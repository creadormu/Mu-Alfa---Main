// FPSSelector.cpp: Implementation of FPS Selector with OpenGL Shader Support
#include "stdafx.h"
#include "FPSSelector.h"
#include "Protect.h"
#include "resource.h"
#include <stdio.h>

CFPSSelector gFPSSelector;

CFPSSelector::CFPSSelector()
{
    m_SelectedFPS = FPS_MODE_40; // Default 40
    m_ShadersLoaded = false;
    m_VSyncEnabled = false;
}

CFPSSelector::~CFPSSelector()
{
}

DWORD CFPSSelector::GetSelectedFPS()
{
    return m_SelectedFPS;
}

bool CFPSSelector::LoadShaderFile(const char* filename, char** shaderSource)
{
    FILE* file = fopen(filename, "rb");
    if (!file)
    {
        return false;
    }
    
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    *shaderSource = (char*)malloc(fileSize + 1);
    if (!*shaderSource)
    {
        fclose(file);
        return false;
    }
    
    fread(*shaderSource, 1, fileSize, file);
    (*shaderSource)[fileSize] = '\0';
    
    fclose(file);
    return true;
}

void CFPSSelector::InitializeShaders()
{
    char* vertexShader = NULL;
    char* fragmentShader = NULL;
    
    // Load shader files
    bool vertexLoaded = LoadShaderFile("Shaders\\vertexshader.vs", &vertexShader);
    bool fragmentLoaded = LoadShaderFile("Shaders\\vertexfragment.fs", &fragmentShader);
    
    if (vertexLoaded && fragmentLoaded)
    {
        m_ShadersLoaded = true;
        // Shaders loaded successfully
        // In a real implementation, you would compile and link these shaders with OpenGL
    }
    
    if (vertexShader) free(vertexShader);
    if (fragmentShader) free(fragmentShader);
}

void CFPSSelector::InitializeVSync()
{
    // Initialize VSync using wglSwapIntervalEXT
    // This requires the VSyncLib.GLIB to be loaded
    typedef BOOL (WINAPI * PFNWGLSWAPINTERVALEXTPROC)(int interval);
    
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;
    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
    
    if (wglSwapIntervalEXT)
    {
        // Enable VSync (1) or disable (0)
        wglSwapIntervalEXT(1);
        m_VSyncEnabled = true;
    }
}

INT_PTR CALLBACK CFPSSelector::DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
        {
            // Center the dialog
            RECT rc;
            GetWindowRect(hwndDlg, &rc);
            int x = (GetSystemMetrics(SM_CXSCREEN) - (rc.right - rc.left)) / 2;
            int y = (GetSystemMetrics(SM_CYSCREEN) - (rc.bottom - rc.top)) / 2;
            SetWindowPos(hwndDlg, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
            
            // Set default selection to 60 FPS
            CheckRadioButton(hwndDlg, 1001, 1003, 1002);
            
            return TRUE;
        }
        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDOK:
                {
                    // Get selected FPS
                    if (IsDlgButtonChecked(hwndDlg, 1001) == BST_CHECKED)
                    {
                        gFPSSelector.m_SelectedFPS = FPS_MODE_40;
                    }
                    else if (IsDlgButtonChecked(hwndDlg, 1002) == BST_CHECKED)
                    {
                        gFPSSelector.m_SelectedFPS = FPS_MODE_60;
                    }
                    else if (IsDlgButtonChecked(hwndDlg, 1003) == BST_CHECKED)
                    {
                        gFPSSelector.m_SelectedFPS = FPS_MODE_120;
                    }
                    
                    EndDialog(hwndDlg, IDOK);
                    return TRUE;
                }
                
                case IDCANCEL:
                {
                    gFPSSelector.m_SelectedFPS = FPS_MODE_40; // Default
                    EndDialog(hwndDlg, IDCANCEL);
                    return TRUE;
                }
            }
            break;
        }
        
        case WM_CLOSE:
        {
            gFPSSelector.m_SelectedFPS = FPS_MODE_40; // Default
            EndDialog(hwndDlg, IDCANCEL);
            return TRUE;
        }
    }
    
    return FALSE;
}

bool CFPSSelector::ShowFPSDialog()
{
    // Create a simple dialog box for FPS selection
    const char* dialogTitle = "Select FPS Mode";
    const char* message = "Choose your preferred FPS limit:\n\n";
    const char* option1 = "40 FPS (Default - Best Compatibility)";
    const char* option2 = "60 FPS (Recommended)";
    const char* option3 = "120 FPS (High Performance)";
    
    // Create message box with custom buttons
    char buffer[512];
    sprintf(buffer, "%s\n[1] %s\n[2] %s\n[3] %s\n\nPress 1, 2, or 3 to select, or ESC to cancel.",
            message, option1, option2, option3);
    
    // Simple implementation using MessageBox with MB_YESNOCANCEL
    int result = MessageBox(NULL, 
        "Select FPS Mode:\n\n"
        "YES = 60 FPS (Recommended)\n"
        "NO = 40 FPS (Default)\n"
        "CANCEL = 120 FPS (High Performance)\n\n"
        "OpenGL Shaders will be loaded for enhanced graphics.",
        "FPS Selection - Enhanced Graphics",
        MB_YESNOCANCEL | MB_ICONQUESTION | MB_TOPMOST);
    
    switch (result)
    {
        case IDYES:
            m_SelectedFPS = FPS_MODE_60;
            break;
        case IDNO:
            m_SelectedFPS = FPS_MODE_40;
            break;
        case IDCANCEL:
            m_SelectedFPS = FPS_MODE_120;
            break;
        default:
            m_SelectedFPS = FPS_MODE_40;
            break;
    }
    
    // Update the MainInfo structure with selected FPS
    gProtect.m_MainInfo.LimitFPS = m_SelectedFPS;
    
    // Initialize shaders and VSync
    InitializeShaders();
    
    return true;
}
