#include "GameFramework.h"
#include "Rendering/Renderer.h"
#include "Assets/AssetManager.h"

namespace NotUneal {

GameFramework::GameFramework() : mDeltaTime(0.0f), mTotalTime(0.0f) {}

bool GameFramework::Initialize() {
    // Initialize renderer
    if (!Renderer::Get().Initialize(1920, 1080)) {
        return false;
    }
    
    return true;
}

void GameFramework::Shutdown() {
    Renderer::Get().Shutdown();
    AssetManager::Get().ClearCache();
}

void GameFramework::Update(float deltaTime) {
    mDeltaTime = deltaTime;
    mTotalTime += deltaTime;
    
    if (mCurrentScene) {
        mCurrentScene->Update(deltaTime);
    }
}

void GameFramework::Render() {
    Renderer::Get().BeginFrame();
    
    if (mCurrentScene) {
        mCurrentScene->Render();
    }
    
    Renderer::Get().EndFrame();
}

void GameFramework::LoadScene(const std::shared_ptr<Scene>& scene) {
    mCurrentScene = scene;
}

void GameFramework::LoadSceneByName(const std::string& sceneName) {
    // TODO: Load scene from package by name
}

std::shared_ptr<GameObject> GameFramework::FindObjectByTag(const std::string& tag) const {
    if (!mCurrentScene) return nullptr;
    auto results = mCurrentScene->FindByTag(tag);
    return results.empty() ? nullptr : results[0];
}

std::vector<std::shared_ptr<GameObject>> GameFramework::FindObjectsByTag(const std::string& tag) const {
    if (!mCurrentScene) return {};
    return mCurrentScene->FindByTag(tag);
}

std::shared_ptr<GameObject> GameFramework::FindObjectByName(const std::string& name) const {
    if (!mCurrentScene) return nullptr;
    return mCurrentScene->FindByName(name);
}

} // namespace NotUneal
