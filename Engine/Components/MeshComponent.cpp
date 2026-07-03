#include "MeshComponent.h"
#include "Rendering/Renderer.h"
#include "Scene/GameObject.h"

namespace NotUneal {

MeshComponent::MeshComponent() {}

void MeshComponent::Render() {
    if (!mMesh || !mMaterial) return;
    
    auto owner = GetOwner();
    if (!owner) return;
    
    auto transform = owner->GetTransform();
    if (!transform) return;
    
    // Submit render command
    RenderCommand cmd;
    cmd.mesh = mMesh;
    cmd.material = mMaterial;
    cmd.transform = transform->GetWorldMatrix();
    cmd.sortKey = 0; // TODO: Proper sorting
    
    Renderer::Get().Submit(cmd);
}

} // namespace NotUneal
