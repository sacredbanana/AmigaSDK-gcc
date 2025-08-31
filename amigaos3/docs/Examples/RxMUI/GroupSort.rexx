/**/

signal on halt
signal on break_c

call init
call createApp
call handleApp
/* never reached */
/***********************************************************************/
init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    return
/***********************************************************************/
handleApp: procedure
    ctrl_C=2**12
    do forever
        call newhandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise interpret h.event
        end
    end
    /* never reached */
/***********************************************************************/
createApp: procedure

    /* first of all the let's create the menu strip
     * here made only of one item "Project"
     */
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
    if res~=0 then call err(res)

    /* with one NewObj() call we create many objects */

    /* first of all the let's define the application object */
    app.Title="GroupSort"
    app.Version="$VER: GroupSort 1.0 (15.1.2002)"
    app.Copyright="Copyright 1999-2002 Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="Group sort example"
    app.Base="GROUPSORT"
    app.menustrip="strip"
    app.subwindow="win"

     /* let's define the window */
     win.ID="MAIN"
     win.Title=app.Description
     win.Contents="mgroup"

      /* let's define the window contents */
      mgroup.0="g"
       g.class="group"
       g.frame="group"
       g.background="groupback"
        do i=0 to 9
            g.i="g." || i
             g.i.class="group"
             g.i.horiz=1
              g.i.0=hspace()
              g.i.1=label("Checkmark _" || i)
              g.i.2=CheckMark("c" || i,,i)
              g.i.3=hspace()
        end

      mgroup.1="bg"
       bg.class="group"
       bg.horiz=1
         ascend.disabled=1
        bg.0=button("Ascend","_Ascend")
        bg.1=button("Descend","_Descend")

    call NewObj("Application","app")

    call Notify("mabout","menutrigger","Everytime","app","about","win")
    call Notify("maboutrxmui","menutrigger","everytime","app","aboutrxmui","win")
    call Notify("maboutmui","menutrigger","everytime","app","aboutmui","win")
    call Notify("mhide","menutrigger","everytime","app","set","iconified",1)
    call Notify("mquit","menutrigger","everytime","app","returnid","quit")
    call Notify("win","closerequest","Everytime","app","returnid","quit")
    call Notify("ascend","pressed",0,"ascend","set","disabled",1)
    call Notify("ascend","pressed",0,"descend","set","disabled",0)
    call Notify("ascend","pressed",0,"app","return","call order(0)")
    call Notify("descend","pressed",0,"descend","set","disabled",1)
    call Notify("descend","pressed",0,"ascend","set","disabled",0)
    call Notify("descend","pressed",0,"app","return","call order(1)")

    call set("win","open",1)
    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
/* Note that not all objects, like in this example
** have to be specified
*/
order: procedure
parse arg descend
    do i=0 to 9
        if descend then sort.i="g." || 9-i
        else sort.i="g." || i
    end
    call DoMethod("g","SortStem","sort")
    return
/**************************************************************************/
