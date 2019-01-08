#include <Orbit.h>
#include "Layer/TestLayer.h"

class Sandbox : public Orbit::Application {
public: 
	Sandbox() {
		PushLayer(new TestLayer);

		Object obj(new Orbit::Object());
		Mesh mesh(new Orbit::Mesh("nopath"));
		obj->addComponent(mesh);

		Mesh test = obj->getComponent<Orbit::Mesh>();
		Transform test1 = obj->getComponent<Orbit::Transform>();
	}

	~Sandbox() {

	}
};

Orbit::Application* Orbit::CreateApplication() {
	return new Sandbox();
}