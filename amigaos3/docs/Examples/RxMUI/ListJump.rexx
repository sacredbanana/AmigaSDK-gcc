/* How to link 2 List */

signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
call RxMUIOpt("ShowErr DebugMode")
call SetRxMUIStack(24000)

call CreateApp
call set("lv0","active",50)
call handleApp

/***********************************************************************/
CreateApp: procedure

    do i=0 to 100
        entries.i="Entry" i
    end

    app.Title="Example"
    app.Version="$VER: Example 1.0 (20.12.00)"
    app.Copyright="©2000, alfie"
    app.Author="alfie"
    app.Description="Just a little example"
    app.Base="EXAMPLE"
    app.Subwindow="Win"

     win.ID="MAIN"
     win.Title="Example"
     win.Contents="MGROUP"

      mgroup.0="hg"
        hg.class="group"
        hg.horiz=1

         hg.0="lister"
          lister.class="listview"
          lister.FixWidthTxT="123456789012345"
          lister.list="list"
           list.frame="inputlist"
           list.active=0
            list.0="Page 1"
            list.1="Page 2"

         hg.1="pager"
          pager.class="group"
          pager.pagemode=1

           pager.0="page0"
            page0.class="group"
            page0.frame="readlist"
            page0.frametitle=list.0
             page0.0="lv0"
              lv0.class="listview"
              lv0.list="list0"
               list0.frame="inputlist"
               list0.list="entries"

           pager.1="page1"
            page1.class="group"
            page1.frame="readlist"
            page1.frametitle=list.1
             page1.0="lv1"
              lv1.class="listview"
              lv1.list="list1"
               list1.frame="inputlist"
               list1.list="entries"

      mgroup.1="bg"
       bg.class="group"
       bg.columns=5
       bg.simesize=1
        bg.0=button("Active","_Active")
        bg.1=button("Top","_Top")
        bg.2=button("Bottom","_Bottom")
        bg.3=button("up","_Up")
        bg.4=button("down","_Down")

    res=NewObj("application","app")
    if res~=0 then exit

    call Notify("win","closerequest",1,"app","returnid","quit")

    call Notify("lister","active","everytime","pager","set","activepage","triggervalue")

    call Notify("lv0","active","everytime","lv1","set","active","triggervalue")
    call Notify("lv1","active","everytime","lv0","set","active","triggervalue")

    call Notify("active","pressed",0,"lv0","jump","active")
    call Notify("active","pressed",0,"lv1","jump","active")

    call Notify("Top","pressed",0,"lv0","jump","top")
    call Notify("Top","pressed",0,"lv1","jump","top")

    call Notify("Bottom","pressed",0,"lv0","jump","Bottom")
    call Notify("Bottom","pressed",0,"lv1","jump","Bottom")

    call Notify("Up","pressed",0,"lv0","jump","Up")
    call Notify("Up","pressed",0,"lv1","jump","Up")

    call Notify("Down","pressed",0,"lv0","jump","Down")
    call Notify("Down","pressed",0,"lv1","jump","Down")

    call Notify("pager","activepage","everytime","lv0","jump","active")
    call Notify("pager","activepage","everytime","lv1","jump","active")

    call set("win","open",1)

    return
/**************************************************************************/
handleApp: procedure
    ctrl_c=2**12
    do forever
        call newhandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise say h.event
        end
    end
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

