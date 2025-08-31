/* Amirc 2.2 GUI ?!? */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp
/* Never reached */
/***********************************************************************/
Init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call ProgDir()
    global.ub=0
    return
/***********************************************************************/
CreateApp: procedure expose global.
    app.Title="Amirc"
    app.Version="$VER: Amirc 2.2 (3.6.2002)"
    app.Copyright="Copyright © 2002 by Alfonso Ranieri"
    app.Author="Alfonso Ranieri"
    app.Description="Amirc GUI clone"
    app.Base="AIRC"
    app.MenuStrip="strip"
     call child("strip","mproject","Menu")
      mproject.Title="Project"
       call child("mproject",menuitem("mservers","Server...","S"))
       call child("mproject",menuitem("","Bar"))
       call child("mproject",menuitem("mlog","Active log",,"Chekit Toggle"))
       call child("mproject",menuitem("","Bar"))
       call child("mproject",menuitem("mhide","Hide","H"))
       call child("mproject",menuitem("","Bar"))
       call child("mproject",menuitem("mhelp","Help..."))
       call child("mproject",menuitem("","Bar"))
       call child("mproject",menuitem("maboutAmirc","About Amirc...","?"))
       call child("mproject",menuitem("maboutmui","About MUI..."))
       call child("mproject",menuitem("","bar"))
       call child("mproject",menuitem("mquit","Quit","Q"))
    app.SubWindow="mwin"
     mwin.Title="Amirc"
     mwin.ID="AIRC"
     mwin.Contents="mgroup"
      call child("mgroup","g1","Group")
       g1.Horiz=1
       g1.HorizSpacing=0
        channels.Weight=0;call child("g1",Button("Channels","#amiga"))
       call child("g1","tp","Group")
        tp.PageMode=1
         call child("tp",String("Topic"))
         call child("tp",Text("STopic","a"))
       call child("g1",MakeTinyToggle("T","T",1))
       call child("g1",MakeTinyToggle("N","N",1))
       call child("g1",MakeTinyToggle("S","S",0))
       call child("g1",MakeTinyToggle("I","I",0))
       call child("g1",MakeTinyToggle("M","M",0))
       call child("g1",MakeTinyToggle("L","L",0))
       MaxUsers.Disabled=1;MaxUsers.Weight=0;call child("g1",string("MaxUsers"))
       call child("g1",MakeTinyToggle("K","k",0))
       key.Disabled=1;key.Weight=0;call child("g1",String("Key"))
       call child("G1",MakeTinyToggle("B","B",0))
      call child("mgroup","g2","Group")
       g2.Horiz=1
        call child("g2","talk","Group")
        call child("talk","msg","NListview")
         msg.List="List"
          list.Class="NList"
          list.Input=0
          list.AutoCopyToClip=1
          list.Format="PREPARSE" d2c(27)"r COL=0 BAR, COL=1 BAR"
          list.WrapCol=x2d(62)
          list.AutoVisible=0
           list.0="poing|CA rulezza, MUI suka"
           list.1="«Kick»|poing è stato cacciato da #amigaita da alfie : poing suka"
           list.2="alfie|rxmui.library rulez! :)"
           list.3="alfie|Open 'buttons' with an editor, modify and save it! :-)"
        call child("talk","me","Group")
         me.Horiz=1
          call child("me","lamp","Lamp")
          call child("me",Label("alfie"))
          call child("me","DUMMY1","GROUP")
           dummy1.Horiz=1
           dummy1.HorizSpacing=0
            call child("dummy1",String("mymsg"))
            e.Weight=0;call child("dummy1",Button("E","L"))
       call child("g2",MakeObj(,"Balance"))
       call child("g2","utils","Group")
        utils.Weight=10
         call child("utils","users","NListview")
          users.List="ulist"
           ulist.0="alfie"
           ulist.1="jhon"
         hbar.Weight=0;call child("utils",MakeObj("hbar","HBar",0))
    app.SubWindow.1="cwin"
     cwin.Title="Preferred channels"
     cwin.ID="CWIN"
     cwin.Contents="cwmgroup"
      cwmgroup.FrameTitle="(doubleclick on a channel to join it)"
      call child("cwmgroup","clistview","NListview")
       clistview.List="clist"
        clist.class="NList"
         clist.0="#amiga"
         clist.1="#amigaita"
      call child("cwmgroup","cwg","Group")
       cwg.Horiz=1
        call child("cwg",Label("Add:"))
        call child("cwg",String("ac"))
        call child("cwg",Button("rc","Remove"))

    if NewObj("APPLICATION","APP")>0 then exit

    call CreateUserButtons

    call Notify("mwin","CloseRequest",1,"app","ReturnID","QUIT")
    call Notify("cwin","CloseRequest",1,"cwin","Set","Open",0)

    call Notify("channels","Pressed",0,"cwin","Set","open",1)

    call Notify("msg","entries","EveryTime","msg","Set","first","bottom")

    call Notify("channels","Pressed",0,"app","ReturnID")

    call Notify("topic","NewContents","EveryTime","stopic","Set","Contents","TriggerValue")

    call Notify("T","Selected",0,"msg","insert","«mode»|not protected","bottom")
    call Notify("T","Selected",1,"msg","insert","«mode»|protected","bottom")
    call Notify("T","Selected","EveryTime","tp","Set","activepage","TriggerValue")
    call Notify("S","Selected",1,"msg","insert","«mode»|secret","bottom")
    call Notify("S","Selected",0,"msg","insert","«mode»|not secret","bottom")
    call Notify("I","Selected",1,"msg","insert","«mode»|invite only","bottom")
    call Notify("I","Selected",0,"msg","insert","«mode»|not invite","bottom")
    call Notify("M","Selected",1,"msg","insert","«mode»|moderated","bottom")
    call Notify("M","Selected",0,"msg","insert","«mode»|not moderated","bottom")
    call Notify("L","Selected","EveryTime","maxusers","Set","disabled","notTriggerValue")
    call Notify("K","Selected","EveryTime","key","Set","disabled","notTriggerValue")
    call Notify("B","Selected","EveryTime","app","returnid")

    call Notify("maboutamirc","MenuTrigger","EveryTime","app","About","mwin")
    call Notify("maboutmui","MenuTrigger","EveryTime","app","AboutMUI","mwin")
    call Notify("mquit","MenuTrigger","EveryTime","app","ReturnID","QUIT")
    call Notify("mhide","MenuTrigger","EveryTime","app","Set","Iconified",1)

    call set("topic","Contents","rxmui.library is out !!!")
    call set("stopic","Contents","rxmui.library is out !!!")

    call set("mwin","Open",1)

    return
