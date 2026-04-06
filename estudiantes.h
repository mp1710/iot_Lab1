#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H
#include <stdio.h>
#include <stdint.h>


typedef struct estudiantes{

    char nombre[64];
    char apellido[64];
    uint32_t ci;
    uint8_t grado;
    float promedio;
    struct estudiantes *siguiente;

} estudiante_t;

//La variabale cabeza es un puntero a un puntero a estudiante_t

//FUNCION 1
void agregar_estudiante(estudiante_t **cabeza, char nombre[], char apellido[], uint32_t ci, int grado, float promedio);

//FUNCION 2
void eliminar_estudiante(estudiante_t **cabeza, uint32_t ci);

//FUNCION 3
void mostrar_lista(estudiante_t *cabeza);

//FUNCION 4
void mostrar_estudiante_nombre(estudiante_t *cabeza, const char *nombre);

//FUNCION 5
void mostrar_estudiante_ci(estudiante_t *cabeza, uint32_t ci);

//FUNCION 6
void ordenar_por_apellido(estudiante_t *cabeza);

//FUNCION 7
void ordenar_por_ci(estudiante_t *cabeza);

//FUNCION 8
void calificacion(estudiante_t *estudiante);

#endif // ESTUDIANTES_H