#include <GL/glfw.h>
#include "launcher.h"

Launcher::~Launcher() {
    delete renderer;
}

bool Launcher::init() {
    // Initialize the library
    if (!glfwInit())
        return false;

    // Create a windowed mode window and its OpenGL context
    if (!glfwOpenWindow(700, 700, 8, 8, 8, 0, 24, 0, GLFW_WINDOW))
        return false;

    glfwSetWindowSizeCallback(renderer->reshape);
    glfwSwapInterval(1);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
}

void Launcher::showWindowWhileNotClosed() {
    float oldTime = glfwGetTime();
    float time = 0;

    // Loop until the user closes the window
    while (glfwGetWindowParam(GLFW_OPENED)) {
        // calculate time elapsed, and the amount by which stuff rotates
        float currentTime = glfwGetTime();
        float delta = currentTime - oldTime;
        oldTime = currentTime;
        time += delta;

        // clear the buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render here
        renderer->render(time);

        // Swap front and back buffers and process events
        glfwSwapBuffers();
    }
}
