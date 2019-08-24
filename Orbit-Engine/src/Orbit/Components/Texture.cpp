#include "obtpch.h"
#include "Texture.h"

#include "../Renderer/glRenderer/glRenderer.h"

namespace Orbit {
	Texture::Texture(std::string path) {
		this->m_Type = TextureType::TYPE_DIFFUSE;
		this->m_Id = Renderer::getRenderer()->LoadTextureImage(path);
	}

	TextureType Texture::getType() {
		return this->m_Type;
	}

	uint32_t Texture::getId() {
		return this->m_Id;
	}

	Texture::~Texture() {
	}
}
