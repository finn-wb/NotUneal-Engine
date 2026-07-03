# NotUneal Engine - Complete Implementation

A lightweight, extensible game engine with a visual editor, custom shader system, and complete asset management pipeline.

## 🎮 Features Implemented

### Core Engine
- ✅ **GameObject System**: Universal actor/component architecture
- ✅ **Transform Component**: Position, rotation, scale management with hierarchy
- ✅ **Scene Management**: Scene graph with object lifecycle
- ✅ **Component Framework**: Easy extensibility for custom behaviors

### Rendering
- ✅ **OpenGL 4.6 Renderer**: Modern rendering pipeline
- ✅ **Material System**: Shader-based materials with properties
- ✅ **Mesh Rendering**: Vertex/Index buffer support
- ✅ **Camera System**: Perspective and orthographic cameras
- ✅ **Lighting Framework**: Directional, Point, and Spot lights

### Visual Shader Editor
- ✅ **Node-Based Graph**: Drag-and-drop shader creation
- ✅ **Built-in Nodes**:
  - Vertex Input nodes (Position, Normal, TexCoord, etc.)
  - Texture Sampling
  - Math Operations (Add, Multiply, Dot, Normalize, etc.)
  - Custom GLSL
- ✅ **Live Compilation**: GLSL code generation
- ✅ **Real-time Preview**: Instant shader feedback

### Asset Management
- ✅ **Asset Packaging**: Binary asset packages (.npkg format)
- ✅ **Runtime Loading**: Stream assets during gameplay
- ✅ **Import Pipeline**:
  - FBX, GLTF, OBJ mesh import
  - PNG, JPEG, TGA, HDR texture import
- ✅ **Asset Cache**: Efficient memory management

### Editor
- ✅ **Scene Editor**: Visual scene composition
- ✅ **Hierarchy Panel**: Object organization
- ✅ **Inspector**: Property editing
- ✅ **Viewport**: Real-time scene preview
- ✅ **Gizmos**: Transform manipulation (translate, rotate, scale)
- ✅ **Play/Stop Controls**: In-editor game testing

### Build System
- ✅ **Code Compilation**: User project compilation with engine bindings
- ✅ **Asset Packaging**: Optimization and batching
- ✅ **Multi-Platform**: Windows, Linux, WebGL support
- ✅ **Executable Generation**: Standalone game distribution

### Framework
- ✅ **Game Framework**: Scene and object management
- ✅ **Input System**: Keyboard, mouse, controller input
- ✅ **Tag System**: Object grouping and queries
- ✅ **Time Management**: Delta time and total time tracking

## 📁 Project Structure

```
NotUneal-Engine/
├── Engine/
│   ├── Core/              # Foundation types and utilities
│   ├── Scene/             # GameObject and scene system
│   ├── Rendering/         # Graphics and rendering
│   ├── Components/        # Built-in components (Mesh, Light, etc.)
│   ├── ShaderEditor/      # Visual shader graph editor
│   ├── Assets/            # Asset management and packaging
│   ├── Framework/         # Game framework
│   ├── Input/             # Input handling
│   └── Serialization/     # Serialization utilities
├── Editor/                # Desktop editor application
├── Tools/                 # Build and import tools
├── Examples/              # Example projects
├── Documentation/         # Engine documentation
└── CMakeLists.txt        # Build configuration
```

## 🚀 Quick Start

### Building

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### Creating a Project

```cpp
#include <NotUneal/Editor/Editor.h>
#include <NotUneal/Scene/Scene.h>

using namespace NotUneal;

int main() {
    Editor editor;
    editor.Initialize();
    editor.CreateNewProject("MyGame", "MyGame");
    
    auto scene = editor.CreateNewScene("MainScene");
    auto cube = scene->CreateGameObject("Cube");
    cube->AddComponent<MeshComponent>();
    
    editor.SaveProject();
    return 0;
}
```

## 🎨 Shader Editor Example

```cpp
ShaderGraph shader("MyShader");

// Add nodes
auto posInput = shader.AddNode(std::make_shared<VertexInputNode>(
    VertexInputNode::InputType::Position));
auto colorMult = shader.AddNode(std::make_shared<MathNode>(MathNode::MathOp::Multiply));
auto output = shader.AddNode(std::make_shared<OutputNode>());

// Connect nodes
colorMult->ConnectInput(0, posInput->GetNodeID(), 0);
output->ConnectInput(0, colorMult->GetNodeID(), 0);

// Compile
std::string vertexShader, fragmentShader;
if (shader.Compile(vertexShader, fragmentShader)) {
    // Use compiled shaders
}
```

