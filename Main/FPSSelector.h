// FPSSelector.h: FPS Selection Dialog with OpenGL Shader Support
#pragma once

#include <windows.h>

#define FPS_MODE_40  40  // ~26 FPS (Original)
#define FPS_MODE_60  17  // ~60 FPS
#define FPS_MODE_120 8   // ~120 FPS

class CFPSSelector
{
public:
    CFPSSelector();
    virtual ~CFPSSelector();
    
    bool ShowFPSDialog();
    void InitializeShaders();
    void InitializeVSync();
    DWORD GetSelectedFPS();
    bool LoadShaderFile(const char* filename, char** shaderSource);
    
private:
    static INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
    DWORD m_SelectedFPS;
    bool m_ShadersLoaded;
    bool m_VSyncEnabled;
};

extern CFPSSelector gFPSSelector;
