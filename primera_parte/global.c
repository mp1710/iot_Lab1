#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "global.h"
//Esta funcion imprime los nombres del grupo usando printf, no retorna nada ni utiliza parametros
void init_lab(void) {
    printf("Angelo Gauthier\n");
    printf("Pilar Martinez\n");
    printf("Ignacio Negri\n");
}

// Esta funcion calcula las raices de una ecuacion cuadratica usando la formula general.
// Se calcula el discriminante para determinar si son raices complejas o reales, 
// se almacenan en una struct y se retorna ese resultado. 
// *coefficientes: es un puntero a una estructura que tiene los valores de a, b y c (coef. de la ecuacion).
// *result: es un puntero a una estructura tipo root_t que tiene las raices calculadas. Si hay un error en 
// la reserva de la memoria devuelve NULL. 
// La memoria devuelta se libera en el main con free()
root_t *eq_solver(coeff_t *coeficientes) {
    // Obtengo a, b y c accediendo con el puntero por eso se usa (->). 
    double a = coeficientes->a;
    double b = coeficientes->b;
    double c = coeficientes->c;

    double discriminante = b * b - 4 * a * c;
    root_t *result = malloc(sizeof(root_t));
    if (result == NULL) {
    return NULL;
    }
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

// Esta funcion recibe un numero binario (como cadena de caracteres), y lo convierte a su valor decimal.
// Ademas puede interpretar si el numero es con signo (se realiza complemento a 2) o sin signo.
// *binary: el numero binario a convertir a decimal
// sign: boolean que indica si tiene bit de signo o no
// se usan variables locales como decimal (para almacenar el numero decimal y retornarlo) y lengh (dice la medida del numero binario 
// lo que permite recorrerlo).
int32_t bin2dec(char *binary, bool sign) {
    int32_t decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        if (binary[length - 1 - i] == '1') {
            decimal += (1<< i); // se le suma 2^i
        }
    }
    if (sign && binary[0] == '1') {
        decimal -= (1 << length); // se le resta 2^length
    }
    return decimal;
}

// Esta funcion imprime los elementos de un array en orden inverso. 
// Recibe un puntero al array, el tamaño del tipo de dato y la cantidad de elementos del array.
// No retorna nada, solo imprime el array al revés.
// *array: puntero al array a imprimir
// data_type: tamaño del tipo de dato
// array_size: cantidad de elementos del array
void print_reverse_array(void *array, size_t data_type, size_t array_size) {
    if (array == NULL || array_size == 0) {
        printf("Array invalido.\n");
        return;
    }
    
    if (data_type == sizeof(char)) {
        char *arr = (char *)array;
        for (size_t i = array_size; i > 0; i--) {
            printf("%c", arr[i-1]);
        }
        printf("\n");
    } 
    else if (data_type == sizeof(int32_t)) {
        int32_t *arr = (int32_t *)array;
        for (size_t i = array_size; i > 0; i--) {
            printf("%d", arr[i-1]);
        }
        printf("\n");
    } 
    else if (data_type == sizeof(float)) {
        float *arr = (float *)array;
        for (size_t i = array_size; i > 0; i--) {
            printf("%f", arr[i-1]);
        }
        printf("\n");
    }
    else if (data_type == sizeof(double)) {
        double *arr = (double *)array;
        for (size_t i = array_size; i > 0; i--) {
            printf("%lf", arr[i-1]);
        }
        printf("\n");
    }
    else {
        printf("Tipo de dato no soportado.\n");
    }
}

// Esta funcion encuentra el indice del valor máximo en un array.
// Recibe un puntero al array, el tamaño del tipo de dato y la cantidad de elementos del array.
// No retorna nada, solo imprime el indice y el valor máximo encontrado.
// *array: puntero al array a analizar
// data_type: tamaño del tipo de dato
// array_size: cantidad de elementos del array
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

// Esta funcion encuentra el indice del valor mínimo en un array (idem a la anterior).
// Recibe un puntero al array, el tamaño del tipo de dato y la cantidad de elementos del array.
// No retorna nada, solo imprime el indice y el valor mínimo encontrado.
// *array: puntero al array a analizar
// data_type: tamaño del tipo de dato
// array_size: cantidad de elementos del array
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

