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
		int drawSubMesh(subMesh* submesh, Camera* scene_camera);
		void Destroy() {}
		static uint32_t GLLoadImage(std::string path);
	private:
		GLuint genVBO(subMesh* submesh, GLsizeiptr size, GLint dataSize, const void* data, GLenum usage);
		Shader* m_Shader;
	};
}