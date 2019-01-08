#pragma once

#include "Core.h"
#include "Events/ApplicationEvents/WindowEvent.h"
#include "Layer/LayerStack.h"
#include "Window.h"
#include "Renderer/Renderer.h"
#include "Renderer/Object.h"

namespace Orbit {
	class ORBIT_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();

		void onEvent(Event& e);

		void PushLayer  (Layer* layer);
		void PushOverlay(Layer* layer);
		
		std::shared_ptr<Window> getWindow();
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::shared_ptr<Window> m_Window;
		std::shared_ptr<Renderer> m_Renderer;
		bool m_Running;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}

