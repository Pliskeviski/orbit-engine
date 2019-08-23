#pragma once
#include <string>
#include <vector>

#include "Component.h"
#include "Transform.h"
#include "subMesh.h"

class Component;
namespace Orbit {
	class ORBIT_API Mesh : public Component {
	public:
		Mesh(std::string path);
		~Mesh();
		void Draw();
		std::vector<subMesh*>& getSubMeshes();
		Transform* getTransform();
		
		// @ Componet's override
		void setParent(Component* parent) override;
	private:
		std::vector<subMesh*> m_subMesh;
		Transform* m_Transform;
	};
}