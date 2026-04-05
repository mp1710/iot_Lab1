#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "global.h"

int main(void) {

// FUNCIÓN 1
    printf("Testing init_lab:\n");
    init_lab();
    printf("\n");
// FUNCIÓN 2
    printf("Testing eq_solver:\n");
    // Creo coeficientes para la ecuacion x^2 - 5x + 6 = 0, que tiene raices reales y distintas (2 y 3)
    coeff_t coef = {1, -5, 6};
    // Llamo a eq_solver con los coeficientes y guardo el resultado en un puntero a root_t
    root_t *result = eq_solver(&coef);

    if (result != NULL) {
        printf("Root 1: %d + %di\n", result->real1, result->imag1);
        printf("Root 2: %d + %di\n", result->real2, result->imag2);
        printf("Complex: %s\n", result->complex ? "true" : "false");

        free(result);
        printf("\n");
    }
// FUNCIÓN 3
    printf("Testing string_copy:\n");
    char source[] = "Prueba de string copy";
    char destination[20];
    string_copy(source, destination);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    printf("\n");

// FUNCIÓN 4
    printf("Testing max_index:\n");
    int32_t arr_int[] = {1, 3, 5, 2, 4};
    size_t size_int = sizeof(arr_int) / sizeof(arr_int[0]);
    max_index(arr_int, sizeof(int32_t), size_int);
    printf("\n");

// FUNCIÓN 5
    printf("Testing min_index:\n");
    int32_t arr_int[] = {5, 1, 9, 2, 5};
    float arr_float[] = {3.5, 2.1, 4.6, 1.1, 3.3};
    double arr_double[] = {2.5, 1.2, 3.8, 2.7, 0.9};
    printf("Para array de enteros:\n");
    min_index(arr_int, sizeof(int32_t), sizeof(arr_int) / sizeof(arr_int[0]));
    printf("Para array de floats:\n");
    min_index(arr_float, sizeof(float), sizeof(arr_float) / sizeof(arr_float[0]));
    printf("Para array de doubles:\n");
    min_index(arr_double, sizeof(double), sizeof(arr_double) / sizeof(arr_double[0]));

// FUNCIÓN 6
    printf("Testing swap:\n");
    int32_t a = 5, b = 10;
    swap(&a, &b, sizeof(int32_t));
    printf("Después del swap: a = %d, b = %d\n", a, b);
    float x = 1.5f, y = 2.5f;
    swap(&x, &y, sizeof(float));
    printf("Después del swap: x = %.2f, y = %.2f\n", x, y);
    double m = 3.14, n = 2.71;
    swap(&m, &n, sizeof(double));
    printf("Después del swap: m = %.2lf, n = %.2lf\n", m, n);

// FUNCIÓN 7
    char str[] = "Hola, buenas tardes";
    print_reverse_string(str, sizeof(char), strlen(str));
    

// FALTA DAYS_LEFT

    
// FUNCIÓN 9
    char string[] = "Ejemplo para contar vocales";
    int num_vocales = vocales(string);
    printf("Número de vocales en la cadena: %d\n", num_vocales);
    
    return 0;
}
