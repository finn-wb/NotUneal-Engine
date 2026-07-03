cmake_minimum_required(VERSION 3.16)
project(NotUnealRendering)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL
find_package(OpenGL REQUIRED)

add_library(NotUnealRendering STATIC
    src/Renderer.h
    src/Renderer.cpp
    src/Camera.h
    src/Camera.cpp
    src/Shader.h
    src/Shader.cpp
    src/ShaderProgram.h
    src/ShaderProgram.cpp
    src/Material.h
    src/Material.cpp
    src/Mesh.h
    src/Mesh.cpp
    src/Texture.h
    src/Texture.cpp
    src/RenderCommand.h
    src/RenderCommand.cpp
)

target_include_directories(NotUnealRendering PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(NotUnealRendering PUBLIC NotUnealCore NotUnealScene OpenGL::OpenGL)
