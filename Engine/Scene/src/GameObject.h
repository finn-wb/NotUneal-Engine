#pragma once

#include "Core/Types.h"
#include "Component.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

namespace NotUneal {

class Component;
class TransformComponent;

/**
 * Base class for all objects in a scene.
 * Every actor (mesh, light, camera, etc.) inherits from GameObject.
 */
class NOTUNEAL_EXPORT GameObject : public std::enable_shared_from_this<GameObject> {
public:
    GameObject(const std::string& name = "GameObject");
    virtual ~GameObject();
    
    // Identity and naming
    void SetName(const std::string& name) { mName = name; }
    const std::string& GetName() const { return mName; }
    UUID GetUUID() const { return mUUID; }
    
    // Hierarchy
    void SetParent(std::shared_ptr<GameObject> parent);
    std::shared_ptr<GameObject> GetParent() const { return mParent.lock(); }
    
    void AddChild(std::shared_ptr<GameObject> child);
    void RemoveChild(std::shared_ptr<GameObject> child);
    const std::vector<std::shared_ptr<GameObject>>& GetChildren() const { return mChildren; }
    
    // Tags for grouping
    void AddTag(const std::string& tag);
    void RemoveTag(const std::string& tag);
    bool HasTag(const std::string& tag) const;
    const std::vector<std::string>& GetTags() const { return mTags; }
    
    // Components - every GameObject has a TransformComponent by default
    template<typename T>
    std::shared_ptr<T> AddComponent() {
        auto component = std::make_shared<T>();
        component->SetOwner(shared_from_this());
        component->OnCreate();
        mComponents.push_back(component);
        return component;
    }
    
    template<typename T>
    std::shared_ptr<T> GetComponent() const {
        for (const auto& comp : mComponents) {
            if (auto castedComp = std::dynamic_pointer_cast<T>(comp)) {
                return castedComp;
            }
        }
        return nullptr;
    }
    
    std::shared_ptr<TransformComponent> GetTransform() const { return mTransform; }
    
    // Serialization
    virtual std::string Serialize() const;
    virtual void Deserialize(const std::string& data);
    
    // Lifecycle
    virtual void OnCreate() {}
    virtual void OnDestroy() {}
    virtual void Update(float deltaTime);
    virtual void Render();
    
    // Active state
    void SetActive(bool active) { mActive = active; }
    bool IsActive() const { return mActive; }
    
private:
    UUID mUUID;
    std::string mName;
    bool mActive;
    
    std::weak_ptr<GameObject> mParent;
    std::vector<std::shared_ptr<GameObject>> mChildren;
    std::vector<std::string> mTags;
    
    std::shared_ptr<TransformComponent> mTransform;
    std::vector<std::shared_ptr<Component>> mComponents;
};

} // namespace NotUneal
