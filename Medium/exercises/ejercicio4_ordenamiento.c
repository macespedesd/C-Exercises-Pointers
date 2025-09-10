/*
 * EJERCICIO 4: Algoritmos de Ordenamiento con Punteros
 * 
 * OBJETIVO: Implementar algoritmos de ordenamiento usando punteros.
 * Practicar manipulación de arreglos con punteros.
 * 
 * NIVEL: Medium (Intermedio)
 * TIEMPO ESTIMADO: 45-50 minutos
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO: Implementa intercambio usando punteros
void intercambiar(int* a, int* b) {
    // TU CÓDIGO AQUÍ: Intercambia los valores apuntados por a y b
}

// TODO: Implementa bubble sort usando punteros
void bubble_sort(int* arr, int n) {
    // TU CÓDIGO AQUÍ: Ordena el arreglo usando bubble sort
    // Usa aritmética de punteros en lugar de índices
}

// TODO: Implementa selection sort usando punteros
void selection_sort(int* arr, int n) {
    // TU CÓDIGO AQUÍ: Ordena usando selection sort con punteros
}

// TODO: Función para imprimir arreglo usando punteros
void imprimir_arreglo(int* arr, int n, const char* titulo) {
    // TU CÓDIGO AQUÍ: Imprime el arreglo usando solo punteros
}

// TODO: Función para llenar arreglo con números aleatorios
void llenar_aleatorio(int* arr, int n, int max_valor) {
    // TU CÓDIGO AQUÍ: Llena con números aleatorios entre 1 y max_valor
}

// TODO: Función para copiar arreglo
void copiar_arreglo(int* origen, int* destino, int n) {
    // TU CÓDIGO AQUÍ: Copia elementos de origen a destino
}

int main() {
    printf("=== EJERCICIO 4: ORDENAMIENTO CON PUNTEROS ===\n\n");
    
    srand(time(NULL));
    int n = 10;
    
    // Crear arreglos dinámicos
    int* arr_original = (int*)malloc(n * sizeof(int));
    int* arr_bubble = (int*)malloc(n * sizeof(int));
    int* arr_selection = (int*)malloc(n * sizeof(int));
    
    // TODO: Prueba los algoritmos de ordenamiento
    // 1. Llena arr_original con números aleatorios
    // 2. Copia a los otros arreglos
    // 3. Aplica diferentes algoritmos de ordenamiento
    // 4. Compara resultados y tiempos
    
    // Liberar memoria
    free(arr_original);
    free(arr_bubble);
    free(arr_selection);
    
    printf("=== FIN DEL EJERCICIO ===\n");
    return 0;
}

/*
 * ALGORITMOS DE ORDENAMIENTO:
 * - Bubble Sort: O(n²) - Compara e intercambia elementos adyacentes
 * - Selection Sort: O(n²) - Encuentra el mínimo y lo coloca en su posición
 * - Insertion Sort: O(n²) - Inserta cada elemento en su posición correcta
 * 
 * PUNTEROS EN ORDENAMIENTO:
 * - Permite manipular directamente la memoria
 * - Aritmética de punteros en lugar de índices
 * - Paso por referencia para intercambios
 */