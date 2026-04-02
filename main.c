#include <stdio.h>
#include <stdlib.h>
#include "global.h"

int main(void) {

// FUNCION 1
    printf("Test init_lab:\n");
    init_lab();
    printf("\n"); // agrego espacio entre funciones 
// FUNCION 2
    printf("Test eq_solver:\n");
    // Creo coeficientes para la ecuacion x^2 - 5x + 6 = 0, que tiene raices reales y distintas (2 y 3)
    coeff_t coef = {1, -5, 6};
    // Llamo a eq_solver con los coeficientes y guardo el resultado en un puntero a root_t
    root_t *result = eq_solver(&coef);

    if (result != NULL) {
        printf("Raiz 1: %d + %di\n", result->real1, result->imag1);
        printf("Raiz 2: %d + %di\n", result->real2, result->imag2);
        printf("Compleja: %s\n", result->complex ? "true" : "false");

        free(result);
        printf("\n");
    }
// FUNCION 3
    printf("Test string_copy:\n");
    char source[] = "Prueba de string copy";
    char destination[20];
    string_copy(source, destination);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    printf("\n");

// FUNCION 4
    printf("Test max_index:\n");
    int32_t arr_int[] = {1, 3, 5, 2, 4};
    size_t size_int = sizeof(arr_int) / sizeof(arr_int[0]);
    max_index(arr_int, sizeof(int32_t), size_int);
    printf("\n");
    
    return 0;
}
