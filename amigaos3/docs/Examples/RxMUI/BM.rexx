/* Bitmap example */

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
    call RxMUIOpt("debugmode showerr")
    call ProgDir()
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

    app.Title="BitmapExample"
    app.Version="$VER: BitmapExample 1.1 (25.1.2002)"
    app.Copyright="©2002, alfie"
    app.Author="alfie"
    app.Description="BitmapExample"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"
     win.ID="bitm"
     win.Title="BitmapExample"
     win.Contents="MGROUP"

      mgroup.0=vspace()
      mgroup.1="gg"
       gg.class="group"
       gg.horiz=1
        gg.0=hspace()
        gg.1="bm"
         bm.class="bitmap"
         bm.file="PROGDIR:pics/Trek"
         bm.file="service:rxmui/Arc/rxmui/examples/pics/Trek"
         bm.inputmode="relverify"
         bm.frame="button"
        gg.2=hspace()
      mgroup.2=vspace()

    if NewObj("APPLICATION","APP")>0 then exit

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")
    call Notify("bm","pressed",0,"app","return","say 'bm pressed'")

    call set("win","Open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
