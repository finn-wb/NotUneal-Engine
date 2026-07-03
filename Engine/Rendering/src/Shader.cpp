#include "Shader.h"
#include <GL/gl.h>
#include <sstream>

namespace NotUneal {

Shader::Shader(Type type, const std::string& source)
    : mType(type), mSource(source), mHandle(0) {}

Shader::~Shader() {
    if (mHandle) {
        glDeleteShader(mHandle);
    }
}

bool Shader::Compile() {
    GLenum shaderType;
    switch (mType) {
        case Type::Vertex:   shaderType = GL_VERTEX_SHADER; break;
        case Type::Fragment: shaderType = GL_FRAGMENT_SHADER; break;
        case Type::Geometry: shaderType = GL_GEOMETRY_SHADER; break;
        case Type::Compute:  shaderType = GL_COMPUTE_SHADER; break;
        default: return false;
    }
    
    mHandle = glCreateShader(shaderType);
    const char* src = mSource.c_str();
    glShaderSource(mHandle, 1, &src, nullptr);
    glCompileShader(mHandle);
    
    int success;
    glGetShaderiv(mHandle, GL_COMPILE_STATUS, &success);
    
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(mHandle, 512, nullptr, infoLog);
        mError = infoLog;
        return false;
    }
    
    return true;
}

} // namespace NotUneal
