#pragma once

#include "AssetPackage.h"
#include <unordered_map>
#include <memory>
#include <string>

namespace NotUneal {

class Texture;
class Mesh;
class Material;

/**
 * Asset manager for loading and managing game assets.
 */
class NOTUNEAL_EXPORT AssetManager {
public:
    static AssetManager& Get();
    
    // Package management
    bool LoadAssetPackage(const std::string& packagePath);
    void UnloadAssetPackage(const std::string& packagePath);
    
    // Asset loading
    std::shared_ptr<Texture> LoadTexture(uint64_t assetID);
    std::shared_ptr<Mesh> LoadMesh(uint64_t assetID);
    std::shared_ptr<Material> LoadMaterial(uint64_t assetID);
    
    // Asset querying
    bool HasAsset(uint64_t assetID) const;
    const AssetMetadata* GetAssetMetadata(uint64_t assetID) const;
    
    // Cache management
    void ClearCache();
    
private:
    AssetManager() = default;
    
    std::unordered_map<std::string, std::shared_ptr<AssetPackage>> mLoadedPackages;
    std::unordered_map<uint64_t, std::shared_ptr<Texture>> mTextureCache;
    std::unordered_map<uint64_t, std::shared_ptr<Mesh>> mMeshCache;
    std::unordered_map<uint64_t, std::shared_ptr<Material>> mMaterialCache;
};

} // namespace NotUneal
