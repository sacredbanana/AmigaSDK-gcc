/* The power of Virtgroup */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
init: procedure
    l="rmh.library";if ~show("L",l) then;if ~AddLib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call RxMUIOpt("DebugMode ShowErr")
    return
/***********************************************************************/
MakePage1: procedure

    text1=ParseText("
%iHello User !%n\n
\n
This could be a very long text and you are looking\n
at it through a %uvirtual group%n. Please use the\n
scrollbars at the right and bottom of the group to\n
move the visible area either vertically or\n
horizontally. While holding down the small arrow\n
button between both scrollbars, the display will\n
follow your mouse moves.\n
\n
If you click somewhere into a %uvirtual group%n and\n
move the mouse across one of its borders, the group will\n
start scrolling. If you are lucky and own a middle mouse\n
button, you may also want to press it and try moving.\n
\n
When the surrounding window is big enough for the\n
complete virtual group to fit, the scrollers and\n
the move button get disabled.\n
\n
Since this %uvirtual group%n does only contain a\n
single text object, it's a rather simple example.\n
In fact, virtual groups are a lot more powerful,\n
they can contain any objects you like.\n
\n
Note to 7MHz/68000 users: Sorry if you find this\n
thingy a bit slow. Clipping in virtual groups can\n
get quite complicated. Please don't blame me,\n
blame your 'out of date' machine! :-)\n
\n
%i%cHave fun, Stefan.%n%l\n\n")

    v.frame="virtual"
    v.UseWinBorder=1
     v.0="t0"
      t0.class="text"
      t0.background="textback"
      t0.contents=text1

    res=NewObj("scrollgroup","page1","v")
    if res~=0 then call err(res)

    return "page1"
/***********************************************************************/
MakeImagesGroup: procedure
    g.frame="group"
    g.background="groupback"
    g.FrameTitle="Images"
    g.horiz=1
     g.0=hspace()
     g.1="g1"
      g1.class="group"
      g1.columns=2
        do i=0 to 9
            g1.i="im"i;
            interpret "IM"i".CLASS=image"
            interpret 'IM'i'.SPEC='i+11
        end
     g.2=hspace()
    return xnewobj("group",,"g")
/***********************************************************************/
MakeBackgroundsGroup: procedure
    gg.frame="group"
    gg.background="groupback"
    gg.FrameTitle="Backgrounds"
    gg.horiz=1
     gg.0=hspace()
     gg.1="g"
     g.class="group"
     g.columns=3
     g.0="rec0"
      rec0.class="rectangle"
      rec0.frame="text"
      rec0.background="background"
      rec0.fixwidth=32
     g.1="rec1"
      rec1.class="rectangle"
      rec1.frame="text"
      rec1.background="fill"
      rec1.fixwidth=32
     g.2="rec2"
      rec2.class="rectangle"
      rec2.frame="text"
      rec2.background="shadow"
      rec2.fixwidth=32
     g.3="rec3"
      rec3.class="rectangle"
      rec3.frame="text"
      rec3.background="shadowback"
      rec3.fixwidth=32
     g.4="rec4"
      rec4.class="rectangle"
      rec4.frame="text"
      rec4.background="shadowfill"
      rec4.fixwidth=32
     g.5="rec5"
      rec5.class="rectangle"
      rec5.frame="text"
      rec5.background="shadowshine"
      rec5.fixwidth=32
     g.6="rec6"
      rec6.class="rectangle"
      rec6.frame="text"
      rec6.background="fillback"
      rec6.fixwidth=32
     g.7="rec7"
      rec7.class="rectangle"
      rec7.frame="text"
      rec7.background="shineback"
      rec7.fixwidth=32
     g.8="rec8"
      rec8.class="rectangle"
      rec8.frame="text"
      rec8.background="fillshine"
      rec8.fixwidth=32
     gg.2=hspace()
    return XNewObj("group",,"gg")
/***********************************************************************/
MakeVirtInVirt: procedure
      sch.Frame="group"
      sch.FrameTitle="Virtual in virtual"
      sch.virtgroupcontents="vgh"
       vgh.class="virtgroup"
       vgh.frame="virtual"
       vgh.columns=2
        vgh.0=label("Name:")
        vgh.1="t0"
         t0.class="text"
         t0.frame="text"
         t0.background="textback"
         t0.contents="ppp0"
        vgh.2=label("Ontime:")
        vgh.3="t1"
         t1.class="text"
         t1.frame="text"
         t1.background="textback"
         t1.contents="02:34:56"
        vgh.4=label("Rate:")
        vgh.5="t2"
         t2.class="text"
         t2.frame="text"
         t2.background="textback"
         t2.contents="64 Kb"
        vgh.6=label("Traffic:")
        vgh.7="t3"
         t3.class="text"
         t3.frame="text"
         t3.background="textback"
         t3.contents="122,45 Mb"
    return XNewObj("scrollgroup",,"sch")
/***********************************************************************/
MakePage2: procedure

   sg.VirtgroupContents="v"
    v.class="Virtgroup"
    v.frame="virtual"

     v.0=text(,ParseText("
%cAs you can see, this virtual group contains a\n
lot of different objects. The (virtual) width\n
and height of the virtual group are automatically\n
calculated from the default width and height of\n
the virtual groups contents."))


     v.1="g0"
      g0.class="group"
      g0.horiz=1
       g0.0=MakeImagesGroup()
       g0.1=MakeBackgroundsGroup()

     v.2=MakeVirtInVirt()

    res=NewObj("scrollgroup","page2","sg")
    if res~=0 then call err(res)

    return "page2"
/***********************************************************************/
HandleApp: procedure  expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise nop
        end
    end
/***********************************************************************/
CreateApp: procedure expose global.

    app.title="VirtualDemo"
    app.version="$VER: VirtualDemo 1.1 (25.1.2002)"
    app.copyright="©2002, alfie"
    app.author="alfie"
    app.description="Show virtual groups."
    app.base="VIRTUALDEMO"
    app.SubWindow="mwin"

     mwin.title="Virtual Groups"
     mwin.ID="VIRT"
     mwin.UseRightBorderScroller=1
     mwin.UseBottomBorderScroller=1
     mwin.contents="mgroup"

      mgroup.0="dummy"
       dummy.class="group"
       dummy.0="reg"
        reg.Class="Register"
        reg.Titles="Page1|Page2"
         reg.0=MakePage1()
         reg.1=MakePage2()

    if NewObj("application","app")>0 then exit

    call Notify("mwin","CloseRequest",1,"app","ReturnID","quit")

    call set("mwin","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
