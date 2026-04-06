#include <stdio.h>
#include "estudiantes.h"

int main() {
    estudiante_t *cabeza = NULL;

    agregar_estudiante(&cabeza, "Pilar", "Martinez", 12345678, 10, 85.5);
    agregar_estudiante(&cabeza, "Juan", "Perez", 87654321, 11, 90.0);
    agregar_estudiante(&cabeza, "Maria", "Gomez", 11223344, 9, 92.3);
    agregar_estudiante(&cabeza, "Pilar", "Martinez", 12345678, 10, 88.0);
    printf("\n");
    printf("Lista de estudiantes:\n");
    mostrar_lista(cabeza);
    printf("\n");
    printf("\nOrdenar por apellido:\n");
    ordenar_por_apellido(cabeza);
    printf("\n");
    printf("Ordenar por CI:\n");
    ordenar_por_ci(cabeza);
    printf("\n");
        estudiante_t *estudiante = cabeza; // Tomamos el primer estudiante para la calificación
        calificacion(estudiante);
    return 0;
}
