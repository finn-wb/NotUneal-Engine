#!/bin/bash
# Build script for NotUneal Engine
# Usage: ./build.sh [options]

set -e

echo "============================================"
echo "NotUneal Engine - Build Script"
echo "============================================"
echo ""

# Color output
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Default options
BUILD_TYPE="Release"
BUILD_EDITOR=ON
BUILD_TOOLS=ON
BUILD_EXAMPLES=ON
BUILD_TESTS=OFF

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -d|--debug)
            BUILD_TYPE="Debug"
            shift
            ;;
        --no-editor)
            BUILD_EDITOR=OFF
            shift
            ;;
        --no-tools)
            BUILD_TOOLS=OFF
            shift
            ;;
        --no-examples)
            BUILD_EXAMPLES=OFF
            shift
            ;;
        --tests)
            BUILD_TESTS=ON
            shift
            ;;
        --clean)
            rm -rf build
            echo -e "${GREEN}Cleaned build directory${NC}"
            shift
            ;;
        -h|--help)
            echo "Usage: ./build.sh [options]"
            echo ""
            echo "Options:"
            echo "  -d, --debug           Build debug version"
            echo "  --no-editor           Skip editor build"
            echo "  --no-tools            Skip tools build"
            echo "  --no-examples         Skip examples build"
            echo "  --tests               Build tests"
            echo "  --clean               Clean build directory"
            echo "  -h, --help            Show this help message"
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

echo -e "${YELLOW}Configuration:${NC}"
echo "  Build Type: $BUILD_TYPE"
echo "  Editor: $BUILD_EDITOR"
echo "  Tools: $BUILD_TOOLS"
echo "  Examples: $BUILD_EXAMPLES"
echo "  Tests: $BUILD_TESTS"
echo ""

# Create build directory
if [ ! -d "build" ]; then
    mkdir build
    echo -e "${GREEN}Created build directory${NC}"
fi

cd build

# Configure
echo -e "${YELLOW}Configuring CMake...${NC}"
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
      -DNOTUNEAL_BUILD_EDITOR=$BUILD_EDITOR \
      -DNOTUNEAL_BUILD_TOOLS=$BUILD_TOOLS \
      -DNOTUNEAL_BUILD_EXAMPLES=$BUILD_EXAMPLES \
      -DNOTUNEAL_BUILD_TESTS=$BUILD_TESTS \
      ..

echo -e "${GREEN}CMake configuration complete${NC}"
echo ""

# Build
echo -e "${YELLOW}Building...${NC}"
cmake --build . --config $BUILD_TYPE -j$(nproc || echo 4)

echo ""
echo -e "${GREEN}============================================${NC}"
echo -e "${GREEN}Build Complete!${NC}"
echo -e "${GREEN}============================================${NC}"
echo ""
echo "Output:"
echo "  Libraries: ./build/"
if [ "$BUILD_EXAMPLES" = "ON" ]; then
    echo "  Examples: ./build/Examples/"
fi
if [ "$BUILD_TESTS" = "ON" ]; then
    echo "  Tests: Run with 'ctest --verbose'"
fi
echo ""
