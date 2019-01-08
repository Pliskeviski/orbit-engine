#include "obtpch.h"
#include "Object.h"

#include "../Components/Transform.h"

#include "glRenderer/glRenderer.h"

namespace Orbit {
	Object::Object(std::string name) : m_Name(name), m_Active(true) {
		
		// All objects MUST have a transform component
		std::shared_ptr<Component> t = std::make_shared<Transform>();
		this->addComponent(t);
	}

	void Object::addComponent(std::shared_ptr<Component> component) {
		this->m_Components.emplace_back(component);
	}

	void Object::setActive(bool active) {
		this->m_Active = active;
	}

	bool Object::isActive() {
		return this->m_Active;
	}

}
