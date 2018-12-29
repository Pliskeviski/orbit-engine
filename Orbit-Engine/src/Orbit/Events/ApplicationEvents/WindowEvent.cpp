#include "WindowEvent.h"


namespace Orbit {
	
	/*
		Window Resize Events
	*/
	WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height) {
	}

	WindowResizeEvent::~WindowResizeEvent() {
	}
	unsigned int WindowResizeEvent::GetWidth() {
		return this->m_width;
	}
	unsigned int WindowResizeEvent::GetHeight() {
		return this->m_height;
	}
	std::string WindowResizeEvent::ToString() const {
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_width << ", " << m_height;
		return ss.str();
	}
	EventType WindowResizeEvent::GetStaticType() {
		return EventType::WindowResize;
	}
	int WindowResizeEvent::GetCategoryFlags() const {
		return EventCategoryApplication;
	}

	/* 
	 	Window Close Events
	*/
	WindowCloseEvent::WindowCloseEvent() {
	}

	EventType WindowCloseEvent::GetStaticType() {
		return EventType::WindowClose;
	}

	int WindowCloseEvent::GetCategoryFlags() const {
		return EventCategoryApplication;
	}

}
