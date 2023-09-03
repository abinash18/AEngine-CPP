#include "aepch.h"
#include "GLFWMouseAndKeyboardInput.h"

#include "GLFW/glfw3.h"

namespace AEngine {
    GLFWMouseAndKeyboardInput::GLFWMouseAndKeyboardInput() {
        mouseGrabbedAndHidden = false;
        mouseHidden           = false;
        mouseX                = 0;
        mouseY                = 0;
        keysDown              = {};
        keysUp                = {};
        keysHeldDown          = {};
        mouseButtonsDown      = {};
        mouseButtonsUp        = {};
        mouseButtonsHeldDown  = {};
        scrollOffsetX         = 0;
        scrollOffsetY         = 0;
    }

    GLFWMouseAndKeyboardInput::~GLFWMouseAndKeyboardInput() { }

    void GLFWMouseAndKeyboardInput::update() {
        keysDown.clear();
        keysUp.clear();
        mouseButtonsDown.clear();
        mouseButtonsUp.clear();
        scrollOffsetX = 0;
        scrollOffsetY = 0;
        glfwPollEvents();
    }

    void GLFWMouseAndKeyboardInput::initInput() { }

    void GLFWMouseAndKeyboardInput::setKeyDown(int key) {
        keysDown.insert(key);
        keysHeldDown.insert(key);
        if (keysUp.contains(key)) {
            keysUp.erase(key);
        }
    }

    void GLFWMouseAndKeyboardInput::setKeyUp(int key) {
        if (keysDown.contains(key)) {
            keysDown.erase(key);
            keysHeldDown.erase(key);
        }
        keysUp.insert(key);
    }

    void GLFWMouseAndKeyboardInput::setMouseButtonDown(int btn) {
        mouseButtonsDown.insert(btn);
        mouseButtonsHeldDown.insert(btn);
        if (mouseButtonsUp.contains(btn)) {
            mouseButtonsUp.erase(btn);
        }
    }

    void GLFWMouseAndKeyboardInput::setMouseButtonUp(int btn) {
        if (mouseButtonsDown.contains(btn)) {
            mouseButtonsDown.erase(btn);
            mouseButtonsHeldDown.erase(btn);
        }
        mouseButtonsUp.insert(btn);
    }

    void GLFWMouseAndKeyboardInput::setScrollOffsetX(const float scroll_offset_x) {
        scrollOffsetX = scroll_offset_x;
    }

    void GLFWMouseAndKeyboardInput::setScrollOffsetY(const float scroll_offset_y) {
        scrollOffsetY = scroll_offset_y;
    }

    bool GLFWMouseAndKeyboardInput::isKeyDown(int key) const {
        return keysDown.contains(key);
    }

    bool GLFWMouseAndKeyboardInput::isKeyUp(int key) const {
        return keysUp.contains(key);
    }

    bool GLFWMouseAndKeyboardInput::isKeyHeld(int key) const {
        return false;
    }

    bool GLFWMouseAndKeyboardInput::isMouseGrabbedAndHidden() const {
        return mouseGrabbedAndHidden;
    }

    bool GLFWMouseAndKeyboardInput::isMouseHidden() const {
        return mouseHidden;
    }

    bool GLFWMouseAndKeyboardInput::isCursorInWindow() const {
        return cursorInWindow;
    }

    float GLFWMouseAndKeyboardInput::getMouseX() const {
        return mouseX;
    }

    float GLFWMouseAndKeyboardInput::getMouseY() const {
        return mouseY;
    }

    float GLFWMouseAndKeyboardInput::getScrollOffsetX() const {
        return scrollOffsetX;
    }

    float GLFWMouseAndKeyboardInput::getScrollOffsetY() const {
        return scrollOffsetY;
    }

    float GLFWMouseAndKeyboardInput::getMouseX1() const {
        return mouseX;
    }

    void GLFWMouseAndKeyboardInput::setMouseX(const float mouse_x) {
        mouseX = mouse_x;
    }

    float GLFWMouseAndKeyboardInput::getMouseY1() const {
        return mouseY;
    }

    void GLFWMouseAndKeyboardInput::setMouseY(const float mouse_y) {
        mouseY = mouse_y;
    }

}
