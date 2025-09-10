/*
 * EJERCICIO 2: Lista Enlazada Simple
 * 
 * OBJETIVO:
 * Implementar una lista enlazada simple usando punteros y memoria dinámica.
 * Aprender los conceptos fundamentales de estructuras de datos dinámicas.
 * 
 * INSTRUCCIONES:
 * 1. Define la estructura de un nodo de lista
 * 2. Implementa funciones básicas: insertar, eliminar, buscar, imprimir
 * 3. Maneja correctamente la memoria dinámica
 * 4. Implementa funciones adicionales como contar elementos y liberar lista
 * 
 * NIVEL: Medium (Intermedio)
 * TIEMPO ESTIMADO: 50-60 minutos
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>
#include <stdlib.h>

// TODO: PARTE 1 - Definir estructura del nodo
// Define la estructura de un nodo que contenga un entero y un puntero al siguiente nodo
typedef struct nodo {
    // TU CÓDIGO AQUÍ:
    // Define los campos: dato (int) y siguiente (puntero a nodo)
    
    
} Nodo;

// TODO: PARTE 2 - Función para crear un nuevo nodo
Nodo* crear_nodo(int valor) {
    // TU CÓDIGO AQUÍ:
    // 1. Asigna memoria para un nuevo nodo
    // 2. Inicializa el dato con el valor dado
    // 3. Inicializa el puntero siguiente en NULL
    // 4. Retorna el puntero al nuevo nodo
    
    
    
    
    
    
    
    return NULL; // Cambia esto por el nodo creado
}

// TODO: PARTE 3 - Función para insertar al inicio de la lista
void insertar_inicio(Nodo** cabeza, int valor) {
    // TU CÓDIGO AQUÍ:
    // 1. Crea un nuevo nodo con el valor
    // 2. Haz que el nuevo nodo apunte a la cabeza actual
    // 3. Actualiza la cabeza para que apunte al nuevo nodo
    
    
    
    
    
}

// TODO: PARTE 4 - Función para insertar al final de la lista
void insertar_final(Nodo** cabeza, int valor) {
    // TU CÓDIGO AQUÍ:
    // 1. Crea un nuevo nodo
    // 2. Si la lista está vacía, el nuevo nodo es la cabeza
    // 3. Si no, recorre hasta el último nodo y enlaza el nuevo nodo
    
    
    
    
    
    
    
    
    
    
    
}

// TODO: PARTE 5 - Función para imprimir la lista
void imprimir_lista(Nodo* cabeza, const char* titulo) {
    // TU CÓDIGO AQUÍ:
    // Recorre la lista desde la cabeza hasta el final e imprime cada valor
    
    
    
    
    
    
    
    
}

// TODO: PARTE 6 - Función para buscar un elemento
Nodo* buscar_elemento(Nodo* cabeza, int valor) {
    // TU CÓDIGO AQUÍ:
    // Recorre la lista buscando el valor
    // Retorna el nodo si lo encuentra, NULL si no existe
    
    
    
    
    
    
    return NULL;
}

// TODO: PARTE 7 - Función para eliminar un elemento
int eliminar_elemento(Nodo** cabeza, int valor) {
    // TU CÓDIGO AQUÍ:
    // 1. Si la lista está vacía, retorna 0 (no encontrado)
    // 2. Si el elemento a eliminar es la cabeza, actualiza la cabeza
    // 3. Si no, busca el elemento y elimínalo manteniendo los enlaces
    // 4. Libera la memoria del nodo eliminado
    // 5. Retorna 1 si eliminó, 0 si no encontró
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

// TODO: PARTE 8 - Función para contar elementos
int contar_elementos(Nodo* cabeza) {
    // TU CÓDIGO AQUÍ:
    // Recorre la lista contando los nodos
    
    
    
    
    
    
    return 0;
}

// TODO: PARTE 9 - Función para liberar toda la lista
void liberar_lista(Nodo** cabeza) {
    // TU CÓDIGO AQUÍ:
    // Recorre la lista liberando cada nodo
    // Al final, asigna NULL a la cabeza
    
    
    
    
    
    
    
    
}

int main() {
    printf("=== EJERCICIO 2: LISTA ENLAZADA SIMPLE ===\n\n");
    
    // Inicializar lista vacía
    Nodo* mi_lista = NULL;
    
    // TODO: PARTE 10 - Probar inserción al inicio
    printf("PARTE 1: Insertando elementos al inicio\n");
    
    // TU CÓDIGO AQUÍ: Inserta los valores 10, 20, 30 al inicio
    
    
    
    
    // TU CÓDIGO AQUÍ: Imprime la lista
    
    printf("\n");
    
    // TODO: PARTE 11 - Probar inserción al final
    printf("PARTE 2: Insertando elementos al final\n");
    
    // TU CÓDIGO AQUÍ: Inserta los valores 40, 50 al final
    
    
    
    // TU CÓDIGO AQUÍ: Imprime la lista
    
    printf("\n");
    
    // TODO: PARTE 12 - Probar búsqueda
    printf("PARTE 3: Buscando elementos\n");
    int buscar1 = 20, buscar2 = 100;
    
    // TU CÓDIGO AQUÍ: Busca buscar1 y buscar2, informa los resultados
    
    
    
    
    printf("\n");
    
    // TODO: PARTE 13 - Contar elementos
    printf("PARTE 4: Contando elementos\n");
    
    // TU CÓDIGO AQUÍ: Cuenta e imprime el número de elementos
    
    
    printf("\n");
    
    // TODO: PARTE 14 - Eliminar elementos
    printf("PARTE 5: Eliminando elementos\n");
    
    // TU CÓDIGO AQUÍ: Elimina el valor 20 y luego el 10
    
    
    
    
    
    // TU CÓDIGO AQUÍ: Imprime la lista después de eliminar
    
    printf("\n");
    
    // TODO: PARTE 15 - Verificar memoria
    printf("PARTE 6: Estado final\n");
    
    // TU CÓDIGO AQUÍ: Cuenta elementos restantes
    
    
    // TU CÓDIGO AQUÍ: Libera toda la lista
    
    
    printf("Lista liberada correctamente\n");
    
    printf("\n=== FIN DEL EJERCICIO ===\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES SOBRE LISTAS ENLAZADAS:
 * 
 * ESTRUCTURA BÁSICA:
 * [dato|siguiente] -> [dato|siguiente] -> [dato|NULL]
 *         ^                                    ^
 *      cabeza                               último
 * 
 * VENTAJAS:
 * - Tamaño dinámico (crece/decrece según necesidad)
 * - Inserción/eliminación eficiente al inicio
 * - No desperdicia memoria
 * 
 * DESVENTAJAS:
 * - No hay acceso aleatorio (hay que recorrer)
 * - Overhead de memoria por los punteros
 * - Localidad de cache pobre
 * 
 * PISTAS PARA RESOLVER:
 * - Para insertar al inicio: nuevo->siguiente = cabeza; cabeza = nuevo;
 * - Para insertar al final: recorre hasta encontrar nodo->siguiente == NULL
 * - Para eliminar: mantén referencia al nodo anterior
 * - Siempre verifica punteros NULL antes de desreferenciar
 * 
 * ERRORES COMUNES:
 * - No actualizar correctamente los enlaces
 * - Memory leaks por no liberar nodos eliminados
 * - Acceder a punteros NULL
 * - Perder la referencia a la cabeza
 * - No manejar lista vacía correctamente
 * 
 * COMPLEJIDAD TEMPORAL:
 * - Insertar al inicio: O(1)
 * - Insertar al final: O(n)
 * - Buscar: O(n)
 * - Eliminar: O(n) para encontrar + O(1) para eliminar
 */