#pragma once

#include "Core.h"
#include "Events/ApplicationEvents/WindowEvent.h"
#include "Layer/LayerStack.h"
#include "Window.h"

namespace Orbit {
	class ORBIT_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();

		void onEvent(Event& e);

		void PushLayer  (Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}

