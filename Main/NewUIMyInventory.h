#pragma once

#include "NewUIButton.h"
#include "Protocol.h"

#define MAX_BUTTERFLES                10
#define MODEL_FENRIR_BLACK              384
#define MODEL_FENRIR_RED              385
#define MODEL_FENRIR_BLUE             386
#define MODEL_FENRIR_GOLD             387
#define MODEL_DARK_HORSE              226
#define MODEL_PEGASUS               323
#define MODEL_UNICON                233
#define MODEL_BUTTERFLY01             176
#define MODEL_HELPER                7827
#define MUUN_INVENTORY_SIZE             62
#define MAX_EQUIPMENT_INDEX             2
#define IMAGE_INVENTORY_BACK            661522
#define IMAGE_FRAME_I3                961630
#define IMAGE_PETINVENTORY_FRAME_I4         661631
#define IMAGE_MENU_BUTTON03             661632
#define IMAGE_MENU_BUTTON04             661633
#define INVENTORY_SQUARE_COL            4
#define INVENTORY_SQUARE_FIL            5
#define INVENTORY_WIDTH               190
#define INVENTORY_HEIGHT              429
#define MAX_ITEM_INFO               12
#define EQUIPMENT_MAIN_INDEX            0
#define EQUIPMENT_SUB_INDEX             1
#define MAX_SOCKETS                 5
#define MAX_ITEM_SPECIAL              8
#define ITEMDEF(x,y)                ((x * 512) + y)


typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec34_t[3][4];

typedef struct
{
  vec3_t StartPos;
  vec3_t XAxis;
  vec3_t YAxis;
  vec3_t ZAxis;
} OBB_t_ok;

struct OBJECT
{
  BYTE arg[4];
  /*+4*/  bool          Live;
  /*+5*/  bool          bBillBoard;
  /*+6*/  bool          m_bCollisionCheck;    //  충돌 체크 할까?
  /*+7*/  bool          m_bRenderShadow;      //  그림자를 찍을까? 말까?
  /*+8*/  bool          EnableShadow;
  /*+9*/  bool      LightEnable;
  /*+10*/ bool      m_bActionStart;
  /*+11*/ bool      m_bRenderAfterCharacter;
  /*+12*/ bool        Visible;
  /*+13*/ bool        AlphaEnable;
  /*+14*/ bool          EnableBoneMatrix;
  /*+15*/ bool      ContrastEnable;
  /*+16*/ bool          ChromeEnable;
  /*+17*/ unsigned char AI;
  /*+18*/ unsigned short CurrentAction;
  /*+19*/ unsigned short PriorAction;
  /*+20*/   BYTE          ExtState;
  /*+21*/   BYTE          Teleport;
  /*+22*/   BYTE          Kind;
  /*+23*/   WORD    Skill;
  /*+24*/   BYTE      m_byNumCloth;       // 천 개수
  /*+25*/   BYTE      m_byHurtByOneToOne;
  /*+26*/   BYTE          WeaponLevel;
  /*+27*/   BYTE          DamageTime;       //  공격을 받은 충격 시간.
  /*+28*/   BYTE          m_byBuildTime;
  /*+29*/   BYTE      m_bySkillCount;
  /*+30*/   BYTE      m_bySkillSerialNum;
  /*+31*/   BYTE      Block;
  /*+32*/ void*     m_pCloth; // 천 붙이기
  /*+40*/ short         ScreenX;
  /*+42*/ short         ScreenY;
  /*+44*/ short         PKKey;
  /*+46*/ short         Weapon;
  /*+48*/ int       Type;
  /*+52*/ int           SubType;
  /*+56*/ int       m_iAnimation;       // 펜릴 발바닥 관련 에니메이션 키값
  /*+60*/ int           HiddenMesh;
  /*+64*/ int           LifeTime;
  /*+68*/ int           BlendMesh;
  int           AttackPoint[2];
  int           RenderType;
  int       InitialSceneFrame;
  int           LinkBone;
  /*92*/    DWORD     m_dwTime;
  /*+96*/   float         Scale;
  /*+100*/  float         BlendMeshLight;
  /*+104*/  float         BlendMeshTexCoordU;
  /*+108*/  float         BlendMeshTexCoordV;
  /*+112*/  float         Timer;
  /*+116*/  float         m_fEdgeScale;       //  외곽선 스케일.  
  /*+120*/  float         Velocity;
  /*+124*/  float     CollisionRange;
  /*+128*/  float         ShadowScale;
  /*+132*/  float         Gravity;
  /*+136*/  float         Distance;
  /*+140*/  float         AnimationFrame;
  /*+144*/  float         PriorAnimationFrame;
  /*+148*/  float       AlphaTarget;
  /*+152*/  float         Alpha;
  vec3_t        Light;
  vec3_t        Direction;
  vec3_t      m_vPosSword;        // 칼끝 위치
  vec3_t      StartPosition;      // bullet
  vec3_t        BoundingBoxMin;
  vec3_t        BoundingBoxMax;
  vec3_t      m_vDownAngle;
  vec3_t      m_vDeadPosition;
  /*+252*/  vec3_t        Position;
  /*+264*/  vec3_t      Angle;
  vec3_t      HeadAngle;
  vec3_t        HeadTargetAngle;
  vec3_t      EyeLeft;
  vec3_t      EyeRight;
  vec3_t      EyeLeft2;
  vec3_t      EyeRight2;
  vec3_t      EyeLeft3;
  vec3_t      EyeRight3;
  vec34_t     Matrix;
  vec34_t       *BoneTrans;
  OBB_t_ok      OBB;
  OBJECT        *Owner;
  OBJECT      *Prior;
  OBJECT      *Next;
  BYTE      m_BuffMap[134];
  short int   m_sTargetIndex;
  BOOL      m_bpcroom;
  vec3_t      m_v3PrePos1;
  vec3_t      m_v3PrePos2;
};

