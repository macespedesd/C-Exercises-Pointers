/*
 * EJERCICIO 3: Operaciones Matemáticas con Punteros
 * 
 * OBJETIVO:
 * Practicar el uso de punteros para realizar operaciones matemáticas
 * y devolver múltiples resultados desde una función.
 * 
 * INSTRUCCIONES:
 * 1. Implementa funciones que usen punteros para devolver múltiples valores
 * 2. Crea una calculadora básica que opere con punteros
 * 3. Implementa funciones de estadísticas básicas (máximo, mínimo, promedio)
 * 4. Practica el paso de parámetros por referencia
 * 
 * NIVEL: Easy (Básico)
 * TIEMPO ESTIMADO: 30-35 minutos
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>

// TODO: PARTE 1 - Función que devuelve suma y producto
// Una función normal solo puede devolver un valor
// Con punteros podemos "devolver" múltiples valores
void suma_y_producto(int a, int b, int *suma, int *producto) {
    // TU CÓDIGO AQUÍ:
    // Calcula la suma y producto de a y b
    // Guarda los resultados en las direcciones apuntadas por suma y producto
    
    
    
}

// TODO: PARTE 2 - Función para operaciones básicas
// Implementa una función que calcule suma, resta, multiplicación y división
void operaciones_basicas(float a, float b, float *suma, float *resta, 
                        float *multiplicacion, float *division) {
    // TU CÓDIGO AQUÍ:
    // Calcula todas las operaciones básicas
    // Nota: Verifica que b no sea 0 antes de dividir
    
    
    
    
    
    
}

// TODO: PARTE 3 - Función para encontrar máximo y mínimo
// Encuentra el mayor y menor valor entre dos números
void max_min(int a, int b, int *maximo, int *minimo) {
    // TU CÓDIGO AQUÍ:
    // Compara a y b, asigna el mayor a *maximo y el menor a *minimo
    
    
    
    
}

// TODO: PARTE 4 - Función para estadísticas de un arreglo
// Calcula el máximo, mínimo y suma de un arreglo
void estadisticas_arreglo(int arreglo[], int tamaño, int *maximo, 
                         int *minimo, int *suma) {
    // TU CÓDIGO AQUÍ:
    // Inicializa maximo y minimo con el primer elemento
    // Recorre el arreglo y actualiza los valores según corresponda
    // También calcula la suma total
    
    
    
    
    
    
    
    
    
}

// TODO: PARTE 5 - Función para intercambiar si está desordenado
// Si a > b, los intercambia para que a <= b
void ordenar_dos_numeros(int *a, int *b) {
    // TU CÓDIGO AQUÍ:
    // Si *a > *b, intercambialos
    
    
    
    
    
}

int main() {
    printf("=== EJERCICIO 3: OPERACIONES MATEMÁTICAS CON PUNTEROS ===\n\n");
    
    // TODO: PARTE 6 - Probar suma y producto
    printf("PRUEBA 1: Suma y Producto\n");
    int num1 = 6, num2 = 7;
    int resultado_suma, resultado_producto;
    
    // TU CÓDIGO AQUÍ: Llama a suma_y_producto
    
    
    printf("Números: %d y %d\n", num1, num2);
    printf("Suma: %d, Producto: %d\n\n", resultado_suma, resultado_producto);
    
    // TODO: PARTE 7 - Probar operaciones básicas
    printf("PRUEBA 2: Operaciones Básicas\n");
    float a = 15.5f, b = 3.0f;
    float r_suma, r_resta, r_mult, r_div;
    
    // TU CÓDIGO AQUÍ: Llama a operaciones_basicas
    
    
    printf("Números: %.1f y %.1f\n", a, b);
    printf("Suma: %.2f\n", r_suma);
    printf("Resta: %.2f\n", r_resta);
    printf("Multiplicación: %.2f\n", r_mult);
    printf("División: %.2f\n\n", r_div);
    
    // TODO: PARTE 8 - Probar máximo y mínimo
    printf("PRUEBA 3: Máximo y Mínimo\n");
    int x = 25, y = 18;
    int mayor, menor;
    
    // TU CÓDIGO AQUÍ: Llama a max_min
    
    
    printf("Números: %d y %d\n", x, y);
    printf("Máximo: %d, Mínimo: %d\n\n", mayor, menor);
    
    // TODO: PARTE 9 - Probar estadísticas de arreglo
    printf("PRUEBA 4: Estadísticas de Arreglo\n");
    int numeros[] = {45, 12, 78, 23, 67, 34, 89, 56};
    int tamaño = 8;
    int max_arr, min_arr, suma_arr;
    
    // TU CÓDIGO AQUÍ: Llama a estadisticas_arreglo
    
    
    printf("Arreglo: ");
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    printf("Máximo: %d\n", max_arr);
    printf("Mínimo: %d\n", min_arr);
    printf("Suma: %d\n", suma_arr);
    printf("Promedio: %.2f\n\n", (float)suma_arr / tamaño);
    
    // TODO: PARTE 10 - Probar ordenamiento de dos números
    printf("PRUEBA 5: Ordenar Dos Números\n");
    int primero = 30, segundo = 10;
    
    printf("Antes: primero = %d, segundo = %d\n", primero, segundo);
    
    // TU CÓDIGO AQUÍ: Llama a ordenar_dos_numeros
    
    
    printf("Después: primero = %d, segundo = %d\n", primero, segundo);
    printf("Estado: %s\n\n", 
           (primero <= segundo) ? "ORDENADOS CORRECTAMENTE" : "NECESITAN MÁS TRABAJO");
    
    // TODO: PARTE 11 - Experimento con calculadora
    printf("EXPERIMENTO: Mini Calculadora\n");
    float valor1 = 8.5f, valor2 = 2.5f;
    float calc_suma, calc_resta, calc_mult, calc_div;
    
    // TU CÓDIGO AQUÍ: Usa la función operaciones_basicas como calculadora
    
    
    printf("Calculadora: %.1f y %.1f\n", valor1, valor2);
    printf("  %.1f + %.1f = %.2f\n", valor1, valor2, calc_suma);
    printf("  %.1f - %.1f = %.2f\n", valor1, valor2, calc_resta);
    printf("  %.1f * %.1f = %.2f\n", valor1, valor2, calc_mult);
    printf("  %.1f / %.1f = %.2f\n", valor1, valor2, calc_div);
    
    printf("\n=== FIN DEL EJERCICIO ===\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES:
 * 
 * MÚLTIPLES VALORES DE RETORNO:
 * - Una función normal solo puede retornar un valor con return
 * - Con punteros, podemos "retornar" múltiples valores
 * - Los parámetros de salida se marcan típicamente con *
 * 
 * PATRÓN COMÚN:
 * void funcion(int entrada1, int entrada2, int *salida1, int *salida2) {
 *     *salida1 = calculo1;
 *     *salida2 = calculo2;
 * }
 * 
 * PISTAS PARA RESOLVER:
 * 1. Usa * para asignar valores a través de punteros
 * 2. Usa & cuando llames las funciones para pasar direcciones
 * 3. Para división, siempre verifica que el divisor no sea 0
 * 4. Para máximo/mínimo usa operadores de comparación if/else
 * 
 * ERRORES COMUNES:
 * - Olvidar usar * al asignar valores en la función
 * - Olvidar usar & al llamar la función
 * - No inicializar variables antes de usarlas en comparaciones
 * - División por cero sin verificar
 * 
 * VENTAJAS DE ESTE ENFOQUE:
 * - Una sola función puede calcular múltiples resultados
 * - Más eficiente que llamar múltiples funciones
 * - Permite validaciones centralizadas
 */