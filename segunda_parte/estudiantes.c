#include "estudiantes.h"
#include <stdlib.h>     // Incluye librerías y el archivo estudiantes.h que contiene la estructura de estudiante_t y
#include <string.h>        // contiene las funciones que se utilizarán

// Función 1 para agregar un estudiante
void agregar_estudiante(estudiante_t **cabeza,   // Utiliza doble puntero para poder modificar la cabeza de la lista
                        char nombre[64],      
                        char apellido[64],
                        uint32_t ci,
                        int grado,
                        float promedio) {

    // Crear nodo 
    estudiante_t *nuevo = malloc(sizeof(estudiante_t)); // Reserva memoria para un nuevo nodo y crea un estudainte dinámicamente
    if (nuevo == NULL) return;    // Si falla la memoria, sale

    // Cargar datos
    strcpy(nuevo->nombre, nombre);    // Copia el nombre al nodo
    strcpy(nuevo->apellido, apellido);    // Copia el apellido al nodo
    nuevo->ci = ci;
    nuevo->grado = grado;    // Guarda valores de ci, grado y promedio
    nuevo->promedio = promedio;
    nuevo->siguiente = NULL;    // Por ahora no apunta a ningún estudiante

// Verificar si ya existe un estudiante con el mismo ci
    estudiante_t *actual = *cabeza;    // Empieza desde el primer nodo
    while (actual != NULL) {      // Recorre toda la lista de estudiantes
        if (actual->ci == ci) {    // Si encuentra el mismo ci que se está ingresando 
            printf("Error: Estudiante con CI %u ya existe.\n", ci);
            free(nuevo);          // Libera memoria para evitar duplicados
            return;
        }
        actual = actual->siguiente;    // Avanza al siguiente nodo
    }

    // Insertar al inicio de la lista 
    nuevo->siguiente = *cabeza;    // El nuevo estudiante apunta al antiguo primer estudiante
    *cabeza = nuevo;      // Se convierte en el cabeza de lista
}
// Función 2 para eliminar un estudiante
void eliminar_estudiante(estudiante_t **cabeza, uint32_t ci) {
    if (*cabeza == NULL) return;    // Si no hay estudiantes, entonces sale

    estudiante_t *actual = *cabeza;    // El puntero estudiante actual apunta al cabeza de lista
    estudiante_t *anterior = NULL;    // El puntero estudiante anterior no apunta a nada

    while (actual != NULL) {      // Comienza a buscar en toda la lista
        if (actual->ci == ci) {    // Si encuentra el ci buscado
            if (anterior == NULL) {  // Esto ocurre cuando se quiere borrar el primer nodo de la lista
                *cabeza = actual->siguiente; // Se hace que cabeza apunte al segundo nodo, dejando el primero sin uso
            } else {                            // El primer puntero de la lista pasa a ser el que anteriormente era el segundo 
                // Eliminar nodo intermedio o final
                anterior->siguiente = actual->siguiente; // El anterior pasa al siguiente del actual, en resumen, se salta uno
            }
            free(actual);    // Libera la memoria del ci que se quiere eliminar
            printf("Estudiante con CI %u eliminado.\n", ci);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;    // Mueve ambos punteros
    }
    printf("Estudiante con CI %u no encontrado.\n", ci);
}
// Función 3: Recorre toda la lista de estudiantes e imprime nombre, apellido, ci, grado y promedio de cada uno de ellos
// El parámetro que recibe es un puntero al primer nodo de la lista, para empezar a recorrer desde allí
// Como la función es void no tiene retorno
void mostrar_lista(estudiante_t *cabeza) {
    estudiante_t *actual = cabeza;
    while (actual != NULL) {
        printf("Nombre: %s %s, CI: %u, Grado: %d, Promedio: %.2f\n",
               actual->nombre, actual->apellido, actual->ci,
               actual->grado, actual->promedio);
        actual = actual->siguiente;
    }
}

// Función 4: Busca un estudiante en particular por nombre y muestra su nombre, apellido, ci , grado, promedio.
              // Si no lo encuentra muestra "Estudiante con nombre X no encontrado"
// Los parámetros que recibe son el puntero al inicio de la lista y un char con el nombre a buscar, que no puede ser modificado por la función debido a "const"
// La función es void por lo que no retorna nada
void mostrar_estudiante_nombre(estudiante_t *cabeza, const char *nombre) {
    estudiante_t *actual = cabeza;
    while (actual != NULL) {  
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
// Función 5: Busca un estudiante utilizando su ci e imprime su nombre, apellido, ci, grado y promedio
              // Si no lo encuentra imprime "Estudiante con CI X no encontrado"
// Recibe de parámetros el puntero a cabeza, inicio de la lista, y la cédula a buscar de tipo entero sin signo de 32 bits
// La función es void así que no retorna nada
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

// Función 6: Ordena la lista alfabéticamente por apellido y luego la muestra
// Recibe de parámetro un puntero al principio de la lista
// Es función void así que no devuelve nada
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
