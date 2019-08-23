#pragma once
#include "Orbit/Core.h"

#include <string>

#include "Orbit/Components/Component.h"
#include "Orbit/Components/Transform.h"
#include "Orbit/Components/Camera.h"
#include "Orbit/Components/Mesh.h"

namespace Orbit {
	class ORBIT_API Object {
	public:
		Object(std::string name = "New Object");
		~Object();

		void addComponent(Component* component);

		template<typename T>
		T* getComponent();

		void setActive(bool active);
		bool isActive();

		void inline setPosition(float x, float y, float z) {
			Transform* t = this->getComponent<Transform>();

			t->setPosition(Orbit::Math::vec3(x, y, z));
		}
	private:
		bool m_Active;
		std::string m_Name;
		std::vector<Component*> m_Components;
	};

	template<typename T>
	inline T* Object::getComponent() {
		for (unsigned int i = 0; i < m_Components.size(); i++) {
			if (typeid(T) == typeid(*m_Components[i])) {
				return (T*)m_Components[i];
			}
		}
		return NULL;
	}

}