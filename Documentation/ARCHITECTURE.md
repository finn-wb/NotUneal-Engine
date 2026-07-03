# NotUneal Engine Architecture

## Core Components

### 1. Engine Core (`Engine/`)
- **Core**: Foundation types, memory management, containers
- **Math**: Vector, Matrix, Quaternion utilities
- **Scene**: Scene graph, game object hierarchy
- **Components**: Base component system
- **Rendering**: Renderer abstraction, shader system

### 2. Editor (`Editor/`)
- **UI Framework**: Qt-based desktop interface
- **Scene Editor**: Visual scene composition and hierarchy
- **Asset Browser**: Asset management and import
- **Shader Editor**: Visual shader graph builder
- **Project Manager**: Project creation and configuration
- **Build System**: Packaging and compilation pipeline

### 3. Runtime (`Runtime/`)
- **Game Framework**: Object management, systems
- **Input Handler**: Input processing
- **Asset Loader**: Runtime asset loading from packages

### 4. Tools (`Tools/`)
- **Asset Importers**: FBX/GLTF mesh import, texture loading
- **Material Compiler**: Shader compilation and packaging
- **Package Creator**: Asset packaging utility

## GameObject System

Every actor (mesh, light, camera, etc.) inherits from `GameObject`:
- **Transform Component**: Position, rotation, scale (always present)
- **Custom Components**: User-defined behavior through components
- **Properties**: Serializable data for editor exposure

## Rendering Pipeline

1. **Scene Collection**: Gather all renderable objects
2. **Culling**: Frustum and occlusion culling
3. **Sorting**: Material and depth sorting
4. **Rendering**: Draw calls with bound materials and shaders
5. **Post-Processing**: Optional post-process effects

## Shader System

Custom shaders via visual node editor:
- **Input Nodes**: Vertex data, textures, parameters
- **Processing Nodes**: Math, sampling, transforms
- **Output Nodes**: Final color, normal, etc.
- **Compilation**: Converted to GLSL/HLSL at build time
