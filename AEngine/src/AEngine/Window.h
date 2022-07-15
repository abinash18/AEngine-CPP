#pragma once

#include "aepch.h"

#include "AEngine/Core.h"
#include "AEngine/EventHandling/Event.h"

namespace AEngine {
	struct WindowProperties {
		std::string  title;
		unsigned int width, height;
		bool fullscreen, vSync;

		WindowProperties(const std::string title  = "AEngine",
						 unsigned int      width  = 1280,
						 unsigned int      height = 720)
			: title(title), width(width), height(height) {};
	};

	class AE_API Window {
		public:
			using event_callback_fn = std::function<void(Event&)>;
			virtual              ~Window() {};
			virtual void         update() = 0;
			virtual unsigned int getWidth() const = 0;
			virtual unsigned int getHeight() const = 0;

			virtual void setEventCallback(const event_callback_fn& callback) = 0;
			virtual void setVSync(bool enabled) = 0;
			virtual bool isVSync() const = 0;

			static Window* Create(const WindowProperties& props = WindowProperties());
	};
}
