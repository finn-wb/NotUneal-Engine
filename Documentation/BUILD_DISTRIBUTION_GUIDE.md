# Build and Distribution Guide

## Building Games

### Basic Build

```cpp
#include <NotUneal/Tools/BuildTools.h>

using namespace NotUneal;

BuildSystem::BuildConfig config;
config.OutputPath = "./Builds/Game";
config.Platform = "Windows";
config.DebugBuild = false;
config.OptimizeAssets = true;

if (BuildSystem::BuildGame("./MyGame", config)) {
    std::cout << "Build successful!" << std::endl;
} else {
    std::cout << "Build failed!" << std::endl;
}
```

### Build Stages

1. **Compilation**: Compile user code with engine bindings
   ```cpp
   BuildSystem::CompileUserCode(projectPath);
   ```

2. **Asset Packaging**: Create asset packages
   ```cpp
   BuildSystem::PackageAssets(projectPath, outputPath);
   ```

3. **Linking**: Link engine and user code
   - Handled automatically by build system

4. **Distribution**: Package executable and assets
   - Generates platform-specific builds

## Platform-Specific Builds

### Windows
```cpp
config.Platform = "Windows";
// Generates .exe with MSVC runtime
```

### Linux
```cpp
config.Platform = "Linux";
// Generates ELF executable
// Requires glibc development files
```

### WebGL (Experimental)
```cpp
config.Platform = "WebGL";
// Generates JavaScript + WebAssembly
// Requires Emscripten SDK
```

## Project Structure for Distribution

```
MyGame/
├── Scenes/
│   ├── MainMenu.scene
│   └── Level01.scene
├── Assets/
│   ├── game_assets.npkg
│   └── shaders.package
├── Code/
│   ├── Game.cpp
│   ├── Player.cpp
│   └── GameRules.cpp
├── Build/
│   └── (build outputs)
├── project.notuneal
└── CMakeLists.txt
```

## Custom Project Code

User code integrates with the engine:

```cpp
// GameLogic.h
#pragma once
#include <NotUneal/Framework/GameFramework.h>

class MyGame : public NotUneal::GameFramework {
public:
    void Initialize() override;
    void Update(float deltaTime) override;
    void OnSceneLoaded() override;
};
```

```cpp
// GameLogic.cpp
#include "GameLogic.h"

void MyGame::Initialize() {
    GameFramework::Initialize();
    // Custom initialization
}

void MyGame::Update(float deltaTime) {
    GameFramework::Update(deltaTime);
    // Custom game logic
}
```

## Asset Optimization

### Mesh Optimization
- Remove unused vertices
- Merge static meshes
- Use LOD variants
- Optimize vertex layout

### Texture Optimization
- Use compression formats (BC1, BC7)
- Generate mipmaps
- Use atlasing for UI textures
- Reduce unnecessary resolution

### Shader Optimization
- Remove dead code
- Use lower precision where possible
- Minimize texture lookups
- Pre-compute what you can

## Debug vs Release Builds

### Debug Build
```cpp
config.DebugBuild = true;
// Includes debugging symbols
// No optimization
// Larger executable
```

### Release Build
```cpp
config.DebugBuild = false;
// Stripped of debug info
// Full optimization
// Smaller executable
// Better performance
```

## Packaging Output

Build produces:
```
Build/
├── Executable/ (MyGame.exe or MyGame)
├── Assets/ (game_assets.npkg, shaders.package)
├── Libs/ (engine libraries if dynamic linking)
└── ReadMe.txt
```

## Distribution Checklist

- [ ] All assets packaged and compressed
- [ ] Game tested on target platform
- [ ] Executable permissions correct
- [ ] Asset paths relative to executable
- [ ] Required runtime libraries included
- [ ] Documentation and credits included
- [ ] Version number set correctly

## Continuous Integration

Example GitHub Actions workflow:

```yaml
name: Build Game
on: [push, pull_request]
jobs:
  build:
    runs-on: windows-latest
    steps:
      - uses: actions/checkout@v2
      - name: Configure
        run: cmake -B build
      - name: Build
        run: cmake --build build --config Release
      - name: Upload Artifacts
        uses: actions/upload-artifact@v2
        with:
          name: game-build
          path: build/Release/
```

## Version Management

Set version in project.notuneal:

```json
{
  "ProjectName": "MyGame",
  "Version": "1.0.0",
  "BuildNumber": 42
}
```

Access in code:

```cpp
#include <NotUneal/Editor/ProjectSettings.h>

auto version = ProjectSettings::Get().GetConfig().Version;
```
