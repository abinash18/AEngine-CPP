#pragma once
namespace AEngine {
    class RenderContext {
        public:
            RenderContext() {
            };
            virtual ~RenderContext() = default;
            virtual void init() = 0;
            virtual void swapBuffers() = 0;
    };
}
