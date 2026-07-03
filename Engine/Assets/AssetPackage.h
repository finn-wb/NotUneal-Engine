#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <vector>

namespace NotUneal {

/**
 * Asset metadata for tracking assets in the engine.
 */
struct AssetMetadata {
    uint64_t AssetID;
    std::string AssetPath;
    std::string AssetName;
    std::string AssetType; // "Mesh", "Texture", "Material", etc.
    uint64_t LastModifiedTime;
};

/**
 * Asset package file format.
 * Contains multiple assets packed together for distribution.
 */
class NOTUNEAL_EXPORT AssetPackage {
public:
    struct Header {
        char signature[4]; // "NPKG"
        uint32_t version;
        uint32_t assetCount;
        uint32_t metadataSize;
    };
    
    struct AssetEntry {
        uint64_t assetID;
        uint32_t offset;
        uint32_t size;
        char type[32];
    };
    
    AssetPackage();
    ~AssetPackage();
    
    bool CreatePackage(const std::string& outputPath);
    bool LoadPackage(const std::string& packagePath);
    
    void AddAsset(uint64_t assetID, const std::string& type, const void* data, uint32_t size);
    const void* GetAsset(uint64_t assetID, uint32_t& outSize) const;
    const AssetMetadata* GetAssetMetadata(uint64_t assetID) const;
    
    const std::vector<AssetEntry>& GetAssetEntries() const { return mAssetEntries; }
    
private:
    Header mHeader;
    std::vector<AssetEntry> mAssetEntries;
    std::vector<AssetMetadata> mAssetMetadata;
    std::vector<uint8_t> mPackageData;
};

} // namespace NotUneal
