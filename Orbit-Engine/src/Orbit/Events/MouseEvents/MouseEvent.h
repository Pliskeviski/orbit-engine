#pragma once

#include "../Event.h"

namespace Orbit {

	class ORBIT_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y);

		float GetX() const;
		float GetY() const;

		std::string ToString() const;

		virtual int GetCategoryFlags() const;

		EVENT_CLASS_TYPE(MouseMoved)
	private:
		float m_MouseX, m_MouseY;
	};

	class ORBIT_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset);

		float GetXOffset() const;
		float GetYOffset() const;

		std::string ToString() const;

		EVENT_CLASS_TYPE(MouseScrolled)
		virtual int GetCategoryFlags() const;
	private:
		float m_XOffset, m_YOffset;
	};

	// Mouse button base class
	class ORBIT_API MouseButtonEvent : public Event {
	public:
		int GetMouseButton() const; 

		virtual int GetCategoryFlags() const;
	protected:
		MouseButtonEvent(int button);

		int m_Button;
	};

	class ORBIT_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button);

		std::string ToString() const;
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class ORBIT_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button);

		std::string ToString() const;
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}