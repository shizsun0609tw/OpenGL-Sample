#pragma once

#include "include/glm/glm.hpp"
#include <vector>

typedef glm::vec3 Position;
typedef glm::vec3 Force;
typedef glm::vec3 Velocity;
typedef glm::vec3 Acceleration;
typedef float Mass;
typedef float Volumn;
typedef float Time;

using namespace std;

class PhysicsEngine {
public:
	static Force calNewton2Law(Mass m, Acceleration a) { return m * a; }
	static Acceleration calNewton2Law(Force F, Mass m) { return (m == 0 ? Acceleration(0.f) : F / m); }
	static Velocity calVelocity(Velocity v0, Acceleration a, Time t) { return v0 + a * t; }
	static Position calPosition(Position p0, Velocity v, Time t) { return p0 + v * t; }
};