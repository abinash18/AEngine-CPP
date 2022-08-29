#pragma once
#include "AEngine/core/Core.h"
#include "AEngine/render/window/GLFWWindow.h"

namespace AEngine {
    class EngineLoadingWindow : public GLFWWindow {
        public:
            EngineLoadingWindow();
            ~EngineLoadingWindow() override;
            virtual void destroy() override;
            virtual void input(float delta) override;
            virtual void update(float delta) override;

        protected:
            virtual void preInit() override;
            virtual void postInit() override;
    };
}
