#pragma once

#include "Core.h"
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace NotUneal {

// Vector types
using Vec2 = glm::vec2;
using Vec3 = glm::vec3;
using Vec4 = glm::vec4;
using Vec2i = glm::ivec2;
using Vec3i = glm::ivec3;
using Vec4i = glm::ivec4;

// Matrix types
using Mat2 = glm::mat2;
using Mat3 = glm::mat3;
using Mat4 = glm::mat4;

// Quaternion
using Quat = glm::quat;

// Color
struct Color {
    float r, g, b, a;
    Color(float r = 1, float g = 1, float b = 1, float a = 1) : r(r), g(g), b(b), a(a) {}
};

// Transform
struct Transform {
    Vec3 position;
    Quat rotation;
    Vec3 scale;
    
    Transform() : position(0), rotation(1, 0, 0, 0), scale(1) {}
    
    Mat4 GetMatrix() const;
    static Transform Inverse(const Transform& t);
};

// Unique ID for entities
using UUID = uint64_t;
UUID GenerateUUID();

} // namespace NotUneal
