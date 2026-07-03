#pragma once

#include "Core/Core.h"
#include <string>
#include <cstdint>

namespace NotUneal {

/**
 * 2D Texture resource.
 */
class NOTUNEAL_EXPORT Texture {
public:
    enum class Format {
        RGB,
        RGBA,
        Depth,
        HDR
    };
    
    Texture(uint32_t width, uint32_t height, Format format);
    ~Texture();
    
    void SetData(const void* data);
    void LoadFromFile(const std::string& path);
    
    void Bind(uint32_t slot = 0) const;
    void Unbind() const;
    
    uint32_t GetWidth() const { return mWidth; }
    uint32_t GetHeight() const { return mHeight; }
    uint32_t GetHandle() const { return mHandle; }
    
private:
    uint32_t mWidth, mHeight;
    Format mFormat;
    uint32_t mHandle;
};

} // namespace NotUneal
