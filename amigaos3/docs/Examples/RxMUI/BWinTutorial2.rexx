/* This is the base for a never written tutorial */

signal on halt
signal on break_c

/* init our world */
call Init

/* create the application */
call createApp

/* open the window */
call set("win","open",1)

/* handle the application */
call handleApp

/* this point is never reached */
/***********************************************************************/
Init: procedure
    /* add the needed libraries */
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rxmui.library")~=0 then exit
    call ProgDir()
    return
/***********************************************************************/
handleApp: procedure
    /* this is the standard cycle to handle an application */
    ctrl_C=2**12
    do forever
    call NewHandle("app","h",ctrl_c)
    if and(h.signals,ctrl_c)>0 then exit
    if h.EventFlag then
        select
            when h.event="QUIT" then exit
            otherwise interpret h.event
        end
    end
    /* this point is never reached */
/***********************************************************************/
createApp: procedure

    /* first of all the let's define the application object */
    app.Title="Tutorial2"
    app.Version="$VER: Tutorial2 1.2 (4.11.2002)"
    app.Copyright="Copyright 1999-2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="Just a little example"
    app.Base="EXAMPLE"
    app.DiskObject="PROGDIR:tutorial2"

    /* this is the menu strip */
    app.menustrip="strip"
     strip.class="Menustrip"
     strip.0="mproject"
      mproject.Title="Project"
      mproject.class="menu"
       mproject.0=menuitem("mabout","?\About...")
       mproject.1=menuitem("maboutrxmui","X\About RxMUI...")
       mproject.2=menuitem("maboutmui","!\About MUI...")
       mproject.3=menuitem("","BAR")
       mproject.4=menuitem("mhide","H\Hide")
       mproject.5=menuitem("","BAR")
       mproject.6=menuitem("mquit","Q\Quit")

     /* this is the main (and only) window */
    app.SubWindow="win"
     win.Class="BWin"
     win.ID="MAIN"
     win.Title="A Tutorial"

      /* the window contents */
     win.Contents="mgroup"

      mgroup.0="dg"
       dg.Class="group"
       dg.Frame="group"
       dg.Background="GroupBack"
       dg.Columns=2

        dg.0=label("_Name");
         name.CycleChain=1
         name.AdvanceOnCR=1
        dg.1=String("name",'n')

        dg.2=Label("_Age");
         age.CycleChain=1
        dg.3=MakeObj(,"HLeft",MakeObj("Age","NumericButton","a",0,150,30))

        dg.4=Label("_Sex","Double")
         sex.CycleChain=1
        dg.5=MakeObj(,"HLeft",MakeObj("Sex","Radio","Male|Female","_Sex",,1))

        dg.6=Label("_Knowledge");
         known.CycleChain=1
        dg.7=MakeObj("known","Cycle","Novice|Average|Good|Expert","_Knowledge")

        dg.8=Label("Language(s)")
        dg.9="lg"
         lg.class="group"
         lg.horiz=1
           BASIC.CycleChain=1
          lg.0=Checkmark("BASIC",,'b')
          lg.1=Label("_Basic")
          lg.2=HSPace()
           ARexx.CycleChain=1
          lg.3=Checkmark("ARexx",,'x')
          lg.4=Label("ARe_xx")
           C.CycleChain=1
          lg.5=HSPace()
          lg.6=Checkmark("C",,'c')
          lg.7=Label("_C")
          lg.8=HSPace()
           ASM.CycleChain=1
          lg.9=Checkmark("ASM",,'m')
          lg.10=Label("AS_M")
          lg.11=hvspace()

      /* to use a crawling you must set its height
         as large as the first object */
      mgroup.1="cr"
       cr.class="crawling"
       cr.Frame="Text"
       cr.Background="TextBack"
       cr.FixHeightTxt="0a"x

        /* this is the first object */
        parse value(RxMUIOpt("Ask")) with . v date .
        cr.0="t0"
         t0.class="text"
         t0.contents=ParseText("%c%bRxMUI%n" v date "\n
Copyright 1999-2002 by Alfonso Ranieri")

        /* this is the second object (you could insert other) */
        cr.1="t1"
         t1.class="text"
         t1.contents=ParseText("%c\n
Please fill this registration form\n
and send to <alforan@tin.it>\n
You will receive a RxMUI ver. 3 key file!\n")

        /* repeating the first object at the end makes
           the crawling smoother */
        cr.2="t2"
         t2.class="text"
         t2.contents=t0.contents

      mgroup.2="bg"
       bg.class="group"
       bg.columns=3
         reset.CycleChain=1
        bg.0=Button("reset","_Reset Form")
         done.CycleChain=1
        bg.1=Button("done","_Done")
         cancel.CycleChain=1
        bg.2=Button("cancel","Cance_l")

    /* create all */
    call NewObj("APPLICATION","APP")

    /* window close gadget means quit */
    call Notify("win","CloseRequest",1,"app","ReturnID","QUIT")

    /* reset pressed -> reset all to defaults */
    call Notify("reset","pressed",0,"app","Return","call reset")

    /* done pressed -> print all */
    call Notify("done","pressed",0,"app","Return","call print")

    /* cancel pressed -> exit */
    call Notify("cancel","pressed",0,"app","returnid","quit")

    /* about menuitem means show the automatic about requester */
    call Notify("mabout","menutrigger","Everytime","app","about","win")

    /* aboutrxmui menuitem means show the rxmui about requester */
    call Notify("maboutrxmui","menutrigger","everytime","app","aboutrxmui","win")

    /* aboutmui menuitem means show the about MUI window */
    call Notify("maboutmui","menutrigger","everytime","app","aboutmui","win")

    /* hide menuitem means hide all windows (just one here) */
    call Notify("mhide","menutrigger","everytime","app","set","iconified",1)

    /* quit menu item means quit */
    call Notify("mquit","menutrigger","everytime","app","returnid","quit")

    /* Add user items to BWin popup menu */
    call DoMethod("win","AddUserItem","ResetForm ",1)
    call DoMethod("win","AddUserItem","Done ",2)
    call Notify("Win","UserItem",1,"app","Return","call reset")
    call Notify("Win","UserItem",2,"app","Return","call print")

    call set("win","activeobject","done")

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
reset: procedure
    set.0="name";  set.0.attr="Contents"; set.0.value=""
    set.1="age";   set.1.attr="Value";    set.1.value=30
    set.2="Sex";   set.2.attr="Active";   set.2.value=0
    set.3="known"; set.3.attr="Active";   set.3.value=0
    set.4="BASIC"; set.4.attr="Selected"; set.4.value=0
    set.5="ARexx"; set.5.attr="Selected"; set.5.value=0
    set.6="C";     set.6.attr="Selected"; set.6.value=0
    set.7="ASM";   set.7.attr="Selected"; set.7.value=0
    call MultiSetAttr("set")
    return
/**************************************************************************/
print: procedure
    get.0="name";  get.0.attr="Contents"
    get.1="age";   get.1.attr="Value"
    get.2="Sex";   get.2.attr="Active"
    get.3="known"; get.3.attr="Active"
    get.4="BASIC"; get.4.attr="Selected"
    get.5="ARexx"; get.5.attr="Selected"
    get.6="C";     get.6.attr="Selected"
    get.7="ASM";   get.7.attr="Selected"
    call MultiGetAttr("get")
    if get.0.value="" then do
        call set("win","ActiveObject","name")
        return
    end
    say " Name:" get.0.value
    say "  Age:" get.1.value
    say "  Sex:" word("Male Female",get.2.value+1)
    say "Known:" word("Novice Average Good Expert",get.3.value+1)
    say "BASIC:" word("Unknown Known ",get.4.value+1)
    say "ARexx:" word("Unknown Known ",get.5.value+1)
    say "    C:" word("Unknown Known ",get.6.value+1)
    say "  ASM:" word("Unknown Known ",get.7.value+1)

    return
/**************************************************************************/
