#pragma once
#include "Orbit/Core.h"

#include "Component.h"
#include "Transform.h"

namespace Orbit {

	class ORBIT_API Camera : public Component {
	public:
		/*
			@ default constructor
			@ position at (0,0,0)
		*/
		Camera();
		~Camera() {};
		/*
			@ new camera at location "pos"
		*/
		Camera(Math::vec3 pos);

		/*
		@ new camera at location "pos"
		@ and field of view "fov"
		*/
		Camera(Math::vec3 pos, float fov);

		/*
			@ set the camera to a new position
		*/
		void setPosition(Math::vec3 position);

		/*
			@ set the camera position in X
		*/
		void setPositionX(float x);

		/*
			@ set the camera position in Y
		*/
		void setPositionY(float y);

		/*
			@ set the camera position in Z
		*/
		void setPositionZ(float z);

		/*
			@ set the camera's field of view
		*/
		void setFov(float fov);

		/*
			@ Add 'v' to the current X position
			@ position.x += v;
		*/
		void addPosX(float v);

		/*
			@ Add 'v' to the current Y position
			@ position.y += v;
		*/
		void addPosY(float v);

		/*
			@ Add 'v' to the current Z position
			@ position.z += v;
		*/
		void addPosZ(float v);

		/*
			@ Add 'v' to the current Yaw value
			@ yaw += v;
		*/
		void addYaw(double v);

		/*
			@ Add 'v' to the current Pitch value
			@ pitch += v;
		*/
		void addPitch(double v);

		/*
			@ return the camera position
		*/
		Math::vec3 getPosition();

		/*
			@ get the view matrix
			@ glm::lookAt(this->c_pos, this->c_pos + this->c_Front, this->c_Up);
		*/
		Math::mat4 getViewMatrix();

		/*
			@ get the camera's field of view
		*/
		float getFov();

		/*
			@ return yaw value
		*/
		float getYaw();

		/*
			@ return pitch value
		*/
		float getPitch();

		/*
			@ set the yaw value
		*/
		void setYaw(float yaw);

		/*
			@ set the pitch value
		*/
		void setPitch(float pitch);

		// Some pre-defined functions
		void Forward(float v);
		void Backwards(float v);
		void Right(float v);
		void Left(float v);


		float m_Width;
		float m_Height;

		//bool firstMouse = true;
		//void OnEvent(Orbit::Event& event) override {
		//	if (event.IsInCategory(EventCategoryKeyboard)) {
		//		KeyPressedEvent* e = static_cast<KeyPressedEvent*>(&event);
		//		event.e_Handled = true;

		//		if (e->GetKeyCode() == 'W')
		//			this->Forward(.1f);
		//		if (e->GetKeyCode() == 'S')
		//			this->Backwards(.1f);
		//		if (e->GetKeyCode() == 'D')
		//			this->Right(.1f);
		//		if (e->GetKeyCode() == 'A')
		//			this->Left(.1f);
		//		if (e->GetKeyCode() == 'E')
		//			this->addPosY(.1f);
		//		if (e->GetKeyCode() == 'Q')
		//			this->addPosY(-.1f);
		//		if (e->GetKeyCode() == 265) // up arrow
		//			this->addPitch(.7f);
		//		if (e->GetKeyCode() == 264) // down
		//			this->addPitch(-.7f);
		//		if (e->GetKeyCode() == 263) // left
		//			this->addYaw(-.7f);
		//		if (e->GetKeyCode() == 262) // right
		//			this->addYaw(.7f);
		//	}
		//	else if (event.IsInCategory(EventCategoryMouse)) {
		//		MouseMovedEvent* e = static_cast<MouseMovedEvent*>(&event);
		//		event.e_Handled = true;

		//		{ // Camera scripting
		//			double cursorX;
		//			double cursorY;
		//				
		//			//Window* window = Application::getApplication()->getWindow().get();
		//			uint32_t screenWidth = 1280;
		//			uint32_t screenHeight = 720;
		//			if (firstMouse == true) {

		//				cursorX = (screenWidth / 2);
		//				cursorY = (screenHeight / 2);
		//				firstMouse = false;
		//			}
		//			else {
		//				cursorX = e->GetX();
		//				cursorY = e->GetY();
		//			}
		//			double mouseX = cursorX - (screenWidth / 2);
		//			double mouseY = (screenHeight / 2) - cursorY;

		//			mouseX *= 0.05f;
		//			mouseY *= 0.05f;

		//			this->addYaw(mouseX);
		//			this->addPitch(mouseY);
		//		}
		//	}
		//}

	private:
		void Update();

		Math::vec3 m_Front;
		Math::vec3 m_Up;
		Math::vec3 m_Right;

		double m_Yaw;
		double m_Pitch;
		float  m_Fov;

		Transform* m_Transform;
	};

}