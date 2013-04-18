#include <iostream>
#include <math.h>

#ifndef UTILS_H_
#define UTILS_H_

#define PI 3.141592653589793238462
#define E 2.718281828459045

using namespace std;

class Utils {
public:
    // random value from 0.0 to 1.0
    static double random() {
        return (double) rand() / (double) RAND_MAX;
    }

    static double drob(double big) {
        return big - (int) big;
    }
};

#endif /* UTILS_H_ */
