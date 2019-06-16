#pragma once
#include "include/glm/glm.hpp"
#include "include/glm/gtc/type_ptr.hpp"
#include "include/GraphicEngine/Shader.h"

class Eye {
public:
	Eye();
	Eye(float theta, float fi, float r, float fovy, glm::vec3 lookPos, float near, float far);
	~Eye();

	float theta, fi;
	float r;
	float fovy;
	float nearDistance, farDistance;
	glm::vec3 u, v, w;
	glm::vec3 pos;
	glm::vec3 lookPos;

	void update();
	void sendData(Shader s);
};