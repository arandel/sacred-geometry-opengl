#include "utils.h"

#ifndef PARTICLE_H_
#define PARTICLE_H_

class Particle {
    static const float ANGLE = PI / 15;
    static const float VELOCITY = 3.0;
    static const float GRAVITY = 0.5;

    bool initialized;

    float vX, vY, vZ; // Velocity vector coordinates
    float initialTime, lifetime;

    void moveCoords(float time);
    void moveColors(float time);

public:
    float x, y, z;
    float r, g, b;
    Particle() {
        initialized = false;
        initialTime = 0;
        lifetime = 5.0 * Utils::random();

        x = 0;
        y = 0;
        z = 0;
        r = 0;
        g = 0;
        b = 0;

        float phi = PI * 2.0 * (Utils::random() - 0.5);
        float psi = ANGLE + ANGLE * Utils::random();

        vZ = VELOCITY * cos(psi);
        float vXY = VELOCITY * sin(psi);
        vX = vXY * cos(phi);
        vY = vXY * sin(phi);
    }
    bool move(float time);
};

#endif /* PARTICLE_H_ */
