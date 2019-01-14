#include "obtpch.h"
#include "Input.h"

#include <iterator>

namespace Orbit {

	Math::vec2 Input::m_MouseScroll   = Math::vec2();
	Math::vec2 Input::m_MousePosition = Math::vec2();
	std::unordered_map<int, OBT_KEY_STATE> Input::m_KeyMap = std::unordered_map<int, OBT_KEY_STATE>();
	std::unordered_map<int, OBT_KEY_STATE> Input::m_MouseButtonMap = std::unordered_map<int, OBT_KEY_STATE>();

	void Input::OnAttach() {
	}

	void Input::OnUpdate() {
	}

	void Input::OnEvent(Orbit::Event& event) {

		// Check for keyboard events
		switch (event.GetEventType()) {
			case EventType::KeyPressed:
			{
				KeyPressedEvent* e = static_cast<KeyPressedEvent*>(&event);
				event.e_Handled = true;
				Input::m_KeyMap[e->GetKeyCode()] = OBT_KEY_PRESSED;
				return;
			}
			case EventType::KeyRelease:
			{
				KeyPressedEvent* e = static_cast<KeyPressedEvent*>(&event);
				event.e_Handled = true;
				Input::m_KeyMap[e->GetKeyCode()] = OBT_KEY_RELEASED;
				return;
			}
		}

		// Check for mouse events
		switch (event.GetEventType()) {
		case EventType::MouseButtonPressed:
			{
				MouseButtonPressedEvent* e = static_cast<MouseButtonPressedEvent*>(&event);
				event.e_Handled = true;
				Input::m_MouseButtonMap[e->GetMouseButton()] = OBT_KEY_PRESSED;
				return;
			}
		case EventType::MouseButtonReleased:
			{
				MouseButtonPressedEvent* e = static_cast<MouseButtonPressedEvent*>(&event);
				event.e_Handled = true;
				Input::m_MouseButtonMap[e->GetMouseButton()] = OBT_KEY_RELEASED;
				return;
			}
		case EventType::MouseMoved:
			{
				MouseMovedEvent* e = static_cast<MouseMovedEvent*>(&event);
				event.e_Handled = true;
				Input::m_MousePosition.x = e->GetX();
				Input::m_MousePosition.y = e->GetY();
				break;
			}
		case EventType::MouseScrolled:
			{
				event.e_Handled = true;
				MouseScrolledEvent* e = static_cast<MouseScrolledEvent*>(&event);
				Input::m_MouseScroll.x = e->GetXOffset();
				Input::m_MouseScroll.y = e->GetYOffset();
				break;
			}
		}
	}

	bool Input::isKeyDown(uint32_t key) {
		return Input::m_KeyMap[key];
	}

	bool Input::isMouseButtonDown(uint32_t mouse_button) {
		return Input::m_MouseButtonMap[mouse_button];
	}

	OBT_KEY_STATE Input::GetKeyState(uint32_t key) {
		return Input::m_KeyMap[key];
	}

	Math::vec2 Input::getMousePosition() {
		return Input::m_MousePosition;
	}

	Math::vec2 Input::getMouseScroll() {
		return Input::m_MouseScroll;
	}

	float Input::getMousePositionX() {
		return Input::m_MousePosition.x;
	}

	float Input::getMousePositionY() {
		return Input::m_MousePosition.y;
	}
}
