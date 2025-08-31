/* How to handle manual drag and drop between 2 NList */


signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
call setrxmuistack(86000) /* Big stack for NList */

call CreateApp

call set("win","open",1)

call HandleApp
exit
/***********************************************************************/
handleApp: procedure
    ctrl_c=2**12
    s=0
    do forever
        ws=1
        call handle("APP","H",s)
        do i=0 to h.num-1
            select
                when h.i="QUIT" then exit
                when h.i="DROPEVENT" then do
                    call dropFun(h.i.from,h.i.to,1)
                    ws=0
                end
                otherwise say i"/"h.num-1 h.i
            end
        end
        if ~ws then iterate
        s=wait(or(h.signals,ctrl_c))
        if and(s,ctrl_c)~=0 then exit
    end
    /* never reached */
/***********************************************************************/
err: procedure expose sigl rxmuierror
parse arg res
say signl "["res"]"
    say getrxmuistring(res) "in line" sigl-1 rxmuierror
    exit
/***********************************************************************/
CreateApp: procedure
    app.Title="ManualD&D"
    app.Version="$VER: ManualD&D 1.0 (22.11.99)"
    app.Copyright="©1999, alfie"
    app.Author="alfie"
    app.Description="ManualD&D example"
    app.Base="SHOW"
    app.SubWindow="WIN"

     win.Title="ManualD&D"
     win.ScreenTitle="ManualD&D"
     win.ID="SHOW"
     win.Contents="mgroup"

      mgroup.0="bg"
       bg.class="group"
       bg.horiz=1
       bg.0 = Button("remove","_Remove")
       bg.1 = Button("sort","_Sort")
      mgroup.1="g"
       g.class="group"
       g.horiz=1
       g.0="listview1"
        listview1.class="nlistview"
        listview1.list="list1"
         list1.title="Uno|Due"
         list1.titleclick=2
         list1.multiselect="shifted"
         list1.dragsortable=1
         list1.dragtype="immediate"
         list1.Format="BAR W=-1,BAR W=-1"
         list1.mincolsortable=0
         list1.titlemark=0
          list1.0="Uno|1"
          list1.1="Due|2"
          list1.2="Tre|3"
       g.1="listview2"
        listview2.class="nlistview"
        listview2.list="list2"
         list2.dragsortable=1
         list2.dragtype="immediate"
         list2.Format="COL=1 BAR,COL=0 BAR"
         list2.multiselect="DEFAULT"
         list2.dragsortinsert=1
          list2.0="Alfonso|Ranieri"
          list2.1="Franco|Fiocca"
          list2.2="Tiziana|Spognardi"
          list2.3="Angelo|Barone"

    res=NewObj("application","app")
    if res~=0 then call err(res)

    res=DandD("list2","list1")
    if res~=0 then call err(res)

    res=DandD("list1","list2")
    if res~=0 then call err(res)

    res=Notify("sort","pressed",0,"list2","sort")
    if res~=0 then call err(res)

    res=Notify("remove","pressed",0,"list1","remove","active")
    if res~=0 then call err(res)

    res=Notify("list1","titleclick","everytime","list1","sort2","triggervalue","add2values")
    if res~=0 then call err(res)

    res=Notify("list1","sorttype","everytime","list1","set","titlemark","triggervalue")
    if res~=0 then call err(res)

    res=Notify("list1","active","everytime","app","returnid")
    if res~=0 then call err(res)

    res=Notify("win","closerequest",1,"app","returnid","quit")
    if res~=0 then call err(res)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
/* this is a drag and drop between 2 NList view */
dropFun: procedure
parse arg from,to,remove

    call set(to,"Quiet",1)

    call getattr(to,"DragSortable","ds")
    if ds then dm="sorted"
    else call getattr(to,"DropMark","dm")

    call DoMethod(from,"GetSelected","SEL")
    do i=0 to sel.num-1
        call DoMethod(from,"GetEntry",sel.i,"E")
        call DoMethod(to,"Insert",e,dm)
        if ~ds then dm=dm+1
    end

    call set(to,"Active",xget(to,"InsertPosition"))

    call set(to,"Quiet",0)

    if remove then call DoMethod(from,"remove","selected")
    call set(from,"Active","off")

    return
/**************************************************************************/
