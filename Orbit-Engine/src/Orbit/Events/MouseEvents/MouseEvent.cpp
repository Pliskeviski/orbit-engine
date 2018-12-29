#include "obtpch.h"
#include "MouseEvent.h"


namespace Orbit {
	MouseMovedEvent::MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}
	
	float MouseMovedEvent::GetX() const {
		return m_MouseX;
	}

	float MouseMovedEvent::GetY() const {
		return m_MouseY;
	}

	std::string MouseMovedEvent::ToString() const {
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
		return ss.str();
	}
	EventType MouseMovedEvent::GetStaticType() {
		return EventType::MouseMoved;
	}

	int MouseMovedEvent::GetCategoryFlags() const {
		return EventCategoryMouse | EventCategoryInput;
	}

	/*
		Mouse Event Scroll
	*/
	MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}
	
	float MouseScrolledEvent::GetXOffset() const {
		return m_XOffset;
	}

	float MouseScrolledEvent::GetYOffset() const {
		return m_XOffset;
	}
	std::string MouseScrolledEvent::ToString() const {
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
		return ss.str();
	}

	EventType MouseScrolledEvent::GetStaticType() {
		return EventType::MouseScrolled;
	}

	int MouseScrolledEvent::GetCategoryFlags() const {
		return EventCategoryMouse | EventCategoryInput;
	}

	// Mouse button
	int MouseButtonEvent::GetMouseButton() const { 
		return m_Button; 
	}
	int MouseButtonEvent::GetCategoryFlags() const {
		return EventCategoryMouse | EventCategoryInput;
	}
	MouseButtonEvent::MouseButtonEvent(int button) : m_Button(button) {}

	// Mouse Pressed
	MouseButtonPressedEvent::MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}
	std::string MouseButtonPressedEvent::ToString() const {
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_Button;
		return ss.str();
	}
	EventType MouseButtonPressedEvent::GetStaticType()
	{
		return EventType::MouseButtonPressed;
	}

	// Mouse Released
	MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

	std::string MouseButtonReleasedEvent::ToString() const {
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_Button;
		return ss.str();
	}

	EventType MouseButtonReleasedEvent::GetStaticType() {
		return EventType::MouseButtonReleased;
	}
}