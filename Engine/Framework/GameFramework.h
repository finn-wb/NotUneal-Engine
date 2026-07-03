#pragma once

#include "Scene/Scene.h"
#include <memory>
#include <vector>
#include <string>

namespace NotUneal {

/**
 * Framework for managing game objects and scenes.
 */
class NOTUNEAL_EXPORT GameFramework {
public:
    GameFramework();
    ~GameFramework() = default;
    
    // Lifecycle
    bool Initialize();
    void Shutdown();
    
    // Game loop
    void Update(float deltaTime);
    void Render();
    
    // Scene management
    std::shared_ptr<Scene> GetCurrentScene() const { return mCurrentScene; }
    void LoadScene(const std::shared_ptr<Scene>& scene);
    void LoadSceneByName(const std::string& sceneName);
    
    // Object finding
    std::shared_ptr<GameObject> FindObjectByTag(const std::string& tag) const;
    std::vector<std::shared_ptr<GameObject>> FindObjectsByTag(const std::string& tag) const;
    std::shared_ptr<GameObject> FindObjectByName(const std::string& name) const;
    
    // Time
    float GetDeltaTime() const { return mDeltaTime; }
    float GetTotalTime() const { return mTotalTime; }
    
private:
    std::shared_ptr<Scene> mCurrentScene;
    float mDeltaTime;
    float mTotalTime;
};

} // namespace NotUneal
