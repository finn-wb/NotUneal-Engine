#include "EditorViewport.h"
#include "Rendering/Renderer.h"
#include "Scene/GameObject.h"

namespace NotUneal {

EditorViewport::EditorViewport()
    : mWidth(1920), mHeight(1080), mGizmoMode("translate") {}

EditorViewport::~EditorViewport() {}

bool EditorViewport::Initialize(uint32_t width, uint32_t height) {
    mWidth = width;
    mHeight = height;
    
    // Create editor camera
    auto cameraObj = std::make_shared<GameObject>("EditorCamera");
    mCamera = cameraObj->AddComponent<Camera>();
    mCamera->SetPerspective(45.0f, (float)width / (float)height, 0.1f, 1000.0f);
    
    return true;
}

void EditorViewport::Render() {
    if (!mScene || !mCamera) return;
    
    Renderer::Get().SetViewport(mWidth, mHeight);
    Renderer::Get().SetCamera(mCamera->GetViewMatrix(), mCamera->GetProjectionMatrix());
    Renderer::Get().Clear();
    
    mScene->Render();
    
    // TODO: Render gizmos and selection highlights
}

void EditorViewport::SelectObject(const std::shared_ptr<GameObject>& object) {
    mSelectedObject = object;
    // TODO: Highlight selected object
}

void EditorViewport::ClearSelection() {
    mSelectedObject = nullptr;
}

} // namespace NotUneal
