/* HTMLview exampe
 *
 * DemoHTMLview 1.0 (18.11.0)
 * HTML File Viewer
 * © 2000 by Robert A. Sisk
 *
 */

signal on Error
signal on Halt

call AddLib "rmh.library",0,-30
if AddLibrary("rexxsupport.library","rxmui.library")~=0 then do
    call EasyRequest "Couldn't open" result,app,"Quit"
    exit
end

appPath = ProgramName("FULL")
if RMH_AskToolType(appPath,"DebugRxMUI","key") then call RxMUIOpt "DebugMode ShowErr"
sb = upper(RMH_AskToolType(appPath,"ScrollBars"))

App.Author="Robert A. Sisk"
App.Base="DEMOHTMLVIEW"
App.Copyright="© 2000 by Robert A. Sisk"
App.Description="HTML File Viewer."
App.SubWindow="mwin"
App.SingleTask=1
App.Title="$VER: DemoHTMLview 1.0 (18.11.0)"
App.Version="DemoHTMLview"
 mwin.Contents="mgroup"
 mwin.ID="MAIN"
 mwin.Title="DemoHTMLview"
 mwin.AppWindow=1

  call child "mgroup","vg","group"
   vg.Spacing=0
    call child "vg","hg","group"
     hg.Horiz=1
     hg.Spacing=0
      call child "hg","html","HTMLview"
       html.Frame="Virtual"
       html.NTAutoLoad=1
      call child "hg","sbv","scrollbar"
       sbv.ShowMe=0
    call child "vg","sbh","scrollbar"
     sbh.Horiz=1
     sbh.ShowMe=0
  call child "mgroup","gauge","gauge"
   gauge.horiz=1
   gauge.FixHeightTxt="n"
   gauge.InfoText="Drop a HTML file over me!"
  call child "mgroup",MakeObj(,"scale")

call NewObj "Application","App"
if result~=0 then call RxMUIError result

call Notify "mwin","CloseRequest",1,"App","ReturnID","Quit"
call Notify "html","ClickedURL","EveryTime","App","Return","call GoToURL(h.clickedURL)","TriggerAttr"

call Notify "html","height","EveryTime","App","Return","call SetScrollBars()"
call Notify "html","width","EveryTime","App","Return","call SetScrollBars()"
call Notify "html","parsed","EveryTime","App","Return","call parsed(h.parsed)","triggerattr"

call Notify "html","title","everytime","gauge","set","infotext","triggervalue"

call Notify "html","virtgroupwidth","everytime","sbh","set","entries","triggervalue"
call Notify "html","virtgroupleft","everytime","sbh","set","first","triggervalue"
call Notify "html","virtgroupheight","everytime","sbv","set","entries","triggervalue"
call Notify "html","virtgrouptop","everytime","sbv","set","first","triggervalue"
call Notify "html","width","everytime","sbh","set","visible","triggervalue"
call Notify "html","height","everytime","sbv","nonotifyset","visible","triggervalue"
call Notify "sbh","first","everytime","html","set","virtgroupleft","triggervalue"
call Notify "sbv","first","everytime","html","set","virtgrouptop","triggervalue"

call AppMessage "mwin"

call set "mwin","Open",1

ctrl_c=2**12
do forever
    call NewHandle "App","h",ctrl_c
    if RMH_And(h.signals,ctrl_c)>0 then exit
    if h.EventFlag then
        select
            when h.event="QUIT" then exit
            when h.event=="SetScrollBars" then call SetScrollBars
            when h.event=="APPEVENT" then call appevent(h.name)
            otherwise interpret h.event
        end
end

AppEvent:
parse arg file
    projectFile=file
    st=StateF(projectFile)
    if word(st,1)~=="FILE" then return 0
    total=word(st,2)
    call set("gauge","max",total)
    call set("gauge","current",0)
    call GoToURL "file://"projectFile
    return

GoToURL:
    call DoMethod "html","GoURL",arg(1)
    return 1

RxMUIError:
    if symbol("RxMUIError")=="LIT" then RxMUIError="?"
    say app": Line" SigL", RxMUI" RxMUIError "error" arg(1)":" GetRxMUIString(arg(1))
    exit

Halt:
    exit

SetScrollBars:
    select
        when sb="NO" then return
        when sb="YES" then do
            rh=0
            vh=1
            rw=0
            vw=1
        end
        when sb="HORIZAUTO" then do
            rh=0
            vh=1
            call getattr("html","width","rw")
            call getattr("html","virtgroupwidth","vw")
        end
        otherwise do
            call getattr("html","width","rw")
            call getattr("html","virtgroupwidth","vw")
            call getattr("html","height","rh")
            call getattr("html","virtgroupheight","vh")
        end
    end
    call set("sbv","showme",rh<vh)
    call set("sbh","showme",rw<vw)
    return

parsed:
parse arg p
    if p=total then call SetScrollBars
    call set("gauge","current",p)
    return

