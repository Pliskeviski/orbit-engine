#pragma once
#include "obtpch.h"
#include "Orbit.h"

#include "Orbit/Window.h"
#include "Orbit/Components/Mesh.h"

namespace Orbit {
	class ORBIT_API BaseRenderer {
	public:
		BaseRenderer(std::shared_ptr<Window> window) : m_Window(window) {};
		virtual void Init() = 0;
		virtual void Draw() = 0;
		virtual void Destroy() = 0;

		virtual void CreateMesh(std::shared_ptr<Mesh> mesh) = 0;
	private:
		std::shared_ptr<Window> m_Window;
		std::vector<std::shared_ptr<Mesh>> m_Mesh;
		
		// Camera camera;
	};
}