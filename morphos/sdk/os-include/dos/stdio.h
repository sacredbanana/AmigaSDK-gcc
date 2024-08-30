#ifndef DOS_STDIO_H
#define DOS_STDIO_H

/*
	dos stdio definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/


#define ReadChar()            FGetC(Input())
#define WriteChar(c)          FPutC(Output(),(c))
#define UnReadChar(c)         UnGetC(Input(),(c))

#define ReadChars(buf,num)    FRead(Input(),(buf),1,(num))
#define ReadLn(buf,len)       FGets(Input(),(buf),(len))
#define WriteStr(s)           FPuts(Output(),(s))
#define VWritef(format,argv)  VFWritef(Output(),(format),(argv))


#define BUF_LINE  0
#define BUF_FULL  1
#define BUF_NONE  2


#define ENDSTREAMCH  -1


#endif /* DOS_STDIO_H */
