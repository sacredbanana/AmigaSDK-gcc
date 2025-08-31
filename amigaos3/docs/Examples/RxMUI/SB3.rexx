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
    app.Version="$VER: Speedbar3 1.0 (24.2.2002)"
    app.Copyright="©2002, alfie"
    app.Author="alfie"
    app.Description="Speedbar example"
    app.Base="SPEEDBAR"
    app.SubWindow="WIN"
     win.ID="MAIN"
     win.Title="Speedbar Example"
     win.Contents="MGROUP"

      mgroup.horiz=1

      mgroup.0="spg"
        spg.class="group"
        spg.frame="group"
        spg.Background="FillBack"
        spg.Weight=0
         spg.0="sb0"
          sb0.class="SpeedBar"
          sb0.RaisingFrame=0
          sb0.Borderless=0
          sb0.ImagesDrawer="PROGDIR:Pics"
          sb0.StripUnderscore=1
          sb0.EnableUnderscore=1
          sb0.Spread=1
          sb0.Rows=3
          sb0.Spacing=1
          sb0.SameSize=1

           i=0

           sb0.i.Text="_Back"
           sb0.i.Img="back"
           sb0.i.Help="Button"
           i=i+1

           sb0.i.Text="_Forward"
           sb0.i.Img="forward"
           sb0.i.Help="Button"
           i=i+1

           sb0.i.Text="Reload"
           sb0.i.Img="reload"
           sb0.i.Help="Immediate"
           sb0.i.Flags="Immediate"
           i=i+1

           sb0.i.Text="Stop"
           sb0.i.Img="stop"
           sb0.i.Help="Toggle"
           sb0.i.Flags="Toggle"
           i=i+1

           sb0.i.Img="home"
           sb0.i.Text="Home"
           sb0.i.Help="MutualExclude with Find"
           sb0.i.Flags="Selected"
           sb0.i.Exclude=2**(i+1)
           i=i+1

           sb0.i.Text="Find"
           sb0.i.Img="find"
           sb0.i.Help="MutualExclude with Home"
           sb0.i.Exclude=2**(i-1)
           i=i+1

         spg.1=vspace()

     mgroup.1="rg"
      rg.class="group"

       cg.class="group"
       cg.0="cgf"
        cgf.class="group"
        cgf.columns=4
         cgf.0=label("Bord_erLess")
         cgf.1=checkmark("BL",,'e')
         cgf.2=label("_RaisingFrame")
         cgf.3=checkmark("RF",,'r')
         cgf.4=label("_ScaledImages")
         cgf.5=checkmark("SI",,'s')
         cgf.6=label("Sunn_y")
         cgf.7=checkmark("SN",,'y')
       cg.1=MakeObj(,"HGroup",label("_View Mode"),MakeObj("vm","Cycle","TextGfx|Gfx|Text","v"))
       cg.2=MakeObj(,"HGroup",label("Label _Pos"),MakeObj("pos","Cycle","Bottom|Top|Right|Left","p"))
      rg.0=MakeObj(,"HFRAMEGROUP","Config",MakeObj(,"VCenter",MakeObj(,"HCenter","cg")))

       hg.class="group"
       hg.columns=2
        hg.0=Label("Disable Back")
        hg.1=MakeObj(,"HLeft",checkmark("cm1"))
        hg.2=Label("Select Reload")
        hg.3=MakeObj(,"HLeft",checkmark("cm2"))
        hg.4=label("Rows")
        hg.5=MakeObj(,"HLeft",MakeObj("sl","Radio","1    |2    |3    |6    ",,2,1))
      rg.1=MakeObj(,"HFRAMEGROUP","Control",MakeObj(,"VCenter","hg"))

    if NewObj("APPLICATION","APP")>0 then exit

    call get("sb0","nobrushes","nb")
    call set("vm","disabled",nb)
    call set("sn","disabled",nb)
    call set("si","disabled",nb)

    call Notify("WIN","CLOSEREQUEST",1,"APP","RETURNID","QUIT")
    call Notify("BL","SELECTED","EVERYTIME","sb0","SET","BORDERLESS","TRIGGERVALUE")
    call Notify("RF","SELECTED","EVERYTIME","sb0","SET","RAISINGFRAME","TRIGGERVALUE")
    call Notify("SI","SELECTED","EVERYTIME","sb0","SET","SMALLIMAGES","TRIGGERVALUE")
    call Notify("SN","SELECTED","EVERYTIME","sb0","SET","SUNNY","TRIGGERVALUE")
    call Notify("vm","Active","EveryTime","sb0","Set","ViewMode","TriggerValue")
    call Notify("pos","Active","EveryTime","sb0","Set","LabelPosition","TriggerValue")

    call Notify("sb0","ACTIVE","EveryTime","app","return","say 'Active:'h.active","triggerattr")

    call Notify("cm1","selected","EveryTime","sb0","SBSET",0,"Disabled","TriggerValue")
    call Notify("cm2","selected","EveryTime","sb0","SBSET",2,"Selected","TriggerValue")
    call Notify("sl","Active","EveryTime","App","return","call ChangeRows")

    call SBNotify("sb0",0,"pressed",0,"app","return","say 'Pressed:' 0")
    call SBNotify("sb0",1,"pressed",0,"app","return","say 'Pressed:' 1")

    call SBNotify("sb0",2,"selected","EveryTime","cm2","set","selected","TriggerValue")

    call SBNotify("sb0",0,"disabled",0,"app","return","say 'Enabled:'0")
    call SBNotify("sb0",0,"disabled",1,"app","return","say 'Disabled:'0")

    call set("win","open",1)

    return
/**************************************************************************/
ChangeRows: procedure
    call DoMethod("sb0","InitChange")
    t.0=1
    t.1=2
    t.2=3
    t.3=6
    a=xget("sl","active")
    call set("sb0","Rows",t.a)
    call DoMethod("sb0","ExitChange")
    return
/***********************************************************************/
halt:
break_c:
    exit
/***********************************************************************/
