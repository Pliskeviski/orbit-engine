#pragma once

#include "Orbit/Core.h"

//#include "Mesh.h"
#include "Transform.h"

namespace Orbit {
	class subMesh {
	public:
		subMesh();
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

		//Mesh* m_Parent;
		Transform* m_Transform;
	};
}