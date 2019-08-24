#include "obtpch.h"
#include "Mesh.h"

#include "Orbit/Renderer/Renderer.h"

#include "MeshLoader/MeshLoader.h"

namespace Orbit {
	Mesh::Mesh(std::string path) {
		this->m_Transform = new Transform();
		
		MeshLoader::loadMesh(path, this);

		for (int i = 0; i < this->m_subMesh.size(); i++) {
			this->m_subMesh[i]->Generate();
			this->m_subMesh[i]->m_Transform->setParent(this->m_Transform);
		}
	}

	Mesh::~Mesh() {
	}

	void Mesh::Draw() {
		for (subMesh* sm : this->m_subMesh)
			Renderer::DrawSubMesh(sm, Renderer::getActiveCamera());
	}

	std::vector<subMesh*>& Mesh::getSubMeshes() {
		return this->m_subMesh;
	}

	Transform* Mesh::getTransform() {
		return this->m_Transform;
	}

	void Mesh::setParent(Component* parent) {
		this->m_Transform->setParent(parent);
	}
	void Mesh::OnUpdate(Orbit::Timestep ts) {
		this->Draw();
	}
}
