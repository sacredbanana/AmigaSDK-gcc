/* Balancing objects example */

signal on halt
signal on break_c

call init
call CreateApp
call handleApp
/* never reached */
/***********************************************************************/
init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit

    global.background.0="BACKGROUND"
    global.background.1="SHADOW"
    global.background.2="SHINE"
    global.background.3="FILL"
    global.background.4="SHADOWBACK"
    global.background.5="SHADOWFILL"
    global.background.6="SHADOWSHINE"
    global.background.7="FILLBACK"
    global.background.8="FILLSHINE"
    global.background.9="SHINEBACK"
    global.background.10="FILLBACK2"
    global.background.11="HSHINEBACK"
    global.background.12="HSHADOWBACK"
    global.background.13="HSHINESHINE"
    global.background.14="HSHADOWSHADOW"
    global.background.14="MARKSHINE"
    global.background.15="MARKHALFSHINE"
    global.background.16="MARKBACKGROUND"

    global.idx=0

    call randu(time(s)) /* init seed */

    return
/***********************************************************************/
CreateApp: procedure expose global.

    app.Title="Balancing"
    app.Version="$VER: BetterBalancing 1.2 (5.10.2001)"
    app.Copyright="Copyright © 2001 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="BetterBalancing example"
    app.Base="BALANCING"
    app.SubWindow="win"

     win.ID="MAIN"
     win.Title="BetterBalancing"
     win.width=-250
     win.height=-250
        g0.Frame="Group"
        g0.Weight=15
        g1.Frame="group"
        g2.Frame="group"
        g3.Frame="group"
        g4.Frame="group"
        g5.Frame="group"
        g6.Frame="group"
     win.Contents=MakeObj(,"HGroup",,
       MakeObj("g0","VGroup",,
        RectangleObject(50),,
        RectangleObject(100),,
        BetterBalanceObject(),,
        RectangleObject(200)),,
       BetterBalanceObject("Bal"),,
       MakeObj("g1","VGroup",,
        MakeObj(,"HGroup",,
         RectangleObject(),,
         BetterBalanceObject(),,
         RectangleObject()),,
        MakeObj(,"HGroup",,
         RectangleObject(),,
         BetterBalanceObject(),,
         RectangleObject(),,
         BetterBalanceObject(),,
         RectangleObject(),,
         BetterBalanceObject(),,
         RectangleObject(),,
         BetterBalanceObject(),,
         RectangleObject()),,
        MakeObj("g2","HGroup",,
         MakeObj(,"HGroup",,
           RectangleObject(),,
           BetterBalanceObject(),,
           RectangleObject()),,
         BetterBalanceObject(),,
         MakeObj(,"HGroup",,
          RectangleObject(),,
          BetterBalanceObject(),,
          RectangleObject())),,
        MakeObj("g3","HGroup",,
         RectangleObject(50),,
         RectangleObject(100),,
         BetterBalanceObject(),,
         RectangleObject(200)),,
        MakeObj("g4","HGroup",,
         button("also","Also"),,
         BetterBalanceObject(),,
         button("try","Try"),,
         BetterBalanceObject(),,
         button("sizing","Sizing"),,
         BetterBalanceObject(),,
         button("with","With"),,
         BetterBalanceObject(),,
         button("shift","Shift")),,
        MakeObj("g5","HGroup",,
         label("Label 1:"),,
         text("data","data..."),,
         BetterBalanceObject(),,
         label("Label 2:"),,
         text("more","more data..."))))

    if NewObj("APPLICATION","APP")>0 then exit

    call DoMethod("app","Load","Env")

    call Notify("WIN","CLOSEREQUEST",1,"APP","RETURNID","QUIT")

    call set("win","defaultobject","Bal")
    call set("win","open",1)

    return
/**************************************************************************/
HandleApp: procedure
    do forever
        call newhandle("APP","H",2**12)
        if and(h.signals,2**12)>0 then exit
        select
            when h.event="QUIT" then do
                call DoMethod("App","Save","Env")
                exit
            end
            otherwise nop
        end
    end
    /* never reached */
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
RectangleObject: procedure expose global.
parse arg w,f

    if arg(1,'e') then rec.Weight=w
    if arg(2,'e') then rec.Frame=f
    else rec.Frame="Text"

    i=random(0,17)
    rec.Background=global.Background.i

    return XNewObj("Rectangle",,"rec")
/**************************************************************************/
BetterBalanceObject: procedure expose global.
parse arg n
    o=MakeObj(n,"BetterBalance",global.idx)
    global.idx=global.idx+1
    return o
/**************************************************************************/
