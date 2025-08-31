/* Register example */

signal on halt
signal on break_c

call init
call CreateApp
call HandleApp
/* never reached */


init: procedure expose global.
    l="rmh.library";if ~show("L",l) then;if ~AddLib(l,0,-30) then exit
    if AddLibrary("rexxsupport.library","rxmui.library")~=0 then exit
    return


CreateApp: procedure expose global.
    app.title="Pages"
    app.version="$VER: Pages 1.1 (25.1.2002)"
    app.copyright="Copyright 2002 by Alfie"
    app.author="alfie"
    app.description="Pages-Demo"
    app.base="Pages"
    app.SubWindow="mwin"

     mwin.ID="MAIN"
     mwin.title="Character Definition"
     mwin.contents="mgroup"

      call child("mgroup","g0","group")
       g0.columns=2
        g0.0=label("_Name:")
        g0.1=string("name","n","Frodo")
        g0.2=label("_Sex:")
        g0.3="sex"
         sex.class="cycle"
         sex.ControlChar="s"
         sex.entries="Male|Female"

      call child("mgroup",VSpace(2))

      call child("mgroup","reg","register")
       reg.REGISTERFRAME=1
       reg.titles="Race|Class|Armor|Level"

        call child("reg","graces","group")
         graces.horiz=1
         graces.spacing=0
          graces.0=HSpace(0)
          graces.1="races"
           races.class="radio"
           races.entries="Human|Elf|Dwarf|Hobbit|Gnome"
          graces.2=HSpace(0)

        call child("reg","gclasses","group")
         gclasses.horiz=1
         gclasses.spacing=0
          gclasses.0=HSpace(0)
          gclasses.1="classes"
           classes.class="radio"
           classes.entries="Warrior|Rogue|Bard|Monk|Magician|Archmage"
          gclasses.2=HSpace(0)

        call child("reg","g1","group")
         g1.horiz=1
          g1.0=HSpace(0)
          g1.1="gweapons"
           gweapons.class="group"
           gweapons.columns=2
            gweapons.0=label("_Cloak:");  cloak.ControlChar="c"; gweapons.1=CheckMark("cloak",1)
            gweapons.2=label("S_hield:"); shield.ControlChar="h"; gweapons.3=CheckMark("shield",1)
            gweapons.4=label("_Gloves:"); gloves.ControlChar="g";gweapons.5=CheckMark("gloves",1)
            gweapons.6=label("H_elmet:"); helmet.ControlChar="e";gweapons.7=CheckMark("helmet",1)
          g1.2=HSpace(0)

        call child("reg","g2","group")
         g2.columns=2
          g2.0=label("_Experience:");
          g2.1="experience"
           experience.class="slider"
           experience.ControlChar="e"
           experience.min=0
           experience.max=100
           experience.level=3
           experience.ControlChar="e"
          g2.2=label("S_trength:");
          g2.3="strength"
           strength.class="slider"
           strength.ControlChar="t"
           strength.min=0
           strength.max=100
           strength.level=42
          g2.4=label("_Dexterity:");
          g2.5="dexterity"
           dexterity.ControlChar="d"
           dexterity.class="slider"
           dexterity.min=0
           dexterity.max=100
           dexterity.level=24
          g2.6=label("_Condition:");
          g2.7="condition"
           condition.class="slider"
           condition.COntrolChar="c"
           condition.min=0
           condition.max=100
           condition.level=39
          g2.8=label("_Intelligence:");
          g2.9="intelligence"
           intelligence.class="slider"
           intelligence.ControlChar="i"
           intelligence.min=0
           intelligence.max=100
           intelligence.level=74

    res=NewObj("application","app")
    if res~=0 then call err(res)

    call notify("mwin","CloseRequest",1,"app","ReturnID","quit")

    call set("mwin","open",1)

    return

HandleApp: procedure expose global.
    ctrl_c=2**12
    do forever
        call NewHandle("APP","H",ctrl_c)
        if and(h.signals,ctrl_c)>0 then exit
        select
            when h.event="QUIT" then exit
            otherwise nop
        end
    end
    /* never reached */



halt:
break_c:
    exit


err: procedure expose sigl RxMUIError
parse arg res
    msg = ProgramName()":" GetRxMUIString(res) "in line" sigl-1
    if RxMUIError~="RXMUIERROR" then msg = msg "["RxMUIError"]"
    say msg
    exit


