/*
** Read an image so that its result
** may be used as Source for Picture class
*/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit

if ~Open("STDERR","CONSOLE:") then stderr="STDOUT"

if ~RMHReadArgs("FROM/A,TO") then call failure

if parm.1.flag then do
    if ~Open("OUT",parm.1.value,"w") then call failure
end
else out = "STDOUT"

st=statef(parm.0.value)
if st="" then call failure
if word(st,1)~="FILE" then do
    call SetIoErr(212)
    call failure
end
s=word(st,2)
if s>32767 then do
    call info(programname(noext)": file '"parm.0.value"'is too large")
    exit
end

bm.sourcetype="file"
bm.source=parm.0.value
if NewObj("picture","bm")>0 then call failure

pic=readfile(parm.0.value)
if pic="" then call failure

msg="Reading file '"parm.0.value"' ("length(pic)" bytes)"
if parm.1.flag then msg=msg "to file '"parm.1.value"'"
call info msg

s=31
do while pic~=""
    parse var pic b +s pic
    b=c2x(b)
    if s=31 then b=' "'||b
    if pic = "" then b=b||'"x'
    call writeln(out,b)
    s=32
end
exit

failure:
    call PrintFault()
    exit

info:
parse arg msg
    call writeln(stderr,msg)
    return

