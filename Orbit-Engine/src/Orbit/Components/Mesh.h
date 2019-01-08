#pragma once
#include <string>
#include "Component.h"
#include "subMesh.h"

namespace Orbit {
	class ORBIT_API Mesh : public Component {
	public:
		Mesh(std::string path);
		~Mesh();
		void Draw();
	private:
		std::vector<subMesh*> m_subMesh;
	};
}