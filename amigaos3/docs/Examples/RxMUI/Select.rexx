/* NList example */

signal on halt
signal on break_c

call Init
call CreateApp
call set("mwin","open",1)
call HandleApp

/***********************************************************************/
init: procedure
    l="rmh.library";if ~show("L",l) then;if ~AddLib(l,0,-30) then exit
    if AddLibrary("rxmui.library")~=0 then exit
    call RxMUIOpt("DebugMode ShowErr")
    call SetRxMUIStack(64000)
    return
/***********************************************************************/
CreateApp: procedure

    app.Title="Listview example"
    app.Version="$VER: Listview examples 2.0 (10.3.2003)"
    app.Copyright="©2000-2003, alfie"
    app.Author="alfie"
    app.Description="Listview example"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="mwin"

     mwin.Title="Listview example"
     mwin.ScreenTitle="Listview example"
     mwin.ID="MWIN"
     mwin.Contents="mgroup"

      mgroup.0=text("info",,"none","none","1B"x"l")

      mgroup.1="lg"
       lg.class="group"
        lg.0="lview"
         lview.Class="nlistview"
         lview.List="list"
         list.Title="First|Second|Third"
          list.Format="BAR,BAR,BAR"
          list.MultiSelect="default"
          list.DragSortable=1
          list.MincolSortable=0

      mgroup.2="bg"
       bg.class="group"
       bg.Columns=3

        bg.0  = Button("selall","_Select all")
        bg.1  = Button("selnone","S_elect none")
        bg.2  = Button("seltoggle","Se_lect toggle")

        bg.3  = Button("remact","_Remove active")
        bg.4  = Button("remall","Re_move all")
        bg.5  = Button("remsel","Rem_ove selected")

        bg.6  = Button("getactive","_Get active")
        bg.7  = Button("getall","Get _all")
        bg.8  = Button("getsel","Get sele_cted")

        bg.9  = Button("defsort","_Def sort")
        bg.10 = Button("nosort","_No Sort")
        bg.11 = Button("readd","Add Entr_ies")

        bg.12 = ToggleButton("showsecret","S_how Secret")
        bg.13 = hspace()
        bg.14 = hspace()

    if NewObj("application","app")>0 then exit

    call notify("selall","pressed",0,"list","select","all","on")
    call notify("selnone","pressed",0,"list","select","all","off")
    call notify("seltoggle","pressed",0,"list","select","all","toggle")

    call notify("remall","pressed",0,"list","clear")
    call notify("remact","pressed",0,"list","remove","active")
    call notify("remsel","pressed",0,"list","remove","selected")

    call notify("getactive","pressed",0,"app","return","call GetActive")
    call notify("getall","pressed",0,"app","return","call GetAll")
    call notify("getsel","pressed",0,"app","return","call GetSel")

    call notify("readd","pressed",0,"app","return","call AddEntries")
    call Notify("defsort","pressed",0,"list","set","SortType","COL 1")
    call Notify("defsort","pressed",0,"list","set","SortType2","COL 0 REV")
    call Notify("defsort","pressed",0,"list","Sort")
    call Notify("showsecret","Selected",0,"app","return","call setformat('BAR,BAR')")
    call Notify("showsecret","Selected",1,"app","return","call setformat('BAR,BAR,BAR')")

    call Notify("nosort","pressed",0,"list","set","SortType","off")
    call Notify("nosort","pressed",0,"list","set","SortType2","off")

    call Notify("list","TitleClick","EveryTime","list","Sort3","TriggerValue","Add2Values","Both");
    call Notify("list","TitleClick2","EveryTime","list","Sort3","TriggerValue","Add2Values","Type2");
    call Notify("list","SortType","EveryTime","list","Set","TitleMark","TriggerValue");
    call Notify("list","SortType2","EveryTime","list","Set","TitleMark2","TriggerValue");

    call Notify("list","Entries","EveryTime","app","return","call info")
    call Notify("list","SelectChange","EveryTime","app","return","call info")

    call Notify("mwin","closerequest",1,"app","returnid","quit")

    call set("list","SortType","COL 1 ")
    call set("list","SortType2","COL 0 REV")

    call AddEntries

    call set("list","Format","BAR,BAR")

    return
/***********************************************************************/
HandleApp: procedure
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.Signals,2**12)~=0 then call halt
        select
            when h.Event="QUIT" then call halt
            otherwise interpret h.Event
        end
    end
end
/***********************************************************************/
AddEntries: procedure

    call DoMethod("list","insert","Emi|Ranieri|Secret 2","sorted")
    call DoMethod("list","insert","Alfonso|Ranieri|Secret 1","sorted")
    call DoMethod("list","insert","Paolo|Ranieri|Secret 3","sorted")
    call DoMethod("list","insert","Tiziana|Spognardi|Secret 4","sorted")
    return
/***********************************************************************/
GetActive: procedure

    a=xget("list","active")
    if a>-1 then do
        call DoMethod("list","GetEntry",a,"e")
        say "Active ["a"]:" e
    end
    else say "No entry active"
    say
    return
/***********************************************************************/
GetAll: procedure

    call DoMethod("list","GetEntries","A")
    if a.num>0 then
        do i=0 to a.num-1
            say i":" a.i
        end
    else say "No entries"
    say
    return
/***********************************************************************/
GetSel: procedure

    call DoMethod("list","GetSelected","a")
    if a.num>0 then
        do i=0 to a.num-1
            call DoMethod("list","GetEntry",i,"e")
            say i":" e
        end
    else say "No entries"
    say
    return
/***********************************************************************/
info: procedure
    call set("info","Contents","Entyries:"xget("list","Entries")" Selected:"xget("list","NumSelected"))
    return
/***********************************************************************/
setformat: procedure
parse arg f
    call set("list","format",f)
    return
/***********************************************************************/
halt:
break_c:
    call DoMethod("list","GetSortType","st")
    say " SortType:" st
    call DoMethod("list","GetSortType2","st2")
    say "SortType2:" st2
    exit
/***********************************************************************/
