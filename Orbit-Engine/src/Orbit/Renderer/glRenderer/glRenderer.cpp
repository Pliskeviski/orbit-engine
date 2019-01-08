#include "obtpch.h"
#include "glRenderer.h"

#include "glad/glad.h"

namespace Orbit {
	glRenderer::glRenderer() {
		const GLubyte* vendor = glGetString(GL_VENDOR);
		const GLubyte* version = glGetString(GL_VERSION);
		const GLubyte* renderer = glGetString(GL_RENDERER);
		ORBIT_CORE_INFO("OpenGL {0} - {1} {2}", version, renderer, vendor);
	}
}
