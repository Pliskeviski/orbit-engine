#pragma once
#include "Orbit/Core.h"

namespace Orbit {
	class Component {
	public:
		Component() {};
		virtual void setParent(Component* parent) {};
		virtual ~Component() {};
	};
}