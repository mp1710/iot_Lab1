#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H
#include <stdio.h>
#include <stdint.h>

typedef struct {

    char nombre[64];
    char apellido[64];
    uint32_t ci;
    uint8_t grado;
    float promedio;
   
} estudiante_t;

typedef struct nodo{
    estudiante_t dato;
    struct nodo *siguiente;
} nodo_t;

// Funciones a implementar? Puede faltar la de ordenar por ci/nombre

//agregar_estudiante
void agregar_estudiante(nodo_t **cabeza, estudiante_t nuevo_estudiante);
//mostrar_lista
void mostrar_lista(nodo_t *cabeza);
//mostrar_estudiante
void mostrar_estudiante(estudiante_t estudiante);
//eliminar_estudiante
void eliminar_estudiante(nodo_t **cabeza, uint32_t ci);
//buscar_estudiante_nombre
estudiante_t* buscar_estudiante_nombre(nodo_t *cabeza, const char *nombre);
//buscar_estudiante_apellido
estudiante_t* buscar_estudiante_apellido(nodo_t *cabeza, const char *apellido);
//buscar_estudiante_ci
estudiante_t* buscar_estudiante_ci(nodo_t *cabeza, uint32_t ci);
//calcular_calificacion
float calcular_calificacion(estudiante_t estudiante);
//liberar_lista
void liberar_lista(nodo_t **cabeza);

#endif // ESTUDIANTES_H
