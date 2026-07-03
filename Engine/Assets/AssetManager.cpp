#include "AssetManager.h"
#include "Rendering/Texture.h"
#include "Rendering/Mesh.h"
#include "Rendering/Material.h"

namespace NotUneal {

AssetManager& AssetManager::Get() {
    static AssetManager instance;
    return instance;
}

bool AssetManager::LoadAssetPackage(const std::string& packagePath) {
    auto package = std::make_shared<AssetPackage>();
    if (!package->LoadPackage(packagePath)) {
        return false;
    }
    
    mLoadedPackages[packagePath] = package;
    return true;
}

void AssetManager::UnloadAssetPackage(const std::string& packagePath) {
    auto it = mLoadedPackages.find(packagePath);
    if (it != mLoadedPackages.end()) {
        mLoadedPackages.erase(it);
    }
}

std::shared_ptr<Texture> AssetManager::LoadTexture(uint64_t assetID) {
    auto it = mTextureCache.find(assetID);
    if (it != mTextureCache.end()) {
        return it->second;
    }
    
    // TODO: Load from asset package
    return nullptr;
}

std::shared_ptr<Mesh> AssetManager::LoadMesh(uint64_t assetID) {
    auto it = mMeshCache.find(assetID);
    if (it != mMeshCache.end()) {
        return it->second;
    }
    
    // TODO: Load from asset package
    return nullptr;
}

std::shared_ptr<Material> AssetManager::LoadMaterial(uint64_t assetID) {
    auto it = mMaterialCache.find(assetID);
    if (it != mMaterialCache.end()) {
        return it->second;
    }
    
    // TODO: Load from asset package
    return nullptr;
}

bool AssetManager::HasAsset(uint64_t assetID) const {
    for (const auto& [path, package] : mLoadedPackages) {
        uint32_t size = 0;
        if (package->GetAsset(assetID, size) != nullptr) {
            return true;
        }
    }
    return false;
}

const AssetMetadata* AssetManager::GetAssetMetadata(uint64_t assetID) const {
    for (const auto& [path, package] : mLoadedPackages) {
        auto metadata = package->GetAssetMetadata(assetID);
        if (metadata) {
            return metadata;
        }
    }
    return nullptr;
}

void AssetManager::ClearCache() {
    mTextureCache.clear();
    mMeshCache.clear();
    mMaterialCache.clear();
}

} // namespace NotUneal
