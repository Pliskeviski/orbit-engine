#include "obtpch.h"
#include "Renderer.h"
#include "glRenderer/glRenderer.h"

namespace Orbit {
	Renderer* Orbit::Renderer::Create(Render api) {
		if (api == OPENGL)
			return new glRenderer;
		return 0;
	}
}
