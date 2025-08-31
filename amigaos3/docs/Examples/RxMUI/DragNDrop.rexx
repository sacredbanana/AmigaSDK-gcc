/* How to handle different types of Drag and Drop between Lists */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp

/***********************************************************************/
Init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call RxMUIOpt("DebugMode ShowErr")
    return
/***********************************************************************/
CreateApp: procedure

    strip.0="mproject"
     mproject.Title="Project"
     mproject.class="menu"
      mproject.0=menuitem("mabout","About...","?")
      mproject.1=menuitem("maboutrxmui","About RxMUI...")
      mproject.2=menuitem("maboutmui","About MUI...")
      mproject.3=menuitem("","BAR")
      mproject.4=menuitem("mhide","Hide","H")
      mproject.5=menuitem("","BAR")
      mproject.6=menuitem("mquit","Quit","Q")
    res=NewObj("menustrip","strip")
    if res~=0 then exit

    app.Title="DragnDrop"
    app.Version="$VER: DragnDrop 1.0 (17.12.00)"
    app.Copyright="©1999, alfie"
    app.Author="alfie"
    app.Description="DragnDrop example"
    app.Base="EXAMPLE"
    app.menustrip="strip"
    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="DragnDrop"
     win.contents="mgroup"

      mgroup.0="cg0"
       cg0.class="group"
       cg0.columns=2

        cg0.0=Text(,ParseText("%cAvailable Fields\n(alpha sorted)"),"none","none")

        cg0.1=Text(,ParseText("%cVisible Fields\n(sortable)"),"none","none")

        cg0.2="lv1"
         lv1.Class="Listview"
         lv1.DragType="Immediate"
         lv1.ControlChar="1"
         lv1.list="list1"
          list1.Frame="InputList"
          list1.ShowDropMark=0
          list1.DragSortable=1
           list1.0="Age"
           list1.1="Birthday"
           list1.2="c/o"
           list1.3="City"
           list1.4="Comment"
           list1.5="Country"
           list1.6="EMail"
           list1.7="Fax"
           list1.8="First name"
           list1.9="Job"
           list1.10="Name"
           list1.11="Phone"
           list1.12="Projects"
           list1.13="Salutation"
           list1.14="ZIP"
           list1.15="State"
           list1.16="Street"

        cg0.3="lv2"
         lv2.Class="Listview"
         lv2.DragType="Immediate"
         lv2.list="list2"
          list2.Frame="InputList"
          list2.DragSortable=1

        cg0.4=Text(,ParseText("%cListview without\nmultiple selection."))

        cg0.5=Text(,ParseText("%cListview with\nmultiple selection."))

        cg0.6="lv3"
         lv3.Class="Listview"
         lv3.DragType="Immediate"
         lv3.Dropable=0
         lv3.ControlChar=1
         lv3.list="list3"
          list3.Frame="InputList"
          list3.DragSortable=1
          list3.list="ll"
           do i=0 to 49
               ll.i="Line "i
           end

        cg0.7="lv4"
         lv4.Class="Listview"
         lv4.DragType="Immediate"
         lv4.list="list4"
         lv4.MultiSelect="Default"
          list4.Frame="InputList"
          list4.DragSortable=1
          list4.list="ll"

    res=NewObj("application","app")
    if res~=0 then exit

    call DandD("list1","list1","noself")
    call DandD("list1","list2","auto remove")
    call DandD("list2","list1","auto remove sorted")

    call Notify("WIN","CLOSEREQUEST",1,"APP","RETURNID","QUIT")
    call Notify("mabout","menutrigger","everytime","app","about","win")
    call Notify("maboutrxmui","menutrigger","everytime","app","aboutrxmui","win")
    call Notify("maboutmui","menutrigger","everytime","app","aboutmui","win")
    call Notify("mhide","menutrigger","everytime","app","set","iconified",1)
    call Notify("mquit","menutrigger","everytime","app","returnid","quit")

    call set("win","open",1)

    return
/**************************************************************************/
handleApp: procedure
    hggg=1
    ctrl_c=2**12
    do forever
        call newhandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            when h.event="DROPEVENT" then call dropFun(h.from,h.to)
            otherwise say h.event
        end
    end
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

