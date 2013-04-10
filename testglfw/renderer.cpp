#include "renderer.h"

void Renderer::reshape(int width, int height) {
    GLfloat h = (GLfloat) height / (GLfloat) width;
    GLfloat xmax, znear, zfar;

    znear = 5.0f;
    zfar = 30.0f;
    xmax = znear * 0.5f;

    glViewport(0, 0, (GLint) width, (GLint) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-xmax, xmax, -xmax * h, xmax * h, znear, zfar);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -20.0);
}

void Renderer::render(float time) {
    glPushMatrix();

    glRotatef(time * 13, 1.0, 0.0, 0.0);
    glRotatef(time * 7, 0.0, 1.0, 0.0);
    glRotatef(time * 4, 0.0, 0.0, 1.0);

    drawer->drawMetatronCube();
    drawer->drawStarTetrahedron();
    drawer->drawHexahedron();
    drawer->drawOctahedron();

    drawer->drawParticles(time);

    glPopMatrix();
}
