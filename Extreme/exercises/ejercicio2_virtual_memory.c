/*
 * EJERCICIO 2: Simulador de Memoria Virtual
 * EJERCICIO 3: Optimización de Compilador
 * EJERCICIO 4: Punteros Concurrentes
 * EJERCICIO 5: Estructuras de Datos Avanzadas
 * 
 * NIVEL: Extreme (Experto)
 * Estos ejercicios requieren implementación de conceptos de sistemas avanzados.
 */

#include <stdio.h>
#include <stdlib.h>

// EJERCICIO 2: Memoria Virtual
typedef struct pagina {
    int numero_pagina;
    int numero_marco;
    int presente;
    int modificada;
    int accedida;
} Pagina;

// TODO: Implementar simulador de paginación
// - Tabla de páginas
// - Algoritmos de reemplazo (LRU, FIFO)
// - Manejo de fallos de página
// - Estadísticas de rendimiento

// EJERCICIO 3: Optimización de Compilador
// TODO: Implementar técnicas de optimización:
// - Eliminación de código muerto
// - Propagación de constantes
// - Optimización de loops
// - Análisis de alias de punteros

// EJERCICIO 4: Programación Concurrente
typedef struct nodo_lockfree {
    int datos;
    struct nodo_lockfree* siguiente;
} NodoLockFree;

// TODO: Implementar estructuras lock-free:
// - Lista enlazada sin bloqueos
// - Uso de atomic operations
// - ABA problem solutions
// - Memory barriers

// EJERCICIO 5: Estructuras Avanzadas
typedef struct nodo_btree {
    int* claves;
    struct nodo_btree** hijos;
    int num_claves;
    int es_hoja;
} NodoBTree;

// TODO: Implementar B-Tree completo:
// - Inserción con splits
// - Eliminación con merges
// - Búsqueda eficiente
// - Balanceo automático

// TODO: Implementar Trie:
// - Inserción de strings
// - Búsqueda con prefijos
// - Autocompletado
// - Compresión de nodos

int main() {
    printf("=== EJERCICIOS EXTREME ===\n");
    printf("Estos ejercicios requieren implementación completa de:\n");
    printf("1. Simulador de memoria virtual con paginación\n");
    printf("2. Técnicas de optimización de compilador\n");
    printf("3. Estructuras de datos lock-free\n");
    printf("4. B-Trees y Tries optimizados\n");
    printf("\nCada ejercicio es un proyecto completo por sí mismo.\n");
    
    return 0;
}

/*
 * CONCEPTOS AVANZADOS CUBIERTOS:
 * 
 * MEMORIA VIRTUAL:
 * - Traducción de direcciones virtuales a físicas
 * - Manejo de fallos de página
 * - Algoritmos de reemplazo de páginas
 * - Optimización de localidad
 * 
 * OPTIMIZACIÓN:
 * - Análisis estático de código
 * - Transformaciones que preservan semántica
 * - Optimización de acceso a memoria
 * - Vectorización y paralelización
 * 
 * CONCURRENCIA:
 * - Programación sin bloqueos
 * - Operaciones atómicas
 * - Modelos de consistencia de memoria
 * - Problemas de sincronización
 * 
 * ESTRUCTURAS AVANZADAS:
 * - Árboles balanceados automáticamente
 * - Estructuras de texto eficientes
 * - Optimización de cache
 * - Algoritmos de compresión
 */