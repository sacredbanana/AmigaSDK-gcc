/* Send messages as email or news
**
** SendMsgFun 2.1 (16.3.2001)
**/

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

    global.eol="D0A"x

    call SetSocketBaseSingle("BREAKMASK",or(2**12,2**13))

    call info "Resolving <"var.Host">..."
    remote.AddrAddr=resolve(var.Host)
    if remote.AddrAddr==-1 then call err "Host <"var.Host"> not found."
    remote.AddrPort=var.HostPort

    global.sock=socket("inet","stream")
    if global.sock<0 then call err "Can't create my socket."

    call info "Connecting to <"var.Host":"var.HostPort">..."
    res=connect(global.sock,"remote")
    if res<0 then call err "Can't connect to <"var.Host":"var.HostPort"> ("ErrorString()")"

    if GetSockName(global.sock,"locale")<0 then call err("Not enogh memory")

    call info("Entering...")
    call sen "HELO" locale.addraddr

    call rec

    call info("Sending message...")

    msg=,
    "Message-ID: <SendMsg"time(s)"@"locale.addraddr">" || global.eol ||,
    "From:" var.Name "<"var.EMail">" || global.eol ||,
    "Subject:" var.Subject || global.eol || ,
    "Date:" GMTInetDate() || global.eol

    if var.News then do

        call sen "POST"
        call rec

        msg=msg || ,
        "Newsgroups:" var.To || global.eol ||,
        "X-Newsposter: sendmsg/2.0" global.eol
    end
    else do
        call sen "MAIL FROM: <"var.EMail">"
        call rec

        call sen "RCPT TO: <"var.To">"
        call rec

        call sen "DATA"
        call rec

        msg=msg ||,
        "To: <"var.To">" || global.eol ||,
        "X-Mailer: sendmsg/1.0"
    end

    call sen msg

    call sen var.Text

    call sen global.eol || "."
    call rec

    call sen "QUIT"
    call rec

    call info("Done.")

    return
/***********************************************************************/
sen: procedure expose global.
parse arg string
    string=string || global.eol
    if send(global.sock,string)~=length(string) then call err("Send error" ErrorString())
    return
/***********************************************************************/
rec: procedure expose global.
    if recv(global.sock,"BUF",256)<0 then call err("Recv error" ErrorString())
    parse var BUF code rest (global.eol)
    if code>=400 then call err("Error from server: ("code")"rest)
    return
/***********************************************************************/
GMTInetDate: procedure expose global.
    m.1="Jan";m.2="Feb";m.3="Mar";m.4="Apr";m.5="May";m.6="Jun";m.7="Jul";m.8="Aug";m.9="Sep";m.10="Oct";m.11="Nov";m.12="Dec"
    call GetDate("D","GMT")
    parse value(FormatDate("D","%d %m %Y %H:%M:%S")) with i j rest
    j=j%1
    return i m.j || rest
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

