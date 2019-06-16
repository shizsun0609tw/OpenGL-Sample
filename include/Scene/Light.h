#pragma once

#include "include/glm/glm.hpp"
#include "include/glm/gtc/type_ptr.hpp"
#include "include/GraphicEngine/Shader.h"

class Light {
public:
	Light() {}
	Light(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular)
		: ambient(ambient), diffuse(diffuse), specular(specular) {}
	~Light() {}
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	virtual void sendData(Shader s) = 0;
};

class SpotLight : public Light {
public:
	SpotLight() : Light() {}
	SpotLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position, glm::vec3 direction, 
			float cutOff, float outerCutOff, float constant, float linear)
		: Light(ambient, diffuse, specular), position(position), cutOff(cutOff), outerCutOff(outerCutOff), constant(constant), linear(linear){}
	~SpotLight() {}
	glm::vec3 position;
	glm::vec3 direction;
	float cutOff = 20.f;
	float outerCutOff = 30.f;
	float constant = 1.f;
	float linear = 0.09f;

	void sendData(Shader s) override {
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "mySpotLight.ambient"), 1, glm::value_ptr(ambient));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "mySpotLight.diffuse"), 1, glm::value_ptr(diffuse));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "mySpotLight.specular"), 1, glm::value_ptr(specular));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "mySpotLight.position"), 1, glm::value_ptr(position));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "mySpotLight.direction"), 1, glm::value_ptr(direction));
		glUniform1f(glGetUniformLocation(s.shaderProgram, "mySpotLight.cutOff"), glm::cos(glm::radians(cutOff)));
		glUniform1f(glGetUniformLocation(s.shaderProgram, "mySpotLight.outerCutOff"), glm::cos(glm::radians(outerCutOff)));
		glUniform1f(glGetUniformLocation(s.shaderProgram, "mySpotLight.constant"), constant);
		glUniform1f(glGetUniformLocation(s.shaderProgram, "mySpotLight.linear"), linear);
	}
};

class DirLight : public Light {
public:
	DirLight() : Light() {}
	DirLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 direction)
		: Light(ambient, diffuse, specular), direction(direction) {}
	~DirLight() {}
	glm::vec3 direction;

	void sendData(Shader s) override {
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myDiretionLight.ambient"), 1, glm::value_ptr(ambient));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myDiretionLight.diffuse"), 1, glm::value_ptr(diffuse));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myDiretionLight.specular"), 1, glm::value_ptr(specular));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myDiretionLight.direction"), 1, glm::value_ptr(direction));
	}
};

class PointLight : public Light {
public:
	PointLight() : Light() {}
	PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 position, float constant, float linear)
		: Light(ambient, diffuse, specular), position(position), constant(constant), linear(linear) {}
	~PointLight() {}
	glm::vec3 position;
	float constant = 1.f;
	float linear = 0.09f;

	void sendData(Shader s) override {
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myPointLight.ambient"), 1, glm::value_ptr(ambient));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myPointLight.diffuse"), 1, glm::value_ptr(diffuse));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myPointLight.specular"), 1, glm::value_ptr(specular));
		glUniform3fv(glGetUniformLocation(s.shaderProgram, "myPointLight.position"), 1, glm::value_ptr(position));
		glUniform1f(glGetUniformLocation(s.shaderProgram, "myPointLight.constant"), constant);
		glUniform1f(glGetUniformLocation(s.shaderProgram, "myPointLight.linear"), linear);
	}
};