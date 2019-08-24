#include "obtpch.h"
#include "Texture.h"

#include "../Renderer/glRenderer/glRenderer.h"

namespace Orbit {
	Texture::Texture(std::string path) {
		this->m_Type = TextureType::TYPE_DIFFUSE;
		this->m_Id = glRenderer::GLLoadImage(path);
	}

	Texture::~Texture() {
	}
}
