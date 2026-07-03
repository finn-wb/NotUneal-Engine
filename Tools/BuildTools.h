#pragma once

#include <string>
#include <memory>
#include <vector>

namespace NotUneal {

/**
 * Asset importer for importing meshes from external formats.
 */
class NOTUNEAL_EXPORT MeshImporter {
public:
    struct ImportSettings {
        bool GenerateNormals;
        bool GenerateTangents;
        bool FlipNormals;
        float Scale;
    };
    
    static bool ImportFBX(const std::string& filePath, const ImportSettings& settings = {});
    static bool ImportGLTF(const std::string& filePath, const ImportSettings& settings = {});
    static bool ImportOBJ(const std::string& filePath, const ImportSettings& settings = {});
};

/**
 * Asset importer for importing textures.
 */
class NOTUNEAL_EXPORT TextureImporter {
public:
    struct ImportSettings {
        bool GenerateMipmaps;
        bool CompressTexture;
        std::string CompressionFormat; // "BC1", "BC7", etc.
    };
    
    static bool ImportPNG(const std::string& filePath, const ImportSettings& settings = {});
    static bool ImportJPEG(const std::string& filePath, const ImportSettings& settings = {});
    static bool ImportTGA(const std::string& filePath, const ImportSettings& settings = {});
    static bool ImportHDR(const std::string& filePath, const ImportSettings& settings = {});
};

/**
 * Build system for packaging games.
 */
class NOTUNEAL_EXPORT BuildSystem {
public:
    struct BuildConfig {
        std::string OutputPath;
        std::string Platform; // "Windows", "Linux", "WebGL"
        bool DebugBuild;
        bool OptimizeAssets;
    };
    
    static bool BuildGame(const std::string& projectPath, const BuildConfig& config);
    static bool CompileUserCode(const std::string& projectPath);
    static bool PackageAssets(const std::string& projectPath, const std::string& outputPath);
};

} // namespace NotUneal
