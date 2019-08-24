#pragma once
#include <string>

#include "Component.h"

enum TextureType {
	TYPE_DIFFUSE,
	TYPE_METALLIC,
	TYPE_ROUGHNESS,
	TYPE_NORMAL,
	TYPE_AO
};

namespace Orbit {
	class ORBIT_API Texture : Component {
	public:
		Texture(std::string path);
		~Texture();
	private:
		uint32_t m_Id;
		TextureType m_Type;
	};
}

