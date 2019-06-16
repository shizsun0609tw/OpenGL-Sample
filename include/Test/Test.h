#pragma once

#include "include/Reader/Reader.h"
#include "include/GraphicEngine/Material.h"
#include "include/GraphicEngine/VAO.h"
#include "include/PhysicsEngine/PhysicsEngine.h"

class Test {
public:
	Test() {
		vao = Reader::readObj(string(_getcwd(NULL, 0)) + "\\Assets\\cube.obj");
		material = Material(glm::vec3(1.f), glm::vec3(1.f), glm::vec3(1.f), 1);
	}
	~Test() {}

	void update() {
		updateAttrib();
		updateGesture();
	}

	void draw() {
		_var::model = glm::translate(_var::model, pos);
		_var::model = _var::model * rotateMtx;

		material.sendData(_var::shader);
		glUniform4fv(glGetUniformLocation(_var::shader.shaderProgram, "color"), 1, glm::value_ptr(glm::vec3(0.25f)));
		glUniformMatrix4fv(glGetUniformLocation(_var::shader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(_var::view));
		glUniformMatrix4fv(glGetUniformLocation(_var::shader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(_var::projection));
		glUniformMatrix4fv(glGetUniformLocation(_var::shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(_var::model));

		VAOManagement::drawVAO(vao);
	}
private:
	vector<VAO> vao;
	Material material;

	glm::vec3 pos;
	glm::vec3 angle;

	glm::mat4 rotateMtx = glm::mat4(1.f);

	void updateAttrib() {}
	void updateGesture() {
		// TODO use force to update pos
		//pos = PhysicsEngine::calPosition(pos, glm::vec3(0.01f, 0.f, 0.f), _var::time);

		glm::vec3 pastAngle = angle;
		// TODO use torque to update angle
		// angle.y += 0.05f;

		rotateMtx = glm::rotate(rotateMtx, glm::radians(angle.x - pastAngle.x), glm::vec3(1.f, 0.f, 0.f));
		rotateMtx = glm::rotate(rotateMtx, glm::radians(angle.y - pastAngle.y), glm::vec3(0.f, 1.f, 0.f));
		rotateMtx = glm::rotate(rotateMtx, glm::radians(angle.z - pastAngle.z), glm::vec3(0.f, 0.f, 1.f));
	}
};