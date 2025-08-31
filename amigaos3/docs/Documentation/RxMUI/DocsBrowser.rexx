/*
** RxMUI documentation browser
**/

signal on halt
signal on break_c

call Init
call HandleApp
/* never reached */
/***********************************************************************/
Init: procedure expose global.
    call StartInit()
    call StartCreateApp()
    call ReadNav("PROGDIR:navigator.html")
    call FinishInit()
    call FinishCreateApp()
    call set("mwin","Open",1)
    call AdvanceIntro("Done.")
    call set("iwin","Open",0)
    call DoMethod("iwin","Snapshot")
    call Dispose("iwin")
    return
/***********************************************************************/
StartInit: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~AddLib(l,0,-30) then exit
    if AddLibrary("rxmui.library")~=0 then exit
    call RxMUIOpt("DebugMode ShowErr")
    call pragma(w,n)
    call MacroEnv("env","PROGDIR CD")
    global.prg=env.Prg
    parse value(RxMUIOpt("Ask")) with " " global.ver " (" global.date ")"
    return
/***********************************************************************/
FinishInit: procedure expose global.

    global.history.0.target="right"
    global.history.0.pred=-1
    global.history.0.succ=-1
    global.history.current=0
    global.history.max=1

    global.Gadgets.0="imdir"; global.Gadgets.0.Attr="Contents"
    global.Gadgets.1="vm";    global.Gadgets.1.Attr="Active"
    global.Gadgets.2="bl";    global.Gadgets.2.Attr="Selected"
    global.Gadgets.3="rf";    global.Gadgets.3.Attr="Selected"
    global.Gadgets.4="si";    global.Gadgets.4.Attr="Selected"
    global.Gadgets.5="sn";    global.Gadgets.5.Attr="Selected"
    global.Gadgets.6="lpos";  global.Gadgets.6.Attr="Active"

    global.Configwin=0

    call ReadConfig()

    global.file=AddPart("file://PROGDIR:","introduction.html")
    global.history.0="introduction.html"

    return
/**************************************************************************/
ReadConfig: procedure expose global.

    call AdvanceIntro("Reading configuration...")

    global.ImagesDir="Images"
    global.BorderLess=0
    global.RaisingFrame=0
    global.SmallImages=0
    global.Sunny=0
    global.ViewMode=0
    global.LabelPosition=0

    if ReadToolTypes(global.prg,"tt") then
        do i=0 to tt.num-1
            select
                when tt.i="IMAGES" & tt.i.Active then global.ImagesDir=tt.i.Value
                when tt.i="BORDERLESS" then global.BorderLess=tt.i.Active
                when tt.i="RAISINGFRAME" then global.RaisingFrame=tt.i.Active
                when tt.i="SMALLIMAGES" then global.SmallImages=tt.i.Active
                when tt.i="SUNNY" then global.Sunny=tt.i.Active
                when tt.i="VIEWMODE" & tt.i.Active then do
                    v=find("TEXTGFX GFX TEXT",tt.i.Value)
                    if v>0 then global.ViewMode=v-1
                end
                when tt.i="LABELPOSITION" & tt.i.Active then do
                    v=find("BOTTOM TOP RIGHT LEFT",tt.i.Value)
                    if v>0 then global.LabelPosition=v-1
                end
                otherwise nop
            end
        end

    return
/**************************************************************************/
UseConfig: procedure expose global.

    call set("mwin","Sleep",1)

    call DoMethod("mgroup","InitChange")
    call Dispose("sb")

    call MultiGetAttr("global.Gadgets")

    global.ImagesDir=global.Gadgets.0.Value
    global.ViewMode=global.Gadgets.1.Value
    global.BorderLess=global.Gadgets.2.Value
    global.RaisingFrame=global.Gadgets.3.Value
    global.SmallImages=global.Gadgets.4.Value
    global.Sunny=global.Gadgets.5.Value
    global.LabelPosition=global.Gadgets.6.Value

    bar=CreateBar("sb",global.ImagesDir,global.ViewMode,global.BorderLess,global.RaisingFrame,global.SmallImages,global.Sunny,global.LabelPosition)

    call SetBarNotifies()
    call SetBarGadgets()

    call Add("mgroup",bar)
    call DoMethod("mgroup","Sort","sb","hg")
    call DoMethod("mgroup","ExitChange")

    call set("mwin","Sleep",0)

    return
