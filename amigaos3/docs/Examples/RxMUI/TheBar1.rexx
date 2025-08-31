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
    app.Version="$VER: TheBar 1.0 (6.6.2003)"
    app.Copyright="©2003 by alfie"
    app.Author="alfie"
    app.Description="TheBar example"
    app.Base="TheBar"

    app.SubWindow.0="bwin"
     bwin.ID="BWIN"
     bwin.Title="TheBar Example"
     bwin.Contents="mbgroup"
      mbgroup.0="TheBar"
       TheBar.class="TheBar"
       TheBar.Horiz=1
       TheBar.PicsDrawer="PROGDIR:Pics"
       TheBar.EnableKeys=1
       TheBar.Framed=1
       TheBar.DragBar=1
       TheBar.AutoID=1
       TheBar.ViewMode="GFX"
       TheBar.Strip="YAM:Icons/Main.toolbar"
       TheBar.StripCols=14

        TheBar.0.Img=0
        TheBar.0.Text="Read"
        TheBar.0.Help="Read mail."

        TheBar.1.Img=1
        TheBar.1.Text="Edit"
        TheBar.1.Help="Edit mail."

        TheBar.2.Img="Bar"

        TheBar.3.Img=2
        TheBar.3.Text="Move"
        TheBar.3.Help="Move mail."

        TheBar.4.Img=3
        TheBar.4.Text="Delete"
        TheBar.4.Help="Delete mail."

        TheBar.5.Img="Button"

        TheBar.6.Img=4
        TheBar.6.Text="Get"
        TheBar.6.Help="Get mail."

        TheBar.7.Img=5
        TheBar.7.Text="New"
        TheBar.7.Help="Write mail."

        TheBar.8.Img="Image"

        TheBar.9.Img=7
        TheBar.9.Text="Reply"
        TheBar.9.Flags="Toggle"
        TheBar.9.Help="Reply mail."

        TheBar.10.Img="Bar"

        TheBar.11.Img=9
        TheBar.11.Text="Forward"
        TheBar.11.Flags="Selected"
        TheBar.11.Exclude=2**12
        TheBar.11.Help="Forward mail."

        TheBar.12.Img=10
        TheBar.12.Text="Fetch"
        TheBar.12.Exclude=2**11
        TheBar.12.Help="Fetch mail."

    app.SubWindow.1="cwin"
     cwin.ID="CWIN"
     cwin.Title="TheBar Example controls"
     cwin.Contents="cmgroup"

      cmgroup.0="ag"
       ag.class="Group"
       ag.columns=2
        ag.0=label("Appearance")
        ag.1=MakeObj("vm","Cycle","Icons and Text|Icons|Text",,1)
        ag.2=label("Bar pos")
        ag.3=MakeObj("bp","Cycle","Left|Center|Right")
        ag.4=label("Label pos")
        ag.5=MakeObj("lp","Cycle","Down|Up|Right|Left")

      cmgroup.1="sg"
       sg.class="scrollgroup"
        sg.virtgroupcontents="vg"
        sg.freehoriz=0
         vg.class="virtgroup"
         vg.frame="virtual"
          vg.0="hg"
           hg.class="hgroup"
            hg.0="cg"
             cg.class="group"
             cg.columns=2
              cg.0=checkmark("BL")
              cg.1=label("BorderLess","Left")
              cg.2=checkmark("RF")
              cg.3=label("Raised","Left")
              cg.4=checkmark("SI")
              cg.5=label("Scaled","Left")
              cg.6=checkmark("SN")
              cg.7=label("Sunny","Left")

              cg.8=vfspace("X")
              cg.9=vfspace("X")

              cg.10=checkmark("horiz",1)
              cg.11=label("Horiz","Left")
              cg.12=checkmark("freehoriz",1)
              cg.13=label("Free horiz","Left")
              cg.14=checkmark("freevert",)
              cg.15=label("Free vert","Left")
              cg.16=checkmark("BarSpacer")
              cg.17=label("Bar spacers","Left")

              cg.18=vfspace("X")
              cg.19=vfspace("X")

              cg.20=checkmark("cm1",1)
              cg.21=Label("Enable back","Left")
              cg.22=checkmark("cm2")
              cg.23=Label("Hide stop","Left")
              cg.24=checkmark("cm3")
              cg.25=Label("Sleep home","Left")

              cg.26=vfspace("X")
              cg.27=vfspace("X")

              cg.28=checkmark("rbar")
              cg.29=Label("Remove bar spacers","Left")
              cg.30=checkmark("rbut")
              cg.31=Label("Remove button spacers","Left")
              cg.32=checkmark("rim")
              cg.33=Label("Remove image spacer","Left")
              cg.34=checkmark("rall")
              cg.35=Label("Remove all spacers","Left")

            hg.1=hspace()
          vg.1=vspace()

      cmgroup.2="tg"
       tg.class="Group"
       tg.columns=2
        tg.0=label("Cols")
        tg.1=MakeObj(,"HLeft",MakeObj("cols","Radio","0|1|2|3|4|5|6|7|8|9|10",,,1))
        tg.2=label("Rows")
        tg.3=MakeObj(,"HLeft",MakeObj("rows","Radio","0|1|2|3|4|5|6|7|8|9|10",,,1))

    if NewObj("Application","app")>0 then exit

    call get("TheBar","TextOnly","nb")
    call set("vm","disabled",nb)
    call set("lp","disabled",nb)
    call set("sn","disabled",nb)
    call set("si","disabled",nb)

    call Notify("cols","active","EveryTime","app","return","call table")
    call Notify("rows","active","EveryTime","app","return","call table")

    call Notify("rbar","selected","EveryTime","app","return","call table")
    call Notify("rbut","selected","EveryTime","app","return","call table")
    call Notify("rim","selected","EveryTime","app","return","call table")
    call Notify("rall","selected","EveryTime","app","return","call table")

    call Notify("vm","active","EveryTime","TheBar","set","viewmode","TriggerValue")
    call Notify("bp","active","EveryTime","TheBar","set","barpos","TriggerValue")
    call Notify("lp","active","EveryTime","TheBar","set","labelpos","TriggerValue")

    call Notify("bwin","closerequest",1,"app","returnid","quit")
    call Notify("cwin","closerequest",1,"app","returnid","quit")

    call Notify("bl","selected","everytime","TheBar","set","borderless","triggervalue")
    call Notify("rf","selected","everytime","TheBar","set","raised","triggervalue")
    call Notify("si","selected","everytime","TheBar","set","scaled","triggervalue")
    call Notify("sn","selected","everytime","TheBar","set","sunny","triggervalue")

    call Notify("TheBar","active","EveryTime","app","return","say 'Active:'h.active","triggerattr")

    call Notify("cm1","selected","EveryTime","TheBar","TheBarSet",0,"Disabled","NotTriggerValue")
    call Notify("cm2","selected","EveryTime","TheBar","TheBarSet",4,"Hide","TriggerValue")
    call Notify("cm3","selected","EveryTime","TheBar","TheBarSet",6,"Sleep","TriggerValue")

    call Notify("horiz","selected","EveryTime","app","return","call horizFun(h.selected)","TriggerAttr")
    call Notify("freehoriz","selected","EveryTime","TheBar","set","FreeHoriz","TriggerValue")
    call Notify("freevert","selected","EveryTime","TheBar","set","FreeVert","TriggerValue")
    call Notify("BarSpacer","selected","EveryTime","TheBar","set","BarSpacer","TriggerValue")

    call TheBarNotify("TheBar",0,"pressed",0,"app","return","say 'Back pressed'")
    call TheBarNotify("TheBar",1,"pressed",0,"app","return","say 'Forward pressed'")
    call TheBarNotify("TheBar",3,"pressed",0,"app","return","say 'Reload pressed'")
    call TheBarNotify("TheBar",4,"pressed",0,"app","return","say 'Stop pressed'")
    call TheBarNotify("TheBar",6,"pressed",0,"app","return","say 'Home pressed'")
    call TheBarNotify("TheBar",7,"pressed",0,"app","return","say 'Find pressed'")

    call TheBarNotify("TheBar",9,"selected","Everytime","app","return","say 'java selected:'h.selected","TriggerAttr")

    call set("cwin","open",1)
    call set("bwin","open",1)

    /*s.0=1
    s.1=2
    s.2=4

    call DoMethod("TheBar","TheBarSort","s")

    add.ID=22
    add.Img=8
    add.Text="Added"
    add.Help="Added"
    call DoMethod("TheBar","thebaradd","add")
    s.0=22
    call DoMethod("TheBar","TheBarSort","s")*/

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

