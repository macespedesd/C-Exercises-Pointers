/*
 * EJERCICIO 4: Recorrer Arreglos con Punteros
 * 
 * OBJETIVO:
 * Dominar la relación entre punteros y arreglos, aprender diferentes
 * formas de recorrer arreglos usando punteros y aritmética de punteros.
 * 
 * INSTRUCCIONES:
 * 1. Implementa funciones que recorran arreglos usando punteros
 * 2. Practica diferentes formas de acceder a elementos de arreglos
 * 3. Implementa operaciones comunes: buscar, contar, modificar
 * 4. Compara la eficiencia de diferentes métodos de acceso
 * 
 * NIVEL: Easy (Básico)
 * TIEMPO ESTIMADO: 35-40 minutos
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>

// TODO: PARTE 1 - Función para imprimir arreglo usando punteros
// Imprime todos los elementos de un arreglo usando únicamente punteros
void imprimir_arreglo(int *arr, int tamaño) {
    // TU CÓDIGO AQUÍ:
    // Usa un puntero para recorrer el arreglo e imprimir cada elemento
    // Método 1: Usa aritmética de punteros (arr + i)
    
    printf("Elementos del arreglo: ");
    
    
    
    printf("\n");
}

// TODO: PARTE 2 - Función para calcular suma usando punteros
// Calcula la suma de todos los elementos usando punteros
int sumar_arreglo(int *arr, int tamaño) {
    // TU CÓDIGO AQUÍ:
    // Usa un puntero para recorrer y sumar todos los elementos
    // Método 2: Usa incremento de puntero (ptr++)
    
    int suma = 0;
    
    
    
    
    return suma;
}

// TODO: PARTE 3 - Función para buscar un elemento
// Busca un elemento en el arreglo y devuelve su posición (o -1 si no existe)
int buscar_elemento(int *arr, int tamaño, int elemento) {
    // TU CÓDIGO AQUÍ:
    // Recorre el arreglo buscando el elemento
    // Devuelve la posición (índice) si lo encuentra, -1 si no
    
    
    
    
    
    
    return -1; // No encontrado
}

// TODO: PARTE 4 - Función para contar elementos pares
// Cuenta cuántos números pares hay en el arreglo
int contar_pares(int *arr, int tamaño) {
    // TU CÓDIGO AQUÍ:
    // Recorre el arreglo y cuenta elementos que sean divisibles por 2
    
    int contador = 0;
    
    
    
    
    return contador;
}

// TODO: PARTE 5 - Función para duplicar elementos
// Multiplica todos los elementos del arreglo por 2
void duplicar_elementos(int *arr, int tamaño) {
    // TU CÓDIGO AQUÍ:
    // Recorre el arreglo y multiplica cada elemento por 2
    // Modifica el arreglo original
    
    
    
    
}

// TODO: PARTE 6 - Función para encontrar el mayor elemento y su posición
// Encuentra el elemento mayor y guarda su valor y posición
void encontrar_mayor(int *arr, int tamaño, int *mayor_valor, int *mayor_posicion) {
    // TU CÓDIGO AQUÍ:
    // Recorre el arreglo para encontrar el mayor elemento
    // Guarda el valor en *mayor_valor y la posición en *mayor_posicion
    
    
    
    
    
    
    
}

// TODO: PARTE 7 - Función para invertir arreglo
// Invierte el orden de los elementos del arreglo
void invertir_arreglo(int *arr, int tamaño) {
    // TU CÓDIGO AQUÍ:
    // Usa dos punteros: uno al inicio y otro al final
    // Intercambia elementos y mueve los punteros hacia el centro
    
    
    
    
    
    
    
    
}

int main() {
    printf("=== EJERCICIO 4: RECORRER ARREGLOS CON PUNTEROS ===\n\n");
    
    // Arreglo de prueba
    int numeros[] = {15, 8, 23, 42, 7, 19, 34, 11, 26, 5};
    int tamaño = 10;
    
    // TODO: PARTE 8 - Probar impresión con punteros
    printf("PRUEBA 1: Imprimir Arreglo\n");
    printf("Arreglo original: ");
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    // TU CÓDIGO AQUÍ: Llama a imprimir_arreglo
    
    printf("\n");
    
    // TODO: PARTE 9 - Probar suma con punteros  
    printf("PRUEBA 2: Suma de Elementos\n");
    // TU CÓDIGO AQUÍ: Llama a sumar_arreglo y muestra el resultado
    
    
    printf("\n");
    
    // TODO: PARTE 10 - Probar búsqueda
    printf("PRUEBA 3: Búsqueda de Elementos\n");
    int buscar1 = 23, buscar2 = 100;
    
    // TU CÓDIGO AQUÍ: Busca buscar1 y buscar2, muestra los resultados
    
    
    
    printf("\n");
    
    // TODO: PARTE 11 - Probar conteo de pares
    printf("PRUEBA 4: Contar Números Pares\n");
    // TU CÓDIGO AQUÍ: Llama a contar_pares y muestra el resultado
    
    
    printf("\n");
    
    // TODO: PARTE 12 - Probar encontrar mayor
    printf("PRUEBA 5: Encontrar Mayor Elemento\n");
    int mayor_val, mayor_pos;
    
    // TU CÓDIGO AQUÍ: Llama a encontrar_mayor
    
    
    printf("Mayor elemento: %d en posición %d\n\n", mayor_val, mayor_pos);
    
    // TODO: PARTE 13 - Probar duplicación (modifica el arreglo)
    printf("PRUEBA 6: Duplicar Elementos\n");
    printf("Antes de duplicar: ");
    imprimir_arreglo(numeros, tamaño);
    
    // TU CÓDIGO AQUÍ: Llama a duplicar_elementos
    
    
    printf("Después de duplicar: ");
    imprimir_arreglo(numeros, tamaño);
    printf("\n");
    
    // TODO: PARTE 14 - Probar inversión
    printf("PRUEBA 7: Invertir Arreglo\n");
    printf("Antes de invertir: ");
    imprimir_arreglo(numeros, tamaño);
    
    // TU CÓDIGO AQUÍ: Llama a invertir_arreglo
    
    
    printf("Después de invertir: ");
    imprimir_arreglo(numeros, tamaño);
    printf("\n");
    
    // TODO: PARTE 15 - Experimento con diferentes tipos
    printf("EXPERIMENTO: Arreglo de Caracteres\n");
    char letras[] = {'H', 'O', 'L', 'A', '\0'};
    char *ptr_letra = letras;
    
    printf("Recorriendo caracteres con punteros: ");
    // TU CÓDIGO AQUÍ: Recorre e imprime el arreglo de caracteres
    // Usa ptr_letra y incremento hasta encontrar '\0'
    
    
    
    
    printf("\n");
    
    printf("\n=== FIN DEL EJERCICIO ===\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES:
 * 
 * EQUIVALENCIAS FUNDAMENTALES:
 * - arr[i] == *(arr + i)
 * - &arr[i] == (arr + i)
 * - arr == &arr[0]
 * 
 * FORMAS DE RECORRER ARREGLOS:
 * 1. Índices tradicionales: for(i=0; i<n; i++) arr[i]
 * 2. Aritmética de punteros: for(i=0; i<n; i++) *(arr + i)
 * 3. Incremento de punteros: while(ptr < arr + n) *ptr++
 * 
 * PISTAS PARA RESOLVER:
 * - Para recorrer: usa un bucle for o while con punteros
 * - Para modificar: usa *puntero = nuevo_valor
 * - Para buscar: compara *puntero con el valor buscado
 * - Para invertir: usa dos punteros (inicio y fin)
 * 
 * ERRORES COMUNES:
 * - Acceder fuera de los límites del arreglo
 * - Confundir ptr++ con *ptr++
 * - No inicializar punteros correctamente
 * - Olvidar que los arreglos se pasan por referencia automáticamente
 * 
 * VENTAJAS DE LOS PUNTEROS:
 * - Acceso más directo a la memoria
 * - Posible mejor rendimiento (menos cálculos de índices)
 * - Flexibilidad para trabajar con subarreglos
 * - Base para estructuras de datos avanzadas
 * 
 * NOTA IMPORTANTE:
 * En C, cuando pasas un arreglo a una función, realmente pasas
 * un puntero al primer elemento. Por eso int arr[] y int *arr
 * son equivalentes en parámetros de función.
 */