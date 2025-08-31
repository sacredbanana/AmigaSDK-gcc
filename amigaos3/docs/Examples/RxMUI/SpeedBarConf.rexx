/* SpeedBar configuration example macro */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp

/***********************************************************************/
Init: procedure expose expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rxmui.library")~=0 then exit
    call ProgDir()
    return
/***********************************************************************/
CreateApp: procedure expose global.

    app.Title="SpeedBarConf"
    app.Version="$VER: SpeedBarConf 1.1 (27.6.2002)"
    app.Copyright="Copyright 2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="SpeedBar configuration example macro"
    app.Base="BARCONF"

    app.MenuStrip="strip"
     strip.0="mproject"
      mproject.Title="Project"
      mproject.class="menu"
       mproject.0=menuitem("mabout","?\About...")
       mproject.1=menuitem("maboutrxmui","X\About RxMUI...")
       mproject.2=menuitem("maboutmui","!\About MUI...")
       mproject.3=menuitem("","BAR")
       mproject.4=menuitem("mhide","H\Hide")
       mproject.5=menuitem("","BAR")
       mproject.6=menuitem("mquit","Q\Quit")

    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="SpeedBar configuration"
     win.Contents="mgroup"

      mgroup.0="hg"
       hg.Class="group"
       hg.Horiz=1

        hg.0="bg"
         bg.Class="group"

          bg.0="lg"
           lg.Class="group"
           lg.Horiz=1
            lg.0="fromlv"
             fromlv.Class="NListview"
             fromlv.FrameTitle="Available buttons"
             fromlv.DragType="Immediate"
             fromlv.ControlChar="1"
             fromlv.List="fromList"
              fromList.DragSortable=1
              fromList.Format=","
              fromList.MinColCompare=1
              fromList.Image.0="im0"
               im0.Class="picture"
               im0.Source="PROGDIR:Pics/Back"
               im0.Transparent=1
              fromList.Image.1="im1"
               im1.Class="picture"
               im1.Source="PROGDIR:Pics/Find"
               im1.Transparent=1
              fromList.Image.2="im2"
               im2.Class="picture"
               im2.Source="PROGDIR:Pics/Forward"
               im2.Transparent=1
              fromList.Image.3="im3"
               im3.Class="picture"
               im3.Source="PROGDIR:Pics/Home"
               im3.Transparent=1
              fromList.Image.4="im4"
               im4.Class="picture"
               im4.Source="PROGDIR:Pics/Reload"
               im4.Transparent=1
              fromList.Image.5="im5"
               im5.Class="picture"
               im5.Source="PROGDIR:Pics/Spacer"
               im5.Transparent=1
              fromList.Image.6="im6"
               im6.Class="picture"
               im6.Source="PROGDIR:Pics/Stop"
               im6.Transparent=1

            lg.1="rec"
             rec.class="rectangle"
             rec.weight=5

            lg.2="tolv"
             tolv.Class="NListview"
             tolv.FrameTitle="Bar buttons"
             tolv.DragType="Immediate"
             tolv.List="toList"
              toList.DragSortable=1
              toList.Format=","
              toList.Image.0="im0"
              toList.Image.1="im1"
              toList.Image.2="im2"
              toList.Image.3="im3"
              toList.Image.4="im4"
              toList.Image.5="im5"
              toList.Image.6="im6"

          bg.1="vg"
           vg.Class="group"
           vg.Frame="group"
           vg.FrameTitle="Appareance"
           vg.Background="groupback"
            vg.0="vg0"
             vg0.Class="group"
             vg0.Horiz=1
              vg0.0=Label("Toolbar appears as")
              vg0.1=MakeObj("vm","Cycle","TextGfx|Gfx|Text")
            vg.1="vg1"
             vg1.Class="group"
             vg1.Horiz=1
              vg1.0=Label("Borderless")
              vg1.1=Checkmark("bl")
              vg1.2=Hspace()
              vg1.3=Label("Highlight")
              vg1.4=Checkmark("su")
              vg1.5=Hspace()
              vg1.6=Label("Raised")
              vg1.7=Checkmark("ra")
              vg1.8=Hspace()
              vg1.9=Label("Small")
              vg1.10=Checkmark("sm")
              vg1.11=Hspace()
              vg1.12=Label("Vert")
              vg1.13=Checkmark("ve")

        hg.1="cg"
         cg.Class="group"
         cg.Frame="virtual"
         cg.Background="groupback"
         cg.Weight=15
          cg.0=Button("reset","_Reset")
          cg.1=Button("test","_Test")
          cg.2=VSpace()
          cg.3=Button("cancel","_Cancell")

    call NewObj("Application","app")

    call DandD("fromList","fromList","NoSelf")
    call DandD("fromList","toList")
    call DandD("toList","fromlv")

    call Notify("win","CloseRequest",1,"app","returnid","quit")
    call Notify("mabout","menutrigger","everytime","app","about","win")
    call Notify("maboutrxmui","menutrigger","everytime","app","aboutrxmui","win")
    call Notify("maboutmui","menutrigger","everytime","app","aboutmui","win")
    call Notify("mhide","menutrigger","everytime","app","set","iconified",1)
    call Notify("mquit","menutrigger","everytime","app","returnid","quit")

    call Notify("fromList","DoubleClick","Everytime","app","return","call doubleClick('FROMLIST','TOLIST')")
    call Notify("toList","DoubleClick","Everytime","app","return","call doubleClick('TOLIST','FROMLIST')")

    call Notify("reset","pressed",0,"app","return","call resetLists")
    call Notify("test","pressed",0,"app","return","call testfun")
    call Notify("cancel","pressed",0,"app","returnid","quit")

    call resetLists
    call set("win","open",1)

    return
