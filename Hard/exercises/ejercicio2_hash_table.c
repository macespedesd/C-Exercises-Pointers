/*
 * EJERCICIO 2: Tabla Hash con Manejo de Colisiones
 * 
 * OBJETIVO: Implementar una tabla hash completa con función hash,
 * manejo de colisiones y operaciones básicas.
 * 
 * NIVEL: Hard (Avanzado)
 * TIEMPO ESTIMADO: 65-75 minutos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMAÑO_TABLA 10

typedef struct entrada {
    char* clave;
    int valor;
    struct entrada* siguiente; // Para manejo de colisiones por encadenamiento
} Entrada;

typedef struct {
    Entrada** tabla;
    int tamaño;
    int elementos;
} TablaHash;

// TODO: Implementa todas las funciones de la tabla hash
unsigned int funcion_hash(const char* clave, int tamaño_tabla) {
    // TU CÓDIGO AQUÍ: Implementa función hash (ej: djb2, sdbm)
    return 0;
}

TablaHash* crear_tabla_hash(int tamaño) {
    // TU CÓDIGO AQUÍ: Crear e inicializar tabla hash
    return NULL;
}

void insertar(TablaHash* tabla, const char* clave, int valor) {
    // TU CÓDIGO AQUÍ: Insertar elemento (manejar colisiones)
}

int buscar(TablaHash* tabla, const char* clave) {
    // TU CÓDIGO AQUÍ: Buscar elemento por clave
    return -1; // No encontrado
}

int eliminar(TablaHash* tabla, const char* clave) {
    // TU CÓDIGO AQUÍ: Eliminar elemento
    return 0; // No eliminado
}

void imprimir_tabla(TablaHash* tabla) {
    // TU CÓDIGO AQUÍ: Mostrar contenido de la tabla
}

float factor_carga(TablaHash* tabla) {
    // TU CÓDIGO AQUÍ: Calcular factor de carga
    return 0.0;
}

void redimensionar_tabla(TablaHash* tabla) {
    // TU CÓDIGO AQUÍ: Redimensionar cuando factor de carga > 0.75
}

void liberar_tabla(TablaHash* tabla) {
    // TU CÓDIGO AQUÍ: Liberar toda la memoria
}

int main() {
    printf("=== EJERCICIO 2: TABLA HASH ===\n");
    
    // TODO: Implementa un programa que:
    // 1. Cree una tabla hash
    // 2. Inserte múltiples elementos
    // 3. Maneje colisiones correctamente
    // 4. Realice búsquedas y eliminaciones
    // 5. Muestre estadísticas (factor de carga)
    // 6. Redimensione si es necesario
    
    return 0;
}

/*
 * TABLA HASH:
 * - Mapeo clave → valor usando función hash
 * - Colisiones: Encadenamiento vs Direccionamiento abierto
 * - Factor de carga: elementos / tamaño_tabla
 * - Redimensionamiento cuando factor > 0.75
 */