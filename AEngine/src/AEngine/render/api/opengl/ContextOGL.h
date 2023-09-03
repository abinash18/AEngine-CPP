#pragma once
#include "AEngine/render/api/ae/RenderContext.h"

struct GLFWwindow;

namespace AEngine {
    class ContextOGL : public RenderContext {
        public:
            ContextOGL(GLFWwindow* handle);
            virtual void init() override;
            virtual void swapBuffers() override;
        private:
            GLFWwindow* handle;
    };
}
