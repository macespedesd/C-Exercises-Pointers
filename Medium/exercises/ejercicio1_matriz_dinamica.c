/*
 * EJERCICIO 1: Matriz Dinámica
 * 
 * OBJETIVO:
 * Aprender a crear y manipular matrices bidimensionales usando memoria dinámica.
 * Practicar el manejo de punteros dobles para representar matrices.
 * 
 * INSTRUCCIONES:
 * 1. Implementa funciones para crear, llenar, imprimir y liberar matrices dinámicas
 * 2. Crea una matriz de enteros usando punteros dobles
 * 3. Implementa operaciones básicas como suma de matrices
 * 4. Asegúrate de manejar correctamente la memoria
 * 
 * NIVEL: Medium (Intermedio)
 * TIEMPO ESTIMADO: 45-50 minutos
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>
#include <stdlib.h>

// TODO: PARTE 1 - Función para crear matriz dinámica
// Crea una matriz de filas x columnas usando memoria dinámica
int** crear_matriz(int filas, int columnas) {
    // TU CÓDIGO AQUÍ:
    // 1. Asigna memoria para un arreglo de punteros (filas)
    // 2. Para cada fila, asigna memoria para las columnas
    // 3. Verifica que todas las asignaciones sean exitosas
    // 4. Si alguna falla, libera la memoria ya asignada y retorna NULL
    
    
    
    
    
    
    
    
    
    
    
    
    return NULL; // Cambia esto por el puntero a la matriz creada
}

// TODO: PARTE 2 - Función para llenar matriz con valores
// Llena la matriz con valores según un patrón
void llenar_matriz(int** matriz, int filas, int columnas, int valor_inicial) {
    // TU CÓDIGO AQUÍ:
    // Llena la matriz donde matriz[i][j] = valor_inicial + i * columnas + j
    // Esto crea un patrón secuencial
    
    
    
    
    
    
}

// TODO: PARTE 3 - Función para imprimir matriz
void imprimir_matriz(int** matriz, int filas, int columnas, const char* titulo) {
    // TU CÓDIGO AQUÍ:
    // Imprime la matriz de forma ordenada con el título dado
    // Verifica que matriz no sea NULL antes de imprimir
    
    
    
    
    
    
    
    
    
}

// TODO: PARTE 4 - Función para liberar matriz
void liberar_matriz(int** matriz, int filas) {
    // TU CÓDIGO AQUÍ:
    // 1. Verifica que matriz no sea NULL
    // 2. Libera cada fila (cada puntero en el arreglo de punteros)
    // 3. Libera el arreglo de punteros
    
    
    
    
    
    
    
    
}

// TODO: PARTE 5 - Función para sumar dos matrices
// Crea una nueva matriz que sea la suma de dos matrices existentes
int** sumar_matrices(int** matriz1, int** matriz2, int filas, int columnas) {
    // TU CÓDIGO AQUÍ:
    // 1. Crea una nueva matriz para el resultado
    // 2. Suma elemento por elemento: resultado[i][j] = matriz1[i][j] + matriz2[i][j]
    // 3. Retorna la matriz resultado
    
    
    
    
    
    
    
    
    
    
    return NULL; // Cambia esto por la matriz suma
}

// TODO: PARTE 6 - Función para transponer matriz
// Crea una nueva matriz que sea la transpuesta de la matriz original
int** transponer_matriz(int** matriz, int filas, int columnas) {
    // TU CÓDIGO AQUÍ:
    // 1. Crea una nueva matriz de columnas x filas
    // 2. Copia los elementos: transpuesta[j][i] = matriz[i][j]
    // 3. Retorna la matriz transpuesta
    
    
    
    
    
    
    
    
    
    
    return NULL; // Cambia esto por la matriz transpuesta
}

// TODO: PARTE 7 - Función para encontrar el elemento máximo
int encontrar_maximo(int** matriz, int filas, int columnas, int* fila_max, int* col_max) {
    // TU CÓDIGO AQUÍ:
    // 1. Recorre toda la matriz buscando el elemento máximo
    // 2. Guarda la posición del máximo en fila_max y col_max
    // 3. Retorna el valor máximo encontrado
    
    
    
    
    
    
    
    
    
    
    return 0; // Cambia esto por el valor máximo
}

int main() {
    printf("=== EJERCICIO 1: MATRIZ DINÁMICA ===\n\n");
    
    // Dimensiones de las matrices de prueba
    int filas = 3, columnas = 4;
    
    // TODO: PARTE 8 - Crear primera matriz
    printf("PARTE 1: Creando matriz %dx%d\n", filas, columnas);
    
    // TU CÓDIGO AQUÍ: Crea la primera matriz usando crear_matriz
    
    
    if (matriz1 == NULL) {
        printf("Error: No se pudo crear la matriz1\n");
        return 1;
    }
    
    printf("Matriz1 creada exitosamente\n\n");
    
    // TODO: PARTE 9 - Llenar y mostrar primera matriz
    printf("PARTE 2: Llenando matriz1\n");
    
    // TU CÓDIGO AQUÍ: Llena matriz1 con valores comenzando en 1
    
    
    // TU CÓDIGO AQUÍ: Imprime matriz1
    
    printf("\n");
    
    // TODO: PARTE 10 - Crear segunda matriz para suma
    printf("PARTE 3: Creando segunda matriz para suma\n");
    
    // TU CÓDIGO AQUÍ: Crea matriz2 con las mismas dimensiones
    
    
    if (matriz2 == NULL) {
        printf("Error: No se pudo crear la matriz2\n");
        // TU CÓDIGO AQUÍ: Libera matriz1 antes de salir
        
        return 1;
    }
    
    // TU CÓDIGO AQUÍ: Llena matriz2 con valores comenzando en 100
    
    
    // TU CÓDIGO AQUÍ: Imprime matriz2
    
    printf("\n");
    
    // TODO: PARTE 11 - Sumar matrices
    printf("PARTE 4: Sumando matrices\n");
    
    // TU CÓDIGO AQUÍ: Suma las matrices usando sumar_matrices
    
    
    if (matriz_suma == NULL) {
        printf("Error: No se pudo crear la matriz suma\n");
    } else {
        // TU CÓDIGO AQUÍ: Imprime la matriz suma
        
        printf("\n");
    }
    
    // TODO: PARTE 12 - Transponer matriz
    printf("PARTE 5: Transponiendo matriz1\n");
    
    // TU CÓDIGO AQUÍ: Transpone matriz1 usando transponer_matriz
    
    
    if (matriz_transpuesta == NULL) {
        printf("Error: No se pudo crear la matriz transpuesta\n");
    } else {
        // TU CÓDIGO AQUÍ: Imprime la matriz transpuesta
        
        printf("\n");
    }
    
    // TODO: PARTE 13 - Encontrar máximo
    printf("PARTE 6: Encontrando elemento máximo\n");
    int fila_max, col_max;
    
    // TU CÓDIGO AQUÍ: Encuentra el máximo en matriz_suma
    
    
    printf("Elemento máximo: %d en posición [%d][%d]\n\n", maximo, fila_max, col_max);
    
    // TODO: PARTE 14 - Liberar toda la memoria
    printf("PARTE 7: Liberando memoria\n");
    
    // TU CÓDIGO AQUÍ: Libera todas las matrices creadas
    
    
    
    
    
    
    
    
    
    
    printf("Toda la memoria ha sido liberada correctamente\n");
    
    printf("\n=== FIN DEL EJERCICIO ===\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES SOBRE MATRICES DINÁMICAS:
 * 
 * REPRESENTACIÓN:
 * Una matriz dinámica se representa como un puntero doble:
 * int** matriz; donde matriz[i][j] accede al elemento en fila i, columna j
 * 
 * ESTRUCTURA EN MEMORIA:
 * matriz -> [ptr_fila0] -> [col0][col1][col2]...
 *           [ptr_fila1] -> [col0][col1][col2]...
 *           [ptr_fila2] -> [col0][col1][col2]...
 * 
 * PASOS PARA CREAR:
 * 1. Asignar memoria para arreglo de punteros (filas)
 * 2. Para cada fila, asignar memoria para las columnas
 * 3. Verificar que todas las asignaciones sean exitosas
 * 
 * PASOS PARA LIBERAR:
 * 1. Liberar cada fila (en orden inverso o cualquier orden)
 * 2. Liberar el arreglo de punteros
 * 
 * PISTAS PARA RESOLVER:
 * - Para crear: matriz = malloc(filas * sizeof(int*))
 * - Para cada fila: matriz[i] = malloc(columnas * sizeof(int))
 * - Para acceder: matriz[i][j] o *(*(matriz + i) + j)
 * - Para liberar filas: free(matriz[i])
 * - Para liberar matriz: free(matriz)
 * 
 * ERRORES COMUNES:
 * - No verificar NULL después de malloc
 * - No liberar todas las filas antes de liberar la matriz
 * - Acceder fuera de los límites de la matriz
 * - Liberar memoria ya liberada
 * - Memory leaks por no liberar memoria asignada
 * 
 * VENTAJAS DE MATRICES DINÁMICAS:
 * - Tamaño definido en tiempo de ejecución
 * - Uso eficiente de memoria (solo la necesaria)
 * - Flexibilidad para redimensionar
 * 
 * DESVENTAJAS:
 * - Más complejo de manejar que arreglos estáticos
 * - Requiere manejo manual de memoria
 * - Posibles memory leaks si no se maneja correctamente
 */