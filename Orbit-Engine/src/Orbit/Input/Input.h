#pragma once
#include "Orbit/Core.h"

#include "Orbit/Events/Event.h"
#include "Orbit/Events/KeyEvents/KeyEvents.h"
#include "Orbit/Events/MouseEvents/MouseEvent.h"

#include "InputLayer.h"

namespace Orbit {
	
	enum OBT_KEY_STATE {
		OBT_KEY_RELEASED = 0,
		OBT_KEY_PRESSED
	};

	class ORBIT_API Input : public InputLayer {
	public:
		void OnAttach();
		void OnUpdate();
		void OnEvent(Orbit::Event& event);

		static bool isKeyDown(uint32_t key);
		static bool isMouseButtonDown(uint32_t mouse_button);
		
		static OBT_KEY_STATE GetKeyState(uint32_t key);

		static Math::vec2 getMousePosition();
		static Math::vec2 getMouseScroll();
		static float getMousePositionX();
		static float getMousePositionY();
	private:
		static Math::vec2 m_MousePosition;
		static Math::vec2 m_MouseScroll;
		static std::unordered_map<int, OBT_KEY_STATE> m_KeyMap;
		static std::unordered_map<int, OBT_KEY_STATE> m_MouseButtonMap;
	};
}