#include <GL/glfw.h>
#include "particle.h"

#ifndef DRAWER_H_
#define DRAWER_H_

class Drawer {
	static const int PARTICLE_NUM = 10000;
	static const int SEGMENTS = 50;

	static const float RADIUS = 1.5;

	static const GLfloat BLUE[4], RED[4], YELLOW[4], GREY[4], LIGHT_GREY[4];

	GLUquadricObj * quadObj;
	Particle* particles[PARTICLE_NUM];

	void drawSquare(float rad);

public:
	Drawer() {
		quadObj = gluNewQuadric();
		gluQuadricDrawStyle(quadObj, GLU_FILL);
		for (int i = 0; i < PARTICLE_NUM; ++i) {
			particles[i] = new Particle();
		}
	}
	~Drawer() {
		gluDeleteQuadric(quadObj);
		delete [] particles;
	}

	void drawMetatronCube();
	void drawStarTetrahedron();
	void drawHexahedron();
	void drawOctahedron();

	void drawParticles(float);
};

#endif /* DRAWER_H_ */
