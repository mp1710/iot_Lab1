#include "global.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

matriz_t matrix_sub(matriz_t A, matriz_t B) {
    matriz_t C;
    if (A.rows != B.rows || A.cols != B.cols) {
        printf("Las matrices deben tener las mismas dimensiones.\n");
        C.data = NULL;
        C.rows = 0;
        C.cols = 0;
        return C;
    }
    C.rows = A.rows;
    C.cols = A.cols;
    C.data = malloc(C.rows * sizeof(int*));
    for (int i = 0; i < C.rows; i++) {
        C.data[i] = malloc(C.cols * sizeof(int));
    }

    // Resta
    for (int i = 0; i < C.rows; i++) {
        for (int j = 0; j < C.cols; j++) {
            C.data[i][j] = A.data[i][j] - B.data[i][j];
            printf("%d ", C.data[i][j]);
        }
        printf("\n");
    }
    return C;
}

int32_L string_length(char *string) {
    if (string == NULL) {
        return -1; // Retorna -1 si el puntero es NULL
    }

    int32_L length = 0;

    while (string[length] != '\0' && length <= 20) { // Límite arbitrario de 20 caracteres para evitar desbordamiento
        if (length >= 20) {
            return -1; // Retorna -1 si se supera el límite de 20 caracteres sin encontrar el carácter nulo
        }
        length++;
    }

    return length;
}

int32_L string_words(char *string) {
    if (string == NULL) return -1;

    int32_L words = 0;
    int32_L length = 0;
    int en_word = 0;

    while (length < 50 && string[length] != '\0') {

        if (string[length] != ' ' && en_word == 0) {
            words++;       // empieza una palabra nueva
            en_word = 1;
        } else if (string[length] == ' ') {
            en_word = 0;   // saliste de palabra
        }

        length++;
    }

    if (length == 50 && string[length] != '\0') {   // si llegaste al límite sin '\0'
        return -1;
    }

    return words;
}

complex_t sum(complex_t a, complex_t b) {
    complex_t resultado;
    resultado.real = a.real + b.real;
    resultado.imag = a.imag + b.imag;
    return resultado;
}

complex_t prod(complex_t a, complex_t b) {
    complex_t resultado;
    resultado.real = a.real * b.real - a.imag * b.imag;
    resultado.imag = a.real * b.imag + a.imag * b.real;
    return resultado;
}
