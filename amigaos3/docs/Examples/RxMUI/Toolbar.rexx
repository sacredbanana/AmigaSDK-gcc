/* The beauty of Toolbar */

signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
call RxMUIOpt("debugmode showerr")
call ProgDir()
call Pragma("W","N")

call CreateApp(f)
call HandleApp
/* never reached */
/***********************************************************************/
HandleApp: procedure expose pic

    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise say h.event
        end
    end
    /* never reached */
/***********************************************************************/
err: procedure expose sigl rxmuierror
parse arg res
say sigl "["res"]"
    say getrxmuistring(res) "in line" sigl-1 rxmuierror
    exit
/***********************************************************************/
CreateApp: procedure expose pic
parse arg f

    app.Title="ToolbarExample"
    app.Version="$VER: ToolbarExample 1.0 (23.3.2001)"
    app.Copyright="©2001, alfie"
    app.Author="alfie"
    app.Description="ToolbarExample"
    app.Base="RXMUIEXAMPLE"
    app.SubWindow="win"
     win.ID="MAIN"
     win.Title="Toolbar example"
     win.Contents="MGROUP"

      mgroup.0="tbg"
       tbg.class="virtgroup"
       tbg.horiz=1
        tbg.0="tb"
         tb.Class="Toolbar"
         tb.Font="Tiny"
         tb.Path="YAM:Icons/"
         tb.ImageNormal="Main.toolbar"
         tb.ImageSelect="Main_S.toolbar"
         tb.ImageGhost="Main_G.toolbar"
         tb.ParseUnderscore=1
         tb.ShortHelp=1
          tb.0.Type= "BUTTON"; tb.0.Text="_Read";
          tb.1.Type= "BUTTON"; tb.1.Text="_Edit";
          tb.2.Type= "BUTTON"; tb.2.Text="_Move";
          tb.3.Type= "BUTTON"; tb.3.Text="_Delete";
          tb.4.Type= "BUTTON"; tb.4.Text="_GetAdd";
          tb.5.Type= "SPACE"
          tb.6.Type= "BUTTON"; tb.6.Text="_New";
          tb.7.Type= "BUTTON"; tb.7.Text="_Reply";
          tb.8.Type= "BUTTON"; tb.8.Text="_Forward";
          tb.9.Type= "SPACE"
          tb.10.Type="BUTTON"; tb.10.Text="_Get";
          tb.11.Type="BUTTON"; tb.11.Text="_Forward"; tb.11.Flags="toggle"
          tb.12.Type="SPACE"
          tb.13.Type="BUTTON"; tb.13.Text="_Filter"; tb.13.Exlude=2**14+2**15+2**16; tb.13.Flags="selected"
          tb.14.Type="BUTTON"; tb.14.Text="_Find";   tb.14.Exlude=2**13+2**15+2**16
          tb.15.Type="BUTTON"; tb.15.Text="_Addr";   tb.15.Exlude=2**13+2**14+2**16
          tb.16.Type="BUTTON"; tb.16.Text="_Config"; tb.16.Exlude=2**13+2**14+2**15
        tbg.1=hspace()

      mgroup.1=hbar()

      mgroup.2="cg"
       cg.class="group"
       cg.columns=2
        cg.0=label("Exclude")
        cg.1=MakeObj(,"HLeft",MakeObj("ra","radio","Filter|Find|Addr|Config",,,1))
        cg.2=label("Disable _0")
        cg.3=MakeObj(,"HLeft",CheckMark("c0",,'0'))
        cg.4=label("Gone _1")
        cg.5=MakeObj(,"HLeft",CheckMark("c1",,'1'))
        cg.6=label("Disable toolbar")
        cg.7=MakeObj(,"HLeft",CheckMark("c2"))

    res=NewObj("APPLICATION","APP")
    if res~=0 then do
        call PrintFault()
        exit
    end

    call set("win","open",1)

    call Notify("win","CloseRequest",1,"app","ReturnID","quit")

    call Notify("ra","active",0,"tb","tbset",13,"selected",1)
    call Notify("ra","active",1,"tb","tbset",14,"selected",1)
    call Notify("ra","active",2,"tb","tbset",15,"selected",1)
    call Notify("ra","active",3,"tb","tbset",16,"selected",1)

    call TBNotify("tb",0,"pressed",0,"app","return","TB0")
    call TBNotify("tb",1,"pressed",0,"app","return","TB1")
    call TBNotify("tb",3,"pressed",0,"app","return","TB3")
    call TBNotify("tb",13,"pressed",1,"ra","set","active",0)
    call TBNotify("tb",14,"pressed",1,"ra","set","active",1)
    call TBNotify("tb",15,"pressed",1,"ra","set","active",2)
    call TBNotify("tb",16,"pressed",1,"ra","set","active",3)

    call Notify("c0","selected","everytime","tb","tbset",0,"ghosted","triggervalue")
    call Notify("c1","selected","everytime","tb","tbset",1,"Gone","triggervalue")
    call Notify("c2","selected","everytime","tb","tbsetall","ghosted","triggervalue")

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/

