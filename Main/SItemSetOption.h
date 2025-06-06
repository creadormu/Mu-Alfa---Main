#pragma once
#define MAX_CLASS_OPTION      7
#define MAX_SET_OPTION         512

typedef struct
{
   char   strSetName[64];
   BYTE   byStandardOption[6][2];
   BYTE   byStandardOptionValue[6][2];
   BYTE   byExtOption[2];
   BYTE   byExtOptionValue[2];
   BYTE   byOptionCount;
   BYTE   byFullOption[5];
   BYTE   byFullOptionValue[5];
   BYTE   byRequireClass[MAX_CLASS_OPTION];
} ITEM_SET_OPTION;

class CSItemSetOption
{
public:
   CSItemSetOption(void);
   virtual ~CSItemSetOption(void);
   void Init();
   ITEM_SET_OPTION m_ItemSetOption[MAX_SET_OPTION];
};

extern CSItemSetOption g_csItemOption;