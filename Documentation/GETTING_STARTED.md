# Getting Started with NotUneal Engine

## Prerequisites

- CMake 3.16 or higher
- C++17 compatible compiler (MSVC, GCC, Clang)
- Git

### Dependencies

- GLM (for math) - included or install via package manager
- GLAD/GLEW (for OpenGL) - to be added
- Qt5 or Qt6 (for editor) - optional, for editor development

## Building

### Linux/macOS

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
```

### Windows (MSVC)

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
```

## Project Structure Overview

- `Engine/Core` - Core types and utilities (Math, Types, Memory management)
- `Engine/Scene` - Scene graph and GameObject system
- `Engine/Rendering` - Renderer abstraction (to be implemented)
- `Editor/` - Desktop editor (to be implemented)
- `Tools/` - Asset importers and utilities (to be implemented)
- `Examples/` - Example games and projects (to be added)

## Next Steps

1. Explore the core systems in `Engine/Core` and `Engine/Scene`
2. Implement the Rendering system
3. Create the visual editor
4. Build asset import tools
5. Develop shader editor
6. Create packaging system