/**************************************************************************/
handleApp: procedure expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            when h.event="DROPEVENT" then call dropFun(h.from,h.to)
            otherwise interpret h.event
        end
    end
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
resetLists: procedure expose global.
    s.0="[Image im0]|Back"
    s.1="[Image im1]|Find"
    s.2="[Image im2]|Forward"
    s.3="[Image im3]|Home"
    s.4="[Image im4]|Reload"
    s.5="[Image im5]|Spacer"
    s.6="[Image im6]|Stop"
    call DoMethod("fromList","ClearAddStem","s")
    call DoMethod("toList","Clear")
    return
/**************************************************************************/
dropFun: procedure expose global.
parse arg from,to
    call DoMethod(from,"GetEntry","Active","e")
    parse var e im "|" name
    if to="TOLIST" then do
        if name~="Spacer" then call DoMethod("fromList","Remove","Active")
        call DoMethod("toList","Insert",e,xget("toList","DropMark"))
    end
    else do
        call DoMethod("toList","Remove","Active")
        if name~="Spacer" then call DoMethod("fromList","Insert",e,"Sorted")
    end
    return
/**************************************************************************/
doubleClick: procedure expose global.
parse arg from,to
    call DoMethod(from,"GetEntry","Active","e")
    parse var e im "|" name
    if to="TOLIST" then do
        if name~="Spacer" then call DoMethod("fromList","Remove","Active")
        call DoMethod("toList","Insert",e,"Bottom")
    end
    else do
        call DoMethod("toList","Remove","Active")
        if name~="Spacer" then call DoMethod("fromList","Insert",e,"Sorted")
    end
    return
/**************************************************************************/
testFun: procedure expose global.
	call set("app","Sleep",1)

    if global.twin=1 then do
        call Dispose("twin")
        global.twin=0
    end

    n=xget("toList","entries")
    if n=0 then do
		call set("app","Sleep",0)
		return
	end

    twin.ID="TWIN"
    twin.Title="Test window"
    twin.Contents="tgroup"

      speedbar.Class="speedbar"
      speedbar.ImagesDrawer="PROGDIR:Pics"
      speedbar.BarSpacer=1

      speedbar.Horiz=~xget("ve","selected")
      speedbar.ViewMode=xget("vm","active")
      speedbar.Borderless=xget("bl","selected")
      speedbar.Sunny=xget("su","selected")
      speedbar.RaisingFrame=xget("ra","selected")
      speedbar.SmallImages=xget("sm","selected")
      speedbar.Layout="Left"

      do i=0 to n-1
          call DoMethod("toList","GetEntry",i,"e")
          parse var e im "|" name
          speedbar.i.Img=name
          if name="Spacer" then iterate
          speedbar.i.Text=name
      end

     tgroup.0="speedbar"

       spg.1=hvspace()

    if NewObj("window","twin")>0 then do
		call set("app","Sleep",0)
		return
	end

    call add("app","twin")
    call Notify("twin","CloseRequest",1,"app","return","if global.twin then call dispose('twin');global.twin=0")
    call set("twin","open",1)
    global.twin=1
	call set("app","Sleep",0)
    return
/**************************************************************************/
