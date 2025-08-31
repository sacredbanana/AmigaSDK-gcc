/* EMCheck 1.2 (13.3.2001) - Checks emails */

signal on halt
signal on break_c

call Init()
call CreateApp()
call HandleApp()
/* never reached */
/***************************************************************************/
Init:procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library","rxsocket.library","rxlibnet.library")~=0 then exit
    call RxMUIOpt("DebugMode ShowErr")

    global.MacroNotify="EMCHECK_"time(s)
    global.mns=MacroNotifyCreate(global.MacroNotify)
    if global.mns=0 then exit

    return
/***************************************************************************/
HandleApp: procedure expose global.

    ctrl_c=2**12
    mask=or(global.mns,ctrl_c)

    do forever
        call NewHandle("app","h",mask)

        if and(h.signals,ctrl_c)>0 then exit
        if and(h.signals,global.mns)>0 then call HandleMacroEvent()

        if h.EventFlag then
            select
                when h.event="QUIT" then exit
                otherwise interpret h.event
            end

    end
    /* never reached */
/***********************************************************************/
HandleMacroEvent: procedure expose global.
    do forever
        ev=MacroNotifyGetEvent(global.MacroNotify)
        if ev="" then return

        parse var ev ev child d
        select

            when ev="STARTED" then do
                call set("g1","ActivePage",1)
                call set("app","sleep",0)
            end

            when ev="ENDED" then do
                call set("g1","ActivePage",0)
            end

            when ev="INFO" then do
                call info(d)
            end

            otherwise nop
        end
    end
    /* never reached */
/***********************************************************************/
CreateApp: procedure expose global.

    mstrip.0="MProject"
     MProject.class="menu"
     MProject.title="Project"
      MProject.0=MenuItem("MAbout","About...","?")
      MProject.1=MenuItem("MAboutRxMUI","About RxMUI...")
      MProject.2=MenuItem("MAboutMUI","About MUI...")
      MProject.3=MenuItem("","BAR")
      MProject.4=MenuItem("MHide","Hide","H")
      MProject.5=MenuItem("","BAR")
      MProject.6=MenuItem("MQuit","Quit","Q")
    mstrip.1="MSettings"
     MSettings.class="menu"
     MSettings.title="Preferences"
      MSettings.0=MenuItem("MUse","Use","U")
      MSettings.1=MenuItem("MSave","Save","S")
      MSettings.2=MenuItem("MRestore","Last saved","R")
      MSettings.3=MenuItem("","BAR")
      MSettings.4=MenuItem("MMUI","MUI...")
    res=NewObj("menustrip","mstrip")
    if res>0 then exit

    app.title="EMCheck"
    app.version="$VER: EMCheck 1.1 (11.11.2000)"
    app.copyright="Under GNU public licence"
    app.author="Alfonso [alfie] Ranieri"
    app.description="Checks a pop3 email account."
    app.base="EMCHECK"
    app.DiskObject="emcheck"
    app.MenuStrip="mstrip"
    app.SubWindow="mwin"

     mwin.ID="MAIN"
     mwin.Title="EMCheck 1.1"
     mwin.Contents="mgroup"

      mgroup.0="g0"
       g0.Class="group"
       g0.Frame="group"
       g0.Background="groupback"
       g0.Columns=2
        g0.0=label("_Host")
        g0.1="hg"
         hg.Class="group"
         hg.Horiz=1
         hg.spacing=1
           host.CycleChain=1
           host.ObjectID=1
          hg.0=string("host","h")
           HostPort.Weight=30
           HostPort.CycleChain=1
           HostPort.ObjectID=2
           HostPort.IsNumeric=1
           HostPort.MinVal=1
           HostPort.MaxVal=65535
           HostPort.Format="right"
          hg.1=string("HostPort",,110)
        g0.2=label("_Login")
         login.CycleChain=1
         login.ObjectID=3
        g0.3=string("login","l")
        g0.4=label("_Pass")
         pass.CycleChain=1
         pass.ObjectID=4
         pass.Secret=1
        g0.5=string("pass","p")

      mgroup.1=text("info","Welcome to EMCheck!")

      mgroup.2="g1"
       g1.Class="group"
       g1.PageMode=1
         start.CycleChain=1
        g1.0=button("start","_Start")
         stop.CycleChain=1
        g1.1=button("stop","_Stop")

    res=NewObj("application","app")
    if res>0 then exit

    call notify("mwin","CloseRequest",1,"app","ReturnID","QUIT")

    call notify("MAbout","MenuTrigger","EveryTime","app","About","mwin")
    call notify("MAboutRxMUI","MenuTrigger","EveryTime","app","AboutRxMUI","mwin")
    call notify("MAboutMUI","MenuTrigger","EveryTime","app","AboutMUI","mwin")
    call notify("MHide","MenuTrigger","EveryTime","app","set","iconified",1)
    call notify("MQuit","MenuTrigger","EveryTime","app","returnid","quit")
    call notify("MUse","MenuTrigger","EveryTime","app","save","env")
    call notify("MSave","MenuTrigger","EveryTime","app","save","envarc")
    call notify("MSave","MenuTrigger","EveryTime","app","save","env")
    call notify("MRestore","MenuTrigger","EveryTime","app","load","envarc")
    call notify("MMUI","MenuTrigger","EveryTime","app","OpenConfigWindow")

    call notify("start","pressed",0,"app","return","call SafeStart")
    call notify("stop","pressed",0,"app","return","call SafeQuit(0)")

    call notify("g1","ActivePage","EveryTime","g0","set","disabled","TriggerValue")
    call notify("g1","ActivePage",0,"mwin","set","DefaultObject","start")
    call notify("g1","ActivePage",1,"mwin","set","DefaultObject","stop")
    call notify("g1","ActivePage",0,"mwin","set","ActiveObject","start")
    call notify("g1","ActivePage",1,"mwin","set","ActiveObject","stop")

    call DoMethod("app","load","env")

    call set("mwin","open",1)

    call set("g1","ActivePage",0)

    return
/***************************************************************************/
halt:
break_c:
    call SafeQuit(1)
/***************************************************************************/
SafeStart: procedure expose global.

    if ~IsLibOn("SOCKET") then do
        call info("No TCP/IP stack running !!!")
        return
    end

    if ~exists("EMCheckFun.rexx") then do
        call info("EMCheckFun.rexx not found !!!")
        return
    end

    var.host=xget("host","contents")
    if var.host="" then do
        call info("Host not supplied.")
        return
    end

    var.HostPort=xget("HostPort","contents")
    if var.HostPort="" then do
        call info("Host port not supplied.")
        return
    end

    if var.HostPort=0 | var.HostPort>65535 then do
        call info("Host port not valid '"var.HostPort"'.")
        return
    end

    var.login=xget("login","contents")
    if var.login="" then do
        call info("Login not supplied.")
        return
    end

    var.Pass=xget("pass","contents")
    if var.Pass="" then do
        call info("Password not supplied.")
        return
    end

    call set("app","sleep",1)
    call set("g1","ActivePage",1)
    call info("Launching child macro...")

    var.MacroNotify=global.MacroNotify
    call StemToVar("var")

    call RxsCall("EMCheckFun.rexx")

    return
/***************************************************************************/
SafeQuit: procedure expose global.
parse arg e
    if e then exit
    call MacroNotifySync()
    return
/***************************************************************************/
info: procedure expose global.
parse arg msg
    call set("info","contents",msg)
    return
/***************************************************************************/
