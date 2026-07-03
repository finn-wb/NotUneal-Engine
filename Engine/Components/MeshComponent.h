#pragma once

#include "Scene/Component.h"
#include "Rendering/Mesh.h"
#include "Rendering/Material.h"
#include <memory>

namespace NotUneal {

/**
 * Mesh renderer component.
 */
class NOTUNEAL_EXPORT MeshComponent : public Component {
public:
    MeshComponent();
    ~MeshComponent() override = default;
    
    void SetMesh(const std::shared_ptr<Mesh>& mesh) { mMesh = mesh; }
    std::shared_ptr<Mesh> GetMesh() const { return mMesh; }
    
    void SetMaterial(const std::shared_ptr<Material>& material) { mMaterial = material; }
    std::shared_ptr<Material> GetMaterial() const { return mMaterial; }
    
    void Render() override;
    
    std::string GetComponentName() const override { return "MeshComponent"; }
    
private:
    std::shared_ptr<Mesh> mMesh;
    std::shared_ptr<Material> mMaterial;
};

} // namespace NotUneal
