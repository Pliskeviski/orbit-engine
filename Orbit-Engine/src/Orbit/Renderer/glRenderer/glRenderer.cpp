#include "obtpch.h"
#include "glRenderer.h"

#include <vector>
#include "Orbit/Core.h"

#include "Orbit/Components/Camera.h"

#include "SOIL2.h"

namespace Orbit {
	glRenderer::glRenderer() {
		const GLubyte* vendor = glGetString(GL_VENDOR);
		const GLubyte* version = glGetString(GL_VERSION);
		const GLubyte* renderer = glGetString(GL_RENDERER);

		//std::string vertexPath   = __FILE__ "\\..\\Shader\\Shaders\\TransformVertexShader.vertexshader";
		//std::string fragmentPath = __FILE__ "\\..\\Shader\\Shaders\\ColorFragmentShader.fragmentshader";
		
		std::string vertexPath = __FILE__ "\\..\\Shader\\Shaders\\pbr.vertexshader";
		std::string fragmentPath = __FILE__ "\\..\\Shader\\Shaders\\pbr.fragmentshader";
		this->m_Shader = new Shader(vertexPath, fragmentPath);

		this->m_Shader->setVec3("lightPositions[0]", Math::vec3(0, 0, 0));
		this->m_Shader->setVec3("lightColors[0]", Math::vec3(100, 100, 100));

		glViewport(0, 0, 1280, 768);

		ORBIT_CORE_INFO("OpenGL {0} - {1} {2}", version, renderer, vendor);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glEnable(GL_DEPTH_TEST);
	}

	void glRenderer::Draw() {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		this->m_Shader->Use();
	}

