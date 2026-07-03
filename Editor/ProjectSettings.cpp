#include "ProjectSettings.h"
#include <fstream>
#include <sstream>

namespace NotUneal {

ProjectSettings::ProjectSettings() {
    mConfig.ProjectName = "NewProject";
    mConfig.TargetWidth = 1920;
    mConfig.TargetHeight = 1080;
    mConfig.TargetPlatform = "Windows";
}

bool ProjectSettings::LoadProjectConfig(const std::string& projectPath) {
    std::string configPath = projectPath + "/project.notuneal";
    std::ifstream file(configPath);
    if (!file.is_open()) return false;
    
    // TODO: Parse configuration file
    return true;
}

bool ProjectSettings::SaveProjectConfig() {
    // TODO: Serialize configuration to file
    return true;
}

} // namespace NotUneal