struct PMSG_MUUN_ITEM_GET_RECV
{
  PSBMSG_HEAD header; // C3:4E:00
  BYTE result;
  BYTE ItemInfo[MAX_ITEM_INFO];
};

struct PMSG_MUUN_ITEM_LIST_RECV
{
  PSWMSG_HEAD header; // C4:4E:02
  BYTE count;
};

struct PMSG_MUUN_ITEM_LIST
{
  BYTE slot;
  BYTE ItemInfo[MAX_ITEM_INFO];
};

struct PMSG_MUUN_ITEM_DUR_RECV
{
  PSBMSG_HEAD header; // C1:4E:03
  BYTE slot;
  BYTE dur;
};

struct PMSG_MUUN_ITEM_DELETE_RECV
{
  PSBMSG_HEAD header; // C1:4E:04
  BYTE slot;
  BYTE flag;
};

struct PMSG_MUUN_ITEM_MODIFY_RECV
{
  PSBMSG_HEAD header; // C1:4E:05
  BYTE flag;
  BYTE slot;
  BYTE ItemInfo[MAX_ITEM_INFO];
};

struct PMSG_MUUN_ITEM_CHANGE_RECV
{
  PSBMSG_HEAD header; // C1:4E:06
  BYTE index[2];
  BYTE ItemInfo[MAX_ITEM_INFO];
};

struct PMSG_MUUN_ITEM_STATUS_SEND
{
  PSBMSG_HEAD header; // C1:4E:07
  BYTE slot;
  BYTE status;
};

struct PMSG_MUUN_ITEM_USE_RECV
{
  PSBMSG_HEAD header; // C1:4E:08
  BYTE result;
  BYTE type;
};

