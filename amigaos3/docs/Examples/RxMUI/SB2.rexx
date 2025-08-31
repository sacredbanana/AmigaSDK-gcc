/* Speedbar beauty */

signal on halt
signal on break_c

call init
call createApp
call handleApp

/***********************************************************************/
init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call ProgDir()
    return
/***********************************************************************/
handleApp: procedure expose global.
    do forever
        call NewHandle("app","h",4096)
        if and(h.signals,4096)>0 | h.event="QUIT" then exit
        interpret h.event
    end
/***********************************************************************/
createApp: procedure expose global.
    app.Title="Speedbar"
    app.Version="$VER: Speedbar2 1.0 (24.2.2002)"
    app.Copyright="©2002, alfie"
    app.Author="alfie"
    app.Description="Speedbar example"
    app.Base="SPEEDBAR"
    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="Speedbar Example"
     win.Contents="mgroup"

      mgroup.0="speedbar"
       speedbar.class="speedbar"
       speedbar.Horiz=1
       speedbar.ImagesDrawer="PROGDIR:Pics"
       speedbar.ViewMode="Gfx"
       speedbar.Layout="Left"

        i=0

        speedbar.i.Text="_Back"
        speedbar.i.Img="back"
        speedbar.i.Help="Button"
        i=i+1

        speedbar.i.Text="_Forward"
        speedbar.i.Img="forward"
        speedbar.i.Help="Button"
        i=i+1

        speedbar.i.Text="V_iew"
        speedbar.i.Img="reload"
        speedbar.i.Help="Immediate"
        speedbar.i.Flags="Immediate"
        i=i+1

        speedbar.i.Img="Spacer"
        i=i+1

        speedbar.i.Text="Stop"
        speedbar.i.Img="stop"
        speedbar.i.Help="Toggle"
        speedbar.i.Flags="Toggle"
        i=i+1

        speedbar.i.Img="Spacer"
        i=i+1

        speedbar.i.Img="home"
        speedbar.i.Text="Home"
        speedbar.i.Help="MutualExclude with Find"
        speedbar.i.Flags="Selected"
        speedbar.i.Exclude=2**(i+1)
        i=i+1

        speedbar.i.Text="Find"
        speedbar.i.Img="find"
        speedbar.i.Help="MutualExclude with Home"
        speedbar.i.Exclude=2**(i-1)
        i=i+1

     mgroup.1="zg"
       zg.class="group"

        zg.0="vg"
         vg.class="Group"
         vg.Frame="Group"
         vg.BackGround="GroupBack"
         vg.FrameTitle="Config"

          vg.0=vspace()

          vg.1="hg"
           hg.class="Group"
           hg.Horiz=1

            hg.0=hwspace(5)

            hg.1="cgf"

            hg.1="cfg"
             cfg.class="Group"

              cfg.0=MakeObj(,"Hgroup",,
                  Label("_Appearance"),,
                  MakeObj("vm","Cycle","Icons and Text|Icons|Text","a",1),,
                  HWSpace(5),,
                  Label("_Label position"),,
                  MakeObj("lp","Cycle","Down|Up|Right|Left","l"))

              cfg.1="cfg1"
               cfg1.class="group"
               cfg1.horiz=1
                cfg1.0=HSpace()

                cfg1.1=label("_BorderLess")
                cfg1.2=checkmark("BL",,'b')

                cfg1.3=HSpace()

                cfg1.4=label("_RaisingFrame")
                cfg1.5=checkmark("RF",,'r')

                cfg1.6=HSpace()

                cfg1.7=label("_SmallImages")
                cfg1.8=checkmark("SI",,'s')

                cfg1.9=HSpace()
                cfg1.10=label("Sunn_y")
                cfg1.11=checkmark("SN",,'y')

                cfg1.12=HSpace()

                cfg1.13=label("Bar")
                cfg1.14=checkmark("BR",,'')

                cfg1.15=HSpace()

            hg.2=hwspace(5)

          vg.2=vspace()

        zg.1="rg"
         rg.class="group"
         rg.Rows=2
         rg.Frame="Group"
         rg.BackGround="GroupBack"
         rg.FrameTitle="Control"
          rg.0=hspace()
          rg.1=Label("Disable Back")
          rg.2=checkmark("cm1")
          rg.3=hspace()
          rg.4=Label("Select View")
          rg.5=checkmark("cm2")
          rg.6=hspace()
          rg.7=hspace()
          rg.8=label("Show Forward")
          rg.9=checkmark("cm3",1,'w')
          rg.10=hspace()
          rg.11=label("Horiz")
          rg.12=checkmark("horiz",,'')
          rg.13=hspace()

    if NewObj("Application","app")>0 then exit

    call get("speedbar","nobrushes","nb")
    call set("vm","disabled",nb)
    call set("sn","disabled",nb)
    call set("si","disabled",nb)

    call Notify("win","closerequest",1,"app","returnid","quit")
    call Notify("bl","selected","everytime","speedbar","set","borderless","triggervalue")
    call Notify("rf","selected","everytime","speedbar","set","raisingframe","triggervalue")
    call Notify("si","selected","everytime","speedbar","set","smallimages","triggervalue")
    call Notify("sn","selected","everytime","speedbar","set","sunny","triggervalue")
    call Notify("br","selected","everytime","speedbar","set","barspacer","triggervalue")
    call Notify("vm","Active","EveryTime","SpeedBar","Set","ViewMode","TriggerValue")
    call Notify("lp","Active","EveryTime","SpeedBar","Set","LabelPosition","TriggerValue")

    call Notify("speedbar","active","EveryTime","app","return","say 'Active:'h.active","triggerattr")

    call Notify("cm1","selected","EveryTime","speedbar","SBSet",0,"Disabled","TriggerValue")
    call Notify("cm2","selected","EveryTime","speedbar","SBSet",2,"Selected","TriggerValue")
    call Notify("cm3","selected","EveryTime","speedbar","SBSet",1,"ShowMe","TriggerValue")
    call Notify("horiz","selected","EveryTime","app","return","call changehoriz(h.selected)","TriggerAttr")

    call SBNotify("speedbar",0,"pressed",0,"app","return","say 'Pressed:' 0")
    call SBNotify("speedbar",1,"pressed",0,"app","return","say 'Pressed:' 1")

    call SBNotify("speedbar",2,"selected","EveryTime","cm2","set","selected","TriggerValue")

    call SBNotify("speedbar",0,"disabled",0,"app","return","say 'Enabled:'0")
    call SBNotify("speedbar",0,"disabled",1,"app","return","say 'Disabled:'0")

    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
changehoriz: procedure
parse arg h
    call DoMethod("mgroup","InitChange")
    call set("mgroup","horiz",h,0)
    call set("speedbar","horiz",~h,0)
    call DoMethod("mgroup","ExitChange")
    return
