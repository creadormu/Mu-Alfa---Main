#pragma once
#define sub_7DC2C0 ((int(__thiscall*)(int This, int a2))0x007DC2C0)
#define sub_7D9B50 ((void(__cdecl*)(int a1))0x007D9B50)

#define sub_7853F0 ((BYTE(__cdecl*)(char a4, int a5, int a6, int a7, int a8, int a9, int a10, char a11))0x007853F0)

#define SetOption1					((char(__thiscall*)(int This))0x004EC950)
#define SetOption2					((char(__thiscall*)(int This))0x004EC970)

#define sub_969000					((BOOL(__thiscall*)(void * This))0x00969000)

#define sub_4EC9B0					((char(__thiscall*)(int This))0x004EC9B0)

#define sub_7DC240 ((int(__cdecl*)(int This, flotantes a2))0x007DC240)

void RenderTooltipAncestral_772EA0(int ThisR);
void MoverSlotItem(int This);

#define sub_779350 ((int(__thiscall*)(int This, char a5, int a6, char a7, char a8, char a9))0x00779350)
#define sub_779410 ((int(__thiscall*)(char *This, int X, int Y, int Width, int Height)) 0x00779410)

#define pDrawPuntero ((int(__thiscall*)(int This, char a5, int a6, char a7, char a8, char a9))0x00779350)
#define ChangeButtonInfo ((int(__thiscall*)(char *This, int X, int Y, int Width, int Height)) 0x00779410)

#define GetInstance ((int(__cdecl*)()) 0x00861110)
#define GetUIBaul ((int(__thiscall*)(int This))0x00861360)
#define GetUIBaulExt ((int(__thiscall*)(int This))0x00861A80)
#define getCharacterInfo ((int(__thiscall*)(int This))0x00861440)
#define GetInventory ((int(__thiscall*)(int This))0x00861260)
#define GetInventoryExt ((int(__thiscall*)(int This))0x00861A60)
#define GetChaosBox ((int(__thiscall*)(int a1)) 0x008612C0)
#define pWindowStore ((int(__thiscall*)(int a1)) 0x00861400)

#define CheckInventoryExt ((int(__thiscall*)(int This))0x00513050)

#define sub_587620 ((int(__cdecl*)(char a1)) 0x00587620)
#define sub_5873C0 ((char(__cdecl*)(unsigned __int8 a1)) 0x005873C0)
//----- (008613E0)
#define sub_8613E0 ((int(__thiscall*)(int This))0x008613E0)
//----- (0081C8C0)
#define sub_81C8C0 ((double(__thiscall * )(int a1, int a2))0x0081C8C0)
#define sub_5906E0 ((char(__cdecl*)(int a1))0x005906E0)
#define sub_420150 ((int(__thiscall*)(int This, int a2, int a3, int a4, int a5, int a6, int a7, int a8))0x00420150)
#define sub_83C0C0 ((signed int(__thiscall*)(__int16 a1))0x0083C0C0)
#define sub_7DA7B0 ((int(__thiscall*)(int a1, int a5, int a6))0x007DA7B0)
//----- (007798F0) --------------------------------------------------------
#define sub_7798F0 ((char(__thiscall*)(int This, char a9))0x007798F0)
//----- (00779740) --------------------------------------------------------
#define sub_779740 ((int(__thiscall*)(int This, int a5, int a6))0x00779740)
//-- Innecesarios
#define sub_7DDCC0 ((void *(__cdecl*)(int a1, void * a5))0x007DDCC0)
#define sub_7DDCF0 ((void *(__thiscall*)(int a1))0x007DDCF0)
#define sub_7DDF40 ((BOOL(__thiscall*)(void *a1, int a5))0x007DDF40)
#define sub_7DDEE0 ((void *(__thiscall*)(void **a1))0x007DDF40)
#define sub_7DDF00 ((int(__thiscall*)(int a1, int a5, int a6))0x007DDF00)
#define pAllowRepair ((bool(__cdecl*)(WORD *a1)) 0x005C9DA0)

#define RenderPrintCesto ((void (__stdcall*)(int x, int y, int w, int h)) 0x007F7D60)

#define sub_7DA7E0 ((ObjectItem *(__cdecl*)(int a1, int a2)) 0x007DA7E0)
#define Convert ((double(__cdecl*)(float a1)) 0x004DB0C0)
void PetMuunHP(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9);
bool CheckButtonPressed(int x, int y, int w, int h);
extern int MinimizarPet;
void EventMuOffhelper(DWORD Event);

float TransForX(float num);
float TransForY(float num);
float TransFor2X(float num);
float ReturnX(float num);
float Return2X(float num);
float ReturnY(float num);

void InitSeason15();