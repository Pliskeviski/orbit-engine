#include <Orbit.h>
#include "Layer/TestLayer.h"

class Sandbox : public Orbit::Application {
public:
	Sandbox() {
		PushLayer(new TestLayer);

		this->obj = new Orbit::Object("Test Object");

		Orbit::Mesh* mesh = new Orbit::Mesh("nopath");
		obj->addComponent(mesh);

		Orbit::Mesh* test = obj->getComponent<Orbit::Mesh>();
		Orbit::Transform* test1 = obj->getComponent<Orbit::Transform>();
	}

	void Update() {
		this->obj->getComponent<Orbit::Mesh>()->Draw();
	}

	~Sandbox() {
	}
private:
	Orbit::Object* obj;
};

Orbit::Application* Orbit::CreateApplication() {
	return new Sandbox();
}