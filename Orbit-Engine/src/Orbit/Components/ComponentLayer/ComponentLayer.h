#pragma once

#include "Orbit/Core.h"
#include "Orbit/Layer/Layer.h"

#include "Orbit/Events/Event.h"
#include "Orbit/Events/KeyEvents/KeyEvents.h"
#include "Orbit/Events/MouseEvents/MouseEvent.h"
#include "Orbit/Events/EventDispatcher.h"

namespace Orbit {
	class ORBIT_API ComponentLayer : public Layer {
	public:
		ComponentLayer() : Layer("Component Layer") {
		};

		virtual void OnUpdate() = 0;

		virtual void OnEvent(Orbit::Event& event) = 0;
	};
}
