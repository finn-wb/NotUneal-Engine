# Frequently Asked Questions

## General

### What is NotUneal Engine?
NotUneal is a lightweight, open-source game engine inspired by Unreal Engine but drastically simplified. It provides core game development features including rendering, scene management, asset handling, and an editor.

### Who is NotUneal for?
- Indie game developers
- Students learning game development
- Developers wanting a custom game engine
- Programmers interested in graphics and game systems

### Is NotUneal production-ready?
NotUneal is in early development (v0.1.0). While the core systems are functional, it lacks some features needed for large productions. It's ideal for learning, prototyping, and small projects.

## Getting Started

### How do I install NotUneal?
```bash
git clone https://github.com/finn-wb/NotUneal-Engine.git
cd NotUneal-Engine
mkdir build && cd build
cmake ..
cmake --build .
```

### What do I need to build NotUneal?
- CMake 3.16+
- C++17 compiler (MSVC, GCC, Clang)
- OpenGL development files
- Optional: Qt6 for editor

### How do I create my first game?
See `Examples/SimpleScene.cpp` for a basic 3D scene setup, or check `Documentation/GETTING_STARTED.md`.

## Development

### How do I create custom components?
```cpp
class MyComponent : public Component {
public:
    void Update(float deltaTime) override {
        // Your logic here
    }
    std::string GetComponentName() const override { return "MyComponent"; }
};
```

### How do I add custom shaders?
Use the visual shader editor or create directly:
```cpp
auto vertexShader = std::make_shared<Shader>(Shader::Type::Vertex, code);
vertexShader->Compile();
```

### How do I load assets?
```cpp
AssetManager::Get().LoadAssetPackage("assets.npkg");
auto mesh = AssetManager::Get().LoadMesh(MESH_ID);
```

### How do I handle input?
```cpp
if (InputSystem::Get().IsKeyPressed(InputSystem::Key::W)) {
    // Handle W key
}
```

### How do I manage scenes?
```cpp
auto scene = std::make_shared<Scene>("MyScene");
auto obj = scene->CreateGameObject("MyObject");
game.LoadScene(scene);
```

## Rendering & Graphics

### What rendering API does NotUneal use?
OpenGL 4.6 core profile.

### Can I use other graphics APIs?
Not currently, but the renderer abstraction is designed to support multiple backends.

### How do I optimize rendering?
- Use material batching
- Implement frustum culling
- Use texture compression
- Keep shader complexity reasonable

### How do I create materials?
```cpp
auto material = std::make_shared<Material>(shaderProgram);
material->SetTexture("diffuse", texture);
material->SetColor("color", Color(1, 1, 1));
```

## Shader Editor

### How does the shader editor work?
It's a node-based visual system. Add nodes (inputs, math, textures), connect them, and compile to GLSL.

### What node types are available?
- Input nodes (Position, Normal, TexCoord, etc.)
- Math nodes (Add, Multiply, Dot, Normalize, etc.)
- Texture sampling
- Custom GLSL
- Output

### Can I write custom shaders directly?
Yes, create Shader objects with GLSL code directly:
```cpp
auto shader = std::make_shared<Shader>(Shader::Type::Fragment, glslCode);
```

## Assets

### What asset formats are supported?
- Meshes: FBX, GLTF, OBJ (stubs - need implementation)
- Textures: PNG, JPEG, TGA, HDR (stubs - need implementation)

### How do I package assets?
```cpp
AssetPackage pkg;
pkg.AddAsset(ID, "Mesh", data, size);
pkg.CreatePackage("assets.npkg");
```

### How do I optimize assets?
- Use texture compression
- Generate mipmaps
- Use LOD meshes
- Remove unused vertices

## Editor

### Is there a visual editor?
Basic framework exists. Qt UI implementation is in progress.

### Can I edit scenes programmatically?
Yes, create scenes and objects through code:
```cpp
auto scene = std::make_shared<Scene>();
auto obj = scene->CreateGameObject("MyObject");
```

## Building & Distribution

### How do I build my game?
```cpp
BuildSystem::BuildConfig config;
config.OutputPath = "./Build";
config.Platform = "Windows";
BuildSystem::BuildGame("./Project", config);
```

### What platforms are supported?
- Windows (primary)
- Linux
- WebGL (experimental)

### Can I distribute my game?
Yes! NotUneal uses the MIT license, allowing commercial use.

## Performance

### Is NotUneal fast?
It's designed for reasonable performance with good architecture. Performance depends on scene complexity and optimization.

### How do I profile my game?
Current: Use external profilers. Future: Built-in profiler coming.

### Can NotUneal handle large games?
NotUneal works well for small to medium projects. Large AAA games would need additional systems (physics, advanced culling, LOD management).

## Troubleshooting

### CMake fails to find OpenGL
```bash
# Linux
sudo apt-get install libgl1-mesa-dev

# macOS
brew install glfw glew

# Windows
# Usually comes with Visual Studio
```

### Shader compilation fails
- Check GLSL syntax
- Verify uniform names match
- Ensure attribute locations are correct
- Check version (#version 460 core)

### Assets won't load
- Verify package file exists
- Check asset IDs match
- Ensure AssetManager is initialized
- Check file permissions

## Contributing

### How do I contribute?
See CONTRIBUTING.md for guidelines.

### What areas need help?
- Asset importers (FBX, GLTF, image loaders)
- Physics engine integration
- Particle system
- Animation system
- UI framework
- Documentation and examples

## License & Legal

### What license does NotUneal use?
MIT License - free for personal and commercial use.

### Can I use NotUneal commercially?
Yes! MIT license allows commercial use.

### Do I need to credit NotUneal?
Not required by license, but appreciated!

## Advanced

### How do I extend the engine?
All systems are designed for extension:
- Custom components
- Custom shader nodes
- Custom asset importers
- Custom rendering systems

### Can I use NotUneal with my existing code?
Yes, use the NotUneal::Engine library alongside your code.

### How do I debug the engine?
- Enable debug builds (NOTUNEAL_BUILD_DEBUG)
- Use external debuggers (GDB, MSVC Debugger)
- Add logging statements
- Check compiler warnings

## More Questions?

- Check the documentation files
- Review example projects
- Open an issue on GitHub
- Start a discussion
- Contact maintainers

---

Last updated: July 2026
Version: 0.1.0
