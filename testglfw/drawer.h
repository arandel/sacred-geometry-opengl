#include <GL/glfw.h>
#include "particle.h"

#ifndef DRAWER_H_
#define DRAWER_H_

class Drawer {
    static const int PARTICLE_NUM = 10000;
    static const int SEGMENTS = 50;

    static const float RADIUS = 1.5;

    static const GLfloat PURPLE[4], YELLOW[4], GREY[4], GREEN[4];

    GLUquadricObj * quadObj;
    Particle * particles[PARTICLE_NUM];

    void drawSquare(GLfloat*, float);
    GLfloat * transformColor(const GLfloat*, float);

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
        delete[] particles;
    }

    void drawMetatronCube(float);
    void drawStarTetrahedron(float);
    void drawHexahedron(float);
    void drawOctahedron(float);

    void drawParticles(float);
};

#endif /* DRAWER_H_ */
