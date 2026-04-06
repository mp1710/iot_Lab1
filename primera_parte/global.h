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

// Declaracion de funciones 

//FUNCION 1
void init_lab(void);

//FUNCION 2
root_t *eq_solver(coeff_t *coeficientes);

//FUNCION 3
int32_t bin2dec(char *binary, bool sign);

//FUNCION 4
void print_reverse_array(void *array, size_t data_type, size_t array_size);

//FUNCION 5 
void max_index(void *array, size_t data_type, size_t array_size);

//FUNCION 6
void min_index(void *array, size_t data_type, size_t array_size);

//FUNCION 7
matriz_t* matrix_sub(matriz_t A, matriz_t B);

//FUNCION 8
int swap(void *elem_1, void *elem_2, size_t data_type);

//FUNCION 9
int consonantes(char *string);

//FUNCION 10
int vocales(char *string);

//FUNCION 11
char* reverse_string(char *string);

//FUNCION 12
int32_t string_length(char *string);

//FUNCION 13
int32_t string_words(char *string);

//FUNCION 14
int string_copy(char *source, char *destination);

//FUNCION 15
int find_in_string(char *haystack, char *needle);

//FUNCION 16
void string_to_caps(char *string);

//FUNCION 17
void string_to_min(char *string);

//FUNCION 18
complex_t* sum(complex_t a, complex_t b);

//FUNCION 19
complex_t* prod(complex_t a, complex_t b);

//FUNCION 20
int days_left(date_t start, date_t finish);


#endif // GLOBAL_H
