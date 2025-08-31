/**/

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rxmui.library")~=0 then exit
    if ~ReadArgs("URL") then do
        call PRintFault()
        exit
    end
    if parm.0.flag then global.URL=parm.0.value
    else global.URL="http://saturn.jpl.nasa.gov/multimedia/images/images.cfm?subCategoryID=10"
    call rxmuiopt("debugmode showerr")
    call setrxmuistack(64000)
    return
/***********************************************************************/
CreateApp: procedure expose global.

    app.Title="ARexx Mozilla Firefox"
    app.Version="$VER: ARexx Mozilla Firefox 1.0 (15.1.2004)"
    app.Copyright="©2004, alfie"
    app.Author="alfie"
    app.Description="ARexx Mozilla Firefox :-)"
    app.Base="MOZILLA"
    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="ARexx Mozilla Firefox :-)"
     win.UseRightBorderScroller=1
     win.UseBottomBorderScroller=1
     win.SizeRight=1
     win.Contents="mgroup"

       mgroup.0="g"
        g.class="hgroup"
         g.0=label("_URL")
         g.1=string("URL","u")

       mgroup.1="sg"
         sg.class="scrollgroup"
         sg.UseWinBorder=1
         sg.VirtGroupContents="HTML"
          HTML.class="HTMLview"
          HTML.frame="virtual"
          /*HTML.NTAutoLoad=1*/
          HTML.NoContextMenu=0

       mgroup.2="fg"
        fg.class="hgroup"
        fg.0="info"
         info.class="text"
         info.frame="text"
         info.background="textback"
         info.SetMin=0

    if NewObj("application","APP")~=0 then exit

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")
    call Notify("URL","NewContents","EveryTime","app","return","call URL(h.NewContents)","TriggerAttr")
    call Notify("HTML","CurrentURL","EveryTime","info","set","contents","TriggerValue")

    busy.weight="20"
    if NewObj("busy","busy")=0 then do
        call Notify("HTML","Busy","EveryTime","app","return","call busy(h.busy)","TriggerAttr")
        call Notify("HTML","ImagesinDecodeQueue","Everytime","app","return","call busy(h.ImagesinDecodeQueue)","TriggerAttr")
        global.busy=0
    end

    call set("HTML","agent","Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.7.5) Gecko/20041107 Firefox/1.0")
    call set("win","open",1)
    if global.URL~="" then call URL(global.URL)

    return
/***********************************************************************/
HandleApp: procedure expose global.
    do forever
        call NewHandle("APP","H",2**12)
        if and(h.signals,2**12)>0 then exit

        select
            when h.event="QUIT" then exit
            otherwise interpret h.event
        end
    end
end
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
busy: procedure expose global.
parse arg b
    call DoMethod("fg","InitChange")
    if b>0 then do
        if ~global.busy then do
            call Add("fg","busy")
            global.busy=1
        end
    end
    else do
        if global.busy then do
            call Remove("busy")
            global.busy=0
        end
    end
    call DoMethod("fg","ExitChange")
    return
/**************************************************************************/
URL: procedure expose global.
parse arg u
    if left(u,7)~="http://" then u="http://"u
    call DoMethod("HTML","GoURL",u,"")
    return
/**************************************************************************/
