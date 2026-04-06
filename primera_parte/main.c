#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "global.h"

int main(void) {

// FUNCIÓN 1 init_lab
    printf("Testing init_lab:\n");
    init_lab();
    printf("\n");

// FUNCIÓN 2 eq_solver
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

// FUNCIÓN 3 bin2dec
    printf("Testing bin2dec:\n");
    char binary[] = "1101"; // Representa el número 13 en binario
    int32_t decimal = bin2dec(binary, false);
    printf("El número decimal de %s es: %d\n", binary, decimal);
    printf("\n");

// FUNCIÓN 4 print_reverse_array
    printf("Testing print_reverse_array:\n");
    char str[] = "Prueba de print_reverse_array en LABORATORIO 1";
    print_reverse_array(str, sizeof(char), strlen(str));
    printf("\n");

// FUNCIÓN 5 max_index
    printf("Testing max_index:\n");
    int32_t arr_int[] = {1, 3, 5, 2, 4};
    size_t size_int = sizeof(arr_int) / sizeof(arr_int[0]);
    max_index(arr_int, sizeof(int32_t), size_int);
    printf("\n");

// FUNCIÓN 6 min_index
    printf("Testing min_index:\n");
    int32_t arr_int1[] = {5, 1, 9, 2, 5};
    float arr_float[] = {3.5, 2.1, 4.6, 1.1, 3.3};
    double arr_double[] = {2.5, 1.2, 3.8, 2.7, 0.9};
    printf("Para array de enteros:\n");
    min_index(arr_int1, sizeof(int32_t), sizeof(arr_int1) / sizeof(arr_int1[0]));
    printf("Para array de floats:\n");
    min_index(arr_float, sizeof(float), sizeof(arr_float) / sizeof(arr_float[0]));
    printf("Para array de doubles:\n");
    min_index(arr_double, sizeof(double), sizeof(arr_double) / sizeof(arr_double[0]));
    printf("\n");

//FUNCIÓN 7 matriz_sub
    printf("Testing matrix_sub:\n");
    matriz_t A, B;
    A.rows = 2;
    A.cols = 2;
    A.data = malloc(A.rows * sizeof(int16_t *));
    for (size_t i = 0; i < A.rows; i++) {
        A.data[i] = malloc(A.cols * sizeof(int16_t));
    }
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;

    B.rows = 2;
    B.cols = 2;
    B.data = malloc(B.rows * sizeof(int16_t *));
    for (size_t i = 0; i < B.rows; i++) {
        B.data[i] = malloc(B.cols * sizeof(int16_t));
    }
    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;

    matriz_t *C = matrix_sub(A, B);
    if (C != NULL) {
        printf("Resta de matrices:\n");
        for (size_t i = 0; i < C->rows; i++) {
            for (size_t j = 0; j < C->cols; j++) {
                printf("%d ", C->data[i][j]);
            }
            printf("\n");
        }
        // Liberar memoria de la matriz resultante
        for (size_t i = 0; i < C->rows; i++) {
            free(C->data[i]);
        }
        free(C->data);
        free(C);
    }
    // Liberar memoria de las matrices A y B
    for (size_t i = 0; i < A.rows; i++) {
        free(A.data[i]);
    }
    free(A.data);
    for (size_t i = 0; i < B.rows; i++) {
        free(B.data[i]);
    }
    free(B.data);
    printf("\n");

// FUNCIÓN 8 swap
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
    printf("\n");

// FUNCIÓN 9 consonantes
    printf("Testing consonantes:\n");
    char string1[] = "Contar consonantes en la cadena de LABORATORIO 1";
    int num_consonantes = consonantes(string1);
    printf("Número de consonantes en la cadena: %d\n", num_consonantes);
    printf("\n");
    
// FUNCIÓN 10 vocales
    printf("Testing vocales:\n");
    char string_vocales[] = "Contar vocales en la cadena de LABORATORIO 1";
    int num_vocales = vocales(string_vocales);
    printf("Número de vocales en la cadena: %d\n", num_vocales);
    printf("\n");
    
// FUNCIÓN 11 reverse_string
    printf("Testing reverse_string:\n");
    char str1[] = "Imprimir esta cadenena al revés!";
    char *reversed = reverse_string(str1);
    if (reversed != NULL) {
        printf("Cadena original: %s\n", str1);
        printf("Cadena invertida: %s\n", reversed);
        free(reversed); // Liberar la memoria asignada para la cadena invertida
    } else {
        printf("Error al invertir la cadena.\n");
    }
    printf("\n");    

// FUNCIÓN 12 string_length
    printf("Testing string_length:\n");
    char str2[] = "Cual sera la longitud de esta cadena?";
    int32_t length = string_length(str2);
    if (length != -1) {
        printf("La longitud de la cadena es: %d\n", length);
    } else {
        printf("Error al calcular la longitud de la cadena.\n");
    }
    printf("\n");
    
// FUNCIÓN 13 string_words
    printf("Testing string_words:\n");
    char str3[] = "Cuantas palabras habra en esta cadena de texto?";
    int32_t words = string_words(str3);
    if (words != -1) {
        printf("El número de palabras en la cadena es: %d\n", words);
    } else {
        printf("Error al contar el número de palabras en la cadena.\n");
    }
    printf("\n");

// FUNCIÓN 14 string_copy
    printf("Testing string_copy:\n");
    char source[] = "Probando copiar esta cadena en LABORATORIO 1";
    char destination[64];
    string_copy(source, destination);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    printf("\n");

// FUNCIÓN 15 find_in_string
    printf("Testing find_in_string:\n");
    char haystack[] = "Buscar esta subcadena secreta en la cadena principal";
    char needle[] = "secreta";
    int index = find_in_string(haystack, needle);
    if (index != -1) {
        printf("La subcadena '%s' se encuentra en el índice: %d\n", needle, index);
    } else {
        printf("La subcadena '%s' no se encontró en la cadena principal.\n", needle);
    }
    printf("\n");

// FUNCIÓN 16 string_to_caps
    printf("Testing string_to_caps:\n");
    char string2[] = "ConVErtir a mayuSculAs";
    string_to_caps(string2);
    printf("\n");

// FUNCIÓN 17 string_to_min
    printf("Testing string_to_min:\n");
    char string_min[] = "CONveRtir a miNUscUlAS";
    string_to_min(string_min);
    printf("\n");
 
// FUNCIÓN 18 sum
    printf("Testing sum:\n");
    complex_t complex_a = {2, 3}; // 2 + 3i
    complex_t complex_b = {4, 5}; // 4 + 5i
    complex_t *result_sum = sum(complex_a, complex_b);
    if (result_sum != NULL) {
        printf("Suma: %d + %di\n", result_sum->real, result_sum->imag);
        free(result_sum); // Liberar la memoria asignada para el resultado
    } else {
        printf("Error al calcular la suma de los números complejos.\n");
    }
    printf("\n");
    
// FUNCIÓN 19 prod
    printf("Testing prod:\n");
    complex_t *result_prod = prod(complex_a, complex_b);
    if (result_prod != NULL) {
        printf("Producto: %d + %di\n", result_prod->real, result_prod->imag);
        free(result_prod); // Liberar la memoria asignada para el resultado
    } else {
        printf("Error al calcular el producto de los números complejos.\n");
    }
    printf("\n");

// FUNCIÓN 20 days_left
    printf("Testing days_left:\n");
    date_t start = {1, 1, 2024}; // 1 de enero de 2024
    date_t finish = {31, 12, 2024}; // 31 de diciembre de 2024
    int days = days_left(start, finish);
    if (days != -1) {
        printf("Días restantes entre %d/%d/%d y %d/%d/%d: %d\n", start.day, start.month, start.year, finish.day, finish.month, finish.year, days);
    } else {
        printf("Error al calcular los días restantes entre las fechas.\n");
    }
    printf("\n"); 

    return 0;    
}
