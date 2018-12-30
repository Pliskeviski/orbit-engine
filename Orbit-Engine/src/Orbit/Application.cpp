#include "obtpch.h"
#include "Application.h"
#include "Events/KeyEvents/KeyEvents.h"

namespace Orbit {

	Application::Application() {
		this->m_Window = std::unique_ptr<Window>(Window::Create());
		this->m_Running = true;
	}

	Application::~Application() {
	}

	void Application::Run() {
		while (this->m_Running) {
			this->m_Window->OnUpdate();
		}
	}


//#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
}
