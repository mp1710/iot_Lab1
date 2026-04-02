#include "estudiantes.h"
#include <stdlib.h>

void agregar_estudiante(nodo_t **cabeza, estudiante_t nuevo_estudiante) {
    // Crear un nuevo nodo para el estudiante usando memoria dinámica
    nodo_t *nuevo_nodo = malloc(sizeof(nodo_t)); 
    if (nuevo_nodo == NULL) {
        return; // Manejar error de asignación de memoria
    }
    //Meto los datos del nuevo estudiante en el nodo y lo agrego al inicio de la lista
    nuevo_nodo->dato = nuevo_estudiante;
    nuevo_nodo->siguiente = *cabeza;
    *cabeza = nuevo_nodo;
}

void mostrar_lista(nodo_t *cabeza) {
    // Recorro la lista, mostrando cada estudiante
    nodo_t *actual = cabeza;
    while (actual != NULL) {
        mostrar_estudiante(actual->dato);
        actual = actual->siguiente;
    }
}

void mostrar_estudiante(estudiante_t estudiante) {
    // Imprimo los datos del estudiante 
    printf("Nombre: %s %s\n", estudiante.nombre, estudiante.apellido);
    printf("CI: %u\n", estudiante.ci);
    printf("Grado: %u\n", estudiante.grado);
    printf("Promedio: %.2f\n", estudiante.promedio);
    printf("-------------------------\n");
}

void eliminar_estudiante(nodo_t **cabeza, uint32_t ci) {
    // accedo con un puntero a puntero para modificar la cabeza de la lista si es necesario
    nodo_t *actual = *cabeza;
    // mantengo el dato del puntero anterior por si tengo que eliminar un elemento intermedio o final
    nodo_t *anterior = NULL;

// Recorro la lista buscando el estudiante con el CI y lo elimino
    while (actual != NULL) {
        if (actual->dato.ci == ci) {
            if (anterior == NULL) {
                *cabeza = actual->siguiente; // Eliminar el primer nodo
            } else {
                anterior->siguiente = actual->siguiente; // Eliminar nodo intermedio o final
            }
            free(actual); // Libero memoria del nodo eliminado
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

estudiante_t* buscar_estudiante_nombre(nodo_t *cabeza, const char *nombre) {
    // Recorro la lista buscando el estudiante por nombre
    nodo_t *actual = cabeza;
    while (actual != NULL) {
        if (strcmp(actual->dato.nombre, nombre) == 0) {
            return &actual->dato; // Retorna un puntero al estudiante encontrado
        }
        actual = actual->siguiente;
    }
    return NULL; // Retorna NULL si no se encuentra el estudiante
}

estudiante_t* buscar_estudiante_apellido(nodo_t *cabeza, const char *apellido) {
    // Recorro la lista buscando el estudiante por apellido 
    nodo_t *actual = cabeza;
    while (actual != NULL) {
        if (strcmp(actual->dato.apellido, apellido) == 0) {
            return &actual->dato; // Retorna un puntero al estudiante encontrado
        }
        actual = actual->siguiente;
    }
    return NULL; // Retorna NULL si no se encuentra el estudiante
}

estudiante_t* buscar_estudiante_ci(nodo_t *cabeza, uint32_t ci) {
    // Recorro la lista buscando el estudiante por CI
    nodo_t *actual = cabeza;
    while (actual != NULL) {
        if (actual->dato.ci == ci) {
            return &actual->dato; // Retorna un puntero al estudiante encontrado
        }
        actual = actual->siguiente;
    }
    return NULL; // Retorna NULL si no se encuentra el estudiante
}

float calificacion(estudiante_t estudiante) {
    // Retorna el promedio del estudiante como su calificación
    return estudiante.promedio;
}

void liberar_lista(nodo_t **cabeza) {
    // Libero la memoria de cada nodo de la lista
    nodo_t *actual = *cabeza;
    while (actual != NULL) {
        nodo_t *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    *cabeza = NULL; // Establezco la cabeza a NULL después de liberar la lista
}

