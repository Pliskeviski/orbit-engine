#pragma once

#include "Orbit/Core.h"
#include "Layer.h"

#include <vector>

namespace Orbit {
	class ORBIT_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer (Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopOverlay (Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};

}