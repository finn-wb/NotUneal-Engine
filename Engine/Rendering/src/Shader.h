#pragma once

#include "Core/Core.h"
#include <string>
#include <memory>
#include <unordered_map>

namespace NotUneal {

/**
 * Represents a single shader (vertex, fragment, geometry, etc.).
 */
class NOTUNEAL_EXPORT Shader {
public:
    enum class Type {
        Vertex,
        Fragment,
        Geometry,
        Compute
    };
    
    Shader(Type type, const std::string& source);
    ~Shader();
    
    Type GetType() const { return mType; }
    uint32_t GetHandle() const { return mHandle; }
    
    bool Compile();
    std::string GetError() const { return mError; }
    
private:
    Type mType;
    std::string mSource;
    uint32_t mHandle;
    std::string mError;
};

} // namespace NotUneal
