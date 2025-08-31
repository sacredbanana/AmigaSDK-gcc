/* Simone Tellini's Speedbar beauty */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp

/***********************************************************************/
Init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call ProgDir()
    return
/***********************************************************************/
HandleApp: procedure
    do forever
        call NewHandle("app","h",4096)
        if and(h.signals,4096)>0 | h.event="QUIT" then exit
        interpret h.event
    end
/***********************************************************************/
CreateApp: procedure
    app.Title="Speedbar"
    app.Version="$VER: Speedbar 1.1 (24.2.2002)"
    app.Copyright="©2002, alfie"
    app.Author="alfie"
    app.Description="Speedbar example"
    app.Base="SPEEDBAR"
    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="Speedbar Example"
     win.Contents="mgroup"

      mgroup.0="speedbar"
       speedbar.class="SpeedBar"
       speedbar.Horiz=1
       speedbar.ImagesDrawer="PROGDIR:Pics"
       speedbar.Layout="Left"
        speedbar.0.Img="back"
        speedbar.0.Text="Back"
        speedbar.1.Img="forward"
        speedbar.1.Text="Forward"
        speedbar.2.Flags="Immediate selected"
        speedbar.2.Img="reload"
        speedbar.2.Text="Reload"
        speedbar.2.Flags="Immediate"
        speedbar.3.Img="stop"
        speedbar.3.Text="Stop"
        speedbar.3.Flags="Toggle"
        speedbar.4.Img="Spacer"
        speedbar.5.Img="home"
        speedbar.5.Text="Home"
        speedbar.5.Flags="Immediate Selected"
        speedbar.5.Exclude=2**6
        speedbar.6.Img="find"
        speedbar.6.Text="Find"
        speedbar.6.Flags="Immediate"
        speedbar.6.Exclude=2**5
        speedbar.7.Img="Spacer"
        speedbar.8.Img="book"
        speedbar.8.Text="Book"
        speedbar.8.Flags="Immediate Selected"
        speedbar.8.Exclude=2**9
        speedbar.9.Img="folder"
        speedbar.9.Text="Folder"
        speedbar.9.Flags="Immediate"
        speedbar.9.Exclude=2**8

      mgroup.1=HBar()

      mgroup.2="vg"
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
                MakeObj("vm","Cycle","Icons and Text|Icons|Text","a"),,
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

      mgroup.3="cg"
       cg.class="group"
       cg.horiz=1
        cg.0=hspace()
        cg.1=Label("Enable 0")
        cg.2=checkmark("cm1",1)
        cg.3=hwspace(20)
        cg.4=Label("Select 2")
        cg.5=checkmark("cm2")
        cg.6=hspace()

    if NewObj("Application","app")>0 then exit

    call get("speedbar","nobrushes","nb")
    call set("vm","disabled",nb)
    call set("lp","disabled",nb)
    call set("sn","disabled",nb)
    call set("si","disabled",nb)

    call Notify("vm","active","EveryTime","speedbar","set","viewmode","TriggerValue")
    call Notify("lp","active","EveryTime","speedbar","set","labelposition","TriggerValue")

    call Notify("win","closerequest",1,"app","returnid","quit")
    call Notify("bl","selected","everytime","speedbar","set","borderless","triggervalue")
    call Notify("rf","selected","everytime","speedbar","set","raisingframe","triggervalue")
    call Notify("si","selected","everytime","speedbar","set","smallimages","triggervalue")
    call Notify("sn","selected","everytime","speedbar","set","sunny","triggervalue")
    call Notify("br","selected","everytime","speedbar","set","BarSpacer","triggervalue")

    call Notify("speedbar","active","EveryTime","app","return","say 'Active:'h.active","triggerattr")

    call Notify("cm1","selected","EveryTime","speedbar","SBSet",0,"Disabled","NotTriggerValue")
    call Notify("cm2","selected","EveryTime","speedbar","SBSet",2,"Selected","TriggerValue")

    call SBNotify("speedbar",0,"pressed",0,"app","return","say 'Pressed:' 0")
    call SBNotify("speedbar",1,"pressed",0,"app","return","say 'Pressed:' 1")

    call SBNotify("speedbar",2,"selected","EveryTime","cm2","set","selected","TriggerValue")

    call SBNotify("speedbar",8,"selected",1,"app","return","say 'Selected:'8")
    call SBNotify("speedbar",9,"selected",1,"app","return","say 'Selected:'9")

    call SBNotify("speedbar",0,"disabled",0,"app","return","say 'Enabled:'0")
    call SBNotify("speedbar",0,"disabled",1,"app","return","say 'Disabled:'0")

    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
