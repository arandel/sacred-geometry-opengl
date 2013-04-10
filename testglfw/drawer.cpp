#include <math.h>
#include "drawer.h"

const GLfloat Drawer::BLUE[4] = { 0.0, 0.0, 1.0, 0.5 };
const GLfloat Drawer::RED[4] = { 1.0, 0.0, 0.0, 0.5 };
const GLfloat Drawer::YELLOW[4] = { 1.0, 1.0, 0.0, 0.1 };
const GLfloat Drawer::GREY[4] = { 0.1, 0.1, 0.1, 0.2 };
const GLfloat Drawer::LIGHT_GREY[4] = { 0.7, 0.7, 0.7, 0.01 };

void Drawer::drawMetatronCube() {
	glColor4fv(GREY);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				glPushMatrix();
				glTranslatef(2 * RADIUS * (i - 1), 2 * RADIUS * (j - 1),
						2 * RADIUS * (k - 1));
				gluSphere(quadObj, RADIUS, SEGMENTS, SEGMENTS);
				glPopMatrix();
			}
		}
	}
}

void Drawer::drawStarTetrahedron() {
	float r = 2 * RADIUS;

	// Faces
	glColor4fv(BLUE);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-r, -r, -r);
	glVertex3f(r, r, -r);
	glVertex3f(r, -r, r);
	glVertex3f(-r, r, r);
	glVertex3f(r, r, -r);
	glVertex3f(-r, -r, -r);
	glEnd();

	// Edges
	glColor3fv(YELLOW);
	glBegin(GL_LINE_LOOP);
	glVertex3f(r, 0, 0);
	glVertex3f(0, r, 0);
	glVertex3f(0, 0, r);
	glEnd();

	// Edges
	glColor3fv(BLUE);
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
	glColor4fv(RED);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(r, r, r);
	glVertex3f(-r, -r, r);
	glVertex3f(-r, r, -r);
	glVertex3f(r, -r, -r);
	glVertex3f(-r, -r, r);
	glVertex3f(r, r, r);
	glEnd();

	// Edges
	glColor3fv(RED);
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

void Drawer::drawSquare(float r) {
	// Face
	glColor4fv(LIGHT_GREY);
	glBegin(GL_QUADS);
	glVertex2f(-r, -r);
	glVertex2f(r, -r);
	glVertex2f(r, r);
	glVertex2f(-r, r);
	glEnd();

	// Edges
	glColor3fv(LIGHT_GREY);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-r, -r);
	glVertex2f(r, -r);
	glVertex2f(r, r);
	glVertex2f(-r, r);
	glEnd();
}

void Drawer::drawHexahedron() {
	float r = 2 * RADIUS;

	// Top-Bottom
	glPushMatrix();
	glTranslatef(0.0, 0.0, -r);
	drawSquare(r);
	glTranslatef(0.0, 0.0, 2 * r);
	drawSquare(r);
	glPopMatrix();

	// Front-Back
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -r);
	drawSquare(r);
	glTranslatef(0.0, 0.0, 2 * r);
	drawSquare(r);
	glPopMatrix();

	// Left-Right
	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, -r);
	drawSquare(r);
	glTranslatef(0.0, 0.0, 2 * r);
	drawSquare(r);
	glPopMatrix();
}

void Drawer::drawOctahedron() {
	float r = 4 * RADIUS;

	// Faces
	glColor4fv(YELLOW);
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
	glColor3fv(YELLOW);
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
	for (int i = 0; i < PARTICLE_NUM; ++i) {
		if (!particles[i]->move(time)) {
			delete particles[i];
			particles[i] = new Particle();
		}
		glColor3f(particles[i]->r, particles[i]->g, particles[i]->b);
		glVertex3f(particles[i]->x, particles[i]->y, particles[i]->z);
	}
	glEnd();
}
