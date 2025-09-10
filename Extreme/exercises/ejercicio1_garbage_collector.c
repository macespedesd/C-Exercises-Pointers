/*
 * EJERCICIO 1: Garbage Collector Mark-and-Sweep
 * 
 * OBJETIVO: Implementar un garbage collector básico usando algoritmo
 * mark-and-sweep para recolección automática de memoria.
 * 
 * NIVEL: Extreme (Experto)
 * TIEMPO ESTIMADO: 90-120 minutos
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct objeto {
    void* datos;
    size_t tamaño;
    int marcado;
    struct objeto* siguiente;
    struct objeto** referencias; // Array de punteros a otros objetos
    int num_referencias;
} Objeto;

typedef struct {
    Objeto* cabeza;
    Objeto** raices; // Objetos raíz (stack, variables globales)
    int num_raices;
    size_t memoria_total;
} GarbageCollector;

// TODO: Implementa el garbage collector completo
GarbageCollector* crear_gc() {
    // TU CÓDIGO AQUÍ: Inicializar GC
    return NULL;
}

Objeto* gc_malloc(GarbageCollector* gc, size_t tamaño) {
    // TU CÓDIGO AQUÍ: Asignar objeto rastreado por GC
    return NULL;
}

void agregar_raiz(GarbageCollector* gc, Objeto* obj) {
    // TU CÓDIGO AQUÍ: Agregar objeto raíz
}

void agregar_referencia(Objeto* desde, Objeto* hacia) {
    // TU CÓDIGO AQUÍ: Crear referencia entre objetos
}

void marcar_fase(GarbageCollector* gc) {
    // TU CÓDIGO AQUÍ: Fase de marcado (mark)
}

void limpiar_fase(GarbageCollector* gc) {
    // TU CÓDIGO AQUÍ: Fase de limpieza (sweep)
}

void ejecutar_gc(GarbageCollector* gc) {
    // TU CÓDIGO AQUÍ: Ejecutar ciclo completo de GC
}

void destruir_gc(GarbageCollector* gc) {
    // TU CÓDIGO AQUÍ: Liberar toda la memoria del GC
}

int main() {
    printf("=== EJERCICIO 1: GARBAGE COLLECTOR ===\n");
    
    // TODO: Implementa una demostración completa del GC:
    // 1. Crear objetos con referencias circulares
    // 2. Demostrar recolección automática
    // 3. Medir memoria antes/después del GC
    // 4. Mostrar objetos recolectados vs preservados
    
    return 0;
}

/*
 * ALGORITMO MARK-AND-SWEEP:
 * 1. MARK: Marcar todos los objetos alcanzables desde las raíces
 * 2. SWEEP: Liberar todos los objetos no marcados
 * 3. RESET: Limpiar marcas para siguiente ciclo
 * 
 * CONSIDERACIONES:
 * - Referencias circulares se manejan automáticamente
 * - Pausas en ejecución durante GC
 * - Fragmentación de memoria
 * - Necesidad de rastrear todas las referencias
 */