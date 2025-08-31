/* CompactWindow example */

signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
call RxMUIOpt("DebugMode ShowErr")

call createApp
call handleApp

/* never reached */
/***********************************************************************/
handleApp: procedure
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        if h.event="QUIT" then exit
        else interpret h.event
    end
    /* never reached */
/***********************************************************************/
createApp: procedure

    app.Title="CompactWindow"
    app.Version="$VER: CompactWindow 2.1 (25.1.2002)"
    app.Copyright="Copyright © 2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="CompactWindow example"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="WIN"
     win.Class="CompactWindow"
     win.ID="MAIN"
     win.Title="CompactWindow Example"
     win.noGadgets=1
     win.SizeGadget=0
     win.Contents="mgroup"
      mgroup.0="cy"
       cy.class="Cycle"
       cy.entries="One|Two|Three"
    if NewObj("Application","app")>0 then exit

    call Notify("win","CloseRequest",1,"app","ReturnID","QUIT")

    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
