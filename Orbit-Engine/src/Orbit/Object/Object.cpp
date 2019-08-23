#include "obtpch.h"
#include "Object.h"

#include "Orbit/Components/Transform.h"

namespace Orbit {
	Object::Object(std::string name) : m_Name(name), m_Active(true) {
		
		// All objects MUST have a transform component
		Component* t = new Transform();
		this->addComponent(t);
	}

	Object::~Object() {
		for (Component* c : this->m_Components) {
			c->~Component();
			delete c;
			this->m_Components.erase(this->m_Components.begin());
		}
	}
	 
	void Object::addComponent(Component* component) {
		component->setParent(this->getComponent<Transform>());
		this->m_Components.push_back(component);
	}

	void Object::setActive(bool active) {
		this->m_Active = active;
	}

	bool Object::isActive() {
		return this->m_Active;
	}

}
