/* Icon example */

signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
call RxMUIOpt("DebugMode ShowErr")

call CreateApp
call HandleApp
/* never reached */
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

    app.Title="IconExample"
    app.Version="$VER: IconExample 1.0 (12.10.2000)"
    app.Copyright="©2000, alfie"
    app.Author="alfie"
    app.Description="IconExample"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="IconExample"
     win.Contents="MGROUP"

      mgroup.0=vspace()
      mgroup.1="gg"
       gg.class="group"
       gg.horiz=1
        gg.0=hspace()
        gg.1="ic"
         ic.class="icon"
         ic.name="sys:disk"
         ic.inputmode="relverify"
         ic.frame="button"
        gg.2=hspace()
      mgroup.2=vspace()

    res=NewObj("APPLICATION","APP")
    if res~=0 then exit

    call set("win","open",1)

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")
    call Notify("ic","pressed",0,"app","return","say 'ic pressed'")

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

