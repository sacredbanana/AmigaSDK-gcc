/**/

signal on halt
signal on break_c

call Init
call InitTable
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
Init: procedure expose globals.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    l="rexxmathlib.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rxmui.library")~=0 then exit

    globals.last.m=-1
    globals.last.s=-1
    call setconfig("D",0)

    return
/***********************************************************************/
CreateApp: procedure expose globals.

    app.Title="Clock"
    app.Version="$VER: Clock 1.0 (11.6.2003)"
    app.Copyright="©2003 by alfie"
    app.Author="alfie"
    app.Description="Clock: a tablet example"
    app.Base="RXMUIEXAMPLE"

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
     strip.1="meditor"
      meditor.Title="Editor"
      meditor.class="menu"
       meditor.0=menuitem("mconfig","C\Configure...")
       meditor.1=menuitem("","BAR")
       meditor.2=menuitem("mmui","M\MUI settings...")

    app.SubWindow="win"
     win.ID="MWIN"
     win.nosize=0
     win.Contents="mgroup"
     win.Title="Clock"

      mgroup.0="tb"
       tb.class="Tablet"
       tb.Frame="String"
       tb.Font="BIG"
       tb.InnerLeft=0
       tb.InnerTop=0
       tb.InnerRight=0
       tb.InnerBottom=0

    app.SubWindow.1="pwin"
     pwin.ID="PWIN"
     pwin.ObjectID="PWIN"
     pwin.Title="Config"
     pwin.Contents="pmgroup"

      pmgroup.0="pg"
       pg.class="group"
       pg.frame="group"
       pg.background="groupback"
       pg.columns=6
        pg.0=label("_Back","free")
        pg.1="backgroundpen"
         backgroundpen.class="Poppen"
         backgroundpen.pptitle="Background pen"
         backgroundpen.ppspec=globals.backgroundpen.spec
         backgroundpen.ControlChar="b"
        pg.2=label("_Hours","free")
        pg.3="hourspen"
         hourspen.class="Poppen"
         hourspen.pptitle="Hours pen"
         hourspen.ppspec=globals.hourspen.spec
         hourspen.ControlChar="h"
        pg.4=label("_Minutes","free")
        pg.5="minutespen"
         minutespen.class="Poppen"
         minutespen.pptitle="Minutes pen"
         minutespen.ppspec=globals.minutespen.spec
         minutespen.ControlChar="m"
        pg.6=label("H_our","free")
        pg.7="hourpen"
         hourpen.class="Poppen"
         hourpen.pptitle="Hours pen"
         hourpen.ppspec=globals.hourpen.spec
         hourpen.ControlChar="o"
        pg.8=label("M_inute","free")
        pg.9="minutepen"
         minutepen.class="Poppen"
         minutepen.pptitle="Minute pen"
         minutepen.ppspec=globals.minutepen.spec
         minutepen.ControlChar="i"
        pg.10=label("_Second","free")
        pg.11="secondpen"
         secondpen.class="Poppen"
         secondpen.pptitle="Second pen"
         secondpen.ppspec=globals.secondpen.spec
         secondpen.ControlChar="s"
      pmgroup.1="sg"
       sg.class="hgroup"
       sg.frame="group"
       sg.background="groupback"
        sg.0=hspace()
        sg.1=label("_Show hours")
        sg.2=checkmark("showhours",,'s')
        sg.3=hspace()
        sg.4=label("Show minu_tes")
        sg.5=checkmark("showminutes",,'t')
        sg.6=hspace()
      pmgroup.2="bg"
       bg.class="hgroup"
        bg.0=button("defaultpens","_Defaults")
        bg.1=hspace()
        bg.2=button("alfiepens","_Alfie's")
        bg.3=hspace()
        bg.4=button("usepens","_Use")

    if NewObj("application","APP")>0 then exit

    call Notify("mabout","menutrigger","Everytime","app","about","win")
    call Notify("maboutrxmui","menutrigger","everytime","app","aboutrxmui","win")
    call Notify("maboutmui","menutrigger","everytime","app","aboutmui","win")
    call Notify("mhide","menutrigger","everytime","app","set","iconified",1)
    call Notify("mquit","menutrigger","everytime","app","returnid","quit")
    call Notify("mconfig","menutrigger","everytime","pwin","set","open",1)
    call Notify("mmui","menutrigger","everytime","app","openconfigwindow")

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")
    call Notify("win","open","everytime","app","return","call startstop(h.open)","triggerattr")
    call Notify("tb","tbredraw","everytime","app","return","call drawclock")

    call Notify("pwin","CloseRequest",1,"pwin","set","open",0)
    call Notify("defaultpens","pressed",0,"app","return","call setconfig('D',1)")
    call Notify("alfiepens","pressed",0,"app","return","call setconfig('A',1)")
    call Notify("usepens","pressed",0,"app","return","call newconfig(1)")

    call set("win","open",1)

    return
