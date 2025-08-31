/*
Name:     WarpDT.rexx
Goal:     Warp datatypes configuration GUI
Version:  2.0
Date:     10.11.2002
Author:   Alfonso Ranieri
*/

signal on halt
signal on break_c

call Init()
call CreateApp()
call HandleApp()
/* never reached */
/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~AddLib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call RxMUIOpt("DebugMode ShowErr")
    global.test=0
    return
/***********************************************************************/
HandleApp: procedure expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)~=0 then call SafeExit()
        if h.EventFlag then
            select
                when h.event="QUIT" then call SafeExit()
                otherwise interpret h.event
            end
    end
    /* never reached */
/***********************************************************************/
CreateApp: procedure expose global.

    mstrip.0="mproject"
     mproject.Class="menu"
     mproject.Title="Project"
      mproject.0=MenuItem("mabout","About...","?")
      mproject.1=MenuItem("maboutrxmui","About RxMUI...")
      mproject.2=MenuItem("maboutmui","About MUI...")
      mproject.3=MenuItem("","BAR")
      mproject.4=MenuItem("mhide","Hide","H")
      mproject.5=MenuItem("","BAR")
      mproject.6=MenuItem("mquit","Quit","Q")
    mstrip.1="meditor"
     meditor.Class="menu"
     meditor.Title="Editor"
      meditor.0=MenuItem("mdefault","Reset to defaults","D")
      meditor.1=MenuItem("mlast","Last saveds","L")
      meditor.2=MenuItem("mrestore","Restore","R")
      meditor.3=MenuItem("","BAR")
      meditor.4=MenuItem("mmui","MUI...")
    if NewObj("menustrip","mstrip")>0 then exit

    app.title="WarpDT"
    app.version="$VER: WarpDT 2.0 (10.11.2002)"
    app.copyright="Copyright 2002 by Alfonso Ranieri"
    app.author="Alfonso Ranieri"
    app.description="Manages Warp DT preferences"
    app.base="WarpDT"
    app.MenuStrip="mstrip"
    app.SubWindow="mwin"

     mwin.title="WarpDT Preferences"
     mwin.ID="MAIN"
     mwin.contents="mgroup"

      mgroup.0="hg"
       hg.Class="group"
       hg.Horiz=1
       hg.Spacing=2

       hg.0="hlister"
        hlister.Class="listview"
        hlister.FixWidthTxt="123456789012"
        hlister.list="entries"
        hlister.CycleChain=1
          entries.Frame="InputList"
          entries.Names=ParseText("WarpDT,JPEG,PNG,TIFF,%iBPM,%iPSD")

       hg.1="hpager"
        hpager.Class="group"
        hpager.PageMode=1
        hpager.Frame="ReadList"
        hpager.Background="PageBack"

         hpager.0="warpdt"
          warpdt.Class="group"
           warpdt.0="dith"
            dith.Class="group"
            dith.Frame="Group"
            dith.FrameTitle="Dithering"
            dith.Background="GroupBack"
             dith.0=VSpace()
             dith.1="dith1"
              dith1.Class="group"
              dith1.Columns=2
              dith1.0=Label("_Override")
                DITHER_OVERRIDE.CycleChain=1
              dith1.1=MakeObj("DITHER_OVERRIDE","Cycle","Nothing|Defaults Only|Applications Only|Everything","o",1)
              dith1.2=Label("_Quality")
                DITHER_QUALITY.CycleChain=1
              dith1.3=MakeObj("DITHER_QUALITY","Cycle","Poor (Fast)|Good (Slow)|Best (Slow)","q")
              dith1.4=Label("_Depth filter")
                DITHER_DEPTH.CycleChain=1
              dith1.5=MakeObj("DITHER_DEPTH","slider",'d',1,24)
             dith.2=VSpace()

           warpdt.1="PenSel"
            PenSel.Class="group"
            PenSel.Frame="Group"
            PenSel.FrameTitle="Pen selection"
            PenSel.Background="GroupBack"
             PenSel.0=VSpace()
             PenSel.1="PenSel1"
              PenSel1.Class="Group"
              PenSel1.Columns=2
              PenSel1.0=Label("O_verride")
                PENS_OVERRIDE.CycleChain=1
              PenSel1.1=MakeObj("PENS_OVERRIDE","Cycle","Nothing|Defaults Only|Applications Only|Everything","v",1)
              PenSel1.2=Label("Qu_ality")
                PENS_QUALITY.CycleChain=1
              PenSel1.3=MakeObj("PENS_QUALITY","Cycle","Poor|Good|Best","a")
             PenSel.2=VSpace()

         hpager.1="jpeg"
          jpeg.Class="group"

           jpeg.0="Dec"
            Dec.Class="group"
            Dec.Frame="Group"
            Dec.FrameTitle="Decoder"
            Dec.Background="GroupBack"
             Dec.0=VSpace()
             Dec.1="dec1"
              dec1.Class="group"
              dec1.Columns=2
               dec1.0=Label("_Output mode")
                 OUTPUT_MODE.CycleChain=1
               dec1.1=MakeObj("OUTPUT_MODE","Cycle","Full Colour (24 bit)|Reduced Colour|Grey scale","o",1)
               dec1.2=Label("_DCT quality")
                 DCT_METHOD.CycleChain=1
               dec1.3=MakeObj("DCT_METHOD","Cycle","Good (Fatest)|Best (Slower)","d")
               dec1.4=Label("_Fancy Upsampling")
                 FANCY_UPSAMPLING.CycleChain=1
               dec1.5=MakeObj(,"HLeft",Checkmark("FANCY_UPSAMPLING",,"f"))
             Dec.2=VSpace()

           jpeg.1="ColRed"
            ColRed.Class="group"
            ColRed.Frame="Group"
            ColRed.FrameTitle="Colour reduction"
            ColRed.Background="GroupBack"
             ColRed.0=VSpace()
             ColRed.1="crg"
              crg.Class="group"
              crg.Columns=2
               crg.0=Label("D_ithering")
                 DITHER.CycleChain=1
               crg.1=MakeObj("DITHER","Cycle","None|Ordered|Floyd-Steinberg","i",0)
               crg.2=Label("Co_lour Quality")
                 QUANTIZATION.CycleChain=1
               crg.3=MakeObj("QUANTIZATION","Cycle","Poor (Fast)|Best (Slow)","l")
               crg.4=Label("_Max Colours")
                 NUM_COLOURS.CycleChain=1
               crg.5=MakeObj("NUM_COLOURS","slider",'m',8,256)
             ColRed.2=VSpace()

         hpager.2="png"
          png.Class="group"

            png.0="gamma"
             gamma.Class="group"
             gamma.Background="GroupBack"
             gamma.Frame="Group"
             gamma.FrameTitle="Gamma correction"
             gamma.0=VSpace()
             gamma.1="gamma1"
              gamma1.Class="group"
               GAMMA_CORRECTION.CycleChain=1
              gamma1.0=MakeObj(,"HCenter",MakeObj(,"HGroup",Label("_Enable"),Checkmark("GAMMA_CORRECTION",,'e')))
              gamma1.1="GammaCorrection"
               GammaCorrection.Class="group"
               GammaCorrection.Columns=2
                GammaCorrection.0=Label("Sc_reen Gamma")
                GammaCorrection.1="ScreenGammaPO"
                  ScreenGammaPO.Class="PopObject"
                  ScreenGammaPO.ButtonCycleChain=1
                   SCREEN_GAMMA.Accept="0123456789."
                   SCREEN_GAMMA.CycleChain=1
                  ScreenGammaPO.String=String("SCREEN_GAMMA",'r')
                  ScreenGammaPO.Object="ScreenGammaLV"
                   ScreenGammaLV.Class="Listview"
                   ScreenGammaLV.AutoDefault=1
                   ScreenGammaLV.List="ScreenGammaList"
                    ScreenGammaList.Names="Normal,Darker,Brighter"
                  ScreenGammaPO.OpenFun="call set('ScreenGammaList','Active',-1);return 1"
                  ScreenGammaPO.CloseFun="
                        v.0=2.2;v.1=2.0;v.2=2.4;
                        a=xget('ScreenGammaList','Active');
                        call set('SCREEN_GAMMA','contents',v.a)"

               GammaCorrection.2=Label("_Image gamma")
               GammaCorrection.3="ImageGammaPO"
                  ImageGammaPO.Class="PopObject"
                  ImageGammaPO.ButtonCycleChain=1
                   IMAGE_GAMMA.Accept="0123456789."
                   IMAGE_GAMMA.CycleChain=1
                  ImageGammaPO.String=String("IMAGE_GAMMA",'i')
                  ImageGammaPO.Object="ImageGammaLV"
                   ImageGammaLV.Class="Listview"
                   ImageGammaLV.AutoDefault=1
                   ImageGammaLV.List="ImageGammaList"
                    ImageGammaList.Names="Normal,Low,High"
                  ImageGammaPO.OpenFun="call set('ImageGammaList','Active',-1);return 1"
                  ImageGammaPO.CloseFun="
                        v.0=0.45455;v.1=0.35;v.2=0.55;
                        a=xget('ImageGammaList','Active');
                        call set('IMAGE_GAMMA','contents',v.a)"

             gamma.2=VSpace()

            AlphaMode.Frame="Group"
            AlphaMode.FrameTitle="Alpha Mode"
            AlphaMode.Background="GroupBack"
            ALPHA_MODE.CycleChain=1
           png.1=MakeObj("AlphaMode","VCenter",,
                    MakeObj(,"VCenter",,
                        MakeObj(,"HCenter",,
                            MakeObj(,"HGroup",,
                                Label("E_nable"),,
                                Checkmark("ALPHA_MODE",,'n')))))

         hpager.3="tiff"
          tiff.Class="Group"
           tiff.0="fax"
            fax.Class="Group"
            fax.Frame="Group"
            fax.FrameTitle="Fax correction"
            fax.Background="GroupBack"
             fax.0=VSpace()
             fax.1="fax1"
              fax1.Class="group"
              fax1.Columns=2
               fax1.0=Label("Sc_aling")
                FAX_SCALING.CycleChain=1
               fax1.1=MakeObj("FAX_SCALING","Cycle","Full|Half|Quarter",'a')
               fax1.2=Label("_Expand")
                FAX_EXPAND.CycleChain=1
               fax1.3=MakeObj(,"HLeft",Checkmark("FAX_EXPAND",,'e'))
             fax.2=VSpace()

         hpager.4="bpm"
          bpm.Class="Group"
          bpm.Background="GroupBack"
            bmpt.SetVMax=0
           bpm.0=text("bmpt","No options for BMP","none","none")

         hpager.5="psd"
          psd.Class="Group"
          psd.Background="GroupBack"
            psdt.SetVMax=0
           psd.0=text("psdt","No options for PSD","none","none")

      mgroup.1=Text("info")

      mgroup.2="bg"
       bg.Class="group"
       bg.Horiz=1
       bg.SameSize=1
         save.CycleChain=1
        bg.0=button("save","_Save")
        bg.1=HSpace()
         use.CycleChain=1
        bg.2=button("use","_Use")
        bg.3=HSpace()
         test.CycleChain=1
        bg.4=button("test","_Test")
        bg.5=HSpace()
         cancel.CycleChain=1
        bg.6=button("cancel","_Cancel")

    if NewObj("Application","app")>0 then exit

    call set("hlister","Active",0)

    call notify("mwin","CloseRequest",1,"app","ReturnID","quit")

    call notify("mabout","MenuTrigger","Everytime","app","about","mwin")
    call notify("maboutrxmui","MenuTrigger","Everytime","app","AboutRxMUI","mwin")
    call notify("maboutmui","MenuTrigger","Everytime","app","AboutMUI","mwin")
    call notify("mhide","MenuTrigger","Everytime","app","set","iconified",1)
    call notify("mquit","MenuTrigger","Everytime","app","ReturnID","quit")
    call notify("mdefault","MenuTrigger","Everytime","app","return","call DefaultConfig()")
    call notify("mlast","MenuTrigger","Everytime","app","return","call RestoreConfig(1)")
    call notify("mrestore","MenuTrigger","Everytime","app","return","call RestoreConfig(0)")
    call notify("mmui","MenuTrigger","Everytime","app","OpenConfigWindow")

    call notify("hlister","Active","Everytime","hpager","set","activepage","triggervalue")

    call notify("DITHER_OVERRIDE","Active","Everytime","DITHER_QUALITY","set","Disabled",0)
    call notify("DITHER_OVERRIDE","Active",0,"DITHER_QUALITY","set","Disabled",1)
    call notify("DITHER_OVERRIDE","Active","Everytime","DITHER_DEPTH","set","Disabled",0)
    call notify("DITHER_OVERRIDE","Active",0,"DITHER_DEPTH","set","Disabled",1)

    call notify("PENS_OVERRIDE","Active","Everytime","PENS_QUALITY","set","Disabled",0)
    call notify("PENS_OVERRIDE","Active",0,"PENS_QUALITY","set","Disabled",1)

    call notify("OUTPUT_MODE","Active","Everytime","crg","set","Disabled",0)
    call notify("OUTPUT_MODE","Active",0,"crg","set","Disabled",1)

    call notify("DITHER","Active","Everytime","QUANTIZATION","set","Disabled",0)
    call notify("DITHER","Active",1,"QUANTIZATION","set","Disabled",1)

    call notify("GAMMA_CORRECTION","Selected","Everytime","GammaCorrection","set","Disabled","NotTriggerValue")
    call Notify("ScreenGammaLV","DoubleClick","EveryTime","ScreenGammaPO","Close",1)
    call Notify("ImageGammaLV","DoubleClick","EveryTime","ImageGammaPO","Close",1)

    call notify("save","Pressed",0,"app","return","call SaveConfigExit(1)")
    call notify("use","Pressed",0,"app","return","call SaveConfigExit(0)")
    call notify("test","Pressed",0,"app","return","call TestConfig()")
    call notify("cancel","Pressed",0,"app","returnid","quit")

    call set("mwin","defaultobject","hlister")

    call info("Welcome to WarpDTPrefs!")

    set.0="mwin"; set.0.attr="open";  set.0.value=1
    set.1="app";  set.1.attr="sleep"; set.1.value=1
    call MultiSetAttr("set")

    /* Globals */
    global.gad.0="DITHER_OVERRIDE" ;  global.gad.0.attr="Active"
    global.gad.1="DITHER_QUALITY"  ;  global.gad.1.attr="Active"
    global.gad.2="DITHER_DEPTH"    ;  global.gad.2.attr="Value"
    global.gad.3="PENS_OVERRIDE"   ;  global.gad.3.attr="Active"
    global.gad.4="PENS_QUALITY"    ;  global.gad.4.attr="Active"

    /* JPEG */
    global.gad.5="OUTPUT_MODE"     ;  global.gad.5.attr="Active"
    global.gad.6="DCT_METHOD"      ;  global.gad.6.attr="Active"
    global.gad.7="FANCY_UPSAMPLING";  global.gad.7.attr="Selected"
    global.gad.8="DITHER"          ;  global.gad.8.attr="Active"
    global.gad.9="QUANTIZATION"    ;  global.gad.9.attr="Active"
    global.gad.10="NUM_COLOURS"    ;  global.gad.10.attr="Value"

    /* PNG */
    global.gad.11="GAMMA_CORRECTION"; global.gad.11.attr="Selected"
    global.gad.12="SCREEN_GAMMA";     global.gad.12.attr="Contents"
    global.gad.13="IMAGE_GAMMA";      global.gad.13.attr="Contents"
    global.gad.14="ALPHA_MODE";       global.gad.14.attr="Selected"

    /* TIFF */
    global.gad.15="FAX_SCALING";      global.gad.15.attr="Active"
    global.gad.16="FAX_EXPAND";       global.gad.16.attr="Selected"

    call ReadConfigAll(0)
    call ConfigToGadgets("GLOBAL.PREFS")

    call set("app","sleep",0)
    return
