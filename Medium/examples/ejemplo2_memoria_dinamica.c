/*
 * EJEMPLO 2: Memoria Dinámica en C
 * 
 * Este ejemplo demuestra:
 * - Asignación dinámica de memoria con malloc()
 * - Liberación de memoria con free()
 * - Redimensionamiento con realloc()
 * - Mejores prácticas para evitar memory leaks
 * - Detección y manejo de errores de memoria
 * 
 * Autor: Ejercicios C - Punteros
 * Nivel: Medium (Intermedio)
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para imprimir un arreglo dinámico
void imprimir_arreglo_dinamico(int *arr, int tamaño, const char *titulo) {
    printf("%s: ", titulo);
    if (arr == NULL) {
        printf("(NULL)\n");
        return;
    }
    
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", arr[i]);
    }
    printf("(tamaño: %d)\n", tamaño);
}

// Función para llenar un arreglo con valores secuenciales
void llenar_arreglo(int *arr, int tamaño, int inicio) {
    if (arr == NULL) return;
    
    for (int i = 0; i < tamaño; i++) {
        arr[i] = inicio + i;
    }
}

// Función que demuestra un memory leak (¡MAL EJEMPLO!)
void ejemplo_memory_leak() {
    printf("  [ADVERTENCIA] Creando memory leak intencionalmente...\n");
    
    int *ptr_leak = (int*)malloc(10 * sizeof(int));
    if (ptr_leak != NULL) {
        *ptr_leak = 42;
        printf("  Asignada memoria en %p con valor %d\n", 
               (void*)ptr_leak, *ptr_leak);
    }
    
    // ¡ERROR! No liberamos la memoria antes de salir de la función
    // Esto causa un memory leak
    printf("  Saliendo de la función SIN liberar memoria... ¡Memory leak!\n");
}

// Función que maneja memoria correctamente
int* crear_arreglo_seguro(int tamaño) {
    if (tamaño <= 0) {
        printf("  Error: Tamaño inválido (%d)\n", tamaño);
        return NULL;
    }
    
    int *arr = (int*)malloc(tamaño * sizeof(int));
    if (arr == NULL) {
        printf("  Error: No se pudo asignar memoria para %d elementos\n", tamaño);
        return NULL;
    }
    
    printf("  Memoria asignada correctamente para %d elementos en %p\n", 
           tamaño, (void*)arr);
    return arr;
}

int main() {
    printf("=== EJEMPLO DE MEMORIA DINÁMICA ===\n\n");
    
    // 1. MALLOC BÁSICO
    printf("1. ASIGNACIÓN BÁSICA CON MALLOC:\n");
    
    int tamaño_inicial = 5;
    int *numeros = (int*)malloc(tamaño_inicial * sizeof(int));
    
    // Siempre verificar que malloc no retorne NULL
    if (numeros == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return 1;
    }
    
    printf("Memoria asignada para %d enteros en dirección: %p\n", 
           tamaño_inicial, (void*)numeros);
    printf("Tamaño de cada entero: %zu bytes\n", sizeof(int));
    printf("Memoria total asignada: %zu bytes\n\n", 
           tamaño_inicial * sizeof(int));
    
    // Llenar el arreglo
    llenar_arreglo(numeros, tamaño_inicial, 10);
    imprimir_arreglo_dinamico(numeros, tamaño_inicial, "Arreglo inicial");
    printf("\n");
    
    // 2. REALLOC - REDIMENSIONAR MEMORIA
    printf("2. REDIMENSIONAMIENTO CON REALLOC:\n");
    
    int nuevo_tamaño = 8;
    printf("Intentando redimensionar de %d a %d elementos...\n", 
           tamaño_inicial, nuevo_tamaño);
    
    int *numeros_redim = (int*)realloc(numeros, nuevo_tamaño * sizeof(int));
    
    if (numeros_redim == NULL) {
        printf("Error en realloc, manteniendo arreglo original\n");
        // numeros sigue siendo válido si realloc falla
    } else {
        numeros = numeros_redim; // Actualizar puntero
        printf("Redimensionamiento exitoso, nueva dirección: %p\n", 
               (void*)numeros);
        
        // Llenar los nuevos elementos
        for (int i = tamaño_inicial; i < nuevo_tamaño; i++) {
            numeros[i] = i * 10;
        }
        
        tamaño_inicial = nuevo_tamaño;
    }
    
    imprimir_arreglo_dinamico(numeros, tamaño_inicial, "Arreglo redimensionado");
    printf("\n");
    
    // 3. REDUCIR TAMAÑO
    printf("3. REDUCIR TAMAÑO DEL ARREGLO:\n");
    
    int tamaño_reducido = 3;
    numeros = (int*)realloc(numeros, tamaño_reducido * sizeof(int));
    
    printf("Arreglo reducido a %d elementos\n", tamaño_reducido);
    imprimir_arreglo_dinamico(numeros, tamaño_reducido, "Arreglo reducido");
    printf("\n");
    
    // 4. CALLOC - MEMORIA INICIALIZADA EN CERO
    printf("4. ASIGNACIÓN CON CALLOC (INICIALIZADA EN CERO):\n");
    
    int tamaño_calloc = 6;
    int *ceros = (int*)calloc(tamaño_calloc, sizeof(int));
    
    if (ceros != NULL) {
        printf("Memoria asignada con calloc en: %p\n", (void*)ceros);
        imprimir_arreglo_dinamico(ceros, tamaño_calloc, "Arreglo con calloc");
        
        // Modificar algunos valores
        ceros[2] = 100;
        ceros[4] = 200;
        imprimir_arreglo_dinamico(ceros, tamaño_calloc, "Después de modificar");
    }
    printf("\n");
    
    // 5. ARREGLO DINÁMICO DE CADENAS
    printf("5. ARREGLO DINÁMICO DE CADENAS:\n");
    
    int num_cadenas = 3;
    char **cadenas = (char**)malloc(num_cadenas * sizeof(char*));
    
    if (cadenas != NULL) {
        // Asignar memoria para cada cadena
        cadenas[0] = (char*)malloc(20 * sizeof(char));
        cadenas[1] = (char*)malloc(30 * sizeof(char));
        cadenas[2] = (char*)malloc(25 * sizeof(char));
        
        // Verificar que todas las asignaciones fueron exitosas
        if (cadenas[0] && cadenas[1] && cadenas[2]) {
            strcpy(cadenas[0], "Programación");
            strcpy(cadenas[1], "Estructuras de Datos");
            strcpy(cadenas[2], "Algoritmos");
            
            printf("Cadenas dinámicas:\n");
            for (int i = 0; i < num_cadenas; i++) {
                printf("  cadenas[%d]: \"%s\" (dirección: %p)\n", 
                       i, cadenas[i], (void*)cadenas[i]);
            }
        }
    }
    printf("\n");
    
    // 6. EJEMPLO DE MEMORY LEAK (EDUCATIVO)
    printf("6. DEMOSTRACIÓN DE MEMORY LEAK:\n");
    ejemplo_memory_leak();
    printf("\n");
    
    // 7. MANEJO SEGURO DE MEMORIA
    printf("7. MANEJO SEGURO DE MEMORIA:\n");
    int *arreglo_seguro = crear_arreglo_seguro(4);
    
    if (arreglo_seguro != NULL) {
        llenar_arreglo(arreglo_seguro, 4, 100);
        imprimir_arreglo_dinamico(arreglo_seguro, 4, "Arreglo seguro");
        
        // Liberar correctamente
        free(arreglo_seguro);
        arreglo_seguro = NULL; // Prevenir uso accidental
        printf("Memoria del arreglo seguro liberada correctamente\n");
    }
    printf("\n");
    
    // 8. LIBERACIÓN DE TODA LA MEMORIA
    printf("8. LIBERANDO TODA LA MEMORIA ASIGNADA:\n");
    
    // Liberar arreglo principal
    if (numeros != NULL) {
        free(numeros);
        numeros = NULL;
        printf("Memoria de 'numeros' liberada\n");
    }
    
    // Liberar arreglo de calloc
    if (ceros != NULL) {
        free(ceros);
        ceros = NULL;
        printf("Memoria de 'ceros' liberada\n");
    }
    
    // Liberar arreglo de cadenas
    if (cadenas != NULL) {
        for (int i = 0; i < num_cadenas; i++) {
            if (cadenas[i] != NULL) {
                free(cadenas[i]);
                cadenas[i] = NULL;
            }
        }
        free(cadenas);
        cadenas = NULL;
        printf("Memoria de 'cadenas' liberada\n");
    }
    
    printf("\n=== FIN DEL EJEMPLO ===\n");
    printf("¡Toda la memoria ha sido liberada correctamente!\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES SOBRE MEMORIA DINÁMICA:
 * 
 * FUNCIONES PRINCIPALES:
 * - malloc(size): Asigna 'size' bytes de memoria sin inicializar
 * - calloc(num, size): Asigna memoria para 'num' elementos e inicializa en 0
 * - realloc(ptr, size): Redimensiona un bloque de memoria previamente asignado
 * - free(ptr): Libera memoria previamente asignada
 * 
 * REGLAS DE ORO:
 * 1. Siempre verificar que malloc/calloc/realloc no retornen NULL
 * 2. Por cada malloc/calloc debe haber exactamente un free
 * 3. No usar memoria después de llamar free
 * 4. Asignar NULL al puntero después de free
 * 5. No hacer free de memoria ya liberada (double free)
 * 
 * ERRORES COMUNES:
 * - Memory leak: No liberar memoria asignada
 * - Use after free: Usar memoria después de liberarla
 * - Double free: Liberar la misma memoria dos veces
 * - Buffer overflow: Escribir fuera de los límites asignados
 * - NULL pointer dereference: Usar un puntero NULL
 * 
 * HERRAMIENTAS ÚTILES:
 * - valgrind: Detecta memory leaks y errores de memoria (Linux/Mac)
 * - AddressSanitizer: Detector de errores de memoria (gcc -fsanitize=address)
 * - Static analyzers: Herramientas que analizan código sin ejecutarlo
 * 
 * BUENAS PRÁCTICAS:
 * - Inicializar punteros en NULL
 * - Verificar retorno de funciones de asignación
 * - Liberar memoria en orden inverso a la asignación
 * - Usar const cuando no se modifique la memoria
 * - Considerar usar struct para agrupar datos relacionados
 */