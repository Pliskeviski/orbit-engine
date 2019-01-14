#include "obtpch.h"

#include "Orbit/Application/Application.h"
#include "Orbit/Events/EventDispatcher.h"

#include "Orbit/Input/Input.h"

namespace Orbit {
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::m_Application = 0;

	Application::Application() {
		this->m_Window = std::unique_ptr<Window>(Window::Create());
		this->m_Running = true;
		this->m_Window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
		
		this->PushLayer(new Input);

		this->m_Renderer = std::unique_ptr<Renderer>(Renderer::Create());

		m_Application = this;
	}

	Application::~Application() {
	}

	void Application::Run() {
		while (this->m_Running) {
			Renderer::Update();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();


			this->Update();

			this->m_Window->OnUpdate();
		}
		this->Destroy();
	}

	bool Application::onWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

	void Application::onEvent(Event& e) {
		EventDispatcher disp(e);
		disp.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));

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
	std::shared_ptr<Window> Application::getWindow() {
		return this->m_Window;
	}

	Application* Application::getApplication() {
		return m_Application;
	}
}
