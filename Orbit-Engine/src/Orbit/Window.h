#pragma once

#include "obtpch.h"

#include "Orbit/Core.h"

#include "Events/Event.h"

namespace Orbit {
	struct WindowConfig {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowConfig(const std::string& title = "Orbit Engine",
			unsigned int width = 1280, unsigned int height = 720)
			: title(title), width(width), height(height) { }
	};

	class ORBIT_API Window {
	public:

		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEvent(const Event& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* Create(const WindowConfig& props = WindowConfig());
	};
}