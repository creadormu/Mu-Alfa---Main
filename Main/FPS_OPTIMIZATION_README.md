# High FPS Optimization System for Mu Online Client

## 🎯 Overview

This optimization system allows your Mu Online client to run at **60, 120, 144, or even 240 FPS** while maintaining game stability and preventing character/monster speed issues.

### Key Features

✅ **Configurable FPS**: Switch between 25, 30, 60, 120, 144, 240 FPS or unlimited  
✅ **Frame-Independent Logic**: Movement and animations scaled properly for any FPS  
✅ **HackCheck Compatible**: Maintains anti-cheat security while allowing high FPS  
✅ **Optimized Shaders**: GPU-accelerated rendering with GLSL 1.20  
✅ **Delta Time System**: Proper timing for smooth gameplay at any frame rate  
✅ **VSync Support**: Eliminates screen tearing  
✅ **Easy Integration**: Drop-in solution with minimal code changes

---

## 📊 The Problem

The original game client is limited to **25 FPS** (40ms frame time) by the HackCheck system at these addresses:
- `0x004DA280` - CheckTickCount1
- `0x004DA3A1` - CheckTickCount2
- Hardcoded value: `0x28` (40ms) in HackCheck.cpp line 137 and 188

This causes:
- ❌ Choppy animations
- ❌ Slow response time
- ❌ Poor visual experience on modern monitors
- ❌ Movement/animation speed tied to frame rate

---

## 🔧 The Solution

Our system implements:

### 1. **Advanced FPS Manager** (`AdvancedFPSManager.cpp`)
- Delta time calculation
- Frame multiplier for scaling
- FPS monitoring and limiting
- Interpolation support

### 2. **Improved HackCheck** (`ImprovedHackCheck.cpp`)
- Dynamic FPS limits (replaces hardcoded 0x28)
- Maintains security features
- Configurable frame timing
- Compatible with anti-cheat

### 3. **Optimized Shaders** (`OptimizedShaders.cpp`)
- GLSL 1.20 vertex and fragment shaders
- Early Z-culling for performance
- Optimized light calculations
- Fallback support for older GPUs

---

## 🚀 Installation

### Files to Add to Your Project

1. `AdvancedFPSManager.h` / `.cpp`
2. `ImprovedHackCheck.h` / `.cpp`
3. `OptimizedShaders.h` / `.cpp`
4. `FPSIntegrationGuide.h`

### Step-by-Step Integration

#### Step 1: Modify `Main.cpp`

Add includes at the top:
```cpp
#include "AdvancedFPSManager.h"
#include "ImprovedHackCheck.h"
#include "OptimizedShaders.h"
```

In `EntryProc()` function, add initialization (after loading protect files):
```cpp
// Around line 175, after ReadPetEffectBMD

// Initialize High FPS System
int targetFPS = gProtect.m_MainInfo.LimitFPS;
if (targetFPS <= 0 || targetFPS < 25) targetFPS = 60; // Default to 60 FPS

gAdvancedFPSManager.Initialize(targetFPS);

// Initialize Optimized Shaders (optional for better graphics)
if (gOptimizedShaders.Initialize())
{
    // Shaders loaded successfully
    MessageBox(0, "Optimized Shaders Enabled", "FPS Optimization", MB_OK);
}
```

Replace HackCheck hooks (around line 271-273):
```cpp
// OLD CODE - REPLACE THIS:
// SetCompleteHook(0xE9,0x004DA280,&CheckTickCount1);
// SetCompleteHook(0xE9,0x004DA3A1,&CheckTickCount2);

// NEW CODE:
SetCompleteHook(0xE9,0x004DA280,&CheckTickCount1_Improved);
SetCompleteHook(0xE9,0x004DA3A1,&CheckTickCount2_Improved);
```

Comment out the old InitHackCheck (around line 411):
```cpp
// OLD: InitHackCheck();
// No longer needed - InitImprovedHackCheck is called in AdvancedFPSManager
```

#### Step 2: Modify `User.cpp`

In `User::Refresh()` function (around line 54-65), replace frame speed code:

```cpp
// OLD CODE - REMOVE:
/*
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
*/

// NEW CODE - ADD:
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
```

