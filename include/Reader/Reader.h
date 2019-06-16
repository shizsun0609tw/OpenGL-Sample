#pragma once

#include "include/GraphicEngine/VAO.h"
#include "include/Header/_var.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Reader {
public:
	static vector<VAO> readObj(string path);
private:
	static vector<pair<PositionVec3, NormalVec3>> preProcess(vector<glm::vec3> position, vector<glm::vec3> normal, vector<pair<glm::uvec3, glm::uvec3>> index);
};