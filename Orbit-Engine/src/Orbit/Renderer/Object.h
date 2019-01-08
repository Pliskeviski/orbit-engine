#pragma once
#include "Orbit/Core.h"

#include <string>

#include "Orbit/Components/Component.h"
#include "Orbit/Components/Transform.h"
#include "Orbit/Components/Mesh.h"


namespace Orbit {
	class Renderer;
	
	class ORBIT_API Object {
	public:
		Object(std::string name = "New Object");

		void addComponent(std::shared_ptr<Component> component);

		template<typename T>
		std::shared_ptr<T> getComponent();

		void setActive(bool active);
		bool isActive();
	private:
		bool m_Active;
		std::string m_Name;
		std::vector<std::shared_ptr<Component>> m_Components;
	};

	template<typename T>
	inline std::shared_ptr<T> Object::getComponent() {
		for (unsigned int i = 0; i < m_Components.size(); i++) {
			if (typeid(T) == typeid(*m_Components[i].get())) {
				T* ptr_base = (T*)m_Components[i].get();

				std::shared_ptr<T> ptr(ptr_base);
				return ptr;
			}
		}

		return NULL;
	}

}