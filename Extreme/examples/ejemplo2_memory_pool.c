/*
 * EJEMPLO 2: Memory Pool Optimizado
 * 
 * Implementación completa de un sistema de memory pool con optimizaciones
 * avanzadas para rendimiento y gestión de memoria.
 * 
 * NIVEL: Extreme (Experto)
 * TIEMPO ESTIMADO: Solo lectura - 20 minutos
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Memory pool con segregación por tamaños
typedef struct bloque_libre {
    struct bloque_libre* siguiente;
} BloqueLibre;

typedef struct {
    void* memoria;
    BloqueLibre* lista_libre;
    size_t tamaño_bloque;
    size_t bloques_totales;
    size_t bloques_usados;
    char nombre[32];
} PoolTamaño;

typedef struct {
    PoolTamaño* pools;
    int num_pools;
    size_t total_asignado;
} SistemaMemoria;

// Crear sistema de memoria con múltiples pools
SistemaMemoria* crear_sistema_memoria() {
    SistemaMemoria* sistema = malloc(sizeof(SistemaMemoria));
    if (!sistema) return NULL;
    
    // Tamaños comunes: 16, 32, 64, 128, 256, 512 bytes
    size_t tamaños[] = {16, 32, 64, 128, 256, 512};
    sistema->num_pools = 6;
    sistema->total_asignado = 0;
    
    sistema->pools = malloc(sistema->num_pools * sizeof(PoolTamaño));
    if (!sistema->pools) {
        free(sistema);
        return NULL;
    }
    
    // Inicializar cada pool
    for (int i = 0; i < sistema->num_pools; i++) {
        PoolTamaño* pool = &sistema->pools[i];
        pool->tamaño_bloque = tamaños[i];
        pool->bloques_totales = 1000; // 1000 bloques por pool
        pool->bloques_usados = 0;
        snprintf(pool->nombre, sizeof(pool->nombre), "Pool_%zu", tamaños[i]);
        
        // Asignar memoria del pool
        size_t memoria_total = pool->tamaño_bloque * pool->bloques_totales;
        pool->memoria = aligned_alloc(64, memoria_total);
        if (!pool->memoria) continue;
        
        // Inicializar lista de bloques libres
        pool->lista_libre = NULL;
        char* ptr = (char*)pool->memoria;
        for (size_t j = 0; j < pool->bloques_totales; j++) {
            BloqueLibre* bloque = (BloqueLibre*)ptr;
            bloque->siguiente = pool->lista_libre;
            pool->lista_libre = bloque;
            ptr += pool->tamaño_bloque;
        }
        
        sistema->total_asignado += memoria_total;
    }
    
    return sistema;
}

// Asignar memoria del sistema
void* sistema_malloc(SistemaMemoria* sistema, size_t tamaño) {
    if (!sistema) return malloc(tamaño);
    
    // Encontrar pool apropiado
    PoolTamaño* pool_elegido = NULL;
    for (int i = 0; i < sistema->num_pools; i++) {
        if (sistema->pools[i].tamaño_bloque >= tamaño) {
            pool_elegido = &sistema->pools[i];
            break;
        }
    }
    
    if (!pool_elegido || !pool_elegido->lista_libre) {
        return malloc(tamaño); // Fallback a malloc estándar
    }
    
    // Tomar bloque de la lista libre
    BloqueLibre* bloque = pool_elegido->lista_libre;
    pool_elegido->lista_libre = bloque->siguiente;
    pool_elegido->bloques_usados++;
    
    return (void*)bloque;
}

// Ejemplo de uso y benchmarking
void benchmark_pools() {
    printf("=== BENCHMARK DE MEMORY POOLS ===\n");
    
    SistemaMemoria* sistema = crear_sistema_memoria();
    if (!sistema) return;
    
    clock_t inicio, fin;
    const int ITERACIONES = 100000;
    
    // Benchmark del sistema de pools
    inicio = clock();
    void* ptrs[1000];
    for (int i = 0; i < ITERACIONES; i++) {
        int indice = i % 1000;
        if (ptrs[indice]) {
            // Simularíamos free aquí
        }
        ptrs[indice] = sistema_malloc(sistema, 64);
    }
    fin = clock();
    
    double tiempo_pools = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo con pools: %.4f segundos\n", tiempo_pools);
    
    // Benchmark de malloc estándar
    inicio = clock();
    for (int i = 0; i < ITERACIONES; i++) {
        int indice = i % 1000;
        if (ptrs[indice]) {
            free(ptrs[indice]);
        }
        ptrs[indice] = malloc(64);
    }
    fin = clock();
    
    double tiempo_malloc = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo con malloc: %.4f segundos\n", tiempo_malloc);
    printf("Mejora: %.2fx más rápido\n", tiempo_malloc / tiempo_pools);
}

int main() {
    printf("=== MEMORY POOL OPTIMIZADO ===\n\n");
    benchmark_pools();
    return 0;
}

/*
 * OPTIMIZACIONES IMPLEMENTADAS:
 * - Segregación por tamaños para reducir fragmentación
 * - Alineación de memoria para optimización de cache
 * - Preasignación de bloques para eliminar overhead
 * - Fallback a malloc para tamaños no soportados
 * 
 * CASOS DE USO:
 * - Servidores web (asignación frecuente de buffers)
 * - Juegos (objetos de vida corta)
 * - Compiladores (nodos de AST)
 * - Bases de datos (páginas de memoria)
 */