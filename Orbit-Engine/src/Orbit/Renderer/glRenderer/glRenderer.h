#pragma once
#include "../Renderer.h"

namespace Orbit {
	class glRenderer : public Renderer {
	public:
		glRenderer();
		void Draw() {}
		void Destroy() {}
	};
}