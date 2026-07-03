#include "Camera.h"
#include "Scene/GameObject.h"
#include <glm/gtc/matrix_transform.hpp>

namespace NotUneal {

Camera::Camera()
    : mPerspective(true), mFOV(45.0f), mAspectRatio(16.0f / 9.0f),
      mNearPlane(0.1f), mFarPlane(1000.0f), mOrthographicWidth(10.0f) {}

void Camera::SetPerspective(float fov, float aspectRatio, float nearPlane, float farPlane) {
    mPerspective = true;
    mFOV = fov;
    mAspectRatio = aspectRatio;
    mNearPlane = nearPlane;
    mFarPlane = farPlane;
}

void Camera::SetOrthographic(float width, float height, float nearPlane, float farPlane) {
    mPerspective = false;
    mOrthographicWidth = width;
    mAspectRatio = width / height;
    mNearPlane = nearPlane;
    mFarPlane = farPlane;
}

Mat4 Camera::GetViewMatrix() const {
    auto owner = GetOwner();
    if (!owner) return Mat4(1.0f);
    
    auto transform = owner->GetTransform();
    if (!transform) return Mat4(1.0f);
    
    Vec3 position = transform->GetWorldPosition();
    Vec3 forward = transform->GetForward();
    Vec3 up = transform->GetUp();
    
    return glm::lookAt(position, position + forward, up);
}

Mat4 Camera::GetProjectionMatrix() const {
    if (mPerspective) {
        return glm::perspective(glm::radians(mFOV), mAspectRatio, mNearPlane, mFarPlane);
    } else {
        float halfWidth = mOrthographicWidth * 0.5f;
        float halfHeight = halfWidth / mAspectRatio;
        return glm::ortho(-halfWidth, halfWidth, -halfHeight, halfHeight, mNearPlane, mFarPlane);
    }
}

} // namespace NotUneal
