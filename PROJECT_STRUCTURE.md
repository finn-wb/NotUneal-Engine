# NotUneal Engine - Project Structure Guide

## Complete File Organization

```
NotUneal-Engine/
│
├── CMakeLists.txt                      # Root CMake configuration
├── LICENSE                             # MIT License
├── README.md                           # Quick start guide
├── README_FULL.md                      # Complete overview
├── ROADMAP.md                          # Feature roadmap
├── RELEASE_NOTES.md                    # Version history
├── CONTRIBUTING.md                     # Contribution guidelines
├── CONTRIBUTORS.md                     # List of contributors
├── FAQ.md                              # Frequently asked questions
├── build.sh                            # Linux/macOS build script
├── build.bat                           # Windows build script
│
├── Engine/                             # Core engine library
│   ├── CMakeLists.txt
│   │
│   ├── Core/                           # Foundation
│   │   ├── CMakeLists.txt
│   │   ├── Core.h
│   │   ├── Types.h
│   │   ├── Memory.h
│   │   ├── Containers/
│   │   │   ├── Array.h
│   │   │   ├── Map.h
│   │   │   └── String.h
│   │   └── ...
│   │
│   ├── Scene/                          # GameObject & Scene System
│   │   ├── CMakeLists.txt
│   │   ├── GameObject.h
│   │   ├── GameObject.cpp
│   │   ├── Component.h
│   │   ├── Component.cpp
│   │   ├── TransformComponent.h
│   │   ├── TransformComponent.cpp
│   │   ├── Scene.h
│   │   ├── Scene.cpp
│   │   ├── SceneManager.h
│   │   └── SceneManager.cpp
│   │
│   ├── Rendering/                      # Graphics & Rendering
│   │   ├── CMakeLists.txt
│   │   ├── Renderer.h
│   │   ├── Renderer.cpp
│   │   ├── Camera.h
│   │   ├── Camera.cpp
│   │   ├── Shader.h
│   │   ├── Shader.cpp
│   │   ├── ShaderProgram.h
│   │   ├── ShaderProgram.cpp
│   │   ├── Material.h
│   │   ├── Material.cpp
│   │   ├── Mesh.h
│   │   ├── Mesh.cpp
│   │   ├── Texture.h
│   │   ├── Texture.cpp
│   │   ├── RenderCommand.h
│   │   └── RenderCommand.cpp
│   │
│   ├── Components/                     # Built-in Components
│   │   ├── CMakeLists.txt
│   │   ├── MeshComponent.h
│   │   ├── MeshComponent.cpp
│   │   ├── LightComponent.h
│   │   └── LightComponent.cpp
│   │
│   ├── ShaderEditor/                   # Visual Shader System
│   │   ├── CMakeLists.txt
│   │   ├── ShaderNode.h
│   │   ├── ShaderNode.cpp
│   │   ├── ShaderNodes.h
│   │   ├── ShaderNodes.cpp
│   │   ├── ShaderGraph.h
│   │   └── ShaderGraph.cpp
│   │
│   ├── Assets/                         # Asset Management
│   │   ├── AssetPackage.h
│   │   ├── AssetPackage.cpp
│   │   ├── AssetManager.h
│   │   └── AssetManager.cpp
│   │
│   ├── Framework/                      # Game Framework
│   │   ├── GameFramework.h
│   │   └── GameFramework.cpp
│   │
│   ├── Input/                          # Input System
│   │   ├── InputSystem.h
│   │   └── InputSystem.cpp
│   │
│   ├── Serialization/                  # Serialization
│   │   ├── Archive.h
│   │   └── Serializable.h
│   │
│   └── NotUneal.h                      # Main API Header
│
├── Editor/                             # Editor Application
│   ├── CMakeLists.txt
│   ├── ProjectSettings.h
│   ├── ProjectSettings.cpp
│   ├── EditorViewport.h
│   ├── EditorViewport.cpp
│   ├── Editor.h
│   └── Editor.cpp
│
├── Tools/                              # Build & Import Tools
│   ├── CMakeLists.txt
│   ├── BuildTools.h
│   └── BuildTools.cpp
│
├── Examples/                           # Example Projects
│   ├── CMakeLists.txt
│   ├── SimpleScene.cpp                 # Basic 3D scene
│   ├── ShaderEditorExample.cpp         # Shader creation
│   └── AssetManagementExample.cpp      # Asset import/packaging
│
└── Documentation/                      # Guides & Documentation
    ├── GETTING_STARTED.md              # Build & setup
    ├── ARCHITECTURE.md                 # System design
    ├── RENDERING_GUIDE.md              # Graphics pipeline
    ├── SHADER_EDITOR_GUIDE.md          # Shader system
    ├── ASSET_MANAGEMENT_GUIDE.md       # Asset system
    └── BUILD_DISTRIBUTION_GUIDE.md     # Building games
```

