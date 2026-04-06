#include "estudiantes.h"
#include <stdlib.h>
#include <string.h>


void agregar_estudiante(estudiante_t **cabeza,
                        char nombre[64],
                        char apellido[64],
                        uint32_t ci,
                        int grado,
                        float promedio) {

    // Crear nodo 
    estudiante_t *nuevo = malloc(sizeof(estudiante_t));
    if (nuevo == NULL) return;

    // Cargar datos
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->apellido, apellido);
    nuevo->ci = ci;
    nuevo->grado = grado;
    nuevo->promedio = promedio;
    nuevo->siguiente = NULL;

// Verificar si ya existe un estudiante con el mismo ci
    estudiante_t *actual = *cabeza;
    while (actual != NULL) {
        if (actual->ci == ci) {
            printf("Error: Estudiante con CI %u ya existe.\n", ci);
            free(nuevo);
            return;
        }
        actual = actual->siguiente;
    }

    // Insertar al inicio de la lista 
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void eliminar_estudiante(estudiante_t **cabeza, uint32_t ci) {
    if (*cabeza == NULL) return;

    estudiante_t *actual = *cabeza;
    estudiante_t *anterior = NULL;

    while (actual != NULL) {
        if (actual->ci == ci) {
            if (anterior == NULL) {
                // Eliminar el primer nodo
                *cabeza = actual->siguiente;
            } else {
                // Eliminar nodo intermedio o final
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            printf("Estudiante con CI %u eliminado.\n", ci);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    printf("Estudiante con CI %u no encontrado.\n", ci);
}

void mostrar_lista(estudiante_t *cabeza) {
    estudiante_t *actual = cabeza;
    while (actual != NULL) {
        printf("Nombre: %s %s, CI: %u, Grado: %d, Promedio: %.2f\n",
               actual->nombre, actual->apellido, actual->ci,
               actual->grado, actual->promedio);
        actual = actual->siguiente;
    }
}


void mostrar_estudiante_nombre(estudiante_t *cabeza, const char *nombre) {
// Se recorre la lista buscando el estudiante con el nombre especificado    
    estudiante_t *actual = cabeza;
    while (actual != NULL) {
    // Se compara el nombre del estudiante actual con el nombre buscado usando strcmp    
        if (strcmp(actual->nombre, nombre) == 0) {
            printf("Nombre: %s %s, CI: %u, Grado: %d, Promedio: %.2f\n",
                   actual->nombre, actual->apellido, actual->ci,
                   actual->grado, actual->promedio);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Estudiante con nombre %s no encontrado.\n", nombre);
}

void mostrar_estudiante_ci(estudiante_t *cabeza, uint32_t ci) {
    estudiante_t *actual = cabeza;
    while (actual != NULL) {
        if (actual->ci == ci) {
            printf("Nombre: %s %s, CI: %u, Grado: %d, Promedio: %.2f\n",
                   actual->nombre, actual->apellido, actual->ci,
                   actual->grado, actual->promedio);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Estudiante con CI %u no encontrado.\n", ci);
}


void ordenar_por_apellido(estudiante_t *cabeza) {
    if (cabeza == NULL) return;

    int swapped;
    estudiante_t *ptr;

    do {
        swapped = 0;
        ptr = cabeza;

        while (ptr->siguiente != NULL) {

            if (strcmp(ptr->apellido, ptr->siguiente->apellido) > 0) {

                // intercambiar SOLO datos
                char nombre[50], apellido[50];
                int ci, grado;
                float promedio;

                strcpy(nombre, ptr->nombre);
                strcpy(apellido, ptr->apellido);
                ci = ptr->ci;
                grado = ptr->grado;
                promedio = ptr->promedio;

                strcpy(ptr->nombre, ptr->siguiente->nombre);
                strcpy(ptr->apellido, ptr->siguiente->apellido);
                ptr->ci = ptr->siguiente->ci;
                ptr->grado = ptr->siguiente->grado;
                ptr->promedio = ptr->siguiente->promedio;

                strcpy(ptr->siguiente->nombre, nombre);
                strcpy(ptr->siguiente->apellido, apellido);
                ptr->siguiente->ci = ci;
                ptr->siguiente->grado = grado;
                ptr->siguiente->promedio = promedio;

                swapped = 1;
            }

            ptr = ptr->siguiente;
        }

    } while (swapped);
    mostrar_lista(cabeza);
}

void ordenar_por_ci(estudiante_t *cabeza) {
    if (cabeza == NULL) return;

    int swapped;
    estudiante_t *ptr;

    do {
        swapped = 0;
        ptr = cabeza;

        while (ptr->siguiente != NULL) {

            if (ptr->ci > ptr->siguiente->ci) {

                // intercambiar SOLO datos
                char nombre[50], apellido[50];
                int ci, grado;
                float promedio;

                strcpy(nombre, ptr->nombre);
                strcpy(apellido, ptr->apellido);
                ci = ptr->ci;
                grado = ptr->grado;
                promedio = ptr->promedio;

                strcpy(ptr->nombre, ptr->siguiente->nombre);
                strcpy(ptr->apellido, ptr->siguiente->apellido);
                ptr->ci = ptr->siguiente->ci;
                ptr->grado = ptr->siguiente->grado;
                ptr->promedio = ptr->siguiente->promedio;

                strcpy(ptr->siguiente->nombre, nombre);
                strcpy(ptr->siguiente->apellido, apellido);
                ptr->siguiente->ci = ci;
                ptr->siguiente->grado = grado;
                ptr->siguiente->promedio = promedio;

                swapped = 1;
            }

            ptr = ptr->siguiente;
        }

    } while (swapped);
    mostrar_lista(cabeza);
}

void calificacion(estudiante_t *estudiante) { 
    if (estudiante == NULL) return;

    char letra[30];
    if (estudiante->promedio >= 95) {
        strcpy(letra, "S, Sobresaliente");
    } else if (estudiante->promedio >= 82) {
        strcpy(letra, "MB, Muy Bueno");
    } else if (estudiante->promedio >= 76) {
        strcpy(letra, "BMB, Bueno Muy Bueno");
    } else if (estudiante->promedio >= 61) {
        strcpy(letra, "B, Bueno");
    } else if (estudiante->promedio >= 31) {
        strcpy(letra, "R, Regular");
    } else {
        strcpy(letra, "D, Deficiente");
    }

    printf("Estudiante: %s %s, Promedio: %.2f, Calificación: %s\n",
           estudiante->nombre, estudiante->apellido,
           estudiante->promedio, letra);
}