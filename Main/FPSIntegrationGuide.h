#pragma once

/*
====================================================================================
   HIGH FPS OPTIMIZATION SYSTEM - INTEGRATION GUIDE
====================================================================================

This guide explains how to integrate the advanced FPS system into your Mu Online client.

OVERVIEW:
---------
The system consists of 4 main components:

1. AdvancedFPSManager - Manages frame timing and provides delta time
2. ImprovedHackCheck - Modified hack protection that supports high FPS
3. OptimizedShaders - GPU-accelerated rendering for better performance
4. Integration hooks - Connecting everything together

SUPPORTED FPS TARGETS:
----------------------
- 25 FPS (Original)
- 30 FPS
- 60 FPS (Recommended)
- 120 FPS
- 144 FPS
- 240 FPS
- Unlimited (capped at ~125 FPS for stability)

INSTALLATION STEPS:
-------------------

Step 1: Add new files to your project
--------------------------------------
- AdvancedFPSManager.h / .cpp
- ImprovedHackCheck.h / .cpp
- OptimizedShaders.h / .cpp

Step 2: Modify Main.cpp
------------------------
In the EntryProc() function, AFTER loading protect files but BEFORE InitHackCheck():

    // Initialize FPS Manager
    int targetFPS = gProtect.m_MainInfo.LimitFPS;
    if (targetFPS == 0 || targetFPS < 25) targetFPS = 60; // Default to 60
    gAdvancedFPSManager.Initialize(targetFPS);
    
    // Initialize Optimized Shaders (optional, for better graphics)
    if (gOptimizedShaders.Initialize())
    {
        // Shaders loaded successfully
    }

Step 3: Replace HackCheck hooks
--------------------------------
In Main.cpp, find these lines (around line 271-273):

    SetCompleteHook(0xE9,0x004DA280,&CheckTickCount1);
    SetCompleteHook(0xE9,0x004DA3A1,&CheckTickCount2);

Replace them with:

    SetCompleteHook(0xE9,0x004DA280,&CheckTickCount1_Improved);
    SetCompleteHook(0xE9,0x004DA3A1,&CheckTickCount2_Improved);

Step 4: Modify User.cpp (Frame Speed Adjustment)
-------------------------------------------------
In User::Refresh() function, replace the SetDouble calls with dynamic scaling:

    // OLD CODE (Remove this):
    if ( gObjUser.GetActiveSkill() == 261 || 
         gObjUser.GetActiveSkill() == 552 || 
         gObjUser.GetActiveSkill() == 555 )
    {
        SetDouble(&pFrameSpeed1, 0.0004000);
        SetDouble(&pFrameSpeed2, 0.0002000);
    }
    else
    {
        SetDouble(&pFrameSpeed1, 0.0040000);
        SetDouble(&pFrameSpeed2, 0.0020000);
    }
    
    // NEW CODE (Add this):
    float frameMultiplier = gAdvancedFPSManager.GetFrameMultiplier();
    
    if ( gObjUser.GetActiveSkill() == 261 || 
         gObjUser.GetActiveSkill() == 552 || 
         gObjUser.GetActiveSkill() == 555 )
    {
        SetDouble(&pFrameSpeed1, 0.0004000 * frameMultiplier);
        SetDouble(&pFrameSpeed2, 0.0002000 * frameMultiplier);
    }
    else
    {
        SetDouble(&pFrameSpeed1, 0.0040000 * frameMultiplier);
        SetDouble(&pFrameSpeed2, 0.0020000 * frameMultiplier);
    }

Step 5: Add FPS Manager update to game loop
--------------------------------------------
Find the main game loop (usually in a rendering function).
Add this at the START of each frame:

    gAdvancedFPSManager.Update();

Step 6: Optional - Enable shaders in rendering code
----------------------------------------------------
If you want to use the optimized shaders, in your main rendering function:

    // At start of rendering
    if (gOptimizedShaders.IsShadersSupported())
    {
        gOptimizedShaders.UseShader();
    }
    
    // ... your rendering code ...
    
    // At end of rendering
    if (gOptimizedShaders.IsShadersSupported())
    {
        gOptimizedShaders.DisableShader();
    }

Step 7: Configure LimitFPS in your config file
-----------------------------------------------
In your "CreadorDeMU" config file, set LimitFPS to your desired value:
- 25 = Original speed
- 60 = Smooth 60 FPS (Recommended)
- 120 = High refresh rate
- 0 = Unlimited (capped at 125 for stability)

ADVANCED USAGE:
---------------

Dynamic FPS Switching:
    // Change FPS at runtime
    SetDynamicFPSLimit(120); // Switch to 120 FPS
    
Get Current FPS:
    float currentFPS = gAdvancedFPSManager.GetCurrentFPS();
    
Get Delta Time (for frame-independent calculations):
    float deltaTime = gAdvancedFPSManager.GetDeltaTime();
    
    // Example: Move object frame-independently
    object.position += object.velocity * deltaTime;

Enable VSync:
    gAdvancedFPSManager.SetVSync(true); // Enable VSync
    gAdvancedFPSManager.SetVSync(false); // Disable VSync

IMPORTANT NOTES:
----------------

1. Movement Speed Compensation:
   The system automatically scales movement and animation speeds based on FPS.
   No manual adjustments needed for most cases.

2. HackCheck Compatibility:
   The ImprovedHackCheck maintains all security features while allowing high FPS.
   Speed modifiers are still monitored to prevent actual speed hacks.

3. Performance Tips:
   - 60 FPS is recommended for best balance of performance and smoothness
   - 120+ FPS requires good hardware (GPU with OpenGL 2.0+)
   - Use VSync to prevent screen tearing
   - Enable shaders for better visual quality at high FPS

4. Troubleshooting:
   - If characters move too fast: Check frame multiplier application
   - If FPS is unstable: Try lowering target FPS or enabling VSync
   - If shaders don't work: GPU may not support GLSL 1.20 (fallback to no shaders)

TESTING:
--------

After integration, test these scenarios:
1. Character walking/running at different FPS settings
2. Combat and skill animations
3. Monster movement and attacks
4. Interface rendering and responsiveness
5. Network lag compensation

Compare behavior at 25 FPS vs 60 FPS vs 120 FPS to ensure consistency.

====================================================================================
*/

// Include required headers for integration
#include "AdvancedFPSManager.h"
#include "ImprovedHackCheck.h"
#include "OptimizedShaders.h"

// Helper function to initialize complete FPS system
inline void InitializeHighFPSSystem()
{
	// Get target FPS from config
	int targetFPS = gProtect.m_MainInfo.LimitFPS;
	
	// Default to 60 FPS if not set or invalid
	if (targetFPS <= 0 || targetFPS < 25)
	{
		targetFPS = 60;
	}
	
	// Initialize FPS Manager
	gAdvancedFPSManager.Initialize(targetFPS);
	
	// Initialize Improved HackCheck
	InitImprovedHackCheck();
	
	// Initialize Shaders (optional)
	bool shadersEnabled = gOptimizedShaders.Initialize();
	
	// You can check shader status here
	// if (!shadersEnabled) { /* Shaders not available, use fallback rendering */ }
}

// Helper function to update FPS system each frame
inline void UpdateHighFPSSystem()
{
	gAdvancedFPSManager.Update();
}
