#pragma once
#include "AEngine/core/Core.h"
#include "AEngine/render/window/GLFWWindow.h"

namespace AEngine {
	class EngineLoadingWindow : public GLFWWindow {
		public:
			EngineLoadingWindow();
			~EngineLoadingWindow();
			void destroy() override;
			void input(float delta) override;
			void update(float delta) override;

		protected:
			void preInit() override;
			void postInit() override;
	};
}
