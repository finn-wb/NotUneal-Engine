# Asset Management Guide

## Asset Packaging

NotUneal uses a custom binary format (.npkg) for efficient asset distribution:

```cpp
AssetPackage package;

// Import and add assets
package.AddAsset(MESH_ID_PLAYER, "Mesh", playerMeshData, playerMeshSize);
package.AddAsset(TEXTURE_ID_PLAYER, "Texture", playerTexData, playerTexSize);
package.AddAsset(MAT_ID_PLAYER, "Material", playerMatData, playerMatSize);

// Save package
if (!package.CreatePackage("game_assets.npkg")) {
    std::cerr << "Failed to create asset package" << std::endl;
}
```

## Runtime Asset Loading

```cpp
// Load package
AssetManager::Get().LoadAssetPackage("game_assets.npkg");

// Query assets
if (AssetManager::Get().HasAsset(MESH_ID_PLAYER)) {
    auto mesh = AssetManager::Get().LoadMesh(MESH_ID_PLAYER);
    auto texture = AssetManager::Get().LoadTexture(TEXTURE_ID_PLAYER);
}
```

## Importing Meshes

### FBX Import
```cpp
MeshImporter::ImportSettings settings;
settings.GenerateNormals = true;
settings.GenerateTangents = true;
settings.Scale = 1.0f;

if (MeshImporter::ImportFBX("model.fbx", settings)) {
    // Mesh ready for use
}
```

### GLTF Import
```cpp
if (MeshImporter::ImportGLTF("model.glb", settings)) {
    // Supports both .glb and .gltf
}
```

### OBJ Import
```cpp
if (MeshImporter::ImportOBJ("model.obj", settings)) {
    // Basic OBJ support
}
```

## Importing Textures

### PNG Import
```cpp
TextureImporter::ImportSettings texSettings;
texSettings.GenerateMipmaps = true;
texSettings.CompressTexture = true;
texSettings.CompressionFormat = "BC7";

if (TextureImporter::ImportPNG("texture.png", texSettings)) {
    // Texture ready
}
```

### JPEG Import
```cpp
TextureImporter::ImportJPEG("photo.jpg", texSettings);
```

### TGA Import
```cpp
TextureImporter::ImportTGA("texture.tga", texSettings);
```

### HDR Import
```cpp
texSettings.CompressionFormat = ""; // Don't compress HDR
TextureImporter::ImportHDR("environment.hdr", texSettings);
```

## Asset Organization

### Directory Structure
```
Assets/
├── Meshes/
│   ├── Characters/
│   ├── Environments/
│   └── Props/
├── Textures/
│   ├── Diffuse/
│   ├── Normal/
│   ├── Metallic/
│   └── Roughness/
├── Materials/
├── Shaders/
└── Audio/
```

## Asset Metadata

```cpp
const AssetMetadata* meta = AssetManager::Get().GetAssetMetadata(MESH_ID_PLAYER);
if (meta) {
    std::cout << "Asset: " << meta->AssetName << std::endl;
    std::cout << "Type: " << meta->AssetType << std::endl;
    std::cout << "Modified: " << meta->LastModifiedTime << std::endl;
}
```

## Caching Strategy

Assets are automatically cached in memory:

```cpp
// Load once, use multiple times
auto texture = AssetManager::Get().LoadTexture(TEXTURE_ID);
// Subsequent calls return cached version
auto textureAgain = AssetManager::Get().LoadTexture(TEXTURE_ID);

// Clear cache when needed
AssetManager::Get().ClearCache();
```

## Package Format Specification

```cpp
struct Header {
    char signature[4];      // "NPKG"
    uint32_t version;       // 1
    uint32_t assetCount;    // Number of assets
    uint32_t metadataSize;  // Metadata section size
};

struct AssetEntry {
    uint64_t assetID;       // Unique identifier
    uint32_t offset;        // Byte offset in package
    uint32_t size;          // Asset size in bytes
    char type[32];          // Asset type string
};
```

## Performance Tips

1. **Batch Loading**: Load multiple assets at once
2. **Streaming**: Load assets as needed
3. **Compression**: Use texture compression
4. **LODs**: Create level-of-detail versions
5. **Cleanup**: Unload unused assets

## Asset Pipeline Workflow

```
Source Assets (FBX, PNG, etc.)
    ↓
Import Tools (MeshImporter, TextureImporter)
    ↓
Optimize/Process
    ↓
Asset Package (.npkg)
    ↓
Runtime Loading (AssetManager)
    ↓
In-Game Use
```
