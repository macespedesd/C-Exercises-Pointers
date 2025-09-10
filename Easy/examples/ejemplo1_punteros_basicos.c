/*
 * EJEMPLO 1: Punteros Básicos en C
 * 
 * Este ejemplo muestra los conceptos fundamentales de los punteros:
 * - Declaración de punteros
 * - Inicialización con el operador &
 * - Desreferencia con el operador *
 * - Diferencia entre la dirección y el valor
 * 
 * Autor: Ejercicios C - Punteros
 * Nivel: Easy (Básico)
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>

int main() {
    // Declaramos una variable entera normal
    int numero = 42;
    
    // Declaramos un puntero a entero
    // Un puntero es una variable que almacena la dirección de memoria de otra variable
    int *ptr_numero;
    
    printf("=== EJEMPLO DE PUNTEROS BÁSICOS ===\n\n");
    
    // Mostramos el valor y la dirección de la variable original
    printf("Variable 'numero':\n");
    printf("  Valor: %d\n", numero);
    printf("  Dirección en memoria: %p\n\n", (void*)&numero);
    
    // Asignamos la dirección de 'numero' al puntero
    // El operador & obtiene la dirección de una variable
    ptr_numero = &numero;
    
    printf("Puntero 'ptr_numero':\n");
    printf("  Dirección que contiene: %p\n", (void*)ptr_numero);
    printf("  Valor al que apunta: %d\n", *ptr_numero);
    printf("  Dirección del propio puntero: %p\n\n", (void*)&ptr_numero);
    
    // Modificamos el valor usando el puntero
    // El operador * desreferencia el puntero (accede al valor)
    printf("Modificando el valor usando el puntero...\n");
    *ptr_numero = 100;
    
    printf("Después de modificar con *ptr_numero = 100:\n");
    printf("  numero: %d\n", numero);
    printf("  *ptr_numero: %d\n\n", *ptr_numero);
    
    // Ejemplo de puntero nulo
    int *ptr_nulo = NULL;
    printf("Puntero nulo:\n");
    printf("  Valor del puntero nulo: %p\n", (void*)ptr_nulo);
    printf("  (NULL indica que no apunta a ningún lugar válido)\n\n");
    
    // Ejemplo con diferentes tipos de datos
    char letra = 'A';
    char *ptr_letra = &letra;
    
    float decimal = 3.14f;
    float *ptr_decimal = &decimal;
    
    printf("Punteros con diferentes tipos:\n");
    printf("  char letra = '%c', puntero: %p\n", *ptr_letra, (void*)ptr_letra);
    printf("  float decimal = %.2f, puntero: %p\n", *ptr_decimal, (void*)ptr_decimal);
    
    printf("\n=== FIN DEL EJEMPLO ===\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES:
 * 
 * 1. DECLARACIÓN: int *ptr; declara un puntero a entero
 * 2. INICIALIZACIÓN: ptr = &variable; asigna la dirección de 'variable' al puntero
 * 3. DESREFERENCIA: *ptr accede al valor almacenado en la dirección del puntero
 * 4. NULL: Valor especial que indica que el puntero no apunta a nada válido
 * 5. TIPOS: Los punteros deben coincidir con el tipo de dato al que apuntan
 * 
 * ERRORES COMUNES:
 * - Usar un puntero sin inicializar
 * - Confundir * en declaración con * en desreferencia
 * - Intentar desreferenciar un puntero NULL
 */