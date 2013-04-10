#include <iostream>
#include "launcher.h"

using namespace std;

int main(void) {
    // Initializing Randomizer using current time
    srand(time(0));

    cout << "Creating OpenGL launcher...\n";
    Launcher * launcher = new Launcher();

    cout << "Done, initializing...\n";
    if (!launcher->init())
        return -1;

    cout << "Done, launching window...\n";
    launcher->showWindowWhileNotClosed();

    return 0;
}