/**************************************************************************/
SaveConfig: procedure expose global.
    call set("app","Sleep",1)
    call UseConfig()

    tt.0="BORDERLESS";    tt.0.Active=global.BorderLess;   tt.0.Key=1
    tt.1="RAISINGFRAME";  tt.1.Active=global.RaisingFrame; tt.1.Key=1
    tt.2="SMALLIMAGES";   tt.2.Active=global.SmallImages;  tt.2.Key=1
    tt.3="SUNNY";         tt.3.Active=global.Sunny;        tt.3.Key=1
    tt.4="VIEWMODE";      tt.4.Value=word("TEXTGFX GFX TEXT",global.ViewMode+1)
    tt.5="LABELPOSITION"; tt.5.Value=word("BOTTOM TOP RIGHT LEFT",global.LabelPosition+1)
    tt.6="IMAGES";        tt.6.Value=global.ImagesDir
    tt.7="NOREPORT";      tt.7.Active=1;                   tt.7.Key=1

    call WriteToolTypes(global.prg,"tt")

    call set("app","Sleep",0)
    return
/**************************************************************************/
StartCreateApp: procedure expose global.

    app.Title="RxMUI docs browser"
    app.Version="$" || "VER:" global.prg "31.4 (22.12.2002)"
    app.Copyright="Copyright 1999-2002 Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="RxMUI documentation browser."
    app.Base=upper(global.prg)
    app.DiskObject="docs"
    app.MenuStrip="strip"
     strip.class="Menustrip"
    app.SubWindow="iwin"
     iwin.Class="BWin"
     iwin.NoSize=1
     iwin.NoDragBar=1
     iwin.Activate=0
     iwin.Background="TextBack"
     iwin.LeftEdge=-1
     iwin.TopEdge=-1
     iwin.BWinInnerLeft=4
     iwin.BWinInnerTop=4
     iwin.BWinInnerRight=4
     iwin.BWinInnerBottom=4
     iwin.Contents="igroup"
       igroup.0="ititle"
        ititle.Class="text"
        ititle.Font="Big"
        ititle.Contents="     "ParseText("%c%bRxMUI") global.ver "Documentation     "
       igroup.1=hbar()
       igroup.2=vspace(2)
       igroup.3=text("intro","Welcome","none","none")

    if NewObj("application","app")>0 then call Failure("Can't create Application")

    call set("iwin","open",1)
    return
