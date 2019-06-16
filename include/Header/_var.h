#pragma once

#include "include/glm/glm.hpp"
#include "include/glm/gtc/type_ptr.hpp"
#include "include/GraphicEngine/Shader.h"
#include "include/Scene/Light.h"
#include "include/Header/Eye.h"
#include "direct.h"
#include <vector>
#include <chrono>
#include <string>
#include <map>

using namespace std;

class _var {
public:
	static glm::mat4 model;
	static glm::mat4 view;
	static glm::mat4 projection;
	static int width, height;
	static Shader shader;
	static Eye eye;
	static DirLight dirLight;
	static bool initial;

	static float time;	// pass time

	static void init();
	static void update();
private:
	static chrono::time_point<chrono::steady_clock> lastTime;
};