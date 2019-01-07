#pragma once

#include "../BaseRenderer.h"

namespace Orbit {
	class glRenderer : BaseRenderer {
	public:
		glRenderer(std::shared_ptr<Window> window) : BaseRenderer(window) {};
		void Init() {}
		void Draw() {}
		void Destroy() {}
		void CreateMesh(std::shared_ptr<Mesh> mesh) {}
	};
}