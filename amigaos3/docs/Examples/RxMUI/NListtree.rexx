/* NListtree example */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/* never reached */

/***********************************************************************/
Init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call RxMUIOpt("DebugMode ShowErr")
    return
/***********************************************************************/
HandleApp: procedure

    ctrl_c=2**12
    do forever

        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            when h.event="DROPEVENT" then call dropFun(h.from,h.to)
            otherwise interpret h.event
        end
    end
    /* never reached */
/***********************************************************************/
CreateApp: procedure
    app.Title="NListtree example"
    app.Version="$VER: NListtree example 2.1 (4.3.2003)"
    app.Copyright="©2000-2003, alfie"
    app.Author="alfie"
    app.Description="NListtree example"
    app.Base="NLISTTREE"
    app.SubWindow="win"
     win.ID="MWIN"
     win.Title="NListtree example"
     win.Contents="mgroup"

      mgroup.0="bg"
       bg.Class="group"
       bg.Columns=2
       bg.SameSize=1
        bg.0=Button("openall","Open _all")
        bg.1=Button("closeall","Close a_ll")
        bg.2=Button("openactive","Open a_ctive")
        bg.3=Button("closeactive","Close ac_tive")

      mgroup.1="lv"
       lv.Class="NListview"
       lv.List="list"
        list.Class="NListtree"
        list.Frame="InputList"
        list.Format="BAR,"
        list.Title="Name|Phone"
        list.NLTAutoVisible="expand"
        list.DragDropSort=1

         list.0="Friends"; list.0.Flags="Close"; list.0.List="fr"
          fr.0="Jhon|555876"; fr.0.name="Jhon"
          fr.1.type="Tree"; fr.1.Flags="Close"; fr.1="Uni|555643"; fr.1.list="uni"
           uni.0="Mary|555987"
           uni.1="Carol|555432"
           uni.2.Flags="list"; uni.2="Frank|555432"
          fr.2="Angel|5554231"
         list.1="St. Clara Comp shop|555543241"

      mgroup.2="acg"
       acg.class="group"
       acg.horiz=1
        aname.format="right"
        acg.0=Label(ParseText("%bActiveName:"))
        acg.1=string("aname")
        acg.2=Label(ParseText("%bActiveID:"))
        acg.3="aid"
         aid.class="slider"
         aid.min=0
         aid.max=16

      mgroup.3="ddg"
       ddg.class="group"
       ddg.horiz=1
        ddg.0=Label(ParseText("%b D&D here!"))
        ddg.1=text("text")

    res = NewObj("APPLICATION","APP")
    if res>0 then exit

    call dandd(list,"text")

    call Notify("win","closerequest",1,"app","returnid","quit")

    call Notify("list","activename","everytime","aname","set","contents","triggervalue")
    call Notify("list","activeid","everytime","aid","set","value","triggervalue")
    call Notify("list","activeid","everytime","app","return","say h.activeid","triggerattr")

    call Notify("openall","pressed",0,"list","open","root","all")
    call Notify("openactive","pressed",0,"list","open","active","active")

    call Notify("closeall","pressed",0,"list","close","root","all")
    call Notify("closeactive","pressed",0,"list","close","active","active")

    call Notify("aname","newcontents","everytime","list","set","activename","triggervalue")
    call Notify("aid","value","everytime","list","set","activeid","triggervalue")

    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
DropFun: procedure
parse arg from,to
    call DoMethod("list","getentry","a","active")
    parse var a name "|" phone
    if phone="" then do
        call DoMethod("win","DisplayBeep")
        return
    end
    c=ParseText("%bName:%n" "%i"name"%n" "%bPhone:%n" "%i"phone"%n")
    call set("text","contents",c)
    return
/**************************************************************************/

