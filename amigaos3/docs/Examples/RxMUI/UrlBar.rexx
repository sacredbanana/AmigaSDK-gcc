/* URLBar 1.2 (8.2.2000) */

signal on halt
signal on break_c
call init
call CreateApp
call HandleApp
/* never reached */


init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit

    global.url.0.url="http://www.amiga.org";                    global.url.0.name="Amiga org"
    global.url.1.url="http://www.napster.com";                  global.url.1.name="Napster"
    global.url.2.url="http://alfie.monrif.net/rxmui/";          global.url.2.name="RxMUI"
    global.url.3.url="http://ftp.unina.it/~aminet/";            global.url.3.name="Aminet"
    global.url.max=4

    return


HandleApp: procedure expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)~=0 then exit
        select
            when h.event="QUIT" then exit
            when h.event="DROPEVENT" then call DropFun(h.from,h.to)
            when left(h.event,1)="B" then do
                parse var h.event "B" b
                say global.url.b.url global.url.b.name
            end
            otherwise interpret h.event
        end
    end
    /* never reached */


err: procedure expose sigl RxMUIError
parse arg res
    msg = ProgramName()":" GetRxMUIString(res) "in line" sigl-1
    if RxMUIError~="RXMUIERROR" then msg = msg "["RxMUIError"]"
    say msg
    exit


CreateApp: procedure expose global.

    strip.0="mproject"
     mproject.class="menu"
     mproject.Title="Project"
      mproject.0=menuitem("mabout","About...","?")
      mproject.1=menuitem("maboutrxmui","About RxMUI...")
      mproject.2=menuitem("maboutmui","About MUI...")
      mproject.3=menuitem("","BAR")
      mproject.4=menuitem("mhide","Hide","H")
      mproject.5=menuitem("","BAR")
      mproject.6=menuitem("mquit","Quit","Q")
    strip.1="meditor"
     meditor.class="menu"
     meditor.Title="Editor"
      meditor.0=menuitem("msort","Sort")
      meditor.1=menuitem("","BAR")
      meditor.2=menuitem("mmui","MUI...")
    res=NewObj("menustrip","strip")
    if res~=0 then call err(res)

    app.title="URLBar"
    app.version="$VER: URLBar&D 1.0 (12.10.2000)"
    app.copyright="©2000, alfie"
    app.author="alfie"
    app.description="URLBar (RxMUI D&D example)"
    app.base="URLBAR"
    app.MenuStrip="strip"
    app.SubWindow="win"

     win.title="URLBar"
     win.ScreenTitle="URLBar"
     win.ID="MWIN"
     win.contents="mgroup"

      mgroup.0="g"
       g.class="group"
       g.Frame="group"
       g.FrameTitle="Drag & Drop these buttons!"
       g.SameSize=1
       g.columns=4
       do i=0 to global.url.max-1
           interpret "b"i".draggable=1"
           interpret "b"i".dropable=1"
           g.i=button("b"i,global.url.i.name)
       end

    res=NewObj("application","app")
    if res~=0 then call err(res)

    do i=0 to global.url.max-2
        do j=i+1 to global.url.max-1
            call DandD("b"i,"b"j,"both")
        end
        call Notify("b"i,"pressed",0,"app","ReturnID")
    end
    call Notify("b"i,"pressed",0,"app","ReturnID")

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")

    call Notify("mabout","MenuTrigger","EveryTime","app","about","win")
    call Notify("maboutrxmui","MenuTrigger","EveryTime","app","AboutRxMUI","win")
    call Notify("maboutmui","menutrigger","everytime","app","AboutMUI","win")
    call Notify("mhide","menutrigger","everytime","app","set","iconified",1)
    call Notify("mquit","menutrigger","everytime","app","ReturnID","quit")
    call Notify("msort","menutrigger","everytime","app","return","call sort")
    call Notify("mmui","menutrigger","everytime","app","OpenConfigWindow")

    call set("win","open",1)

    return


halt:
break_c:
    exit


/* this is a drag and drop between 2 NList view */
DropFun: procedure expose global.
parse arg from,to
    parse var from "B" f
    parse var to "B" t
    TempURL  = global.url.f.url
    TempName = global.url.f.name
    global.url.f.url  = global.url.t.url
    global.url.f.name = global.url.t.name
    global.url.t.url  = TempURL
    global.url.t.name = TempName
    temp=xget(from,"contents")
    call set(from,"contents",xget(to,"contents"))
    call set(to,"contents",temp)
    return


sort: procedure expose global.

    call set("win","sleep",1)

    do i=0 to global.url.max-2
        do j=i+1 to global.url.max-1
            if global.url.j.name<global.url.i.name then call DropFun("B"j,"B"i)
        end
    end

    call set("win","sleep",0)

    return