/**************************************************************************/
FinishCreateApp: procedure expose global.

    call AdvanceIntro("Creating main window...")

    mproject.Title="Project"
     mproject.0=MenuItem("maboutrxmui","?\About RxMUI...")
     mproject.1=MenuItem("maboutmui","!\About MUI...")
     mproject.2=MenuItem("","BAR")
     mproject.3=MenuItem("mhide","H\Hide")
     mproject.4=MenuItem("","BAR")
     mproject.5=MenuItem("mquit","Q\Quit")
    if NewObj("Menu","mproject")>0 then call Failure("Can't create menus")

    meditor.Title="Editor"
     meditor.0=MenuItem("msearch","G\Search...")
    if NewObj("Menu","meditor")>0 then call Failure("Can't create menus")

    mprefs.Title="Preferences"
     mprefs.0=MenuItem("mfull","F\Full screen",,"CHEKIT TOGGLE")
     mprefs.1=MenuItem("mdocs","D\Preferences...")
     mprefs.2=MenuItem("","BAR")
     mprefs.3=MenuItem("mmui","M\MUI Settings...")
    if NewObj("Menu","mprefs")>0 then call Failure("Can't create menus")

    call Add("strip","mprefs")
    call Add("strip","meditor")
    call Add("strip","mproject")

    mHContext.0="mhc"
     mhc.Title="RxMUI" global.ver
     mhc.Class="menu"
     do i=0 to global.href.num-1
         mhc.i=MenuItem("mhc."i,global.href.i.name)
     end
    if NewObj("menustrip","mHContext")>0 then call Failure("Can't create menus")

     mwin.ID="MWIN"
     mwin.Title="RxMUI DocsBrowser"
     mwin.UseBottomBorderScroller=1
     mwin.UseRightBorderScroller=1
     mwin.Contents="mgroup"

      mgroup.0=CreateBar("sb",global.ImagesDir,global.ViewMode,global.BorderLess,global.RaisingFrame,global.SmallImages,global.Sunny,global.LabelPosition)

      mgroup.1="hg"
       hg.Class="HGroup"
       hg.HorizSpacing=1
       hg.Frame="Virtual"
        hg.0="navg"
         navg.Class="group"
         navg.Spacing=0
         navg.Weight=20
          navg.0="sg"
           sg.Class="group"
           sg.Spacing=0
            sg.0="sgg"
             sgg.Class="HGroup"
             sgg.Spacing=0
              sgg.0="htmlNav"
               htmlNav.Class="HTMLview"
               htmlNav.NoContextMenu=1
               htmlNav.NTAutoLoad=1
              sgg.1="sbv"
               sbv.Class="Scrollbar"
               sbv.ShowMe=0
            sg.1="sbh"
             sbh.Class="Scrollbar"
             sbh.ShowMe=0
             sbh.Horiz=1
        hg.1=MakeObj("hgbar","Balance")
        hg.2="doc"
         doc.Class="scrollgroup"
         doc.UseWinBorder=1
         doc.virtgroupcontents="html"
          html.Class="HTMLview"
          html.NoContextMenu=1
          html.NTAutoLoad=1
          html.VLink="global.history"

    if NewObj("Window","mwin")>0 then call Failure("Can't create main window")

    call Add("app","mwin")

    swin.ID="SWIN"
    swin.Title="Search window"
    swin.Contents="msgroup"
     msgroup.0="ssg0"
      ssg0.Class="HGroup"
       ssg0.0=Label("Searc_h")
       ssg0.1=String("search","h")
     msgroup.1="ssg1"
       ssg.1="ssg1"
        ssg1.Class="HGroup"
         ssg1.0=Button("pred","_Pred")
         ssg1.1=HSpace()
         ssg1.2=Button("succ","_Succ")

    if NewObj("window","swin")>0 then call Failure("Can't create search window")

    call Add("app","swin")

    call AdvanceIntro("Setting up ...")

    call Notify("mwin","CloseRequest",1,"app","ReturnID","quit")
    call Notify("swin","CloseRequest",1,"swin","set","open",0)

    call Notify("mwin","InputEvent","ramiga b","app","Return","call GoURL('BACK')")
    call Notify("mwin","InputEvent","ramiga n","app","Return","call GoURL('FORWARD')")
    call Notify("mwin","InputEvent","ramiga r","html","Reload")

    call Notify("maboutrxmui","MenuTrigger","Everytime","app","AboutRXMUI","mwin")
    call Notify("maboutmui","MenuTrigger","Everytime","app","AboutMUI","mwin")
    call Notify("mhide","MenuTrigger","Everytime","app","Set","Iconified",1)
    call Notify("mquit","MenuTrigger","Everytime","app","ReturnID","QUIT")
    call Notify("msearch","MenuTrigger","Everytime","swin","set","open",1)

    call Notify("mfull","Checked","Everytime","app","return","call FullScreen(h.checked)","TriggerAttr")

    call Notify("mdocs","MenuTrigger","Everytime","app","Return","call OpenConfigWindow()")
    call Notify("mmui","MenuTrigger","Everytime","app","OpenConfigWindow")

    call SetBarNotifies()

    call Notify("html","Title","Everytime","app","Return","call ChangeTitle(h.Title)","TriggerAttr")
    call Notify("html","ClickedURL","Everytime","app","Return","call NewURLFun(h.clickedurl)","triggerattr")

    call Notify("search","NewContents","Everytime","app","Return","call SearchFun('SEARCHTOP ')")
    call Notify("pred","Pressed",0,"app","Return","call SearchFun('SEARCHBACK')")
    call Notify("succ","Pressed",0,"app","Return","call SearchFun('SEARCHNEXT')")

    call Notify("htmlnav","virtgroupwidth","everytime","sbh","set","entries","triggervalue")
    call Notify("htmlnav","virtgroupleft","everytime","sbh","set","first","triggervalue")
    call Notify("htmlnav","virtgroupheight","everytime","sbv","set","entries","triggervalue")
    call Notify("htmlnav","virtgrouptop","everytime","sbv","set","first","triggervalue")
    call Notify("htmlnav","width","everytime","sbh","set","visible","triggervalue")
    call Notify("htmlnav","height","everytime","sbv","set","visible","triggervalue")
    call Notify("htmlnav","prophdeltafactor","everytime","sbh","set","deltafactor","Triggervalue")
    call Notify("htmlnav","propvdeltafactor","everytime","sbv","set","deltafactor","Triggervalue")
    call Notify("htmlnav","height","EveryTime","App","Return","call SetScrollBars")
    call Notify("htmlnav","width","EveryTime","App","Return","call SetScrollBars")
    call Notify("sbh","first","everytime","htmlnav","set","virtgroupleft","triggervalue")
    call Notify("sbv","first","everytime","htmlnav","set","virtgrouptop","triggervalue")

    call set("mwin","DefaultObject","html")

    call DoMethod("html","GoURL",global.file)

    call SetBarGadgets()

    call Notify("htmlNav","ClickedURL","Everytime","app","Return","call NewURLFun(filepart(h.clickedurl))","triggerattr")

    call DoMethod("htmlNav","GoURL","file://PROGDIR:navigator.html")

    do i=0 to global.href.num-1
        call Notify("mhc."i,"menutrigger","Everytime","app","Return","call NewURLFun("global.href.i")")
    end

    call set("mgroup","ContextMenu","mHContext")

    return
