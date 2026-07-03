#include "ShaderGraph.h"
#include <sstream>

namespace NotUneal {

ShaderGraph::ShaderGraph(const std::string& name) : mName(name) {}

std::shared_ptr<ShaderNode> ShaderGraph::AddNode(std::shared_ptr<ShaderNode> node) {
    mNodes.push_back(node);
    mNodeMap[node->GetNodeID()] = node;
    return node;
}

void ShaderGraph::RemoveNode(uint32_t nodeID) {
    auto it = mNodeMap.find(nodeID);
    if (it != mNodeMap.end()) {
        auto node = it->second;
        auto vecIt = std::find(mNodes.begin(), mNodes.end(), node);
        if (vecIt != mNodes.end()) {
            mNodes.erase(vecIt);
        }
        mNodeMap.erase(it);
    }
}

std::shared_ptr<ShaderNode> ShaderGraph::GetNode(uint32_t nodeID) const {
    auto it = mNodeMap.find(nodeID);
    if (it != mNodeMap.end()) {
        return it->second;
    }
    return nullptr;
}

bool ShaderGraph::Compile(std::string& outVertexShader, std::string& outFragmentShader) {
    try {
        std::string glslCode = CompileGLSL();
        
        // Split into vertex and fragment shaders
        // TODO: Implement shader splitting logic
        outVertexShader = glslCode;
        outFragmentShader = glslCode;
        
        return true;
    } catch (const std::exception& e) {
        mCompileError = e.what();
        return false;
    }
}

std::string ShaderGraph::CompileGLSL() const {
    std::stringstream ss;
    
    ss << "#version 460 core\n\n";
    
    // Generate code from nodes
    for (const auto& node : mNodes) {
        ss << node->GenerateGLSL() << "\n";
    }
    
    return ss.str();
}

std::string ShaderGraph::Serialize() const {
    // TODO: Implement serialization
    return "{}";
}

bool ShaderGraph::Deserialize(const std::string& data) {
    // TODO: Implement deserialization
    return true;
}

} // namespace NotUneal
