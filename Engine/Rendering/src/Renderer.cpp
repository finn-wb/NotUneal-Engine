#include "Renderer.h"
#include <GL/gl.h>
#include <algorithm>

namespace NotUneal {

Renderer& Renderer::Get() {
    static Renderer instance;
    return instance;
}

bool Renderer::Initialize(uint32_t width, uint32_t height) {
    mWidth = width;
    mHeight = height;
    mAmbientLight = Color(0.2f, 0.2f, 0.2f, 1.0f);
    
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    return true;
}

void Renderer::Shutdown() {
    mCommandBuffer.clear();
}

void Renderer::BeginFrame() {
    mCommandBuffer.clear();
}

void Renderer::EndFrame() {
    Flush();
}

void Renderer::Clear(const Color& color) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Submit(const RenderCommand& cmd) {
    mCommandBuffer.push_back(cmd);
}

void Renderer::Flush() {
    // Sort by material for batching
    std::sort(mCommandBuffer.begin(), mCommandBuffer.end(),
        [](const RenderCommand& a, const RenderCommand& b) {
            return a.sortKey < b.sortKey;
        });
    
    // Execute render commands
    for (const auto& cmd : mCommandBuffer) {
        // Bind material and set uniforms
        if (cmd.material && cmd.mesh) {
            cmd.material->Bind();
            // TODO: Set model matrix uniform
            // cmd.mesh->Draw();
        }
    }
}

void Renderer::SetViewport(uint32_t width, uint32_t height) {
    mWidth = width;
    mHeight = height;
    glViewport(0, 0, width, height);
}

void Renderer::SetCamera(const Mat4& view, const Mat4& projection) {
    mViewMatrix = view;
    mProjectionMatrix = projection;
}

void Renderer::SetAmbientLight(const Color& color) {
    mAmbientLight = color;
}

} // namespace NotUneal
