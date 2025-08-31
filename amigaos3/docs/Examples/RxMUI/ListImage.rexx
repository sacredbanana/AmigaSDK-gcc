/* A List with 2 columns */

signal on break_c
signal on halt

call Init
call CreateApp
call handleApp
/* never reached*/
/*******************************************************************/
Init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call ProgDir()
    call RxMUIOpt("DebugMode ShowErr")
    return
/*******************************************************************/
CreateApp: procedure

    app.Title="ListExample"
    app.Version="$VER: ListExample 1.1 (29.6.2002)"
    app.Copyright="Copyright © 2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="List Example"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"
     win.Title="List example"
     win.ID="MWIN"
     win.Contents="mgroup"
      mgroup.0="lv"
       lv.Class="Listview"
       lv.CycleChain=1
       lv.List="l"
        l.Format=","
        l.Title=ParseText("%bTitle|[Image im3]")
        l.MinLineHeight=32
        l.MinColSortable=1
         l.0="[Image im0]|Image 0"
         l.1="[Image im1]|Image 1"
         l.2="[Image im2]|Image 2"
         l.3=ParseText("%I[6:26]|Volume")
        l.Image.0="im0"
         im0.Class="picture"
         im0.Source="PROGDIR:pics/Ram"
         im0.Transparent=1
        l.Image.1="im1"
         im1.Class="picture"
         im1.Source="PROGDIR:pics/TV"
         im1.Transparent=1
        l.Image.2="im2"
         im2.Class="picture"
         im2.Source="PROGDIR:pics/Screen"
         im2.Transparent=1
        l.Image.3="im3"
         im3.Class="picture"
         im3.Source="PROGDIR:pics/Trek"
         im3.Transparent=1
      mgroup.1="gg"
       gg.Class="group"
       gg.Horiz=1
        gg.0=Label("_First col")
         sa.Reject="|"
         sa.CycleChain=1
        gg.1=String("sa","f")
         sb.Reject="|"
         sb.CycleChain=1
        gg.2=HWSpace(0)
        gg.3=Label("S_econd col")
        gg.4=String("sb","e")
      mgroup.2="g"
       g.Class="GROUP"
       g.Horiz=1
         sort.CycleChain=1
        g.0=Button("sort","_Sort")
         add.CycleChain=1
        g.1=HWSpace(0)
        g.2=Button("add","_Add")
         remove.CycleChain=1
        g.3=HWSpace(0)
        g.4=Button("remove","_Remove")

    if NewObj("application","app")>0 then exit

    call Notify("win","CloseRequest",1,"app","ReturnID","Quit")
    call Notify("sort","Pressed",0,"lv","Sort")
    call Notify("add","Pressed",0,"lv","Insert","","Bottom")
    call Notify("add","Pressed",0,"lv","Set","Active","Bottom")
    call Notify("remove","Pressed",0,"lv","Remove","Active")
    call Notify("lv","Active",-1,"sa","set","contents","")
    call Notify("lv","Active",-1,"sb","set","contents","")
    call Notify("lv","ActiveEntry0","EveryTime","sa","Set","Contents","TriggerValue")
    call Notify("lv","ActiveEntry1","EveryTime","sb","set","Contents","TriggerValue")
    call Notify("sa","NewContents","EveryTime","lv","ReplaceCol","Active",0,"TriggerValue")
    call Notify("sb","NewContents","EveryTime","lv","ReplaceCol","Active",1,"TriggerValue")

    call set("win","open",1)
    return
/*******************************************************************/
HandleApp: procedure
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise interpret h.event
        end
    end
/* never reached*/
/*******************************************************************/
break_c:
halt:
    exit
/*******************************************************************/
