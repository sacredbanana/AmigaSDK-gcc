/* PopAsl - multi files request example */

app.Title="PopObject"
app.Version="$VER: PopObject 1.1 (2.2.2002)"
app.Copyright="©1999-2002, alfie"
app.Author="alfie"
app.Description="PopObject show"
app.Base="RXMUIEXAMPLE"
app.SubWindow="win"
 win.Title="PopObject"
 win.ID="POPF"
 win.Contents="mgroup"
  mgroup.0="popu"
   popu.class="popasl"
   popu.type="file"
   popu.fontminheight=11
   popu.fontmaxheight=20
   popu.FilterMacro="parse arg a,b,c;return pos('.c',a)=0"
   popu.domultiselect=1
   popu.acceptpattern="#?"
   popu.rejectpattern="#?.o"
    files.AutoExpand=1
   popu.string=string("files")
   popu.dopattern=1
   popu.sleepwindow=1
   popu.initialpattern="#?"
  mgroup.1=text("info")

call NewObj("application","app")

call notify("win",closerequest,1,app,returnid,quit)
call notify("files","newcontents","everytime",info,set,contents,triggervalue)

call set("win","open",1)

ctrl_c=2**12
do forever
    call NewHandle("app","h",ctrl_c)
    if and(h.signals,ctrl_c)>0 then exit
    if h.event="QUIT" then exit
    if h.event="PO" then do
        call domethod("list","getentry","active","e")
        call set("s","contents",e)
    end
end
