#include "stdafx.h"
#include "Import.h"
#include "Util.h"
#include "MasterSkillPoint.h"

/*char sub_819D60(char a5, char a6, float a7, float a8)
{
  DWORD* v8; // eax@1
  char result; // al@2
  int v10; // eax@3
  char *v11; // ST10_4@3
  int v12; // eax@3
  char v13; // [sp+8h] [bp-64h]@5
  int v14; // [sp+14h] [bp-58h]@1
  char v15; // [sp+1Ch] [bp-50h]@3
  char v16; // [sp+28h] [bp-44h]@3
  char v17; // [sp+38h] [bp-34h]@1
  char v18; // [sp+40h] [bp-2Ch]@3
  int v19; // [sp+48h] [bp-24h]@3
  char v20; // [sp+4Ch] [bp-20h]@1
  char v21; // [sp+54h] [bp-18h]@3
  int v22; // [sp+68h] [bp-4h]@3

  v14 = (int) a5;
  sub_81CE90((int)&v20, &a5);
  v8 = sub_81CC90(v14 + 340);
  if ( sub_81DE60(&v20,(int)v8) )
  {
    result = 1;
  }
  else
  {
    sub_823710((int)&v21);
    v22 = 0;
    sub_823740((int)&v21, a6, a7, a8);
    v10 = sub_81DE00(&v20, (int)a2, a3, (int)a4);
    v11 = sub_81DDC0(&v16, (DWORD *)(v10 + 20), (int)&v21);
    LOBYTE(v22) = 1;
    v12 = sub_81D300(v14 + 308, a2, a3, a4, (int)&v15, (int)v11);
    sub_823250((int)&v18, v12);
    LOBYTE(v22) = 0;
    sub_674040();
    if ( v19 )
    {
      v13 = *(BYTE *)(sub_81DE00(&v20, (int)a2, a3, (int)a4) + 8);
      if ( v13 )
      {
        if ( v13 == 1 )
        {
          *(BYTE *)(v14 + 233) += a6;
        }
        else if ( v13 == 2 )
        {
          *(BYTE *)(v14 + 234) += a6;
        }
      }
      else
      {
        *(BYTE *)(v14 + 232) += a6;
      }
      v22 = -1;
      sub_674060();
      result = 1;
    }
    else
    {
      v22 = -1;
      sub_674060();
      result = 0;
    }
  }
  return result;
}


*/void initMasterPoint()
{
	//SetCompleteHook(0xE8, 0x00651D20,&sub_819D60);
}