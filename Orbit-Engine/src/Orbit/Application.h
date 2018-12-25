#pragma once

#include "Core.h"

namespace Orbit {
	class ORBIT_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}

