#include "Mesh.h"
#include <GL/gl.h>

namespace NotUneal {

Mesh::Mesh() : mVAO(0), mVBO(0), mEBO(0), mIndexCount(0) {
    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mVBO);
    glGenBuffers(1, &mEBO);
}

Mesh::~Mesh() {
    if (mVAO) glDeleteVertexArrays(1, &mVAO);
    if (mVBO) glDeleteBuffers(1, &mVBO);
    if (mEBO) glDeleteBuffers(1, &mEBO);
}

void Mesh::SetVertices(const std::vector<Vertex>& vertices) {
    mVertices = vertices;
    UpdateGPU();
}

void Mesh::SetIndices(const std::vector<uint32_t>& indices) {
    mIndices = indices;
    mIndexCount = indices.size();
    UpdateGPU();
}

void Mesh::UpdateGPU() {
    glBindVertexArray(mVAO);
    
    // Upload vertices
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), mVertices.data(), GL_STATIC_DRAW);
    
    // Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);
    
    // Normal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(1);
    
    // Tangent
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
    glEnableVertexAttribArray(2);
    
    // TexCoord
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoord));
    glEnableVertexAttribArray(3);
    
    // Upload indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(uint32_t), mIndices.data(), GL_STATIC_DRAW);
    
    glBindVertexArray(0);
}

void Mesh::Draw() const {
    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

} // namespace NotUneal
