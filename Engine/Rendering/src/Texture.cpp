#include "Texture.h"
#include <GL/gl.h>

namespace NotUneal {

Texture::Texture(uint32_t width, uint32_t height, Format format)
    : mWidth(width), mHeight(height), mFormat(format), mHandle(0) {
    
    glGenTextures(1, &mHandle);
    glBindTexture(GL_TEXTURE_2D, mHandle);
    
    GLenum internalFormat, pixelFormat;
    switch (format) {
        case Format::RGB:
            internalFormat = GL_RGB;
            pixelFormat = GL_RGB;
            break;
        case Format::RGBA:
            internalFormat = GL_RGBA;
            pixelFormat = GL_RGBA;
            break;
        case Format::Depth:
            internalFormat = GL_DEPTH_COMPONENT;
            pixelFormat = GL_DEPTH_COMPONENT;
            break;
        case Format::HDR:
            internalFormat = GL_RGB16F;
            pixelFormat = GL_RGB;
            break;
        default:
            internalFormat = GL_RGBA;
            pixelFormat = GL_RGBA;
    }
    
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, pixelFormat, GL_UNSIGNED_BYTE, nullptr);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {
    if (mHandle) {
        glDeleteTextures(1, &mHandle);
    }
}

void Texture::SetData(const void* data) {
    glBindTexture(GL_TEXTURE_2D, mHandle);
    
    GLenum pixelFormat = (mFormat == Format::RGB) ? GL_RGB : GL_RGBA;
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, mWidth, mHeight, pixelFormat, GL_UNSIGNED_BYTE, data);
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::LoadFromFile(const std::string& path) {
    // TODO: Implement image loading (use stb_image or similar)
}

void Texture::Bind(uint32_t slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, mHandle);
}

void Texture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

} // namespace NotUneal