	uint32_t glRenderer::CreateBuffer(subMesh* submesh) {

		glGenVertexArrays(1, &submesh->m_VAO);
		glBindVertexArray(submesh->m_VAO);

		//// Add buffers 
		submesh->m_VBOs.push_back(genVBO(submesh, submesh->m_VerticesCount * sizeof(glm::vec3), 3, &submesh->m_Vertices[0], GL_STATIC_DRAW));

		if (submesh->m_HasUVs)
			submesh->m_VBOs.push_back(genVBO(submesh, submesh->m_VerticesCount* sizeof(glm::vec2), 2, &submesh->m_UVs[0], GL_STATIC_DRAW));

		////if (s_mesh->hasNormals)
		////	s_mesh->VBOs.push_back(genVBO(s_mesh, s_mesh->vertSize * sizeof(glm::vec3), 3, &s_mesh->Normals[0], GL_STATIC_DRAW));

		////if (!s_mesh->Tangents.empty())
		////	s_mesh->VBOs.push_back(genVBO(s_mesh, s_mesh->Tangents.size() * sizeof(glm::vec3), 3, &s_mesh->Tangents[0], GL_STATIC_DRAW));

		////if (!s_mesh->BiTangents.empty())
		////	s_mesh->VBOs.push_back(genVBO(s_mesh, s_mesh->BiTangents.size() * sizeof(glm::vec3), 3, &s_mesh->BiTangents[0], GL_STATIC_DRAW));

		glGenBuffers(1, &submesh->m_EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, submesh->m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, submesh->m_IndicesCount * sizeof(uint32_t), &submesh->m_Indices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		return 1;
	}
	int glRenderer::drawSubMesh(subMesh* submesh, Camera* scene_camera) {

		glBindVertexArray(submesh->m_VAO);
		for (unsigned int j = 0; j < submesh->m_VBOs.size(); j++) {
			glEnableVertexAttribArray(j);
		}

		GLuint ViewID       = glGetUniformLocation(this->m_Shader->getID(), "view");
		GLuint ModelID      = glGetUniformLocation(this->m_Shader->getID(), "model");
		GLuint ProjectionID = glGetUniformLocation(this->m_Shader->getID(), "projection");

		GLuint CamPosID = glGetUniformLocation(this->m_Shader->getID(), "camPos");


		Math::mat4 Projection	= glm::perspective(scene_camera->getFov(), (GLfloat)scene_camera->m_Width / (GLfloat)scene_camera->m_Height, 0.1f, 1000.0f);
		Math::mat4 View			= scene_camera->getViewMatrix();

		Math::vec3 s_Parent_Pos = submesh->m_Transform->getParent()->getPosition();
		Math::vec3 s_Parent_Rot = submesh->m_Transform->getParent()->getRotation();
		Math::vec3 s_Parent_Scl = submesh->m_Transform->getParent()->getScale();
		Math::mat4 Model		= glm::translate(glm::mat4(1.f), submesh->m_Transform->getPosition()  + s_Parent_Pos);
		Math::mat4 ModelRX		= glm::rotate	(glm::mat4(1.f), submesh->m_Transform->getRotationX() + s_Parent_Rot.x, glm::vec3(1.0f, .0f, .0f));
		Math::mat4 ModelRY		= glm::rotate	(glm::mat4(1.f), submesh->m_Transform->getRotationY() + s_Parent_Rot.y, glm::vec3(.0f, 1.0f, .0f));
		Math::mat4 ModelRZ		= glm::rotate	(glm::mat4(1.f), submesh->m_Transform->getRotationZ() + s_Parent_Rot.z, glm::vec3(.0f, .0f, 1.0f));
		Math::mat4 ModelScale	= glm::scale	(glm::mat4(1.f), submesh->m_Transform->getScale()     / s_Parent_Scl); // TODO
		Math::mat4 ModelRotation = ModelRX * ModelRY * ModelRZ;

		Model *= ModelRotation * ModelScale;

		glUniformMatrix4fv(ModelID, 1, GL_FALSE, glm::value_ptr(Model));
		glUniformMatrix4fv(ViewID, 1, GL_FALSE, glm::value_ptr(View));
		glUniformMatrix4fv(ProjectionID, 1, GL_FALSE, glm::value_ptr(Projection));

		glUniformMatrix4fv(CamPosID, 1, GL_FALSE, glm::value_ptr(scene_camera->getPosition()));

		glBindVertexArray(submesh->m_VAO);


		if (!submesh->m_Textures.empty()) {
			for (unsigned int i = 0; i < submesh->m_Textures.size(); i++) {
				glActiveTexture(GL_TEXTURE0 + i);
				std::string name;
				if (submesh->m_Textures[i]->getType() == TYPE_DIFFUSE)
					name = "albedoMap";
				if (submesh->m_Textures[i]->getType() == TYPE_NORMAL)
					name = "normalMap";
				if (submesh->m_Textures[i]->getType() == TYPE_METALLIC)
					name = "metallicMap";
				if (submesh->m_Textures[i]->getType() == TYPE_ROUGHNESS)
					name = "roughnessMap";
				if (submesh->m_Textures[i]->getType() == TYPE_AO)
					name = "aoMap";

				glUniform1i(glGetUniformLocation(this->m_Shader->getID(), name.c_str()), i);
				glBindTexture(GL_TEXTURE_2D, submesh->m_Textures[i]->getId());
			}
		}


		glDrawElements(GL_TRIANGLES, submesh->m_IndicesCount, GL_UNSIGNED_INT, 0);

		for (int j = 0; j < submesh->m_VBOs.size(); j++) {
			glDisableVertexAttribArray(j);
		}
		glBindTexture(GL_TEXTURE_2D, 0);

		return 1;
	}
	uint32_t glRenderer::LoadTextureImage(std::string path) {
		int width, height;
		GLuint textureID;

		ORBIT_CORE_INFO("Loading texture: {0}.", path);

		//glActiveTexture(GL_TEXTURE0);
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);

		unsigned char *image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
		if (image == nullptr) {
			std::cout << "Failed to load texture" << std::endl;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image);

		glBindTexture(GL_TEXTURE_2D, 0);

		return textureID;
	}
	GLuint glRenderer::genVBO(subMesh* submesh, GLsizeiptr size, GLint dataSize, const void* data, GLenum usage) {
		glBindVertexArray(submesh->m_VAO);

		GLuint buffer;
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, size, data, usage);

		glEnableVertexAttribArray(submesh->m_VBOs.size());
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glVertexAttribPointer(submesh->m_VBOs.size(), dataSize, GL_FLOAT, GL_FALSE, 0, 0);

		return buffer;
	}
}