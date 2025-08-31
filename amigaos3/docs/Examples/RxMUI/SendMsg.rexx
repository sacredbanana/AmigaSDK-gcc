/*
** Name: SendMsg.rexx
** Version: 2.5
** Date: 12.2.2004
** Author: Alfonso Ranier
** Description: Sends email/new messages
*/

signal on halt
signal on break_c

call Init()
call CreateApp()
call HandleApp()
/* never reached */
/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addLib(l,-5,-30) then exit
    if addLibrary("rxmui.library","rexxsupport.library","rxsocket.library")~=0 then exit

    call SetRxMUIStack(64000) /* CManager uses NList ! */

    call MacroEnv("global","ProgDir CD")
    global.ver=2.5
    global.date="(12.4.2004)"
    global.descr="Sends emails/news messages"
    global.Author="Alfonso Ranieri"

    call RxMUIOpt("DebugMode ShowErr")

    global.MacroNotify=global.NoExtName"_"time(s)
    global.mns=MacroNotifyCreate(global.MacroNotify)
    if global.mns=0 then exit

    parm.0.flag=0
    parm.1.value=""
    parm.2.value=""
    parm.3.value=""

    if ~global.WB? then
        if ~RMHReadArgs("NEW/S,TO/K,SUBJECT/K,MSG/K/F") then do
            call PrintFault()
            exit
        end

    global.MsgType=parm.0.flag
    global.to=parm.1.value
    global.esubject=parm.2.value
    global.nsubject=parm.2.value
    global.msg=parm.3.value

    global.CM?=exists("Libs:CManager.library")
    global.App?=0

    return
