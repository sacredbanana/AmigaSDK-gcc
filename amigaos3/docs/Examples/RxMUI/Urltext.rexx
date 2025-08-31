/* Urltext is magic! */

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

    app.Title="UrltextExample"
    app.Version="$VER: UrltextExample 1.1 (25.1.2002)"
    app.Copyright="©2002, alfie"
    app.Author="alfie"
    app.Description="Urltext example"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="Urltext"
     win.Contents="mgroup"

      fg.frame="group"
      fg.background="groupback"
      fg.frametitle="Urltext examples"
       g.class="group"
       g.columns=5
        g.0=hspace()
        g.1="u0"
         u0.class="urltext"
         u0.Font="big"
         u0.url="alfie.monrif.net"
         u0.text="Alfie's home page"
        g.2=hspace()
        g.3="u1"
         u1.class="urltext"
         u1.url="alfie.monrif.net/rxmui/"
         u1.text="RxMUI home page"
        g.4=hspace()
        g.5=hspace()
        g.6="u2"
         u2.class="urltext"
         u2.url="http://www.egroups.com/group/rxmui"
         u2.text="RxMUI mail list"
        g.7=hspace()
        g.8="u3"
         u3.class="urltext"
         u3.url="mailto:alforan@tin.it"
         u3.text="Alfonso Ranieri"
        g.9=hspace()
      mgroup.0=MakeObj("fg","VCenter","g")

      mgroup.1=Text("info")

    if NewObj("application","app")>0 then exit

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")
    if xget("u0","active") then do
        call Notify("u0","url","everytime","info","set","contents","triggervalue")
        call Notify("u1","url","everytime","info","set","contents","triggervalue")
        call Notify("u2","url","everytime","info","set","contents","triggervalue")
        call Notify("u3","url","everytime","info","set","contents","triggervalue")
    end
    else call set("info","contents","OpenURL is not installed!")

    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