/***********************************************************************/
SearchFun: procedure expose global.
parse arg mode
    call GetAttr("search","Contents","string")
    if string~="" then call DoMethod("html","search",string,right(mode,4))
    return
/**************************************************************************/
CreateBar: procedure expose global.
parse arg name,dir,vm,bl,rf,si,su,lpos

    bar.Horiz=1
    bar.SameHeight=1
    bar.SameWidth=1

    bar.ViewMode=vm
    bar.Borderless=bl
    bar.RaisingFrame=rf
    bar.SmallImages=si
    bar.Sunny=su
    bar.LabelPosition=lpos
    bar.BarSpacer=1
    bar.StripUnderscore=1
    bar.EnableUnderscore=1
    bar.Layout="Left"

    bar.0.Img=AddPart(dir,"Back")
    bar.0.Text="_Back"

    bar.1.Img=AddPart(dir,"Forward")
    bar.1.Text="_Forward"

    bar.2.Img=AddPart(dir,"Reload")
    bar.2.Text="_Reload"

    bar.3.Img=AddPart(dir,"Stop")
    bar.3.Text="_Stop"

    if NewObj("speedbar",name,"bar")>0 then call Failure("Can't create Speedbar")

    return name
/**************************************************************************/
SetBarNotifies: procedure expose global.
    call SBNotify("sb",0,"Pressed",0,"app","Return","call GoURL('BACK')")
    call SBNotify("sb",1,"Pressed",0,"app","Return","call GoURL('FORWARD')")
    call SBNotify("sb",2,"Pressed",0,"html","Reload")
    call SBNotify("sb",3,"Pressed",0,"html","Abort")
    return
/**************************************************************************/
SetBarGadgets: procedure expose global.
    c=global.history.current
    call DoMethod("sb","sbset",0,"Disabled",global.history.c.pred==-1)
    call DoMethod("sb","sbset",1,"Disabled",global.history.c.succ==-1)
    return
/**************************************************************************/
halt:
break_c:
    call RxMUIOpt("")
    if set("iwin","Open",0)=0 then do
        call DoMethod("iwin","Snapshot")
        call Dispose("iwin")
    end
    exit
/**************************************************************************/
HandleApp: procedure expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 | h.event="QUIT" then exit
        interpret h.event
    end
    /* never reached */
