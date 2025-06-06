#pragma once
#include "UITextInputBox.h"

#define MAX_ID_SIZE								10
#define MAX_PERSONAL_SIZE						14
#define MAX_PASSWORD_SIZE						20
#define SIZE_PROTOCOLVERSION					( 5)
#define SIZE_PROTOCOLSERIAL						( 16)
//--
#define	REQUEST_JOIN_SERVER						0
#define RECEIVE_JOIN_SERVER_WAITING				1	// 인증서버가 바쁘니 대기하라.
#define	RECEIVE_JOIN_SERVER_SUCCESS				2
#define	RECEIVE_JOIN_SERVER_FAIL_VERSION		3
#define	REQUEST_CREATE_ACCOUNT					10	// 사용안함.
#define	RECEIVE_CREATE_ACCOUNT_SUCCESS			11	// 사용안함.
#define	RECEIVE_CREATE_ACCOUNT_FAIL_ID			12	// 사용안함.
#define	RECEIVE_CREATE_ACCOUNT_FAIL_RESIDENT	13	// 사용안함.
#define	REQUEST_LOG_IN					        19
#define	RECEIVE_LOG_IN_SUCCESS			        20
#define	RECEIVE_LOG_IN_FAIL_PASSWORD	        21
#define	RECEIVE_LOG_IN_FAIL_ID			        22
#define RECEIVE_LOG_IN_FAIL_ID_CONNECTED        23
#define RECEIVE_LOG_IN_FAIL_SERVER_BUSY         24
#define RECEIVE_LOG_IN_FAIL_ID_BLOCK            25
#define RECEIVE_LOG_IN_FAIL_VERSION				26
#define RECEIVE_LOG_IN_FAIL_CONNECT				27
#define RECEIVE_LOG_IN_FAIL_ERROR				28
#define RECEIVE_LOG_IN_FAIL_USER_TIME1          29
#define RECEIVE_LOG_IN_FAIL_USER_TIME2          30
#define RECEIVE_LOG_IN_FAIL_PC_TIME1            31
#define RECEIVE_LOG_IN_FAIL_PC_TIME2            32
#define RECEIVE_LOG_IN_FAIL_DATE				33	// 사용 안함.
#define RECEIVE_LOG_IN_FAIL_POINT_DATE			34	// 대만 전용
#define RECEIVE_LOG_IN_FAIL_POINT_HOUR			35	// 대만 전용
#define RECEIVE_LOG_IN_FAIL_INVALID_IP			36	// 대만 전용
#define RECEIVE_LOG_IN_FAIL_NO_PAYMENT_INFO		37
#define RECEIVE_LOG_IN_FAIL_ONLY_OVER_15		38

#define MESSAGE_FREE_MSG_NOT_BTN				91
#define CREATE_ACCOUNT_FAIL_ID					0
#define CREATE_ACCOUNT_SUCCESS					1
#define CREATE_ACCOUNT_FAIL_RESIDENT			2
#define CREATE_ACCOUNT_FAIL_CAPTCHA				8
#define CREATE_ACCOUNT_FAIL_USERID				9
#define CREATE_ACCOUNT_FAIL_PASSWORD			10
#define CREATE_ACCOUNT_FAIL_PERSOCODE			11

typedef void (*PUSHEVENT_CALLBACK_LPVOID)(LPVOID);

#define CurrentProtocolState			*(int*)0x87935A4
#define FindText2						((bool(__cdecl*)(char *Text,char *Token,bool First)) 0x00512DC0)
#define CharMakeWin						((int(*)()) 0x00482B70)
#define PopUpMsgWin						((void(__thiscall*)(int thisa, int nMsgCode, char* pszMsg)) 0x00484A10)
#define CUIMngShowWin					((int(__thiscall*)(int thisa, BYTE* pWin)) 0x00483B20)
#define CUIMngHideWin					((int(__thiscall*)(int thisa, BYTE* pWin)) 0x00483B50)
#define MouseLButton					*(bool*)0x8793386
#define FontHeight						*(DWORD *)0x81C0380
#define RenderImageD					((void(__cdecl*)(int ModelID, float X, float Y, float W, float H, float CurrentX, float CurrentY)) 0x00790E40)

class CRegisterForm
{
public:
	CRegisterForm(void);
	virtual ~CRegisterForm(void);
	void Create(BYTE* thisa);
	void Show(bool bShow);
	bool CheckShow();
	void RenderForm();
	void GenerateCaptcha();
	void GiveFocus(BYTE bIndex, BOOL bSel);
	void SetPosicion(int x, int y);
	void RequestAccount(BYTE code);
	static void RequestRegister(LPVOID pClass);
	static void CloseFormRegister(LPVOID pClass);
	void RenderUI2DButton2(float x,float y,float w,float h, char * text, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc);

	void RenderUI2DButton1(int IMGcode, float x, float y, float w, float h, float uw, float uh, float a8, float a9, PUSHEVENT_CALLBACK_LPVOID pCallbackFunc);
	void RenderUI2DButton3(int IMGcode, float x, float y, float w, float h, float uw, float uh, float a8, float a9);
	BYTE* CWin;
	BYTE CodeAction;
	char reCaptcha2[12];
private:
	POINT m_Pos;
	int vk_timer2D;
	bool bShowRegister;
	char reCaptcha[7];
	//--
	CUITextInputBox * sprInputBox;
	CUITextInputBox * sprInputBoxPass;
	CUITextInputBox * sprInputBoxEmail;
	CUITextInputBox * sprInputBoxPersonal;
	CUITextInputBox * sprInputBoxCaptcha;
};

