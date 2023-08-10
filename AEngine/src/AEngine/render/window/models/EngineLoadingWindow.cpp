#include "aepch.h"
#include "EngineLoadingWindow.h"

namespace AEngine {
    EngineLoadingWindow::EngineLoadingWindow() : GLFWWindow() { }

    EngineLoadingWindow::~EngineLoadingWindow() { }

    void EngineLoadingWindow::destroy() {
        GLFWWindow::destroy();
    }

    void EngineLoadingWindow::input(float delta) {
        GLFWWindow::input(delta);
    }

    void EngineLoadingWindow::update(float delta) {
        GLFWWindow::update(delta);
    }

    void EngineLoadingWindow::preInit() {
        //addGLFWWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
        //addGLFWWindowHint(GLFW_DECORATED, GLFW_FALSE);
        //addGLFWWindowHint(GLFW_DECORATED, GLFW_FALSE);
        //addGLFWWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        //properties.start_hidden = true;
    }
    void EngineLoadingWindow::postInit() {
        setVSync(false);
        
    }
}