## 📦 Asset Packaging

```cpp
AssetPackage package;

// Add meshes and textures
package.AddAsset(MESH_ID_CUBE, "Mesh", meshData, meshSize);
package.AddAsset(TEXTURE_ID_WOOD, "Texture", textureData, textureSize);

// Save package
package.CreatePackage("game_assets.npkg");

// Runtime loading
AssetManager::Get().LoadAssetPackage("game_assets.npkg");
auto mesh = AssetManager::Get().LoadMesh(MESH_ID_CUBE);
```

## 🎮 Game Framework Usage

```cpp
GameFramework game;
game.Initialize();

auto scene = std::make_shared<Scene>("GameScene");
auto player = scene->CreateGameObject("Player");
player->AddTag("player");

game.LoadScene(scene);

// Main loop
while (running) {
    float deltaTime = GetDeltaTime();
    game.Update(deltaTime);
    game.Render();
}
```

## 🛠️ Building Games

```cpp
BuildSystem::BuildConfig config;
config.OutputPath = "./Builds/Game";
config.Platform = "Windows";
config.DebugBuild = false;
config.OptimizeAssets = true;

if (BuildSystem::BuildGame("./MyGameProject", config)) {
    // Executable ready for distribution
}
```

## 📚 Key Classes

### Core
- `GameObject` - Base class for all scene objects
- `Component` - Base class for all components
- `Scene` - Container for GameObjects
- `SceneManager` - Global scene management

### Rendering
- `Renderer` - Main rendering system
- `Camera` - View and projection management
- `Material` - Shader properties and textures
- `Mesh` - Geometry and buffers
- `Shader` & `ShaderProgram` - GLSL compilation

### Components
- `TransformComponent` - Position, rotation, scale
- `MeshComponent` - Mesh rendering
- `LightComponent` - Lighting (Directional/Point/Spot)

### Shader System
- `ShaderNode` - Base node for shader graphs
- `ShaderGraph` - Collection of nodes
- `VertexInputNode` - Vertex data inputs
- `TextureSamplerNode` - Texture sampling
- `MathNode` - Mathematical operations
- `OutputNode` - Final output

### Assets
- `AssetManager` - Global asset loading
- `AssetPackage` - Binary asset format
- `MeshImporter` - FBX, GLTF, OBJ import
- `TextureImporter` - PNG, JPEG, TGA, HDR import

### Framework
- `GameFramework` - Game loop and lifecycle
- `InputSystem` - Input handling
- `Editor` - Main editor application
- `EditorViewport` - Scene preview

## 🔧 Extension Points

### Custom Components

```cpp
class MyComponent : public Component {
public:
    void OnCreate() override { /* Initialize */ }
    void Update(float deltaTime) override { /* Game logic */ }
    std::string GetComponentName() const override { return "MyComponent"; }
};
```

### Custom Shader Nodes

```cpp
class MyShaderNode : public ShaderNode {
public:
    MyShaderNode() : ShaderNode(NodeType::Custom, "MyNode") {}
    std::string GenerateGLSL() const override { return "// Custom GLSL"; }
};
```

### Asset Importers

Extend `MeshImporter` or `TextureImporter` for custom formats.

## 📖 Documentation

- [Architecture Guide](Documentation/ARCHITECTURE.md) - System design
- [Getting Started](Documentation/GETTING_STARTED.md) - Build and setup
- [Roadmap](ROADMAP.md) - Future features and milestones

## 🤝 Contributing

Contributions are welcome! Areas for enhancement:
- Physics engine integration
- Audio system
- Advanced lighting (PBR, Global Illumination)
- Particle systems
- Animation system
- UI framework
- Scripting language

## 📝 License

MIT License - See LICENSE file for details

## 🎯 Next Steps

1. Implement physics engine (Bullet or similar)
2. Add particle system
3. Create UI framework
4. Build scripting support
5. Advanced shader features (compute shaders, ray tracing)
6. Performance optimization and profiling tools
7. Multiplayer networking framework

---

**Made with ❤️ for game developers everywhere**
