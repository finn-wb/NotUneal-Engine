# Advanced Rendering Guide

## Rendering Pipeline

The NotUneal rendering system uses a deferred rendering approach:

1. **Geometry Pass**: Render all meshes to G-buffer
2. **Lighting Pass**: Compute lighting from G-buffer data
3. **Composition Pass**: Combine all render targets
4. **Post-Processing**: Apply effects

## Material System

Materials combine shaders with properties:

```cpp
auto material = std::make_shared<Material>(shaderProgram);
material->SetColor("baseColor", Color(1.0f, 0.5f, 0.2f));
material->SetFloat("metallic", 0.8f);
material->SetTexture("normalMap", normalMapTexture);
```

## Lighting

Three light types are supported:

### Directional Light
```cpp
auto light = scene->CreateGameObject("Sun");
auto lightComp = light->AddComponent<LightComponent>();
lightComp->SetLightType(LightType::Directional);
lightComp->SetIntensity(1.0f);
```

### Point Light
```cpp
auto light = scene->CreateGameObject("Lamp");
auto lightComp = light->AddComponent<LightComponent>();
lightComp->SetLightType(LightType::Point);
lightComp->SetRange(10.0f);
```

### Spot Light
```cpp
auto light = scene->CreateGameObject("Spotlight");
auto lightComp = light->AddComponent<LightComponent>();
lightComp->SetLightType(LightType::Spot);
lightComp->SetAngle(45.0f);
lightComp->SetRange(20.0f);
```

## Custom Shaders

Create custom shaders using the visual editor or directly:

```cpp
std::string vertexShader = R"(
#version 460 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

out vec3 Normal;

uniform mat4 uModel;
uniform mat4 uViewProj;

void main() {
    Normal = mat3(uModel) * normal;
    gl_Position = uViewProj * uModel * vec4(position, 1.0);
}
)";

std::string fragmentShader = R"(
#version 460 core
in vec3 Normal;

out vec4 FragColor;

void main() {
    FragColor = vec4(normalize(Normal) * 0.5 + 0.5, 1.0);
}
)";

auto shader = std::make_shared<Shader>(Shader::Type::Vertex, vertexShader);
shader->Compile();
```

## Rendering Custom Objects

```cpp
// Create and setup mesh
std::vector<Vertex> vertices = { /* ... */ };
std::vector<uint32_t> indices = { /* ... */ };
auto mesh = std::make_shared<Mesh>();
mesh->SetVertices(vertices);
mesh->SetIndices(indices);

// Create material
auto material = std::make_shared<Material>(shaderProgram);

// Render
RenderCommand cmd;
cmd.mesh = mesh;
cmd.material = material;
cmd.transform = Mat4(1.0f);
Renderer::Get().Submit(cmd);
```

## Performance Tips

1. **Batching**: Group similar materials for fewer state changes
2. **Culling**: Use frustum and occlusion culling
3. **LOD**: Use lower polygon counts at distance
4. **Texture Atlasing**: Combine textures to reduce bindings
5. **Shader Optimization**: Keep shader code simple

## Debugging Rendering

```cpp
// Enable debug info
Renderer::Get().SetDebugMode(true);

// Visualize buffers
Renderer::Get().VisuializeBuffer("Normals");
Renderer::Get().VisuializeBuffer("Depth");
```
