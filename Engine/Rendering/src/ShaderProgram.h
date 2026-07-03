#pragma once

#include "Shader.h"
#include "Core/Types.h"
#include <memory>
#include <string>

namespace NotUneal {

/**
 * Shader program combining multiple shaders (vertex, fragment, etc.).
 */
class NOTUNEAL_EXPORT ShaderProgram {
public:
    ShaderProgram();
    ~ShaderProgram();
    
    void AttachShader(const std::shared_ptr<Shader>& shader);
    bool Link();
    void Bind() const;
    void Unbind() const;
    
    uint32_t GetHandle() const { return mHandle; }
    std::string GetError() const { return mError; }
    
    // Uniforms
    void SetUniform1i(const std::string& name, int value) const;
    void SetUniform1f(const std::string& name, float value) const;
    void SetUniform2f(const std::string& name, float x, float y) const;
    void SetUniform3f(const std::string& name, float x, float y, float z) const;
    void SetUniform3f(const std::string& name, const Vec3& vec) const;
    void SetUniform4f(const std::string& name, float x, float y, float z, float w) const;
    void SetUniformMat4f(const std::string& name, const Mat4& mat) const;
    
private:
    uint32_t mHandle;
    std::string mError;
    int GetUniformLocation(const std::string& name) const;
};

} // namespace NotUneal
