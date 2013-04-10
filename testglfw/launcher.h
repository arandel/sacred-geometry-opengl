#include "renderer.h"

#ifndef LAUNCHER_H_
#define LAUNCHER_H_

class Launcher {
    Renderer * renderer;
public:
    Launcher() {
        renderer = new Renderer();
    }
    ~Launcher();
    bool init();
    void showWindowWhileNotClosed();
};

#endif /* LAUNCHER_H_ */
