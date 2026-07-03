#pragma once

#include "Core/Types.h"
#include <vector>
#include <memory>
#include <cstdint>

namespace NotUneal {

/**
 * Vertex data structure.
 */
struct Vertex {
    Vec3 position;
    Vec3 normal;
    Vec3 tangent;
    Vec2 texCoord;
};

/**
 * Mesh data and GPU resources.
 */
class NOTUNEAL_EXPORT Mesh {
public:
    Mesh();
    ~Mesh();
    
    void SetVertices(const std::vector<Vertex>& vertices);
    void SetIndices(const std::vector<uint32_t>& indices);
    
    const std::vector<Vertex>& GetVertices() const { return mVertices; }
    const std::vector<uint32_t>& GetIndices() const { return mIndices; }
    
    void Draw() const;
    
    uint32_t GetVAO() const { return mVAO; }
    uint32_t GetVBO() const { return mVBO; }
    uint32_t GetEBO() const { return mEBO; }
    uint32_t GetIndexCount() const { return mIndexCount; }
    
private:
    void UpdateGPU();
    
    std::vector<Vertex> mVertices;
    std::vector<uint32_t> mIndices;
    
    uint32_t mVAO, mVBO, mEBO;
    uint32_t mIndexCount;
};

} // namespace NotUneal