struct PMSG_MUUN_ITEM_SELL_RECV
{
  PSBMSG_HEAD header; // C1:4E:09
  BYTE result;
  DWORD money;
};
//--
struct PMSG_MUUN_ITEM_USE_SEND
{
  PSBMSG_HEAD header; // C1:4E:08
  BYTE SourceSlot;
  BYTE TargetSlot;
  BYTE type;
};

struct PMSG_MUUN_ITEM_SELL_SEND
{
  PSBMSG_HEAD header; // C3:4E:09
  BYTE slot;
};

struct PMSG_MUUN_ITEM_DROP_SEND
{
  PSBMSG_HEAD header; // C1:4E:08
  BYTE x;
  BYTE y;
  BYTE slot;
};

struct PMSG_MUUN_ITEM_DROP_RECV
{
  PSBMSG_HEAD header; // C1:4E:09
  BYTE result;
  BYTE slot;
};

#pragma pack(push, 1)
typedef struct tagITEM  //-> Complete (size: 107)
{
  /*+0*/    WORD  Type;
  /*+2*/    int   Level;
  /*+6*/    BYTE  Part;
  /*+7*/    BYTE  Class;
  /*+8*/    bool  TwoHand;
  /*+9*/    WORD  DamageMin;
  /*+11*/   WORD  DamageMax;
  /*+13*/   BYTE  SuccessfulBlocking;
  /*+14*/   WORD  Defense;
  /*+16*/   WORD  MagicDefense;
  /*+18*/   BYTE  MagicPower;
  /*+19*/   BYTE  WeaponSpeed;
  /*+20*/   WORD  WalkSpeed;
  /*+22*/   BYTE  Durability;
  /*+23*/   BYTE  Option1;
  /*+24*/   BYTE  ExtOption;
  /*+25*/   WORD  RequireStrength;
  /*+27*/   WORD  RequireDexterity;
  /*+29*/   WORD  RequireEnergy;
  /*+31*/   WORD  RequireVitality;
  /*+33*/   WORD  RequireCharisma;
  /*+35*/   WORD  RequireLevel;
  /*+37*/   BYTE  SpecialNum;
  /*+38*/   WORD  Special[MAX_ITEM_SPECIAL];
  /*+54*/   BYTE  SpecialValue[MAX_ITEM_SPECIAL];
  /*+62*/   DWORD Key;
  /*+66*/   BYTE  bySelectedSlotIndex;
  /*+67*/   BYTE  PosX;
  /*+68*/   BYTE  PosY;
  /*+69*/   WORD  Jewel_Of_Harmony_Option;
  /*+71*/   WORD  Jewel_Of_Harmony_OptionLevel;
  /*+73*/   bool  option_380;
  /*+74*/   BYTE  bySocketOption[MAX_SOCKETS];
  /*+79*/   BYTE  SocketCount;
  /*+80*/   BYTE  SocketSeedID[MAX_SOCKETS];
  /*+85*/   BYTE  SocketSphereLv[MAX_SOCKETS];
  /*+90*/   BYTE  SocketSeedSetOption;
  int   Number;
  BYTE  Color;
  /*+96*/   BYTE  byColorState;
  /*+97*/   bool  PeriodItem;
  /*+98*/   bool  ExpiredItem;
  /*+99*/   int   lExpireTime;
  /*+103*/  int   RefCount;
} ITEM;
#pragma pack(pop)
typedef struct
{
  char Name[30];
  /*+30*/ bool TwoHand;
  /*+32*/ WORD Level;
  /*+34*/ BYTE m_byItemSlot;
  /*+36*/ WORD m_wSkillIndex;
  /*+38*/ BYTE Width;
  /*+39*/ BYTE Height;
  /*+40*/ BYTE DamageMin;
  /*+41*/ BYTE DamageMax;
  /*+42*/ BYTE SuccessfulBlocking;
  /*+43*/ BYTE Defense;
  /*+44*/ BYTE MagicDefense;
  /*+45*/ BYTE WeaponSpeed;
  /*+46*/ BYTE WalkSpeed;
  /*+47*/ BYTE Durability;
  /*+48*/ BYTE MagicDur;
  /*+49*/ BYTE MagicPower;
  /*+50*/ WORD RequireStrength;
  /*+52*/ WORD RequireDexterity;
  /*+54*/ WORD RequireEnergy;
  /*+56*/ WORD  RequireVitality;
  /*+58*/ WORD RequireCharisma;
  /*+60*/ WORD RequireLevel;
  /*+62*/ BYTE Value;
  /*+64*/ int  iZen;
  /*+68*/ BYTE  AttType;
  /*+69*/ BYTE RequireClass[7];
  /*+77*/ BYTE Resistance[7];
} ITEM_ATTRIBUTE;

