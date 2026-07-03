#pragma once

#include "GameObject.h"
#include <vector>
#include <string>
#include <memory>

namespace NotUneal {

/**
 * A scene contains a collection of GameObjects.
 */
class NOTUNEAL_EXPORT Scene : public std::enable_shared_from_this<Scene> {
public:
    Scene(const std::string& name = "Scene");
    ~Scene() = default;
    
    const std::string& GetName() const { return mName; }
    void SetName(const std::string& name) { mName = name; }
    
    // Object management
    std::shared_ptr<GameObject> CreateGameObject(const std::string& name = "GameObject");
    void DestroyGameObject(std::shared_ptr<GameObject> object);
    void Clear();
    
    // Finding objects
    std::shared_ptr<GameObject> FindByName(const std::string& name) const;
    std::shared_ptr<GameObject> FindByUUID(UUID uuid) const;
    std::vector<std::shared_ptr<GameObject>> FindByTag(const std::string& tag) const;
    
    const std::vector<std::shared_ptr<GameObject>>& GetRootObjects() const { return mRootObjects; }
    
    // Lifecycle
    void Update(float deltaTime);
    void Render();
    
    // Serialization
    std::string Serialize() const;
    void Deserialize(const std::string& data);
    
private:
    std::string mName;
    std::vector<std::shared_ptr<GameObject>> mRootObjects;
    std::vector<std::shared_ptr<GameObject>> mAllObjects; // Flat list for searching
};

} // namespace NotUneal
