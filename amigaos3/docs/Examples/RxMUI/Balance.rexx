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

    call randu(time(s)) /* init seed */

    return
/***********************************************************************/
CreateApp: procedure expose global.

    app.Title="Balancing"
    app.Version="$VER: Balancing 1.3 (25.1.2002)"
    app.Copyright="Copyright © 2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="Balancing example"
    app.Base="BALANCING"
    app.SubWindow="win"

     win.ID="MAIN"
     win.Title="Balancing"
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
        MakeObj(,"Balance"),,
        RectangleObject(200)),,
       MakeObj("Bal","Balance"),,
       MakeObj("g1","VGroup",,
        MakeObj(,"HGroup",,
         RectangleObject(1),,
         MakeObj(,"Balance"),,
         RectangleObject(1)),,
        MakeObj(,"HGroup",,
         RectangleObject(),,
         MakeObj(,"Balance"),,
         RectangleObject(),,
         MakeObj(,"Balance"),,
         RectangleObject(),,
         MakeObj(,"Balance"),,
         RectangleObject(),,
         MakeObj(,"Balance"),,
         RectangleObject()),,
        MakeObj("g2","HGroup",,
         MakeObj(,"HGroup",,
           RectangleObject(),,
           MakeObj(,"Balance"),,
           RectangleObject()),,
         MakeObj(,"Balance"),,
         MakeObj(,"HGroup",,
          RectangleObject(),,
          MakeObj(,"Balance"),,
          RectangleObject())),,
        MakeObj("g3","HGroup",,
         RectangleObject(50),,
         RectangleObject(100),,
         MakeObj(,"Balance"),,
         RectangleObject(200)),,
        MakeObj("g4","HGroup",,
         button("also","Also"),,
         MakeObj(,"Balance"),,
         button("try","Try"),,
         MakeObj(,"Balance"),,
         button("sizing","Sizing"),,
         MakeObj(,"Balance"),,
         button("with","With"),,
         MakeObj(,"Balance"),,
         button("shift","Shift")),,
        MakeObj("g5","HGroup",,
         label("Label 1:"),,
         text("data","data..."),,
         MakeObj(,"Balance"),,
         label("Label 2:"),,
         text("more","more data..."))))

    if NewObj("APPLICATION","APP")>0 then exit

    call Notify("WIN","CLOSEREQUEST",1,"APP","RETURNID","QUIT")

    call set("win","defaultobject","Bal")
    call set("win","open",1)

    return
/**************************************************************************/
handleApp: procedure
    ctrl_c=2**12
    s=0
    do forever
        call handle("app","h",s)
        do i=0 to h.num-1
            if h.i="QUIT" then exit
        end
        s=Wait(or(h.signals,ctrl_c))
        if and(s,ctrl_c)~=0 then exit
    end
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
