#pragma once

#include "ShaderProgram.h"
#include "Texture.h"
#include "Core/Types.h"
#include <memory>
#include <string>
#include <unordered_map>

namespace NotUneal {

/**
 * Material combines a shader program with textures and properties.
 */
class NOTUNEAL_EXPORT Material {
public:
    Material(const std::shared_ptr<ShaderProgram>& shader);
    ~Material() = default;
    
    void Bind() const;
    void Unbind() const;
    
    std::shared_ptr<ShaderProgram> GetShader() const { return mShader; }
    void SetShader(const std::shared_ptr<ShaderProgram>& shader) { mShader = shader; }
    
    // Textures
    void SetTexture(const std::string& name, const std::shared_ptr<Texture>& texture);
    std::shared_ptr<Texture> GetTexture(const std::string& name) const;
    
    // Properties
    void SetColor(const std::string& name, const Color& color);
    void SetFloat(const std::string& name, float value);
    void SetVec3(const std::string& name, const Vec3& value);
    void SetMatrix(const std::string& name, const Mat4& value);
    
    // Cloning
    std::shared_ptr<Material> Clone() const;
    
private:
    std::shared_ptr<ShaderProgram> mShader;
    std::unordered_map<std::string, std::shared_ptr<Texture>> mTextures;
    std::unordered_map<std::string, Color> mColors;
    std::unordered_map<std::string, float> mFloats;
    std::unordered_map<std::string, Vec3> mVec3s;
    std::unordered_map<std::string, Mat4> mMatrices;
};

} // namespace NotUneal
