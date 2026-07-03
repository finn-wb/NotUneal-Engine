#include "GameObject.h"
#include "TransformComponent.h"
#include <algorithm>

namespace NotUneal {

GameObject::GameObject(const std::string& name)
    : mName(name), mActive(true), mUUID(GenerateUUID()) {
    // Every GameObject gets a TransformComponent by default
    mTransform = std::make_shared<TransformComponent>();
    mTransform->SetOwner(shared_from_this());
    mTransform->OnCreate();
    mComponents.push_back(mTransform);
}

GameObject::~GameObject() {
    for (auto& component : mComponents) {
        component->OnDestroy();
    }
}

void GameObject::SetParent(std::shared_ptr<GameObject> parent) {
    auto currentParent = mParent.lock();
    if (currentParent) {
        auto it = std::find(currentParent->mChildren.begin(), currentParent->mChildren.end(), shared_from_this());
        if (it != currentParent->mChildren.end()) {
            currentParent->mChildren.erase(it);
        }
    }
    
    mParent = parent;
    if (parent) {
        parent->mChildren.push_back(shared_from_this());
    }
}

void GameObject::AddChild(std::shared_ptr<GameObject> child) {
    child->SetParent(shared_from_this());
}

void GameObject::RemoveChild(std::shared_ptr<GameObject> child) {
    auto it = std::find(mChildren.begin(), mChildren.end(), child);
    if (it != mChildren.end()) {
        (*it)->SetParent(nullptr);
    }
}

void GameObject::AddTag(const std::string& tag) {
    if (std::find(mTags.begin(), mTags.end(), tag) == mTags.end()) {
        mTags.push_back(tag);
    }
}

void GameObject::RemoveTag(const std::string& tag) {
    auto it = std::find(mTags.begin(), mTags.end(), tag);
    if (it != mTags.end()) {
        mTags.erase(it);
    }
}

bool GameObject::HasTag(const std::string& tag) const {
    return std::find(mTags.begin(), mTags.end(), tag) != mTags.end();
}

void GameObject::Update(float deltaTime) {
    if (!mActive) return;
    
    for (auto& component : mComponents) {
        component->Update(deltaTime);
    }
    
    for (auto& child : mChildren) {
        child->Update(deltaTime);
    }
}

void GameObject::Render() {
    if (!mActive) return;
    
    for (auto& component : mComponents) {
        component->Render();
    }
    
    for (auto& child : mChildren) {
        child->Render();
    }
}

std::string GameObject::Serialize() const {
    // TODO: Implement serialization
    return "{}";
}

void GameObject::Deserialize(const std::string& data) {
    // TODO: Implement deserialization
}

} // namespace NotUneal
