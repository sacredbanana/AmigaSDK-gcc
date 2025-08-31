/* How to show/hide objects */

signal on halt
signal on break_c

call init
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~AddLib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    return
/***********************************************************************/
CreateApp: procedure expose global.

    app.title="ShowHide"
    app.version="$VER: ShowHide 1.0 (20.7.2000)"
    app.copyright="Copyright 2000 by Alfie"
    app.author="alfie"
    app.description="Show object hiding."
    app.base="SHOWHIDE"
    app.SubWindow="mwin"

     mwin.ID="MAIN"
     mwin.title="Show & Hide"
     mwin.contents="mgroup"

      call child("mgroup","g0","group")
       g0.frame="group"

        call child("g0","g00","group")
         g00.horiz=1
         g00.weight=0
          g00.0=hspace(0)
          g00.1=CheckMark("c0",1)
          g00.2=CheckMark("c1",1)
          g00.3=CheckMark("c2",1)
          g00.4=CheckMark("c3",1)
          g00.5=CheckMark("c4",1)
          g00.6=hspace(0)

        call child("g0","g01","group")
          g01.0=button("b0","Button 1")
          g01.1=button("b1","Button 2")
          g01.2=button("b2","Button 3")
          g01.3=button("b3","Button 4")
          g01.4=button("b4","Button 5")
          g01.5=VSpace(0)

    res=NewObj("application","app")
    if res~=0 then call err(res)

    call notify("mwin","CloseRequest",1,"app","ReturnID","quit")
    call notify("c0","selected","EveryTime","b0","set","showme","TriggerValue")
    call notify("c1","selected","EveryTime","b1","set","showme","TriggerValue")
    call notify("c2","selected","EveryTime","b2","set","showme","TriggerValue")
    call notify("c3","selected","EveryTime","b3","set","showme","TriggerValue")
    call notify("c4","selected","EveryTime","b4","set","showme","TriggerValue")

    call set("mwin","open",1)

    return
/***********************************************************************/
HandleApp: procedure  expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise nop
        end
    end
    /* never reached */
/***********************************************************************/
err: procedure expose sigl RxMUIError
parse arg res
    msg = ProgramName()":" GetRxMUIString(res) "in line" sigl-1
    if RxMUIError~="RXMUIERROR" then msg = msg "["RxMUIError"]"
    say msg
    exit

/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

