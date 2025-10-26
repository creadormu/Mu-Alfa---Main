// VSync.cpp: Simple VSync Implementation
// Only enables VSync for smooth display - NO FPS changes, NO shader loading

#include "stdafx.h"
#include "VSync.h"

CVSync gVSync;

CVSync::CVSync()
{
    m_VSyncSupported = false;
    m_VSyncEnabled = false;
}

CVSync::~CVSync()
{
}

void CVSync::Initialize()
{
    // Try to enable VSync using wglSwapIntervalEXT
    typedef BOOL (WINAPI * PFNWGLSWAPINTERVALEXTPROC)(int interval);
    
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;
    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
    
    if (wglSwapIntervalEXT)
    {
        m_VSyncSupported = true;
        EnableVSync(true);
    }
}

void CVSync::EnableVSync(bool enable)
{
    if (!m_VSyncSupported)
        return;
    
    typedef BOOL (WINAPI * PFNWGLSWAPINTERVALEXTPROC)(int interval);
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;
    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
    
    if (wglSwapIntervalEXT)
    {
        wglSwapIntervalEXT(enable ? 1 : 0);
        m_VSyncEnabled = enable;
    }
}

bool CVSync::IsVSyncSupported()
{
    return m_VSyncSupported;
}
