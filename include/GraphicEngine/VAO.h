#pragma once

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <iostream>

typedef glm::vec3 PositionVec3;
typedef glm::vec3 NormalVec3;

using namespace std;

class VAO {
public:
	GLuint vao;
	int count = 0;
};

class VAOManagement {
public:
	static VAO generateVAO(vector<pair<PositionVec3, NormalVec3>> vertexData);
	static void drawVAO(vector<VAO>);
};
