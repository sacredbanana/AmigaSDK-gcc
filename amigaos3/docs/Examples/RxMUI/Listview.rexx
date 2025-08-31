/* A List with 2 columns */

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if AddLibrary("rxmui.library")~=0 then exit

app.Title="ListExample"
app.Version="$VER: ListExample 1.1 (29.1.2002)"
app.Copyright="©2002, alfie"
app.Author="alfie"
app.Description="List Example"
app.Base="RXMUIEXAMPLE"
app.SubWindow="win"
 win.Title="ListExample"
 win.ID="WINL"
 win.Contents="mgroup"

  mgroup.0="lv"
   lv.Class="Listview"
   lv.CycleChain=1
   lv.List="l"
    l.Format="BAR,"
    l.0="Alfonso|1"
    l.1="Paolo|2"
    l.2="Emi|3"

  mgroup.1="g"
   g.Class="Group"
   g.Horiz=1
    sort.CycleChain=1;   g.0=Button("sort","_Sort")
    add.CycleChain=1;    g.1=Button("add","_Add")
    remove.CycleChain=1; g.2=Button("remove","_Remove")

  mgroup.2="gg"
   gg.Class="Group"
   gg.Horiz=1
     sa.CycleChain=1; sa.Reject="|"; gg.0=String("sa")
     sb.CycleChain=1; sb.Reject="|"; gg.1=String("sb")

if NewObj("Application","app")>0 then exit


call Notify("win","CloseRequest",1,"app","ReturnID","quit")

call Notify("sort","Pressed",0,"lv","Sort")
call Notify("add","Pressed",0,"l","Insert","","Bottom")
call Notify("add","Pressed",0,"l","Set","Active","Bottom")
call Notify("Remove","Pressed",0,"l","Remove","Active")

call Notify("l","ActiveEntry","Everytime","app","Return","say 'Active entry:' h.ActiveEntry","TriggerAttr")
call Notify("l","Active","Everytime","app","Return","say 'Active:' h.Active","TriggerAttr")

call Notify("l","Active",-1,"sa","Set","Contents","")
call Notify("l","Active",-1,"sb","Set","Contents","")

call Notify("l","ActiveEntry0","Everytime","sa","Set","Contents","TriggerValue")
call Notify("l","ActiveEntry1","Everytime","sb","Set","Contents","TriggerValue")

call Notify("sa","NewContents","Everytime","l","ReplaceCol","Active",0,"TriggerValue")
call Notify("sb","NewContents","Everytime","l","ReplaceCol","Active",1,"TriggerValue")

call set("l","Active",0)

set.DefaultObject="lv"
set.Open=1
call SetAttrs("win","set")

do forever
    call NewHandle("app","h",2**12)
    if and(h.signals,2**12)>0 then exit
    if h.event="QUIT" then exit
    interpret h.event
end
