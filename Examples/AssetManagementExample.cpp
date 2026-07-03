# Example: Asset Management

This example shows how to import, package, and load assets at runtime.

```cpp
#include <NotUneal/Engine.h>
#include <NotUneal/Tools/BuildTools.h>
#include <NotUneal/Assets/AssetManager.h>
#include <iostream>

using namespace NotUneal;

int main() {
    // ========== ASSET IMPORT PHASE ==========
    
    std::cout << "Importing assets..." << std::endl;
    
    // Import mesh
    MeshImporter::ImportSettings meshSettings;
    meshSettings.GenerateNormals = true;
    meshSettings.GenerateTangents = true;
    meshSettings.Scale = 1.0f;
    
    if (!MeshImporter::ImportFBX("assets/player_model.fbx", meshSettings)) {
        std::cerr << "Failed to import FBX" << std::endl;
        return -1;
    }
    
    // Import textures
    TextureImporter::ImportSettings texSettings;
    texSettings.GenerateMipmaps = true;
    texSettings.CompressTexture = true;
    texSettings.CompressionFormat = "BC7";
    
    if (!TextureImporter::ImportPNG("assets/player_diffuse.png", texSettings)) {
        std::cerr << "Failed to import texture" << std::endl;
        return -1;
    }
    
    // ========== ASSET PACKAGING PHASE ==========
    
    std::cout << "Creating asset package..." << std::endl;
    
    AssetPackage package;
    
    // Load imported assets and add to package
    // (In a real scenario, the importer would return asset data)
    const uint64_t MESH_ID_PLAYER = 1001;
    const uint64_t TEXTURE_ID_DIFFUSE = 2001;
    
    // Simulated asset data
    uint8_t meshData[] = { /* mesh vertex data */ };
    uint8_t textureData[] = { /* texture pixel data */ };
    
    package.AddAsset(MESH_ID_PLAYER, "Mesh", meshData, sizeof(meshData));
    package.AddAsset(TEXTURE_ID_DIFFUSE, "Texture", textureData, sizeof(textureData));
    
    if (!package.CreatePackage("game_assets.npkg")) {
        std::cerr << "Failed to create asset package" << std::endl;
        return -1;
    }
    
    std::cout << "Asset package created: game_assets.npkg" << std::endl;
    
    // ========== RUNTIME LOADING PHASE ==========
    
    std::cout << "Loading assets at runtime..." << std::endl;
    
    // Load package
    if (!AssetManager::Get().LoadAssetPackage("game_assets.npkg")) {
        std::cerr << "Failed to load asset package" << std::endl;
        return -1;
    }
    
    // Query assets
    if (!AssetManager::Get().HasAsset(MESH_ID_PLAYER)) {
        std::cerr << "Player mesh not found in package" << std::endl;
        return -1;
    }
    
    // Load specific assets
    auto playerMesh = AssetManager::Get().LoadMesh(MESH_ID_PLAYER);
    auto playerDiffuse = AssetManager::Get().LoadTexture(TEXTURE_ID_DIFFUSE);
    
    if (!playerMesh || !playerDiffuse) {
        std::cerr << "Failed to load assets" << std::endl;
        return -1;
    }
    
    std::cout << "Assets loaded successfully!" << std::endl;
    
    // Use assets in scene
    auto scene = std::make_shared<Scene>("GameScene");
    auto player = scene->CreateGameObject("Player");
    auto meshComp = player->AddComponent<MeshComponent>();
    meshComp->SetMesh(playerMesh);
    
    // Asset metadata
    const AssetMetadata* metadata = AssetManager::Get().GetAssetMetadata(MESH_ID_PLAYER);
    if (metadata) {
        std::cout << "Asset Name: " << metadata->AssetName << std::endl;
        std::cout << "Asset Type: " << metadata->AssetType << std::endl;
    }
    
    return 0;
}
```

Compile with:
```bash
g++ -std=c++17 -I./Engine example_assets.cpp -o example_assets -lNotUnealEngine -lNotUnealTools
```
