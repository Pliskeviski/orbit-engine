#pragma once

#ifdef OBT_PLATFORM_WINDOWS

#include "Application.h"

extern Orbit::Application* Orbit::CreateApplication();

int main(int argc, char** argv) {
	printf("Orbit Engine!\n");
	auto app = Orbit::CreateApplication();
	app->Run();
	delete app;
}
#endif