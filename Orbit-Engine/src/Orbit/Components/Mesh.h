#pragma once
#include <string>
#include <vector>

#include "Orbit/TimeStep.h"
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
		void OnUpdate(Orbit::Timestep ts) override;
	private:
		std::vector<subMesh*> m_subMesh;
		Transform* m_Transform;
	};
}