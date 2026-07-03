#include "AssetPackage.h"
#include <fstream>
#include <cstring>

namespace NotUneal {

AssetPackage::AssetPackage() {
    std::memcpy(mHeader.signature, "NPKG", 4);
    mHeader.version = 1;
    mHeader.assetCount = 0;
    mHeader.metadataSize = 0;
}

AssetPackage::~AssetPackage() {}

bool AssetPackage::CreatePackage(const std::string& outputPath) {
    std::ofstream file(outputPath, std::ios::binary);
    if (!file.is_open()) return false;
    
    // Write header
    file.write((const char*)&mHeader, sizeof(Header));
    
    // Write asset entries
    for (const auto& entry : mAssetEntries) {
        file.write((const char*)&entry, sizeof(AssetEntry));
    }
    
    // Write asset data
    file.write((const char*)mPackageData.data(), mPackageData.size());
    
    file.close();
    return true;
}

bool AssetPackage::LoadPackage(const std::string& packagePath) {
    std::ifstream file(packagePath, std::ios::binary);
    if (!file.is_open()) return false;
    
    // Read header
    file.read((char*)&mHeader, sizeof(Header));
    
    if (std::memcmp(mHeader.signature, "NPKG", 4) != 0) {
        return false; // Invalid package
    }
    
    // Read asset entries
    mAssetEntries.resize(mHeader.assetCount);
    for (uint32_t i = 0; i < mHeader.assetCount; i++) {
        file.read((char*)&mAssetEntries[i], sizeof(AssetEntry));
    }
    
    // Read asset data
    file.seekg(0, std::ios::end);
    uint32_t dataSize = file.tellg() - sizeof(Header) - (mHeader.assetCount * sizeof(AssetEntry));
    file.seekg(sizeof(Header) + (mHeader.assetCount * sizeof(AssetEntry)));
    
    mPackageData.resize(dataSize);
    file.read((char*)mPackageData.data(), dataSize);
    
    file.close();
    return true;
}

void AssetPackage::AddAsset(uint64_t assetID, const std::string& type, const void* data, uint32_t size) {
    AssetEntry entry;
    entry.assetID = assetID;
    entry.offset = mPackageData.size();
    entry.size = size;
    std::strncpy(entry.type, type.c_str(), 31);
    entry.type[31] = '\0';
    
    mAssetEntries.push_back(entry);
    
    const uint8_t* dataPtr = reinterpret_cast<const uint8_t*>(data);
    mPackageData.insert(mPackageData.end(), dataPtr, dataPtr + size);
    
    mHeader.assetCount++;
}

const void* AssetPackage::GetAsset(uint64_t assetID, uint32_t& outSize) const {
    for (const auto& entry : mAssetEntries) {
        if (entry.assetID == assetID) {
            outSize = entry.size;
            return mPackageData.data() + entry.offset;
        }
    }
    outSize = 0;
    return nullptr;
}

const AssetMetadata* AssetPackage::GetAssetMetadata(uint64_t assetID) const {
    for (const auto& meta : mAssetMetadata) {
        if (meta.AssetID == assetID) {
            return &meta;
        }
    }
    return nullptr;
}

} // namespace NotUneal
