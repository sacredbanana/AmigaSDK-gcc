
(**********************************************************************
:Program.       mccTron.mod
:Contents.      Oberon 2 Modul for Tron.mcc
:Contents.      Registered class of the Magic User Interface.
:Author.        Klaus Melchior [kmel]
:Email.         kmel@eifel.tng.oche.de
:Help.          Frank Duerring [fjd]    (Oberon Modul)
:Email.         fd@marvin.unterland.de
:Copyright.     Klaus Melchior [kmel]
:Language.      Oberon 2
:Translator.    AmigaOberon v3.20d
:History.       [kmel] 28-Aug-1996 : PrMake generates this
***********************************************************************)

MODULE mccTron;

IMPORT Mui,
       MuiBasics,
       Utility,
       SYSTEM,
       Exec;


(*** Methods ***)

  CONST mTronDemo           * = 8002000BH;


(*** Method structs ***)

  TYPE
  pTronDemoPtr * = POINTER TO pTronDemo;
  pTronDemo    * = STRUCT
    MethodID   * : LONGINT;
  END;


(*** Special method values ***)

  CONST vTronDemoSimple                 * =   0;


(*** Special method flags ***)



(*** Attributes ***)

  CONST aTronRunning        * = 80020040H;


(*** Special attribute values ***)



(*** Stuff ***)

  CONST cTron * = "Tron.mcc";





VAR

  PROCEDURE mccTronObject*{"mccTron.mccTronObjectA"} ( tags{9}.. : Utility.Tag);
  PROCEDURE mccTronObjectA*( tags{9} : Utility.TagListPtr );
    BEGIN
      MuiBasics.NewObjectA( SYSTEM.ADR(cTron), tags );
    END mccTronObjectA;

END mccTron.

(* PrMake.rexx 0.10 (16.2.1996) Copyright 1995 kmel, Klaus Melchior *)

