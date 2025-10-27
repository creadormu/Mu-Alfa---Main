// FPSSelector_GraphicsOnly.h: Graphics Enhancement Without FPS Changes
// This version ONLY loads shaders, does NOT change FPS
#pragma once

#include <windows.h>

class CFPSSelectorGraphicsOnly
{
public:
    CFPSSelectorGraphicsOnly();
    virtual ~CFPSSelectorGraphicsOnly();
    
    void InitializeGraphicsEnhancements();
    bool LoadShaderFile(const char* filename, char** shaderSource);
    void InitializeShaders();
    void InitializeVSync();
    
private:
    bool m_ShadersLoaded;
    bool m_VSyncEnabled;
};

extern CFPSSelectorGraphicsOnly gGraphicsEnhancer;