/***********************************************************************/
HandleApp: procedure expose globals.
    globals.tim=CreateTimer()
    ts=timersignal(globals.tim)
    ctrl_c=2**12
    sigs=or(ts,ctrl_c)
    call starttimer(globals.tim,0,800000)
    do forever
        call NewHandle("app","h",sigs)
        if and(h.signals,ctrl_c)>0 then signal break_c
        if and(h.signals,ts)>0 then do
            call drawtime
            call starttimer(globals.tim,0,800000)
        end
        if h.eventflag then
            select
                when h.event="QUIT" then signal break_c
                otherwise interpret h.event
            end
    end
    /* never reached */
/***********************************************************************/
inittable: procedure expose globals.

    delta=0.104471975512
    r=0

    do i=0 for 15

        c=cos(r)
        s=sin(r)

        globals.i.x=c
        globals.i.y=s

        r=r+delta
    end

    return
/**************************************************************************/
drawclock: procedure expose globals.
    call set("app","sleep",1)

    globals.width=xget("tb","tbwidth")
    globals.height=xget("tb","tbheight")

    if globals.width>globals.height then r=globals.height
    else r=globals.width

    r=trunc(r/2)-8

    globals.hc=trunc(globals.width/2)
    globals.vc=trunc(globals.height/2)

    globals.hr=r-20
    globals.mr=r-14
    globals.sr=r-10

    globals.last.hx=globals.hc
    globals.last.hy=globals.vc

    globals.last.mx=globals.hc
    globals.last.my=globals.vc

    globals.last.sx=globals.hc
    globals.last.sy=globals.vc

    call set("tb","tbapen",globals.backgroundpen.pen)
    call DoMethod("tb","tbrectfill",0,0,globals.width-1,globals.height-1)

    if (globals.showhours | globals.showminutes) & globals.width>80 & globals.height>80 then do
        do i=0 for 60
            call getcoord(i,"F")

            fx=trunc(globals.free.sx*(r+1))+globals.hc
            fy=trunc(globals.free.sy*(r+1))+globals.vc

            if i//5=0 then do
                j=i%5
                hours.j.hfx=fx
                hours.j.hfy=fy
                hours.j.htx=trunc(globals.free.sx*(r-8))+globals.hc
                hours.j.hty=trunc(globals.free.sy*(r-8))+globals.vc

            end
            else do
                if globals.showminutes then do
                    tx=trunc(globals.free.sx*(r-2))+globals.hc
                    ty=trunc(globals.free.sy*(r-2))+globals.vc
                    call DoMethod("tb","tbareadraw",fx,fy,tx,ty)
                end
            end
        end

        if globals.showminutes then do
            call set("tb","tbapen",globals.minutespen.pen)
            call DoMethod("tb","tbareaend")
        end

        if globals.showhours then do
            do i=0 for 12
                call DoMethod("tb","tbareadraw",hours.i.hfx,hours.i.hfy,hours.i.htx,hours.i.hty)
            end

            call set("tb","tbapen",globals.hourspen.pen)
            call DoMethod("tb","tbareaend")
        end
    end

    call drawtime

    call set("app","sleep",0)

    return
/**************************************************************************/
getcoord: procedure expose globals.
parse arg val,what,min

    if what="H" then do
        val=val//12
        k=(val*5)//15
        if min>=12 then k=k+1
        if min>=24 then k=k+1
        if min>=36 then k=k+1
        if min>=48 then k=k+1
    end
    else k=val//15

    x=globals.k.x
    y=globals.k.y

    if (what="H" & val>=9) | (val>=45) then do
        cx=-x
        cy=-y
    end
    else
        if (what="H" & val>=6) | (val>=30) then do
            cx=-y
            cy=x
        end
        else
            if (what="H" & val>=3) | (val>=15) then do
                cx=x
                cy=y
            end
            else do
                cx=y
                cy=-x
            end

    select
        when what="H" then do
            nhx=trunc(globals.hr*cx)+globals.hc
            nhy=trunc(globals.hr*cy)+globals.vc
            if nhx~=globals.last.hx | nhy~=globals.last.hy then do
                call domethod("tb","tbdraw",globals.hc,globals.vc,globals.last.hx,globals.last.hy)
            end

            globals.last.hx=nhx
            globals.last.hy=nhy
        end

        when what="M" then do
            globals.last.mx=trunc(globals.mr*cx)+globals.hc
            globals.last.my=trunc(globals.mr*cy)+globals.vc
        end

        when what="S" then do
            globals.last.sx=trunc(globals.sr*cx)+globals.hc
            globals.last.sy=trunc(globals.sr*cy)+globals.vc
        end

        when what="F" then do
            globals.free.sx=cx
            globals.free.sy=cy
        end
    end

    return
