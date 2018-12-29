#pragma once
#include "../Event.h"

namespace Orbit {
	class ORBIT_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height);
		~WindowResizeEvent();
		
		unsigned int GetWidth();
		unsigned int GetHeight();

		std::string ToString() const;

		static EventType GetStaticType();
		virtual int GetCategoryFlags() const;
	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	class ORBIT_API WindowCloseEvent : public Event {
	public: 
		WindowCloseEvent();
		static EventType GetStaticType();
		virtual int GetCategoryFlags() const;
	};
}

