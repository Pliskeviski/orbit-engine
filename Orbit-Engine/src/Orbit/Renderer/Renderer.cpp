#include "obtpch.h"
#include "Renderer.h"
#include "glRenderer/glRenderer.h"

namespace Orbit {
	Renderer* Renderer::m_Renderer = 0;
	Camera* Renderer::m_ActiveCamera = 0;
	
	Renderer* Orbit::Renderer::Create(Render api) {
		if (api == OPENGL) {
			m_Renderer = new glRenderer;
			return m_Renderer;
		}
		return 0;
	}

	uint32_t Renderer::Update() {
		if (m_Renderer) {
			m_Renderer->Draw();
			return 1;
		}

		ORBIT_CORE_ERROR("NO RENDER FOUND!");
		return 0;
	}

	uint32_t Renderer::GenerateBuffers(subMesh* submesh) {
		if (m_Renderer) {
			return m_Renderer->CreateBuffer(submesh);
		}

		ORBIT_CORE_ERROR("NO RENDER FOUND!");
		return 0;
	}

	uint32_t Renderer::DrawSubMesh(subMesh* submesh, Camera* scene_camera) {
		if (m_Renderer) {
			return m_Renderer->drawSubMesh(submesh, scene_camera);
		}

		ORBIT_CORE_ERROR("NO RENDER FOUND!");
		return 0;
	}

	Camera* Renderer::getActiveCamera() {
		return Renderer::m_ActiveCamera;
	}
	void Renderer::setActiveCamera(Camera* camera) {
		Renderer::m_ActiveCamera = camera;
	}
	Renderer* Renderer::getRenderer() {
		return Renderer::m_Renderer;
	}
}
