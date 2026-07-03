cmake_minimum_required(VERSION 3.16)
project(NotUnealEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Options
option(NOTUNEAL_BUILD_EDITOR "Build the editor application" ON)
option(NOTUNEAL_BUILD_TOOLS "Build asset tools" ON)
option(NOTUNEAL_BUILD_EXAMPLES "Build example projects" ON)
option(NOTUNEAL_BUILD_TESTS "Build unit tests" OFF)
option(NOTUNEAL_SHARED_LIBS "Build shared libraries" OFF)

# Find dependencies
find_package(OpenGL REQUIRED)
find_package(Qt6 COMPONENTS Core Gui Widgets QUIET)

# Set library type
if(NOTUNEAL_SHARED_LIBS)
    set(LIB_TYPE SHARED)
else()
    set(LIB_TYPE STATIC)
endif()

# Core engine subdirectories
add_subdirectory(Engine/Core)
add_subdirectory(Engine/Scene)
add_subdirectory(Engine/Rendering)
add_subdirectory(Engine/Components)
add_subdirectory(Engine/ShaderEditor)

# Create main library
add_library(NotUnealEngine ${LIB_TYPE}
    # Empty - uses subdirectory libraries
)

target_link_libraries(NotUnealEngine INTERFACE
    NotUnealCore
    NotUnealScene
    NotUnealRendering
    NotUnealComponents
    NotUnealShaderEditor
)

# Include directories
target_include_directories(NotUnealEngine INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Optional: Tools
if(NOTUNEAL_BUILD_TOOLS)
    add_subdirectory(Tools)
endif()

# Optional: Editor
if(NOTUNEAL_BUILD_EDITOR AND Qt6_FOUND)
    add_subdirectory(Editor)
endif()

# Optional: Examples
if(NOTUNEAL_BUILD_EXAMPLES)
    add_subdirectory(Examples)
endif()

# Optional: Tests
if(NOTUNEAL_BUILD_TESTS)
    enable_testing()
    add_subdirectory(Tests)
endif()

# Installation
install(TARGETS NotUnealEngine
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY Engine/
    DESTINATION include/NotUneal
    FILES_MATCHING PATTERN "*.h"
)

# Print summary
message(STATUS "")
message(STATUS "NotUneal Engine v${PROJECT_VERSION}")
message(STATUS "===============================")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Library Type: ${LIB_TYPE}")
message(STATUS "Build Editor: ${NOTUNEAL_BUILD_EDITOR}")
message(STATUS "Build Tools: ${NOTUNEAL_BUILD_TOOLS}")
message(STATUS "Build Examples: ${NOTUNEAL_BUILD_EXAMPLES}")
message(STATUS "Build Tests: ${NOTUNEAL_BUILD_TESTS}")
message(STATUS "")
