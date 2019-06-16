#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "include/GL/glew.h"

using namespace std;

class Shader {
public:
	Shader();
	Shader(string VertexShaderPath, string FragmentShaderPath);
	~Shader();
	GLuint shaderProgram;
};