/***********************************************************************/
info: procedure expose global.
parse arg msg,ntsave
    if msg="" then msg=global.last
    else if ntsave~=1 then global.last=msg
    call set("info","contents",msg)
    return
/***********************************************************************/
ConfigToGadgets: procedure expose global.
    /* Globals */
    global.gad.0.value=global.prefs.DITHER_OVERRIDE
    global.gad.1.value=global.prefs.DITHER_QUALITY
    global.gad.2.value=global.prefs.DITHER_DEPTH
    global.gad.3.value=global.prefs.PENS_OVERRIDE
    global.gad.4.value=global.prefs.PENS_QUALITY

    /* JPEG */
    global.gad.5.value=global.prefs.OUTPUT_MODE
    global.gad.6.value=global.prefs.DCT_METHOD
    global.gad.7.value=global.prefs.FANCY_UPSAMPLING
    global.gad.8.value=global.prefs.DITHER
    global.gad.9.value=global.prefs.QUANTIZATION
    global.gad.10.value=global.prefs.NUM_COLOURS

    /* PNG */
    global.gad.11.value=global.prefs.GAMMA_CORRECTION
    global.gad.12.value=global.prefs.SCREEN_GAMMA
    global.gad.13.value=global.prefs.IMAGE_GAMMA
    global.gad.14.value=global.prefs.ALPHA_MODE

    /* TIFF */
    global.gad.15.value=global.prefs.FAX_SCALING
    global.gad.16.value=global.prefs.FAX_EXPAND

    call MultiSetAttr("global.gad")
    return
