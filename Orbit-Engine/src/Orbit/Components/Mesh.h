#pragma once
#include <string>
#include <vector>

#include "Component.h"
#include "subMesh.h"

class Component;
namespace Orbit {
	class ORBIT_API Mesh : public Component {
	public:
		Mesh(std::string path);
		~Mesh();
		void Draw();
		void addSubMesh();
	private:
		std::vector<subMesh*> m_subMesh;
	};
}