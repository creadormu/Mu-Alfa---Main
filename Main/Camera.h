#pragma once

struct CAMERA_ZOOM
{
	float MinPercent;
	float MaxPercent;
	float MinLimit;
	float MaxLimit;
	float Precision;
};

struct CAMERA_ADDR
{
	float* Zoom;
	float* RotX;
	float* RotY;
	double* PosZ;
	double* ClipX[2];
	float* ClipY[2];
	float* ClipGL;
};

struct CAMERA_INFO
{
	int IsLoad;
	float Zoom;
	float RotX;
	float RotY;
	double PosZ;
	double ClipX[2];
	float ClipY[2];
	float ClipGL;
};

class CCamera
{
public:
	CCamera();
	virtual ~CCamera();
	void Toggle();
	void Restore();
	void SetIsMove(BOOL IsMove);
	void SetCursorX(LONG CursorXC);
	void SetCursorY(LONG CursorYC);
	void Zoom(MOUSEHOOKSTRUCTEX* lpMouse);
	void Move(MOUSEHOOKSTRUCTEX* lpMouse);
	void SetCurrentValue();
	void SetDefaultValue();
	bool getEnabled();
	static void RotateDmg(float& X, float& Y, float D);
	static void RotateFix();
private:
	BOOL m_Enable;
	BOOL m_IsMove;
	LONG m_CursorX;
	LONG m_CursorY;
	CAMERA_ZOOM m_Zoom;
	CAMERA_ADDR m_Address;
	CAMERA_INFO m_Default;
};

extern CCamera gCamera;