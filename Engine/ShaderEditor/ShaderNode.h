#pragma once

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

namespace NotUneal {

/**
 * Base class for shader graph nodes.
 */
class ShaderNode {
public:
    enum class NodeType {
        Input,      // Vertex data inputs
        Texture,    // Texture sampling
        Math,       // Mathematical operations
        Output,     // Final output
        Custom      // Custom GLSL
    };
    
    ShaderNode(NodeType type, const std::string& name);
    virtual ~ShaderNode() = default;
    
    NodeType GetType() const { return mType; }
    const std::string& GetName() const { return mName; }
    uint32_t GetNodeID() const { return mNodeID; }
    
    // Connections
    void ConnectInput(uint32_t inputSlot, uint32_t sourceNodeID, uint32_t sourceOutputSlot);
    void DisconnectInput(uint32_t inputSlot);
    
    const std::vector<std::pair<uint32_t, uint32_t>>& GetConnections() const { return mConnections; }
    
    // Properties
    virtual std::string GetPropertyValue(const std::string& name) const { return ""; }
    virtual void SetPropertyValue(const std::string& name, const std::string& value) {}
    
    // Code generation
    virtual std::string GenerateGLSL() const = 0;
    
protected:
    NodeType mType;
    std::string mName;
    uint32_t mNodeID;
    std::vector<std::pair<uint32_t, uint32_t>> mConnections; // {sourceNodeID, sourceSlot}
};

} // namespace NotUneal
