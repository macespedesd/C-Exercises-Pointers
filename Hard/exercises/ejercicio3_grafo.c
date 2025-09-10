/*
 * EJERCICIO 3: Implementación de Grafo
 * 
 * OBJETIVO: Crear un grafo con lista de adyacencia y algoritmos
 * básicos como DFS, BFS y detección de ciclos.
 * 
 * NIVEL: Hard (Avanzado)
 * TIEMPO ESTIMADO: 70-80 minutos
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_adj {
    int vertice;
    int peso; // Para grafos ponderados
    struct nodo_adj* siguiente;
} NodoAdj;

typedef struct {
    int num_vertices;
    NodoAdj** lista_adj;
    int dirigido; // 1 si es dirigido, 0 si no
} Grafo;

// TODO: Implementa todas las funciones del grafo
Grafo* crear_grafo(int vertices, int dirigido) {
    // TU CÓDIGO AQUÍ: Crear estructura del grafo
    return NULL;
}

void agregar_arista(Grafo* grafo, int origen, int destino, int peso) {
    // TU CÓDIGO AQUÍ: Agregar arista (considerar si es dirigido)
}

void eliminar_arista(Grafo* grafo, int origen, int destino) {
    // TU CÓDIGO AQUÍ: Eliminar arista
}

void dfs(Grafo* grafo, int inicio, int* visitados) {
    // TU CÓDIGO AQUÍ: Búsqueda en profundidad
}

void bfs(Grafo* grafo, int inicio) {
    // TU CÓDIGO AQUÍ: Búsqueda en anchura (usar cola)
}

int tiene_ciclo(Grafo* grafo) {
    // TU CÓDIGO AQUÍ: Detectar ciclos usando DFS
    return 0;
}

void componentes_conexas(Grafo* grafo) {
    // TU CÓDIGO AQUÍ: Encontrar componentes conexas
}

int* camino_mas_corto(Grafo* grafo, int origen, int destino) {
    // TU CÓDIGO AQUÍ: Algoritmo de Dijkstra simplificado
    return NULL;
}

void imprimir_grafo(Grafo* grafo) {
    // TU CÓDIGO AQUÍ: Mostrar representación del grafo
}

void liberar_grafo(Grafo* grafo) {
    // TU CÓDIGO AQUÍ: Liberar toda la memoria
}

int main() {
    printf("=== EJERCICIO 3: GRAFO ===\n");
    
    // TODO: Implementa un programa que:
    // 1. Cree un grafo dirigido y uno no dirigido
    // 2. Agregue múltiples aristas
    // 3. Realice DFS y BFS desde diferentes vértices
    // 4. Detecte ciclos
    // 5. Encuentre componentes conexas
    // 6. Calcule camino más corto (si implementas Dijkstra)
    
    return 0;
}

/*
 * GRAFO:
 * - Representación: Lista de adyacencia vs Matriz de adyacencia
 * - DFS: Stack (recursión) - Exploración en profundidad
 * - BFS: Cola - Exploración en anchura, caminos mínimos
 * - Ciclos: Detección usando DFS con estados (blanco/gris/negro)
 * - Dijkstra: Camino más corto con pesos positivos
 */