#include "obtpch.h"
#include "Object.h"

#include "Orbit/Components/Transform.h"
#include "Orbit/Application/Application.h"
namespace Orbit {
	Object::Object(std::string name) : m_Name(name), m_Active(true) {
		// All objects MUST have a transform component
		Application::getApplication()->PushLayer(this);
		this->m_DebugName = name;
		Component* t = new Transform();
		this->addComponent(t);
		this->m_UpdateCallbackFn = NULL;
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

	void Object::OnUpdate(Orbit::Timestep ts) {
		if (!this->isActive()) return;
		
		//ORBIT_INFO("{0}->Update", this->m_Name);
		for (Component* c : this->m_Components)
			c->OnUpdate(ts);

		if(this->m_UpdateCallbackFn)
			this->m_UpdateCallbackFn(ts, this);
	}

	void Object::setUpdateFn(const std::function<void(float, Orbit::Object*)>& callback) {
		this->m_UpdateCallbackFn = callback;
	}

}
