#include <Orbit.h>

class Sandbox : public Orbit::Application {
public: 
	Sandbox() {

	}

	~Sandbox() {

	}
};

Orbit::Application* Orbit::CreateApplication() {
	return new Sandbox();
}