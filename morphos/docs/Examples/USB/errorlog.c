
#include <proto/poseidon.h>
#include <proto/exec.h>
#include <stdio.h>

#include <libraries/poseidon.h>

struct Library *PsdBase;

int main(int argc, char *argv[])
{
    struct List *errmsgs;
    struct Node *pem;
    ULONG level;
    STRPTR origin;
    STRPTR errstr;

    if(PsdBase = OpenLibrary("poseidon.library", 1))
    {
        psdGetAttrs(PGA_STACK, NULL, PA_ErrorMsgList, &errmsgs, TAG_END);
        Forbid();
        while(errmsgs->lh_Head->ln_Succ)
        {
            pem = errmsgs->lh_Head;
            psdGetAttrs(PGA_ERRORMSG, pem,
                        EMA_Level, &level,
                        EMA_Origin, &origin,
                        EMA_Msg, &errstr,
                        TAG_END);
            printf("%2ld-%s: %s\n", level, origin, errstr);
            psdRemErrorMsg(pem);
        }
        Permit();
        CloseLibrary(PsdBase);
    } else {
        printf("Unable to open poseidon.library\n");
    }
    return(0);
}

