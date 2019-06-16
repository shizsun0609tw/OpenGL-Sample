#include "include/Header/Eye.h"

Eye::Eye() {

}


Eye::Eye(float theta, float fi, float r, float fovy, glm::vec3 lookPos, float near, float far)
{
	this->theta = theta;
	this->fi = fi;
	this->r = r;
	this->lookPos = lookPos;
	this->fovy = fovy;
	this->nearDistance = near;
	this->farDistance = far;

	update();
}

Eye::~Eye() {

}

void Eye::update() {
	glm::mat4 transform = glm::mat4(1.f);
	glm::vec4 eye_position = glm::vec4(0.f, 0.f, 0.f, 1.f);
	
	transform = glm::translate(transform, lookPos);
	transform = glm::rotate(transform, glm::radians(theta), glm::vec3(0.f, 1.f, 0.f));
	transform = glm::rotate(transform, glm::radians(fi), glm::vec3(0.f, 0.f, 1.f));
	transform = glm::translate(transform, glm::vec3(r, 0.f, 0.f));
	pos = transform * eye_position;
	
	w = glm::normalize(pos - lookPos);
	u = glm::normalize(glm::cross(glm::vec3(0.f, 1.f, 0.f), w));
	v = glm::normalize(glm::cross(w, u));
}

void Eye::sendData(Shader s) {
	glUniform3fv(glGetUniformLocation(s.shaderProgram, "eyePos"), 1, glm::value_ptr(pos));
}