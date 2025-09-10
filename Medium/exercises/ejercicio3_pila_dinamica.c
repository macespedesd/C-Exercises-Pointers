/*
 * EJERCICIO 3: Pila Dinámica (Stack)
 * 
 * OBJETIVO: Implementar una pila usando memoria dinámica y punteros.
 * Comprender el principio LIFO (Last In, First Out).
 * 
 * NIVEL: Medium (Intermedio)
 * TIEMPO ESTIMADO: 40-45 minutos
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_pila {
    int dato;
    struct nodo_pila* siguiente;
} NodoPila;

typedef struct {
    NodoPila* tope;
    int tamaño;
} Pila;

// TODO: Implementa las funciones de la pila
Pila* crear_pila() {
    // TU CÓDIGO AQUÍ: Crea y inicializa una pila vacía
    return NULL;
}

int esta_vacia(Pila* pila) {
    // TU CÓDIGO AQUÍ: Retorna 1 si está vacía, 0 si no
    return 0;
}

void push(Pila* pila, int valor) {
    // TU CÓDIGO AQUÍ: Inserta elemento en el tope
}

int pop(Pila* pila) {
    // TU CÓDIGO AQUÍ: Elimina y retorna elemento del tope
    return -1; // Valor de error
}

int peek(Pila* pila) {
    // TU CÓDIGO AQUÍ: Retorna el tope sin eliminarlo
    return -1; // Valor de error
}

void imprimir_pila(Pila* pila) {
    // TU CÓDIGO AQUÍ: Imprime la pila desde el tope
}

void liberar_pila(Pila* pila) {
    // TU CÓDIGO AQUÍ: Libera toda la memoria de la pila
}

int main() {
    printf("=== EJERCICIO 3: PILA DINÁMICA ===\n\n");
    
    Pila* mi_pila = crear_pila();
    
    // TODO: Prueba todas las operaciones de la pila
    // Push varios elementos, pop algunos, peek, etc.
    
    printf("Prueba completada\n");
    liberar_pila(mi_pila);
    return 0;
}

/*
 * PILA (STACK): Estructura LIFO (Last In, First Out)
 * Operaciones principales: push (insertar), pop (extraer), peek (ver tope)
 * Aplicaciones: Evaluación de expresiones, llamadas de función, undo/redo
 */