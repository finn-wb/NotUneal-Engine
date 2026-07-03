#include "Editor.h"
#include "Framework/GameFramework.h"
#include <filesystem>

namespace NotUneal {

Editor::Editor()
    : mProjectOpen(false), mPlayMode(false) {}

Editor::~Editor() {}

bool Editor::Initialize() {
    mViewport = std::make_shared<EditorViewport>();
    if (!mViewport->Initialize(1920, 1080)) {
        return false;
    }
    
    return true;
}

void Editor::Shutdown() {
    if (mProjectOpen) {
        SaveProject();
    }
}

bool Editor::CreateNewProject(const std::string& projectPath, const std::string& projectName) {
    // Create project directory structure
    std::filesystem::create_directories(projectPath + "/Scenes");
    std::filesystem::create_directories(projectPath + "/Assets");
    std::filesystem::create_directories(projectPath + "/Code");
    std::filesystem::create_directories(projectPath + "/Build");
    
    // Set project config
    auto config = mProjectSettings.GetConfig();
    config.ProjectName = projectName;
    config.ProjectPath = projectPath;
    mProjectSettings.SetConfig(config);
    
    mProjectOpen = true;
    return mProjectSettings.SaveProjectConfig();
}

bool Editor::OpenProject(const std::string& projectPath) {
    if (!mProjectSettings.LoadProjectConfig(projectPath)) {
        return false;
    }
    
    mProjectOpen = true;
    return true;
}

bool Editor::SaveProject() {
    return mProjectSettings.SaveProjectConfig();
}

std::shared_ptr<Scene> Editor::CreateNewScene(const std::string& sceneName) {
    auto scene = std::make_shared<Scene>(sceneName);
    mOpenScenes.push_back(scene);
    mCurrentScene = scene;
    mViewport->SetScene(scene);
    return scene;
}

bool Editor::SaveScene(const std::shared_ptr<Scene>& scene) {
    // TODO: Serialize scene to file
    return true;
}

bool Editor::LoadScene(const std::string& scenePath) {
    // TODO: Load scene from file
    return true;
}

void Editor::Play() {
    mPlayMode = true;
    // TODO: Start game simulation
}

void Editor::Stop() {
    mPlayMode = false;
    // TODO: Stop game simulation
}

void Editor::Pause() {
    // TODO: Pause/unpause simulation
}

bool Editor::BuildGame(const std::string& outputPath) {
    // TODO: Package game for distribution
    // 1. Compile user code
    // 2. Package assets
    // 3. Generate executable
    return true;
}

} // namespace NotUneal
