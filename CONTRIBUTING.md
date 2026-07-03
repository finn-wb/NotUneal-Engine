# Contributing to NotUneal Engine

## Welcome!

Thank you for your interest in contributing to NotUneal Engine! This document provides guidelines and instructions for contributing.

## Code of Conduct

- Be respectful and inclusive
- Provide constructive feedback
- Focus on ideas, not individuals
- Help others succeed

## How to Contribute

### Reporting Bugs

1. Check if the bug has already been reported
2. Create a clear bug report including:
   - System information (OS, compiler, version)
   - Steps to reproduce
   - Expected behavior
   - Actual behavior
   - Error messages or logs

### Suggesting Features

1. Check if the feature has been suggested
2. Provide a clear description of the feature
3. Explain why this feature would be useful
4. Provide examples or mockups if applicable

### Submitting Pull Requests

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Follow the code style guidelines
4. Write tests for new functionality
5. Ensure all tests pass
6. Commit with clear messages
7. Push to your fork
8. Open a Pull Request with:
   - Clear description of changes
   - Related issue numbers
   - Screenshots for UI changes

## Code Style Guidelines

### C++ Style

```cpp
// Use PascalCase for classes
class MyComponent {
};

// Use camelCase for methods
void myMethod() {
}

// Use UPPER_CASE for constants
const float MAX_SPEED = 10.0f;

// Use m prefix for member variables
float mSpeed;

// Prefer meaningful names
float calculatedVelocity; // ✓
float cv;                  // ✗

// Use braces on same line
if (condition) {
    // code
}

// Comment complex logic
float angle = glm::atan(y, x); // Calculate angle in radians
```

### Documentation

```cpp
/**
 * Brief description of what this class does.
 * 
 * Longer description providing more detail about
 * the purpose, usage, and behavior of this class.
 */
class MyClass {
public:
    /**
     * Brief description of this method.
     * @param param1 Description of param1
     * @return Description of return value
     */
    int DoSomething(float param1);
};
```

### File Organization

```
Feature/
├── FeatureName.h          // Header file
├── FeatureName.cpp        // Implementation
├── SubFeature.h           // Related components
├── SubFeature.cpp
└── CMakeLists.txt         // Build configuration
```

## Development Setup

### Prerequisites
- CMake 3.16+
- C++17 compiler
- Git
- OpenGL development files

### Build Steps

```bash
git clone https://github.com/finn-wb/NotUneal-Engine.git
cd NotUneal-Engine
mkdir build
cd build
cmake -DNOTUNEAL_BUILD_EXAMPLES=ON -DNOTUNEAL_BUILD_TESTS=ON ..
cmake --build . --config Debug
```

### Running Tests

```bash
ctest --verbose
```

## Project Areas

### Core Engine
- Scene system improvements
- Memory optimization
- Serialization system

### Rendering
- Advanced lighting (PBR, Global Illumination)
- Compute shaders
- Ray tracing
- Post-processing effects

### Shader Editor
- More node types
- Graph optimization
- Visual improvements
- Node libraries

### Asset System
- Complete importer implementations
- Compression options
- Streaming optimization
- Format support

### Editor
- UI implementation (Qt integration)
- Gizmo rendering
- Property inspector
- Hierarchy visualization

### Tools & Framework
- Physics integration
- Particle system
- Animation system
- Audio system
- Input improvements

### Documentation
- API documentation
- Tutorial videos
- Example projects
- Best practices guide

## Commit Message Guidelines

```
<type>: <subject>

<body>

<footer>
```

Types:
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation
- `style`: Code style changes
- `refactor`: Code refactoring
- `perf`: Performance improvements
- `test`: Tests

Example:
```
feat: Add parallax mapping shader nodes

Implement parallax mapping nodes for the shader editor.
Includes height map sampling and UV offset calculation.

Closes #123
```

## Pull Request Process

1. Update documentation if needed
2. Update the ROADMAP.md with any new features
3. Add tests for new functionality
4. Ensure CI/CD passes
5. Request review from maintainers
6. Address feedback
7. Maintainers will merge when approved

## Questions?

- Check the documentation
- Review existing issues and discussions
- Open a new discussion
- Contact maintainers

## Recognition

All contributors are recognized in:
- CONTRIBUTORS.md
- GitHub contributors page
- Release notes

Thank you for helping make NotUneal Engine better! 🎮
