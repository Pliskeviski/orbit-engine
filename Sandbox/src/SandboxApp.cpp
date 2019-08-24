#include <Orbit.h>
#include "Layer/TestLayer.h"

float t = 0;
namespace defaults {
	const std::string assets_dir = __FILE__ "\\..\\..\\assets\\";
}

class Sandbox : public Orbit::Application {
public:
	Sandbox() {
		PushLayer(new TestLayer);
		
		this->m_MainCamera = new Orbit::Object("Camera");
		this->m_MainCamera->addComponent(new Orbit::Camera(Orbit::Math::vec3(0.f, 0.f, -1.0f)));

		this->obj = new Orbit::Object("Test Object");

		Orbit::Mesh* mesh = new Orbit::Mesh(defaults::assets_dir + "Biplano\\biplane_complete.obt");
		obj->addComponent(mesh);

		mesh->getSubMeshes()[0]->addTexture(new Orbit::Texture(defaults::assets_dir + "Biplano\\prop_biplane_last.jpg"));
		mesh->getSubMeshes()[1]->addTexture(new Orbit::Texture(defaults::assets_dir + "Biplano\\biplano_last.jpg"));
		mesh->getSubMeshes()[2]->addTexture(new Orbit::Texture(defaults::assets_dir + "Biplano\\wheels_biplane_last.jpg"));
		mesh->getSubMeshes()[3]->addTexture(new Orbit::Texture(defaults::assets_dir + "Biplano\\flaps_biplane_last.jpg"));
		mesh->getSubMeshes()[4]->addTexture(new Orbit::Texture(defaults::assets_dir + "Biplano\\prop_biplane_last.jpg"));

		Orbit::Mesh* test = obj->getComponent<Orbit::Mesh>();
		Orbit::Transform* test1 = obj->getComponent<Orbit::Transform>();
		test1->setPositionX(1.f);
		test1->setScale(10.f);

		this->m_FirstMouse = true;
	}

	Orbit::Math::vec2 lastMousePos;

	void Update() {
		this->obj->getComponent<Orbit::Mesh>()->Draw();

		if (Orbit::Input::isMouseButtonDown(1)) {

			// Camera scripting || Temp
			if (Orbit::Input::isKeyDown('W'))
				this->m_MainCamera->getComponent<Orbit::Camera>()->Forward(.1f);
			if (Orbit::Input::isKeyDown('S'))
				this->m_MainCamera->getComponent<Orbit::Camera>()->Backwards(.1f);
			if (Orbit::Input::isKeyDown('D'))
				this->m_MainCamera->getComponent<Orbit::Camera>()->Right(.1f);
			if (Orbit::Input::isKeyDown('A'))
				this->m_MainCamera->getComponent<Orbit::Camera>()->Left(.1f);
			if (Orbit::Input::isKeyDown('E'))
				this->m_MainCamera->getComponent<Orbit::Camera>()->addPosY(.1f);
			if (Orbit::Input::isKeyDown('Q'))
				this->m_MainCamera->getComponent<Orbit::Camera>()->addPosY(-.1f);
			if (Orbit::Input::isKeyDown(265)) // up arrow
				this->m_MainCamera->getComponent<Orbit::Camera>()->addPitch(.7f);
			if (Orbit::Input::isKeyDown(264)) // down
				this->m_MainCamera->getComponent<Orbit::Camera>()->addPitch(-.7f);
			if (Orbit::Input::isKeyDown(263)) // left
				this->m_MainCamera->getComponent<Orbit::Camera>()->addYaw(-.7f);
			if (Orbit::Input::isKeyDown(262)) // right
				this->m_MainCamera->getComponent<Orbit::Camera>()->addYaw(.7f);

			Orbit::Math::vec2 MousePos = Orbit::Input::getMousePosition();
			if (lastMousePos != MousePos) {

				double cursorX;
				double cursorY;

				Orbit::Window* window = Application::getApplication()->getWindow().get();
				window->setCursorVisible(false);
				window->forceCursorCenter(true);

				uint32_t screenWidth = window->getWidth();
				uint32_t screenHeight = window->getHeight();

				if (this->m_FirstMouse == true) {
					cursorX = (screenWidth / 2);
					cursorY = (screenHeight / 2);
					this->m_FirstMouse = false;
				}
				else {
					lastMousePos = MousePos;
					cursorX = MousePos.x;
					cursorY = MousePos.y;
				}

				double mouseX = cursorX - (screenWidth / 2);
				double mouseY = (screenHeight / 2) - cursorY;

				mouseX *= 0.05f;
				mouseY *= 0.05f;

				Orbit::Renderer::getActiveCamera()->addYaw(mouseX);
				Orbit::Renderer::getActiveCamera()->addPitch(mouseY);
			}
		}
		else {
			Orbit::Window* window = Application::getApplication()->getWindow().get();
			window->setCursorVisible(true);
			window->forceCursorCenter(false);
			this->m_FirstMouse = true;
		}

		//ORBIT_CORE_WARN("Camera: x: {0} y: {1} z: {2}", this->m_MainCamera->getComponent<Orbit::Camera>()->getPosition().x, this->m_MainCamera->getComponent<Orbit::Camera>()->getPosition().y, this->m_MainCamera->getComponent<Orbit::Camera>()->getPosition().z);
		//ORBIT_CORE_WARN("Camera: Pitch {0}, Yaw {1}", this->m_MainCamera->getComponent<Orbit::Camera>()->getPitch(), this->m_MainCamera->getComponent<Orbit::Camera>()->getYaw());
	}

	~Sandbox() {}
private:
	Orbit::Object* obj;
	Orbit::Object* m_MainCamera;
	bool m_FirstMouse;
};

Orbit::Application* Orbit::CreateApplication() {
	return new Sandbox();
}