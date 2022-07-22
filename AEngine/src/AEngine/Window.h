#pragma once

#include "aepch.h"

#include "AEngine/Core.h"
#include "AEngine/EventHandling/Event.h"

namespace AEngine {
	struct WindowProperties {
		std::string  title;
		unsigned int width,      height;
		bool         fullscreen, vSync;

		WindowProperties(const std::string title  = "AEngine",
						 unsigned int      width  = 1280,
						 unsigned int      height = 720)
			: title(title), width(width), height(height) {};
	};

	class AE_API Window {
		public:
			using event_callback_fn = std::function<void(Event&)>;
			virtual ~Window() {};

			virtual void         update() = 0;
			virtual void         swapbuffers() = 0;
			virtual unsigned int getWidth() const = 0;
			virtual unsigned int getHeight() const = 0;

			virtual void setEventCallback(const event_callback_fn& callback) = 0;
			virtual void setVSync(bool enabled) = 0;
			virtual bool isVSync() const = 0;

			// This is where user will add any pre creation window hints
			virtual void pre_init() = 0;
			// This is where the user can execute any post creation methods that require context.
			virtual void post_init() = 0;
			// Used to request close
			virtual void close() = 0;

			static Window* create(const WindowProperties& props = WindowProperties());
	};
}
