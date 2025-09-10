/*
 * EJERCICIO 5: Algoritmos de Búsqueda y Manipulación de Datos
 * 
 * OBJETIVO: Implementar algoritmos de búsqueda usando punteros.
 * Practicar manipulación avanzada de datos con punteros.
 * 
 * NIVEL: Medium (Intermedio)
 * TIEMPO ESTIMADO: 40-45 minutos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Búsqueda lineal usando punteros
int* busqueda_lineal(int* arr, int n, int valor) {
    // TU CÓDIGO AQUÍ: Busca el valor y retorna puntero al elemento
    // Retorna NULL si no se encuentra
    return NULL;
}

// TODO: Búsqueda binaria usando punteros (arreglo debe estar ordenado)
int* busqueda_binaria(int* arr, int n, int valor) {
    // TU CÓDIGO AQUÍ: Implementa búsqueda binaria con punteros
    // Usa aritmética de punteros en lugar de índices
    return NULL;
}

// TODO: Función para encontrar todos los elementos que cumplen una condición
int filtrar_elementos(int* arr, int n, int** resultado, int (*condicion)(int)) {
    // TU CÓDIGO AQUÍ: Crea un nuevo arreglo con elementos que cumplan la condición
    // Retorna el número de elementos encontrados
    return 0;
}

// Funciones de condición para filtrar
int es_par(int x) { return x % 2 == 0; }
int es_positivo(int x) { return x > 0; }
int es_mayor_que_10(int x) { return x > 10; }

// TODO: Función para eliminar duplicados
int eliminar_duplicados(int* arr, int n) {
    // TU CÓDIGO AQUÍ: Elimina elementos duplicados del arreglo
    // Retorna el nuevo tamaño del arreglo
    return n;
}

// TODO: Función para invertir arreglo usando punteros
void invertir_arreglo(int* arr, int n) {
    // TU CÓDIGO AQUÍ: Invierte el arreglo usando dos punteros
}

// TODO: Función para fusionar dos arreglos ordenados
int* fusionar_arreglos(int* arr1, int n1, int* arr2, int n2, int* tamaño_resultado) {
    // TU CÓDIGO AQUÍ: Fusiona dos arreglos ordenados en uno ordenado
    return NULL;
}

int main() {
    printf("=== EJERCICIO 5: BÚSQUEDA Y MANIPULACIÓN ===\n\n");
    
    // Arreglo de prueba
    int datos[] = {3, 7, 1, 9, 4, 6, 8, 2, 5, 7, 3, 9};
    int n = sizeof(datos) / sizeof(datos[0]);
    
    // TODO: Prueba todas las funciones implementadas
    // 1. Búsqueda lineal y binaria
    // 2. Filtrado de elementos
    // 3. Eliminación de duplicados
    // 4. Inversión de arreglo
    // 5. Fusión de arreglos
    
    printf("=== FIN DEL EJERCICIO ===\n");
    return 0;
}

/*
 * ALGORITMOS DE BÚSQUEDA:
 * - Búsqueda Lineal: O(n) - Recorre secuencialmente
 * - Búsqueda Binaria: O(log n) - Divide y vencerás (requiere orden)
 * 
 * MANIPULACIÓN DE DATOS:
 * - Filtrado: Selecciona elementos según criterio
 * - Eliminación de duplicados: Remueve elementos repetidos
 * - Inversión: Cambia orden de elementos
 * - Fusión: Combina arreglos manteniendo orden
 */