/* Coloradjust example */

signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit

call createApp
call handleApp

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
createApp: procedure
    app.Title="Coloradjust"
    app.Version="$VER: Coloradjust 1.1 (25.1.2002)"
    app.Copyright="©2002, alfie"
    app.Author="alfie"
    app.Description="Coloradjust example"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="WIN"
     win.ID="cadj"
     win.Title="Coloradjust Example"
     win.Contents="MGROUP"
      mgroup.0="ca"
       ca.class="coloradjust"

    if NewObj("APPLICATION","APP")>0 then exit

    call Notify("WIN","CLOSEREQUEST",1,"APP","RETURNID","QUIT")
    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
