#pragma once
#include <string>
#include "Component.h"

namespace Orbit {
	class ORBIT_API Mesh : public Component {
	public:
		Mesh(std::string path);
		void Draw();
	};
}