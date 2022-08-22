#pragma once
#include "AEngine/render/api/ae/RenderContext.h"

struct GLFWwindow;

namespace AEngine {
    class ContextOGL : public RenderContext {
        public:
            ContextOGL(GLFWwindow* handle);
            void init() override;
            void    swapBuffers() override;
        private:
            GLFWwindow* handle;
    };
}
