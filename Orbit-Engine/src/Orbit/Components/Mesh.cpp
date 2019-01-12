#include "obtpch.h"
#include "Mesh.h"

#include "Orbit/Renderer/Renderer.h"

namespace Orbit {
	Mesh::Mesh(std::string path) {
		this->addSubMesh();
	}

	Mesh::~Mesh() {
	}

	void Mesh::Draw() {
		for(subMesh* sm : this->m_subMesh)
			Renderer::DrawSubMesh(sm);
	}

	void Mesh::addSubMesh() {
		subMesh* submesh = new subMesh();
		this->m_subMesh.push_back(submesh);
	}
}
