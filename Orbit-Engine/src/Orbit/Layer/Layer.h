#pragma once
#include "Orbit/TimeStep.h"
#include "Orbit/Core.h"
#include "Orbit/Events/Event.h"

namespace Orbit {

	class ORBIT_API Layer {
	public:
		Layer(const std::string& name = "Layer") : m_DebugName(name) {};
		virtual ~Layer() {};

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Orbit::Timestep ts) {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}