typedef std::map<int, ITEM*> type_vec_item;

#define Hero                    *(DWORD*)0x007BC4F04
//-- OpenGL
#define EnableAlphaTest               ((void  (__cdecl*)(bool Mode)) 0x00635FD0)
#define DisableAlphaBlend             ((void  (__cdecl*)( )) 0x00635F50)
#define RenderItem3D                ((int(__cdecl*)(float sx,float sy,float Width,float Height,int Type,int Level,int Option1,int ExtOption,bool PickUp)) 0x005CF310)
#define BeginBitmap                 ((void(*)()) 0x00637770)
#define EndBitmap                 ((void(*)()) 0x00637870)
#define CameraViewNear                *(float*)0xE61E38
#define CameraViewFar               *(float*)0xE61E3C
#define glViewport2                 ((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x006363D0)
#define gluPerspective_2              ((int(__cdecl*)(float a1, float a2, float a3, float a4)) 0x006358A0)
#define GetOpenGLMatrixF              ((void(__cdecl*)(LPVOID a1)) 0x00635830)
#define EnableDepthTestF              ((void(*)()) 0x00635DE0)
#define EnableDepthMaskF              ((void(*)()) 0x00635E40)
#define CameraMatrixF               (LPVOID)0x87933A0
#define g_WindowWidth               0x00E61E58
#define g_WindowHeight                0x00E61E5C
#define g_fScreenRate_x               *(float*)0x00E7C3D4
#define g_fScreenRate_y               *(float*)0x00E7C3D8
//-- Pick Item
#define GetUI3D                   ((int   (__thiscall*)(int thisa))0x00861AA0)