/**************************************************************************/
drawtime: procedure expose globals.

    parse value(time()) with h":"m":"s
    h=h+0; m=m+0; s=s+0

    call set("tb","tbapen",globals.backgroundpen.pen)
    call clear(h,m,s)

    call getcoord(h,"H",m)
    call getcoord(m,"M")
    call getcoord(s,"S")

    call set("tb","tbapen",globals.hourpen.pen)
    call domethod("tb","tbdraw",globals.hc,globals.vc,globals.last.hx,globals.last.hy)

    call set("tb","tbapen",globals.minutepen.pen)
    call domethod("tb","tbdraw",globals.hc,globals.vc,globals.last.mx,globals.last.my)

    call set("tb","tbapen",globals.secondpen.pen)
    call domethod("tb","tbdraw",globals.hc,globals.vc,globals.last.sx,globals.last.sy)

    msg="ASoft"
    call DoMethod("tb","TBTextSize",msg,"size")
    amx=(globals.width-size.width)%2
    amy=(globals.height-size.height-size.MinY)%2
    call set("tb","tbapen",globals.hourspen.pen)
    call DoMethod("tb","TBText",amx,amy,msg)

    return
/**************************************************************************/
clear: procedure expose globals.
parse arg ah,am,as

    if as~=globals.last.s then do
        globals.last.s=as
        call domethod("tb","tbdraw",globals.hc,globals.vc,globals.last.sx,globals.last.sy)
    end

    if am~=globals.last.m then do
        globals.last.m=am
        call domethod("tb","tbdraw",globals.hc,globals.vc,globals.last.mx,globals.last.my)
    end

    return
/**************************************************************************/
newpen: procedure expose globals.
parse arg what,redraw
    select
        when what="B"  then o="BACKGROUNDPEN"
        when what="HS" then o="HOURSPEN"
        when what="MS" then o="MINUTESPEN"
        when what="H"  then o="HOURPEN"
        when what="M"  then o="MINUTEPEN"
        when what="S"  then o="SECONDPEN"
    end

    s=xget(o,"PPSpec")

    call domethod("tb","TBAllocPen",s,"A")
    if rc then do
        if redraw then call domethod("tb","TBReleasePen",globals.o.pen)
        globals.o.spec=s
        globals.o.pen=A

        if redraw then call drawclock

    end

    return
/**************************************************************************/
newconfig: procedure expose globals.
parse arg redraw

    call set("app","sleep",1)
    call newpen("B",0)
    call newpen("HS",0)
    call newpen("MS",0)
    call newpen("H",0)
    call newpen("M",0)
    call newpen("S",0)

    globals.showhours=xget("showhours","selected")
    globals.showminutes=xget("showminutes","selected")

    call set("app","sleep",0)
    if redraw then call drawclock

    return
/**************************************************************************/
setconfig: procedure expose globals.
parse arg what,put

    select
        when what="D" then do
            globals.backgroundpen.spec="m1"
            globals.hourspen.spec="m5"
            globals.minutespen.spec="m5"
            globals.hourpen.spec="m5"
            globals.minutepen.spec="m6"
            globals.secondpen.spec="m0"

            globals.showhours=0
            globals.showminutes=0
        end

        when what="A" then do
            globals.backgroundpen.spec="m5"
            globals.hourspen.spec="m1"
            globals.minutespen.spec="m1"
            globals.hourpen.spec="m0"
            globals.minutepen.spec="m6"
            globals.secondpen.spec="m7"

            globals.showhours=1
            globals.showminutes=0
        end
    end

    if put then do
        call set("backgroundpen","PPSpec",globals.backgroundpen.spec)
        call set("hourspen","PPSpec",globals.hourspen.spec)
        call set("minutespen","PPSpec",globals.hourspen.spec)
        call set("hourpen","PPSpec",globals.hourpen.spec)
        call set("minutepen","PPSpec",globals.minutepen.spec)
        call set("secondpen","PPSpec",globals.secondpen.spec)

        call set("showhours","Selected",globals.showhours)
        call set("showminutes","Selected",globals.showminutes)
    end

    return
/**************************************************************************/
startstop: procedure expose globals.
parse arg start
    if start then do
        call newconfig(0)
        globals.go=1
        call starttimer(globals.tim,0,800000)
    end
    else do
        globals.go=0
        call stoptimer(globals.tim)
    end
    return
/**************************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