/***************************************************************************/
GadgetsToConfig: procedure expose global.
parse arg from
    call MultiGetAttr("global.gad")

    /* Globals */
    global.prefs.DITHER_OVERRIDE  = global.gad.0.value
    global.prefs.DITHER_QUALITY   = global.gad.1.value
    global.prefs.DITHER_DEPTH     = global.gad.2.value
    global.prefs.PENS_OVERRIDE    = global.gad.3.value
    global.prefs.PENS_QUALITY     = global.gad.4.value

    /* JPEG */
    global.prefs.OUTPUT_MODE      = global.gad.5.value
    global.prefs.DCT_METHOD       = global.gad.6.value
    global.prefs.FANCY_UPSAMPLING = global.gad.7.value
    global.prefs.DITHER           = global.gad.8.value
    global.prefs.QUANTIZATION     = global.gad.9.value
    global.prefs.NUM_COLOURS      = global.gad.10.value

    /* PNG */
    global.prefs.GAMMA_CORRECTION = global.gad.11.value
    global.prefs.SCREEN_GAMMA     = global.gad.12.value
    global.prefs.IMAGE_GAMMA      = global.gad.13.value
    global.prefs.ALPHA_MODE       = global.gad.14.value

    /* TIFF */
    global.prefs.FAX_SCALING      = global.gad.15.value
    global.prefs.FAX_EXPAND       = global.gad.16.value

    return
