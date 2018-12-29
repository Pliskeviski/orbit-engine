#pragma once

#include "../Event.h"

namespace Orbit {
	class ORBIT_API KeyEvent : public Event {
	public:
		int GetKeyCode() const;

		virtual int GetCategoryFlags() const;
		virtual std::string ToString() const override = 0;
	protected:
		KeyEvent(int keycode);
		int m_KeyCode;
	};

	class ORBIT_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount);

		int GetRepeatCount() const;

		std::string ToString() const;

		static EventType GetStaticType();
	private:
		int m_RepeatCount;
	};

	class ORBIT_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode);

		std::string ToString() const;

		static EventType GetStaticType();
	};
}