#### Step 3: Find Main Game Loop

You need to find where the main rendering loop is. Search for these patterns:
- `SwapBuffers`
- Main loop with `while(true)` or `while(running)`
- Function that renders each frame

At the **START** of each frame loop, add:
```cpp
gAdvancedFPSManager.Update();
```

Example:
```cpp
void MainGameLoop()
{
    while (IsRunning())
    {
        gAdvancedFPSManager.Update();  // <-- ADD THIS LINE
        
        ProcessInput();
        UpdateGame();
        RenderGame();
        SwapBuffers();
    }
}
```

#### Step 4: Optional - Enable Shaders in Rendering

In your main rendering function, wrap rendering code:

```cpp
void RenderGame()
{
    // Enable shader
    if (gOptimizedShaders.IsShadersSupported())
    {
        gOptimizedShaders.UseShader();
    }
    
    // Your rendering code here
    RenderWorld();
    RenderCharacters();
    RenderUI();
    
    // Disable shader
    if (gOptimizedShaders.IsShadersSupported())
    {
        gOptimizedShaders.DisableShader();
    }
}
```

#### Step 5: Configure in Config File

In your `CreadorDeMU` configuration file, set the `LimitFPS` value:

```
LimitFPS = 60    // For 60 FPS (Recommended)
// LimitFPS = 120   // For 120 FPS
// LimitFPS = 144   // For 144 Hz monitors
// LimitFPS = 0     // Unlimited (capped at 125)
```

---

## 🎮 Usage Examples

### Change FPS at Runtime
```cpp
// Switch to 120 FPS
SetDynamicFPSLimit(120);

// Switch to unlimited
SetDynamicFPSLimit(0);

// Back to 60 FPS
SetDynamicFPSLimit(60);
```

### Get Current FPS
```cpp
float currentFPS = gAdvancedFPSManager.GetCurrentFPS();
char buffer[64];
sprintf(buffer, "FPS: %.1f", currentFPS);
// Draw buffer on screen
```

### Frame-Independent Movement
```cpp
float deltaTime = gAdvancedFPSManager.GetDeltaTime();

// Old way (frame-dependent):
// player.x += player.speedX;

// New way (frame-independent):
player.x += player.speedX * deltaTime;
```

### Enable/Disable VSync
```cpp
// Enable VSync (sync with monitor refresh rate)
gAdvancedFPSManager.SetVSync(true);

// Disable VSync (for higher FPS than monitor refresh)
gAdvancedFPSManager.SetVSync(false);
```

---

## 📈 Performance Comparison

| FPS Setting | Frame Time | Use Case |
|------------|------------|----------|
| 25 FPS (Original) | 40ms | Legacy/Low-end systems |
| 30 FPS | 33ms | Minimum smooth experience |
| 60 FPS | 16ms | **Recommended** - Smooth gameplay |
| 120 FPS | 8ms | High refresh rate monitors |
| 144 FPS | 7ms | 144Hz monitors |
| 240 FPS | 4ms | Competitive gaming, 240Hz monitors |
| Unlimited | Variable | Max performance (capped at 125) |

---

## ⚠️ Important Notes

### Movement Speed Compensation

The system uses a **frame multiplier** to ensure consistent movement speed:
- At 25 FPS (original): multiplier = 1.0
- At 60 FPS: multiplier ≈ 0.67
- At 120 FPS: multiplier ≈ 0.33

This means animations and movement are scaled to maintain the same perceived speed regardless of FPS.

### HackCheck Compatibility

The `ImprovedHackCheck` system:
- ✅ Maintains all security checks
- ✅ Monitors speed modifiers
- ✅ Detects memory manipulation
- ✅ Allows configurable FPS limits
- ✅ Prevents actual speed hacks

### Shader Requirements

Optimized shaders require:
- OpenGL 2.0 or higher
- GLSL 1.20 support
- Modern GPU (2010+)

If shaders fail to load, the game continues with standard rendering.

---

## 🔍 Troubleshooting

### Characters Move Too Fast
- Check that `User::Refresh()` applies frame multiplier
- Verify `gAdvancedFPSManager.Update()` is called each frame
- Lower the target FPS

