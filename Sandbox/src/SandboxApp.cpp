#include <Orbit.h>
#include "Layer/TestLayer.h"
class Sandbox : public Orbit::Application {
public: 
	Sandbox() {
		PushLayer(new TestLayer);
	}

	~Sandbox() {

	}
};

Orbit::Application* Orbit::CreateApplication() {
	return new Sandbox();
}