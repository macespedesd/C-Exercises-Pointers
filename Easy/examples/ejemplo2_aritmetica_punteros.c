/*
 * EJEMPLO 2: Aritmética de Punteros y Arreglos
 * 
 * Este ejemplo demuestra:
 * - Relación entre punteros y arreglos
 * - Aritmética de punteros (incremento/decremento)
 * - Recorrido de arreglos usando punteros
 * - Diferencia entre notación de arreglos y punteros
 * 
 * Autor: Ejercicios C - Punteros
 * Nivel: Easy (Básico)
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>

int main() {
    // Declaramos un arreglo de enteros
    int numeros[] = {10, 20, 30, 40, 50};
    int tamaño = 5;
    
    // Un puntero al primer elemento del arreglo
    int *ptr = numeros; // Equivale a: int *ptr = &numeros[0];
    
    printf("=== ARITMÉTICA DE PUNTEROS Y ARREGLOS ===\n\n");
    
    // Mostramos el arreglo usando notación tradicional
    printf("Arreglo usando notación tradicional:\n");
    for (int i = 0; i < tamaño; i++) {
        printf("  numeros[%d] = %d (dirección: %p)\n", 
               i, numeros[i], (void*)&numeros[i]);
    }
    printf("\n");
    
    // Mostramos el arreglo usando punteros
    printf("Arreglo usando punteros:\n");
    for (int i = 0; i < tamaño; i++) {
        printf("  *(ptr + %d) = %d (dirección: %p)\n", 
               i, *(ptr + i), (void*)(ptr + i));
    }
    printf("\n");
    
    // Recorremos el arreglo incrementando el puntero
    printf("Recorriendo con incremento de puntero:\n");
    int *ptr_actual = numeros;
    for (int i = 0; i < tamaño; i++) {
        printf("  *ptr_actual = %d (dirección: %p)\n", 
               *ptr_actual, (void*)ptr_actual);
        ptr_actual++; // Avanza al siguiente elemento
    }
    printf("\n");
    
    // Aritmética de punteros: suma y resta
    printf("Aritmética de punteros:\n");
    int *inicio = numeros;
    int *final = numeros + (tamaño - 1);
    
    printf("  Puntero al inicio: %p (valor: %d)\n", (void*)inicio, *inicio);
    printf("  Puntero al final: %p (valor: %d)\n", (void*)final, *final);
    printf("  Diferencia entre punteros: %ld elementos\n", final - inicio);
    printf("  Diferencia en bytes: %ld bytes\n\n", (char*)final - (char*)inicio);
    
    // Navegación bidireccional
    printf("Navegación desde el final hacia el inicio:\n");
    ptr_actual = final; // Empezamos desde el último elemento
    for (int i = tamaño - 1; i >= 0; i--) {
        printf("  Posición %d: *ptr_actual = %d\n", i, *ptr_actual);
        ptr_actual--; // Retrocede al elemento anterior
    }
    printf("\n");
    
    // Acceso aleatorio con punteros
    printf("Acceso aleatorio con punteros:\n");
    int *base = numeros;
    printf("  Elemento en posición 0: *(base + 0) = %d\n", *(base + 0));
    printf("  Elemento en posición 2: *(base + 2) = %d\n", *(base + 2));
    printf("  Elemento en posición 4: *(base + 4) = %d\n", *(base + 4));
    printf("\n");
    
    // Comparación de punteros
    printf("Comparación de punteros:\n");
    int *ptr1 = &numeros[1];
    int *ptr2 = &numeros[3];
    
    if (ptr1 < ptr2) {
        printf("  ptr1 (%p) está antes que ptr2 (%p) en memoria\n", 
               (void*)ptr1, (void*)ptr2);
    }
    
    // Modificación usando aritmética de punteros
    printf("\nModificando valores usando aritmética de punteros:\n");
    *(numeros + 2) = 999; // Modifica el tercer elemento
    printf("  Nuevo valor en posición 2: %d\n", numeros[2]);
    
    printf("\n=== FIN DEL EJEMPLO ===\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES:
 * 
 * 1. EQUIVALENCIA: numeros[i] es equivalente a *(numeros + i)
 * 2. ARITMÉTICA: ptr + n apunta n elementos adelante
 * 3. INCREMENTO: ptr++ avanza al siguiente elemento del tipo correspondiente
 * 4. DIFERENCIA: ptr2 - ptr1 da el número de elementos entre los punteros
 * 5. COMPARACIÓN: Se pueden comparar punteros que apunten al mismo arreglo
 * 
 * NOTAS IMPORTANTES:
 * - La aritmética de punteros considera el tamaño del tipo de dato
 * - int *ptr; ptr++ avanza 4 bytes (tamaño de int)
 * - char *ptr; ptr++ avanza 1 byte (tamaño de char)
 * - Siempre verificar que el puntero esté dentro de los límites del arreglo
 */