#define ms_pPickedItem                *(DWORD*)0x9816F7C
#define GetPickedItem               ((int   (*)( )) 0x007DD0F0)
#define DeletePickedItem              ((void  (*)( )) 0x007DD1B0)
#define GetMouseItem                ((ITEM* (__thiscall*)(int thisa)) 0x007D9430)
#define CreateItemPick                ((ITEM* (__stdcall*)(ITEM*)) 0x007E1E50)
#define SetPickItem                 ((bool  (__cdecl*)(int a4, const void *a5)) 0x007DD100)
#define CInventoryProcess             ((bool  (__thiscall*)(int thisa))0x00838240)
#define GetSourceLinealPos              ((int(__thiscall*)(int thisa))0x007D94E0)
#define MoveToFromRecv                ((int   (__cdecl*)(int a4, int a5)) 0x0064B860)
#define RenderItemInfo                ((void  (__thiscall*)(int thisa, int sx,int sy,ITEM *ip,bool Sell, int Inventype, bool bItemTextListBoxUse)) 0x007E3E30)
#define SendRequestEquipmentItem          ((char  (__cdecl*)(BYTE SourceFlag, BYTE SourceSlot, ITEM* pItem, BYTE TargetFlag, BYTE TargetSlot)) 0x005BD850)
//-- User
#define CList                   ((int   (*)( )) 0x00402BC0)
#define sub_58AA80                  ((int   (__cdecl*)(DWORD)) 0x58AA80)
#define FindCharacterIndex              ((int   (__cdecl*)(int a1)) 0x0057D9A0)
#define CharactersClient              ((int   (__thiscall*)(int List, int num)) 0x0096A4C0)
//-- Action Pet
#define CheckActionPet                ((bool  (__thiscall*)(LPVOID thisa, int type)) 0x00925700)
#define DelectePetAction              ((int   (__thiscall*)(LPVOID thisa,int a1, short a2)) 0x009253D0)
#define CreatePetAction               ((int   (__thiscall*)(void * thisa, int IndexPet, int IndexItemModel, vec3_t Posicion, int a4, int pHero, int a6)) 0x009250E0)
#define CreateBug                 ((void  (__cdecl*)(int Type, vec3_t Position, OBJECT *Owner, int SubType, int LinkBone)) 0x00501700)
#define CreateBugSub                ((bool  (__cdecl*)(int Type, vec3_t Position, OBJECT *Owner, int SubType, int LinkBone)) 0x005013B0)
#define DeleteBug                 ((void  (__cdecl*)(OBJECT *Owner)) 0x005012D0)
//-- Control UI
#define IsRepeat                  ((bool  (__cdecl*)(int iVirtKey))0x00791090)
#define IsRelease                 ((bool  (__cdecl*)(int iVirtKey))0x00791050)
#define IsPress                   ((bool  (__cdecl*)(int iVirtKey))0x00791070)
//--
#define pCheckInMouse               ((bool  (__cdecl*)(int sx, int sy, int sw, int sh)) 0x00790B10)
#define CGetScreenWidth2              ((int   (*)( )) 0x005C6E80)
#define RenderRight                 ((bool  (__thiscall*)(int thisa)) 0x007DF950)
#define CreateInventoryCTRL             ((bool  (__thiscall*)(int thisa, int a5, int a6, int a7, int a8, int a9, int col, int fil)) 0x007D9ED0)
#define BPlaySound                  ((int   (__cdecl*)(int Sound, int o, int a3))0x006D6C20)
#define g_pNewUISystem                ((int   (*)( )) 0x00861110)
#define IsVisible                 ((bool  (__thiscall*)(int This, int Code)) 0x0085EC20)
#define CreateItemConvertByte           ((ITEM* (__thiscall*)(int a1, void *lp)) 0x007E1B10)
#define RBitmaps                  ((void  (__cdecl*)(int Texture,float x,float y,float Width,float Height,float u,float v,float uWidth,float vHeight,bool Scale,bool StartScale,float Alpha)) 0x00637C60)
#define LoadBitmapA                 ((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define SelectXF                  *(float*)0x82C6A9C
#define SelectYF                  *(float*)0x82C6A98
#define CollisionPosition_1             *(float*)0x8793248
#define CollisionPosition_2             *(float*)0x879324C
#define TERRAIN_SCALE               100.0f
#define MouseUpdateTime               *(DWORD*)0x81C03B4
#define MouseUpdateTimeMax              *(DWORD*)0xE616D0
#define ResetMouseLButton             ((void(__cdecl*)( ))0x83C080)
#define RenderTerrain               ((void(__cdecl*)(bool EditFlag))0x005DC820)
#define RenderTerrainTile             ((bool(__cdecl*)(float xf, float yf, int xi, int yi, float lodf, int lodi, bool Flag))0x005DA250)


#define RenderNumArrow                ((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E02B0)
#define RenderEquipedHelperLife           ((bool(__stdcall*)(int iX, int iY)) 0x007DFDB0)
#define RenderEquipedPetLife            ((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E0180)
#define RenderSummonMonsterLife           ((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E0220)
#define CreateBarHP                 ((int(__stdcall*)(int PosX, int PosY, char * name, int currentLife, int MaxLife, bool a6)) 0x007DFA60)
#define Defineclass                 ((int(__cdecl*)(BYTE userclass)) 0x00405230)
#define pItem_Attribute               *(DWORD*)0x8128AC0

