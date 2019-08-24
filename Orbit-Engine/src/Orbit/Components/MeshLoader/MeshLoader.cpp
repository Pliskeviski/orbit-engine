#include "obtpch.h"
#include "MeshLoader.h"

namespace Orbit {
	void MeshLoader::loadMesh(std::string& filePath, Mesh* mesh) {
	
		FILE* fileB = fopen(filePath.c_str(), "rb");
		if (!fileB) return;

		std::vector<subMesh*> meshes = mesh->getSubMeshes();


		unsigned int m_meshes;
		fread(&m_meshes, sizeof(int), 1, fileB);
		fclose(fileB);

		meshes.reserve(m_meshes);
		for (unsigned int i = 0; i < m_meshes; i++) {
			std::string f_name(filePath);
			f_name.append(std::to_string(i));
			ORBIT_CORE_INFO("Loading file {0}.", f_name);

			FILE* file = fopen(f_name.c_str(), "rb");
			if (!file) {
				ORBIT_CORE_ERROR("Opening mesh file problem");
				break;
			}

			subMesh* submesh = new subMesh(mesh->getTransform());
			
			//mesh->sMesh_cout++;
			submesh->m_Name = std::string("SubMesh " + std::to_string(i)).c_str();
			// Read info about Vertices size and Indices size
			glm::vec3 info;
			fread(&info, sizeof(glm::vec3), 1, file);
			submesh->m_VerticesCount = info.x;
			submesh->m_IndicesCount = info.y;

			// Read info to check if the mesh has normals and UVs
			glm::vec3 info2;
			fread(&info2, sizeof(glm::vec3), 1, file);
			submesh->m_HasNormals = bool(info2.x);
			submesh->m_HasUVs = bool(info2.y);

			// Read position
			glm::vec3 pos;
			fread(&pos, sizeof(glm::vec3), 1, file);
			submesh->m_Transform = new Transform({ pos.x, pos.y, pos.z });

			// Vertices
			submesh->m_Vertices = new glm::vec3[info.x];
			fread(&submesh->m_Vertices[0], sizeof(glm::vec3), info.x, file);
			ORBIT_CORE_INFO("{0} Vertices loaded!", info.x);

			// Normals
			submesh->m_Normals = new glm::vec3[info.x];
			fread(&submesh->m_Normals[0], sizeof(glm::vec3), info.x, file);
			ORBIT_CORE_INFO("{0} Normals loaded!", info.x);

			// UVs
			if (submesh->m_HasUVs) {
				submesh->m_HasUVs = true;
				submesh->m_UVs = new glm::vec2[info.x];
				fread(&submesh->m_UVs[0], sizeof(glm::vec2), info.x, file);
				ORBIT_CORE_INFO("{0} UVs loaded!", info.x);

				for (unsigned int g = 0; g < info.x; g++) {
					submesh->m_UVs[g].y *= -1;
				}
			}

			struct Index {
				unsigned int x, y, z;
			};
			Index* indices = new Index[info.y];
			fread(&indices[0], sizeof(Index), info.y, file);
			submesh->m_Indices = new unsigned int[info.y * 3];

			int indice_index = 0;
			for (int i = 0; i < info.y / 3; i++) {
				submesh->m_Indices[indice_index++] = indices[i].x;
				submesh->m_Indices[indice_index++] = indices[i].y;
				submesh->m_Indices[indice_index++] = indices[i].z;
				//ORBIT_CORE_WARN("{0} {1} {2}", submesh->m_Indices[indice_index-3], submesh->m_Indices[indice_index-2], submesh->m_Indices[indice_index-1]);
			}

			// Indices
			//fread(&submesh->m_Indices[0], sizeof(unsigned int), info.y, file);
			ORBIT_CORE_INFO("{0} Indices loaded!", info.y);

			//meshes.push_back(submesh);
			mesh->getSubMeshes().push_back(submesh);
			fclose(file);
		}
	}
}