/***************************************************************************/
ConfigToDefaults: procedure expose global.
    /* Globals */
    global.prefs.DITHER_OVERRIDE    = 0
    global.prefs.DITHER_QUALITY     = 2
    global.prefs.DITHER_DEPTH       = 8
    global.prefs.PENS_OVERRIDE      = 0
    global.prefs.PENS_QUALITY       = 1

    /* JPEG */
    global.prefs.OUTPUT_MODE        = 0
    global.prefs.DCT_METHOD         = 1
    global.prefs.FANCY_UPSAMPLING   = 0
    global.prefs.DITHER             = 2
    global.prefs.QUANTIZATION       = 1
    global.prefs.NUM_COLOURS        = 256

    /* PNG */
    global.prefs.GAMMA_CORRECTION   = 1
    global.prefs.SCREEN_GAMMA       = 2.2
    global.prefs.IMAGE_GAMMA        = 0.45455
    global.prefs.ALPHA_MODE         = 1

    /* TIFF */
    global.prefs.FAX_SCALING        = 0
    global.prefs.FAX_EXPAND         = 0
    return
/**************************************************************************/
ReadConfigAll: procedure expose global.
parse arg saved
    call set("app","sleep",1)
    call info("Reading preferences...",1)
    call ConfigToDefaults()

    call ReadConfig(saved,"DT")
    call ReadConfig(saved,"JPEG")
    call ReadConfig(saved,"PNG")
    call ReadConfig(saved,"TIFF")
    call ReadConfig(saved,"BMP")
    call ReadConfig(saved,"PSD")

    call CopyConfig("GLOBAL.PREFS","GLOBAL.BACKPREFS")
    call info("")
    call set("app","sleep",0)

    return
