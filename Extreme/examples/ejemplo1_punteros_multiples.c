/*
 * EJEMPLO 1: Punteros Múltiples y Aplicaciones Avanzadas
 * 
 * Este ejemplo demuestra técnicas avanzadas con punteros múltiples,
 * optimizaciones de memoria y casos de uso especializados.
 * 
 * Autor: Ejercicios C - Punteros
 * Nivel: Extreme (Experto)
 * Para: Estudiantes de 3er semestre (nivel avanzado)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stddef.h>

// Estructura para demostrar punteros múltiples
typedef struct matriz_dinamica {
    int*** datos;       // Puntero triple para matriz 3D
    int dimensiones[3]; // x, y, z
} Matriz3D;

// Crear matriz 3D dinámica
Matriz3D* crear_matriz_3d(int x, int y, int z) {
    Matriz3D* matriz = malloc(sizeof(Matriz3D));
    if (!matriz) return NULL;
    
    matriz->dimensiones[0] = x;
    matriz->dimensiones[1] = y;
    matriz->dimensiones[2] = z;
    
    // Asignar memoria para el primer nivel (x)
    matriz->datos = malloc(x * sizeof(int**));
    if (!matriz->datos) {
        free(matriz);
        return NULL;
    }
    
    // Asignar memoria para el segundo nivel (y)
    for (int i = 0; i < x; i++) {
        matriz->datos[i] = malloc(y * sizeof(int*));
        if (!matriz->datos[i]) {
            // Liberar memoria ya asignada en caso de error
            for (int j = 0; j < i; j++) {
                free(matriz->datos[j]);
            }
            free(matriz->datos);
            free(matriz);
            return NULL;
        }
        
        // Asignar memoria para el tercer nivel (z)
        for (int j = 0; j < y; j++) {
            matriz->datos[i][j] = calloc(z, sizeof(int));
            if (!matriz->datos[i][j]) {
                // Cleanup en caso de error
                for (int k = 0; k < j; k++) {
                    free(matriz->datos[i][k]);
                }
                for (int k = 0; k < i; k++) {
                    for (int l = 0; l < y; l++) {
                        free(matriz->datos[k][l]);
                    }
                    free(matriz->datos[k]);
                }
                free(matriz->datos);
                free(matriz);
                return NULL;
            }
        }
    }
    
    return matriz;
}

// Llenar matriz 3D con patrón
void llenar_matriz_3d(Matriz3D* matriz) {
    for (int i = 0; i < matriz->dimensiones[0]; i++) {
        for (int j = 0; j < matriz->dimensiones[1]; j++) {
            for (int k = 0; k < matriz->dimensiones[2]; k++) {
                matriz->datos[i][j][k] = i * 100 + j * 10 + k;
            }
        }
    }
}

// Liberar matriz 3D
void liberar_matriz_3d(Matriz3D* matriz) {
    if (!matriz) return;
    
    for (int i = 0; i < matriz->dimensiones[0]; i++) {
        for (int j = 0; j < matriz->dimensiones[1]; j++) {
            free(matriz->datos[i][j]);
        }
        free(matriz->datos[i]);
    }
    free(matriz->datos);
    free(matriz);
}

// Sistema de cache consciente usando punteros
typedef struct {
    void* datos;
    size_t tamaño;
    size_t capacidad;
    int alineacion;
} BufferAlineado;

BufferAlineado* crear_buffer_alineado(size_t tamaño, int alineacion) {
    BufferAlineado* buffer = malloc(sizeof(BufferAlineado));
    if (!buffer) return NULL;
    
    // Asignar memoria extra para garantizar alineación
    size_t tamaño_total = tamaño + alineacion;
    void* memoria_cruda = malloc(tamaño_total);
    if (!memoria_cruda) {
        free(buffer);
        return NULL;
    }
    
    // Calcular dirección alineada
    uintptr_t direccion = (uintptr_t)memoria_cruda;
    uintptr_t direccion_alineada = (direccion + alineacion - 1) & ~(alineacion - 1);
    
    buffer->datos = (void*)direccion_alineada;
    buffer->tamaño = tamaño;
    buffer->capacidad = tamaño_total;
    buffer->alineacion = alineacion;
    
    // Guardar la dirección original para free() posterior
    *((void**)memoria_cruda) = memoria_cruda;
    
    return buffer;
}

// Pool de objetos con punteros inteligentes
typedef struct objeto_pool {
    void* memoria_base;
    void** objetos_libres;
    int* estados; // 0 = libre, 1 = usado
    size_t tamaño_objeto;
    size_t num_objetos;
    size_t siguiente_libre;
} ObjetoPool;

ObjetoPool* crear_objeto_pool(size_t tamaño_objeto, size_t num_objetos) {
    ObjetoPool* pool = malloc(sizeof(ObjetoPool));
    if (!pool) return NULL;
    
    pool->tamaño_objeto = tamaño_objeto;
    pool->num_objetos = num_objetos;
    pool->siguiente_libre = 0;
    
    // Asignar memoria para objetos
    pool->memoria_base = aligned_alloc(64, tamaño_objeto * num_objetos);
    if (!pool->memoria_base) {
        free(pool);
        return NULL;
    }
    
    // Inicializar arrays de control
    pool->objetos_libres = malloc(num_objetos * sizeof(void*));
    pool->estados = calloc(num_objetos, sizeof(int));
    
    if (!pool->objetos_libres || !pool->estados) {
        free(pool->memoria_base);
        free(pool->objetos_libres);
        free(pool->estados);
        free(pool);
        return NULL;
    }
    
    // Inicializar lista de objetos libres
    for (size_t i = 0; i < num_objetos; i++) {
        pool->objetos_libres[i] = (char*)pool->memoria_base + i * tamaño_objeto;
    }
    
    return pool;
}

void* pool_alloc_objeto(ObjetoPool* pool) {
    if (!pool || pool->siguiente_libre >= pool->num_objetos) {
        return NULL;
    }
    
    void* objeto = pool->objetos_libres[pool->siguiente_libre];
    pool->estados[pool->siguiente_libre] = 1;
    
    // Buscar siguiente objeto libre
    do {
        pool->siguiente_libre++;
    } while (pool->siguiente_libre < pool->num_objetos && 
             pool->estados[pool->siguiente_libre] == 1);
    
    return objeto;
}

void pool_free_objeto(ObjetoPool* pool, void* objeto) {
    if (!pool || !objeto) return;
    
    // Calcular índice del objeto
    ptrdiff_t offset = (char*)objeto - (char*)pool->memoria_base;
    size_t indice = offset / pool->tamaño_objeto;
    
    if (indice < pool->num_objetos && pool->estados[indice] == 1) {
        pool->estados[indice] = 0;
        if (indice < pool->siguiente_libre) {
            pool->siguiente_libre = indice;
        }
    }
}

// Técnica de copy-on-write simplificada
typedef struct {
    void* datos;
    size_t tamaño;
    int* ref_count;
    int es_copia;
} COWBuffer;

COWBuffer* crear_cow_buffer(size_t tamaño) {
    COWBuffer* buffer = malloc(sizeof(COWBuffer));
    if (!buffer) return NULL;
    
    buffer->datos = malloc(tamaño);
    buffer->ref_count = malloc(sizeof(int));
    if (!buffer->datos || !buffer->ref_count) {
        free(buffer->datos);
        free(buffer->ref_count);
        free(buffer);
        return NULL;
    }
    
    buffer->tamaño = tamaño;
    *(buffer->ref_count) = 1;
    buffer->es_copia = 0;
    
    return buffer;
}

COWBuffer* clonar_cow_buffer(COWBuffer* original) {
    if (!original) return NULL;
    
    COWBuffer* clon = malloc(sizeof(COWBuffer));
    if (!clon) return NULL;
    
    clon->datos = original->datos;
    clon->tamaño = original->tamaño;
    clon->ref_count = original->ref_count;
    clon->es_copia = 1;
    
    (*(clon->ref_count))++;
    
    return clon;
}

void* cow_get_writable(COWBuffer* buffer) {
    if (!buffer) return NULL;
    
    // Si somos la única referencia, podemos escribir directamente
    if (*(buffer->ref_count) == 1) {
        return buffer->datos;
    }
    
    // Necesitamos hacer copia real
    void* nuevos_datos = malloc(buffer->tamaño);
    if (!nuevos_datos) return NULL;
    
    memcpy(nuevos_datos, buffer->datos, buffer->tamaño);
    
    // Decrementar referencia original
    (*(buffer->ref_count))--;
    
    // Crear nueva referencia
    buffer->datos = nuevos_datos;
    buffer->ref_count = malloc(sizeof(int));
    *(buffer->ref_count) = 1;
    
    return buffer->datos;
}

int main() {
    printf("=== EJEMPLO DE PUNTEROS MÚLTIPLES AVANZADOS ===\n\n");
    
    // 1. MATRIZ 3D CON PUNTEROS TRIPLES
    printf("1. MATRIZ 3D DINÁMICA:\n");
    
    Matriz3D* matriz = crear_matriz_3d(3, 4, 5);
    if (matriz) {
        llenar_matriz_3d(matriz);
        
        printf("Matriz 3D creada: %dx%dx%d\n", 
               matriz->dimensiones[0], matriz->dimensiones[1], matriz->dimensiones[2]);
        
        // Mostrar algunos valores
        printf("Algunos valores: ");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    printf("[%d][%d][%d]=%d ", i, j, k, matriz->datos[i][j][k]);
                }
            }
        }
        printf("\n\n");
        
        liberar_matriz_3d(matriz);
    }
    
    // 2. POOL DE OBJETOS OPTIMIZADO
    printf("2. POOL DE OBJETOS:\n");
    
    typedef struct { int id; float valor; char nombre[16]; } TestObject;
    ObjetoPool* pool = crear_objeto_pool(sizeof(TestObject), 10);
    
    if (pool) {
        printf("Pool creado para %zu objetos de %zu bytes\n", 
               pool->num_objetos, pool->tamaño_objeto);
        
        // Asignar varios objetos
        TestObject* obj1 = (TestObject*)pool_alloc_objeto(pool);
        TestObject* obj2 = (TestObject*)pool_alloc_objeto(pool);
        TestObject* obj3 = (TestObject*)pool_alloc_objeto(pool);
        
        if (obj1 && obj2 && obj3) {
            obj1->id = 1; strcpy(obj1->nombre, "Objeto1");
            obj2->id = 2; strcpy(obj2->nombre, "Objeto2");
            obj3->id = 3; strcpy(obj3->nombre, "Objeto3");
            
            printf("Objetos asignados exitosamente\n");
            
            pool_free_objeto(pool, obj2);
            printf("Objeto 2 liberado\n");
            
            TestObject* obj4 = (TestObject*)pool_alloc_objeto(pool);
            if (obj4) {
                printf("Objeto 4 reutiliza espacio de objeto 2\n");
            }
        }
        
        free(pool->memoria_base);
        free(pool->objetos_libres);
        free(pool->estados);
        free(pool);
    }
    printf("\n");
    
    // 3. COPY-ON-WRITE BUFFER
    printf("3. COPY-ON-WRITE BUFFER:\n");
    
    COWBuffer* original = crear_cow_buffer(1024);
    if (original) {
        strcpy((char*)original->datos, "Datos originales");
        printf("Buffer original creado\n");
        
        COWBuffer* copia = clonar_cow_buffer(original);
        printf("Referencias: %d\n", *(original->ref_count));
        
        // Intentar escribir en la copia
        char* datos_escribibles = (char*)cow_get_writable(copia);
        if (datos_escribibles) {
            strcpy(datos_escribibles, "Datos modificados");
            printf("Copia modificada, referencias originales: %d\n", 
                   *(original->ref_count));
        }
        
        printf("Original: '%s'\n", (char*)original->datos);
        printf("Copia: '%s'\n", (char*)copia->datos);
        
        // Cleanup
        free(original->datos);
        free(original->ref_count);
        free(original);
        free(copia->datos);
        free(copia->ref_count);
        free(copia);
    }
    
    printf("\n=== FIN DEL EJEMPLO ===\n");
    
    return 0;
}

/*
 * TÉCNICAS AVANZADAS DEMOSTRADAS:
 * 
 * PUNTEROS MÚLTIPLES:
 * - Matrices multidimensionales dinámicas
 * - Gestión compleja de memoria anidada
 * - Cleanup seguro en caso de errores
 * 
 * OPTIMIZACIONES DE MEMORIA:
 * - Alineación de memoria para cache
 * - Pools de objetos para asignación rápida
 * - Copy-on-write para compartir datos
 * 
 * TÉCNICAS DE SISTEMAS:
 * - Manipulación directa de direcciones
 * - Gestión de referencias compartidas
 * - Optimización consciente del cache
 * 
 * APLICACIONES PRÁCTICAS:
 * - Gráficos 3D y procesamiento de imágenes
 * - Sistemas de gestión de memoria
 * - Compiladores y interpretadores
 * - Sistemas operativos y drivers
 */