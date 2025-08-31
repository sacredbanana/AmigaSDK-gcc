/* Shows BAD BAD BAD notify */

signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit

call createApp
call handleApp

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
err: procedure expose sigl rxmuierror
parse arg res
say sigl "["res"]"
    say getrxmuistring(res) "in line" sigl-1 rxmuierror
    exit
/***********************************************************************/
createApp: procedure
    app.Title="Cycle"
    app.Version="$VER: Cycle 1.0 (10.12.99)"
    app.Copyright="©1999, alfie"
    app.Author="alfie"
    app.Description="Cycle example"
    app.Base="EXAMPLE"
    app.SubWindow="WIN"
     win.ID="MAIN"
     win.Title="Cycle Example"
     win.Contents="MGROUP"

      mgroup.0=text(,ParseText("
This is an example of %bBAD%n\n
Dead End Notifies"))

      mgroup.1=vspace()

      mgroup.2="vg"
       vg.class="group"
       vg.horiz=1
       vg.Frame="group"
       vg.Background="groupback"
        vg.0=hspace()
        vg.1="hg"
         hg.class="group"
          hg.0="radio"
           radio.class="radio"
           radio.horiz=1
           radio.entries="1|2|3"
          hg.1=MakeObj("cycle","cycle","uno|due|tre")
         vg.2=hspace()

       mgroup.3=hspace()

    if NewObj("APPLICATION","APP")>0 then exit

    call Notify("WIN","CLOSEREQUEST",1,"APP","RETURNID","QUIT")
    call Notify("cycle","active","everytime","radio","set","active",triggervalue)
    call Notify("radio","active","everytime","cycle","set","active",nottriggervalue)

    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

