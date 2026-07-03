#pragma once

#include "Core/Types.h"
#include "Scene/Component.h"

namespace NotUneal {

/**
 * Camera component for rendering scenes.
 */
class NOTUNEAL_EXPORT Camera : public Component {
public:
    Camera();
    ~Camera() override = default;
    
    // Perspective
    void SetPerspective(float fov, float aspectRatio, float nearPlane, float farPlane);
    void SetOrthographic(float width, float height, float nearPlane, float farPlane);
    
    // Properties
    float GetFOV() const { return mFOV; }
    void SetFOV(float fov) { mFOV = fov; }
    
    float GetAspectRatio() const { return mAspectRatio; }
    void SetAspectRatio(float ratio) { mAspectRatio = ratio; }
    
    float GetNearPlane() const { return mNearPlane; }
    float GetFarPlane() const { return mFarPlane; }
    
    // Matrices
    Mat4 GetViewMatrix() const;
    Mat4 GetProjectionMatrix() const;
    
    std::string GetComponentName() const override { return "Camera"; }
    
private:
    bool mPerspective;
    float mFOV;
    float mAspectRatio;
    float mNearPlane;
    float mFarPlane;
    float mOrthographicWidth;
};

} // namespace NotUneal
