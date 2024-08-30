;/* Execute me to compile
gcc -o AutoSort AutoSort.c -lauto
quit
;*/

#include <proto/intuition.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/listbrowser.h>
#include <proto/utility.h>

#include <classes/window.h>
#include <gadgets/layout.h>
#include <gadgets/listbrowser.h>

#include <stdlib.h>


enum {
    COL_DEFAULT_SORT,
    COL_CUSTOM_SORT,
    COL_LBM_SORT,
    NUM_COLS
};


static void add_row(struct List *list, CONST_STRPTR label1, CONST_STRPTR label2, CONST_STRPTR label3);
static int32 compare_func(struct Hook *hook, APTR obj, struct LBSortMsg *msg);


int main()
{
    struct Screen *screen = NULL;

    /* We'll just open up on the default public screen, and use its screen font. */
    if (screen = IIntuition->LockPubScreen(NULL))
    {
        struct List list;
        IExec->NewList(&list);

        /* Create the columns */
        struct Hook *compare_hook = IExec->AllocSysObjectTags(ASOT_HOOK,
            ASOHOOK_Entry, compare_func,
            TAG_DONE);

        struct ColumnInfo *ci = IListBrowser->AllocLBColumnInfo(NUM_COLS,
            LBCIA_Column, COL_DEFAULT_SORT,
                LBCIA_Title, "Default Sort",
                LBCIA_Width, 100,
                LBCIA_AutoSort, TRUE,
                LBCIA_DraggableSeparator, TRUE,
                LBCIA_SortArrow, TRUE,
            LBCIA_Column, COL_CUSTOM_SORT,
                LBCIA_Title, "Custom Sort",
                LBCIA_Width, 100,
                LBCIA_AutoSort, TRUE,
                LBCIA_CompareHook, compare_hook,
                LBCIA_DraggableSeparator, TRUE,
                LBCIA_SortArrow, TRUE,
            LBCIA_Column, COL_LBM_SORT,
                LBCIA_Title, "LBM_SORT",
                LBCIA_Width, 100,
                LBCIA_Sortable, TRUE,
                LBCIA_DraggableSeparator, TRUE,
                LBCIA_SortArrow, TRUE,
            TAG_DONE);

        /* Create the GUI objects */
        struct DrawInfo *drinfo = IIntuition->GetScreenDrawInfo(screen);
        Object *layout = NULL;
        Object *lb_gad = NULL;

        layout = IIntuition->NewObject(NULL, "layout.gadget",
            GA_DrawInfo, drinfo,
            LAYOUT_DeferLayout, TRUE,  // Defers GM_LAYOUT and GM_RENDER
            LAYOUT_SpaceOuter, TRUE,

            LAYOUT_AddChild, lb_gad = IIntuition->NewObject(NULL, "listbrowser.gadget",
                GA_ID, 1,
                GA_RelVerify, TRUE,
                LISTBROWSER_Labels, &list,
                LISTBROWSER_ColumnInfo, ci,
                LISTBROWSER_ColumnTitles, TRUE,
                LISTBROWSER_TitleClickable, TRUE,
//                LISTBROWSER_SortColumn, 0,    // Could be saved/restored via user prefs
                LISTBROWSER_Separators, TRUE,
                LISTBROWSER_MultiSelect, TRUE,
                LISTBROWSER_ShowSelected, TRUE,
                LISTBROWSER_AutoFit, TRUE,
                TAG_DONE),
            TAG_DONE);

        if (layout != NULL)
        {
            /* Add some rows to the list */
            add_row(&list, "Auto-sort feature demo",    "This row is sorted",  "This row is");
            add_row(&list, "Click on the column",       "using a custom hook", "sorted using");
            add_row(&list, "title and the rows in the", "on the 2nd letter",   "LBM_SORT from");
            add_row(&list, "listbrowser.gadget will",   "of each row",         "the");
            add_row(&list, "be automatically sorted.",  "just for fun.",       "application.");

            /* Create the window object */
            Object *window_obj = IIntuition->NewObject(NULL, "window.class",
                WA_CustomScreen, screen,
                WA_IDCMP, IDCMP_CLOSEWINDOW,
                WA_Flags, WFLG_DRAGBAR | WFLG_DEPTHGADGET | WFLG_CLOSEGADGET |
                            WFLG_SIZEGADGET | WFLG_ACTIVATE | WFLG_SMART_REFRESH,
                WA_Title, "ListBrowser AutoSort Example",
                WA_InnerWidth, 500,
                WA_InnerHeight, 300,
                WINDOW_Position, WPOS_CENTERSCREEN,
                WINDOW_Layout, layout,
                TAG_DONE);

            if (window_obj != NULL)
            {
                struct Window *win;

                /* Open the window */
                if (win = (struct Window *)IIntuition->IDoMethod(window_obj, WM_OPEN))
                {
                    BOOL ok = TRUE;

                    /* add the labels to the listbrowser */
                    IIntuition->RefreshSetGadgetAttrs((struct Gadget*)lb_gad, win, NULL,
                        LISTBROWSER_Labels, &list,
                        TAG_DONE);

                    /* Obtain the window wait signal mask.*/
                    uint32 signal = 0;
                    IIntuition->GetAttr(WINDOW_SigMask, window_obj, &signal);

                    /* Input Event Loop */
                    while (ok)
                    {
                        IExec->Wait(signal);

                        /* WM_HANDLEINPUT returns the gadget ID of a clicked
                         * gadget, or one of several pre-defined values.
                         */
                        uint32 result = 0;
                        int16 code = 0;

                        while ((result = IIntuition->IDoMethod(window_obj, WM_HANDLEINPUT, &code)) != WMHI_LASTMSG)
                        {
                            switch(result & WMHI_CLASSMASK)
                            {
                                case WMHI_CLOSEWINDOW:
                                    ok = FALSE;
                                    break;

                                case WMHI_GADGETUP:
                                    switch (result & WMHI_GADGETMASK)
                                    {
                                        case 1:
                                        {
                                            uint32 rel_event = LBRE_NORMAL;
                                            int32 rel_col    = -1;

                                            IIntuition->GetAttrs(lb_gad,
                                                LISTBROWSER_RelEvent, &rel_event,
                                                LISTBROWSER_RelColumn, &rel_col,
                                                TAG_DONE);

                                            if (rel_event == LBRE_TITLECLICK && rel_col == COL_LBM_SORT)
                                            {
                                                // Since we are not using auto-sort we have to track
                                                // and toggle the sort direction ourselves.
                                                static uint32 dir = LBMSORT_FORWARD;

                                                struct lbSort lbs;

                                                lbs.MethodID        = LBM_SORT;
                                                lbs.lbs_GInfo       = NULL;  // Filled in by DoGadgetMethod()
                                                lbs.lbs_Column      = COL_LBM_SORT;
                                                lbs.lbs_Direction   = dir;
                                                lbs.lbs_CompareHook = NULL;  // Default comparison (see LBM_SORT)

                                                IIntuition->DoGadgetMethodA((struct Gadget*)lb_gad, win, NULL, (APTR)&lbs);

                                                dir = (dir == LBMSORT_FORWARD) ? LBMSORT_REVERSE : LBMSORT_FORWARD;
                                            }

                                            break;
                                        }
                                    }
                                    break;
                            }
                        }
                    }
                 }
                else
                    IDOS->PutStr("ERROR: failed to start.  Couldn't open window\n");

                /* Disposing of the window object will also close the
                 * window if it is already opened and it will dispose of
                 * all objects attached to it.
                 */
                IIntuition->DisposeObject(window_obj);
            }
            else
                IDOS->PutStr("ERROR: failed to start.  Couldn't create window\n");
        }
        else
            IDOS->PutStr("ERROR: failed to start.  Couldn't create layout\n");

        IListBrowser->FreeLBColumnInfo(ci);
        IExec->FreeSysObject(ASOT_HOOK, compare_hook);

        IListBrowser->FreeListBrowserList(&list);

        IIntuition->FreeScreenDrawInfo(screen, drinfo);
        IIntuition->UnlockPubScreen(0, screen);
    }
    else
        IDOS->PutStr("ERROR: failed to start.  Couldn't lock destination screen\n");

    return(0);
}


static void add_row(struct List *list, CONST_STRPTR label1, CONST_STRPTR label2, CONST_STRPTR label3)
{
    struct Node *node = IListBrowser->AllocListBrowserNode(NUM_COLS,
        LBNA_Column, COL_DEFAULT_SORT,
            LBNCA_Text, label1,
        LBNA_Column, COL_CUSTOM_SORT,
            LBNCA_Text, label2,
        LBNA_Column, COL_LBM_SORT,
            LBNCA_Text, label3,
        TAG_DONE);

    if (node != NULL)
    {
        IExec->AddTail(list, node);
    }
}


static int32 compare_func(struct Hook *hook, APTR obj, struct LBSortMsg *msg)
{
    if (msg->lbsm_TypeA == 1 && msg->lbsm_TypeB == 1)
    {
        CONST_STRPTR lhs = msg->lbsm_DataA.Text;
        CONST_STRPTR rhs = msg->lbsm_DataB.Text;

        return IUtility->Stricmp(&lhs[1], &rhs[1]);
    }
    else
    {
        return 0;
    }
}

