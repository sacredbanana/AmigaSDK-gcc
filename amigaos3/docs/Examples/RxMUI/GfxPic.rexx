/**/

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rxmui.library")~=0 then exit
    parm.0.value=""
    if ~ReadArgs("FILE,FREE/S,TRANS/S") then do
        call PrintFault()
        exit
    end
    global.file=parm.0.value
    global.free=parm.1.flag
    global.trans=parm.2.flag
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

	app.Title="GFXPicExample"
	app.Version="$VER: GFXPicExample 2.0 (5.3.2000)"
	app.Copyright="Copyright 2003 by  alfie"
	app.Author="alfie"
	app.Description="GFXPicExample"
	app.Base="RXMUIEXAMPLE"

	app.SubWindow="win"
	 win.ID="MAIN"
	 win.Title="GFXPic example"
     win.UseRightBorderScroller=1
     win.UseBottomBorderScroller=1

	 win.Contents="mgroup"

	  mgroup.0="sg"
       sg.Class="Scrollgroup"
	   sg.aFrame="virtual"
	   sg.aBackground="groupback"
       sg.UseWinBorder=1

       sg.VirtGroupContents="vg"
        vg.Class="Virtgroup"
         vg.0="dt"
		  dt.Class="GFXPic"
		  dt.Transparent=0
		  dt.XUnlimited=1
		  dt.yUnlimited=1
          dt.rendered=1
          dt.FreeHoriz=global.free
          dt.FreeVert=global.free
          dt.Transparent=global.trans
          dt.LoadAtOpen=1

	app.SubWindow.1="cwin"
	 cwin.ID="CWIN"
	 cwin.Title="GFXPic example controls"

     cwin.Contents="cmgroup"

      cmgroup.0="IG"
        ig.Class="hgroup"
         ig.0=label("_Image")
         ig.1="popa"
          popa.Class="popasl"
          popa.String=string("image",'i',global.file)

      cmgroup.1="rd"
       rd.Class="gauge"
       rd.Horiz=1
       rd.FixHeightTxt="X"
       rd.Max=100
      cmgroup.2=XNewObj("scale")

      cmgroup.3="fg"
       fg.Class="group"
       fg.Frame="group"
       fg.Background="groupback"
       fg.Columns=2
        fg.0=label("_Scale")
        fg.1="ssg"
         ssg.Class="hgroup"
          scale.Disabled=global.free
          scale.Stringify="parse arg v;if v=0 then return 'Off';return v '%'"
          ssg.0=MakeObj("scale","slider",'s',0,200)
           applyscale.SetMax=1
           applyscale.Disabled=global.free
          ssg.1=button("applyscale","_Apply")
        fg.2=label("_Trans")
        fg.3="cg"
         cg.class="hgroup"
           trans.Disabled=1
          cg.0=checkmark("trans",global.trans,"t")
          cg.1=button("flipx","Flip _X")
          cg.2=button("flipy","Flip _Y")
        fg.4=label("_HSType")
        fg.5="ccg"
         ccg.class="hgroup"
          ccg.0=MakeObj("hstype","Cycle","12Bit|15Bit|18Bit|21Bit|24Bit|12BitTurbo|15BitTurbo|18BitTurbo",'h',5)
          ccg.1=label("_Dither")
          ccg.2=MakeObj("dither","Cycle","None|FS|RANDOM|EDD",'d',1)
          ccg.3=label("_Quality")
          ccg.4=MakeObj("quality","Cycle","Gui|Icon|Image|Exact",'q',2)

      cmgroup.4="dg"
       dg.Class="group"
        dg.Columns=4
        dg.Frame="group"
        dg.Background="groupback"
         dg.0=label("Image width")
         dg.1=text("width")
         dg.2=label("Image height")
         dg.3=text("height")
         dg.4=label("Scaled width")
         dg.5=text("swidth")
         dg.6=label("Scaled height")
         dg.7=text("sheight")

	if NewObj("APPLICATION","APP")>0 then exit

	call Notify("win","CloseRequest",1,"app","ReturnID","quit")
	call Notify("cwin","CloseRequest",1,"app","ReturnID","quit")

    call Notify("image","Newcontents","EveryTime","app","Return","call rebuild")
    call Notify("applyscale","Pressed",0,"app","Return","call scale()")
    call Notify("flipx","Pressed",0,"app","Return","call flipx")
    call Notify("flipY","Pressed",0,"app","Return","call flipY")
    call Notify("trans","Selected","EveryTime","dt","set","Transparent","TriggerValue")
    call Notify("hstype","ActiveEntry","EveryTime","app","return","call rebuildChange")
    call Notify("dither","ActiveEntry","EveryTime","app","return","call rebuildChange")
    call Notify("quality","ActiveEntry","EveryTime","app","return","call rebuildChange")

    call Notify("dt","ImageWidth","EveryTime","Width","set","integer","TriggerValue")
    call Notify("dt","ImageHeight","EveryTime","Height","set","Integer","TriggerValue")
    call Notify("dt","ScaledWidth","EveryTime","swidth","set","Integer","TriggerValue")
    call Notify("dt","ScaledHeight","EveryTime","sheight","set","Integer","TriggerValue")
    call Notify("dt","Alpha","EveryTime","trans","set","disabled","NotTriggerValue")
    call Notify("dt","Rendered","EveryTime","rd","set","Current","TriggerValue")

	call set("win","Open",1)
    call set("cwin","Open",1)
    call rebuild

    return
/***********************************************************************/
rebuild: procedure expose global.
    call set("app","Sleep",1)
    call get("image","Contents",f)
    call DoMethod("sg","InitChange")
    call set("dt","Source",f)
    call DoMethod("sg","ExitChange")
    call set("app","Sleep",0)
    return
/**************************************************************************/
halt:
break_c:
	exit
/**************************************************************************/
scale: procedure expose global.
    call set("app","Sleep",1)
    call DoMethod("sg","InitChange")
    call set("dt","Scale",xget("scale","Value"))
    call DoMethod("sg","ExitChange")
    call set("app","Sleep",0)
    return
/**************************************************************************/
flipx: procedure expose global.
    call set("app","Sleep",1)
    call DoMethod("dt","FlipX")
    call set("app","Sleep",0)
    return
/**************************************************************************/
flipy: procedure expose global.
    call set("app","Sleep",1)
    call DoMethod("dt","FlipY")
    call set("app","Sleep",0)
    return
/**************************************************************************/
rebuildChange: procedure expose global.
    call set("dt","HSType",xget("hstype","activeentry"))
    call set("dt","DitherMode",xget("dither","activeentry"))
    call set("dt","Precision",xget("quality","activeentry"))
    call rebuild
    return
/**************************************************************************/