/***********************************************************************/
GoURL: procedure expose global.
parse arg method,nurl,ntarget

    select
        when upper(left(nurl,12))="AREXXSCRIPT:" then do
            parse var nurl +12 cmd
            INTERPRET cmd
            return
        end

        when (upper(left(nurl,7))="HTTP://") |,
             (upper(left(nurl,6))="FTP://") |,
             (upper(left(nurl,7))="MAILTO:") then do
            call OpenURL(nurl)
            return
        end

        otherwise
            select

                when method="NEWURL" then do
                    i=global.history.current
                    m=global.history.max

                    global.history.m=nurl
                    global.history.m.target=ntarget
                    global.history.m.pred=i
                    global.history.m.succ=-1

                    global.history.i.succ=m
                    global.history.current=m
                    global.history.max=m+1

                    call DoMethod("html","GoURL",nurl,ntarget)
                end

                when method="BACK" then do
                    i=global.history.current
                    if global.history.i.pred>-1 then do
                        i=global.history.i.pred
                        call DoMethod("html","GoURL",global.history.i,global.history.i.target)
                        global.history.current=i
                    end
                end

                when method="FORWARD" then do
                    i=global.history.current
                    if global.history.i.succ>-1 then do
                        i=global.history.i.succ
                        call DoMethod("html","GoURL",global.history.i,global.history.i.target)
                        global.history.current=i
                    end
                end
            end
    end

    call SetBarGadgets()

    return
/***********************************************************************/
NewURLFun: procedure expose global.
parse arg clicked
    i=global.history.current
    if upper(global.history.i)=upper(clicked) then return
    if left(clicked,7)~="file://" then clicked="file://"||clicked
    call GetAttr("html","target","ntarget")
    call GoURL("NEWURL",clicked,ntarget)
    return
/**************************************************************************/
OpenConfigWindow: procedure expose global.

    if ~global.ConfigWin then do

        call set("app","Sleep",1)

        cwin.ID="CWIN"
        cwin.Title=global.prg "Preferences"
        cwin.Contents="cmgroup"

         cmgroup.0="chg"
          chg.Class="HGroup"

           chg.0="lister"
            lister.Class="listview"
            lister.Weight=0
            lister.List="list"
             list.Class="listtree"
             list.Frame="inputlist"
              list.0="Bar"

           chg.1="pager"
            pager.Class="Group"
            pager.PageMode=1
            pager.Frame="readlist"

             pager.0="BarPage"
              BarPage.Class="Group"

               BarPage.0="cbg"
                cbg.Class="HGroup"
                cbg.0="CDummyBarG"
                 CDummyBarG.Class="Group"
                 CDummyBarG.Spacing=0
                  CDummyBarG.0="csb"
                   csb.Class="rectangle"
                cbg.1=HSpace()

               opt1.Class="Group"
               opt1.Columns=2
                opt1.0=Label("_Images")
                opt1.1="popd"
                 popd.Class="popasl"
                 popd.String=string("imdir",'i')
                 popd.DrawersOnly=1
                opt1.2=Label("_ViewMode")
                opt1.3=MakeObj("vm","Cycle","TextGfx|Gfx|Text","v")
                opt1.4=Label("_Label")
                opt1.5=MakeObj("lpos","Cycle","Bottom|Top|Right|Left","l")

                opt2.Class="Group"
                opt2.Columns=4
                 opt2.0=Label("B_orderLess")
                 opt2.1=CheckMark("bl",,'o')
                 opt2.2=Label("R_aisingFrame")
                 opt2.3=CheckMark("rf",,'a')
                 opt2.4=Label("S_mallImages")
                 opt2.5=CheckMark("si",,'m')
                 opt2.6=Label("Sunn_y")
                 opt2.7=CheckMark("sn",,'y')

               BarPage.1=MakeObj(,"VFrameGroup",,MakeObj(,"VGroup",VSpace(),"opt1",VSpace(),MakeObj(,"HCenter","opt2"),VSpace()))

         cmgroup.1="cbug"
          cbug.Class="HGroup"
           cbug.0=Button("csave","_Save")
           cbug.1=Button("cuse","_Use")
           cbug.2=Button("ccancel","_Cancel")

        if NewObj("window","cwin")>0 then return

        call Add("app","cwin")

        call Notify("cwin","CloseRequest",1,"cwin","Set","Open",0)
        call Notify("imdir","NewContents","Everytime","app","Return","call CBarChanged()")
        call Notify("cuse","Pressed",0,"app","Return","call UseConfig()")
        call Notify("cuse","Pressed",0,"cwin","Set","Open",0)
        call Notify("csave","Pressed",0,"app","Return","call SaveConfig()")
        call Notify("csave","Pressed",0,"cwin","Set","Open",0)
        call Notify("ccancel","Pressed",0,"cwin","Set","Open",0)

        call set("app","Sleep",0)
        call set("list","ActiveID",1)

        global.Configwin=1
    end

    global.Gadgets.0.value=global.ImagesDir
    global.Gadgets.1.value=global.ViewMode
    global.Gadgets.2.value=global.BorderLess
    global.Gadgets.3.value=global.RaisingFrame
    global.Gadgets.4.value=global.SmallImages
    global.Gadgets.5.value=global.Sunny
    global.Gadgets.6.value=global.LabelPosition
    call MultiSetAttr("global.Gadgets",1)

    call CBarChanged()
    call set("cwin","Open",1)

    return