/***********************************************************************/
CreateApp: procedure expose global.

    strip.0="MProject"
     MProject.Class="menu"
     MProject.Title="Project"
      MProject.0=MenuItem("MAbout","?\About...","?")
      MProject.1=MenuItem("MAboutRxMUI","X\About RxMUI...")
      MProject.2=MenuItem("MAboutMUI","!\About MUI...")
      MProject.3=MenuItem("","BAR")
      MProject.4=MenuItem("MHide","H\Hide")
      MProject.5=MenuItem("","BAR")
      MProject.6=MenuItem("MQuit","Q\Quit")
    strip.1="MEditor"
     MEditor.Title="Editor"
      MEditor.Class="menu"
      MEditor.0=MenuItem("MMUI","M\MUI Settings...")
    if NewObj("Menustrip","strip")>0 then call ShowErr(0)

    to.CycleChain=1
    if string("to","t")="" then call ShowErr(0)

    if global.CM? then do
        ToObj.Window="tow"
          tow.Class="Window"
          tow.Title="Contact Manager"
          tow.ID="CMAN"
           tow.Contents="cm"
            cm.Class="cm"
            cm.HideUsers=0
            cm.HideWWW=1
            cm.HideFtp=1
            cm.HideChat=1
            cm.HideTelnet=1
            cm.NoBar=1
            cm.NoMenu=1
            cm.NoGroups=1
            cm.AutoLoad=1
            cm.DoubleClick="GLOBAL.CMENTRY"
        ToObj.String="to"
         tpb.CycleChain=1;
        ToObj.Button=MakeObj("tpb","ImageButton","Popup")
        ToObj.CloseFun="call set('to','contents',RxMUIGetVar('global.cmentry.email'))"

        if NewObj("PopString","ToObj")>0 then call ShowErr(0)
    end
    else ToObj="to"

    app.Title=global.NoExtName
    app.Version="$VER:" global.NoExtName global.ver global.date
    app.Copyright="Copyright 2001-2003 by" global.author
    app.Author=global.author
    app.Description=global.descr
    app.Base=upper(global.NoExtName)
    app.MenuStrip="strip"
    app.DiskObject=global.NoExtName
    app.SubWindow="mwin"

     mwin.ID="MAIN"
     mwin.Title=global.NoExtName
     mwin.Contents="mgroup"

      call child("mgroup","mg","group")

       call child("mg","swg","group")
        swg.Horiz=1
        swg.0=label("Send _what")
         MsgType.CycleChain=1
        swg.1=MakeObj("MsgType","Cycle","EMail|New","w",global.MsgType)
        swg.2=hspace(8)
        swg.3=label("Show setti_ngs")
         se.ObjectID="SHOW"
         se.CycleChain=1
        swg.4=checkmark("se",1,"n")

       call child("mg","eg","group")
        eg.Frame="group"
        eg.FrameTitle="Message"
        eg.Background="groupback"
         call child("eg","sg","group")
          sg.PageMode=1
          sg.ActivePage=global.MsgType
           call child("sg","sge","group")
            sge.Columns=2
             call child("sge",label("_To"))
             call child("sge",ToObj)
             call child("sge",label("S_ubject"))
             esubject.CycleChain=1; call child("sge",string("ESUBJECT","u",global.esubject))
           call child("sg","sgn","group")
            sgn.Columns=2
             call child("sgn",label("_Group"))
             group.CycleChain=1; call child("sgn",string("group","g"))
             call child("sgn",label("S_ubject"))
             nsubject.CycleChain=1; call child("sgn",string("NSUBJECT","u",global.nsubject))
          textg.Spacing=0
         call child("eg","textg","HGroup")
          call child("textg","text","TextEditor")
          text.Slider="scroller"
          text.Export="EMAIL"
          text.Contents=global.msg
          call child("textg","scroller","Scrollbar")

      call child("mg","g0","group")
       g0.Weight=0
       g0.Frame="group"
       g0.FrameTitle="Settings"
       g0.BAckground="groupback"
       g0.Columns=2
        call child("g0",label("Re_al name"))
        name.CycleChain=1; name.ObjectID="NAME"; call child("g0",string("NAME","a"))
        call child("g0",label("_EMail"))
        email.CycleChain=1; email.ObjectID="EMAL"; call child("g0",string("EMAIL","e"))
        call child("g0",label("_Host"))
        call child("g0","hg","group")
         hg.PageMode=1
         hg.ActivePage=global.MsgType
          ehost.CycleChain=1; ehost.ObjectID="MHOS"; call child("hg",string("EHOST","h"))
          nhost.CycleChain=1; nhost.ObjectID="NHOS"; call child("hg",string("NHOST","h"))

       info.Weight=20;
      call child("mgroup",text("info","Welcome to SendMsg!"))

      call child("mgroup","abg","group")
       abg.Weight=20
       abg.Horiz=1
       abg.PageMode=1
        call child("abg","abg0","group")
        abg0.Horiz=1
           send.CycleChain=1;
          call child("abg0",button("SEND","_Send"))
          call child("abg0",hspace())
           quit.CycleChain=1;
          call child("abg0",button("QUIT","_Quit"))
           stop.CycleChain=1;
        call child("abg",button("STOP","_Stop"))

    if NewObj("application","app")>0 then call ShowErr(0)
    call add("app","tow")

    call notify("mwin","CloseRequest",1,"app","return","call SafeQuit(1)")

    call notify("MAbout","MenuTrigger","everytime","app","about","mwin")
    call notify("MAboutRxMUI","MenuTrigger","everytime","app","aboutrxmui","mwin")
    call notify("MAboutMUI","MenuTrigger","everytime","app","aboutmui","mwin")
    call notify("MHide","MenuTrigger","everytime","app","Set","iconified",1)
    call notify("MQuit","MenuTrigger","everytime","app","return","call SafeQuit(1)")
    call notify("mmui","MenuTrigger","everytime","app","openconfigwindow")

    call notify("MsgType","active","everytime","hg","Set","ActivePage","triggervalue")
    call notify("MsgType","active","everytime","sg","Set","ActivePage","triggervalue")
    call notify("se","Selected","everytime","g0","Set","ShowMe","triggervalue")

    call notify("send","pressed",0,"app","return","call SafeStart()")
    call notify("stop","pressed",0,"app","return","call SafeQuit(0)")
    call notify("quit","pressed",0,"app","return","call SafeQuit(1)")

    call notify("abg","ActivePage","everytime","mg","Set","disabled","triggervalue")

    if global.CM? then do
        call Notify("tow","CloseRequest",1,"toObj","Close",0)
        call Notify("cm","DoubleClick","EveryTime","toObj","Close",1)
    end

    call set("g0","showme",xget("se","selected"))
    call set("mwin","defaultobject","send")

    if global.MsgType then call set("group","contents",global.to)
    else call set("to","contents",global.to)

    call DoMethod("app","load","env")

    call set("mwin","open",1)

    global.App?=1
    return
