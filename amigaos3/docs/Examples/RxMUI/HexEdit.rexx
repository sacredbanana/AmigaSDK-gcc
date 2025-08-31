/* HexEdit example */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call RxMUIOpt("debugmode showerr")
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
CreateApp: procedure expose global.

    mem=GetSpace(1024)
    if mem=Null() then exit
    call Export(mem,Copies("RxMUI rulezzzz!!!",50))

    app.Title="HexEditExample"
    app.Version="$VER: HexEditExample 2.0 (10.9.2001)"
    app.Copyright="©2000, alfie"
    app.Author="alfie"
    app.Description="HexEditExample"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="HexEditExample"
     win.Contents="MGROUP"
     win.ID="MAIN"
     win.Title="HexEdit Example"
     win.UseRightBorderScroller=1
     win.Contents="mgroup"

      mgroup.0="reg"
       reg.Class="Register"
       reg.Titles="No scroll|Scroll|Win scroll"

        reg.0="he0"
         he0.Class="HexEdit"
         he0.Frame="Virtual"
         he0.EditMode=1
         he0.LowBound=mem
         he0.HighBound=d2c(c2d(mem)+1023)

        reg.1="sg1"
         sg1.class="group"
         sg1.horiz=1
         sg1.spacing=0
          sg1.0="he1"
           he1.class="hexedit"
           he1.Frame="Virtual"
           he1.EditMode=1
           he1.LowBound=mem
           he1.HighBound=d2c(c2d(mem)+1023)
           he1.PropObject="Scroll1"
          sg1.1=XNewObj("Scrollbar","Scroll1")

        reg.2="sg2"
         sg2.class="group"
         sg2.horiz=1
         sg2.spacing=0
          sg2.0="he2"
           he2.class="hexedit"
           he2.Frame="Virtual"
           he2.EditMode=1
           he2.LowBound=mem
           he2.HighBound=d2c(c2d(mem)+1023)
           he2.PropObject="Scroll2"
            Scroll2.UseWinBorder="right"
          sg2.1=XNewObj("scrollbar","Scroll2")

    if NewObj("Application","app")>0 then exit

    call set("win","Open",1)

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

