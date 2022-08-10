#pragma once

#include "AEngine/core/CoreEngine.h"
#include "GLFW/glfw3.h"

#include "AEngine/core/Core.h"

namespace AEngine {

	struct AE_API WindowContext {

	};

	class AE_API GLFWWindowManager : public WindowManager {
		public:
			GLFWWindowManager(CoreEngine* controller);
			~GLFWWindowManager();
			void render() override;
			void update(float delta) override;
			void input(float delta) override;
			void openWindow(std::string id, Window* wnd) override;
			bool isEngineStopFlagRaised() const override;
			void raiseEngineStopFlag() override;
			void setErrorCallback(void* errorCallback);
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
