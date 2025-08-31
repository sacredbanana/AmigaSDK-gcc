/* Browse ENV */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp

/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    return
/***********************************************************************/
handleApp: procedure  expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select

            when h.event="QUIT" then exit

            when h.event="PARENT" then do
                call getattr("dlist","directory","P")
                call set("dlist","directory",pathpart(p))
            end

            when h.event="DOUBLE" then do
                call getattr("dlist","Path","P")
                if word(statef(p),1)="DIR" then call set("dlist","directory",p)
            end

            when h.event="DISPLAY" then do
                call getattr("dlist","Path","P")
                if word(statef(p),1)~="DIR" then cont=ReadFile(p)
                else cont=""
                call set("elcont","contents",cont)
            end

            otherwise nop
        end
    end

/***********************************************************************/
createApp: procedure expose global.

    app.title="EnvBrowser"
    app.version="$Ver: EnvBrowser 19.5 (20.7.2000)"
    app.copyright="Copyright 2000 by Alfie"
    app.author="alfie"
    app.description="View environment variables."
    app.base="ENVBROWSER"
    app.SubWindow="mwin"

     mwin.ID="MAIN"
     mwin.title="Environment Browser"
     mwin.contents="mgroup"

      call child("mgroup","elview","listview")
       elview.list="dlist"
        dlist.class="dirlist"
        dlist.frame="inputlist"
        dlist.directory="env:"

      call child("mgroup","elcont","textinputscroll")
       elcont.FIXHEIGHTTXT="0a0a0a0a"x
       elcont.frame="text"
       elcont.multiline=1
       elcont.noinput=1

      call child("mgroup",button("parent","_Parent"))

    if NewObj("application","app")>0 then exit

    call notify("mwin","CLOSEREQUEST",1,"APP","RETURNID","QUIT")

    call notify("elview","active","everytime","app","return","DISPLAY")
    call notify("elview","doubleclick","everytime","app","return","DOUBLE")

    call notify("parent","pressed",0,"app","returnid")

    call set("mwin","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

