#include "TransformComponent.h"
#include "GameObject.h"
#include <glm/gtc/matrix_transform.hpp>

namespace NotUneal {

TransformComponent::TransformComponent() = default;

Vec3 TransformComponent::GetWorldPosition() const {
    auto parent = GetOwner();
    if (parent) {
        auto parentTransform = parent->GetParent();
        if (parentTransform) {
            // TODO: Combine with parent transform
        }
    }
    return mLocalTransform.position;
}

Quat TransformComponent::GetWorldRotation() const {
    // TODO: Combine with parent rotation
    return mLocalTransform.rotation;
}

Mat4 TransformComponent::GetWorldMatrix() const {
    // TODO: Combine with parent matrix
    return mLocalTransform.GetMatrix();
}

Vec3 TransformComponent::GetForward() const {
    return glm::rotate(mLocalTransform.rotation, Vec3(0, 0, -1));
}

Vec3 TransformComponent::GetRight() const {
    return glm::rotate(mLocalTransform.rotation, Vec3(1, 0, 0));
}

Vec3 TransformComponent::GetUp() const {
    return glm::rotate(mLocalTransform.rotation, Vec3(0, 1, 0));
}

} // namespace NotUneal
