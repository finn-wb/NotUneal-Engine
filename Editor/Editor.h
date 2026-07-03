#pragma once

#include "ProjectSettings.h"
#include "EditorViewport.h"
#include "Scene/Scene.h"
#include <memory>
#include <string>
#include <vector>

namespace NotUneal {

/**
 * Main editor application.
 */
class NOTUNEAL_EXPORT Editor {
public:
    Editor();
    ~Editor();
    
    bool Initialize();
    void Shutdown();
    
    // Project management
    bool CreateNewProject(const std::string& projectPath, const std::string& projectName);
    bool OpenProject(const std::string& projectPath);
    bool SaveProject();
    
    // Scene management
    std::shared_ptr<Scene> CreateNewScene(const std::string& sceneName);
    bool SaveScene(const std::shared_ptr<Scene>& scene);
    bool LoadScene(const std::string& scenePath);
    
    // Editor state
    const ProjectSettings& GetProjectSettings() const { return mProjectSettings; }
    const std::shared_ptr<EditorViewport>& GetViewport() const { return mViewport; }
    
    bool IsProjectOpen() const { return mProjectOpen; }
    bool IsPlayMode() const { return mPlayMode; }
    
    void Play();
    void Stop();
    void Pause();
    
    // Building
    bool BuildGame(const std::string& outputPath);
    
private:
    ProjectSettings mProjectSettings;
    std::shared_ptr<EditorViewport> mViewport;
    
    bool mProjectOpen;
    bool mPlayMode;
    
    std::vector<std::shared_ptr<Scene>> mOpenScenes;
    std::shared_ptr<Scene> mCurrentScene;
};

} // namespace NotUneal
