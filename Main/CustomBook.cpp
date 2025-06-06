#include "stdafx.h"
#include "CustomBook.h"
#include "Util.h"


//----- (00534AC0) --------------------------------------------------------
void sub_534AC0(int a5, int a6, signed int a7, int a8)
{
  if ( (a6 < 3752 || a6 > 3760) && a6 != 3771 )
  {
    sub_535C90(a5);
    sub_536030(a5);
  }
  else
  {
    sub_535990(a5,a6, a7, a8);
    sub_535CD0(a5,a6, a7, a8);
  }
}

void InitBookLoad(){
	//SetCompleteHook(0xE8, 0x0057D09F,&sub_534AC0);
}