/**************************************************************************/
ReadConfig: procedure expose global.
parse arg saved,what

    select
        when what="DT"   then file="WarpDT.prefs"
        when what="JPEG" then file="WarpJPEG.prefs"
        when what="PNG"  then file="WarpPNG.prefs"
        when what="TIFF" then file="WarpTIFF.prefs"
        when what="BMP"  then file="WarpBMP.prefs"
        when what="PSD"  then file="WarpPNG.prefs"
    end

    if saved then file=AddPart("ENVARC:Datatypes",file)
    else file=AddPart("ENV:Datatypes",file)

    conf=GetVar(file,"GLOBAL BINARY")

    do while conf~=""
        parse upper var conf key "=" value "A"x conf
        select

            /* Globals */
            when what="DT" & key="DITHER_OVERRIDE" then do
                p=find("NOTHING DEFAULTS APPS EVERYTHING",value)
                if p>0 then global.prefs.DITHER_OVERRIDE=p-1
            end

            when what="DT" & key="DITHER_QUALITY" then do
                p=find("POOR GOOD BEST",value)
                global.prefs.DITHER_QUALITY=p-1
            end

            when what="DT" & key="DITHER_DEPTH" then
                if Datatype(value,"n") then do
                    if value>24 then value=24
                    else if value<1 then value=1
                    global.prefs.DITHER_DEPTH=value
                end

            when what="DT" & key="PENS_OVERRIDE" then do
                p=find("NOTHING DEFAULTS APPS EVERYTHING",value)
                if p>0 then global.prefs.PENS_OVERRIDE=p-1
            end

            when what="DT" & key="PENS_QUALITY" then do
                p=find("POOR GOOD BEST",value)
                if p>0 then global.prefs.PENS_QUALITY=p-1
            end

            /* JPEG */
            when what="JPEG" & key="OUTPUT_MODE" then do
                p=find("FULL REDUCED GREY",value)
                if p>0 then global.prefs.OUTPUT_MODE=p-1
            end

            when what="JPEG" & key="DCT_METHOD" then do
                p=find("FAST SLOW",value)
                if p>0 then global.prefs.DCT_METHOD=p-1
            end

            when what="JPEG" & key="FANCY_UPSAMPLING" then do
                p=find("OFF ON",value)
                if p>0 then global.prefs.FANCY_UPSAMPLING=p-1
            end

            when what="JPEG" & key="DITHER" then do
                p=find("NONE ORDERED FS",value)
                if p>0 then global.prefs.DITHER=p-1
            end

            when what="JPEG" & key="QUANTIZATION" then do
                p=find("POOR BEST",value)
                if p>0 then global.prefs.QUANTIZATION=p-1
            end

            when what="JPEG" & key="NUM_COLOURS" then
                if Datatype(value,"n") then do
                    if value>256 then value=256
                    else if value<8 then value=8
                    global.prefs.NUM_COLOURS=value
                end

            /* PNG */
            when what="PNG" & key="GAMMA_CORRECTION" then do
                p=find("OFF ON",value)
                if p>0 then global.prefs.GAMMA_CORRECTION=p-1
            end

            when what="PNG" & key="SCREEN_GAMMA" then do
                if DataType(value,"N") then global.prefs.SCREEN_GAMMA=value/1000000
            end

            when what="PNG" & key="IMAGE_GAMMA" then do
                if DataType(value,"N") then global.prefs.IMAGE_GAMMA=value/1000000
            end

            when what="PNG" & key="ALPHA_MODE" then do
                p=find("OFF ON",value)
                if p>0 then global.prefs.ALPHA_MODE=p-1
            end

            /* TIFF */
            when what="TIFF" & key="FAX_SCALING" then do
                p=find("FULL HALF QUARTER",value)
                if p>0 then global.prefs.FAX_SCALING=p-1
            end

            when what="TIFF" & key="FAX_EXPAND" then do
                p=find("OFF ON",value)
                if p>0 then global.prefs.FAX_EXPAND=p-1
            end

            otherwise nop
        end
    end

    return
