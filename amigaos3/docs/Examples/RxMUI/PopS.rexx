/* How to crate and handle a Popstring object */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
Init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addLib(l,0,-30) then exit
    if addLibrary("rxmui.library")~=0 then exit
    call RxMUIOpt("DebugMode ShowErr")
    return
/***********************************************************************/
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
    /* never reached */
/***********************************************************************/
CreateApp: procedure

    /* Application */
    app.Title="PopstringExample"
    app.Version="$VER: PopstringExample 2.0 (25.1.2002)"
    app.Copyright="Copyright 2001-2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="PopstringExample"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="mwin"

     /* Main window */
     mwin.Title="PopstringExample"
     mwin.ID="MAIN"
     mwin.Contents="mgroup"

      /* Contents of mwin */
      mgroup.0="g"
       g.Class="group"
       g.Horiz=1

        /* Popstring object */
        g.0="ps"
         ps.Class="popstring"
         ps.Toggle=1
         ps.buttoncyclechain=1

         /* As the Popstring is opening, this in-line macro is called.
            It just build a list of the public ports.
            Note that it returns 1 to tell the Popstring it is ok to go. */
         ps.OpenFun="
            call set('l','quiet',1);
            pl=show('p',,'/');
            do while pl~='';
                parse var pl p '/' pl;
                call domethod('l','insert',p,'sorted');
            end;
            call set('l','quiet',0);
            return 1"

         /* As the Popstring is closed, this in-line macro is called.
            It receives one argument: success. You have to tell the
            Popstring what it means. If success is 1, a port was
            doubleclicked, and it is set in the string. Otherwise
            nothing happens. Note that it also clears the list. */
         ps.CloseFun="
            parse arg s;
            if s then do;
                call DoMethod('l','GetEntry','active','A');
                call set('s','contents',a);
            end;
            call domethod('l','clear')"

         /* This is the String object */
          s.CycleChain=1
         ps.String=String("s")

         /* Here you should specify a Button object, but we use
            the auto popup button */
         /*bs.Weight=0
           ps.Button=Button("BS","Pop!")*/

         /* This is the Window object */
         ps.Window="pw"
          pw.Class="window"
          pw.Title="PopstringWindow"
          pw.ID="SHOW"
           pw.Contents="pwmain"
            pwmain.0="lv"
             lv.Class="Listview"
             lv.List="l"
              l.Frame="InputList"
            pwmain.1=Button("cs",'_Close')

    call NewObj("APPLICATION","APP")

    /* The Window object of the Popstring must be added
       to the application to be opened */
    call Add("app","pw")

    /* Set lv as DefaultObject for pw */
    call set("pw","DefaultObject","lv")

    call Notify("mwin","CloseRequest",1,"app","ReturnID","quit")

    /* If the Popstring-Window is closed it is a no-success event */
    call Notify("pw","CloseRequest",1,"ps","Close",0)

    /* If the Close-Button is pressed it is a no-success event */
    call Notify("cs","Pressed",0,"ps","Close",0)

    /* If an entry is doubleclicked it is a SUCCESS event */
    call Notify("l","Doubleclick","EveryTime","ps","Close",1)

    call set("mwin","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

