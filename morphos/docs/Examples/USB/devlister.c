
#include <proto/poseidon.h>
#include <proto/exec.h>
#include <stdio.h>

struct Library *PsdBase;

int main(int argc, char *argv[])
{
    APTR pd;
    APTR pp;
    struct MsgPort *mp;
    ULONG devadr;
    ULONG devusbvers;
    ULONG devclass;
    ULONG devsubclass;
    ULONG devproto;
    ULONG devvendorid;
    ULONG devprodid;
    ULONG devversion;
    STRPTR devmanufact;
    STRPTR devprodname;
    STRPTR devserial;
    ULONG devcurrlang;
    UWORD *devlangarray;
    ULONG devislowspeed;
    ULONG devisconnected;
    ULONG devhasaddress;
    ULONG devhasdevdesc;
    ULONG devisconfigured;
    ULONG devnumcfgs;

    struct List *cfgs;
    struct Node *pc;
    ULONG cfgselfpow;
    ULONG cfgremwake;
    ULONG cfgnum;
    ULONG cfgmaxpower;
    STRPTR cfgname;
    ULONG cfgnumifs;

    struct List *ifs;
    struct Node *pif;
    struct Node *altpif;
    struct List *altpiflist;
    ULONG ifnum;
    ULONG ifaltnum;
    ULONG ifclass;
    ULONG ifsubclass;
    ULONG ifproto;
    STRPTR ifname;
    ULONG ifnumeps;

    APTR binding;
    struct Library *bindingcls;

    struct List *eps;
    struct Node *pep;
    ULONG episin;
    ULONG epnum;
    ULONG eptranstype;
    ULONG epmaxpktsize;
    ULONG epinterval;

    STRPTR strdesc;

    if(PsdBase = OpenLibrary("poseidon.library", 1))
    {
        pd = NULL;
        mp = CreateMsgPort();
        psdLockReadPBase();
        while(pd = psdGetNextDevice(pd))
        {
            psdLockReadDevice(pd);
            pp = psdAllocPipe(pd, mp, NULL);
            psdGetAttrs(PGA_DEVICE, pd,
                        DA_Address, &devadr,
                        DA_UsbVersion, &devusbvers,
                        DA_Class, &devclass,
                        DA_SubClass, &devsubclass,
                        DA_Protocol, &devproto,
                        DA_VendorID, &devvendorid,
                        DA_ProductID, &devprodid,
                        DA_Version, &devversion,
                        DA_Manufacturer, &devmanufact,
                        DA_ProductName, &devprodname,
                        DA_SerialNumber, &devserial,
                        DA_CurrLangID, &devcurrlang,
                        DA_LangIDArray, &devlangarray,
                        DA_IsLowspeed, &devislowspeed,
                        DA_IsConnected, &devisconnected,
                        DA_HasAddress, &devhasaddress,
                        DA_HasDevDesc, &devhasdevdesc,
                        DA_IsConfigured, &devisconfigured,
                        DA_NumConfigs, &devnumcfgs,
                        DA_ConfigList, &cfgs,
                        DA_Binding, &binding,
                        DA_BindingClass, &bindingcls,
                        TAG_END);
            printf("  Product Name    : '%s' (ID: %04lx, Vers: %04lx)\n"
                   "  Manufacturer    : '%s' (Vendor: %04lx (%s))\n"
                   "  Serial Number   : '%s' (USBVers: %04lx)\n"
                   "  Device State    : %s%s%s%s%s\n"
                   "  Device Address  : %ld\n"
                   "  Class/Sub/Proto : %ld/%ld/%ld (%s)\n"
                   "  Current Language: %s\n",
                   devprodname, devprodid, devversion,
                   devmanufact, devvendorid,
                   psdNumToStr(NTS_VENDORID, (LONG) devvendorid, "unknown"),
                   devserial, devusbvers,
                   devislowspeed ? "lowspeed " : "fullspeed ",
                   devisconnected ? "connected " : "disconnected ",
                   devhasaddress ? "hasaddress " : "",
                   devhasdevdesc ? "hasdevdesc " : "",
                   devisconfigured ? "isconfigured " : "",
                   devadr,
                   devclass, devsubclass, devproto,
                   psdNumToStr(NTS_CLASSCODE, devclass, "<unknown>"),
                   psdNumToStr(NTS_LANGID, devcurrlang, "<unknown>"));
            if(devlangarray)
            {
                UWORD *wptr = devlangarray;
                ULONG idx = 1;
                ULONG perline = 0;
                printf("  Supported Langs : ");
                while(*wptr)
                {
                    printf(psdNumToStr(NTS_LANGID, (ULONG) *wptr, "<unknown>"));
                    wptr++;
                    if(*wptr)
                    {
                        printf(", ");
                    }
                    if(++perline > 2)
                    {
                        printf("\n                    ");
                        perline = 0;
                    }
                }
                printf("\n");
                /*while(strdesc = psdGetStringDescriptor(pp, idx))
                {
                    printf("  String descriptor %04ld: %s\n", idx, strdesc);
                    psdFreeVec(strdesc);
                    idx++;
                }*/
            }
            if(binding)
            {
                printf("\n  This device is bound to %s, context %08lx.\n",
                       bindingcls->lib_Node.ln_Name, binding);
            }
            printf("\n  %ld configuration(s):\n", devnumcfgs);
            pc = cfgs->lh_Head;
            while(pc->ln_Succ)
            {
                psdGetAttrs(PGA_CONFIG, pc,
                            CA_SelfPowered, &cfgselfpow,
                            CA_RemoteWakeup, &cfgremwake,
                            CA_ConfigNum, &cfgnum,
                            CA_MaxPower, &cfgmaxpower,
                            CA_ConfigName, &cfgname,
                            CA_NumInterfaces, &cfgnumifs,
                            CA_InterfaceList, &ifs,
                            TAG_END);
                printf("    Config %ld (%s)\n"
                       "    Attrs   : %s %s\n"
                       "    MaxPower: %ld mA\n",
                       cfgnum, cfgname,
                       cfgselfpow ? "self-powered " : "bus-powered ",
                       cfgremwake ? "remote-wakeup" : "",
                       cfgmaxpower);
                printf("\n    %ld interface(s) for this config:\n", cfgnumifs);
                pif = ifs->lh_Head;
                while(pif->ln_Succ)
                {
                    altpif = pif;
                    do
                    {
                        psdGetAttrs(PGA_INTERFACE, altpif,
                                    IFA_InterfaceNum, &ifnum,
                                    IFA_AlternateNum, &ifaltnum,
                                    IFA_Class, &ifclass,
                                    IFA_SubClass, &ifsubclass,
                                    IFA_Protocol, &ifproto,
                                    IFA_InterfaceName, &ifname,
                                    IFA_NumEndpoints, &ifnumeps,
                                    IFA_EndpointList, &eps,
                                    IFA_AlternateIfList, &altpiflist,
                                    IFA_Binding, &binding,
                                    IFA_BindingClass, &bindingcls,
                                    TAG_END);
                        printf("      Interface %ld (%s)\n"
                               "      Alternate Setting: %ld\n"
                               "      Class/Sub/Proto  : %ld/%ld/%ld (%s)\n",
                               ifnum, ifname,
                               ifaltnum,
                               ifclass, ifsubclass, ifproto,
                               psdNumToStr(NTS_CLASSCODE, ifclass, "<unknown>"));
                        if(binding)
                        {
                            printf("\n      This interface is bound to %s, context %08lx.\n",
                                   bindingcls->lib_Node.ln_Name, binding);
                        }
                        printf("\n      %ld endpoint(s) for this interface:\n", ifnumeps);
                        pep = eps->lh_Head;
                        while(pep->ln_Succ)
                        {
                            psdGetAttrs(PGA_ENDPOINT, pep,
                                        EA_IsIn, &episin,
                                        EA_EndpointNum, &epnum,
                                        EA_TransferType, &eptranstype,
                                        EA_MaxPktSize, &epmaxpktsize,
                                        EA_Interval, &epinterval,
                                        TAG_END);
                            printf("        Endpoint %ld (%s %s)\n"
                                   "        MaxPktSize: %ld\n"
                                   "        Interval  : %ld\n",
                                   epnum, psdNumToStr(NTS_TRANSTYPE, eptranstype, "?"),
                                   episin ? "<-[ IN" : "OUT ]->",
                                   epmaxpktsize,
                                   epinterval);

                            pep = pep->ln_Succ;
                        }
                        if(altpif == pif)
                        {
                            altpif = (struct PsdInterface *) altpiflist->lh_Head;
                            /* check for alternate settings */
                            if(!altpif->ln_Succ)
                            {
                                printf("      No alternate settings.\n");
                                break;
                            }
                            printf("      Alternate settings:\n");
                        } else {
                            altpif = altpif->ln_Succ;
                            if(!altpif->ln_Succ)
                            {
                                break;
                            }
                        }
                    } while(TRUE);
                    pif = pif->ln_Succ;
                }
                pc = pc->ln_Succ;
            }
            psdFreePipe(pp);
            psdUnlockDevice(pd);
            printf("---------------------------------------------------------------------------\n");
        }
        psdUnlockPBase();
        DeleteMsgPort(mp);
        CloseLibrary(PsdBase);
    } else {
        printf("Unable to open poseidon.library\n");
    }
    return(0);
}

