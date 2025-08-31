/**/

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
CreateApp: procedure expose global.

    app.Title="IconBar"
    app.Version="$VER: IconBar 1.0 (15.1.2002)"
    app.Copyright="@ 2002 by alfie"
    app.Author="alfie"
    app.Description="IconBar"
    app.Base="ICONBAR"
    app.SubWindow="win"
     win.ID="MAIN"
     win.AppWindow=1
     win.Title="IconBar"
     win.UseRightBorderScroller=1
     win.UseBottomBorderScroller=1
     win.Contents="mgroup"

      mgroup.0="sg"
       sg.class="ScrollGroup"
       sg.Frame="virtual"
       sg.UseWinBorder=1
       sg.VirtGroupContents="vg"
        vg.class="VirtGroup"
         vg.0="vertg"
          vertg.class="group"
           vertg.0=vspace()
           vertg.1="horizg"
            horizg.class="group"
            horizg.horiz=1
             horizg.0="ig"
              ig.class="group"
              ig.horiz=1
              ig.spacing=1
              ig.0=hspace()
           vertg.2=vspace()

      mgroup.1="bg"
       bg.class="group"
       bg.horiz=1
        bg.0=button("cb","_Clear bar")

    call NewObj("Application","app")

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")
    call Notify("cb","pressed",0,"app","Return","call clearBar")

    call AppMessage("vg")

    global.icons=0
    global.space=ig.0

    call set("win","open",1)

    return
/**************************************************************************/
iconObject: procedure
parse arg n,f
    ic.name=f
    ic.inputmode="relverify"
    ic.frame="imagebutton"
    return XNewObj("Icon",n,"ic")
/**************************************************************************/
HandleApp: procedure expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            when h.event="APPEVENT" then call appFun(h.to,h.name)
            otherwise interpret h.event
        end
    end
    /* never reached */
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
addIcon: procedure expose global.
parse arg f
    id=global.icons
    n="ic" || id
    if right(f,1)=":" then f=addpart(f,"disk")
    else do
        t=word(statef(f),1)
        if t="DIR" then f=pathpart(f)
    end
    call RxMUIOpt("")
    o=iconObject(n,f)
    call RxMUIOpt("debugmode showerr")
    if o~="" then do
        call DoMethod("ig","InitChange")
        call Add("ig",o)
        call Remove(global.space)
        call Add("ig",global.space)
        call DoMethod("ig","ExitChange")
        global.id=o
        global.icons=id+1
    end
    return o
/**************************************************************************/
clearBar: procedure expose global.
    call DoMethod("horizg","InitChange")
    do i=0 to global.icons-1
        call Dispose(global.i)
    end
    call DoMethod("horizg","ExitChange")
    global.icons=0
    return
/**************************************************************************/
AppFun: procedure expose global.
    parse arg to,name
    say "Dropped" name "to" to
    if to="VG" then call addIcon(name)
    return
/**************************************************************************/
