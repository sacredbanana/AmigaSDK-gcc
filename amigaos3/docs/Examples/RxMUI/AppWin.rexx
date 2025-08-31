/* APPEVENT example */

signal on halt
signal on break_c

call init
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    return
/***********************************************************************/
handleApp: procedure
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            when h.event="APPEVENT" then call appFun(h.to,h.name)
            otherwise interpret h.event
        end
    end
    /* never reached */
/***********************************************************************/
CreateApp: procedure

    app.Title="AppWindowExample"
    app.Version="$VER: AppWindowExample 2.2 (25.1.2002)"
    app.Copyright="©2002, alfie"
    app.Author="alfie"
    app.Description="AppWindowExample"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"
     win.Title="AppWindowExample"
     win.AppWindow=1
     win.Contents="mgroup"
      mgroup.frametitle="Drop icons on me!"
      mgroup.0="droplist1"
       droplist1.class="listview"
       droplist1.input=1
       droplist1.list="list"
        list.frame="inputlist"
      mgroup.1="droplist2"
       droplist2.class="listview"
       droplist2.input=1
       droplist2.list="dlist"
        dlist.class="dirlist"
        dlist.frame="inputlist"

    res=NewObj("APPLICATION","APP")
    if res~=0 then exit

    call Notify("win","closerequest",1,"app","returnid","quit")
    call Notify("droplist1","entries","everytime","droplist1","jump","triggervalue")

    call AppMessage("droplist1")
    call AppMessage("droplist2")
    call set("app","DropObject","droplist1")

    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
appFun: procedure
parse arg to,what
say to what
    if to="DROPLIST1" then call DoMethod(to,"insert",what,"bottom")
    else call set("dlist","DIRECTORY",what)

    return
/**************************************************************************/

