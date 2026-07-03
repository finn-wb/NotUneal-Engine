# Example: Simple 3D Scene

A basic example showing how to create a 3D scene with a mesh, lighting, and camera.

```cpp
#include <NotUneal/Engine.h>
#include <iostream>

using namespace NotUneal;

int main() {
    // Initialize framework
    GameFramework game;
    if (!game.Initialize()) {
        std::cerr << "Failed to initialize game framework" << std::endl;
        return -1;
    }
    
    // Create scene
    auto scene = std::make_shared<Scene>("MainScene");
    game.LoadScene(scene);
    
    // Create camera
    auto cameraObj = scene->CreateGameObject("Camera");
    auto camera = cameraObj->AddComponent<Camera>();
    auto cameraTransform = cameraObj->GetTransform();
    cameraTransform->SetPosition(Vec3(0, 2, 5));
    cameraTransform->SetRotation(glm::rotate(glm::quat(1, 0, 0, 0), 
                                             glm::radians(-20.0f), 
                                             Vec3(1, 0, 0)));
    
    // Create cube mesh (simple)
    std::vector<Vertex> vertices = {
        {{-1, -1, -1}, {0, 0, -1}, {1, 0, 0}, {0, 0}},
        {{1, -1, -1}, {0, 0, -1}, {1, 0, 0}, {1, 0}},
        {{1, 1, -1}, {0, 0, -1}, {1, 0, 0}, {1, 1}},
        {{-1, 1, -1}, {0, 0, -1}, {1, 0, 0}, {0, 1}},
        // ... more vertices ...
    };
    
    std::vector<uint32_t> indices = {
        0, 1, 2, 0, 2, 3,
        // ... more indices ...
    };
    
    auto mesh = std::make_shared<Mesh>();
    mesh->SetVertices(vertices);
    mesh->SetIndices(indices);
    
    // Create shader
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
            vec3 normal = normalize(Normal);
            float light = dot(normal, normalize(vec3(1, 1, 1))) * 0.5 + 0.5;
            FragColor = vec4(vec3(light), 1.0);
        }
    )";
    
    auto vShader = std::make_shared<Shader>(Shader::Type::Vertex, vertexShader);
    auto fShader = std::make_shared<Shader>(Shader::Type::Fragment, fragmentShader);
    vShader->Compile();
    fShader->Compile();
    
    auto program = std::make_shared<ShaderProgram>();
    program->AttachShader(vShader);
    program->AttachShader(fShader);
    program->Link();
    
    auto material = std::make_shared<Material>(program);
    material->SetColor("baseColor", Color(0.8f, 0.2f, 0.2f));
    
    // Create cube object
    auto cube = scene->CreateGameObject("Cube");
    auto meshComp = cube->AddComponent<MeshComponent>();
    meshComp->SetMesh(mesh);
    meshComp->SetMaterial(material);
    
    // Create light
    auto lightObj = scene->CreateGameObject("Light");
    auto light = lightObj->AddComponent<LightComponent>();
    light->SetLightType(LightType::Directional);
    light->SetColor(Color(1, 1, 1));
    light->SetIntensity(1.0f);
    auto lightTransform = lightObj->GetTransform();
    lightTransform->SetRotation(glm::rotate(glm::quat(1, 0, 0, 0),
                                            glm::radians(45.0f),
                                            Vec3(1, 0, 1)));
    
    // Main loop (simplified)
    const int FRAMES = 300;
    for (int i = 0; i < FRAMES; ++i) {
        float deltaTime = 0.016f; // ~60 FPS
        
        // Rotate cube
        auto cubeTransform = cube->GetTransform();
        auto rot = cubeTransform->GetRotation();
        rot = glm::rotate(rot, glm::radians(1.0f), Vec3(0, 1, 0));
        cubeTransform->SetRotation(rot);
        
        // Update and render
        game.Update(deltaTime);
        game.Render();
    }
    
    game.Shutdown();
    return 0;
}
```

Compile with:
```bash
g++ -std=c++17 -I./Engine example.cpp -o example -lNotUnealEngine -lOpenGL
```
