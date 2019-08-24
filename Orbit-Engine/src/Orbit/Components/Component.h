#pragma once
#include "Orbit/Core.h"
#include "Orbit/TimeStep.h"
namespace Orbit {
	class Component {
	public:
		Component() {};
		virtual void setParent(Component* parent) {};
		virtual void OnUpdate(Orbit::Timestep ts) {};
		virtual ~Component() {};
	};
}