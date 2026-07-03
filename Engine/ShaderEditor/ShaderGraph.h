#pragma once

#include "ShaderNode.h"
#include <memory>
#include <vector>
#include <unordered_map>

namespace NotUneal {

/**
 * Shader graph combining nodes into a complete shader.
 */
class NOTUNEAL_EXPORT ShaderGraph {
public:
    ShaderGraph(const std::string& name = "Shader");
    ~ShaderGraph() = default;
    
    const std::string& GetName() const { return mName; }
    void SetName(const std::string& name) { mName = name; }
    
    // Node management
    std::shared_ptr<ShaderNode> AddNode(std::shared_ptr<ShaderNode> node);
    void RemoveNode(uint32_t nodeID);
    std::shared_ptr<ShaderNode> GetNode(uint32_t nodeID) const;
    const std::vector<std::shared_ptr<ShaderNode>>& GetNodes() const { return mNodes; }
    
    // Compilation
    bool Compile(std::string& outVertexShader, std::string& outFragmentShader);
    std::string GetCompileError() const { return mCompileError; }
    
    // Serialization
    std::string Serialize() const;
    bool Deserialize(const std::string& data);
    
private:
    std::string CompileGLSL() const;
    
    std::string mName;
    std::vector<std::shared_ptr<ShaderNode>> mNodes;
    std::unordered_map<uint32_t, std::shared_ptr<ShaderNode>> mNodeMap;
    std::string mCompileError;
};

} // namespace NotUneal
