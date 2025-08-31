/* EMCheckFun 1.1 (11.11.2000) */

signal on halt
signal on break_c
signal on break_d
signal on syntax
signal on error

call init
call start()
exit

/***************************************************************************/
init: procedure expose global. var.
    call VarToStem("var.#?")
    global.MacroNotify=var.MacroNotify
    call MacroNotifyJoin(global.MacroNotify)
    global.done=1
    return
/***************************************************************************/
start: procedure expose global. var.

    host=var.Host
    HostPort=var.HostPort
    login=var.Login
    pass=var.Pass

    call SetSocketBaseSingle("BREAKMASK",or(2**12,2**13))

    call info "Resolving <"host">..."
    remote.AddrAddr=resolve(host)
    if remote.AddrAddr==-1 then call err "Host <"host"> not found."
    remote.AddrPort=hostPort

    global.sock=socket("INET","STREAM")
    if global.sock<0 then call err "Can't create my socket."

    call info "Connecting to <"host":"hostPort">..."
    res=connect(global.sock,"REMOTE")
    if res<0 then call err "Can't connect to <"host":"hostPort"> ("ErrorString()")"

    call info "Loggin in.."

    call rec

    call sen("USER" login)

    call rec

    call sen("PASS" pass)

    call rec

    call info "Statistics..."
    call sen("STAT")

    stat=rec()

    num=word(stat,2)
    if num>0 then msg="You have" num "new mail(s), for" word(stat,3) "total bytes."
    else msg="You have no new mail."
    call info msg

    call sen("QUIT")
    return
/***************************************************************************/
rec: procedure expose global.

    len=recv(global.sock,"B",256)

    if len<1 then call err "Error receiving ("ErrorString()")."

    parse var b b"D"x
    if word(b,1)=="-ERR" then call err right(b,length(b)-wordindex(b,2)+1) "(errore server)."
    return b
/***************************************************************************/
sen: procedure expose global.
parse arg string

    string=string"D0A"x
    res=send(global.sock,string)

    if res~=length(string) then call err "Error sending ("ErrorString()")."
    return
/***************************************************************************/
info: procedure expose global.
parse arg msg
    call MacroNotifyInsertEvent(global.MacroNotify,"INFO",msg)
    return
/***************************************************************************/
err: procedure expose global.
parse arg msg,err
    call info(msg)
    exit
/***************************************************************************/
halt:
break_c:
break_d:
    call CheckInit
    call err "Interrupted"
/***************************************************************************/
syntax:
    call CheckInit
    call err "Syntax error" rc "at line" sigl":" ErrorText(rc)
/***************************************************************************/
error:
    call CheckInit
    call err "Error" rc "at line" sigl":" ErrorText(rc)
/***************************************************************************/
CheckInit:
    if global.done~=1 then do
        call VarToStem("var.#?")
        call MacroNotifyJoin(var.MacroNotify)
        global.MacroNotify=var.MacroNotify
        global.done=1
    end
    return
/***************************************************************************/

