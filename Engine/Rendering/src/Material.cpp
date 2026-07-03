#include "Material.h"

namespace NotUneal {

Material::Material(const std::shared_ptr<ShaderProgram>& shader)
    : mShader(shader) {}

void Material::Bind() const {
    if (mShader) {
        mShader->Bind();
        
        // Bind textures
        uint32_t slot = 0;
        for (const auto& [name, texture] : mTextures) {
            if (texture) {
                texture->Bind(slot);
                mShader->SetUniform1i(name, slot);
                slot++;
            }
        }
        
        // Set uniforms
        for (const auto& [name, color] : mColors) {
            mShader->SetUniform4f(name, color.r, color.g, color.b, color.a);
        }
        for (const auto& [name, value] : mFloats) {
            mShader->SetUniform1f(name, value);
        }
        for (const auto& [name, value] : mVec3s) {
            mShader->SetUniform3f(name, value);
        }
        for (const auto& [name, value] : mMatrices) {
            mShader->SetUniformMat4f(name, value);
        }
    }
}

void Material::Unbind() const {
    if (mShader) {
        mShader->Unbind();
    }
}

void Material::SetTexture(const std::string& name, const std::shared_ptr<Texture>& texture) {
    mTextures[name] = texture;
}

std::shared_ptr<Texture> Material::GetTexture(const std::string& name) const {
    auto it = mTextures.find(name);
    if (it != mTextures.end()) {
        return it->second;
    }
    return nullptr;
}

void Material::SetColor(const std::string& name, const Color& color) {
    mColors[name] = color;
}

void Material::SetFloat(const std::string& name, float value) {
    mFloats[name] = value;
}

void Material::SetVec3(const std::string& name, const Vec3& value) {
    mVec3s[name] = value;
}

void Material::SetMatrix(const std::string& name, const Mat4& value) {
    mMatrices[name] = value;
}

std::shared_ptr<Material> Material::Clone() const {
    auto clone = std::make_shared<Material>(mShader);
    clone->mTextures = mTextures;
    clone->mColors = mColors;
    clone->mFloats = mFloats;
    clone->mVec3s = mVec3s;
    clone->mMatrices = mMatrices;
    return clone;
}

} // namespace NotUneal
