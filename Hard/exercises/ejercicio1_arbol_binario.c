/*
 * EJERCICIO 1: Árbol Binario de Búsqueda Completo
 * 
 * OBJETIVO: Implementar un árbol binario de búsqueda con todas las operaciones
 * principales y algunas funciones avanzadas.
 * 
 * NIVEL: Hard (Avanzado)
 * TIEMPO ESTIMADO: 60-70 minutos
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo* izquierdo;
    struct nodo* derecho;
} Nodo;

// TODO: Implementa todas las funciones del BST
Nodo* crear_nodo(int valor) {
    // TU CÓDIGO AQUÍ
    return NULL;
}

Nodo* insertar(Nodo* raiz, int valor) {
    // TU CÓDIGO AQUÍ: Insertar manteniendo propiedad BST
    return NULL;
}

Nodo* buscar(Nodo* raiz, int valor) {
    // TU CÓDIGO AQUÍ: Búsqueda eficiente en BST
    return NULL;
}

Nodo* eliminar(Nodo* raiz, int valor) {
    // TU CÓDIGO AQUÍ: Eliminar nodo (3 casos)
    return NULL;
}

void inorden(Nodo* raiz) {
    // TU CÓDIGO AQUÍ: Recorrido inorden
}

int altura(Nodo* raiz) {
    // TU CÓDIGO AQUÍ: Calcular altura del árbol
    return -1;
}

int es_balanceado(Nodo* raiz) {
    // TU CÓDIGO AQUÍ: Verificar si está balanceado
    return 0;
}

Nodo* encontrar_lca(Nodo* raiz, int a, int b) {
    // TU CÓDIGO AQUÍ: Lowest Common Ancestor
    return NULL;
}

void imprimir_por_niveles(Nodo* raiz) {
    // TU CÓDIGO AQUÍ: Recorrido por niveles (BFS)
}

void liberar_arbol(Nodo* raiz) {
    // TU CÓDIGO AQUÍ: Liberar toda la memoria
}

int main() {
    printf("=== EJERCICIO 1: BST COMPLETO ===\n");
    
    // TODO: Implementa un programa completo que:
    // 1. Cree un BST con valores específicos
    // 2. Realice búsquedas y eliminaciones
    // 3. Verifique si está balanceado
    // 4. Encuentre el LCA de dos nodos
    // 5. Muestre recorrido por niveles
    // 6. Libere toda la memoria
    
    return 0;
}

/*
 * BST (Binary Search Tree):
 * - Propiedad fundamental: Izquierdo < Raíz < Derecho
 * - Operaciones eficientes en promedio O(log n)
 * - Casos de eliminación: hoja, un hijo, dos hijos
 * - LCA: Ancestro común más bajo de dos nodos
 */