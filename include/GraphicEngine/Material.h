#pragma once

#include "include/glm/glm.hpp"
#include "include/glm/gtc/type_ptr.hpp"
#include "include/GraphicEngine/Shader.h"

class Material {
public:
	Material() {}
	Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shininess)
		:ambient(ambient), diffuse(diffuse), specular(specular), shininess(shininess) {}
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shininess;
	void sendData(Shader s) {
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myMaterial.ambient"), 1, glm::value_ptr(ambient));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myMaterial.diffuse"), 1, glm::value_ptr(diffuse));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myMaterial.specular"), 1, glm::value_ptr(specular));
		glUniform1f(glGetUniformLocation(s.shaderProgram, "myMaterial.shininess"), shininess);
	}
};