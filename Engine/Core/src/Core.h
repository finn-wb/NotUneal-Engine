#pragma once

// NotUneal Engine Core
// Foundation types and utilities

#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>

namespace NotUneal {

// Export macros
#ifdef _WIN32
    #define NOTUNEAL_EXPORT __declspec(dllexport)
    #define NOTUNEAL_IMPORT __declspec(dllimport)
#else
    #define NOTUNEAL_EXPORT __attribute__((visibility("default")))
    #define NOTUNEAL_IMPORT
#endif

} // namespace NotUneal
