#pragma once

#include <cstdint>
#include <cstring>
#include <string>

namespace NotUneal {

/**
 * Binary serialization/deserialization utilities.
 */
class Archive {
public:
    Archive() : mBuffer(nullptr), mSize(0), mCapacity(0), mPosition(0) {}
    
    virtual ~Archive() {
        if (mBuffer) delete[] mBuffer;
    }
    
    // Writing
    template<typename T>
    void Write(const T& value) {
        const uint8_t* data = reinterpret_cast<const uint8_t*>(&value);
        WriteBytes(data, sizeof(T));
    }
    
    void WriteString(const std::string& str) {
        uint32_t len = str.length();
        Write(len);
        WriteBytes((const uint8_t*)str.data(), len);
    }
    
    // Reading
    template<typename T>
    T Read() {
        T value;
        uint8_t* data = reinterpret_cast<uint8_t*>(&value);
        ReadBytes(data, sizeof(T));
        return value;
    }
    
    std::string ReadString() {
        uint32_t len = Read<uint32_t>();
        std::string str(len, 0);
        ReadBytes((uint8_t*)str.data(), len);
        return str;
    }
    
    const uint8_t* GetData() const { return mBuffer; }
    uint32_t GetSize() const { return mPosition; }
    void Reset() { mPosition = 0; }
    
private:
    void WriteBytes(const uint8_t* data, uint32_t size) {
        if (mPosition + size > mCapacity) {
            uint32_t newCapacity = std::max(mCapacity * 2, mPosition + size);
            uint8_t* newBuffer = new uint8_t[newCapacity];
            if (mBuffer) {
                std::memcpy(newBuffer, mBuffer, mPosition);
                delete[] mBuffer;
            }
            mBuffer = newBuffer;
            mCapacity = newCapacity;
        }
        std::memcpy(mBuffer + mPosition, data, size);
        mPosition += size;
    }
    
    void ReadBytes(uint8_t* data, uint32_t size) {
        if (mPosition + size > mSize) return; // Error
        std::memcpy(data, mBuffer + mPosition, size);
        mPosition += size;
    }
    
    uint8_t* mBuffer;
    uint32_t mSize;
    uint32_t mCapacity;
    uint32_t mPosition;
};

} // namespace NotUneal
