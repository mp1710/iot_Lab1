#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "global.h"

root_t eq_solver(coeff_t *coeficientes) {
    double a = coeficientes->a;
    double b = coeficientes->b;
    double c = coeficientes->c;

    double discriminante = b * b - 4 * a * c;
    root_t result;

    if (discriminante > 0) {
        result.real1 = (-b + sqrt(discriminante)) / (2 * a);
        result.imag1 = 0;
        result.real2 = (-b - sqrt(discriminante)) / (2 * a);
        result.imag2 = 0;
        result.complex = false;
    } else if (discriminante == 0) {
        result.real1 = -b / (2 * a);
        result.imag1 = 0;
        result.real2 = -b / (2 * a);
        result.imag2 = 0;
        result.complex = false;
    } else {
        result.real1 = -b / (2 * a);
        result.imag1 = sqrt(-discriminante) / (2 * a);
        result.real2 = -b / (2 * a);
        result.imag2 = -sqrt(-discriminante) / (2 * a);
        result.complex = true;
    }
    return result;
}

void string_copy(char *source, char *destination) {
    while (*source) {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0'; // Agregar el carácter nulo al final de la cadena
    
}

