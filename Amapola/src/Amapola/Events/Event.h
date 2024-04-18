#pragma once

#include "amplpch.h"
#include "Amapola/Core.h"

namespace Amapola
{
	/*
	* 
	* TODO Events for now are currently blocking, meaning when an event is triggered, the whole app stops to process it.
	* Maybe a good strategy for the future is to implement a queue, bus or something to buffer events and deal with them
	* 
	*/

	enum class EventType
	{
		None = 0,
		
		// Window events (./ApplicationEvent.h) - TODO Maybe move to a WindowEvent.h file?
		WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved,

		// App events (./ApplicationEvent.h)
		AppTick, AppUpdated, AppRender,

		// Key events (./KeyEvent.h)
		KeyPressed, KeyReleased,

		// Mouse events (./MouseEvent.h)
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	/*
	* 
	* This enum is for categorizing the different types of events so if we need to manage
	* all events of the same type we can do it easily
	* 
	* For example: if we need to log all mouse events, it'll be easier to manage/validate that logic using this enum
	* 
	*/
	// TODO Remove "EventCategory" from names?
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	/*
	* To prevent declaring this for all events, these macros will do the same for all
	* 
	* For example (KeyPressed):
	* static EventType GetStaticType() { return EventType::KeyPressed; }
	* virtual EventType GetEventType() const override { return GetStaticType(); }
	* virtual const char* GetName() const override { return "KeyPressed"; }
	* 
	*/
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class AMAPOLA_API Event
	{
		friend class EventDispatcher;
		
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }

	protected:
		bool m_Handled = false;
	};

	/*
	* 
	* This dispatches any type of event we indicate in the constructor
	* Basically what this does is call the EventFn when the Dispatch method is used/called
	* 
	*/
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			// If the event type is the same as in the T type in the func param, it calls this func function
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				// This *(T*)&m_Event casts m_Event ref from an Event to T
				m_Event.m_Handled = func(*(T*)&m_Event);
				// First, &m_Event gets the memory address of m_Event (being an Event*)
				// Then, this Event* gets casted into a T* using (T*) (now being indeed a T*)
				// Finally, this T* gets "dereferenced" into a T with *(T*)&m_Event

				return true;
			}
			return false;
		}
	
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) { return os << e.ToString(); }
}
