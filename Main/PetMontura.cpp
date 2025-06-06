#include "stdafx.h"
#include "TMemory.h"
#include "CustomPet.h"
#include "Import.h"
#include "Pet.h"
#include "Util.h"
#include "Defines.h"
#include "PetMontura.h"
#include "InfoLog.h"

int recargaNuevoPet(int NuevoPet)
{
	int t = -1;
	t = gCustomPet2.GetInfoPetType(NuevoPet - 1171);

	return t;
}

int __cdecl DrawObjectDropOnViewport(int a1)
{
	int result;
	char v3;

	DWORD dwItemNumber = *(DWORD *)(a1 + 48);

	*(float *)(a1 + 264) = 0.0;
	*(float *)(a1 + 268) = 0.0;
	*(float *)(a1 + 272) = -45.0;
	
	if ( dwItemNumber < 1171 || dwItemNumber >= 2195 )
	{
		if(gCustomPet2.CheckCustomPetByItem(dwItemNumber - 1171))
		{
			*(float *)(a1 + 264) = 270.0;
			*(float *)(a1 + 268) = 180.0;
			*(float *)(a1 + 272) = 45.0;
			*(float *)(a1 + 96) = gCustomPet2.GetScaleDrop(dwItemNumber - 1171);
		}
	}
	return result;
}

int recargaNuevoFenrir(int NuevoPet)
{
	int t = 0;
	t = gCustomPet2.GetInfoPetEffect(NuevoPet - 1171);

	return t;
}

#pragma optimize("t",on)

__declspec(naked) void SetPlayerAnimation2_Horse()
{
	static int Type;
	static DWORD horse;
	static DWORD Aguila;
	static DWORD This;
	static DWORD Addr1_JMP = 0x0054ECA0;
	static DWORD Addr2_JMP = 0x0054ED28;
	static DWORD Addr3_JMP = 0x0054ED43;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOV This, EAX
	}

	Type = recargaNuevoPet(horse);

	if(*(WORD *)(This + 676) != 0 && *(BYTE *)(This + 14) == 1 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else if(horse == 0x1E97 || Type == 6 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
}

__declspec(naked) void SetPlayerAnimation5()
{
	static int Type;
	static DWORD horse;
	static DWORD Addr1_JMP = 0x0055D1F5;
	static DWORD Addr2_JMP = 0x0055D219;
	static DWORD Addr3_JMP = 0x0055D236;
	
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP + 0x8]
		MOVSX ECX,WORD PTR DS:[EAX + 0x22C]
		MOV horse, ECX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1E97 || horse == 0x1E95 || horse == 0x1E96 || Type == 6 || Type == 7 || Type == 11 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else if( horse == 0x1EB8 || Type == 5 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
}

__declspec(naked) void SetPlayerAnimation7()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005AF200;
	static DWORD Addrss2 = 0x005AF212;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1E95 || horse == 0x1E96 || horse == 0x1E97 || Type == 7 || Type == 6 || Type == 11 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_EARTHQUAKE()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005AF28A;
	static DWORD Addrss2 = 0x005AFF59;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97  || Type == 6 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation9()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005AF553;
	static DWORD Addrss2 = 0x005AF565;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EDX,WORD PTR DS:[ECX + 0x22C]
		MOV horse, EDX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97 || Type == 6 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetHorsePlayer5()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x00552CD8;
	static DWORD Addrss2 = 0x005528F5;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 7829||  horse == 7830 ||horse == 0x1E97 || Type == 6 ||  Type == 7 ||  Type == 11 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetMontDarkHorse4()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005964E8;
	static DWORD Addrss2 = 0x005964F4;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV horse, ECX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97 || Type == 6 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetMontDarkHorse5()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005A3976;
	static DWORD Addrss2 = 0x005A3863;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV horse, ECX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1EB8 ||horse == 0x1E95 ||horse == 0x1E96 ||horse == 0x1E97 || Type == 7 || Type == 6 || Type == 5 || Type == 11 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void FollowMoveAllPet()
{
	static DWORD NuevoPet;
	static int Type;
	static DWORD MoveUniria = 0x00502C05;
	static DWORD MoveHorse = 0x005018A2;
	static DWORD Addrss2 = 0x005031C9;
	static DWORD MoveAngel = 0x00503232;
	static DWORD MoveSatan = 0x00503391;
	static DWORD MoveFenrrir = 0x0050190F;

	static DWORD Addr_Buffer = 0x0050339A;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP + 0x8]
		MOV ECX,DWORD PTR DS:[EAX + 0x30]
		MOV DWORD PTR SS:[EBP-0x124],ECX
		MOV EDX, DWORD PTR SS:[EBP-0x124]
		MOV NuevoPet, EDX
	}

	Type = recargaNuevoPet(NuevoPet);

	if( NuevoPet == 0x143 || NuevoPet == 0x0E9 || Type == 7 || Type == 11 ) //-- Uniria || Dinorant
	{
		_asm
		{
			JMP [MoveUniria]
		}
	}
	else if( NuevoPet == 0x0B0 ) //-- Algun Pet Extraño
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
	else if( NuevoPet == 0x1E93 || Type == 9) //-- PetAngel
	{
		_asm
		{
			JMP [MoveAngel]
		}
	}
	else if( NuevoPet == 0x1E94 || Type == 10) //-- PetSatan
	{
		_asm
		{
			JMP [MoveSatan]
		}
	}
	else if( NuevoPet == 0x180 ||  NuevoPet == 0x181 ||  NuevoPet == 0x182 || NuevoPet == 0x183 || Type == 5 ) //-- Pet Fenrrir
	{
		_asm
		{
			JMP [MoveFenrrir]
		}
	}
	else if( NuevoPet == 0x0E2 || Type == 6 ) //-- MonturaGhost || DarkHorse
	{
		_asm
		{
			JMP [MoveHorse]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr_Buffer]
		}
	}
}

__declspec(naked) void SetPlayerAnimation2_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x0054EADE;
	static DWORD Addrss2 = 0x0054EC8F;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV Fenrrir, ECX
	}

	Type = recargaNuevoPet(Fenrrir);

	if(Fenrrir == 0x1EB8 || Type == 5)	// fenrir
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation3_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x0054F6C0;
	static DWORD Addrss2 = 0x0054F6F6;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+8]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV Fenrrir, EDX
	}

	Type = recargaNuevoPet(Fenrrir);

	if(Fenrrir == 0x1EB8 || Type == 5)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetEffect_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x005E03E3;
	static DWORD Addrss2 = 0x005E05A4;
	static DWORD Addrss3 = 0x005E10AE;

	static DWORD CallMe1 = 0x004DB0C0;
	static DWORD CallMe2 = 0x00546860;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+8]
		MOV EAX, DWORD PTR DS:[ECX + 0x30]
		MOV Fenrrir, EAX
	}

	Type = recargaNuevoFenrir(Fenrrir);

	if(Fenrrir == 0x180 || Fenrrir == 0x181 || Fenrrir == 0x182 || Fenrrir == 0x183 ||Type != 0)
	{
		_asm
		{
			FLD DWORD PTR DS:[0x5EF5A1C]
			FMUL QWORD PTR DS:[0xD281C0]
			FSTP DWORD PTR SS:[EBP-0x55C]
			FLD DWORD PTR SS:[EBP-0x55C]
			PUSH ECX                                 ; /Arg1
			FSTP DWORD PTR SS:[ESP]                  ; |
			CALL CallMe1                      ; \main1.004DB0C0
			ADD ESP,0x4
			FMUL QWORD PTR DS:[0xD27C28]
			FSTP DWORD PTR SS:[EBP-0xAC]
			PUSH ECX                                 ; /Arg1
			FLD1                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP-0x14]            ; |
			CALL CallMe2                      ; \main1.00546860
			MOV EDX,DWORD PTR SS:[EBP-0x14]
			FLD1
			FSTP DWORD PTR DS:[EDX+0x48]
			MOV EAX,DWORD PTR SS:[EBP-0x14]
			FLD1
			FSTP DWORD PTR DS:[EAX+0x4C]
			MOV ECX,DWORD PTR SS:[EBP-0x14]
			FLD1
			FSTP DWORD PTR DS:[ECX+0x50]
		}

		if(Fenrrir == 0x183 ||Type == 2)
		{
			_asm
			{
				JMP [Addrss1]
			}
		}
		else
		{
			_asm
			{
				JMP [Addrss2]
			}
		}
		
	}
	else
	{
		_asm
		{
			JMP [Addrss3]
		}
	}
}

