#include "KeyEvents.h"

namespace Orbit {

	/*
		Key Event base class
	*/
	KeyEvent::KeyEvent(int keycode) : m_KeyCode(keycode) {
	}

	int KeyEvent::GetKeyCode() const {
		return this->m_KeyCode;
	}
	
	int KeyEvent::GetCategoryFlags() const {
		return EventCategoryKeyboard | EventCategoryInput;
	}

	/*
		Key pressed
	*/

	KeyPressedEvent::KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

	int KeyPressedEvent::GetRepeatCount() const { return m_RepeatCount; }

	std::string KeyPressedEvent::ToString() const {
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
		return ss.str();
	}

	EventType KeyPressedEvent::GetStaticType() {
		return EventType::KeyPressed;
	}

	/*
		Key released
	*/

	KeyReleasedEvent::KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}
	
	std::string KeyReleasedEvent::ToString() const {
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_KeyCode;
		return ss.str();
	}

	EventType KeyReleasedEvent::GetStaticType() {
		return EventType::KeyRelease;
	}
}
