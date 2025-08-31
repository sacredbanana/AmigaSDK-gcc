/* How to create and handle a Popobject */

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

    app.Title="PopObject"
    app.Version="$VER: PopObject 1.1 (5.10.2001)"
    app.Copyright="Copyrifht 2001 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="PopObjectExample"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="mwin"
     mwin.Title="PopObjectExample"
     mwin.ID="MAIN"
     mwin.Contents="mgroup"
      mgroup.0="po"
       po.Class="Popobject"
       po.Object="pg"
        pg.Class="group"
        pg.Frame="Inputlist"
         pg.0="Lv"
          lv.Class="Listview"
          lv.list="l"
         pg.1=Button("closepo","Close")
       po.String=String("S")
       po.Button=MakeObj("","Imagebutton","popup")
       po.Toggle=1
       po.OpenFun="call DoMethod('l','clear');call set('l','quiet',1);pl=show('p',,'/');do while pl~='';parse var pl p '/' pl;call domethod('l','insert',p,'sorted');end;call set('l','quiet',0);return 1"
       po.CloseFun="call DoMethod('l','GetEntry','active','A');call set('s','contents',a)"

    call NewObj("application","app")

    call Notify("mwin","CloseRequest",1,"app","ReturnID","quit")
    call Notify("lv","DoubleClick","EveryTime","po","Close",1)
    call Notify("closepo","Pressed",0,"po","Close")

    call set("mwin","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

