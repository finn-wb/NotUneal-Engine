#include "SceneManager.h"

namespace NotUneal {

SceneManager& SceneManager::Get() {
    static SceneManager instance;
    return instance;
}

std::shared_ptr<Scene> SceneManager::CreateScene(const std::string& name) {
    auto scene = std::make_shared<Scene>(name);
    mScenes[name] = scene;
    return scene;
}

void SceneManager::DestroyScene(const std::string& name) {
    auto it = mScenes.find(name);
    if (it != mScenes.end()) {
        if (mActiveScene == it->second) {
            mActiveScene = nullptr;
        }
        mScenes.erase(it);
    }
}

std::shared_ptr<Scene> SceneManager::GetScene(const std::string& name) const {
    auto it = mScenes.find(name);
    if (it != mScenes.end()) {
        return it->second;
    }
    return nullptr;
}

void SceneManager::SetActiveScene(const std::string& name) {
    auto scene = GetScene(name);
    if (scene) {
        mActiveScene = scene;
    }
}

void SceneManager::Update(float deltaTime) {
    if (mActiveScene) {
        mActiveScene->Update(deltaTime);
    }
}

void SceneManager::Render() {
    if (mActiveScene) {
        mActiveScene->Render();
    }
}

} // namespace NotUneal
