#pragma once
#include "Event.h"

namespace AEngine {

	/**
	 * @brief When the window is resized by the user.
	*/
	class AE_API WindowResizeEvent : public Event {
		public:
			/**
			 * @brief Constructor to the window resize event.
			 * @param _width The new width of the new window.
			 * @param _height The new height of the window.
			*/
			WindowResizeEvent(unsigned int _width, unsigned int _height) : width(_width), height(_height) {
			};

			/**
			 * @brief 
			 * @return width
			*/
			unsigned int getWidth() {
				return width;
			}

			/**
			 * @brief 
			 * @return height
			*/
			unsigned int getHeight() {
				return height;
			}

			/**
			 * @brief toString overloader
			 * @return 
			*/
			std::string toString() const override {
				std::stringstream ss;
				ss << "WindowResizeEvent: " << width << ", " << height;
				return ss.str();
			};

			EVENT_CLASS_TYPE(WINDOW_RESIZE)
			EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
		private:
			unsigned int width, height;
	};

	/**
	 * @brief Sent on the window close request
	*/
	class AE_API WindowCloseEvent : public Event {
		public:
			WindowCloseEvent() {
			};

			EVENT_CLASS_TYPE(WINDOW_CLOSE)
			EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
	};

	/**
	 * @brief Sent when the render is called on the application
	*/
	class AE_API ApplicationRenderEvent : public Event {
		public:
			ApplicationRenderEvent() {
			};

			EVENT_CLASS_TYPE(APPLICATION_RENDER)
			EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
	};

	/**
	 * @brief Sent when the window is updated
	*/
	class AE_API ApplicationUpdateEvent : public Event {
		public:
			ApplicationUpdateEvent() {
			};

			EVENT_CLASS_TYPE(APPLICATION_UPDATE)
			EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
	};

	/**
	 * @brief Sent when the engine ticks the application.
	*/
	class AE_API ApplicationTickEvent : public Event {
		public:
			ApplicationTickEvent() {
			};

			EVENT_CLASS_TYPE(APPLICATION_TICK)
			EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
	};
} // namespace AEngine
