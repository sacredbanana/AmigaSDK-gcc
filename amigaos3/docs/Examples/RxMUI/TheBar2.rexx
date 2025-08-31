/*  */

signal on halt
signal on break_c

call Init
call CreateApp
call HandleApp

/***********************************************************************/
Init: procedure
    l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    call ProgDir()
    return
/***********************************************************************/
HandleApp: procedure
    ctrl_c=2**12
    do forever
        call NewHandle("app","h",ctrl_c)
        if and(h.signals,ctrl_c)>0 | h.event="QUIT" then exit
        interpret h.event
    end
/***********************************************************************/
CreateApp: procedure
    app.Title="TheBar"
    app.Version="$VER: TheBar2 1.0 (1.1.2003)"
    app.Copyright="©2004 by alfie"
    app.Author="alfie"
    app.Description="TheBar2 example"
    app.Base="TheBar"

    app.SubWindow.0="win"
     win.ID="win"
     win.Title="TheBar2 Example"
     win.Contents="mgroup"

      mgroup.ebackground="2:00000000,00000000,00000000"

      mgroup.0="TheBar"
       TheBar.class="TheBar"
       TheBar.Horiz=1
       TheBar.PicsDrawer="PROGDIR:Pics"
       TheBar.AutoID=1
       TheBar.ViewMode="GFX"
       TheBar.Borderless=1
       TheBar.Sunny=1
       TheBar.BarPos="Center"
       TheBar.TBHorizSpacing=32
       TheBar.TBNtRaiseActive=1

        TheBar.Pics.0="ball1"
        TheBar.Pics.1="ball2"
        TheBar.Pics.2="ball3"

        TheBar.0.Img=0
        TheBar.0.Help="Page 0"
        TheBar.0.Exclude=6
        TheBar.0.Flags="Selected"

        TheBar.1.Img=1
        TheBar.1.Help="Page 1"
        TheBar.1.Exclude=5

        TheBar.2.Img=2
        TheBar.2.Help="Page 2"
        TheBar.2.Exclude=3

      mgroup.1="gv"
       gv.class="group"
        gv.0=vspace()
        gv.1="gh"
         gh.class="hgroup"
          gh.0=hspace()
          gh.1="reg"
           reg.class="group"
           reg.pagemode=1
           reg.0=label(ParseText("%1Page 0"),"centered")
           reg.1=label(ParseText("%1Page 1"),"centered")
           reg.2=label(ParseText("%1Page 2"),"centered")
          gh.2=hspace()
        gv.2=vspace()

    if NewObj("Application","app")>0 then exit

    call Notify("win","closerequest",1,"app","returnid","quit")

    call Notify("TheBar","tbmouseover","EveryTime","thebar","set","Active","triggervalue")
    call Notify("TheBar","tbmouseover","EveryTime","reg","set","ActivePage","triggervalue")

    /*call TheBarNotify("TheBar",7,"pressed",0,"app","return","say 'Find pressed'")*/

    call set("win","open",1)

    return
/***********************************************************************/
halt:
break_c:
    exit
/**************************************************************************/
table: procedure
    r=""
    if xget("rbar","selected") then r=r "BARS "
    if xget("rbut","selected") then r=r "BUTTONS "
    if xget("rim","selected")  then r=r "IMAGES"
    if xget("rall","selected")  then r=r "ALL"

    call DoMethod("TheBar","InitChange")

    call set("TheBar","Remove",r)
    call set("TheBar","BarCols",0)
    call set("TheBar","BarCols",xget("cols","Active"))
    call set("TheBar","BarRows",xget("rows","Active"))

    call DoMethod("TheBar","ExitChange")

    return
/**************************************************************************/
horizFun: procedure
parse arg h

    if xget("rbar","selected") then r="BARS"
    else r=""
    if xget("rbut","selected") then r=r "BUTTONS"
    if xget("rall","selected")  then r=r "ALL"
    if h then im=""
    else im="IMAGES"

    call DoMethod("thebar","initchange")

    call set("thebar","remove",r im)
    call set("freehoriz","selected",h,1)
    call set("freevert","selected",~h,1)
    call set("rim","selected",~h,1)

    call set("thebar","Horiz",h)

    call DoMethod("thebar","exitchange")
    return

