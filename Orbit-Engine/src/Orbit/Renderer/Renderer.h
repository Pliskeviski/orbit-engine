#pragma once
#include "Orbit/Core.h"

#include "Orbit/Components/subMesh.h"
#include "Orbit/Components/Camera.h"

enum Render {
	OPENGL = 0
};

namespace Orbit {
	class ORBIT_API Renderer {
	public:
		Renderer() {}
		virtual ~Renderer() {};

		virtual void Draw() = 0;
		virtual uint32_t CreateBuffer(subMesh* submesh) = 0;
		virtual int drawSubMesh(subMesh* submesh, Camera* scene_camera) = 0;
		virtual void Destroy() = 0;
		
		static Renderer* Create(Render api = OPENGL);

		static uint32_t Update();
		static uint32_t GenerateBuffers(subMesh* submesh);
		static uint32_t DrawSubMesh(subMesh* submesh, Camera* scene_camera);

		static Camera* getActiveCamera();
		static void setActiveCamera(Camera* camera);
		virtual uint32_t LoadTextureImage(std::string path) = 0;
		static Renderer* getRenderer();
	private:
		static Renderer* m_Renderer;
		static Camera* m_ActiveCamera;
	};
}