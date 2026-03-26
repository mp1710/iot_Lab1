#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "global.h"


void eq_solver(coeff_t coeff, root_t *roots) {
    double a = coeff.a;
    double b = coeff.b;
    double c = coeff.c;
    
    double discriminante = b * b - 4 * a * c;
    
    if (discriminante > 0) {
        roots->real1 = (-b + sqrt(discriminante)) / (2 * a);
        roots->imag1 = 0;
        roots->real2 = (-b - sqrt(discriminante)) / (2 * a);
        roots->imag2 = 0;
        roots->complex = false;
    } else if (discriminante == 0) {
        roots->real1 = -b / (2 * a);
        roots->imag1 = 0;
        roots->real2 = -b / (2 * a);
        roots->imag2 = 0;
        roots->complex = false;
    } else {
        roots->real1 = -b / (2 * a);
        roots->imag1 = sqrt(-discriminante) / (2 * a);
        roots->real2 = -b / (2 * a);
        roots->imag2 = -sqrt(-discriminante) / (2 * a);
        roots->complex = true;
    }
    return *roots;
}

