/* Picture example. Show a saved-in-the-macro pic */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
Init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library","rxlibnet.library")~=0 then exit
    return
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
CreateApp: procedure
    app.Title="PictureExample"
    app.Version="$VER: PictureExample 1.2 (25.1.2002)"
    app.Copyright="Copyright © 2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="PictureExample"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"
     win.ID="bpic"
     win.Title="PictureExample"
     win.Contents="mgroup"
      bm.Class="Picture"
      bm.Source=GetSource()
      bm.SourceType="mem"
      bm.InputMode="RelVerify"
      bm.Frame="Button"

      mgroup.0=text(,ParseText("
This is a builtin image.\n
It means that image data are saved\n
in the macro itself."))

      mgroup.1=MakeObj(,"VCenter",MakeObj(,"HCenter","bm"))

    if NewObj("Application","app")>0 then exit

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")
    call Notify("bm","Pressed",0,"app","return","say 'bm pressed'")

    call set("win","Open",1)

    say "-- Information --"
    say "      Width:" xget("bm","BitmapWidth")
    say "     Height:" xget("bm","BitmapHeight")
    say "      Depth:" xget("bm","BitmapDepth")
    say "    Masking:" xget("bm","BitmapMasking")
    say "Compression:" xget("bm","BitmapCompression")
    say "Transparent:" xget("bm","BitmapTransparent")
    say "    XAspect:" xget("bm","BitmapXAspect")
    say "    YAspect:" xget("bm","BitmapYAspect")

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
/* This is obteined via rxlibnet.library/EncodeB64(),
   The simplest way is to use p2s.rexx */

GetSource:

call DecodeB64("
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
IgABACH9ABM/f///7fu/+/9r/d3//v/e//VAAAo=","res","string var")

return res
/**************************************************************************/
