/* Busy bar example */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp

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
            otherwise interpret h.event
        end
    end
    /* never reached */
/***********************************************************************/
CreateApp: procedure
    app.Title="Busybar"
    app.Version="$VER: Busybar 1.2 (25.1.2002)"
    app.Copyright="Copyright © 2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="Busybar example"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="WIN"
     win.ID="busy"
     win.Title="Busybar Example"
     win.Contents="MGROUP"
      mgroup.0=MakeObj(,"Busy")

    if NewObj("APPLICATION","APP")>0 then exit

    call set("win","open",1)

    call Notify("WIN","CLOSEREQUEST",1,"APP","RETURNID","QUIT")
    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
