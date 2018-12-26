#pragma once

#ifdef OBT_PLATFORM_WINDOWS

#include "Application.h"

extern Orbit::Application* Orbit::CreateApplication();

int main(int argc, char** argv) {
	Orbit::Log::Init();
	Orbit::Log::GetCoreLogger()->info("Orbit Engine!");
	ORBIT_CORE_ERROR("Orbit Engine!");
	auto app = Orbit::CreateApplication();
	app->Run();
	delete app;
}
#endif