// Esta funcion realiza la resta de dos matrices A y B, y retorna una nueva matriz C con el resultado.
// Recibe dos matrices A y B, que son estructuras que contienen un puntero a una matriz de valores, 
// el numero de filas y el numero de columnas.
// Retorna un puntero a una nueva matriz C con el resultado de la resta, 
//o NULL si hay un error en la reserva de memoria.
// Tiene una limitacion y es que A y B deben tener las mismas dimensiones para poder realizar la resta,
// si no se retorna una matriz con data = NULL, rows = 0 y cols = 0.
matriz_t* matrix_sub(matriz_t A, matriz_t B) {
    matriz_t *C = malloc(sizeof(matriz_t));
    if (C == NULL) {
        printf("Error al asignar memoria para la matriz resultante.\n");
        return NULL;
    }
    if (A.rows != B.rows || A.cols != B.cols) {
        printf("Las matrices deben tener las mismas dimensiones.\n");
        C->data = NULL;
        C->rows = 0;
        C->cols = 0;
        return C;
    }
    C->rows = A.rows;
    C->cols = A.cols;
    C->data = malloc(C->rows * sizeof(int*));
    for (int i = 0; i < C->rows; i++) {
        C->data[i] = malloc(C->cols * sizeof(int));
    }

    // Resta
    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            C->data[i][j] = A.data[i][j] - B.data[i][j];
            printf("%d ", C->data[i][j]);
        }
        printf("\n");
    }
    return C;
}

// Esta funcion intercambia los valores de dos variables de cualquier tipo de dato (int, float o double).
// Recibe dos punteros a las variables a intercambiar y el tamaño del tipo de dato (data_type).
// Retorna 0 si el swap fue realizado, o -1 si el tipo de dato no es soportado.
// *elem_1: puntero a la primera variable a intercambiar
// *elem_2: puntero a la segunda variable a intercambiar
// data_type: tamaño del tipo de dato (sizeof(int32_t), sizeof(float) o sizeof(double))
int swap(void *elem_1, void *elem_2, size_t data_type) {
    if (data_type == sizeof(int32_t)) {
        int32_t aux = *(int32_t *)elem_1;
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

// Esta funcion cuenta el numero de consonantes en una cadena de caracteres. 
// Se cuentan a medida que sea una letra (mayuscula o minuscula) y no sea una vocal o simbolo.
// Recibe un puntero a la cadena de caracteres a analizar, y retorna el numero de consonantes encontradas.
// *string: puntero a la cadena de caracteres a analizar
int consonantes(char *string) {
    int num_consonantes = 0;
    char *p = string; 
    while (*p != '\0') {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) { 
            if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u' &&
                *p != 'A' && *p != 'E' && *p != 'I' && *p != 'O' && *p != 'U') {
                num_consonantes++;
            }
        }
        p++;
    }
    return num_consonantes;
}

// Cuenta la cantidad de vocales en un string.
// Recibe un puntero a char (string).
// Retorna un int con la cantidad de vocales encontradas.
int vocales(char *string) {
    int num_vocales = 0;
    char *p = string;
    while (*p != '\0') {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
            num_vocales++;
        }
        p++;
    }
    return num_vocales;
}

// Esta funcion invierte un string.
// Recibe un puntero a char (string).
// Retorna un puntero a un nuevo string invertido (usa memoria dinamica, puede retornar NULL).
char* reverse_string(char *string) {
    int length = strlen(string);
    char *reversed = malloc((length + 1) * sizeof(char));
    if (reversed == NULL) {
        return NULL; 
    }
    for (int i = 0; i < length; i++) {
        reversed[i] = string[length - 1 - i];
    }
    reversed[length] = '\0';
    return reversed;
}

// Esta funcion calcula la longitud de un string con limite arbitrario (20).
// Recibe un puntero a char (string).
// Retorna la longitud (int32_t). Devuelve -1 si es NULL o supera 20 caracteres.
int32_t string_length(char *string) {
    if (string == NULL) {
        return -1; // Retorna -1 si el puntero es NULL
    }

    int32_t length = 0;

    while (string[length] != '\0' && length <= 20) { 
        if (length >= 20) {
            return -1; 
        }
        length++;
    }

    return length;
}

// Esta funcion cuenta la cantidad de palabras en un string. Se pone un limite de 50 caracteres para el string, de manera arbitraria.
// Recibe un puntero a char (string).
// Retorna el numero de palabras (int32_t). Devuelve -1 si es NULL o supera 50 caracteres.
int32_t string_words(char *string) {
    if (string == NULL) return -1;

    int32_t words = 0;
    int32_t length = 0;
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

    if (length == 50 && string[length] != '\0') {
        return -1;
    }

    return words;
}

