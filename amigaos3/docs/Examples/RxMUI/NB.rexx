/* Numeric gadgets */

signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
call RxMUIOpt("DebugMode ShowErr")

call createApp
call SetNotifies

call set("win","open",1)

call handleApp
exit
/***********************************************************************/
handleApp: procedure
ctrl_c=2**12
s=0
do forever
    call handle("APP","H",s)
    do i=0 to h.num-1
        if h.i="QUIT" then exit
        say h.num-1 h.i
    end
    s=Wait(or(h.signals,ctrl_c))
    if and(s,ctrl_c)>0 then exit
end
exit
/***********************************************************************/
err: procedure expose sigl rxmuierror
parse arg res
say sigl "["res"]"
    say getrxmuistring(res) "in line" sigl-1 rxmuierror
    exit
/***********************************************************************/
createApp: procedure
    app.Title="NumericButton"
    app.Version="$VER: NumericButton 1.0 (10.12.99)"
    app.Copyright="©1999, alfie"
    app.Author="alfie"
    app.Description="NumericButton example"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="WIN"
     win.ID="MAIN"
     win.Title="NumericButton Example"
     win.Contents="MGROUP"
      mgroup.0="g"
       g.class="group"
       g.horiz=1
        g.0=hspace()
        g.1="ng"
         ng.class="group"
          ng.0="nb0"
           nb0.class="numericbutton"
           nb0.Format="1B63"x || "Val:%lx"
          ng.1="nb1"
           nb1.class="numericbutton"
           nb1.stringify="parse arg val; if val=0 then return '1B63'x || 'None';else return '1B63'x || 'Value:' val"
        g.2=hspace()

    res=NewObj("APPLICATION","APP")
    if res~=0 then call err(res)

    return
/***********************************************************************/
setNotifies: procedure
    res=Notify("WIN","CLOSEREQUEST",1,"APP","RETURNID","QUIT")
    if res~=0 then call err(res)

    call Notify("nb0","value","everytime","APP","RETURNID")
    call Notify("nb0","value","everytime","nb1","set","value","triggervalue")
    call Notify("nb1","value","everytime","nb0","set","value","triggervalue")

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

