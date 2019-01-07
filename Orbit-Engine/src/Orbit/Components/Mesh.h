#pragma once

#include "Component.h"

namespace Orbit {
	class Mesh : public Component {
		Mesh(std::string& path);
		void Draw();
	};
}