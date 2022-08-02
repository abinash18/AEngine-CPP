#pragma once

#include "aepch.h"

#include "AEngine/Core.h"
#include "AEngine/input/event/Event.h"

namespace AEngine {
	class AE_API Window {
		public:
			using event_callback_fn = std::function<void(Event&)>;

			virtual ~Window() {
			};
			virtual void update() = 0;
			virtual void swapbuffers() = 0;
			virtual void input() = 0;

			// Used to request close
			virtual void requestClose() = 0;

			virtual bool isCloseRequested() = 0;

			virtual void destroy() = 0;

			/**
			 * Getters and setters
			 */
			virtual int*         getWindowHandle() = 0;
			virtual unsigned int getWidth() const = 0;
			virtual unsigned int getHeight() const = 0;
			virtual void         setEventCallback(const event_callback_fn& callback) = 0;
			virtual void         setVSync(bool enabled) = 0;
			virtual bool         isVSync() const = 0;

			virtual Window* create() = 0;
	};
}
