#pragma once

#include "Orbit/Window.h"

#include <GLFW/glfw3.h>

namespace Orbit {
	class winWindow : public Window {
	public:
		winWindow(const WindowConfig& config);
		virtual ~winWindow();

		void OnUpdate() override;
		
		unsigned int getWidth() const override;
		unsigned int getHeight() const override;

		void setEventCallback(const EventCallbackFn& callback) override;

		void setVSync(bool enabled) override;
		bool isVSync() const override;
		void setCursorVisible(bool value);
		void forceCursorCenter(bool value);
	private:
		virtual void Init(const WindowConfig& config);
		virtual void Destroy();
		
	// GLFW
	private:
		GLFWwindow* m_Window;

		struct WindowData {
			std::string title;
			unsigned int width;
			unsigned int height;
			bool cursor_center;
			bool vsync;

			EventCallbackFn eventCallback;
		};

		WindowData m_Data;
	};
}