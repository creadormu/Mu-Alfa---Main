#pragma pack(pop)

#define pGetItemAtt(id, offset)	(*(DWORD*)0x8128AC0 + 84 * id + offset) //1.04D || 1.04E may be -0x150

#pragma pack(push, 1)
typedef struct	//-> Complete (size: 107)
{
	/*+0*/		short	ItemID;
	/*+2*/		int		Level;
	/*+6*/		char	Unknown6;
	/*+7*/		char	Unknown7;
	/*+8*/		char	Unknown8;
	/*+9*/		WORD	DamageMin;
	/*+11*/		WORD	DamageMax;
	/*+13*/		char	Unknown13;
	/*+14*/		WORD	Defense;
	/*+16*/		WORD	MagicDefense;
	/*+18*/		WORD	MagicPower;
	/*+19*/		char	Unknown19;
	/*+20*/		short	Unknown20;
	/*+22*/		char	Durability;
	/*+23*/		char	ExcellentOption;
	/*+24*/		char	AncientOption;
	/*+25*/		short	ReqStrenght;
	/*+27*/		short	ReqDextirity;
	/*+29*/		short	ReqEnergy;
	/*+31*/		short	ReqVitality;
	/*+33*/		short	ReqCommand;
	/*+35*/		short	ReqLevel;
	/*+37*/		char	SpecialCount;
	/*+38*/		WORD	SpecialType[8];
	/*+54*/		BYTE	SpecialValue[8];
	/*+62*/		int		UniqueID;
	/*+66*/		char	Unknown66;
	/*+67*/		char	PosX;
	/*+68*/		char	PosY;
	/*+69*/		WORD	HarmonyType;
	/*+71*/		short	HarmonyValue;
	/*+73*/		char	Is380Item;
	/*+74*/		char	SocketOption[5];
	/*+79*/		char	Unknown79;
	/*+80*/		char	SocketSeedIndex[5];
	/*+85*/		char	SocketSphereLevel[5];
	/*+90*/		char	SocketSet;
	BYTE gap01[5];
	/*+96*/		char	DurabilityState;
	/*+97*/		char	PeriodItem;
	/*+98*/		char	ExpiredItem;
	/*+99*/		int		ExpireDateConvert;
	/*+103*/	int		Unknown103;
} ObjectItemRender, * lpItemObjRender;
#pragma pack(pop)

#define pSetItemOption ((void(__cdecl*)(ObjectItemRender * lpItem, BYTE Option, BYTE Special, BYTE Value)) 0x0058B910) //1.04D || 1.04E may be -0x150


class cItemInfoEx
{
public:
	cItemInfoEx();
	~cItemInfoEx();
	void Load();
	// ----
public:
}; extern cItemInfoEx gItemInfoEx;