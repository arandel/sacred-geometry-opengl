#include "particle.h"

void Particle::moveCoords(float t) {
	x = vX * t;
	y = vY * t;
	z = vZ * t - GRAVITY * t * t;
}

void Particle::moveColors(float t) {
	r = Utils::drob(vX * t);
	g = Utils::drob(vY * t);
	b = Utils::drob(vZ * t);
}

bool Particle::move(float time) {
	if (!initialized) {
		initialTime = time;
		initialized = true;
	}
	float t = time - initialTime;
	if (t > lifetime)
		return false;

	moveCoords(t);

	moveColors(t);

	return true;
}
