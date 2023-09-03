#include "aepch.h"
#include "ContextOGL.h"

#include <GLFW/glfw3.h>

#include "glad/glad.h"

namespace AEngine {
    ContextOGL::ContextOGL(GLFWwindow* handle) : handle(handle) {
        AE_CORE_ASSERT(handle, "Window Handle is NULL");
    }

    void ContextOGL::init() {
        glfwMakeContextCurrent(handle);

        // Load gl functions in this context.
        int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        AE_CORE_ASSERT(status, "Failed GLAD Initialization");
    }


    void ContextOGL::swapBuffers() {
        glfwSwapBuffers(handle);
    }
}