### FPS is Unstable
- Enable VSync: `gAdvancedFPSManager.SetVSync(true)`
- Lower target FPS (try 60 instead of 120)
- Check GPU/CPU usage

### Shaders Don't Work
- GPU may not support GLSL 1.20
- Update graphics drivers
- System will fall back to standard rendering

### Game Crashes on Startup
- Verify all new files are included in project
- Check that `ImprovedHackCheck` hooks replace old ones
- Ensure `InitHackCheck()` is NOT called (replaced by improved version)

### Network Lag Issues
- FPS system is client-side only
- Network lag is independent of frame rate
- Server still operates at its own tick rate

---

## 🧪 Testing Checklist

After integration, test:

- [ ] Character walking at 25, 60, 120 FPS
- [ ] Character running at different FPS
- [ ] Combat animations and attacks
- [ ] Skill casting and effects
- [ ] Monster movement and attacks
- [ ] NPC interactions
- [ ] Interface responsiveness
- [ ] Network synchronization
- [ ] Party member movement
- [ ] Teleporting/warping

---

## 🎨 Shader Details

### Vertex Shader Features
- Uses built-in `gl_ModelViewProjectionMatrix` for compatibility
- Efficient attribute passing (position, texture, color)
- Minimal calculations for maximum performance

### Fragment Shader Features
- Optimized texture sampling
- Light intensity clamping (prevents over-bright pixels)
- Early Z-culling (discards transparent pixels)
- Compatible with GLSL 1.20 (older GPUs)

### Advanced Shader Options

You can create custom shaders by modifying:
- `OptimizedShaders.cpp::GetVertexShaderSource()`
- `OptimizedShaders.cpp::GetFragmentShaderSource()`

Example enhancements:
- Add bloom effect
- Add color grading
- Add motion blur
- Add ambient occlusion

---

## 🔬 Technical Details

### Frame Timing Calculation

```
Base FPS: 25 (original)
Base Frame Time: 40ms

Target FPS: 60
Target Frame Time: 1000ms / 60 = 16.67ms

Frame Multiplier: CurrentFrameTime / BaseFrameTime
                = 16.67 / 40
                = 0.417

Movement Speed: OriginalSpeed * FrameMultiplier
```

### Delta Time Usage

Delta time ensures frame-rate independent physics:

```cpp
// Physics update
velocity += acceleration * deltaTime;
position += velocity * deltaTime;

// Animation update
animationFrame += animationSpeed * deltaTime;
```

### Interpolation

The system provides interpolation alpha for smooth rendering:

```cpp
float alpha = gAdvancedFPSManager.GetInterpolationAlpha();

// Smooth position between physics updates
renderPosition = previousPosition * (1 - alpha) + currentPosition * alpha;
```

---

## 📝 Configuration File Format

Example `CreadorDeMU` configuration:

```ini
[FPS Settings]
LimitFPS = 60           # Target FPS (25, 30, 60, 120, 144, 240, 0 for unlimited)
MonitorFPS = 1          # Show FPS counter (1 = yes, 0 = no)
MonitorMS = 1           # Show frame time in MS (1 = yes, 0 = no)

[Graphics Settings]
DisableEffectRemake = 0 # Enable shader effects
```

---

## 🤝 Credits

Based on analysis of:
- Original HackCheck.cpp timing system
- Speed.cpp hack detection
- SpeedFix.cpp attack speed limiter
- User.cpp frame speed modifiers

Developed to provide:
- Higher FPS without speed hacks
- Stable gameplay at any frame rate
- Professional-grade frame timing
- GPU-accelerated rendering

---

## 📞 Support

If you encounter issues:

1. Check the troubleshooting section
2. Verify all integration steps
3. Test at lower FPS (60 before 120)
4. Check console/log for error messages
5. Ensure GPU supports OpenGL 2.0+

---

## 🔄 Version History

**Version 1.0** (Current)
- Initial release
- Support for 60/120/144/240 FPS
- Delta time system
- Optimized shaders
- VSync support
- Frame interpolation

---

**Enjoy your silky-smooth 60+ FPS Mu Online experience! 🎮✨**