## Build Directory Structure (After Building)

```
build/
├── CMakeFiles/                         # CMake generated files
├── Engine/
│   ├── Core/
│   │   └── libNotUnealCore.a           # Core library
│   ├── Scene/
│   │   └── libNotUnealScene.a          # Scene library
│   ├── Rendering/
│   │   └── libNotUnealRendering.a      # Rendering library
│   └── ...
├── Editor/
│   └── libNotUnealEditor.a             # Editor library (if enabled)
├── Tools/
│   └── libNotUnealTools.a              # Tools library (if enabled)
├── Examples/
│   ├── SimpleSceneExample              # Executable
│   ├── ShaderEditorExample             # Executable
│   └── AssetManagementExample          # Executable
└── ...
```

## Key Files at a Glance

### Starting Points
- `README.md` - Quick overview
- `Documentation/GETTING_STARTED.md` - Build instructions
- `Examples/` - Working code samples

### Architecture
- `Engine/NotUneal.h` - Main API header
- `Engine/Core/` - Foundation types
- `Engine/Scene/` - GameObject system
- `Engine/Rendering/` - Graphics system

### Game Development
- `Engine/Framework/GameFramework.h` - Game loop
- `Engine/Input/InputSystem.h` - Input handling
- `Engine/Scene/GameObject.h` - Base actor class
- `Engine/Scene/Component.h` - Base behavior class

### Graphics
- `Engine/Rendering/Renderer.h` - Main renderer
- `Engine/Rendering/Material.h` - Materials
- `Engine/Rendering/Camera.h` - Cameras
- `Engine/ShaderEditor/` - Visual shader system

### Assets
- `Engine/Assets/AssetManager.h` - Asset system
- `Engine/Assets/AssetPackage.h` - Asset packaging
- `Tools/BuildTools.h` - Import/export tools

### Tools
- `build.sh` - Linux/macOS build
- `build.bat` - Windows build
- `CMakeLists.txt` - Build configuration

## File Statistics

```
Header Files (.h):        50+
Implementation Files (.cpp): 30+
Lines of Core Code:       5000+
Documentation Pages:      100+
Example Projects:         3
Total Repository Size:    ~2MB (code)
```

## Documentation Files Quick Reference

| File | Purpose | Audience |
|------|---------|----------|
| README.md | Quick start | Everyone |
| GETTING_STARTED.md | Build setup | Developers |
| ARCHITECTURE.md | System design | Advanced users |
| RENDERING_GUIDE.md | Graphics pipeline | Graphics devs |
| SHADER_EDITOR_GUIDE.md | Shader creation | Artists/Devs |
| ASSET_MANAGEMENT_GUIDE.md | Asset system | All |
| BUILD_DISTRIBUTION_GUIDE.md | Building games | Game devs |
| CONTRIBUTING.md | Contributing | Contributors |
| FAQ.md | Common questions | Everyone |
| ROADMAP.md | Future plans | All |

## Naming Conventions

```
Classes:          PascalCase       (GameObject, MeshComponent)
Methods:          camelCase        (Update(), GetName())
Variables:        camelCase        (position, velocity)
Members:          m prefix         (mPosition, mVelocity)
Constants:        UPPER_CASE       (MAX_SPEED, PI)
Namespace:        camelCase        (NotUneal)
Files:            PascalCase       (GameObject.h)
Directories:      lowercase        (rendering, components)
```

## Dependency Graph

```
NotUnealEngine
├── NotUnealCore (Foundation)
├── NotUnealScene (Depends on: Core)
├── NotUnealRendering (Depends on: Core)
├── NotUnealComponents (Depends on: Scene, Rendering)
└── NotUnealShaderEditor (Depends on: Core, Rendering)

NotUnealEditor (Depends on: Engine, Qt6)
NotUnealTools (Depends on: Engine)
Examples (Depends on: Engine)
```

## Cross-Platform Support

- **Windows**: Tested with MSVC 2022
- **Linux**: Tested with GCC 11
- **macOS**: Tested with Clang 13

## Extension Points

### Add New Component
```cpp
// In Engine/Components/
// MyComponent.h + MyComponent.cpp
class MyComponent : public Component {
    // Implementation
};
```

### Add New Shader Node
```cpp
// In Engine/ShaderEditor/
class MyNode : public ShaderNode {
    std::string GenerateGLSL() const override;
};
```

### Add New Asset Importer
```cpp
// In Tools/
class MyImporter {
    static bool ImportFormat(const std::string& path);
};
```

---

For more details, see the main [README.md](README.md) or specific documentation files.
