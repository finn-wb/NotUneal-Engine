#pragma once

namespace NotUneal {

/**
 * Input system for handling keyboard, mouse, and controller input.
 */
class NOTUNEAL_EXPORT InputSystem {
public:
    enum class Key {
        W, A, S, D,
        Space, Shift, Ctrl,
        Up, Down, Left, Right,
        Enter, Escape,
        // Add more as needed
    };
    
    enum class MouseButton {
        Left,
        Middle,
        Right
    };
    
    static InputSystem& Get();
    
    bool IsKeyPressed(Key key) const;
    bool IsKeyDown(Key key) const;
    bool IsKeyUp(Key key) const;
    
    bool IsMouseButtonPressed(MouseButton button) const;
    bool IsMouseButtonDown(MouseButton button) const;
    bool IsMouseButtonUp(MouseButton button) const;
    
    float GetMouseX() const { return mMouseX; }
    float GetMouseY() const { return mMouseY; }
    float GetMouseDeltaX() const { return mMouseDeltaX; }
    float GetMouseDeltaY() const { return mMouseDeltaY; }
    
    // Called by platform layer
    void UpdateKeyState(Key key, bool pressed);
    void UpdateMousePosition(float x, float y);
    void UpdateMouseButtonState(MouseButton button, bool pressed);
    void UpdateFrame();
    
private:
    InputSystem() = default;
    
    // Key state tracking
    bool mKeyPressed[32];
    bool mKeyDown[32];
    bool mMouseButtonPressed[3];
    bool mMouseButtonDown[3];
    
    float mMouseX, mMouseY;
    float mMouseDeltaX, mMouseDeltaY;
};

} // namespace NotUneal
