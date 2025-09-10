/*
 * EJERCICIO 4: Memory Pool y Asignación Avanzada
 * 
 * OBJETIVO: Implementar un sistema de memory pool para optimizar
 * asignaciones frecuentes de memoria del mismo tamaño.
 * 
 * NIVEL: Hard (Avanzado)
 * TIEMPO ESTIMADO: 60-70 minutos
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct bloque {
    struct bloque* siguiente;
} Bloque;

typedef struct {
    void* memoria_base;
    Bloque* lista_libre;
    size_t tamaño_bloque;
    size_t num_bloques;
    size_t bloques_usados;
} MemoryPool;

// TODO: Implementa el sistema de memory pool
MemoryPool* crear_pool(size_t tamaño_bloque, size_t num_bloques) {
    // TU CÓDIGO AQUÍ: Crear pool preasignando memoria
    return NULL;
}

void* pool_alloc(MemoryPool* pool) {
    // TU CÓDIGO AQUÍ: Asignar bloque del pool
    return NULL;
}

void pool_free(MemoryPool* pool, void* ptr) {
    // TU CÓDIGO AQUÍ: Liberar bloque de vuelta al pool
}

void estadisticas_pool(MemoryPool* pool) {
    // TU CÓDIGO AQUÍ: Mostrar estadísticas del pool
}

void destruir_pool(MemoryPool* pool) {
    // TU CÓDIGO AQUÍ: Liberar todo el pool
}

// Sistema de allocator personalizado
typedef struct allocator {
    void* (*alloc)(size_t size);
    void (*free)(void* ptr);
    void* contexto;
} Allocator;

// TODO: Implementa diferentes estrategias de asignación
void* malloc_wrapper(size_t size) {
    // TU CÓDIGO AQUÍ: Wrapper para malloc estándar
    return NULL;
}

void free_wrapper(void* ptr) {
    // TU CÓDIGO AQUÍ: Wrapper para free estándar
}

Allocator crear_allocator_estandar() {
    // TU CÓDIGO AQUÍ: Crear allocator que usa malloc/free
    Allocator alloc = {NULL, NULL, NULL};
    return alloc;
}

Allocator crear_allocator_pool(size_t tamaño_bloque, size_t num_bloques) {
    // TU CÓDIGO AQUÍ: Crear allocator basado en pool
    Allocator alloc = {NULL, NULL, NULL};
    return alloc;
}

// Estructura de prueba para usar con el pool
typedef struct {
    int id;
    char nombre[32];
    float valor;
} EstructuraPrueba;

int main() {
    printf("=== EJERCICIO 4: MEMORY POOL ===\n");
    
    // TODO: Implementa un programa que:
    // 1. Cree un memory pool para estructuras específicas
    // 2. Realice múltiples asignaciones y liberaciones
    // 3. Compare rendimiento con malloc/free estándar
    // 4. Muestre estadísticas de uso
    // 5. Implemente allocator personalizado
    // 6. Demuestre ventajas del pool en fragmentación
    
    return 0;
}

/*
 * MEMORY POOL:
 * - Preasignación de bloques del mismo tamaño
 * - Eliminación de fragmentación externa
 * - Asignación/liberación O(1)
 * - Mejor localidad de cache
 * - Útil para objetos de vida corta y tamaño fijo
 * 
 * VENTAJAS:
 * - Rendimiento predecible
 * - Sin fragmentación
 * - Liberación rápida de todo el pool
 * 
 * DESVENTAJAS:
 * - Memoria preasignada (puede desperdiciar)
 * - Solo para objetos de tamaño fijo
 * - Complejidad adicional
 */