/***********************************************************************/
SaveConfigAll: procedure expose global.
parse arg save
    call set("app","sleep",1)
    call info("Saving preferences...",1)

    call SaveConfig(save,"DT")
    call SaveConfig(save,"JPEG")
    call SaveConfig(save,"PNG")
    call SaveConfig(save,"TIFF")
    call SaveConfig(save,"BMP")
    call SaveConfig(save,"PSD")

    call CopyConfig("GLOBAL.PREFS","GLOBAL.BACKPREFS")

    global.test=0
    call info("")
    call set("app","sleep",0)

    return
/**************************************************************************/
SaveConfig: procedure expose global.
parse arg save,what

    conf=""

    /* Globals */
    conf=conf || "DITHER_OVERRIDE="  || word("nothing defaults apps everything",global.prefs.DITHER_OVERRIDE+1) || "A"x
    conf=conf || "DITHER_QUALITY="   || word("poor good best",global.prefs.DITHER_QUALITY+1) || "A"x
    conf=conf || "DITHER_DEPTH="     || global.prefs.DITHER_DEPTH  || "A"x
    conf=conf || "PENS_OVERRIDE="    || word("nothing defaults apps everything",global.prefs.PENS_OVERRIDE+1) || "A"x
    conf=conf || "PENS_QUALITY="     || word("poor good best",global.prefs.PENS_QUALITY+1)

    select
        when what="DT" then file="Datatypes/WarpDT.prefs"

        when what="JPEG" then do
            file="Datatypes/WarpJPEG.prefs"
            conf=conf || "A"x
            conf=conf || "OUTPUT_MODE="      || word("full reduced grey",global.prefs.OUTPUT_MODE+1) || "A"x
            conf=conf || "DCT_METHOD="       || word("slow fast",global.prefs.DCT_METHOD+1) || "A"x
            conf=conf || "FANCY_UPSAMPLING=" || word("off on",global.prefs.FANCY_UPSAMPLING+1) || "A"x
            conf=conf || "DITHER="           || word("none ordered fs",global.prefs.DITHER+1) || "A"x
            conf=conf || "QUANTIZATION="     || word("poor best",global.prefs.QUANTIZATION+1) || "A"x
            conf=conf || "NUM_COLOURS="      || global.prefs.NUM_COLOURS
        end

        when what="PNG" then do
            file="Datatypes/WarpPNG.prefs"
            conf=conf || "A"x
            conf=conf || "GAMMA_CORRECTION=" || word("off on",global.prefs.GAMMA_CORRECTION+1) || "A"x
            v=global.prefs.SCREEN_GAMMA
            p=pos('.',global.prefs.SCREEN_GAMMA)
            if p>0 then if pos('.',global.prefs.SCREEN_GAMMA,p+1) then v=2.2
            conf=conf || "SCREEN_GAMMA="     || trunc(v*1000000) || "A"x
            v=global.prefs.IMAGE_GAMMA
            p=pos('.',global.prefs.IMAGE_GAMMA)
            if p>0 then if pos('.',global.prefs.IMAGE_GAMMA,p+1) then v=0.45455
            conf=conf || "IMAGE_GAMMA="      || trunc(v*1000000) || "A"x
            conf=conf || "ALPHA_MODE="       || word("off on",global.prefs.ALPHA_MODE+1)
        end

        when what="TIFF" then do
            file="Datatypes/WarpTIFF.prefs"
            conf=conf || "A"x
            conf=conf || "FAX_SCALING="      || word("full half quarter",global.prefs.FAX_SCALING+1) || "A"x
            conf=conf || "FAX_EXPAND="       || word("off on",global.prefs.FAX_EXPAND+1)
        end

        when what="BMP" then file="Datatypes/WarpBMP.prefs"

        when what="PSD" then file="Datatypes/WarpPSD.prefs"
    end

    if save then call SetVar(file,conf,"SAVE GLOBAL")
    else call SetVar(file,conf)

    return
