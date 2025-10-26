// VSync.h: Simple VSync Controller (No FPS changes, just smooth display)
#pragma once

#include <windows.h>

class CVSync
{
public:
    CVSync();
    virtual ~CVSync();
    
    void Initialize();
    void EnableVSync(bool enable);
    bool IsVSyncSupported();
    
private:
    bool m_VSyncSupported;
    bool m_VSyncEnabled;
};

extern CVSync gVSync;
