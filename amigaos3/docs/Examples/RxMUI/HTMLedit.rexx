/**/

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rxmui.library")~=0 then exit
    call rxmuiopt("debugmode showerr")
    call setrxmuistack(16000)
    return
/***********************************************************************/
CreateApp: procedure expose global.

    app.Title="Htmlview editor"
    app.Version="$VER: HtmlviewEditor 1.0 (5.2.2002)"
    app.Copyright="©2002, alfie"
    app.Author="alfie"
    app.Description="Htmlview editor"
    app.Base="HTMLEDIT"
    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="Htmlview editor"
     win.Contents="mgroup"
     win.userightborderscroller=1
     win.sizeright=1

      mgroup.0="bg"
        bg.class="group"
        bg.horiz=1
        bg.0=button("open","_Open")
        bg.2=button("save","_Save")
        bg.1=button("insert","_Insert")

      mgroup.1="rg"
       rg.class="Register"
       rg.Titles="Text|Preview"
       rg.0="tg"
        tg.Horiz=1
        tg.spacing=0
        tg.class="group"
        tg.Horiz=1
        tg.spacing=0
         tg.0="text"
          text.class="texteditor"
          text.frame="string"
          text.FIXEDFONT=1
          text.UseARexx=1
          text.slider=XNewObj("scrollbar","tescr")
         tg.1="tescr"
       rg.1="sg"
        sg.class="scrollgroup"
        sg.aUseWinBorder=1
        sg.virtgroupcontents="html"
         html.class="htmlview"
         html.frame="virtual"
         html.ntautoload=1
         html.nocontextmenu=0

    res=NewObj("APPLICATION","APP")
    if res~=0 then exit
    call Notify("win","closerequest",1,"app","returnid","quit")

    call Notify("open","pressed",0,"app","return","call openfile")
    call Notify("insert","pressed",0,"app","return","call insertfile")
    call Notify("save","pressed",0,"app","return","call savefile")
    call Notify("rg","activepage",1,"app","return","call Preview()")

    call set("win","open",1)
    return
/***********************************************************************/
HandleApp: procedure expose global.
    do forever
        call NewHandle("APP","H",2**12)
        if and(h.signals,2**12)>0 then exit

        select
            when h.event="QUIT" then exit
            otherwise interpret h.event
        end
    end
end
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
Preview: procedure expose global.
    call getattr("text","contents","c")
    call set("html","contents",c)
    return
/***********************************************************************/
openfile: procedure
    if reqfile(f)~=0 then return
    call domethod("text","open",addpart(f.drawer,f.file))
    call pragma("D",f.drawer)
    return
/***********************************************************************/
insertfile: procedure
    if reqfile(f)~=0 then return
    call domethod("text","insert",addpart(f.drawer,f.file))
    call pragma("D",f.drawer)
    return
/***********************************************************************/
savefile: procedure
    if reqfile(f)~=0 then return
    call domethod("text","save",addpart(f.drawer,f.file))
    call pragma("D",f.drawer)
    return
/***********************************************************************/
