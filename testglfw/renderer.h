#include "drawer.h"

#ifndef RENDERER_H_
#define RENDERER_H_

class Renderer {
    Drawer * drawer;

public:
    Renderer() {
        drawer = new Drawer();
    }

    ~Renderer() {
        delete drawer;
    }

    void render(float time);
    static void reshape(int, int);
};

#endif /* RENDERER_H_ */
