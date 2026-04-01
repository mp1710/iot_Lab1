#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "global.h"

void init_lab(void) {
    printf("Angelo Gauthier\n");
    printf("Pilar Martinez\n");
    printf("Ignacio Negri\n");
}

root_t *eq_solver(coeff_t *coeficientes) {
    double a = coeficientes->a;
    double b = coeficientes->b;
    double c = coeficientes->c;

    double discriminante = b * b - 4 * a * c;
    root_t *result = malloc(sizeof(root_t));
    if (result == NULL) {
    return NULL;
    }
    // Como result no es struct, es una direccion se accede con ->
    if (discriminante > 0) {
        result -> real1 = (-b + sqrt(discriminante)) / (2 * a);
        result -> imag1 = 0;
        result -> real2 = (-b - sqrt(discriminante)) / (2 * a);
        result -> imag2 = 0;
        result -> complex = false;
    } else if (discriminante == 0) {
        result -> real1 = -b / (2 * a);
        result -> imag1 = 0;
        result -> real2 = -b / (2 * a);
        result -> imag2 = 0;
        result -> complex = false;
    } else {
        result -> real1 = -b / (2 * a);
        result -> imag1 = sqrt(-discriminante) / (2 * a);
        result -> real2 = -b / (2 * a);
        result -> imag2 = -sqrt(-discriminante) / (2 * a);
        result -> complex = true;
    }
    return result;
}

int string_copy(char *source, char *destination) {
    while (*source) {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0'; // Agregar el carácter nulo al final de la cadena
    return 0; // Retornar la dirección del destino
}

void max_index(void *array,size_t data_type,size_t array_size) {
    if (data_type == sizeof(int32_t)) {
        int32_t *arr = (int32_t *)array;
        int32_t max = arr[0];
        size_t max_index = 0;
        for (size_t i = 1; i < array_size; i++) {
            if (arr[i] > max) {
                max = arr[i];
                max_index = i;
            }
        }
        printf("El índice del valor máximo es: %zu\n", max_index);
        printf("El valor máximo es: %d\n", max);
    } else if (data_type == sizeof(float)) {
        float *arr = (float *)array;
        float max = arr[0];
        size_t max_index = 0;
        for (size_t i = 1; i < array_size; i++) {
            if (arr[i] > max) {
                max = arr[i];
                max_index = i;
            }
        }
        printf("El índice del valor máximo es: %zu\n", max_index);
        printf("El valor máximo es: %f\n", max);
    } else if (data_type == sizeof(double)) {
        double *arr = (double *)array;
        double max = arr[0];
        size_t max_index = 0;
        for (size_t i = 1; i < array_size; i++) {
            if (arr[i] > max) {
                max = arr[i];
                max_index = i;
            }
        }
        printf("El índice del valor máximo es: %zu\n", max_index);
        printf("El valor máximo es: %lf\n", max);
    } else {
        printf("Tipo de dato no soportado.\n");
    }
}

void min_index(void *array,size_t data_type,size_t array_size) {
    if (data_type == sizeof(int32_t)) {
        int32_t *arr = (int32_t *)array;
        int32_t min = arr[0];
        size_t min_index = 0;
        for (size_t i = 1; i < array_size; i++) {
            if (arr[i] < min) {
                min = arr[i];
                min_index = i;
            }
        }
        printf("El índice del valor mínimo es: %zu\n", min_index);
        printf("El valor mínimo es: %d\n", min);
    } else if (data_type == sizeof(float)) {
        float *arr = (float *)array;
        float min = arr[0];
        size_t min_index = 0;
        for (size_t i = 1; i < array_size; i++) {
            if (arr[i] < min) {
                min = arr[i];
                min_index = i;
            }
        }
        printf("El índice del valor mínimo es: %zu\n", min_index);
        printf("El valor mínimo es: %f\n", min);
    } else if (data_type == sizeof(double)) {
        double *arr = (double *)array;
        double min = arr[0];
        size_t min_index = 0;
        for (size_t i = 1; i < array_size; i++) {
            if (arr[i] < min) {
                min = arr[i];
                min_index = i;
            }
        }
        printf("El índice del valor mínimo es: %zu\n", min_index);
        printf("El valor mínimo es: %lf\n", min);
    } else {
        printf("Tipo de dato no soportado.\n");
    }
}

int swap(void *elem_1, void *elem_2, size_t data_type) {
    if (data_type == sizeof(int32_t)) {
        int32_t aux = *(int32_t *)elem_2;
        *(int32_t *)elem_1 = *(int32_t *)elem_2;
        *(int32_t *)elem_2 = aux;
        return 0;
    } else if (data_type == sizeof(float)) {
        float aux = *(float *)elem_1;
        *(float *)elem_1 = *(float *)elem_2;
        *(float *)elem_2 = aux;
        return 0;
    } else if (data_type == sizeof(double)) {
        double aux = *(double *)elem_1;
        *(double *)elem_1 = *(double *)elem_2;
        *(double *)elem_2 = aux;
        return 0;
    } else {
        printf("Tipo de dato no soportado.\n");
        return -1;
    }
}
void print_reverse_string(void *array, size_t data_type, size_t array_size) {
    if (data_type == sizeof(char)) {
        char *arr = (char *)array;
        for (size_t i = array_size - 1; i < array_size; i--) {
            printf("%c", arr[i]);
        }
        printf("\n");
    } else {
        printf("Tipo de dato no soportado.\n");
    }
}

int days_left(date_t start, date_t finish) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;

    if (start.year == finish.year) {
        if (start.month == finish.month) {
            return finish.day - start.day;
        } else {
            days += days_in_month[start.month - 1] - start.day;
            for (int i = start.month; i < finish.month - 1; i++) {
                days += days_in_month[i];
            }
            days += finish.day;
        }
    } else {
        days += days_in_month[start.month - 1] - start.day;
        for (int i = start.month; i < 12; i++) {
            days += days_in_month[i];
        }
        for (int i = 0; i < finish.month - 1; i++) {
            days += days_in_month[i];
        }
        days += finish.day;
    }

    return days;
}

// Número de vocales en una cadena
int vocales(char *string) {
    int num_vocales = 0;
    char *p = string; // Puntero para recorrer la cadena
    while (*p != '\0') {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
            num_vocales++;
        }
        p++;
    }
    return num_vocales;
}

// Número de consonantes en una cadena
int consonantes(char *string) {
    int num_consonantes = 0;
    char *p = string; // Puntero para recorrer la cadena
    while (*p != '\0') {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) { // Mientras que el string sean letras, no símbolos
            if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u' &&
                *p != 'A' && *p != 'E' && *p != 'I' && *p != 'O' && *p != 'U') {
                num_consonantes++;
            }
        }
        p++;
    }
    return num_consonantes;
}

//Convertir string a mayúsculas
void string_to_caps(char *string) {
    for (size_t i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') { // Si el string es una letra minúscula resta 32
            string[i] = string[i] - 32;      // Las letras son código ascii, representan un número, 32 representa el número de
        }                                       // la distancia entre una letra minúscula y su respectiva letra mayúscula
    }
    printf("String en mayúsculas: %s\n", string);
}

//Convertir string a minúsculas
void string_to_min(char *string) {
    for (size_t i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') { // Si el string es una letra mayúscula suma 32
            string[i] = string[i] + 32;
        }
    }
    printf("String en minúsculas: %s\n", string);
}
