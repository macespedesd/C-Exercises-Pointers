/*
 * EJERCICIO 2: Intercambio de Valores usando Punteros
 * 
 * OBJETIVO:
 * Aprender cómo los punteros permiten que las funciones modifiquen
 * variables del programa principal. Implementar una función de intercambio.
 * 
 * INSTRUCCIONES:
 * 1. Implementa una función que intercambie dos enteros usando punteros
 * 2. Implementa una función que intercambie dos caracteres usando punteros
 * 3. Prueba las funciones con diferentes valores
 * 4. Compara con un intento de intercambio SIN punteros (que no funcionará)
 * 
 * NIVEL: Easy (Básico)
 * TIEMPO ESTIMADO: 25-30 minutos
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>

// TODO: PARTE 1 - Función de intercambio INCORRECTA (sin punteros)
// Esta función NO funcionará para intercambiar valores
// Implementa esta función para entender por qué no funciona
void intercambio_incorrecto(int a, int b) {
    // TU CÓDIGO AQUÍ:
    // Intenta intercambiar a y b usando una variable temporal
    // (Nota: Esto no modificará las variables originales)
    
    
    
    
    printf("  Dentro de intercambio_incorrecto: a = %d, b = %d\n", a, b);
}

// TODO: PARTE 2 - Función de intercambio CORRECTA (con punteros)
// Esta función SÍ funcionará para intercambiar valores
void intercambio_correcto(int *a, int *b) {
    // TU CÓDIGO AQUÍ:
    // Intercambia los valores usando punteros y una variable temporal
    // Recuerda usar el operador * para acceder a los valores
    
    
    
    
    printf("  Dentro de intercambio_correcto: *a = %d, *b = %d\n", *a, *b);
}

// TODO: PARTE 3 - Función para intercambiar caracteres
// Implementa una función que intercambie dos caracteres usando punteros
void intercambio_caracteres(char *c1, char *c2) {
    // TU CÓDIGO AQUÍ:
    
    
    
    
    printf("  Dentro de intercambio_caracteres: *c1 = '%c', *c2 = '%c'\n", *c1, *c2);
}

int main() {
    printf("=== EJERCICIO 2: INTERCAMBIO CON PUNTEROS ===\n\n");
    
    // Variables para probar intercambio de enteros
    int num1 = 10;
    int num2 = 20;
    
    // Variables para probar intercambio de caracteres
    char letra1 = 'A';
    char letra2 = 'Z';
    
    // TODO: PARTE 4 - Probar intercambio incorrecto
    printf("PRUEBA 1: Intercambio INCORRECTO (sin punteros)\n");
    printf("Antes: num1 = %d, num2 = %d\n", num1, num2);
    
    intercambio_incorrecto(num1, num2);
    
    printf("Después: num1 = %d, num2 = %d\n", num1, num2);
    printf("Resultado: %s\n\n", 
           (num1 == 10 && num2 == 20) ? "NO SE INTERCAMBIARON" : "SE INTERCAMBIARON");
    
    // TODO: PARTE 5 - Probar intercambio correcto
    printf("PRUEBA 2: Intercambio CORRECTO (con punteros)\n");
    printf("Antes: num1 = %d, num2 = %d\n", num1, num2);
    
    // TU CÓDIGO AQUÍ: Llama a intercambio_correcto pasando las direcciones
    
    
    printf("Después: num1 = %d, num2 = %d\n", num1, num2);
    printf("Resultado: %s\n\n", 
           (num1 == 20 && num2 == 10) ? "SE INTERCAMBIARON CORRECTAMENTE" : "ALGO SALIÓ MAL");
    
    // TODO: PARTE 6 - Probar intercambio de caracteres
    printf("PRUEBA 3: Intercambio de caracteres\n");
    printf("Antes: letra1 = '%c', letra2 = '%c'\n", letra1, letra2);
    
    // TU CÓDIGO AQUÍ: Llama a intercambio_caracteres
    
    
    printf("Después: letra1 = '%c', letra2 = '%c'\n", letra1, letra2);
    printf("\n");
    
    // TODO: PARTE 7 - Experimento adicional
    // Crea dos variables float y intercambias usando punteros
    printf("EXPERIMENTO ADICIONAL: Intercambio de flotantes\n");
    
    float precio1 = 15.99f;
    float precio2 = 29.95f;
    
    printf("Antes: precio1 = %.2f, precio2 = %.2f\n", precio1, precio2);
    
    // TU CÓDIGO AQUÍ: Declara punteros e intercambia los flotantes
    // No necesitas crear una función nueva, hazlo directamente aquí
    
    
    
    
    
    printf("Después: precio1 = %.2f, precio2 = %.2f\n", precio1, precio2);
    
    printf("\n=== FIN DEL EJERCICIO ===\n");
    
    return 0;
}

/*
 * EXPLICACIÓN CONCEPTUAL:
 * 
 * ¿POR QUÉ NO FUNCIONA SIN PUNTEROS?
 * - Cuando pasas variables a una función, se crean COPIAS
 * - Modificar las copias no afecta las variables originales
 * - Esto se llama "paso por valor"
 * 
 * ¿POR QUÉ SÍ FUNCIONA CON PUNTEROS?
 * - Cuando pasas punteros, pasas las DIRECCIONES
 * - La función puede acceder directamente a la memoria original
 * - Esto se llama "paso por referencia" (simulado con punteros)
 * 
 * ALGORITMO DE INTERCAMBIO:
 * 1. temp = *a;     // Guarda el valor de a en temporal
 * 2. *a = *b;       // Copia el valor de b a a
 * 3. *b = temp;     // Copia el valor temporal a b
 * 
 * PISTAS PARA RESOLVER:
 * - Usa el operador & para pasar direcciones: intercambio(&var1, &var2)
 * - Usa el operador * para acceder a valores: *puntero
 * - Una variable temporal es necesaria para el intercambio
 * 
 * ERRORES COMUNES:
 * - Olvidar usar & al llamar la función
 * - Olvidar usar * dentro de la función
 * - No declarar variable temporal para el intercambio
 */