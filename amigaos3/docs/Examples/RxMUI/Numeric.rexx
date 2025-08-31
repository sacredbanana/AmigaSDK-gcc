/**/

signal on halt
signal on break_c

call Init()
call createApp()
call handleApp()
/* never reached */
/***********************************************************************/
Init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    return
/***********************************************************************/
handleApp: procedure
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise interpret h.event
        end
    end
/* never reached */
/***********************************************************************/
err: procedure expose sigl RxMUIError
parse arg res
    msg = ProgramName()":" GetRxMUIString(res) "in line" sigl-1
    if RxMUIError~="RXMUIERROR" then msg = msg "["RxMUIError"]"
    say msg
    exit
/***********************************************************************/
createApp: procedure

    minv=0
    maxv=100
    defv=50

    app.Title="NumericExample"
    app.Version="$VER: NumericExample 1.1 (25.1.2002)"
    app.Copyright="©2002 by alfie"
    app.Author="alfie"
    app.Description="Numeric example"
    app.Base="NUMERICEXAMPLE"
    app.SubWindow="mwin"

     mwin.ID="MWIN"
     mwin.Title="Numeric example"
     mwin.Contents="mgroup"

      mgroup.0="ng"
       ng.class="group"
       ng.frame="group"
       ng.columns=2

        call child("ng",label("Levelmeter"))
        call child("ng","lg","group")
         lg.horiz=1
         lg.0="levelmeter"
          levelmeter.class="levelmeter"
          levelmeter.min=minv
          levelmeter.max=maxv
          levelmeter.value=defv
          levelmeter.label="Level"
         lg.1=hspace()

        call child("ng",label("_Knob"))
        call child("ng","kg","group")
         kg.horiz=1
         kg.0="knob"
          knob.class="knob"
          knob.controlChar="k"
          knob.min=minv
          knob.max=maxv
          knob.value=defv
          knob.default=defv
         kg.1=hspace()

        call child("ng",label("Num button"))
        call child("ng","nbg","group")
         nbg.horiz=1
         nbg.class="group"
         nbg.0="nb"
          nb.class="numericbutton"
          nb.min=minv
          nb.max=maxv
          nb.value=defv
         nbg.1=hspace()

        call child("ng",label("_Slider"))
        call child("ng","sl","slider")
         sl.controlChar="s"
         sl.min=minv
         sl.max=maxv
         sl.level=defv
         sl.format="Value: %lx"

        call child("ng",label("Gauge"))
        call child("ng","gg","group")
          gg.0="gauge"
           gauge.class="gauge"
           gauge.frame="text"
           gauge.FixHeightTxt="\n\n"
           gauge.horiz=1
           gauge.max=maxv
           gauge.current=defv
          gg.1=MakeObj(,"scale")

        call child("ng",label("Prop"))
        call child("ng","prop","prop")
           prop.frame="text"
           prop.FixHeightTxt="\n\n"
           prop.horiz=1
           prop.entries=maxv
           prop.first=0
           prop.visible=defv

      mgroup.1="bg"
       bg.class="group"
       bg.horiz=1
        bg.0=button("reset","_Reset")
        bg.1=button("inc","_Increase")
        bg.2=button("dec","_Decrease")

    call NewObj("APPLICATION","APP")

    call notify("knob","value","everytime","app","set","num1","triggervalue")

    call Notify("mwin","closerequest",1,"app","returnid","quit")

    call notify("knob","value","everytime","nb","set","value","triggervalue")
    call notify("nb","value","everytime","sl","set","value","triggervalue")
    call notify("sl","value","everytime","levelmeter","set","value","triggervalue")
    call notify("levelmeter","value","everytime","knob","set","value","triggervalue")

    call notify("knob","value","everytime","gauge","set","current","triggervalue")

    call notify("knob","value","everytime","prop","set","visible","triggervalue")

    call notify("reset","pressed",0,"knob","setdefault")
    call notify("inc","pressed",0,"knob","increase",1)
    call notify("dec","pressed",0,"knob","decrease",1)

    call set("mwin","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