/***************************************************************************/
GetSaveConfig: procedure expose global.
parse arg save
    call GadgetsToConfig()
    call SaveConfigAll(save)
    return
/***********************************************************************/
SaveConfigExit: procedure expose global.
parse arg save
    call set("mwin","open",0)
    call GetSaveConfig(save)
    exit
/***********************************************************************/
DefaultConfig: procedure expose global.
    call ConfigToDefaults()
    call CopyConfig("GLOBAL.PREFS","GLOBAL.BACKPREFS")
    call ConfigToGadgets()
    return
/***************************************************************************/
RestoreConfig: procedure expose global.
parse arg saved
    if saved then call ReadConfigAll(1)
    else call CopyConfig("GLOBAL.BACKPREFS","GLOBAL.PREFS")
    call ConfigToGadgets()
    return
/***************************************************************************/
TestConfig: procedure expose global.
    call CopyConfig("GLOBAL.BACKPREFS","GLOBAL.TESTPREFS")
    call GetSaveConfig(0)
    global.test=1
    return
/***************************************************************************/
CopyConfig: procedure expose global.
parse arg from,to
    /* Global */
    interpret to".DITHER_OVERRIDE   = "from".DITHER_OVERRIDE"
    interpret to".DITHER_QUALITY    = "from".DITHER_QUALITY"
    interpret to".DITHER_DEPTH      = "from".DITHER_DEPTH"
    interpret to".PENS_OVERRIDE     = "from".PENS_OVERRIDE"
    interpret to".PENS_QUALITY      = "from".PENS_QUALITY"
    /* JPEG */
    interpret to".OUTPUT_MODE       = "from".OUTPUT_MODE"
    interpret to".DCT_METHOD        = "from".DCT_METHOD"
    interpret to".FANCY_UPSAMPLING  = "from".FANCY_UPSAMPLING"
    interpret to".DITHER            = "from".DITHER"
    interpret to".QUANTIZATION      = "from".QUANTIZATION"
    interpret to".NUM_COLOURS       = "from".NUM_COLOURS"
    /* PNG */
    interpret to".GAMMA_CORRECTION  = "from".GAMMA_CORRECTION"
    interpret to".SCREEN_GAMMA      = "from".SCREEN_GAMMA"
    interpret to".IMAGE_GAMMA       = "from".IMAGE_GAMMA"
    interpret to".ALPHA_MODE        = "from".ALPHA_MODE"
    /* TIFF */
    interpret to".FAX_SCALING       = "from".FAX_SCALING"
    interpret to".FAX_EXPAND        = "from".FAX_EXPAND"

    return
/***************************************************************************/
SafeExit: procedure expose global.
    if global.test then do
        call CopyConfig("GLOBAL.TESTPREFS","GLOBAL.PREFS")
        call SaveConfigAll(0)
    end
    exit
/***************************************************************************/
halt:
break_c:
    call SafeExit()
/**************************************************************************/
