/* Dirlist example */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~AddLib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call Pragma("W","N")
    call RxMUIOpt("DebugMode ShowErr")
    return
/***********************************************************************/
CreateApp: procedure expose global.

    app.Title="DirlistExample"
    app.Version="$VER: DirlistExample 2.0 (10.12.2001)"
    app.Copyright="Copyright © 2001 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="Dirlist"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"
     win.ID="MWIN"
     win.Title="DirlistExample"
     win.Contents="mgroup"

      mgroup.0="lv"
       lv.Class="Listview"
       lv.List="dirl"
        dirl.Class="Dirlist"
        dirl.Directory=pragma("D")
        dirl.Frame="ReadList"
        dirl.ShowTitle=1

      mgroup.1="ig"
       ig.class="group"
       ig.horiz=1
       ig.frame="text"
       ig.background="textback"
        ig.0=Text("info",,"none","none")
        ig.1="lamp"
         lamp.class="Lamp"

      mgroup.2=Text("ainfo")

      mgroup.3="g"
       g.class="group"
       g.frame="group"
       g.background="groupback"
        g.0="cg"
         cg.class="group"
         cg.columns=2
          cg.0=Label("_Drawer")
          cg.1=String("dir","d",dirl.Directory)
          cg.2=Label("_Accept")
          cg.3=String("ap","a")
          cg.4=Label("R_eject")
          cg.5=String("rp","e")
          cg.6=Label("Sort order")
          cg.7=MakeObj("stype","Cycle","Name|Date|Size")
          cg.8=Label("Sort dirs")
          cg.9=MakeObj("sdirs","Cycle","First|Last|Mix")
        g.1=hbar()
         fg.class="group"
         fg.Columns=4
          fg.0=Label("Au_to")
          fg.1=Checkmark("ar",1,"t")
          fg.2=Label("Dirs _only")
          fg.3=Checkmark("do",,"o")
          fg.4=Label("_Files only")
          fg.5=Checkmark("fo",,"f")
          fg.6=Label("No _icons")
          fg.7=Checkmark("ri",,"i")
        g.2=MakeObj(,"HCenter","fg")

      mgroup.4="bg"
       bg.class="group"
       bg.horiz=1
        bg.0=Button("parent","_Parent")
        bg.1=Button("reload","_Reload")

    if NewObj("Application","app")>0 then exit

    call Notify("WIN","CLOSEREQUEST",1,"APP","RETURNID","QUIT")

    call Notify("dirl","status",0,"lamp","set","color","Error")
    call Notify("dirl","status",1,"lamp","set","color","LoadingData")
    call Notify("dirl","status",2,"lamp","set","color","OK")
    call Notify("dirl","DoubleClick","EveryTime","app","Return","call ChangeDir('D')")
    call Notify("dirl","Active","EveryTime","app","Return","call ChangeActive(h.path)","Path")

    call Notify("dir","NewContents","EveryTime","app","Return","call ChangeDir('S')")
    call Notify("ap","NewContents","EveryTime","dirl","set","AcceptPattern","TriggerValue")
    call Notify("rp","NewContents","EveryTime","dirl","set","RejectPattern","TriggerValue")
    call Notify("stype","Active","EveryTime","dirl","set","SortType","TriggerValue")
    call Notify("sdirs","Active","EveryTime","dirl","set","SortDirs","TriggerValue")
    call Notify("ar","Selected","EveryTime","dirl","set","AutoReRead","TriggerValue")
    call Notify("fo","Selected","EveryTime","dirl","set","FilesOnly","TriggerValue")
    call Notify("do","Selected","EveryTime","dirl","set","DrawersOnly","TriggerValue")
    call Notify("ri","Selected","EveryTime","dirl","set","RejectIcons","TriggerValue")

    call Notify("parent","Pressed",1,"app","Return","call ChangeDir('P')")
    call Notify("reload","pressed",0,"dirl","ReRead")

    call Notify("Dirl","Status","EveryTime","App","Return","call MakeTitle(h.status)","TriggerAttr")

    call set("win","open",1)

    return
/***********************************************************************/
HandleApp: procedure expose global.

    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise interpret h.event
        end
    end
    /* never reached */
/***********************************************************************/
ChangeDir: procedure
parse arg where
    select
        when where="D" then do
            call DoMethod("dirl","GetEntry","Active","a")
            if a.entrytype>0 then do
                call pragma("D",a.name)
                call set("dirl","Directory",pragma("D"))
                call set("dir","Contents",pragma("D"))
            end
        end
        when where="S" then do
            d=xget("dir","Contents")
            parse value(Statef(d)) with t .
            if t=="DIR" then do
                call pragma("D",d)
                call set("dirl","Directory",pragma("D"))
            end
            else call set("dirl","Directory","")
        end
        when where="P" then do
            d=pragma("D")
            d=PathPart(d)
            call pragma("D",d)
            call set("dirl","Directory",pragma("D"))
            call set("dir","Contents",pragma("D"))
        end
    end
    return
/***********************************************************************/
MakeTitle: procedure
parse arg status
    select
        when status=0 then t="Invalid dir"
        when status=1 then t="Reading..."
        when status=2 then do
            nb=xget("Dirl","NumBytes")
            nd=xget("Dirl","NumDrawers")
            nf=xget("Dirl","NumFiles")
            t="[Bytes:" nb"] [Drawers:" nd"] [Files:" nf"]"
        end
    end
    call set("info","contents",t)
    return
/**************************************************************************/
ChangeActive: procedure
parse arg p
    call set("ainfo","Contents",p)
    return
/**************************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
