/* Very cute: show the content of the clipboard
** both text and image
**/

signal on halt
signal on break_c

call Init()
call CreateApp(f)
call HandleApp
/* never reached */

/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call MacroEnv("global","ProgDir CD")
    call SetRxMUIStack(16384)
    global.noti=StartNotify("CLIP",0)
    if global.noti<0 then do
        call PrintFault(IoErr(),ProgramName("NOEXT"))
        exit
    end
    global.ns=NotifySignal(global.noti)
    global.bm=0
    if NewObj("rectangle","bm")>0 then exit
    return
/***********************************************************************/
CreateApp: procedure expose global.

    call RxMUIOpt("debugmode showerr")

    app.Title="Clipview"
    app.Version="$VER: Clipview 1.1 (25.1.2002)"
    app.Copyright="Copyright 2002 by alfie"
    app.Author="alfie"
    app.Description="Clipview example"
    app.Base="CLIPVIEW"
    app.SubWindow="win"

     win.ID="main"
     win.Title="Clipview"
     win.UseBottomBorderScroller=1
     win.UseRightBorderScroller=1
     win.Contents="mgroup"

      mgroup.0="sg"
       sg.class="scrollgroup"
       sg.UseWinBorder=1
       sg.frame="virtual"
       sg.virtgroupcontents="vg"
        vg.class="virtgroup"

    if NewObj("APPLICATION","APP")>0 then exit

    call RxMUIOpt("")

    call CreateClipObject()

    call set("win","open",1)

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")

    return
/***********************************************************************/
HandleApp: procedure expose global.

    ctrl_c=2**12
    mask=or(ctrl_c,global.ns)
    do forever

        call NewHandle("app","h",mask)

        if and(h.signals,ctrl_c)>0 then exit
        if and(h.signals,global.ns)>0 then call CreateClipObject()
        if h.EventFlag then
            select
                when h.event="QUIT" then exit
                otherwise interpret h.event
            end

    end
    /* never reached */
/***********************************************************************/
CreateClipObject: procedure expose global.

    call set("app","sleep",1)

    call DoMethod("vg","InitChanges")
    if global.bm then call Dispose("chg")

    bm.sourcetype="Clipboard"
    bm.source=0
    if NewObj("picture","bm")>0 then do
        if ReadTextClip("t")>0 then do
            drop bm.
            bm.contents=t
            if NewObj("text","bm")>0 then exit
            t="text"
        end
        else t="none"
    end
    else t="picture"

    chg.horiz=1
    chg.spacing=0
     chg.0="cvg"
      cvg.class="group"
      cvg.spacing=0
       cvg.0="bm"
       cvg.1=vspace()
     chg.1=hspace()
    if NewObj("group","chg")>0 then exit

    global.bm=1

    call Add("vg","chg")
    call DoMethod("vg","ExitChanges")
    call set("win","Title","Clipview ["t"]")
    call set("app","sleep",0)
    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

