/* Very cute: a Popobject with CManager */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/* never reached */
/***********************************************************************/
Init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call RxMUIOpt("DebugMode ShowErr")
    call SetRxMUIStack(80000) /* CManager uses NList ! */
    return
/***********************************************************************/
CreateApp: procedure

    app.Title="Choose an URL"
    app.Version="$VER: ChooseURL 2.2 (11.2.2004)"
    app.Copyright="Copyright © 2004 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="Let you choose an URL"
    app.Base="CURL"
    app.SubWindow="win"
     win.Title="Choose an URL"
     win.Contents="mgroup"
     win.ID="MAIN"
      mgroup.0="pg"
       pg.Class="Group"
       pg.Horiz=1
        pg.0=Label("_URL")
        pg.1="pop"
         pop.Class="Popstring"
         pop.String=String("url",'u')
         pop.Button=MakeObj(,"ImageButton","Popup")
         pop.Window="pw"
          pw.Class="Window"
          pw.Title="Contact Manager"
          pw.ID="CMAN"
           pw.Contents="cm"
            cm.Class="cm"
            cm.HideUsers=1
            cm.HideWWW=0
            cm.HideFtp=1
            cm.HideChat=1
            cm.HideTelnet=1
            cm.NoBar=1
            cm.NoMenu=1
            cm.NoGroups=1
            cm.DoubleClick="cmentry"
         pop.CloseFun="call set('url','contents',RxMUIGetVar('cmentry.www'))"

    if NewObj("Application","app")>0 then exit

    call Add("app","pw")
    call DoMethod("cm","LoadData")

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")

    call Notify("pw","CloseRequest",1,"pop","Close",0)
    call Notify("cm","DoubleClick","EveryTime","pop","Close",1)

    call set("win","open",1)

    return
/***********************************************************************/
HandleApp: procedure
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise nop
        end
    end
    /* never reached */
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
