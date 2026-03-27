#include <stdio.h>
#include <string.h>

//Número de vocales en una cadena
int vocales(char *string) {
    int num_vocales = 0;
    char *p = string; // puntero para recorrer la cadena
    while (*p != '\0') {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
            num_vocales++;
        }
        p++;
    }
    return num_vocales;
}

//Número de consonantes en una cadena
int consonantes(char *string) {
    int num_consonantes = 0;
    char *p = string; // puntero para recorrer la cadena
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

//Convertir string a mayúsculas
void convertir_a_mayusculas(char *string) {
    for (size_t i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = string[i] - 32;
        }
    }

}