class CNewUIMyInventory
{
public:
  enum ITEM_COLORSTATE
  {
    ITEM_COLOR_NORMAL = 0,
    ITEM_COLOR_DURABILITY_50,
    ITEM_COLOR_DURABILITY_70,
    ITEM_COLOR_DURABILITY_80,
    ITEM_COLOR_DURABILITY_100,
    ITEM_COLOR_TRADE_WARNING,
  };
  CNewUIMyInventory();
  virtual ~CNewUIMyInventory();
  //-- Render
  void Init();
  static void LoadImages();
  //-- Create
  bool UpdateMouseEvent();
  int MoveToInvetoryMuun(int Packet, int Engine);
  static bool __thiscall InventoryProcess(int thisa);
  static bool __thiscall CRenderInterfaceRight(int thisa);
  void __thiscall CRenderInterfaceLeft(int thisa);
  static bool __thiscall CreateInventoryUICTRL(int thisa, int a5, int a6, int a7, int a8, int a9, int col, int fil);
  //--
  BYTE RenderEquipedMuunLife(int iX, int iY, int Slot);
  BYTE PetEquipedHPBar(int iX, int iY);
  bool CheckMuunInventoryOver();
  void SetPos(int x, int y);
  void RenderFrame();
  void RenderWindows();
  //void RenderDetails();
  void RenderEquippedItem();
  void RenderInventoryCtrl();
  void InventoryCtrlRender3D();
  //-- Protocolo
  void ItemGetRecv(PMSG_MUUN_ITEM_GET_RECV *lpMsg);
  void ItemListRecv(PMSG_MUUN_ITEM_LIST_RECV* lpMsg);
  void ItemSetDur(PMSG_MUUN_ITEM_DUR_RECV* lpMsg);
  void ItemModifyRecv(PMSG_MUUN_ITEM_MODIFY_RECV *lpMsg);
  void ItemDropRecv(PMSG_MUUN_ITEM_DROP_RECV *lpMsg);
  void ItemChangeRecv(PMSG_MUUN_ITEM_CHANGE_RECV *lpMsg);
  void ItemDeleteRecv(PMSG_MUUN_ITEM_DELETE_RECV *lpMsg);
  void ItemSellRecv(PMSG_MUUN_ITEM_SELL_RECV *lpMsg);
  //-- Funtions
  void SendRequestDropItem(BYTE SlotPick, BYTE tx, BYTE ty);
  void SendRequestSellItem(BYTE SlotPick);
  void SendRequestUsedItem(BYTE SourceSlot, BYTE TargetSlot, BYTE type);
  void CheckTooltipMuun();
  static bool UpdateKeyEvent();
  static void  DelectPetBug(OBJECT * Owner);
  ITEM* FindItemBySlot(DWORD dwKey);
  void EquipMuun(ITEM* TempItem, int Slot);
  void UnEquipMuun(int EQUIPMENT_SLOT, ITEM* MuunPet);
  void AddInventoryCtrl(ITEM* pNewItem, int dwKey);
  void DelInventoryCTRL(int Slot);
  //-- variables
  void CRenderBitmap(int Texture, float x, float y, float Width, float Height, float u = 0.f, float v = 0.f, float uWidth = 1.f, float vHeight = 1.f, bool Scale = true, bool StartScale = true, float Alpha = 0.f);

  void DrawConfirmBox();
public:
  int          g_pdwItemTooltip;
  POINT           m_Pos; //-- WindowsInventario
  SIZE            m_Size;
  type_vec_item   m_vecItem;
  int             InventoryCTRLStatus;
  DWORD           m_pdwItemCheckBox[MUUN_INVENTORY_SIZE];
  int             PageID;
  CNewUIButton    back;
  CNewUIButton    next;
};

extern CNewUIMyInventory g_MuunSystem;
