#pragma once

#include "Orbit/Core.h"
#include "Orbit/Events/ApplicationEvents/WindowEvent.h"
#include "Orbit/Layer/LayerStack.h"
#include "Orbit/Window.h"
#include "Orbit/Renderer/Renderer.h"
#include "Orbit/Object/Object.h"

namespace Orbit {
	class ORBIT_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
		virtual void Update() {};
		virtual void Destroy() {};

		void onEvent(Event& e);

		void PushLayer  (Layer* layer);
		void PushOverlay(Layer* layer);
		
		std::shared_ptr<Window> getWindow();

		static Application* getApplication();
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::shared_ptr<Window> m_Window;
		std::shared_ptr<Renderer> m_Renderer;
		bool m_Running;
		LayerStack m_LayerStack;
		static Application* m_Application;
	};

	Application* CreateApplication();
}

