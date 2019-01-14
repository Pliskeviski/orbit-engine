#pragma once

#include "glm/glm.hpp"
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

namespace Orbit {
	namespace Math {
		typedef glm::vec3 vec3;
		typedef glm::vec2 vec2;
		typedef glm::mat4 mat4;
		
		/*double radians(float value) {
			return glm::radians(value);
		}

		vec3 normalize(vec3 value) {
			return glm::normalize(value);
		}

		vec3 cross(vec3 value, vec3 value2) {
			return glm::cross(value, value2);
		}

		mat4 lookAt(vec3 value, vec3 value2, vec3 value3) {
			return glm::lookAt(value, value2, value3);
		}*/
	}
}