#include "obtpch.h"
#include "Mesh.h"

#include "Orbit/Renderer/Renderer.h"

namespace Orbit {
	Mesh::Mesh(std::string path) {
		this->m_Transform = new Transform();
		this->addSubMesh();
	}

	Mesh::~Mesh() {
	}

	void Mesh::Draw() {
		for (subMesh* sm : this->m_subMesh)
			Renderer::DrawSubMesh(sm, Renderer::getActiveCamera());
	}

	void Mesh::addSubMesh() {
		subMesh* submesh = new subMesh(this->m_Transform);
		this->m_subMesh.push_back(submesh);
	}
}
