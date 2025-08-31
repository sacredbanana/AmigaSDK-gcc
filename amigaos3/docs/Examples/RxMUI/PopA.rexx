/* PopAsl example */

signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit

call RxMUIOpt("debugmode showerr")
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
HandleApp: procedure

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
err: procedure expose sigl rxmuierror
parse arg res
say sigl "["res"]"
    say getrxmuistring(res) "in line" sigl-1 rxmuierror
    exit
/***********************************************************************/
CreateApp: procedure

    app.Title="PopaslExample"
    app.Version="$VER: PopaslExample 1.0 (12.10.2000)"
    app.Copyright="©2000, alfie"
    app.Author="alfie"
    app.Description="PopaslExample"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="PopaslExample"
     win.Contents="MGROUP"

      mgroup.0="pg"
       pg.class="group"
       pg.frame="group"
       pg.frametitle="Popasl example"
       pg.background="groupback"
       pg.Columns=2

      pg.0=label("HTML only")
      pg.1="popf"
       popf.class="popasl"
       popf.FilterMacro="parse arg a,b,c;return match('#?.(htm|html)',a)"
       popf.DomultiSelect=1
       popf.AcceptPattern="#?"
       popf.RejectPattern="#?.o"
        url.Maxlen=16000
       popf.String=string("file")
       popf.DoPattern=1
       popf.SleepWindow=1
       popf.InitialPattern="#?"
       popf.Title="File selector"

       /*
       PopSpec examples:
       popf.PopSpec="1:1"
       popf.PopSpec="2:C0C0C0C0,C0C0C0C0,C0C0C0C0"
       popf.PopSpec="2:m3" (use pen number 3 - undocumented hack)
       popf.PopSpec="3:" FORGET ABOUT THIS!
       popf.PopSpec="4:XEN/Gradient/11pt/PopFile.mf0"
       popf.PopSpec="5:Pics/Stop"
       popf.PopSpec="6:12"
       */
      pg.2=label("Above")
      pg.3=Text("info")

      pg.4=label("Drawer")
      pg.5="popd"
       popd.class="popasl"
       popd.String=string("dir")
       popd.DrawersOnly=1
       popd.Title="Drawer selector"

      pg.6=label("Font")
      pg.7="popfo"
       popfo.class="popasl"
       popfo.type="font"
       popfo.String=string("font")
       popfo.Title="Fonts selector"
       popfo.toggle=0

      pg.8=label("Fixed font")
      pg.9="popfof"
       popfof.class="popasl"
       popfof.type="font"
       popfof.FixedWidthOnly=1
       popfof.String=string("fixedfont")
       popfof.Title="Fonts selector"

      mgroup.1="bg"
       bg.class="group"
       bg.horiz=1
        bg.0=hspace()
        bg.1=button("fo","Font _Open")
        bg.2=hspace()

    res=NewObj("APPLICATION","APP")
    if res~=0 then call err(res)

    call set("win","open",1)

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")
    call notify("file","newcontents","everytime",info,set,contents,triggervalue)

    call notify("fo","pressed",0,"popfo","open")

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

