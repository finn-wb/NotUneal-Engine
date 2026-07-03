#pragma once

#include "Component.h"
#include "Core/Types.h"

namespace NotUneal {

class NOTUNEAL_EXPORT TransformComponent : public Component {
public:
    TransformComponent();
    ~TransformComponent() override = default;
    
    void SetPosition(const Vec3& pos) { mLocalTransform.position = pos; }
    Vec3 GetPosition() const { return mLocalTransform.position; }
    Vec3 GetWorldPosition() const;
    
    void SetRotation(const Quat& rot) { mLocalTransform.rotation = rot; }
    Quat GetRotation() const { return mLocalTransform.rotation; }
    Quat GetWorldRotation() const;
    
    void SetScale(const Vec3& scale) { mLocalTransform.scale = scale; }
    Vec3 GetScale() const { return mLocalTransform.scale; }
    
    Mat4 GetLocalMatrix() const { return mLocalTransform.GetMatrix(); }
    Mat4 GetWorldMatrix() const;
    
    Vec3 GetForward() const;
    Vec3 GetRight() const;
    Vec3 GetUp() const;
    
    std::string GetComponentName() const override { return "Transform"; }
    
private:
    Transform mLocalTransform;
};

} // namespace NotUneal
