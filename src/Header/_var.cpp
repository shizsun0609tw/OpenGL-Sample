#include "include/Header/_var.h"

glm::mat4 _var::model = glm::mat4(1.f);
glm::mat4 _var::view = glm::mat4(1.f);
glm::mat4 _var::projection = glm::mat4(1.f);

int _var::height = 0;
int _var::width = 0;

Shader _var::shader = Shader();

Eye _var::eye = Eye();

DirLight _var::dirLight = DirLight();

float _var::time = 0;
chrono::time_point<chrono::steady_clock> _var::lastTime;

bool _var::initial = false;

void _var::update() {
	/* time update */
	_var::time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - lastTime).count() / 1000.f;
	_var::lastTime = chrono::steady_clock::now();
	/* eye update */
	_var::eye.update();
	_var::eye.sendData(shader);
	/* light update */
	_var::dirLight.sendData(shader);
	/* matrix update */
	_var::model = glm::mat4(1.f);
	_var::view = glm::lookAt(_var::eye.pos, _var::eye.lookPos, glm::vec3(0, 1, 0));
	_var::projection = glm::perspective(glm::radians(_var::eye.fovy), (float)_var::width / (float)_var::height,
		_var::eye.nearDistance, _var::eye.farDistance);
}



void _var::init() {
	eye = Eye(45.f, 45.f, 10.f, 45.f, glm::vec3(0.f), 0.1f, 500.f);

	string currentPath = _getcwd(NULL, 0);
	shader = Shader(currentPath + "\\src\\GraphicEngine\\shader.vert",
						currentPath + "\\src\\GraphicEngine\\shader.frag");
	dirLight = DirLight(glm::vec3(0.3f), glm::vec3(0.6f), glm::vec3(0.2f), glm::vec3(0.f, -1.f, 0.f));

	lastTime = chrono::steady_clock::now();

	initial = true;
}