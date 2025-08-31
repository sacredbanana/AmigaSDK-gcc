/* HString example */

call Init
call createApp
call handleApp()
/* never reached */
/***********************************************************************/
init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    return
/***********************************************************************/
createApp: procedure
    app.Title="HStringExample"
    app.Version="$VER: HStringExample 1.1 (6.12.2002)"
    app.Copyright="©2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="HString Example"
    app.Base="HSTRING"

    app.SubWindow="mwin"
     mwin.Title="HString Example"
     mwin.ID="MWIN"
     mwin.Contents="mgroup"

      mgroup.0="lv"
       lv.class="NListview"
       l.format="BAR,BAR,"
       lv.list="l"
        l.Input=0
        l.Format=ParseText("P=%i BAR,P=%r BAR,")
        l.DefaultObjectOnClick=0

      mgroup.1="g"
       g.class="group"
       g.horiz=1
         g.0=Label("alfie")
         g.1="hs"
          hs.Class="hstring"
          hs.AlwaysNotifyNC=1
          hs.MaxLen=257
          ch.weight=0
         g.2=button("ch","Clear history")

    if NewObj("application","app")~=0 then exit

    call Notify("mwin","closerequest",1,"app","returnid","quit")
    call Notify("hs","NewContents","Everytime","app","return","call message(h.newcontents)","TriggerAttr")
    call Notify("ch","Pressed",0,"hs","HSClearHistory")

    call DoMethod("l","InsertWrap",ParseText(time()"|%b«HString»|Welcome!"),"bottom","WrapCol2")

    call set("mwin","ActiveObject","hs")
    call set("mwin","DefaultObject","hs")
    call set("mwin","open",1)

    return
/***********************************************************************/
handleApp: procedure
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        if h.event="QUIT" then exit
        else interpret h.event
    end
/* never reached */
/***********************************************************************/
message: procedure
parse arg msg
    if msg="" then return
    msg=time()"|alfie|"msg
    call DoMethod("l","InsertWrap",msg,"bottom","WrapCol2")
    call get("l","insertposition","p")
    call DoMethod("l","jump",p)
    return
/***********************************************************************/
