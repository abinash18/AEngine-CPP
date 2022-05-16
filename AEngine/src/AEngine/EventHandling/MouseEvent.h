#pragma once
#include "Event.h"
#include <ostream>
#include <sstream>

namespace AEngine {

	class AE_API MouseMovedEvent : public Event {
		public:
			MouseMovedEvent(float _x, float _y) : x(_x), y(_y) {};

			inline float getX() const { return x; }
			inline float getY() const { return y; }

			std::string toString() const override {
				std::stringstream ss;
				ss << "MouseMovedEvent: " << x << ", " << y;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MOUSE_MOVED)
			EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)
		private:
			float x, y;
	};

	class AE_API MouseScrolledEvent : public Event {
		public:
			MouseScrolledEvent(float _xOffset, float _yOffset)
				: xOffset(_xOffset), yOffset(_yOffset) {}

			inline float getXOffset() const { return xOffset; }
			inline float getYOffset() const { return yOffset; }

			std::string toString() const override {
				std::stringstream ss;
				ss << "MouseMovedEvent: " << xOffset << ", " << yOffset;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MOUSE_SCROLLED)
			EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)
		private:
			float xOffset, yOffset;
	};

	/**
	 * @brief A abstract class that will extend to mouse button pressed and released Events.
	*/
	class AE_API MouseButtonEvent : public Event {
		public:
			EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)
		protected:
			MouseButtonEvent(int _button) : button(_button) {}
			int button;
	};

	class AE_API MouseButtonPressedEvent : public MouseButtonEvent {
		public:
			MouseButtonPressedEvent(int _button) : MouseButtonEvent(_button) {}

			std::string toString() const override {
				std::stringstream ss;
				ss << "MouseButtonPressedEvent: " << button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
	};


	class AE_API MouseButtonReleasedEvent : public MouseButtonEvent {
		public:
			MouseButtonReleasedEvent(int _button) : MouseButtonEvent(_button) {}

			std::string toString() const override {
				std::stringstream ss;
				ss << "MouseButtonReleasedEvent: " << button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)
	};
} // namespace AEngine
