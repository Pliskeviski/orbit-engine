#pragma once
#include "Orbit/Core.h"

enum ComponentType {
	TRANSFORM = 0,
	MESH
};

namespace Orbit {
	class ORBIT_API Component {
	public:
		Component(ComponentType type) : m_Type(type) {};
		virtual ~Component() {};
		ComponentType GetType() {
			return this->m_Type;
		}
	private:
		ComponentType m_Type;
	};
}