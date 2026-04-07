#include "estudiantes.h"
#include <stdlib.h>    
#include <string.h>        

// Función 1: Crea memoria dinámica para agregar un estudiante, carga su nombre, apellido, ci, grado y promedio.
              // Verifica que no exista otro estudiante con el mismo ci y en tal caso imprime "Estudiante con CI X ya existe".
              // Además, actualiza la cabeza de la lista, que pasa a ser el nuevo estudiante agregado
// Parámetros: Utiliza doble puntero para poder modificar la cabeza de la lista. Recibe la dirección del inicio de la lista, nombre del 
// estudiante como char de hasta 64 caracteres, apellido de igual tipo, ci de tipo entero sin signo de 32 bits, grado de tipo entero, y 
// promedio de tipo float
// La función no devuelve nada por ser de tipo void
void agregar_estudiante(estudiante_t **cabeza,   
                        char nombre[64],      
                        char apellido[64],
                        uint32_t ci,
                        int grado,
                        float promedio) {

    estudiante_t *nuevo = malloc(sizeof(estudiante_t)); 
    if (nuevo == NULL) return;    

    strcpy(nuevo->nombre, nombre);    
    strcpy(nuevo->apellido, apellido);    
    nuevo->ci = ci;
    nuevo->grado = grado;    
    nuevo->promedio = promedio;
    nuevo->siguiente = NULL;    


    estudiante_t *actual = *cabeza;    
    while (actual != NULL) {      
        if (actual->ci == ci) {    
            printf("Error: Estudiante con CI %u ya existe.\n", ci);
            free(nuevo);         
            return;
        }
        actual = actual->siguiente;    
    }

   
    nuevo->siguiente = *cabeza;    
    *cabeza = nuevo;     
}
// Función 2: Elimina un estudiante de la lista según su ci. Busca el nodo a eliminar, lo saltea y luego libera su memoria correspondiente
// Si lo encuentra y lo elimina imprime "Estudiante con CI X eliminado", si no lo encuentra en la lista, imprime "Estudiante con CI X no encontrado"
// De parámetros recibe un doble puntero a cabeza que permite cambiar la cabeza si se requiere y el ci como entero sin signo de 32 bits
// Por ser función void no retorna nada
void eliminar_estudiante(estudiante_t **cabeza, uint32_t ci) {
    if (*cabeza == NULL) return;    

    estudiante_t *actual = *cabeza;    
    estudiante_t *anterior = NULL;     

    while (actual != NULL) {      
        if (actual->ci == ci) {    
            if (anterior == NULL) {  
                *cabeza = actual->siguiente; 
            } else {                            
                
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
// Función 7: Ordena la lista de estudiantes por ci de manera creciente y luego la muestra
// Recibe como parámetro el puntero al comienzo de la lista
// No devuleve nada por ser función void
void ordenar_por_ci(estudiante_t *cabeza) {
    if (cabeza == NULL) return;

    int swapped;
    estudiante_t *ptr;

    do {
        swapped = 0;
        ptr = cabeza;

        while (ptr->siguiente != NULL) {

            if (ptr->ci > ptr->siguiente->ci) {

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
// Función 8: Convierte el promedio del estudiante en una calificación de texto.
// Menor a 31 será deficiente, entre 31 y 60 regular, entre 61 y 75 Bueno, entre 76 y 81 bueno muy bueno
// Entre 82  y 94 muy bueno y entre 95 y 100 será sobresaliente
// Recibe de parámetro un puntero al estudiante que queremos calificar
// No devuelve nada al ser función void, pero imprime "Estudiante: nombre apellido, Promedio: X, Calificación: nota en texto"
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
