/* Colorfield Drag and Drop */

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
    global.red="red"
    global.green="green"
    global.blue="blue"
    global.violet="violet"
    return
/***********************************************************************/
HandleApp: procedure expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            when h.event="DROPEVENT" then call dropfun(h.from,h.to)
            otherwise interpret h.event
        end
    end
    exit
/***********************************************************************/
CreateApp: procedure expose global.

    app.Title="ColorFieldExample"
    app.Version="$VER: ColorFieldExample 1.1 (25.1.2002)"
    app.Copyright="©2002, alfie"
    app.Author="alfie"
    app.Description="Just a little example"
    app.Base="EXAMPLE"
    app.menustrip="menustrip"
     menustrip.class="menustrip"
      menustrip.0="Project"
       project.class="menu"
       project.title="Project"
        project.0="mabout"
         mabout.class="menuitem"
         mabout.title="About..."
         mabout.ShortCut="?"
        project.1=MenuItem("maboutrxmui","About RxMUI...")
        project.2=MenuItem("maboutmui","About MUI...")
        project.3=MenuItem("","BAR")
        project.4=MenuItem("mhide","Hide","H")
        project.5=MenuItem("","BAR")
        project.6=MenuItem("mquit","Quit","Q")

    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="ColorField Example"
     win.Contents="mgroup"
      mgroup.0="g"
       g.class="GROUP"
       g.columns=2
        g.0="red"
         red.class="colorfield"
         red.Draggable=1
         red.Dropable=1
         red.Frame="button"
         red.red="FF000000"x
         red.green="00000000"x
         red.blue="00000000"x
         red.ContextMenu="stripRed"
          stripRed.class="menustrip"
           stripRed.0="menu0"
            menu0.class="menu"
            menu0.title=""
             menu0.0=menuitem("item0",global.red)
        g.1="green"
         green.class="colorfield"
         green.Draggable=1
         green.Dropable=1
         green.Frame="button"
         green.red="00000000"x
         green.green="FF000000"x
         green.blue="00000000"x
         green.ContextMenu="stripGreen"
          stripGreen.class="menustrip"
           stripGreen.0="menu1"
            menu1.class="menu"
            menu1.title=""
             menu1.0=menuitem("item1",global.green)
        g.2="blue"
         blue.class="colorfield"
         blue.Draggable=1
         blue.Dropable=1
         blue.Frame="button"
         blue.red="00000000"x
         blue.green="00000000"x
         blue.blue="FF000000"x
         blue.ContextMenu="stripBlue"
          stripBlue.class="menustrip"
           stripBlue.0="menu2"
            menu2.class="menu"
            menu2.title=""
             menu2.0=menuitem("item2",global.blue)
        g.3="violet"
         violet.class="colorfield"
         violet.Draggable=1
         violet.Dropable=1
         violet.Frame="button"
         violet.red="FF000000"x
         violet.green="00000000"x
         violet.blue="FF000000"x
         violet.ContextMenu="stripViolet"
          stripViolet.class="menustrip"
           stripViolet.0="menu3"
            menu3.class="menu"
            menu3.title=""
             menu3.0=menuitem("item3",global.violet)

    call NewObj("APPLICATION","APP")

    call Notify("win","closerequest",1,"app","returnid","quit")

    call DandD("red","green","both")
    call DandD("red","blue","both")
    call DandD("red","violet","both")
    call DandD("green","blue","both")
    call DandD("green","violet","both")
    call DandD("violet","blue","both")

    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
dropfun: procedure expose global.
parse arg from,to
    l.0=from;   l.0.attr="Red"
    l.1=from;   l.1.attr="Green"
    l.2=from;   l.2.attr="Blue"
    l.3=to;     l.3.attr="Red"
    l.4=to;     l.4.attr="Green"
    l.5=to;     l.5.attr="Blue"
    call MultiGetAttr("l")

    do i=0 to 2; l.i=to; end
    do i=3 to 5; l.i=from; end
    call MultiSetAttr("l")

    fromStrip=global.from
    toStrip=global.to
    global.from=toStrip
    global.to=fromStrip
    call set(to,"contextmenu","strip"fromStrip)
    call set(from,"contextmenu","strip"toStrip)

    return
/**************************************************************************/

