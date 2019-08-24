#include "obtpch.h"
#include "subMesh.h"

#include "Orbit/Renderer/Renderer.h"

namespace Orbit {
	subMesh::subMesh(Transform* parent) : m_Active(true), m_Parent(parent) {
		this->m_Transform = new Transform();

		// Mock values
		//this->m_Vertices = new Math::vec3[4];
		//this->m_Vertices[0] = Math::vec3( 0.5f,  0.5f, 0.0f);
		//this->m_Vertices[1] = Math::vec3( 0.5f, -0.5f, 0.0f);
		//this->m_Vertices[2] = Math::vec3(-0.5f, -0.5f, 0.0f);
		//this->m_Vertices[3] = Math::vec3(-0.5f,  0.5f, 0.0f);
		//this->m_VerticesCount = 4;
		//
		//this->m_Indices = new uint32_t[6];
		//
		//this->m_Indices[0] = 0;
		//this->m_Indices[1] = 1;
		//this->m_Indices[2] = 3;
		//this->m_Indices[3] = 1;
		//this->m_Indices[4] = 2;
		//this->m_Indices[5] = 3;
		//this->m_IndicesCount = 6;

	}



	subMesh::~subMesh() {
		//delete this->m_Transform;
	}
	void subMesh::Generate() {
		Renderer::GenerateBuffers(this);
	}
	void subMesh::addTexture(Texture* texture) {
		this->m_Textures.push_back(texture);
	}
}
