/*A clock */

signal on halt
signal on break_c
call init
call CreateApp
call handleApp
/* never reached */
/***********************************************************************/
init:procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit

    global.tim=CreateTimer()
    global.ts=TimerSignal(global.tim)

    global.DateFormats.0="%A %e %b %Y"
    global.DateFormats.1="%A %b %e %Y"
    global.DateFormats.2="%e/%m/%Y"
    global.DateFormats.3="%m/%e/%Y"

    global.TimeFormats.0="%H:%M:%S"
    global.TimeFormats.1="%I:%M:%S %p"

    global.DateFormat=0
    global.TimeFormat=0

    global.NewDateFormat=0
    global.NewTimeFormat=0

    global.ChangeDateFormat=0
    global.ChangeTimeFormat=0

    return
/***********************************************************************/
HandleApp: procedure expose global.
    ctrl_c=2**12
    sig=or(ctrl_c,global.ts)
    call StartTimer(global.tim,0,900000)
    do forever
        call NewHandle("app","h",sig)
        if and(h.signals,ctrl_c)>0 then exit
        if and(h.signals,global.ts)>0 then do
            call RefreshTime()
            call StartTimer(global.tim,0,900000)
        end
        if h.EventFlag then
            select
                when h.event="QUIT" then exit
                otherwise interpret h.event
            end
        end
    end
    /* never reached */
/***********************************************************************/
CreateApp: procedure expose global.

    app.title="Clock"
    app.version="$VER: Clock 1.1 (25.1.2002)"
    app.copyright="©2002 by alfie"
    app.author="alfie"
    app.description="Clock"
    app.base="CLOCK"
    app.SubWindow="win"

     win.ID="MAIN"
     win.title="Clock"
     win.contents="mgroup"

      call child("mgroup","vg","group")
       call child("vg","popd","popobject")
        popd.object="popdlv"
         popdlv.class="listview"
         popdlv.list="dflist"
          dflist.frame="inputlist"
           dflist.0="DayName DayNum MonthName Year"
           dflist.1="DayName Month DayNum Year"
           dflist.2="DayName/MonthName/Year"
           dflist.3="MonthName/DayName/Year"
        popd.string=text("date","")
        popd.button=MakeObj("","Imagebutton","popup")
        popd.toggle=1

       call child("vg","popt","popobject")
        popt.object="poptlv"
         poptlv.class="listview"
         poptlv.list="tflist"
          tflist.frame="inputlist"
           tflist.0="24 hours"
           tflist.1="Am/Pm"
        popt.string=text("time","")
        popt.button=MakeObj("","Imagebutton","popup")
        popt.toggle=1

    if NewObj("application","app")>0 then exit

    call notify("win","CloseRequest",1,"app","ReturnID","QUIT")

    call notify("dflist","doubleclick","everytime","popd","close",1)
    call notify("dflist","doubleclick","everytime","app","setvar","GLOBAL.CHANGEDATEFORMAT")
    call notify("dflist","active","everytime","app","setvar","GLOBAL.NEWDATEFORMAT")

    call notify("tflist","doubleclick","everytime","popt","close",1)
    call notify("tflist","doubleclick","everytime","app","setvar","GLOBAL.CHANGETIMEFORMAT")
    call notify("tflist","active","everytime","app","setvar","GLOBAL.NEWTIMEFORMAT")

    call RefreshTime()

    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
RefreshTime: procedure expose global.
    call GetDate("NOW")

    if global.ChangeTimeFormat then do
        global.ChangeTimeFormat=0
        global.TimeFormat=global.NewTimeFormat
    end
    tf=global.TimeFormat
    time=FormatDate("NOW",global.TimeFormats.tf)
    call set("time","contents",time)

    if global.ChangeDateFormat then do
        global.ChangeDateFormat=0
        global.DateFormat=global.NewDateFormat
    end
    df=global.DateFormat
    date=FormatDate("NOW",global.DateFormats.df)
    if global.OldDate~=date then do
        call set("date","contents",date)
        global.OldDate=date
    end
    return
/***************************************************************************/
