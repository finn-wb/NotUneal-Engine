#pragma once

#include "Core/Core.h"
#include <memory>
#include <string>

namespace NotUneal {

class GameObject;

/**
 * Base class for all components.
 * Components add functionality to GameObjects.
 */
class NOTUNEAL_EXPORT Component : public std::enable_shared_from_this<Component> {
public:
    virtual ~Component() = default;
    
    std::shared_ptr<GameObject> GetOwner() const { return mOwner.lock(); }
    void SetOwner(std::shared_ptr<GameObject> owner) { mOwner = owner; }
    
    virtual void OnCreate() {}
    virtual void OnDestroy() {}
    virtual void Update(float deltaTime) {}
    virtual void Render() {}
    
    virtual std::string GetComponentName() const = 0;
    
protected:
    std::weak_ptr<GameObject> mOwner;
};

} // namespace NotUneal
