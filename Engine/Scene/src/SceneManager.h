#pragma once

#include "Scene.h"
#include <unordered_map>
#include <memory>
#include <string>

namespace NotUneal {

/**
 * Manages all scenes in the engine.
 * Singleton that handles scene lifecycle and switching.
 */
class NOTUNEAL_EXPORT SceneManager {
public:
    static SceneManager& Get();
    
    std::shared_ptr<Scene> CreateScene(const std::string& name);
    void DestroyScene(const std::string& name);
    std::shared_ptr<Scene> GetScene(const std::string& name) const;
    std::shared_ptr<Scene> GetActiveScene() const { return mActiveScene; }
    
    void SetActiveScene(const std::string& name);
    
    void Update(float deltaTime);
    void Render();
    
private:
    SceneManager() = default;
    
    std::unordered_map<std::string, std::shared_ptr<Scene>> mScenes;
    std::shared_ptr<Scene> mActiveScene;
};

} // namespace NotUneal
