/*
 * EJEMPLO 1: Punteros Dobles (Punteros a Punteros)
 * 
 * Este ejemplo demuestra:
 * - Qué son los punteros dobles y cómo declararlos
 * - Cómo usar punteros dobles para modificar punteros
 * - Aplicaciones prácticas de punteros dobles
 * - Arreglos de punteros y punteros a arreglos
 * 
 * Autor: Ejercicios C - Punteros
 * Nivel: Medium (Intermedio)
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>
#include <stdlib.h>

// Función que modifica un puntero usando puntero doble
void cambiar_puntero(int **ptr_ptr, int *nuevo_destino) {
    printf("  Dentro de cambiar_puntero():\n");
    printf("    Puntero original apuntaba a: %p\n", (void*)*ptr_ptr);
    
    // Modificamos a dónde apunta el puntero original
    *ptr_ptr = nuevo_destino;
    
    printf("    Ahora el puntero apunta a: %p\n", (void*)*ptr_ptr);
}

// Función que asigna memoria usando puntero doble
void asignar_memoria(int **ptr, int tamaño) {
    // Asignamos memoria y modificamos el puntero original
    *ptr = (int*)malloc(tamaño * sizeof(int));
    
    if (*ptr == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return;
    }
    
    printf("  Memoria asignada en: %p para %d enteros\n", 
           (void*)*ptr, tamaño);
}

int main() {
    printf("=== EJEMPLO DE PUNTEROS DOBLES ===\n\n");
    
    // Variables normales
    int num1 = 100;
    int num2 = 200;
    int num3 = 300;
    
    // Puntero simple
    int *ptr = &num1;
    
    // Puntero doble (puntero a puntero)
    int **ptr_ptr = &ptr;
    
    printf("1. CONCEPTOS BÁSICOS:\n");
    printf("Variables:\n");
    printf("  num1 = %d (dirección: %p)\n", num1, (void*)&num1);
    printf("  num2 = %d (dirección: %p)\n", num2, (void*)&num2);
    printf("  num3 = %d (dirección: %p)\n\n", num3, (void*)&num3);
    
    printf("Puntero simple:\n");
    printf("  ptr apunta a: %p (contiene valor: %d)\n", (void*)ptr, *ptr);
    printf("  dirección de ptr: %p\n\n", (void*)&ptr);
    
    printf("Puntero doble:\n");
    printf("  ptr_ptr apunta a: %p (dirección del puntero)\n", (void*)ptr_ptr);
    printf("  *ptr_ptr = %p (dirección que contiene el puntero)\n", (void*)*ptr_ptr);
    printf("  **ptr_ptr = %d (valor final)\n\n", **ptr_ptr);
    
    // Cambiando a qué apunta el puntero usando puntero doble
    printf("2. MODIFICANDO PUNTEROS CON PUNTEROS DOBLES:\n");
    printf("Antes: ptr apunta a num1 (%d)\n", *ptr);
    
    // Usar puntero doble para cambiar a dónde apunta ptr
    *ptr_ptr = &num2;
    
    printf("Después: ptr apunta a num2 (%d)\n\n", *ptr);
    
    // Usando función que modifica punteros
    printf("3. FUNCIÓN QUE MODIFICA PUNTEROS:\n");
    cambiar_puntero(&ptr, &num3);
    printf("Resultado: ptr ahora apunta a num3 (%d)\n\n", *ptr);
    
    // Arreglo de punteros
    printf("4. ARREGLO DE PUNTEROS:\n");
    int *arreglo_ptrs[3] = {&num1, &num2, &num3};
    
    printf("Arreglo de punteros:\n");
    for (int i = 0; i < 3; i++) {
        printf("  arreglo_ptrs[%d] apunta a: %p (valor: %d)\n", 
               i, (void*)arreglo_ptrs[i], *arreglo_ptrs[i]);
    }
    printf("\n");
    
    // Puntero al arreglo de punteros
    int **ptr_al_arreglo = arreglo_ptrs;
    printf("Accediendo via puntero al arreglo:\n");
    for (int i = 0; i < 3; i++) {
        printf("  *(ptr_al_arreglo + %d) = %d\n", i, **(ptr_al_arreglo + i));
    }
    printf("\n");
    
    // Memoria dinámica con punteros dobles
    printf("5. MEMORIA DINÁMICA CON PUNTEROS DOBLES:\n");
    int *ptr_dinamico = NULL;
    
    printf("Antes de asignar: ptr_dinamico = %p\n", (void*)ptr_dinamico);
    
    // Usamos función que modifica el puntero asignando memoria
    asignar_memoria(&ptr_dinamico, 5);
    
    printf("Después de asignar: ptr_dinamico = %p\n", (void*)ptr_dinamico);
    
    // Llenamos el arreglo dinámico
    if (ptr_dinamico != NULL) {
        for (int i = 0; i < 5; i++) {
            ptr_dinamico[i] = (i + 1) * 10;
        }
        
        printf("Contenido del arreglo dinámico: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", ptr_dinamico[i]);
        }
        printf("\n");
        
        // Liberamos la memoria
        free(ptr_dinamico);
        ptr_dinamico = NULL; // Buena práctica
        printf("Memoria liberada correctamente\n");
    }
    printf("\n");
    
    // Ejemplo avanzado: arreglo dinámico de cadenas
    printf("6. ARREGLO DINÁMICO DE CADENAS:\n");
    char *nombres[] = {
        "Ana", "Carlos", "María", "Pedro"
    };
    int num_nombres = 4;
    
    char **ptr_nombres = nombres; // Puntero a arreglo de cadenas
    
    printf("Nombres usando puntero doble:\n");
    for (int i = 0; i < num_nombres; i++) {
        printf("  Nombre %d: %s (dirección: %p)\n", 
               i + 1, *(ptr_nombres + i), (void*)*(ptr_nombres + i));
    }
    
    printf("\n=== FIN DEL EJEMPLO ===\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES:
 * 
 * DECLARACIÓN DE PUNTEROS DOBLES:
 * - int **ptr_ptr;     // Puntero a puntero a entero
 * - char **ptr_cadenas; // Puntero a puntero a char (común para cadenas)
 * 
 * NIVELES DE INDIRECCIÓN:
 * - ptr_ptr         // Dirección del puntero
 * - *ptr_ptr        // Dirección a la que apunta el puntero
 * - **ptr_ptr       // Valor final almacenado
 * 
 * USOS COMUNES:
 * 1. Modificar punteros dentro de funciones
 * 2. Arreglos de cadenas de caracteres
 * 3. Matrices dinámicas (arreglos de arreglos)
 * 4. Estructuras de datos complejas
 * 
 * ERRORES COMUNES:
 * - Confundir los niveles de indirección (* vs **)
 * - No verificar punteros NULL antes de usarlos
 * - Memory leaks al usar memoria dinámica
 * - Usar memoria después de liberarla
 * 
 * REGLAS DE ORO:
 * 1. Siempre inicializa punteros
 * 2. Verifica NULL antes de desreferenciar
 * 3. Libera toda memoria asignada dinámicamente
 * 4. Asigna NULL después de free()
 */