#pragma once
#include "obtpch.h"

#include "Component.h"

class Component;
namespace Orbit {
	class Transform : public Component {
	public:
		/*
			@ new transform component
		*/
		Transform(Math::vec3 position = Math::vec3(0, 0, 0), Math::vec3 rotation = Math::vec3(0, 0, 0), Math::vec3 scale = Math::vec3(1.f, 1.f, 1.f));

		/*
			@ set transform position
		*/
		void setPosition(Math::vec3 position);

		/*
			@ set tranform X position
		*/
		void setPositionX(float x);

		/*
			@ set transform Y position
		*/
		void setPositionY(float y);

		/*
			@ set transform Z position
		*/
		void setPositionZ(float z);

		/*
			@ set transform rotation
		*/
		void setRotation(Math::vec3 rotation);

		/*
			@ set transform X rotation
		*/
		void setRotationX(float x);

		/*
			@ set transform Y rotation
		*/
		void setRotationY(float y);

		/*
			@ set transform Z rotation
		*/
		void setRotationZ(float z);

		/*
			@ set transform parent
		*/
		//void setParent(std::shared_ptr<Transform> parent);

		/*
			@ get transform global location
		*/
		Math::vec3 getPosition();

		/*
			@ get transform global location in X
		*/
		float getPositionX();

		/*
			@ get transform global location in Y
		*/
		float getPositionY();

		/*
			@ get transform global location in Z
		*/
		float getPositionZ();

		/*
			@ get transform rotation
		*/
		Math::vec3 getRotation();

		/*
			@ get transform rotation in X
		*/
		float getRotationX();

		/*
			@ get transform rotation in Y
		*/
		float getRotationY();

		/*
			@ get transform rotation in Z
		*/
		float getRotationZ();

		/*
			@ return transform parent
			@ return NULL if none
		*/
		//std::shared_ptr<Transform> getParent();

		/*
			@ return transform scale
		*/
		Math::vec3 getScale();

		/*
			@ define transform scale (x, y, z)
		*/
		void setScale(Math::vec3 scale);
		/*
		@ define transform scale (same for x, y, z)
		*/
		void setScale(float scale);
		~Transform();
	private:
		Math::vec3 m_Position;
		Math::vec3 m_Rotation;
		Math::vec3 m_Scale;
	 	Transform* m_Parent;
	};
}