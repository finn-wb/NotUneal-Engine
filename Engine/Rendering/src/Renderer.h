#pragma once

#include "Core/Types.h"
#include "Shader.h"
#include "Material.h"
#include "Mesh.h"
#include <vector>
#include <memory>
#include <queue>

namespace NotUneal {

struct RenderCommand {
    std::shared_ptr<Mesh> mesh;
    std::shared_ptr<Material> material;
    Mat4 transform;
    uint32_t sortKey;
};

/**
 * Main rendering system.
 * Handles rendering pipeline, batching, and draw calls.
 */
class NOTUNEAL_EXPORT Renderer {
public:
    static Renderer& Get();
    
    // Initialization
    bool Initialize(uint32_t width, uint32_t height);
    void Shutdown();
    
    // Rendering
    void BeginFrame();
    void EndFrame();
    void Clear(const Color& color = Color(0.1f, 0.1f, 0.1f, 1.0f));
    
    // Submit render commands
    void Submit(const RenderCommand& cmd);
    void Flush();
    
    // Viewport
    void SetViewport(uint32_t width, uint32_t height);
    uint32_t GetWidth() const { return mWidth; }
    uint32_t GetHeight() const { return mHeight; }
    
    // Camera
    void SetCamera(const Mat4& view, const Mat4& projection);
    Mat4 GetViewMatrix() const { return mViewMatrix; }
    Mat4 GetProjectionMatrix() const { return mProjectionMatrix; }
    
    // Lighting
    void SetAmbientLight(const Color& color);
    Color GetAmbientLight() const { return mAmbientLight; }
    
private:
    Renderer() = default;
    
    uint32_t mWidth, mHeight;
    
    Mat4 mViewMatrix;
    Mat4 mProjectionMatrix;
    Color mAmbientLight;
    
    std::vector<RenderCommand> mCommandBuffer;
};

} // namespace NotUneal
