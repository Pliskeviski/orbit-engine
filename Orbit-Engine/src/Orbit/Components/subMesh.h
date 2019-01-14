#pragma once

#include "Orbit/Core.h"

//#include "Mesh.h"
#include "Transform.h"

namespace Orbit {
	class subMesh {
	public:
		subMesh(Transform* parent);
		~subMesh();
		
		bool m_Active;
		uint32_t m_VAO;
		uint32_t m_VBO;
		uint32_t m_EBO;
		
		std::vector<uint32_t> m_VBOs;
		Math::vec3* m_Vertices;

		uint32_t* m_Indices;

		uint32_t m_IndicesCount;
		uint32_t m_VerticesCount;

		Transform* m_Parent;
		Transform* m_Transform;
	};
}