// Esta funcion copia un string en otro,
// Recibe un string origen (char*) y destino (char*).
// Retorna 0 si la copia se realiza correctamente.
int string_copy(char *source, char *destination) {
    while (*source) {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
    return 0;
}

// Esta funcion busca una subcadena dentro de otra, recorriendo los str con punteros y comparando.
// Recibe la string principal (haystack) y subcadena (needle).
// Retorna el indice de la primera aparicion o -1 si no se encuentra.
int find_in_string(char *haystack, char *needle) {
    char *p_haystack = haystack;
    char *p_needle = needle;

    while (*p_haystack) {
        if (*p_haystack == *p_needle) {
            char *temp_haystack = p_haystack;
            char *temp_needle = p_needle;

            while (*temp_needle && *temp_haystack && *temp_haystack == *temp_needle) {
                temp_haystack++;
                temp_needle++;
            }

            if (*temp_needle == '\0') {
                return p_haystack - haystack; // Retorna el índice de la primera aparición
            }
        }
        p_haystack++;
    }
    return -1; // Retorna -1 si no se encuentra la subcadena
}

// Esta funcion convierte un string a minusculas, restando 32 al valor del char si este corresponde a una minuscula.
// Recibe un puntero a char (string).
// No retorna nada, solo modifica el string original.
void string_to_caps(char *string) {
    for (size_t i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = string[i] - 32;
        }
    }
    printf("String en mayúsculas: %s\n", string);
}

// Esta funcion convierte un string a minusculas, sumando 32 al valor del char si este corresponde a una mayuscula.
// Recibe un puntero a char (string).
// No retorna nada, solo modifica el string original.
void string_to_min(char *string) {
    for (size_t i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + 32;
        }
    }
    printf("String en minúsculas: %s\n", string);
}

// Esta funcion suma dos numeros complejos, sumando parte real con parte real, e parte imaginaria con parte imaginaria.
// Recibe dos estructuras complex_t.
// Retorna un puntero a complex_t con el resultado (usa memoria dinamica, puede ser NULL). 
complex_t* sum(complex_t a, complex_t b) {
    complex_t *resultado = malloc(sizeof(complex_t));
    if (resultado == NULL) {
        printf("Error al asignar memoria para el resultado de la suma.\n");
        return NULL;
    }
    resultado->real = a.real + b.real;
    resultado->imag = a.imag + b.imag;
    return resultado;
}

// Esta funcion realiza el producto entre dos numeros complejos, operando con las componentes reales e imaginarias de los numeros, la componenete real del
// resultado depende del producto de las partes reales y el producto de las partes imaginarias (j*j=-1), mientras que la parte imaginaria del resultado
// depende de los productos de partes reales con imaginarias entre los numeros.
// Recibe como parametros dos numeros complejos guadrados en struct, para trabajar con sus componentes independientes, y retorna el resultado
// con sus componentes como un puntero a un struct del mismo tipo (usa memoria dinamica, puede ser NULL).
complex_t* prod(complex_t a, complex_t b) {
    complex_t *resultado = malloc(sizeof(complex_t));
    if (resultado == NULL) {
        printf("Error al asignar memoria para el resultado del producto.\n");
        return NULL;
    }
    resultado->real = a.real * b.real - a.imag * b.imag;
    resultado->imag = a.real * b.imag + a.imag * b.real;
    return resultado;
}

// Esta funcion calcula los dias transcurridos entre dos fechas.
// Convierte ambas fechas a dias totales desde el año 1 y luego las resta.
// Recibe dos estructuras date_t (start y finish).
// Retorna un int con la diferencia en dias entre la fecha final y la inicial.
int days_left(date_t start, date_t finish) {

    int days_start = 0;
    int days_finish = 0;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int y = 1; y < start.year; y++) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            days_start += 366;
        } else {
            days_start += 365;
        }
    }

    if ((start.year % 4 == 0 && start.year % 100 != 0) || (start.year % 400 == 0)) {
        days_in_month[1] = 29;
    }

    for (int m = 1; m < start.month; m++) {
        days_start += days_in_month[m - 1];
    }

    days_start += start.day;

    int days_in_month_finish[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int y = 1; y < finish.year; y++) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            days_finish += 366;
        } else {
            days_finish += 365;
        }
    }

    if ((finish.year % 4 == 0 && finish.year % 100 != 0) || (finish.year % 400 == 0)) {
        days_in_month_finish[1] = 29;
    }

    for (int m = 1; m < finish.month; m++) {
        days_finish += days_in_month_finish[m - 1];
    }

    days_finish += finish.day;

    return days_finish - days_start;
}

    }

    return days;
}
