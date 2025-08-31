/* The ARexx port is mine! */

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
    return
/***********************************************************************/
HandleApp: procedure expose global.
    call getattr("app","base","PORTNAME")
    ps=PortSignal(portname)
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",or(ctrl_c,ps))
        if and(h.signals,ctrl_c)~=0 then exit
        if and(h.signals,ps)>0 then call HandlePort(portname)
        select
            when h.event="QUIT" then exit
            when h.event="DROPEVENT" then call DropFun(h.from,h.to)
            when left(h.event,1)="B" then do
                parse var h.event "B" b
                say global.url.b.url global.url.b.name
            end
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
CreateApp: procedure expose global.
    app.Title="OwnARexxExample"
    app.Version="$VER: OwnARexxExample 2.0 (12.10.2000)"
    app.Copyright="©2000, alfie"
    app.Author="alfie"
    app.Description="OwnARexxExample"
    app.Base="RXMUIEXAMPLE"
    app.OwnARexx=1
    app.SubWindow="win"
     win.Title="OwnARexxExample"
     win.Contents="mgroup"
      mgroup.frametitle="Messages received"
      mgroup.0="msglist"
       msglist.class="listview"
       msglist.input=1
       msglist.list="list"
      mgroup.1=text("info")

    res=NewObj("APPLICATION","APP")
    if res~=0 then call err(res)

    call Notify("win","closerequest",1,"app","returnid","quit")
    call Notify("msglist","entries","everytime","msglist","jump","triggervalue")

    call set("info","Contents","Send msgs to:" xget("app","base"))
    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
HandlePort: procedure
parse arg portname
    pkt=Getpkt(portname)
    do while pkt~=null()
        msg=getarg(pkt)
        call DoMethod(msglist,"insert",msg,"bottom")
        call DoMethod("app","inputbuffered")
        call Reply(pkt)
        if upper(msg)="QUIT" then exit
        pkt=Getpkt(portname)
    end
    return
/**************************************************************************/
