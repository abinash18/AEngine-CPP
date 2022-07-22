#pragma once

#include "AEngine/Window.h"

#include <GLFW/glfw3.h>

namespace AEngine {
	class WindowsWindow : public Window {
		public:
			WindowsWindow(const WindowProperties& properties);
			virtual ~WindowsWindow();
			void    update() override;

			inline unsigned int getWidth() const override {
				return m_data.width;
			};

			inline unsigned int getHeight() const override {
				return m_data.height;
			};

			inline void setEventCallback(const event_callback_fn& callback) override {
				m_data.set_event_callback = callback;
			};
			void setVSync(bool enabled) override;
			bool isVSync() const override;
			void swapbuffers() override;
			void post_init() override;
			void pre_init() override;
		private:
			virtual void init(const WindowProperties& properties);
			virtual void close();
		private:
			GLFWwindow* m_Window;

			struct WindowData {
				std::string       title;
				unsigned int      width, height;
				bool              vSync, fullscreen;
				event_callback_fn set_event_callback;
			};

			WindowData m_data;
	};
}
