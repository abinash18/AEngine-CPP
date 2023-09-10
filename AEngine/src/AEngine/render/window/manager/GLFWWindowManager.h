#pragma once

#include "AEngine/core/CoreEngine.h"
#include "GLFW/glfw3.h"

#include "AEngine/core/Core.h"

namespace AEngine {

    struct AE_API WindowContext { };

    class AE_API GLFWWindowManager : public WindowManager {
        public:
            GLFWWindowManager(CoreEngine* controller);
            ~GLFWWindowManager() override;
            virtual void render() override;
            virtual void update(float delta) override;
            virtual void input(float delta) override;
            virtual void openWindow(std::string id, Window* wnd) override;
            virtual bool isEngineStopFlagRaised() const override;
            virtual void raiseEngineStopFlag() override;
            virtual void setErrorCallback(void(*errorCallback)(int, const char*)) override;
        private:
            bool ENGINE_STOP_FLAG = false;

            //std::map<std::string, Window*> windows;
            std::vector<Window*> windows;

            /**
             * @brief The controlling CoreEngine,
             * this is used for debug purposes and quick prototyping.
             * In the future there can be multiple window managers idk why but i want support for that.
            */
            CoreEngine* controler;

            void setContext(Window* wnd);

    };
}
