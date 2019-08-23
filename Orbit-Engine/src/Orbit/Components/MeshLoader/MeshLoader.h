#pragma once
#include "Orbit/Core.h"

#include <string>
#include "Orbit/Components/Mesh.h"

namespace Orbit {
	class MeshLoader {
	public:
		static void loadMesh(std::string& filePath, Mesh* mesh);
	};
}