// Fix
#define MAX_ITEM_INFO 350

// Fix
struct PMSG_ITEM_CHANGE_RECV
{
	PBMSG_HEAD header; // C1:25
	BYTE index[2];
	BYTE ItemInfo[MAX_ITEM_INFO];
};

typedef void(__thiscall *ObjCreatePet)(int ItemId);
extern ObjCreatePet gObjCreatePet;

typedef int(__cdecl *ObjCreateBug)(int BugId, int Arg2, int Arg3, int Arg4, int Arg5);
extern ObjCreateBug gObjCreateBug;

void gObjCreatePetExHook();