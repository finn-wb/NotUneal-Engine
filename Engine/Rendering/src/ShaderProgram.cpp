#include "ShaderProgram.h"
#include <GL/gl.h>
#include <glm/gtc/type_ptr.hpp>

namespace NotUneal {

ShaderProgram::ShaderProgram() : mHandle(glCreateProgram()) {}

ShaderProgram::~ShaderProgram() {
    if (mHandle) {
        glDeleteProgram(mHandle);
    }
}

void ShaderProgram::AttachShader(const std::shared_ptr<Shader>& shader) {
    if (shader && shader->GetHandle()) {
        glAttachShader(mHandle, shader->GetHandle());
    }
}

bool ShaderProgram::Link() {
    glLinkProgram(mHandle);
    
    int success;
    glGetProgramiv(mHandle, GL_LINK_STATUS, &success);
    
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(mHandle, 512, nullptr, infoLog);
        mError = infoLog;
        return false;
    }
    
    return true;
}

void ShaderProgram::Bind() const {
    glUseProgram(mHandle);
}

void ShaderProgram::Unbind() const {
    glUseProgram(0);
}

int ShaderProgram::GetUniformLocation(const std::string& name) const {
    return glGetUniformLocation(mHandle, name.c_str());
}

void ShaderProgram::SetUniform1i(const std::string& name, int value) const {
    glUniform1i(GetUniformLocation(name), value);
}

void ShaderProgram::SetUniform1f(const std::string& name, float value) const {
    glUniform1f(GetUniformLocation(name), value);
}

void ShaderProgram::SetUniform2f(const std::string& name, float x, float y) const {
    glUniform2f(GetUniformLocation(name), x, y);
}

void ShaderProgram::SetUniform3f(const std::string& name, float x, float y, float z) const {
    glUniform3f(GetUniformLocation(name), x, y, z);
}

void ShaderProgram::SetUniform3f(const std::string& name, const Vec3& vec) const {
    glUniform3fv(GetUniformLocation(name), 1, glm::value_ptr(vec));
}

void ShaderProgram::SetUniform4f(const std::string& name, float x, float y, float z, float w) const {
    glUniform4f(GetUniformLocation(name), x, y, z, w);
}

void ShaderProgram::SetUniformMat4f(const std::string& name, const Mat4& mat) const {
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(mat));
}

} // namespace NotUneal