__declspec(naked) void AngelAnimacionPet()
{
	static DWORD Addrs_JMP1 = 0x00503407;
	static DWORD Addrs_JMP2 = 0x00503712;
	static DWORD a4;
	static int Type;

	_asm
	{
		MOV ECX, DWORD PTR SS:[EBP + 0x8]
		MOV EDX, DWORD PTR DS:[ECX + 0x30]
		MOV a4,EDX
	}

	Type = recargaNuevoPet(a4);

	if(a4 == ITEM2(13,0) || a4 == ITEM2(13,1) || Type == 9)
	{
		_asm
		{
			JMP[Addrs_JMP1]
		}
	}
	else
	{
		_asm
		{
			JMP[Addrs_JMP2]
		}
	}
}

__declspec(naked) void SetMontDarkHorse6()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x007DFE7E;
	static DWORD Addrss2 = 0x007E00BA;//007E00BA
	_asm
	{
		MOV EAX,DWORD PTR DS:[0x7BC4F04]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV horse, ECX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 7827 ||horse == 7831 ||horse == 7891 || horse == 7892 || horse == 7894|| horse == 7907 || horse == 7933 || horse == 7950 || horse == 7864  
		|| Type == 9 || Type == 6 || Type == 5 || Type == 3 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation1_uniria()
{
	static int Type;
	static DWORD uniria;
	static DWORD Addrss1 = 0x0054ED6A;
	static DWORD Addrss2 = 0x0054EDFA;

	_asm
	{
		MOV EAX, DWORD PTR SS:[EBP + 0x8]
		MOVSX ECX, WORD PTR DS:[EAX + 0x22C]
		MOV uniria, ECX
	}

	Type = recargaNuevoPet(uniria);

	if(uniria == 0x1E95 || uniria == 0x1E96 || Type == 7 || Type == 11 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation3_uniria()
{
	static DWORD uniria;
	static int Type;
	static DWORD Addrss1 = 0x005517C7;
	static DWORD Addrss2 = 0x0055182C;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV uniria, EAX
	}

	Type = recargaNuevoPet(uniria);

	if( uniria == 7829 || uniria == 7830 || Type == 7 || Type == 11 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation4_uniria()
{
	static DWORD uniria;
	static int Type;
	static DWORD Addrss1 = 0x00552757;
	static DWORD Addrss2 = 0x00552789;
	static DWORD Addrss3 = 0x005527A6;
	static DWORD Addr_Call = 0x00542310;
	static DWORD Addr_JNZ = 0x00552777;
	static DWORD Addr_JMP = 0x005527F4;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV uniria, EAX
	}

	Type = recargaNuevoPet(uniria);

	if( uniria == 7829 || uniria == 7830 || Type == 7 || Type == 11 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else if(Type == 6)
	{
		_asm
		{
			MOV EAX,DWORD PTR SS:[EBP+0x8]
			MOVZX ECX,BYTE PTR DS:[EAX+0xE]
			TEST ECX,ECX
			JNZ SHORT Addr_JNZ
			PUSH 1                                   ; /Arg3 = 00000001
			PUSH 86                                  ; |Arg2 = 0000009B
			MOV EDX,DWORD PTR SS:[EBP-0x4]             ; |
			PUSH EDX                                 ; |Arg1
			CALL [Addr_Call]
			JMP [Addr_JMP]
		}
	}
	else if(uniria = 0x1EB8 || Type == 5 )
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss3]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_STERN()
{
	static DWORD Addr1_JMP = 0x005B3942;
	static WORD Type;

	Type = *(WORD *)recargaNuevoPet(*(WORD *)(oUserPreviewStruct + 556));

	if ( Type != 6 &&*(WORD *)(oUserPreviewStruct + 556) != 7831 || *(BYTE *)(oUserPreviewStruct + 14) )
	{
		if ( Type != 7 && *(WORD *)(oUserPreviewStruct + 556) != 7829 || *(BYTE *)(oUserPreviewStruct + 14) )
		{
			if ( Type != 11 && *(WORD *)(oUserPreviewStruct + 556) != 7830 || *(BYTE *)(oUserPreviewStruct + 14) )
			{
				if ( Type != 5 && *(WORD *)(oUserPreviewStruct + 556) != 7864 || *(BYTE *)(oUserPreviewStruct + 14) )
					pActionPlayerSend(oUserPreviewStruct + 776, 67, 1);
				else
					pActionPlayerSend(oUserPreviewStruct + 776, 97, 1);
			}
			else
			{
				pActionPlayerSend(oUserPreviewStruct + 776, 69, 1);
			}
		}
		else
		{
			pActionPlayerSend(oUserPreviewStruct + 776, 68, 1);
		}
	}
	else
	{
		pActionPlayerSend(oUserPreviewStruct + 776, 86, 1);
	}

	_asm
	{
		JMP [Addr1_JMP]
	}
}

__declspec(naked) void PlayerAnimation_SKILL_REMOVE_STERN()
{
	static DWORD Addr1_JMP = 0x005B3C60;
	static WORD Type;

	Type = *(WORD *)recargaNuevoPet(*(WORD *)(oUserPreviewStruct + 556));

	if ( Type != 6 &&*(WORD *)(oUserPreviewStruct + 556) != 7831 || *(BYTE *)(oUserPreviewStruct + 14) )
	{
		if ( Type != 7 && *(WORD *)(oUserPreviewStruct + 556) != 7829 || *(BYTE *)(oUserPreviewStruct + 14) )
		{
			if ( Type != 11 && *(WORD *)(oUserPreviewStruct + 556) != 7830 || *(BYTE *)(oUserPreviewStruct + 14) )
			{
				if ( Type != 5 && *(WORD *)(oUserPreviewStruct + 556) != 7864 || *(BYTE *)(oUserPreviewStruct + 14) )
					pActionPlayerSend(oUserPreviewStruct + 776, 139, 1);
				else
					pActionPlayerSend(oUserPreviewStruct + 776, 97, 1);
			}
			else
			{
				pActionPlayerSend(oUserPreviewStruct + 776, 69, 1);
			}
		}
		else
		{
			pActionPlayerSend(oUserPreviewStruct + 776, 68, 1);
		}
	}
	else
	{
		pActionPlayerSend(oUserPreviewStruct + 776, 86, 1);
	}

	_asm
	{
		JMP [Addr1_JMP]
	}
}

_declspec(naked) void PlayerAnimation_SKILL_GREATER_MANA()
{
	static DWORD Addr1_JMP = 0x005B3F7D;
	static WORD Type;

	Type = *(WORD *)recargaNuevoPet(*(WORD *)(oUserPreviewStruct + 556));

	if ( Type != 6 &&*(WORD *)(oUserPreviewStruct + 556) != 7831 || *(BYTE *)(oUserPreviewStruct + 14) )
	{
		if ( Type != 7 && *(WORD *)(oUserPreviewStruct + 556) != 7829 || *(BYTE *)(oUserPreviewStruct + 14) )
		{
			if ( Type != 11 && *(WORD *)(oUserPreviewStruct + 556) != 7830 || *(BYTE *)(oUserPreviewStruct + 14) )
			{
				if ( Type != 5 && *(WORD *)(oUserPreviewStruct + 556) != 7864 || *(BYTE *)(oUserPreviewStruct + 14) )
					pActionPlayerSend(oUserPreviewStruct + 776, 67, 1);
				else
					pActionPlayerSend(oUserPreviewStruct + 776, 97, 1);
			}
			else
			{
				pActionPlayerSend(oUserPreviewStruct + 776, 69, 1);
			}
		}
		else
		{
			pActionPlayerSend(oUserPreviewStruct + 776, 68, 1);
		}
	}
	else
	{
		pActionPlayerSend(oUserPreviewStruct + 776, 86, 1);
	}

	_asm
	{
		JMP [Addr1_JMP]
	}
}

__declspec(naked) void PlayerAnimation_SKILL_POWER_SLASH()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x005ADB46;
	static DWORD Addr2_JMP = 0x005ADE8F;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX, WORD PTR DS:[EAX + 0x22C]
		MOV PetRender, ECX
	}

	Type = recargaNuevoPet(PetRender);

	if(PetRender == 0x1E97 || PetRender == 0x1E95 || PetRender == 0x1E96 || Type == 7 || Type == 6 || Type == 11 || PetRender == 0x1EB8 || Type == 5 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_BIRDS1()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x005ADE58;
	static DWORD Addr2_JMP = 0x005ADE75;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV PetRender, EAX
	}

	Type = recargaNuevoPet(PetRender);

	if(PetRender == 0x1EB8 || Type == 5 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_BIRDS2()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x005AE1EF;
	static DWORD Addr2_JMP = 0x005AE224;
	static DWORD Addr3_JMP = 0x005AE236;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PetRender, ECX
	}

	Type = recargaNuevoPet(PetRender);

	if(PetRender == 0x1EB8 || Type == 5 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else if(PetRender == 0x1E97 || PetRender == 0x1E95 || PetRender == 0x1E96 || Type == 7 || Type == 6 || Type == 11 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_FIRE_SCREAM()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x005AF1F5;
	static DWORD Addr2_JMP = 0x005AF212;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PetRender, ECX
	}

	Type = recargaNuevoPet(PetRender);

	if(PetRender == 0x1E97 || PetRender == 0x1E95 || PetRender == 0x1E96 || Type == 7 || Type == 6 || Type == 11 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_FORCE()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x006466AE;
	static DWORD Addr2_JMP = 0x006466DD;
	static DWORD Addr3_JMP = 0x006466FA;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x30]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PetRender, ECX
	}

	Type = recargaNuevoPet(PetRender);

	if( PetRender == 0x1E97 || PetRender == 0x1E95 || PetRender == 0x1E96 || Type == 7 || Type == 6 || Type == 11 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else if( PetRender == 0x1EB8 || Type == 5 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_FIRE_BURST()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x00646747;
	static DWORD Addr2_JMP = 0x00646776;
	static DWORD Addr3_JMP = 0x00646793;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x30]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV PetRender, EDX
	}

	Type = recargaNuevoPet(PetRender);

	if( PetRender == 0x1E97 || PetRender == 0x1E95 || PetRender == 0x1E96 || Type == 7 || Type == 6 || Type == 11 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else if( PetRender == 0x1EB8 || Type == 5 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_BUFF_SUM()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x00647B2B;
	static DWORD Addr2_JMP = 0x00647B40;
	static DWORD Addr3_JMP = 0x00647B55;
	static DWORD Addr4_JMP = 0x00647B6A;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x30]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV PetRender, EDX
	}

	Type = recargaNuevoPet(PetRender);

	if( PetRender == 0x1E95 || Type == 7 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else if( PetRender == 0x1E96 || Type == 11 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else if( PetRender == 0x1E97 || Type == 6 )
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
	else if( PetRender == 0x1EB8 || Type == 5 )
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr4_JMP]
		}
	}
}

__declspec(naked) void Enabled_SKILL_EARTHQUAKE()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr_Call = 0x7BC4F04;
	static DWORD Addr1_JMP = 0x008140D7;
	static DWORD Addr2_JMP = 0x008140DB;

	_asm
	{
		MOV EAX,DWORD PTR DS:[Addr_Call]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PetRender, ECX
	}

	Type = recargaNuevoPet(PetRender);

	if( PetRender == 0x1E97 || Type == 6 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

#pragma optimize("t",off)

/*int PlayerAnimation_RUNNING_PET(int a1)
{
	int v4; // eax@37
	int v5; // eax@38
	int v6; // eax@40
	float *v7; // ST28_4@40
	int v8; // eax@42
	float *v9; // ST24_4@42
	int v10; // eax@47
	int v11; // eax@48
	int v12; // eax@49
	int v13; // eax@49
	int v14; // eax@50
	float *v15; // ST20_4@50
	int v16; // eax@52
	int v17; // eax@52
	int v18; // eax@54
	int v19; // eax@54
	int v20; // eax@54
	int v21; // eax@54
	int v22; // eax@54
	int v23; // eax@55
	float *v24; // ST18_4@55
	int v25; // eax@55
	int v26; // eax@55
	int v27; // eax@57
	float *v28; // ST10_4@57
	int v29; // eax@57
	float *v30; // ST0C_4@57
	int v31; // eax@87
	int result; // eax@201
	signed int v33; // eax@205
	signed int v34; // eax@210
	int v35; // eax@215
	signed int v36; // eax@220
	int v37; // eax@225
	signed int v38; // ST08_4@236
	int v39; // eax@236
	int v40; // eax@240
	signed int v41; // [sp+20h] [bp-24h]@238
	int v42; // [sp+24h] [bp-20h]@236
	int j; // [sp+28h] [bp-1Ch]@44
	int i; // [sp+2Ch] [bp-18h]@34
	int v45; // [sp+30h] [bp-14h]@33
	signed int v46; // [sp+38h] [bp-Ch]@3
	signed int v47; // [sp+3Ch] [bp-8h]@3

	int Type;

	Type = recargaNuevoPet(*(WORD *)(a1 + 556));

	if ( *(BYTE *)(a1 + 14) )
		*(BYTE *)(a1 + 37) = 0;
	v46 = *(DWORD *)(*(DWORD *)0x8128AC4 + 5316);
	v47 = *(DWORD *)(*(DWORD *)0x8128AC4 + 5209);
	
	if ( (signed int)*(WORD *)(a1 + 132) < 534 || (signed int)*(WORD *)(a1 + 132) > 539 )
	{
		if ( !*(BYTE *)(a1 + 14)
			&& (signed int)*(BYTE *)(a1 + 37) < 40
			&& (sub_405230(*(BYTE *)(a1 + 19)) == 3
			|| sub_405230(*(BYTE *)(a1 + 19)) == 4
			|| sub_405230(*(BYTE *)(a1 + 19)) == 6
			|| *(DWORD *)0xE61E18 != 7
			&& !sub_4DB1C0(*(DWORD *)0xE61E18)
			&& *(DWORD *)0xE61E18 != 67
			&& *(WORD *)(a1 + 412) != -1 //-- comparando BootsSlot vacio
			&& (signed int)*(BYTE *)(a1 + 414) >= 5
			|| (*(DWORD *)0xE61E18 == 7 || sub_4DB1C0(*(DWORD *)0xE61E18) || *(DWORD *)0xE61E18 == 67)
			&& *(WORD *)(a1 + 376) != -1 //-- comparando GlovesSlot vacio
			&& (signed int)*(BYTE *)(a1 + 378) >= 5
			|| *(DWORD *)0xE61E18 != 7 && !sub_4DB1C0(*(DWORD *)0xE61E18) && *(DWORD *)0xE61E18 != 67 && v46 >= 40
			|| (*(DWORD *)0xE61E18 == 7 || sub_4DB1C0(*(DWORD *)0xE61E18) || *(DWORD *)0xE61E18 == 67) && v47 >= 40
			|| *(WORD *)(a1 + 556) == 7864 
			|| Type == 5
			|| *(DWORD *)(a1 + 828) == 256
			|| *(DWORD *)(a1 + 828) == 257) )
		{
			
			++*(BYTE *)(a1 + 37);
		}
	}
	else
	{
		*(BYTE *)(a1 + 37) = 0;
	}
	
	v45 = a1 + 776;
	if ( *(DWORD *)(a1 + 824) == 1163 )
	{
		for ( i = 15; i <= 22; ++i )
		{
			if ( sub_405230(*(BYTE *)(a1 + 19)) == 6 )
			{
				v4 = (int)sub_4CDA10();
				*(float *)(sub_51A220(v4, i) + 4) = 0.31999999;
			}
			else
			{
				v5 = (int)sub_4CDA10();
				*(float *)(sub_51A220(v5, i) + 4) = 0.33000001;
			}
			if ( pCheckEffectPlayer((DWORD *)(a1 + 1260), 56) )
			{
				v6 = (int)sub_4CDA10();
				v7 = (float *)(sub_51A220(v6, i) + 4);
				*v7 = *v7 * 0.5;
			}
			else if ( pCheckEffectPlayer((DWORD *)(a1 + 1260), 86) )
			{
				v8 = (int)sub_4CDA10();
				v9 = (float *)(sub_51A220(v8, i) + 4);
				*v9 = *v9 * 0.3300000131130219;
			}
		}

		for ( j = 25; j <= 37; ++j )
		{
			if ( sub_405230(*(BYTE *)(a1 + 19)) == 6 )
			{
				v10 = (int)sub_4CDA10();
				*(float *)(sub_51A220(v10, j) + 4) = 0.28;
			}
			else
			{
				v11 = (int)sub_4CDA10();
				*(float *)(sub_51A220(v11, j) + 4) = 0.34;
			}
			v12 = (int)sub_4CDA10();
			*(float *)(sub_51A220(v12, 259) + 4) = 0.34;
			v13 = (int)sub_4CDA10();
			*(float *)(sub_51A220(v13, 260) + 4) = 0.34;
			if ( pCheckEffectPlayer((DWORD *)(a1 + 1260), 56) )
			{
				v14 = (int)sub_4CDA10();
				v15 = (float *)(sub_51A220(v14, j) + 4);
				*v15 = *v15 * 0.5;
			}
			else if ( pCheckEffectPlayer((DWORD *)(a1 + 1260), 86) )
			{
				v16 = (int)sub_4CDA10();
				v17 = sub_51A220(v16, j);
				*(float *)(v17 + 4) = *(float *)(v17 + 4) * 0.3300000131130219;
			}
		}

		v18 = (int)sub_4CDA10();
		*(float *)(sub_51A220(v18, 245) + 4) = 0.048999999;
		v19 = (int)sub_4CDA10();
		*(float *)(sub_51A220(v19, 79) + 4) = 0.33000001;
		v20 = (int)sub_4CDA10();
		*(float *)(sub_51A220(v20, 77) + 4) = 0.33000001;
		v21 = (int)sub_4CDA10();
		*(float *)(sub_51A220(v21, 23) + 4) = 0.33000001;
		v22 = (int)sub_4CDA10();
		*(float *)(sub_51A220(v22, 32) + 4) = 0.75999999;

		if ( pCheckEffectPlayer((DWORD *)(a1 + 1260), 56) )
		{
			v23 = (int)sub_4CDA10();
			v24 = (float *)(sub_51A220(v23, 79) + 4);
			*v24 = *v24 * 0.5;
			v25 = (int)sub_4CDA10();
			v26 = sub_51A220(v25, 77);
			*(float *)(v26 + 4) = *(float *)(v26 + 4) * 0.5;
		}
		else if ( pCheckEffectPlayer((DWORD *)(a1 + 1260), 86) )
		{
			v27 = (int)sub_4CDA10();
			v28 = (float *)(sub_51A220(v27, 79) + 4);
			*v28 = *v28 * 0.3300000131130219;
			v29 = (int)sub_4CDA10();
			v30 = (float *)(sub_51A220(v29, 77) + 4);
			*v30 = *v30 * 0.3300000131130219;
		}
		
		if ( (Type != 5 && *(WORD *)(a1 + 556) != 7864) || *(BYTE *)(a1 + 14) )
		{
			if ( (Type != 6 && *(WORD *)(a1 + 556) != 7831) || *(BYTE *)(a1 + 14) )
			{
				if ( *(WORD *)(a1 + 676) && *(BYTE *)(a1 + 14) )
				{
					pActionPlayerSend(a1 + 776, 77, 1);
				}
				else if ( (Type != 7 && *(WORD *)(a1 + 556) != 7829) || *(BYTE *)(a1 + 14) )
				{
					if ( (Type != 11 && *(WORD *)(a1 + 556) != 7830) || *(BYTE *)(a1 + 14) )
					{
						if ( *(DWORD *)(a1 + 828) == 256
						|| *(DWORD *)(a1 + 828) == 257
						|| *(BYTE *)(a1 + 14)
						|| *(WORD *)(a1 + 520) == 65535 )
						{
							//-- Mapa Atlans
							if ( *(BYTE *)(a1 + 14) || *(DWORD *)0xE61E18 != 7 && !sub_4DB1C0(*(DWORD *)0xE61E18) && *(DWORD *)0xE61E18 != 67 )
							{
								if ( (*(WORD *)(a1 + 448) != -1 || *(WORD *)(a1 + 484) != -1)
									&& (!*(BYTE *)(a1 + 14) || sub_4E65C0(*(DWORD *)0xE61E18)) )
								{
									if ( (signed int)*(BYTE *)(a1 + 37) >= 40 )
									{
										if ( (signed int)*(WORD *)(a1 + 448) < 1171 || (signed int)*(WORD *)(a1 + 448) >= 2707 )
										{
											if ( (signed int)*(WORD *)(a1 + 448) < 3745 || (signed int)*(WORD *)(a1 + 448) > 3751 )
											{
												if ( (signed int)*(WORD *)(a1 + 448) < 3731 || (signed int)*(WORD *)(a1 + 448) >= 4243 )
												{
													if ( (signed int)*(WORD *)(a1 + 448) < 2707 || (signed int)*(WORD *)(a1 + 448) >= 3219 )
													{
														if ( sub_587950(a1) == 1 )
														{
															pActionPlayerSend(a1 + 776, 30, 1);//-- Corriendo con ballesta
														}
														else if ( sub_587950(a1) == 2 )
														{
															pActionPlayerSend(a1 + 776, 31, 1);//-- Corriendo con arco
														}
														else
														{
															pActionPlayerSend(a1 + 776, 25, 1);//-- Corriendo rapido
														}
													}
													else
													{
														pActionPlayerSend(a1 + 776, 29, 1);
													}
												}
												else if ( *(BYTE *)(*(DWORD *)0x8128AC0 + 84 * (*(WORD *)(a1 + 448) - 1171) + 30) )
												{
													pActionPlayerSend(a1 + 776, 29, 1);
												}
												else
												{
													pActionPlayerSend(a1 + 776, 26, 1);//-- corriendo con un arma
												}
											}
											else
											{
												pActionPlayerSend(a1 + 776, 32, 1);//-- corriendo congelado
											}
										}
										else if ( (signed int)*(WORD *)(a1 + 484) < 1171 || (signed int)*(WORD *)(a1 + 484) >= 2707 )
										{
											if ( *(BYTE *)(*(DWORD *)0x8128AC0 + 84 * (*(WORD *)(a1 + 448) - 1171) + 30) )
											{
												if ( *(WORD *)(a1 + 448) != 1192
												&& *(WORD *)(a1 + 448) != 1202
												&& *(WORD *)(a1 + 448) != 1194
												&& *(WORD *)(a1 + 448) != 1196 )
												{
													pActionPlayerSend(a1 + 776, 28, 1);//-- corriendo arma de 2 mano
												}
												else
												{
													pActionPlayerSend(a1 + 776, 144, 1);//-- correr con arma de mg
												}
											}
											else
											{
												pActionPlayerSend(a1 + 776, 26, 1);
											}
										}
										else if ( sub_405230(*(BYTE *)(a1 + 19)) == 6 )
										{
											pActionPlayerSend(a1 + 776, 25, 1);//-- correr
										}
										else
										{
											pActionPlayerSend(a1 + 776, 27, 1);//-- correr
										}
									}
									else if ( (signed int)*(WORD *)(a1 + 448) < 1171 || (signed int)*(WORD *)(a1 + 448) >= 2707 )
									{
										if ( (signed int)*(WORD *)(a1 + 448) < 3745 || (signed int)*(WORD *)(a1 + 448) > 3751 )
										{
											if ( (signed int)*(WORD *)(a1 + 448) < 3731 || (signed int)*(WORD *)(a1 + 448) >= 4243 )
											{
												if ( *(WORD *)(a1 + 448) != 2708 && *(WORD *)(a1 + 448) != 3221 )
												{
													if ( (signed int)*(WORD *)(a1 + 448) < 2707 || (signed int)*(WORD *)(a1 + 448) >= 3219 )
													{
														if ( sub_587950(a1) == 1 )
														{
															pActionPlayerSend(a1 + 776, 21, 1);
														}
														else if ( sub_587950(a1) == 2 )
														{
															pActionPlayerSend(a1 + 776, 22, 1);
														}
														else if ( sub_405230(*(BYTE *)(a1 + 19)) == 2 || sub_405230(*(BYTE *)(a1 + 19)) == 5)
														{
															pActionPlayerSend(a1 + 776, 16, 1);//-- caminar normal femenino
														}
														else
														{
															pActionPlayerSend(a1 + 776, 15, 1);//-- caminar normal
														}
													}
													else
													{
														pActionPlayerSend(a1 + 776, 20, 1);//-- caminar arma 2 manos
													}
												}
												else
												{
													pActionPlayerSend(a1 + 776, 19, 1);//-- caminar Ballesta
												}
											}
											else if ( *(BYTE *)(*(DWORD *)0x8128AC0 + 84 * (*(WORD *)(a1 + 448) - 1171) + 30) )
											{
												pActionPlayerSend(a1 + 776, 20, 1);
											}
											else
											{
												pActionPlayerSend(a1 + 776, 17, 1);//-- caminar raro
											}
										}
										else
										{
											pActionPlayerSend(a1 + 776, 23, 1);// caminar
										}
									}
									else if ( *(BYTE *)(*(DWORD *)0x8128AC0 + 84 * (*(WORD *)(a1 + 448) - 1171) + 30) )
									{
										if ( *(WORD *)(a1 + 448) != 1192
										&& *(WORD *)(a1 + 448) != 1202
										&& *(WORD *)(a1 + 448) != 1194
										&& *(WORD *)(a1 + 448) != 1196 )
										{
											pActionPlayerSend(a1 + 776, 18, 1);//-- arma a 2 manos
										}
										else
										{
											pActionPlayerSend(a1 + 776, 143, 1);//-- espada de mg
										}
									}
									else
									{
										pActionPlayerSend(a1 + 776, 17, 1);//-- caminar raro
									}
								}
								else if ( (signed int)*(BYTE *)(a1 + 37) < 40 )
								{
									if ( sub_405230(*(BYTE *)(a1 + 19)) == 2 || sub_405230(*(BYTE *)(a1 + 19)) == 5 )
									{
										if ( sub_405230(*(BYTE *)(a1 + 19)) == 5 && sub_4E65A0(*(DWORD *)0xE61E18) )
											pActionPlayerSend(a1 + 776, 15, 1);//caminar hombre
										else
											pActionPlayerSend(a1 + 776, 16, 1);//caminar mujer
									}
									else
									{
										pActionPlayerSend(a1 + 776, 15, 1);//caminar hombre
									}
								}
								else
								{
									pActionPlayerSend(a1 + 776, 25, 1);//correr
								}
							}
							else if ( (signed int)*(BYTE *)(a1 + 37) < 40 )
							{
								pActionPlayerSend(a1 + 776, 24, 1);//-- nadar normal
							}
							else
							{
								pActionPlayerSend(a1 + 776, 33, 1);//-- nadar rapido
							}
						}
						else if ( sub_587950(a1) == 2 )
						{
							pActionPlayerSend(a1 + 776, 35, 1);//-- flotar con alas y arco
						}
						else
						{
							pActionPlayerSend(a1 + 776, 34, 1);//-- Flotar con alas
						}
					}
					else if ( *(DWORD *)0xE61E18 != 8 && *(DWORD *)0xE61E18 != 10 )//-- mapa tarkan icarus
					{
						v31 = sub_4DB250();
						if ( !sub_4E44A0(v31 + 132) )
						{
							if ( sub_405230(*(BYTE *)(a1 + 19)) == 6 )
							{
								if ( *(WORD *)(a1 + 448) != -1 || *(WORD *)(a1 + 484) != -1 )
									pActionPlayerSend(a1 + 776, 260, 1);
								else
									pActionPlayerSend(a1 + 776, 259, 1);
							}
							else if ( *(WORD *)(a1 + 448) != -1 || *(WORD *)(a1 + 484) != -1 )
							{
								pActionPlayerSend(a1 + 776, 37, 1);
							}
							else
							{
								pActionPlayerSend(a1 + 776, 36, 1);
							}
						}
					}
				}
				else if ( sub_405230(*(BYTE *)(a1 + 19)) == 6 )
				{
					if ( *(WORD *)(a1 + 448) != -1 || *(WORD *)(a1 + 484) != -1 )
						pActionPlayerSend(a1 + 776, 260, 1);
					else
						pActionPlayerSend(a1 + 776, 259, 1);
				}
				else if ( *(WORD *)(a1 + 448) != -1 || *(WORD *)(a1 + 484) != -1 )
				{
					pActionPlayerSend(a1 + 776, 37, 1);
				}
				else
				{
					pActionPlayerSend(a1 + 776, 36, 1);
				}
			}
			else
			{
				pActionPlayerSend(a1 + 776, 79, 1);
			}
		}
		else if ( (signed int)*(BYTE *)(a1 + 37) >= 20 )
		{
			sub_541CF0(a1, a1 + 776);
		}
		else
		{
			sub_542050(a1, a1 + 776);
		}
	}
	else
	{
		pActionPlayerSend(a1 + 776, 2, 1);
	}
	sub_54EA00(v45);
	if ( *(DWORD *)(a1 + 824) == 671 )
	{
		result = PlayBuffer(124, v45, 0);
	}
	else if ( sub_405230(*(BYTE *)(a1 + 19)) != 4 || (Type != 6 && *(WORD *)(a1 + 556) != 7831) || *(BYTE *)(a1 + 14) )
	{
		if ( (Type != 5 && *(WORD *)(a1 + 556) != 7864)
		|| *(BYTE *)(a1 + 14)
		|| (signed int)*(WORD *)(a1 + 794) < 110
		|| (signed int)*(WORD *)(a1 + 794) > 121 )
		{
			if ( (Type != 5 &&*(WORD *)(a1 + 556) != 7864)
			|| *(BYTE *)(a1 + 14)
			|| (signed int)*(WORD *)(a1 + 794) < 126
			|| (signed int)*(WORD *)(a1 + 794) > 129 )
			{
				if ( (Type != 5 && *(WORD *)(a1 + 556) != 7864)
				|| *(BYTE *)(a1 + 14)
				|| (signed int)*(WORD *)(a1 + 794) < 270
				|| (signed int)*(WORD *)(a1 + 794) > 273 )
				{
					if ( Type != 5 || *(WORD *)(a1 + 556) != 7864
					|| *(BYTE *)(a1 + 14)
					|| (signed int)*(WORD *)(a1 + 794) < 266
					|| (signed int)*(WORD *)(a1 + 794) > 269 )
					{
						if ( a1 == *(DWORD *)0x7BC4F04 && (result = (signed int)sub_9CFB8D() % 64) == 0
						|| (result = a1, a1 != *(DWORD *)0x7BC4F04) && (result = (signed int)sub_9CFB8D() % 16) == 0 )
						{
							if ( *(DWORD *)(a1 + 824) != 1163
							|| *(DWORD *)(a1 + 828) >= 244 && (result = a1 + 776, *(DWORD *)(a1 + 828) <= 246) )
							{
								if ( *(DWORD *)(a1 + 828) >= 244 && *(DWORD *)(a1 + 828) <= 246 )
									PlayBuffer(123, v45, 0);
								//v38 = *(DWORD *)(a1 + 824);
								//v39 = (int)sub_4CDA10();
								result = sub_969C50(sub_4CDA10(), SLODWORD( *(DWORD *)((*(DWORD *)(a1 + 776)) + 48)));
								//result = sub_969C50_Addr(sub_4CDA10_Addr(), *(DWORD*)0x82C6248);
								v42 = result;
								if ( result && *(WORD *)(result + 170) != -1 )
								{
									v41 = 0;
									if ( *(DWORD *)(a1 + 828) == 9 )
										v41 = 5;
									v40 = (signed int)sub_9CFB8D() % 2;
									result = PlayBuffer(v41 + *(WORD *)(v42 + 2 * v40 + 170) + 210, v45, 0);
								}
							}
						}
					}
					else
					{
						v37 = (signed int)sub_9CFB8D() % 2;
						result = PlayBuffer(v37 + 690, v45, 0);
					}
				}
				else
				{
					v36 = sub_9CFB8D();
					result = PlayBuffer(v36 % 3 + 690, v45, 0);
				}
			}
			else
			{
				v35 = (signed int)sub_9CFB8D() % 2;
				result = PlayBuffer(v35 + 690, v45, 0);
			}
		}
		else
		{
			v34 = sub_9CFB8D();
			result = PlayBuffer(v34 % 3 + 690, v45, 0);
		}
	}
	else
	{
		v33 = sub_9CFB8D();
		result = PlayBuffer(v33 % 3 + 451, v45, 0);
	}
	return result;
}*/

/*int PlayerAnimationOneHit(int a1)
{
	int v4; // eax@83
	int v5; // eax@87
	int v6; // eax@88
	int v7; // eax@115
	int v8; // eax@116
	int v9; // eax@145
	int v10; // eax@159
	signed int v11; // ST2C_4@160
	int v12; // eax@160
	int result; // eax@160
	int v14; // eax@164
	int v15; // eax@178
	signed int v16; // [sp+Ch] [bp-14h]@162
	int v17; // [sp+10h] [bp-10h]@160
	char v18; // [sp+17h] [bp-9h]@121
	int v19; // [sp+1Ch] [bp-4h]@1
	int Type;

	v19 = a1 + 776;

	Type = recargaNuevoPet(*(WORD *)(a1 + 556));

	switch ( *(DWORD *)(a1 + 824) )
	{
	case 0x48B:
		sub_5509C0();
		if ( Type != 5 && *(WORD *)(a1 + 556) != 7864 || *(BYTE *)(a1 + 14) )
		{
			if ( Type != 6 && *(WORD *)(a1 + 556) != 7831 || *(BYTE *)(a1 + 14) )
			{
				if ( Type != 7 && Type != 11 && *(WORD *)(a1 + 556) != 7829 && *(WORD *)(a1 + 556) != 7830 || *(BYTE *)(a1 + 14) )
				{
					if ( *(WORD *)(a1 + 448) != -1 || *(WORD *)(a1 + 484) != -1 )
					{
						if ( (signed int)*(WORD *)(a1 + 448) < 1171 || (signed int)*(WORD *)(a1 + 448) >= 2707 )
						{
							if ( (signed int)*(WORD *)(a1 + 484) < 1171 || (signed int)*(WORD *)(a1 + 484) >= 2707 )
							{
								if ( (signed int)*(WORD *)(a1 + 448) < 3731 || (signed int)*(WORD *)(a1 + 448) >= 4243 )
								{
									if ( *(WORD *)(a1 + 448) != 2708 && *(WORD *)(a1 + 448) != 2709 )
									{
										if ( (signed int)*(WORD *)(a1 + 448) < 2707 || (signed int)*(WORD *)(a1 + 448) >= 3219 )
										{
											if ( sub_587950(a1) == 1 )
											{
												if ( *(WORD *)(a1 + 520) == -1 )
													pActionPlayerSend(a1 + 776, 50, 1);
												else
													pActionPlayerSend(a1 + 776, 52, 1);
											}
											else if ( sub_587950(a1) == 2 )
											{
												if ( *(WORD *)(a1 + 520) == -1 )
													pActionPlayerSend(a1 + 776, 51, 1);
												else
													pActionPlayerSend(a1 + 776, 53, 1);
											}
											else
											{
												pActionPlayerSend(a1 + 776, 38, 1);
											}
										}
										else
										{
											pActionPlayerSend(a1 + 776, *(BYTE *)(a1 + 40) % 3 + 47, 1);
										}
									}
									else
									{
										pActionPlayerSend(a1 + 776, 46, 1);
									}
								}
								else if ( *(BYTE *)(*(DWORD *)0x8128AC0 + 84 * (*(WORD *)(a1 + 448) - 1171) + 30) )
								{
									v6 = (signed int)sub_9CFB8D() % 2;
									pActionPlayerSend(a1 + 776, v6 + 148, 1);
								}
								else
								{
									v5 = (signed int)sub_9CFB8D() % 2;
									pActionPlayerSend(a1 + 776, v5 + 39, 1);
								}
							}
							else
							{
								v4 = (signed int)sub_9CFB8D() % 2;
								pActionPlayerSend(a1 + 776, v4 + 41, 1);
							}
						}
						else if ( *(BYTE *)(*(DWORD *)0x8128AC0 + 84 * (*(WORD *)(a1 + 448) - 1171) + 30) )
						{
							if ( *(WORD *)(a1 + 448) != 1192
							&& *(WORD *)(a1 + 448) != 1202
							&& *(WORD *)(a1 + 448) != 1194
							&& *(WORD *)(a1 + 448) != 1196 )
							{
								pActionPlayerSend(a1 + 776, *(BYTE *)(a1 + 40) % 3 + 43, 1);
							}
							else
							{
								pActionPlayerSend(a1 + 776, 145, 1);
							}
						}
						else if ( (signed int)*(WORD *)(a1 + 484) < 1171 || (signed int)*(WORD *)(a1 + 484) >= 2707 )
						{
							pActionPlayerSend(a1 + 776, *(BYTE *)(a1 + 40) % 2 + 39, 1);
						}
						else
						{
							switch ( *(BYTE *)(a1 + 40) % 4 )
							{
								case 0:
									pActionPlayerSend(a1 + 776, 39, 1);
								break;
								case 1:
									pActionPlayerSend(a1 + 776, 41, 1);
								break;
								case 2:
									pActionPlayerSend(a1 + 776, 40, 1);
								break;
								case 3:
									pActionPlayerSend(a1 + 776, 42, 1);
								break;
								default:
									goto LABEL_152;
							}
						}
					}
					else
					{
						pActionPlayerSend(a1 + 776, 38, 1);
					}
				}
				else if ( (signed int)*(WORD *)(a1 + 448) < 2707 || (signed int)*(WORD *)(a1 + 448) >= 2712 )
				{
					if ( (signed int)*(WORD *)(a1 + 448) < 2712 || (signed int)*(WORD *)(a1 + 448) >= 3219 )
					{
						if ( sub_587950(a1) == 1 )
						{
							pActionPlayerSend(a1 + 776, 58, 1);
						}
						else if ( sub_587950(a1) == 2 )
						{
							pActionPlayerSend(a1 + 776, 59, 1);
						}
						else if ( *(WORD *)(a1 + 448) == -1 )
						{
							if ( pGetCharClass(*(BYTE *)(a1 + 19)) == 6 )
								pActionPlayerSend(a1 + 776, 257, 1);
							else
								pActionPlayerSend(a1 + 776, 54, 1);
						}
						else if ( pGetCharClass(*(BYTE *)(a1 + 19)) == 6 )
						{
							if ( *(BYTE *)(*(DWORD *)0x8128AC0 + 84 * (*(WORD *)(a1 + 448) - 1171) + 30) )
								pActionPlayerSend(a1 + 776, 258, 1);
							else
								pActionPlayerSend(a1 + 776, 257, 1);
						}
						else if ( *(BYTE *)(*(DWORD *)0x8128AC0 + 84 * (*(WORD *)(a1 + 448) - 1171) + 30) )
						{
							pActionPlayerSend(a1 + 776, 55, 1);
						}
						else
						{
							pActionPlayerSend(a1 + 776, 54, 1);
						}
					}
					else
					{
						pActionPlayerSend(a1 + 776, 57, 1);
					}
				}
				else
				{
					pActionPlayerSend(a1 + 776, 56, 1);
				}
			}
			else//-- horse
			{
				if ( sub_587950(a1) == 1 )
				{
					pActionPlayerSend(a1 + 776, 101, 1);
				}
				else if ( sub_587950(a1) == 2 )
				{
					pActionPlayerSend(a1 + 776, 98, 1);
				}
				else
				{
					pActionPlayerSend(a1 + 776, 84, 1);
				}
			}
		}
		else
		{
			if ( (signed int)*(WORD *)(a1 + 448) < 2707 || (signed int)*(WORD *)(a1 + 448) >= 2712 )
			{
				if ( sub_587950(a1) == 1 )
				{
					pActionPlayerSend(a1 + 776, 101, 1);
				}
				else if ( sub_587950(a1) == 2 )
				{
					pActionPlayerSend(a1 + 776, 98, 1);
				}
				else if ( *(WORD *)(a1 + 448) == -1 || *(WORD *)(a1 + 484) == -1 )
				{
					if ( *(WORD *)(a1 + 448) == -1 || *(WORD *)(a1 + 484) != -1 )
					{
						if ( *(WORD *)(a1 + 448) != -1 || *(WORD *)(a1 + 484) == -1 || pGetCharClass(*(BYTE *)(a1 + 19)) != 6 )
						{
							if ( *(WORD *)(a1 + 448) != -1 || *(WORD *)(a1 + 484) == -1 )
								pActionPlayerSend(a1 + 776, 90, 1);
							else
								pActionPlayerSend(a1 + 776, 100, 1);
						}
						else
						{
							pActionPlayerSend(a1 + 776, 282, 1);
						}
					}
					else
					{
						pActionPlayerSend(a1 + 776, 100, 1);
					}
				}
				else
				{
					pActionPlayerSend(a1 + 776, 96, 1);
				}
			}
			else
			{
				pActionPlayerSend(a1 + 776, 99, 1);
			}
			if ( pGetCharClass(*(BYTE *)(a1 + 19)) == 4 )
				pActionPlayerSend(a1 + 776, 93, 1);
		}
		break;
	case 0x27:
		pSkillRenderEffect( 259, a1 + 1028, a1 + 1040, (float*)a1 + 932, 0, 0, -1, 0, 0, 0, 0.0, -1);
		pChatReserveLine(16, v19, 0);
		break;
	case 0x28:
		pActionPlayerSend(a1 + 776, 1, 1);
		pChatReserveLine(16, v19, 0);
		break;
	case 0x33:
		pSkillRenderEffect( 32072, a1 + 1028, a1 + 1040, (float*)a1 + 932, 0, 0, -1, 0, 0, 0, 0.0, -1);
		pChatReserveLine(121, 0, 0);
		break;
	case 0x2A4:
		v7 = (signed int)sub_9CFB8D() % 8;
		if ( v7 <= 2 )
		{
			if ( v7 <= 0 )
				pActionPlayerSend(a1 + 776, 9, 1);
			else
				pActionPlayerSend(a1 + 776, 8, 1);
		}
		else
		{
			v8 = (signed int)sub_9CFB8D() % 2;
			pActionPlayerSend(a1 + 776, v8 + 3, 1);
		}
		break;
	default:
		v18 = 1;
		if ( sub_901B00(a1, v19) == 1 )
			v18 = 0;
		if ( sub_8CF620(a1, v19) == 1 )
			v18 = 0;
		if ( sub_90B970(a1, v19) == 1 )
			v18 = 0;
		if ( sub_8CAE70(a1, v19) == 1 )
			v18 = 0;
		if ( sub_8DC0E0(a1, v19) == 1 )
			v18 = 0;
		if ( sub_8A28A0(a1, v19) == 1 )
			v18 = 0;
		if ( sub_8A82B0(a1, v19) == 1 )
			v18 = 0;
		if ( sub_8B43C0(a1, v19) == 1 )
			v18 = 0;
		sub_89CB00();
		if ( sub_89E2C0(a1, v19) )
			v18 = 0;
		sub_91C9D0();
		if ( sub_91CD60(a1, v19) == 1 )
			v18 = 0;
		if ( sub_9141D0(a1, v19) == 1 )
			v18 = 0;
		if ( sub_91ACC0(a1, v19) == 1 )
			v18 = 0;
		//v9 = sub_897DC0();
		//if ( sub_899CA0(a1, v19) == 1 )
			//v18 = 0;
		if ( v18 )
		{
			if ( *(BYTE *)(a1 + 40) % 3 )
				pActionPlayerSend(a1 + 776, 4, 1);
			else
				pActionPlayerSend(a1 + 776, 3, 1);
			++*(BYTE *)(a1 + 40);
		}
		break;
	}
LABEL_152:
	if ( 0xE61E18 == 73 || *(float *)(a1 + 916) != 0.0 )
		goto LABEL_179;
	sub_54EA00(v19);
	if ( *(DWORD *)(a1 + 824) == 1163 && (*(DWORD *)(a1 + 828) < 244 || *(DWORD *)(a1 + 828) > 246) )
	{
		if ( sub_587950(a1) == 1 )
		{
			pChatReserveLine(85, v19, 0);
		}
		else if ( sub_587950(a1) == 2 )
		{
			pChatReserveLine(86, v19, 0);
		}
		else if ( (signed int)*(WORD *)(a1 + 448) < 3232 || (signed int)*(WORD *)(a1 + 448) >= 3234 )
		{
			if ( *(WORD *)(a1 + 448) != 1181 && *(WORD *)(a1 + 448) != 2707 )
			{
				if ( *(WORD *)(a1 + 448) != -1 || *(WORD *)(a1 + 484) != -1 )
				{
					v15 = (signed int)sub_9CFB8D() % 2;
					pChatReserveLine(v15 + 60, v19, 0);
				}
			}
			else
			{
				pChatReserveLine(62, v19, 0);
			}
		}
		else
		{
			pChatReserveLine(118, v19, 0);
		}
		goto LABEL_179;
	}
	if ( *(DWORD *)(a1 + 828) >= 244 && *(DWORD *)(a1 + 828) <= 246 )
	{
		v10 = (signed int)sub_9CFB8D() % 2;
		pChatReserveLine(v10 + 60, v19, 0);
	}
	//v11 = *(DWORD *)(a1 + 824);
	result = sub_969C50(sub_4CDA10(), SLODWORD( *(DWORD *)((*(DWORD *)(a1 + 776)) + 48)));
	v17 = result;
	if ( result )
	{
		if ( *(WORD *)(result + 174) != -1 )
		{
			v16 = 0;
			if ( *(DWORD *)(a1 + 828) == 9 )
				v16 = 5;
			v14 = (signed int)sub_9CFB8D() % 2;
			pChatReserveLine(v16 + *(WORD *)(v17 + 2 * v14 + 174) + 210, v19, 0);
		}
LABEL_179:
		result = a1;
		++*(BYTE *)(a1 + 40);
	}
	return result;
}
*/
__int16 PlayerAnimationMonturaSkill (int a3)
{
	__int16 result; // ax@5
	int v4; // eax@11
	int v5; // [sp+0h] [bp-4h]@1
	int Type;

	v5 = a3 + 776;
	
	Type = recargaNuevoPet(*(WORD *)(a3 + 556));

	if ( *(DWORD *)(a3 + 824) == 1163 )
	{
		sub_5509C0();
		if ( Type != 6 && Type != 7 && Type != 11 && *(WORD *)(a3 + 556) != 7829 && *(WORD *)(a3 + 556) != 7830 || *(BYTE *)(a3 + 14) )
		{
			if (Type != 5 && *(WORD *)(a3 + 556) != 7864 || *(BYTE *)(a3 + 14) )
			{
				if ( pGetCharClass(*(BYTE *)(a3 + 19)) == CLASS_ELF || pGetCharClass(*(BYTE *)(a3 + 19)) == CLASS_SUMMONER)
				{
					result = pActionPlayerSend(v5, 150, 1);
				}
				else
				{
					v4 = (signed int)sub_9CFB8D() % 2;
					result = pActionPlayerSend(v5, v4 + 146, 1);
				}
			}
			else
			{
				result = pActionPlayerSend(v5, 97, 1);
			}
		}
		else
		{
			if(Type == 6)
			{
				result = pActionPlayerSend(v5, 86, 1);
			}
			else
			{
				result = pActionPlayerSend(v5, 155, 1);
			}
		}
	}
	else
	{
		if ( *(BYTE *)(a3 + 40) % 3 )
			pActionPlayerSend(a3 + 776, 4, 1);
		else
			pActionPlayerSend(a3 + 776, 3, 1);
		result = a3;
		++*(BYTE *)(a3 + 40);
	}
	return result;
}

__declspec(naked) void PlayerAnimationHorseMoveSpeed()
{
	static int Type;
	static DWORD RenderPet;
	static DWORD Addr1_JMP = 0x005506D4;
	static DWORD Addr2_JMP = 0x005506D2;
	_asm
	{
		MOV EAX, DWORD PTR SS:[EBP + 0x8]
		MOVSX ECX, WORD PTR DS:[EAX + 0x22C]
		MOV RenderPet, ECX
	}

	Type = recargaNuevoPet(RenderPet);

	if(RenderPet == 0x1E97 || Type == 6 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation1_MoveSpeed()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x00564BB4;
	static DWORD Addr2_JMP = 0x00564C1C;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PET, ECX
	}

	Type = recargaNuevoPet(PET);

	if(PET == 0x1EB8 || Type == 5 ) //-- fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation2_MoveSpeed()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x00564C2D;
	static DWORD Addr2_JMP = 0x00564C55;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PET, ECX
	}

	Type = recargaNuevoPet(PET);

	if(PET == 0x1E97 || Type == 6 ) //-- Horse
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation3_MoveSpeed()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x00564C9C;
	static DWORD Addr2_JMP = 0x00564D08;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PET, ECX
	}

	Type = recargaNuevoPet(PET);

	if( PET == 7829 || PET == 7830 || Type == 7 || Type == 11 ) //dinorant uniria
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation1_Move()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x0054F91A;
	static DWORD Addr2_JMP = 0x0054F8FC;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+8]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV PET, EDX
	}

	Type = recargaNuevoPet(PET);

	if( PET == 0x1EB8 || Type == 5 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation2_Move()
{
	static DWORD PET;
	static DWORD Aguila;
	static int Type;
	static DWORD Addr1_JMP = 0x0054FC8F;
	static DWORD Addr2_JMP = 0x0054FCE9;
	static DWORD Addr3_JMP = 0x0054FD2B;
	static DWORD Addr4_JMP = 0x0054FD5C;
	static DWORD Addr5_JMP = 0x0054FE3B;
	static DWORD Addr6_JMP = 0x0054FF31;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+8]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV PET, EDX
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOV Aguila, ECX
	}

	Type = recargaNuevoPet(PET);

	if(*(WORD *)(Aguila + 676) != 0 && *(BYTE *)(Aguila + 14) == 1 )
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
	else if( PET == 7864 || Type == 5 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else if( PET == 7831 || Type == 6 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else  if( PET == 7829 || Type == 7 )
	{
		_asm
		{
			JMP [Addr4_JMP]
		}
	}
	else if( PET == 7830 || Type == 11 )
	{
		_asm
		{
			JMP [Addr5_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr6_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation3_Move()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x00550717;
	static DWORD Addr2_JMP = 0x00550767;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV PET, EAX
	}

	Type = recargaNuevoPet(PET);

	if( PET == 7864 || Type == 5 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation4_Move()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x00550778;
	static DWORD Addr2_JMP = 0x005507CD;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV PET, EAX
	}

	Type = recargaNuevoPet(PET);

	if( PET == 7864 || Type == 5 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation5_Move()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x005507DE;
	static DWORD Addr2_JMP = 0x00550833;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV PET, EAX
	}

	Type = recargaNuevoPet(PET);

	if( PET == 7864 || Type == 5 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation6_Move()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x00550844;
	static DWORD Addr2_JMP = 0x0055089C;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV PET, EAX
	}

	Type = recargaNuevoPet(PET);

	if( PET == 7864 || Type == 5 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation7_Move()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x005506D4;
	static DWORD Addr2_JMP = 0x00550706;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PET, ECX
	}

	Type = recargaNuevoPet(PET);

	if( PET == 7831 || Type == 6 ) // horse
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation1_Hit()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x0055192B;
	static DWORD Addr2_JMP = 0x00551B09;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV PET, EAX
	}

	Type = recargaNuevoPet(PET);

	if( PET == 7864 || Type == 5 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation2_Hit()
{
	static DWORD PET;
	static int Type;
	static DWORD This;
	static DWORD Addr1_JMP = 0x00551B37;
	static DWORD Addr2_JMP = 0x00551B3F;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV PET, EAX
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOV This, EDX
	}

	Type = recargaNuevoPet(PET);

	if( (PET == 7831 || Type == 6) && *(BYTE *)(This + 14) != 1) // Fenrir
	{
		if ( sub_587950(This) == 1 )
		{
			pActionPlayerSend(This + 776, 101, 1);
		}
		else if ( sub_587950(This) == 2 )
		{
			pActionPlayerSend(This + 776, 98, 1);
		}
		else
		{
			pActionPlayerSend(This + 776, 84, 1);
		}
		_asm
		{
			
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation3_Hit()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x00551B67;
	static DWORD Addr2_JMP = 0x00551D62;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+8]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV PET, EDX
	}

	Type = recargaNuevoPet(PET);

	if( PET == 7829 || PET == 7830 || Type == 7 || Type == 11 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void aceptarbless()
{
	static DWORD ItemIndex;
	static DWORD TargetItem;
	static int Type;
	static DWORD Addr1_JMP = 0x007DBFAE;
	static DWORD Addr2_JMP = 0x007DBFC1;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x70]
		MOVSX EDX,WORD PTR DS:[ECX]
		MOV ItemIndex, EDX
		MOV ECX,DWORD PTR SS:[EBP-0xA8]
		MOV TargetItem, ECX
	}

	Type = recargaNuevoPet(TargetItem + 1171);

	if( ItemIndex == 7181 && TargetItem == 6693 || Type != -1 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void aceptarbless2()
{
	static DWORD TargetItem;
	static int Type;
	static DWORD Addr1_JMP = 0x00838515;
	static DWORD Addr2_JMP = 0x008385C7;

	_asm
	{
		MOV ECX, DWORD PTR SS:[EBP-0x3C]
		MOV TargetItem, ECX
	}

	Type = recargaNuevoPet( TargetItem + 1171 );

	if( TargetItem == 6693 || Type != -1 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

void initmontura()
{
	SetCompleteHook(0xE9, 0x00838508, &aceptarbless2); //-- Player Animation Fenrrir 123 Montar
	SetCompleteHook(0xE9, 0x007DBF94, &aceptarbless); //-- Player Animation Fenrrir 123 Montar
	//-- Action Hit
	SetCompleteHook(0xE9, 0x00551B3F, &PlayerAnimation3_Hit); //-- Player Animation Fenrrir 123 Montar
	SetCompleteHook(0xE9, 0x00551B09, &PlayerAnimation2_Hit); //-- Player Animation Fenrrir 123 Montar
	SetCompleteHook(0xE9, 0x00551916, &PlayerAnimation1_Hit); //-- Player Animation Fenrrir 123 Montar
	//-- Action Running and walk [correr/caminar/nadar]
	SetCompleteHook(0xE9, 0x005506C2, &PlayerAnimation7_Move); //-- Player Animation Fenrrir 123 Montar
	SetCompleteHook(0xE9, 0x00550833, &PlayerAnimation6_Move); //-- Player Animation Fenrrir 123 Montar
	SetCompleteHook(0xE9, 0x005507CD, &PlayerAnimation5_Move); //-- Player Animation Fenrrir 123 Montar
	SetCompleteHook(0xE9, 0x00550767, &PlayerAnimation4_Move); //-- Player Animation Fenrrir 123 Montar
	SetCompleteHook(0xE9, 0x00550706, &PlayerAnimation3_Move); //-- Player Animation Fenrrir 123 Montar
	SetCompleteHook(0xE9, 0x0054FC7D, &PlayerAnimation2_Move); //-- Player Animation Fenrrir 123 Montar
	SetCompleteHook(0xE9, 0x0054F8EA, &PlayerAnimation1_Move); //-- Player Animation Fenrrir 123 Montar
	//-- Action State[espera]
	SetCompleteHook(0xE9, 0x0054EAC8, &SetPlayerAnimation2_Fenrir); //-- Player Animation Fenrrir 123 Montar
	SetCompleteHook(0xE9, 0x0054EC8F, &SetPlayerAnimation2_Horse); //-- Player Animation Horse 78 Montar
	SetCompleteHook(0xE9, 0x0054ED43, &SetPlayerAnimation1_uniria); //-- Player Animation Uniria 13 Montar
	SetCompleteHook(0xE9, 0x0054F6AE, &SetPlayerAnimation3_Fenrir); //-- Player Animation Fenrrir 123 Montar
	//-- Action Skill Execute, Hit, And Run
	SetCompleteHook(0xE9, 0x00552710, &PlayerAnimationMonturaSkill); //-- Player Animation All Skill [SM], [BUFF ELF]
	//SetCompleteHook(0xE9, 0x0054F710, &PlayerAnimation_RUNNING_PET); //-- Player Animation Running, Fix Animation Raven
	//SetCompleteHook(0xE9, 0x005518F0, &PlayerAnimationOneHit); //-- Player Animation [1 HIT][SKILL ELF]
	//--
	//SetCompleteHook(0xE9, 0x005ADB09, &PlayerAnimation_SKILL_POWER_SLASH); //-- Player Animation Skill 56 [Power Slash]
	SetCompleteHook(0xE9, 0x008140C3, &Enabled_SKILL_EARTHQUAKE); //-- Player Animation Skill 238 [Earthquake]
	SetCompleteHook(0xE9, 0x005ADE47, &PlayerAnimation_SKILL_BIRDS1); //-- Player Animation Skill 238 [Birs][Fenrir]
	SetCompleteHook(0xE9, 0x005AE1DD, &PlayerAnimation_SKILL_BIRDS2); //-- Player Animation Skill 238 [Birs]
	SetCompleteHook(0xE9, 0x005AF1D2, &PlayerAnimation_SKILL_FIRE_SCREAM); //-- Player Animation Skill 78 [Fire Screem]
	SetCompleteHook(0xE9, 0x005AF269, &PlayerAnimation_SKILL_EARTHQUAKE); //-- Player Animation Skill 238 [Earthquake]
	SetCompleteHook(0xE9, 0x0064668B, &PlayerAnimation_SKILL_FORCE); //-- Player Animation Skill 60 [Force]
	SetCompleteHook(0xE9, 0x00646724, &PlayerAnimation_SKILL_FIRE_BURST); //-- Player Animation Skill 60 [Force]
	SetCompleteHook(0xE9, 0x00647AF5, &PlayerAnimation_SKILL_BUFF_SUM); //-- Player Animation Skill 217,218,219 [SUM]
	//-- Skill Rare
	SetCompleteHook(0xE9, 0x005B3B8F, &PlayerAnimation_SKILL_STERN); //-- Player Animation 86
	SetCompleteHook(0xE9, 0x005B3875, &PlayerAnimation_SKILL_REMOVE_STERN); //-- Player Animation 86
	SetCompleteHook(0xE9, 0x005B3EAF, &PlayerAnimation_SKILL_GREATER_MANA);
	//-- Increase Speed Move
	SetCompleteHook(0xE9, 0x00564BA2, &PlayerAnimation1_MoveSpeed); //-- Player Animation Fenrir
	SetCompleteHook(0xE9, 0x00564C1C, &PlayerAnimation2_MoveSpeed); //-- Player Animation Horse
	SetCompleteHook(0xE9, 0x00564C8A, &PlayerAnimation3_MoveSpeed); //-- Player Animation Uniria/Dinorant
	//-- Guardian Angel
	SetCompleteHook(0xE9, 0x005033EB, &AngelAnimacionPet);
	//-- Animación Skill 84
	SetCompleteHook(0xE9, 0x005517A4, &SetPlayerAnimation3_uniria); //-- Player Animation Uniria 84
	//-- Animación Skill 82
	SetCompleteHook(0xE9, 0x0055D1C7, &SetPlayerAnimation5); //-- Player Animation Horse 82 Skill Fire Scream OK
	//-- Fenrir Effect
	SetCompleteHook(0xE9, 0x005E0349, &SetEffect_Fenrir);
	//-- PetScale View
	SetOp((LPVOID)0x005F820C, DrawObjectDropOnViewport, ASM::CALL);
	//-- Pet Horse
	SetCompleteHook(0xE9, 0x005AF536, &SetPlayerAnimation9); //-- Player Animation Horse 85 Skill Increase Critical
	SetCompleteHook(0xE9, 0x005528B6, &SetHorsePlayer5); //-- HORSE ok
	SetCompleteHook(0xE9, 0x005964D6, &SetMontDarkHorse4); //HORSE ok
	SetCompleteHook(0xE9, 0x005A3817, &SetMontDarkHorse5); //HORSE ok
	SetCompleteHook(0xE9, 0x007DFDBF, &SetMontDarkHorse6); //HORSE ok
	SetCompleteHook(0xE9, 0x00501860, &FollowMoveAllPet); //Personaje se mueva con el pet
}