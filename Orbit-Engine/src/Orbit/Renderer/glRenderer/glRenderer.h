#pragma once
#include "Orbit/Renderer/Renderer.h"

#include "glad/glad.h"

// Temp
#include "Shader/Shader.h"

namespace Orbit {
	class glRenderer : public Renderer {
	public:
		glRenderer();
		void Draw();
		uint32_t CreateBuffer(subMesh* submesh);
		int drawSubMesh(subMesh* submesh);
		void Destroy() {}
	private:
		GLuint genVBO(subMesh* submesh, GLsizeiptr size, GLint dataSize, const void* data, GLenum usage);
		Shader* m_Shader;
	};
}