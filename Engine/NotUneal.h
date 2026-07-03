#pragma once

/**
 * NotUneal Engine - Main Include Header
 * 
 * Include this header to get access to the entire NotUneal Engine API.
 */

// Core
#include "Engine/Core/Core.h"
#include "Engine/Core/Types.h"
#include "Engine/Core/Memory.h"

// Scene System
#include "Engine/Scene/GameObject.h"
#include "Engine/Scene/Component.h"
#include "Engine/Scene/TransformComponent.h"
#include "Engine/Scene/Scene.h"
#include "Engine/Scene/SceneManager.h"

// Rendering
#include "Engine/Rendering/Renderer.h"
#include "Engine/Rendering/Camera.h"
#include "Engine/Rendering/Shader.h"
#include "Engine/Rendering/ShaderProgram.h"
#include "Engine/Rendering/Material.h"
#include "Engine/Rendering/Mesh.h"
#include "Engine/Rendering/Texture.h"
#include "Engine/Rendering/RenderCommand.h"

// Components
#include "Engine/Components/MeshComponent.h"
#include "Engine/Components/LightComponent.h"

// Shader Editor
#include "Engine/ShaderEditor/ShaderNode.h"
#include "Engine/ShaderEditor/ShaderNodes.h"
#include "Engine/ShaderEditor/ShaderGraph.h"

// Assets
#include "Engine/Assets/AssetPackage.h"
#include "Engine/Assets/AssetManager.h"

// Serialization
#include "Engine/Serialization/Archive.h"
#include "Engine/Serialization/Serializable.h"

// Framework
#include "Engine/Framework/GameFramework.h"

// Input
#include "Engine/Input/InputSystem.h"

// Editor (optional)
#ifdef NOTUNEAL_WITH_EDITOR
#include "Editor/Editor.h"
#include "Editor/EditorViewport.h"
#include "Editor/ProjectSettings.h"
#endif

// Tools (optional)
#ifdef NOTUNEAL_WITH_TOOLS
#include "Tools/BuildTools.h"
#endif

// Convenience namespace alias
namespace NU = NotUneal;

#endif // NOTUNEAL_ENGINE_H
