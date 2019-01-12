#pragma once
#include "Orbit/Core.h"

#include "Orbit/Components/subMesh.h"

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
		virtual int drawSubMesh(subMesh* submesh) = 0;
		virtual void Destroy() = 0;
		
		static Renderer* Create(Render api = OPENGL);

		static uint32_t Update();
		static uint32_t GenerateBuffers(subMesh* submesh);
		static uint32_t DrawSubMesh(subMesh* submesh);
	private:
		static Renderer* m_Renderer;
	};
}