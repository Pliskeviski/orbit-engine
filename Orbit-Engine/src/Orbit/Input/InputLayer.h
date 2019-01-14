#pragma once

#include "Orbit/Core.h"

#include "Orbit/Layer/Layer.h"

namespace Orbit {
	class ORBIT_API InputLayer : public Layer {
	public:
		InputLayer() : Layer("Input Layer") { };

		virtual void OnUpdate() = 0;

		virtual void OnEvent(Orbit::Event& event) = 0;
	};
}