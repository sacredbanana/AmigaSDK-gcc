/* AttachedList example */

call Init
call createApp
call handleApp()
/* never reached */
/***********************************************************************/
init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    return
/***********************************************************************/
createApp: procedure
    app.Title="AttachedListExample"
    app.Version="$VER: AttachedListExample 1.0 (8.7.2001)"
    app.Copyright="©2001 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="AttachedList Example"
    app.Base="ALIST"
    app.SubWindow="mwin"
     mwin.Title="AttachedList Example"
     mwin.ID="MWIN"
     mwin.Contents="mgroup"
      mgroup.0="lv"
       lv.class="Listview"
       l.format="COL=0 BAR,COL=1"
       l.acyclechain=1
       lv.list="l"
        l.0="Alfonso|337665323"
        l.1="Paolo|32898765"
        l.2="Emi|338299222"
      mgroup.1="g"
       g.class="group"
       g.horiz=1
         sort.acyclechain=1
        g.0=Button("sort","_Sort")
         add.acyclechain=1
        g.1=Button("add","_Add")
         remove.acyclechain=1
        g.2=Button("remove","_Remove")
      mgroup.2="sg"
       sg.class="group"
       sg.horiz=1
         sa.acyclechain=1
         sa.reject="|"
        sg.0=String("sa")
         sb.acyclechain=1
         sb.reject="|"
        sg.1=String("sb")

    if NewObj("application","app")~=0 then exit

    call Notify("mwin","closerequest",1,"app","returnid","quit")

    call Notify("sort","pressed",0,"lv","sort")

    call Notify("add","pressed",0,"lv","insert","","bottom")
    call Notify("add","pressed",0,"lv","set","active","bottom")

    call Notify("remove","pressed",0,"lv","remove","active")

    call Notify("lv","active",-1,"sa","set","contents","")
    call Notify("lv","active",-1,"sb","set","contents","")
    call Notify("lv","activeentry0","everytime","sa","set","contents","triggervalue")
    call Notify("lv","activeentry1","everytime","sb","set","contents","triggervalue")
    call Notify("lv","doubleclick","everytime","app","return","say double")

    call Notify("sa","newcontents","everytime","lv","replacecol","active",0,"triggervalue")
    call Notify("sb","newcontents","everytime","lv","replacecol","active",1,"triggervalue")

    call set("sa","AttachedList","lv")
    call set("sb","AttachedList","lv")

    call set("mwin","defaultobject","lv")
    call set("mwin","open",1)

    return
/***********************************************************************/
handleApp: procedure
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if h.event="QUIT" then exit
        else interpret h.event
    end
/* never reached */
/***********************************************************************/