/**************************************************************************/
SetCBarNotifies: procedure expose global.
    call Notify("vm","Active","Everytime","csb","Set","ViewMode","TriggerValue")
    call Notify("lpos","Active","Everytime","csb","Set","LabelPosition","TriggerValue")
    call Notify("bl","Selected","Everytime","csb","Set","BorderLess","TriggerValue")
    call Notify("rf","Selected","Everytime","csb","Set","RaisingFrame","TriggerValue")
    call Notify("si","Selected","Everytime","csb","Set","SmallImages","TriggerValue")
    call Notify("sn","Selected","Everytime","csb","Set","Sunny","TriggerValue")
    return
/**************************************************************************/
CBarChanged: procedure expose global.

    call set("cwin","Sleep",1)
    call DoMethod("CDummyBarG","InitChanges")
    call Dispose("csb")

    call MultiGetAttr("global.Gadgets")

    bar=CreateBar("csb",global.Gadgets.0.Value,global.Gadgets.1.Value,global.Gadgets.2.Value,global.Gadgets.3.Value,global.Gadgets.4.Value,global.Gadgets.5.Value,global.Gadgets.6.Value,0)
    call SetCBarNotifies()

    call Add("CDummyBarG",bar)
    call DoMethod("CDummyBarG","ExitChanges")
    call set("cwin","Sleep",0)

    return
/**************************************************************************/
AdvanceIntro: procedure
parse arg msg
    call set("intro","contents",msg)
    return
/**************************************************************************/
MakeHRef: procedure expose global.
parse arg name,con
    t.Contents=con
    t.InputMode="immediate"
    t.preparse=parsetext("%r")
    t.showselstate=0
    t.font="button"
    return xnewobj("text",name,"t")
/**************************************************************************/
ReadNav: procedure expose global.
parse arg file
    if ~open(in,file,r) then do
        global.href.num=0
        return
    end
    i=0
    global.maxNav=""
    global.maxNavSize=0
    do while ~eof(in)
        l=readln(in)
        if l="" then iterate
        parse var l "<a href=" h ">" n "</a>"
        if h~="" then do
            global.href.i=h
            global.href.i.name=n
            i=i+1
            s=length(n)
            if s>global.maxNavSize then do
                global.maxNav=n
                global.maxNavSize=s
            end
        end
    end
    global.href.num=i
    return
/**************************************************************************/
ChangeTitle: procedure expose global.
parse arg title
    if title~="" then title="-" title
    call set("mwin","Title","RxMUI" global.ver title)
    return
/**************************************************************************/
SetScrollBars: procedure
    call getattr("htmlnav","width","rw")
    call getattr("htmlnav","virtgroupwidth","vw")
    call getattr("htmlnav","height","rh")
    call getattr("htmlnav","virtgroupheight","vh")
    call set("sbv","showme",rh<vh)
    call set("sbh","showme",rw<vw)
    return
/**************************************************************************/
FullScreen: procedure
parse arg f
    call set("app","Sleep",1)
    call DoMethod("mgroup","InitChange")
    if f then do
        call Remove("sb")
        call Remove("navg")
        call Remove("hgbar")
    end
    else do
        call Add("hg","navg")
        call Add("hg","hgbar")
        call DoMethod("hg","sort","navg","hgbar","doc")

        call Add("mgroup","sb")
        call DoMethod("mgroup","sort","sb","hg")
    end
    call DoMethod("mgroup","ExitChange")
    call set("app","Sleep",0)
    return
/**************************************************************************/
Failure: procedure
parse arg msg
    call EasyRequest(msg)
    exit
/**************************************************************************/
/*  $VER: DocsBrowser.rexx 31.4 (22.12.2002) */
