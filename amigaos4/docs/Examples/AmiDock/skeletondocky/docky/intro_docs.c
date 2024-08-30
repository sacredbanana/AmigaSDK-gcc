
/****** docky.library/-introduction- ****************************************
*       
*   PREFACE
*       A docky (plural form: 'Dockies') is a plugin for the AmiDock
*       toolbar system. Dockies are able to control most of AmiDocks
*       feature and provide a great way to expand AmiDocks features beyond
*       its default features.
*       Dockies may be invisible to the user or show static or dynamic
*       (animated) content. They may change their behavior, size and look
*       according their current equirements.
*
*       New API functions/tags are marked with the DockyAPI version they first
*       appeared with.
*
*   STANDALONE DOCKIES
*       The most common form of dockies are stand-alone dockies.
*       This docky-type uses the shared library feature of AmigaOS as common
*       interface to the internal properties and behavioural possibilities
*       of a docky.
*
*   APPLICATION DOCKIES
*       The second possible form of dockies are application dockies (short
*       form 'AppDockies'). An AppDocky is a docky which is introduced to the
*       system during runtime by an application using application.libraries
*       registration mechanism for applications.
*       The biggest difference between the two docky types is that
*       AppDockies belong to a running application and usually are
*       used to represent the current state of the owning application.
*
*   DOCKY INITIALIZATION SEQUENCE
*      The following steps are the typical sequence how AmiDock opens
*      a docky:
*
*       1. DockyGet(DOCKYGET_Version, ...);
*       2. DockySet(DOCKYSET_DockyFileName, ...);
*       3. DockySet(DOCKYSET_DockyAttention, ...);
*       4. DockySet(DOCKYSET_DockyPrefs, ...);
*       5. DockySet(DOCKYSET_Screen, ...);
*       6. DockySet(DOCKYSET_Window, ...);
*       7. DockySet(DOCKYSET_DockTypeChange, ...);
*       8. DockySet(DOCKYSET_DockOrientationChange, ...);
*       9. DockyGet(DOCKYGET_InvisibleProcess, ...);
*      10. DockyGet(DOCKYGET_Notifications, ...);
*      11. DockyGet(DOCKYGET_FrameDelay, ...);
*          [- future expansion -]
*      12. DockySet(DOCKYSET_DockFontChange, ...);
*      13. DockyGet(DOCKYGET_RenderMode, ...);
*      14. DockyGet(DOCKYGET_ShowsName, ...);
*      15. DockySet(DOCKYSET_DockScaleFactor, ...);
*      16. DockyGet(DOCKYGET_GetSize, ...);
*      17. DockyGet(DOCKYSET_RenderDestination, ...);
*
*      Description:
*      ~~~~~~~~~~~~
*
*       1.) DOCKYGET_Version
*           AmiDock retrieves the version of the DockyAPI this docky was
*           designed with.
*
*       2.) DOCKYSET_DockyFileName
*           AmiDock tells the docky its own (the dockie's) full file name
*           with this call. This is not done in the case of an AppDocky.
*           You may ignore this call if you don't need this information.
*
*       3.) DOCKYSET_DockyAttention
*           AmiDock provides a filled struct DockyAttention with this call
*           to the docky. The docky may copy the values of this struct
*           To being later able to signal AmiDock asynchronously if
*           something uregent is pending (the docky will be processed
*           as soon as possible if the docky if it responds to the
*           DOCKYGET_NeedsAttention call).
*           You may ignore this call if you don't need this information.
*
*       4.) DOCKYSET_DockyPrefs
*           If AmiDock has some preferences for this docky which were
*           loaded by AmiDock with its won prefs file, AmiDock will
*           provide the read PrefsObject * with this call.
*           You may ignore this call if you don't need this information.
*
*       5.) DOCKYSET_Screen
*           AmiDock sets off this call to let the dockies know about the
*           screen they will be displayed on (probably useful for
*           remapping colours, etc.)
*           You may ignore this call if you don't need this information.
*
*       6.) DOCKYSET_Window
*           The window provided with this call is the dock window this
*           docky will live in. This info isn't very often required,
*           though.
*           You may ignore this call if you don't need this information.
*       
*       7.) DOCKYSET_DockTypeChange
*           This call provides a struct DockyDockType which gives the
*           information about which dock (and what type dock type) this
*           docky is "living" in.
*           You may ignore this call if you don't need this information.
*          
*       8.) DOCKYSET_DockOrientationChange
*           Some dockies may depend on a certain dock orinentation
*           or may at least know about the orientation of the dock
*           they're living in. This call provides this information.
*           You may ignore this call if you don't need this information.
*           
*       9.) DOCKYGET_InvisibleProcess
*           If the docky answers with TRUE to this question, AmiDock
*           even will process the docky if it is currently not visible
*           to the user (for example of the docky resides in a
*           different category or if the docky was is minimized).
*           Do use this feature only for dockies needing this feature
*           as each processed docky of course needs a small amount of
*           CPU time to being processed.          
*   
*      10.) DOCKYGET_Notifications
*           During runtime, AmiDock is able to send off a lot of different
*           notifications about events happening in the context of
*           AmiDocks environment.
*           This DOCKYGET call retrieves a notification mask which allows
*           the docky to specify the which different notifications are of
*           interest to the docky. Notifications not specified here will
*           not be sent to a docky.
*            
*       11.) DOCKYGET_FrameDelay
*           Specifies the update frequency of a Docky.
*           Have a look at the DockyGet function documentation for more
*           information about this topic.
*
*      12.) DOCKYSET_DockFontChange
*           AmiDock notifies the docky everytime the font attribute, front
*           pen, background pen and drawmode changes. To let the docky use
*           the right font and pens right from the start, this is called
*           at startup.
*
*
*      [- room for future expansion -]
*      Never do make any assumptions about what could be sent inbetween here.
*      Always respond to unknown messages with FALSE (not implemented).
*
*
*      13.) DOCKYGET_RenderMode
*           This call allows AmiDock to retrieve the rendermode required by
*           docky in question. You have to return one of
*           enum enDockyRenderMode here.
*       
*      14.) DOCKYGET_ShowsName
*           AmiDock can automatically render the name of the docky under the 
*           image. Returning TRUE/FALSE enables/disables this feature.
*            
*      15.) DOCKYSET_DockScaleFactor
*           Custom dockies that render their own imagery may want to adhere
*           to the users current setting for icon scaling factor. The LONG
*           supplied here is the current user value of that scaling, and can 
*           be used to calculate the size required in the dock. (see below)
*
*      16.) DOCKYGET_GetSize
*           You have to return a correctly filled struct DockySize here.
*           This allows AmiDock to prepare the currect render destination
*           for the docky. Currently the maximum size is the screen size.
*           The docky may wish to use the scaling factor supplied above 
*           in this calculation.
*
*      17.) DOCKYSET_RenderDestination
*           This is the final call within the initialization phase. AmiDock
*           successfully went through all required steps and allocated the
*           render destination (for example bitmap data). The render
*           destination returned by this call is the place where a docky has
*           to render its imaginery to.
* 
*   SEE ALSO
*       DockyGet(), DockySet(), <libraries/docky.h>
*
******
*
*/