/***********************************************************************/
HandleApp: procedure expose global.
    noti=StartNotify("PROGDIR:buttons")
    ns=NotifySignal(noti)
    ctrl_c=2**12
    mask=or(ctrl_c,ns)
    do forever
        call NewHandle("APP","H",mask)
        if and(h.signals,ctrl_c)>0 then exit
        if and(h.signals,ns)>0 then call createUserButtons
        if h.EventFlag then
            select
                when h.event="QUIT" then exit
                otherwise say h.event
            end
    end
    /* never reached */
/***********************************************************************/
CreateUserButtons: procedure expose global.
    if ~open("in","PROGDIR:buttons","r") then do
        say "can't open buttons file"
        return
    end

    call DoMethod("utils","InitChange")

    if global.ub then do
        call Dispose("userbuttons")
        call set("users","ContextMenu","")
        call Dispose("ubmenu")
    end

    ubmenu.0="mactions"
     mactions.class="Menu"
     mactions.Title="Actions"

    userbuttons.Columns=2
    userbuttons.Spacing=0
    userbuttons.Weight=0

    i=0
    do while ~eof("in")
        line=readln("in")
        if line="" then iterate
        userbuttons.i=button("ub"i,line)
        mactions.i=MenuItem("um"i,line)
        i=i+1
    end

    call close("in")

    if NewObj("Group","userbuttons")>0 then exit
    call Add("utils","userbuttons")

    if NewObj("Menustrip","ubmenu")>0 then exit
    call set("users","ContextMenu","ubmenu")

    call DoMethod("utils","ExitChange")

    global.ub=1

    return
/***********************************************************************/
MakeTinyToggle: procedure expose global.
parse arg name,text,state
    b.Contents=text
    b.InputMode="Toggle"
    b.ShowSelState=1
    b.Selected=state
    b.Font="Button"
    b.Frame="Button"
    b.Background="ButtonBack"
    b.Weight=0
    if NewObj("Text",name,"B")>0 then exit
    return name
/***********************************************************************/
halt:
break_c:
    exit
/***********************************************************************/
