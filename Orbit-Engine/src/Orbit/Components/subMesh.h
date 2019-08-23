#pragma once

#include "Orbit/Core.h"

//#include "Mesh.h"
#include "Transform.h"

namespace Orbit {
	class subMesh {
	public:
		subMesh(Transform* parent);
		~subMesh();
		
		void Generate();
		
		bool m_Active;
		
		std::string m_Name;

		Math::vec3* m_Vertices;
		Math::vec3* m_Normals;
		Math::vec2* m_UVs;

		uint32_t m_VAO;
		uint32_t m_VBO;
		uint32_t m_EBO;
		
		std::vector<uint32_t> m_VBOs;

		bool m_HasNormals;
		bool m_HasUVs;

		uint32_t* m_Indices;
		uint32_t  m_IndicesCount;
		uint32_t  m_VerticesCount;

		Transform* m_Parent;
		Transform* m_Transform;
	};
}