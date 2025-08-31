/* */

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
CreateApp: procedure
    app.Title="kod"
    app.Version="$VER: kod 1.0 (22.11.99)"
    app.Copyright="©1999, koksa"
    app.Author="kkoksa phd"
    app.Description="kodda da worlda"
    app.Base="LOV"
    app.SubWindow="WIN"
     win.Title="Title"
     win.Contents="MGROUP"
      mgroup.0="lv"
       lv.Class="Listview"
       lv.List="voll"
        voll.Class="Volumelist"
        voll.Frame="READLIST"
      mgroup.1=Text("Vol")

    if NewObj("APPLICATION","APP")>0 then exit

    call Notify("win","closerequest",1,"app","returnid","quit")

    call Notify("lv","Doubleclick","everytime","app","returnid")

    call set("win","open",1)

    return
/***********************************************************************/
HandleApp: procedure  expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            when h.event="LV" then do
                call DoMethod("voll","GETENTRY","ACTIVE","A")
                call set("vol","Contents",a.name)
            end
            otherwise nop
        end
    end
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
