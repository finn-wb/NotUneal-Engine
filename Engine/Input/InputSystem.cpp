#include "InputSystem.h"
#include <cstring>

namespace NotUneal {

InputSystem& InputSystem::Get() {
    static InputSystem instance;
    return instance;
}

bool InputSystem::IsKeyPressed(Key key) const {
    return mKeyPressed[static_cast<int>(key)];
}

bool InputSystem::IsKeyDown(Key key) const {
    return mKeyDown[static_cast<int>(key)];
}

bool InputSystem::IsKeyUp(Key key) const {
    return !mKeyDown[static_cast<int>(key)];
}

bool InputSystem::IsMouseButtonPressed(MouseButton button) const {
    return mMouseButtonPressed[static_cast<int>(button)];
}

bool InputSystem::IsMouseButtonDown(MouseButton button) const {
    return mMouseButtonDown[static_cast<int>(button)];
}

bool InputSystem::IsMouseButtonUp(MouseButton button) const {
    return !mMouseButtonDown[static_cast<int>(button)];
}

void InputSystem::UpdateKeyState(Key key, bool pressed) {
    int index = static_cast<int>(key);
    mKeyPressed[index] = pressed;
    if (pressed) {
        mKeyDown[index] = true;
    }
}

void InputSystem::UpdateMousePosition(float x, float y) {
    mMouseDeltaX = x - mMouseX;
    mMouseDeltaY = y - mMouseY;
    mMouseX = x;
    mMouseY = y;
}

void InputSystem::UpdateMouseButtonState(MouseButton button, bool pressed) {
    int index = static_cast<int>(button);
    mMouseButtonPressed[index] = pressed;
    if (pressed) {
        mMouseButtonDown[index] = true;
    }
}

void InputSystem::UpdateFrame() {
    // Reset per-frame tracking
    std::memset(mKeyPressed, 0, sizeof(mKeyPressed));
    std::memset(mMouseButtonPressed, 0, sizeof(mMouseButtonPressed));
    mMouseDeltaX = 0.0f;
    mMouseDeltaY = 0.0f;
}

} // namespace NotUneal
