#include "obtpch.h"
#include "Application.h"
#include "Events/KeyEvents/KeyEvents.h"

namespace Orbit {

	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run() {
		KeyPressedEvent e(20, 1);
		std::cout << e.ToString();
		while (true);
	}


//#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
}
