#pragma once

#include "Orbit/Core.h"

#include <string>
#include <sstream>

namespace Orbit {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyRelease,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput		 = BIT(1),
		EventCategoryKeyboard	 = BIT(2),
		EventCategoryMouse		 = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	class ORBIT_API Event {
	public:
		virtual const char* GetName() const { return NULL; };
		virtual int GetCategoryFlags() const { return 0; };
		virtual EventType GetEventType() const { return EventType::None; };

		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	protected:
		bool e_Handled = false;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}
