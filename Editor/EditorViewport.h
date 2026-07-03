#pragma once

#include "Scene/Scene.h"
#include "Rendering/Camera.h"
#include <memory>
#include <string>

namespace NotUneal {

/**
 * Editor viewport for viewing and editing scenes.
 */
class NOTUNEAL_EXPORT EditorViewport {
public:
    EditorViewport();
    ~EditorViewport();
    
    bool Initialize(uint32_t width, uint32_t height);
    void Render();
    
    void SetScene(const std::shared_ptr<Scene>& scene) { mScene = scene; }
    std::shared_ptr<Scene> GetScene() const { return mScene; }
    
    // Camera control
    std::shared_ptr<Camera> GetCamera() const { return mCamera; }
    
    // Selection
    void SelectObject(const std::shared_ptr<GameObject>& object);
    std::shared_ptr<GameObject> GetSelectedObject() const { return mSelectedObject; }
    void ClearSelection();
    
    // Gizmos
    void SetGizmoMode(const std::string& mode) { mGizmoMode = mode; } // "translate", "rotate", "scale"
    std::string GetGizmoMode() const { return mGizmoMode; }
    
    // Viewport size
    uint32_t GetWidth() const { return mWidth; }
    uint32_t GetHeight() const { return mHeight; }
    
private:
    std::shared_ptr<Scene> mScene;
    std::shared_ptr<Camera> mCamera;
    std::shared_ptr<GameObject> mSelectedObject;
    std::string mGizmoMode;
    
    uint32_t mWidth, mHeight;
};

} // namespace NotUneal
