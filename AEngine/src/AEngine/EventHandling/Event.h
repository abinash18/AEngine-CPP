/********************************************************************
 * \file   Event.h
 * \brief  Event handling main header.
 *
 * \author abina
 * \date   July 2021
 *********************************************************************/
#pragma once

#include "../Core.h"

#include <functional>
#include <ostream>
#include <string>

/**
 * Currently Blocking IO
 */
namespace AEngine {
	/**
	 *
	 * All the different types of blocking events.
	 */
	enum class EventType {
		NONE = 0,
		WINDOW_CLOSE,
		WINDOW_RESIZE,
		WINDOW_FOCUS,
		WINDOW_LOST_FOCUS,
		WINDOW_MOVED,
		APPLICATION_TICK,
		APPLICATION_UPDATE,
		APPLICATION_RENDER,
		KEY_PRESSED,
		KEY_RELEASED,
		MOUSE_BUTTON_PRESSED,
		MOUSE_BUTTON_RELEASED,
		MOUSE_MOVED,
		MOUSE_SCROLLED
	};

	/**
	 *
	 * Bit fields for event categories. The BIT Macro is just shifting 1 by X bits.
	 */
	enum EventCategory {
		NONE = 0,
		EVENT_CATEGORY_APPLICATION = BIT(0),
		EVENT_CATEGORY_INPUT = BIT(1),
		EVENT_CATEGORY_KEYBOARD = BIT(2),
		EVENT_CATEGORY_MOUSE = BIT(3),
		EVENT_CATEGORY_MOUSE_BUTTON = BIT(4)
	};

	#define EVENT_CLASS_TYPE(type) \
	static EventType GetStaticType() { return EventType::##type; } \
  virtual EventType getEventType() const override { return GetStaticType(); } \
  virtual const char *getName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) \
  virtual int getCategoryFlags() const override { return category; }

	/**
	 *
	 * Event class which defines an Event and stores attributes.
	 */
	class AE_API Event {
		friend class EventDispatcher;

		public:
			/**  Pure virtual methods; All event sub classes have to implement them.*/
			virtual EventType   getEventType() const = 0;
			virtual const char* getName() const = 0;
			virtual int         getCategoryFlags() const = 0;
			virtual std::string toString() const { return getName(); }

			bool isInCategory(EventCategory category) { return getCategoryFlags() & category; }

		protected:
			/** If the event has been handled already or not. This is required in layered
			 * systems.*/
			bool m_Handled = false;
	};

	class EventDispatcher {
		template <typename T>
		using EventFn = std::function<bool(T&)>;

		public:
			EventDispatcher(Event& event) : m_Event(event) {}

			template <typename T>
			bool dispatch(EventFn<T> func) {
				if (m_Event.getEventType() == T::GetStaticType()) {
					m_Event.m_Handled = func(*static_cast<T*>(&m_Event));
					return true;
				}
				return false;
			}

		private:
			Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) { return os << e.toString(); }
} // namespace AEngine
