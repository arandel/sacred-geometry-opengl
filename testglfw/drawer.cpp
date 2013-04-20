#include <math.h>
#include "drawer.h"

const GLfloat Drawer::PURPLE[4] = { 118.0 / 0xFF, 8.0 / 0xFF, 170.0 / 0xFF, 0.8 }; //#7608AA
const GLfloat Drawer::YELLOW[4] = { 256.0 / 0xFF, 214.0 / 0xFF, 0.0, 0.3 }; //#FFD600
const GLfloat Drawer::GREY[4] = { 0.1, 0.1, 0.1, 0.2 };
const GLfloat Drawer::GREEN[4] = { 152.0 / 0xFF, 237.0 / 0xFF, 0.0, 0.1 }; //#98ED00

void Drawer::drawMetatronCube(float t) {
    glColor4fv(GREY);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                glPushMatrix();
                glTranslatef(2 * RADIUS * (i - 1), 2 * RADIUS * (j - 1), 2 * RADIUS * (k - 1));
                gluSphere(quadObj, RADIUS, SEGMENTS, SEGMENTS);
                glPopMatrix();
            }
        }
    }
}

void Drawer::drawStarTetrahedron(float t) {
    float r = 2 * RADIUS;

    GLfloat * color = transformColor(PURPLE, t * E);
    // Faces
    glColor4fv(color);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(-r, -r, -r);
    glVertex3f(r, r, -r);
    glVertex3f(r, -r, r);
    glVertex3f(-r, r, r);
    glVertex3f(r, r, -r);
    glVertex3f(-r, -r, -r);
    glEnd();

    glColor3fv(color);
    glColor3fv(YELLOW);
    glBegin(GL_LINE_LOOP);
    glVertex3f(r, 0, 0);
    glVertex3f(0, r, 0);
    glVertex3f(0, 0, r);
    glEnd();

    // Edges
    glBegin(GL_LINE_LOOP);
    glVertex3f(-r, -r, -r);
    glVertex3f(r, r, -r);
    glVertex3f(r, -r, r);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-r, r, r);
    glVertex3f(-r, -r, -r);
    glVertex3f(-r, r, r);
    glVertex3f(r, r, -r);
    glVertex3f(-r, r, r);
    glVertex3f(r, -r, r);
    glEnd();

    // Faces
    glColor4fv(color);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(r, r, r);
    glVertex3f(-r, -r, r);
    glVertex3f(-r, r, -r);
    glVertex3f(r, -r, -r);
    glVertex3f(-r, -r, r);
    glVertex3f(r, r, r);
    glEnd();

    // Edges
    glColor3fv(color);
    glBegin(GL_LINE_LOOP);
    glVertex3f(r, r, r);
    glVertex3f(-r, -r, r);
    glVertex3f(-r, r, -r);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(r, -r, -r);
    glVertex3f(r, r, r);
    glVertex3f(r, -r, -r);
    glVertex3f(-r, -r, r);
    glVertex3f(r, -r, -r);
    glVertex3f(-r, r, -r);
    glEnd();
}

void Drawer::drawSquare(GLfloat * color, float r) {
    // Face
    glColor4fv(color);
    glBegin(GL_QUADS);
    glVertex2f(-r, -r);
    glVertex2f(r, -r);
    glVertex2f(r, r);
    glVertex2f(-r, r);
    glEnd();

    // Edges
    glColor3fv(color);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-r, -r);
    glVertex2f(r, -r);
    glVertex2f(r, r);
    glVertex2f(-r, r);
    glEnd();
}

void Drawer::drawHexahedron(float t) {
    float r = 2 * RADIUS;

    GLfloat * color = transformColor(GREEN, t);

    // Top-Bottom
    glPushMatrix();
    glTranslatef(0.0, 0.0, -r);
    drawSquare(color, r);
    glTranslatef(0.0, 0.0, 2 * r);
    drawSquare(color, r);
    glPopMatrix();

    // Front-Back
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -r);
    drawSquare(color, r);
    glTranslatef(0.0, 0.0, 2 * r);
    drawSquare(color, r);
    glPopMatrix();

    // Left-Right
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, -r);
    drawSquare(color, r);
    glTranslatef(0.0, 0.0, 2 * r);
    drawSquare(color, r);
    glPopMatrix();
}

void Drawer::drawOctahedron(float t) {
    float r = 4 * RADIUS;

    GLfloat * color = transformColor(YELLOW, t * PI);

    // Faces
    glColor4fv(color);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, 0.0, r);
    glVertex3f(r, 0.0, 0.0);
    glVertex3f(0.0, r, 0.0);
    glVertex3f(-r, 0.0, 0.0);
    glVertex3f(0.0, -r, 0.0);
    glVertex3f(r, 0.0, 0.0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, 0.0, -r);
    glVertex3f(r, 0.0, 0.0);
    glVertex3f(0.0, r, 0.0);
    glVertex3f(-r, 0.0, 0.0);
    glVertex3f(0.0, -r, 0.0);
    glVertex3f(r, 0.0, 0.0);
    glEnd();

    // Edges
    glColor3fv(color);
    glBegin(GL_LINE_LOOP);
    glVertex3f(r, 0.0, 0.0);
    glVertex3f(0.0, r, 0.0);
    glVertex3f(-r, 0.0, 0.0);
    glVertex3f(0.0, -r, 0.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0, 0.0, r);
    glVertex3f(0.0, r, 0.0);
    glVertex3f(0.0, 0.0, -r);
    glVertex3f(0.0, -r, 0.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0, 0.0, r);
    glVertex3f(r, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -r);
    glVertex3f(-r, 0.0, 0.0);
    glEnd();
}

void Drawer::drawParticles(float time) {
    glPointSize(1.5);

    glBegin(GL_POINTS);
    for (int i = 0; i < PARTICLE_NUM / 2; ++i) {
        if (!particles[i]->move(time)) {
            delete particles[i];
            particles[i] = new Particle();
        }
        glColor3f(particles[i]->r, particles[i]->g, particles[i]->b);
        glVertex3f(particles[i]->x, particles[i]->y, particles[i]->z);
    }
    glEnd();

    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    for (int i = PARTICLE_NUM / 2; i < PARTICLE_NUM; ++i) {
        if (!particles[i]->move(time)) {
            delete particles[i];
            particles[i] = new Particle();
        }
        glColor3f(particles[i]->r, particles[i]->g, particles[i]->b);
        glVertex3f(particles[i]->x, particles[i]->y, particles[i]->z);
    }
    glEnd();
    glPopMatrix();
}

GLfloat * Drawer::transformColor(const GLfloat * color, float t) {
    GLfloat * result = new GLfloat[4];

    float m = 0.5 + sin(t) / PI;
    for (int i = 0; i < 3; ++i) {
        result[i] = color[i] * m;
    }
    result[3] = color[3];

    return result;
}

