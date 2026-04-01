#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// Definir variables globales y constantes
 
typedef struct {
    int32_t a; //coeficiente cuadratico 
    int32_t b; //coeficiente lineal
    int32_t c; //termino independiente
   
} coeff_t;

typedef struct {
    int32_t real1; //parte real de la primera raiz
    int32_t imag1; //parte imaginaria de la primera raiz
    int32_t real2; //parte real de la segunda raiz
    int32_t imag2; //parte imaginaria de la segunda raiz
    bool complex; //true si las raices son complejas o reales;
} root_t;

typedef struct {
    int32_t real; //parte real 
    int32_t imag; //parte imaginaria 
} complex_t;

typedef struct {
    int8_t day; //(1-31)
    int8_t month; // (1-12)
    int16_t year; // (e.g., 2024)
} date_t;

typedef struct {
    int16_t ** data; //puntero a la matriz de valores
    size_t rows; // numero de filas
    size_t cols; // numero de columnas
} matriz_t;

// Declarar funciones globales

void init_lab(void);

root_t *eq_solver(coeff_t *coeficientes);

int string_copy(char *source, char *destination);

void max_index(void *array, size_t data_type, size_t array_size);

void min_index(void *array, size_t data_type, size_t array_size);

int swap(void *elem_1, void *elem_2, size_t data_type);

void print_reverse_array(void *array, size_t data_type, size_t array_size);

int days_left(date_t start, date_t finish);
#endif // GLOBAL_H
