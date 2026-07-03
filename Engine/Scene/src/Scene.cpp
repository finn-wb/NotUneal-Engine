#include "Scene.h"
#include <algorithm>

namespace NotUneal {

Scene::Scene(const std::string& name) : mName(name) {}

std::shared_ptr<GameObject> Scene::CreateGameObject(const std::string& name) {
    auto obj = std::make_shared<GameObject>(name);
    mRootObjects.push_back(obj);
    mAllObjects.push_back(obj);
    return obj;
}

void Scene::DestroyGameObject(std::shared_ptr<GameObject> object) {
    auto it = std::find(mRootObjects.begin(), mRootObjects.end(), object);
    if (it != mRootObjects.end()) {
        mRootObjects.erase(it);
    }
    
    auto it2 = std::find(mAllObjects.begin(), mAllObjects.end(), object);
    if (it2 != mAllObjects.end()) {
        mAllObjects.erase(it2);
    }
}

void Scene::Clear() {
    mRootObjects.clear();
    mAllObjects.clear();
}

std::shared_ptr<GameObject> Scene::FindByName(const std::string& name) const {
    for (const auto& obj : mAllObjects) {
        if (obj->GetName() == name) {
            return obj;
        }
    }
    return nullptr;
}

std::shared_ptr<GameObject> Scene::FindByUUID(UUID uuid) const {
    for (const auto& obj : mAllObjects) {
        if (obj->GetUUID() == uuid) {
            return obj;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<GameObject>> Scene::FindByTag(const std::string& tag) const {
    std::vector<std::shared_ptr<GameObject>> result;
    for (const auto& obj : mAllObjects) {
        if (obj->HasTag(tag)) {
            result.push_back(obj);
        }
    }
    return result;
}

void Scene::Update(float deltaTime) {
    for (auto& obj : mRootObjects) {
        obj->Update(deltaTime);
    }
}

void Scene::Render() {
    for (auto& obj : mRootObjects) {
        obj->Render();
    }
}

std::string Scene::Serialize() const {
    // TODO: Implement serialization
    return "{}";
}

void Scene::Deserialize(const std::string& data) {
    // TODO: Implement deserialization
}

} // namespace NotUneal