/**************************************************************************/
HandleApp: procedure expose global.

    ctrl_c=2**12
    mask=or(global.mns,ctrl_c)

    do forever
        if NewHandle("app","h",mask)>0 then call ShowErr(2)

        if and(h.signals,ctrl_c)>0 then call SafeQuit(1)
        if and(h.signals,global.mns)>0 then call HandleMacroEvent()

        if h.EventFlag then
            select
                when h.event="QUIT" then call SafeQuit(1)
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
                call set("abg","ActivePage",1)
                call set("app","sleep",0)
            end

            when ev="ENDED" then do
                call set("abg","ActivePage",0)
            end

            when ev="INFO" then do
                call info(d)
            end

            otherwise nop
        end
    end
    /* never reached */
/***********************************************************************/
SafeStart: procedure expose global.

    call set("app","sleep",1)

    if ~IsLibOn("SOCKET") then do
        call info("No TCP/IP stack running!")
        call set("app","sleep",0)
        return
    end

    if ~exists("sendmsgfun.rexx") then do
        call info "Macro 'sendmsgfun.rexx' not found!!!"
        call set("app","sleep",0)
        return
    end

    var.News=xget("MsgType","active")
    if var.News then do
        var.News=1
        var.Host=xget("nhost","contents")
        var.Name=xget("name","contents")
        var.Email=xget("email","contents")
        var.To=xget("group","contents")
        var.Subject=xget("nsubject","contents")
        var.Text=xget("text","contents")
    end
    else do
        var.Host=xget("ehost","contents")
        var.Name=xget("name","contents")
        var.Email=xget("email","contents")
        var.To=xget("to","contents")
        var.Subject=xget("esubject","contents")
        var.Text=xget("text","contents")
    end

    if var.Host="" then do
        call info("No host supplied.")
        call set("app","sleep",0)
        return
    end

    if pos(":",var.Host)>0 then do
        parse var var.Host var.Host ":" var.HostPort
        if var.HostPort<0 | var.HostPort>65535 then do
            call info("Invalid port" var.HostPort".")
            call set("app","sleep",0)
            return
        end
    end
    else
        if var.News then var.HostPort=119
        else var.HostPort=25

    if var.Name="" then do
        call info("No Real name supplied.")
        call set("app","sleep",0)
        return
    end

    if var.Email="" then do
        call info("No EMail address supplied.")
        call set("app","sleep",0)
        return
    end

    if var.To="" then do
        if var.News then call info("No newsgroup supplied.")
        else call info("No destination supplied.")
        call set("app","sleep",0)
        return
    end

    if var.Subject="" then do
        call info("No subject supplied.")
        call set("app","sleep",0)
        return
    end

    if var.Text="" then do
        call info("No message text supplied.")
        call set("app","sleep",0)
        return
    end

    call info("Launching child...")

    var.MacroNotify=global.MacroNotify
    call StemToVar("var")
    call RxsCall("SendMsgFun.rexx")

    return
/**************************************************************************/
SafeQuit: procedure expose global.
parse arg e
    if e then do
        if global.App? then do
            call set("mwin","open",0)
            call DoMethod("app","save","env")
            call DoMethod("app","save","envarc")
        end
        exit
    end
    call MacroNotifySync()
    return
/***************************************************************************/
info: procedure expose global.
parse arg txt
    call set("info","contents",txt)
    return
/**************************************************************************/
halt:
break_c:
    call SafeQuit(1)
/**************************************************************************/
ShowErr: procedure expose global.
parse arg err
    select
        when err=0 then msg="Can't create Application"
        when err=1 then msg="Can't open Window"
        otherwise msg="Too few memory"
    end
    call EasyRequest(msg,global.NoExtName)
    call SafeQuit(1)
/**************************************************************************/

