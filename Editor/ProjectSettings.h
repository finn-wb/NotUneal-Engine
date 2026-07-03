#pragma once

#include <string>
#include <memory>
#include <vector>

namespace NotUneal {

/**
 * Project configuration and metadata.
 */
class NOTUNEAL_EXPORT ProjectSettings {
public:
    struct ProjectConfig {
        std::string ProjectName;
        std::string ProjectPath;
        std::string StartScene;
        uint32_t TargetWidth;
        uint32_t TargetHeight;
        std::string TargetPlatform; // "Windows", "Linux", "WebGL", etc.
    };
    
    ProjectSettings();
    
    bool LoadProjectConfig(const std::string& projectPath);
    bool SaveProjectConfig();
    
    const ProjectConfig& GetConfig() const { return mConfig; }
    void SetConfig(const ProjectConfig& config) { mConfig = config; }
    
private:
    ProjectConfig mConfig;
};

} // namespace NotUneal
