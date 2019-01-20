#include "obtpch.h"
#include "winWindow.h"

#include <glad/glad.h>

#include "Orbit/Events/KeyEvents/KeyEvents.h"
#include "Orbit/Events/MouseEvents/MouseEvent.h"
#include "Orbit/Events/ApplicationEvents/WindowEvent.h"

namespace Orbit {
	
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		ORBIT_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Window* Window::Create(const WindowConfig& config) {
		return new winWindow(config);
	}

	winWindow::winWindow(const WindowConfig& config) {
		Init(config);
	}

	winWindow::~winWindow() {
		this->Destroy();
	}

	void winWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);

		if (this->m_Data.cursor_center)
			glfwSetCursorPos(this->m_Window, this->getWidth() / 2, this->getHeight() / 2);
	}

	unsigned int winWindow::getWidth() const {
		return this->m_Data.width;
	}

	unsigned int winWindow::getHeight() const {
		return this->m_Data.height;
	}

	void winWindow::setEventCallback(const EventCallbackFn& callback) {
		this->m_Data.eventCallback = callback;
	}

	bool winWindow::isVSync() const {
		return this->m_Data.vsync;
	}

	void winWindow::Init(const WindowConfig& config) {
		this->m_Data.title = config.title;
		this->m_Data.width = config.width;
		this->m_Data.height = config.height;

		ORBIT_CORE_INFO("Creating Window \"{0}\" ({1}, {2})", config.title, config.width, config.height);
	
		if (!s_GLFWInitialized) {
			int success = glfwInit();
			OBT_CORE_ASSERT(success, "Could not intialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		this->m_Window = glfwCreateWindow((int)config.width, (int)config.height, m_Data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(this->m_Window);
		glfwSetWindowUserPointer(this->m_Window, &m_Data);
		setVSync(true);

		// Glad
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		OBT_CORE_ASSERT(status, "Failed to initialize Glad");

		// GLFW callbacks
		glfwSetWindowSizeCallback(this->m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.eventCallback(event);
		});

		glfwSetWindowCloseCallback(this->m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.eventCallback(event);
		});

		glfwSetKeyCallback(this->m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					KeyPressedEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE: {
					KeyReleasedEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT: {
					KeyPressedEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(this->m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE: {
					MouseButtonReleasedEvent event(button);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(this->m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(this->m_Window, [](GLFWwindow* window, double xPos, double yPos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.eventCallback(event);
		});
	}

	void winWindow::setCursorVisible(bool visible) {
		if (visible)
			glfwSetInputMode(this->m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		else
			glfwSetInputMode(this->m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void winWindow::forceCursorCenter(bool center) {
		this->m_Data.cursor_center = center;
	}

	void winWindow::Destroy() {
		glfwDestroyWindow(this->m_Window);
	}

	void winWindow::setVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		this->m_Data.vsync = enabled;
	}
}
