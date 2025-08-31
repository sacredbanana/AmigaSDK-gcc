/* Cute one: all is done via MakeObj() calls */

signal on halt
signal on break_c

call Init
call CreateApp
call handleApp

/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    global.left=1
    global.right=1
    return
/***********************************************************************/
CreateApp: procedure expose global.

    app.Title="Slidorama"
    app.Version="$VER: Slidorama 2.0 (26.2.2002)"
    app.Copyright="©1999-2002 alfie"
    app.Author="alfie"
    app.Description="Slidorama example"
    app.Base="EXAMPLE"
    app.menustrip=MakeObj(,"menustrip",,
                    MakeObj(,"menu","Project",,
                        menuitem("mabout","?\About..."),,
                        menuitem("maboutrxmui","X\About RxMUI..."),,
                        menuitem("maboutmui","!\About MUI..."),,
                        menuitem(,"BAR"),,
                        menuitem("mhide","H\Hide"),,
                        menuitem(,"BAR"),,
                        menuitem("mquit","Q\Quit")),,
                    MakeObj("medit","menu","Editor",,
                        MakeObj(,"MenuItem",menuitem(,"Show"),,
                            menuitem("mshowall","Show all",,"CHECKED CHEKIT TOGGLE",6),,
                            menuitem("mshowleft","Show left",,"CHEKIT TOGGLE",5),,
                            menuitem("mshowright","Show right",,"CHEKIT TOGGLE",3)),,
                        menuitem(,"BAR"),,
                        menuitem("mmui","M\MUI...")))


    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="Slidorama"

     sl.Stringify="parse arg v;if v=0 then return ' You''re kidding! '; if v<40 then return v 'points. :-(';if v<61 then return v 'points. :-|';if v=100 then return ' It''s magic! '; return v 'points. :-)'"

     win.Contents=,
        MakeObj("mgroup","VGroup",,
            MakeObj("hgroup","HGroup",,
                MakeObj("left","HFrameGroup","Knobs",,
                    MAkeObj(,"HCenter",,
                        MAkeObj(,"VCenter",,
                            MakeObj(,"ColGroup",2,,
                                Label("Volume:"),,
                                MakeObj(,"HGroup",,
                                    MakeObj(,"Knob",,0,64,64),,
                                    MakeObj(,"Knob",,0,64,64),,
                                    MakeObj(,"Knob",,0,64,64),,
                                    MakeObj(,"Knob",,0,64,64)),,
                                Label("Bass:"),,
                                MakeObj(,"HGroup",,
                                    MakeObj(,"Knob",,-100,100,0),,
                                    MakeObj(,"Knob",,-100,100,0),,
                                    MakeObj(,"Knob",,-100,100,0),,
                                    MakeObj(,"Knob",,-100,100,0)),,
                                Label("Treble:"),,
                                MakeObj(,"HGroup",,
                                    MakeObj(,"Knob",,-100,100,0),,
                                    MakeObj(,"Knob",,-100,100,0),,
                                    MakeObj(,"Knob",,-100,100,0),,
                                    MakeObj(,"Knob",,-100,100,0)))))),,
                MakeObj("right","VGroup",,
                    MakeObj(,"HFrameGroup","Levelmeter Displays",,
                        MakeObj(,"HCenter",,
                            MAkeObj(,"VCenter",,
                                MakeObj(,"HGroup",,
                                    MakeObj("lm1","Levelmeter",,,,,"Horizontal"),,
                                    MakeObj("lm2","Levelmeter",,,,,"Vertical"),,
                                    MakeObj("lm3","Levelmeter",,,,,"Total"))))),,
                    MakeObj(,"HFrameGroup","Numeric Buttons",,
                        MakeObj(,"HCenter",,
                            MakeObj(,"ColGroup",2,,
                                Label("Low:"),,
                                MakeObj(,"HGroup",,
                                    MakeObj(,"NumericButton",,,,,"%ld %%"),,
                                    MakeObj(,"NumericButton",,,,,"%ld %%"),,
                                    MakeObj(,"NumericButton",,,,,"%ld %%")),,
                                Label("Mid:"),,
                                MakeObj(,"HGroup",,
                                    MakeObj(,"NumericButton",,,,,"%ld %%"),,
                                    MakeObj(,"NumericButton",,,,,"%ld %%"),,
                                    MakeObj(,"NumericButton",,,,,"%ld %%")),,
                                Label("High:"),,
                                MakeObj(,"HGroup",,
                                    MakeObj(,"NumericButton",,,,,"%ld %%"),,
                                    MakeObj(,"NumericButton",,,,,"%ld %%"),,
                                    MakeObj(,"NumericButton",,,,,"%ld %%"))))))),,
            MakeObj(,"HGroup",,
                Label("Slidorama Rating:"),,
                MakeObj("sl","Slider")))

    res=NewObj("application","app")
    if res~=0 then exit

    call Notify("win","closerequest",1,"_app","returnid","quit")
    call Notify("mabout","menutrigger","everytime","_app","about","win")
    call Notify("maboutrxmui","menutrigger","everytime","_app","aboutrxmui","win")
    call Notify("maboutmui","menutrigger","everytime","_app","aboutmui","win")
    call Notify("mhide","menutrigger","everytime","_app","set","iconified",1)
    call Notify("mquit","menutrigger","everytime","_app","returnid","quit")
    call Notify("mshowall","checked",1,"app","return","call ShowFun('ALL')")
    call Notify("mshowleft","checked",1,"app","return","call ShowFun('LEFT')")
    call Notify("mshowright","checked",1,"app","return","call ShowFun('RIGHT')")
    call Notify("mmui","menutrigger","everytime","_app","openconfigwindow")

    call Notify("sl","value","EveryTime","lm1","set","value","triggervalue")
    call Notify("sl","value","EveryTime","lm2","set","value","triggervalue")
    call Notify("sl","value","EveryTime","lm3","set","value","triggervalue")

    call set("lm2","Reverse",1)

    call set("win","open",1)

    return
/**************************************************************************/
handleApp: procedure expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise interpret h.event
        end
    end
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
ShowFun: procedure expose global.
parse arg what
    call DoMethod("hgroup","InitChange")
    select
        when what="LEFT" then do
            if global.right then call Remove("right")
            if ~global.left then call Add("hgroup","left")
            global.left=1
            global.right=0
        end
        when what="RIGHT" then do
            if global.left then call Remove("left")
            if ~global.right then call Add("hgroup","right")
            global.left=0
            global.right=1
        end
        otherwise do
            if ~global.left then do
                call Add("hgroup","left")
                sort=1
            end
            else sort=0
            if ~global.right then call Add("hgroup","right")
            if sort then call DoMethod("hgroup","sort","left","right")
            global.left=1
            global.right=1
        end
    end
    call DoMethod("hgroup","ExitChange")
    return
/**************************************************************************/
