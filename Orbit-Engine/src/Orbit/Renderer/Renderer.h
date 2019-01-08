#pragma once
#include "Orbit/Core.h"

//#include "Object.h"

enum Render {
	OPENGL = 0
};

namespace Orbit {
	class ORBIT_API Renderer {
	public:
		Renderer() {}
		virtual ~Renderer() {};

		virtual void Draw() = 0;
		virtual void Destroy() = 0;
		
		static Renderer* Create(Render api = OPENGL);
	private:
		//std::vector<std::shared_ptr<Object>> m_Objects;
	};
}