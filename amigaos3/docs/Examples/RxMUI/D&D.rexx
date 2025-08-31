/* How to handle drag and drop between 2 NList */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp

/***********************************************************************/
Init:
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call SetRxMUIStack(64000) /* Big stack for NList !*/
    call RxMUIOpt("DebugMode ShowErr")
    return
/***********************************************************************/
handleApp: procedure
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if h.event="QUIT" then exit
        else interpret h.event
    end
/* never reached */
/***********************************************************************/
CreateApp: procedure
    app.Title="D&D"
    app.Version="$VER: D&D 2.1 (25.1.2002)"
    app.Copyright="Copyright © 2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="D&D example"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"

     win.Title="D&D"
     win.ID="MWIN"
     win.Contents="mgroup"

      mgroup.0="bg"
       bg.Class="Group"
       bg.Horiz=1
       bg.0=Button("remove","_Remove")
       bg.1=Button("sort","_Sort")
      mgroup.1="g"
       g.Class="Group"
       g.Horiz=1
       g.0="listview1"
        listview1.Class="NListview"
        listview1.List="list1"
         list1.Title="One|Two"
         list1.TitleClick=2
         list1.MultiSelect="Shifted"
         list1.DragSortable=1
         list1.DragType="Immediate"
         list1.Format="BAR W=-1,BAR W=-1"
         list1.MinColSortable=0
         list1.TitleMark=0
          list1.0="One|1"
          list1.1="Two|2"
          list1.2="Three|3"
       g.1="listview2"
        listview2.Class="NListview"
        listview2.List="list2"
         list2.DragSortable=1
         list2.DragType="Immediate"
         list2.Format="COL=1 BAR,COL=0 BAR"
         list2.MultiSelect="Default"
         list2.DragSortInsert=1
          list2.0="Alfonso|Ranieri"
          list2.1="Franco|Fiocca"
          list2.2="Tiziana|Spognardi"
          list2.3="Angelo|Barone"

    if NewObj("Application","app")>0 then exit

    call DandD("list2","list1","Auto")
    call DandD("list1","list2","Auto")

    call Notify("win","closerequest",1,"app","returnid","quit")

    call Notify("sort","pressed",0,"list2","sort")
    call Notify("remove","pressed",0,"list1","remove","active")

    call Notify("list1","titleclick","everytime","list1","sort2","triggervalue","add2values")
    call Notify("list1","sorttype","everytime","list1","set","titlemark","triggervalue")

    call set("win","Open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
