#include "obtpch.h"

#include "Application.h"

#include "Events/EventDispatcher.h"

namespace Orbit {
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application() {
		this->m_Window = std::unique_ptr<Window>(Window::Create());
		this->m_Running = true;
		this->m_Window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
	}

	Application::~Application() {
	}

	void Application::Run() {
		while (this->m_Running) {

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			this->m_Window->OnUpdate();
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

	void Application::onEvent(Event& e) {
		EventDispatcher disp(e);
		disp.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));

		ORBIT_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) { // Goes backwards
			(*--it)->OnEvent(e);
			if (e.e_Handled)
				break;
		}
	}
	

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
	}
}
