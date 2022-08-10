#pragma once
#include "AEngine/core/Core.h"
#include "AEngine/render/window/Window.h"

namespace AEngine {
	class AE_API WindowManager {
		public:
			WindowManager() {
			};

			virtual ~WindowManager() {
			};

			virtual void render() = 0;
			virtual void update(float delta) = 0;
			virtual void input(float delta) = 0;
			virtual void openWindow(std::string id, Window* wnd) = 0;
			virtual bool isEngineStopFlagRaised() const = 0;
			virtual void raiseEngineStopFlag() = 0;
			virtual void setErrorCallback(void* errorCallback) = 0;
	};
}
