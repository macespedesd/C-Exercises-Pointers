/*
 * EJEMPLO 2: Estructuras de Datos Complejas
 * 
 * Este ejemplo demuestra:
 * - Implementación de árbol binario de búsqueda
 * - Navegación y operaciones en árboles
 * - Estructuras autoreferenciadas complejas
 * - Algoritmos recursivos con punteros
 * 
 * Autor: Ejercicios C - Punteros
 * Nivel: Hard (Avanzado)
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para nodo de árbol binario
typedef struct nodo_arbol {
    int dato;
    struct nodo_arbol* izquierdo;
    struct nodo_arbol* derecho;
} NodoArbol;

// Función para crear un nuevo nodo
NodoArbol* crear_nodo(int valor) {
    NodoArbol* nuevo = (NodoArbol*)malloc(sizeof(NodoArbol));
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->izquierdo = NULL;
        nuevo->derecho = NULL;
    }
    return nuevo;
}

// Insertar elemento en árbol binario de búsqueda
NodoArbol* insertar(NodoArbol* raiz, int valor) {
    if (raiz == NULL) {
        return crear_nodo(valor);
    }
    
    if (valor < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    // Si el valor es igual, no insertamos (no duplicados)
    
    return raiz;
}

// Buscar elemento en el árbol
NodoArbol* buscar(NodoArbol* raiz, int valor) {
    if (raiz == NULL || raiz->dato == valor) {
        return raiz;
    }
    
    if (valor < raiz->dato) {
        return buscar(raiz->izquierdo, valor);
    } else {
        return buscar(raiz->derecho, valor);
    }
}

// Encontrar el nodo con valor mínimo
NodoArbol* encontrar_minimo(NodoArbol* nodo) {
    while (nodo && nodo->izquierdo != NULL) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

// Eliminar elemento del árbol
NodoArbol* eliminar(NodoArbol* raiz, int valor) {
    if (raiz == NULL) return raiz;
    
    if (valor < raiz->dato) {
        raiz->izquierdo = eliminar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = eliminar(raiz->derecho, valor);
    } else {
        // Nodo encontrado, casos de eliminación:
        
        // Caso 1: Nodo hoja (sin hijos)
        if (raiz->izquierdo == NULL && raiz->derecho == NULL) {
            free(raiz);
            return NULL;
        }
        // Caso 2: Nodo con un hijo
        else if (raiz->izquierdo == NULL) {
            NodoArbol* temp = raiz->derecho;
            free(raiz);
            return temp;
        } else if (raiz->derecho == NULL) {
            NodoArbol* temp = raiz->izquierdo;
            free(raiz);
            return temp;
        }
        // Caso 3: Nodo con dos hijos
        else {
            NodoArbol* temp = encontrar_minimo(raiz->derecho);
            raiz->dato = temp->dato;
            raiz->derecho = eliminar(raiz->derecho, temp->dato);
        }
    }
    return raiz;
}

// Recorridos del árbol
void inorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierdo);
        printf("%d ", raiz->dato);
        inorden(raiz->derecho);
    }
}

void preorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}

void postorden(NodoArbol* raiz) {
    if (raiz != NULL) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        printf("%d ", raiz->dato);
    }
}

// Calcular altura del árbol
int altura(NodoArbol* raiz) {
    if (raiz == NULL) return -1;
    
    int altura_izq = altura(raiz->izquierdo);
    int altura_der = altura(raiz->derecho);
    
    return 1 + (altura_izq > altura_der ? altura_izq : altura_der);
}

// Contar nodos en el árbol
int contar_nodos(NodoArbol* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contar_nodos(raiz->izquierdo) + contar_nodos(raiz->derecho);
}

// Liberar memoria del árbol
void liberar_arbol(NodoArbol* raiz) {
    if (raiz != NULL) {
        liberar_arbol(raiz->izquierdo);
        liberar_arbol(raiz->derecho);
        free(raiz);
    }
}

// Imprimir árbol de forma visual (simplificada)
void imprimir_arbol(NodoArbol* raiz, int espacio) {
    const int ESPACIOS = 4;
    if (raiz == NULL) return;
    
    espacio += ESPACIOS;
    
    imprimir_arbol(raiz->derecho, espacio);
    
    printf("\n");
    for (int i = ESPACIOS; i < espacio; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->dato);
    
    imprimir_arbol(raiz->izquierdo, espacio);
}

// Estructura para lista de adyacencia (grafo simple)
typedef struct nodo_lista {
    int vertice;
    struct nodo_lista* siguiente;
} NodoLista;

typedef struct {
    int num_vertices;
    NodoLista** lista_adj;
} Grafo;

// Crear grafo
Grafo* crear_grafo(int vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    if (grafo == NULL) return NULL;
    
    grafo->num_vertices = vertices;
    grafo->lista_adj = (NodoLista**)calloc(vertices, sizeof(NodoLista*));
    
    return grafo;
}

// Agregar arista al grafo
void agregar_arista(Grafo* grafo, int origen, int destino) {
    if (grafo == NULL || origen >= grafo->num_vertices || destino >= grafo->num_vertices) {
        return;
    }
    
    // Crear nuevo nodo para la lista de adyacencia
    NodoLista* nuevo_nodo = (NodoLista*)malloc(sizeof(NodoLista));
    nuevo_nodo->vertice = destino;
    nuevo_nodo->siguiente = grafo->lista_adj[origen];
    grafo->lista_adj[origen] = nuevo_nodo;
}

// Imprimir grafo
void imprimir_grafo(Grafo* grafo) {
    if (grafo == NULL) return;
    
    for (int i = 0; i < grafo->num_vertices; i++) {
        printf("Vértice %d: ", i);
        NodoLista* actual = grafo->lista_adj[i];
        while (actual != NULL) {
            printf("%d ", actual->vertice);
            actual = actual->siguiente;
        }
        printf("\n");
    }
}

// Liberar grafo
void liberar_grafo(Grafo* grafo) {
    if (grafo == NULL) return;
    
    for (int i = 0; i < grafo->num_vertices; i++) {
        NodoLista* actual = grafo->lista_adj[i];
        while (actual != NULL) {
            NodoLista* temp = actual;
            actual = actual->siguiente;
            free(temp);
        }
    }
    free(grafo->lista_adj);
    free(grafo);
}

int main() {
    printf("=== EJEMPLO DE ESTRUCTURAS COMPLEJAS ===\n\n");
    
    // 1. ÁRBOL BINARIO DE BÚSQUEDA
    printf("1. ÁRBOL BINARIO DE BÚSQUEDA:\n");
    
    NodoArbol* raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n_valores = sizeof(valores) / sizeof(valores[0]);
    
    printf("Insertando valores: ");
    for (int i = 0; i < n_valores; i++) {
        printf("%d ", valores[i]);
        raiz = insertar(raiz, valores[i]);
    }
    printf("\n\n");
    
    // 2. RECORRIDOS DEL ÁRBOL
    printf("2. RECORRIDOS DEL ÁRBOL:\n");
    printf("Inorden (ordenado): ");
    inorden(raiz);
    printf("\n");
    
    printf("Preorden: ");
    preorden(raiz);
    printf("\n");
    
    printf("Postorden: ");
    postorden(raiz);
    printf("\n\n");
    
    // 3. PROPIEDADES DEL ÁRBOL
    printf("3. PROPIEDADES DEL ÁRBOL:\n");
    printf("Altura del árbol: %d\n", altura(raiz));
    printf("Número de nodos: %d\n", contar_nodos(raiz));
    printf("\n");
    
    // 4. REPRESENTACIÓN VISUAL
    printf("4. REPRESENTACIÓN VISUAL:\n");
    printf("Árbol (rotado 90° a la izquierda):\n");
    imprimir_arbol(raiz, 0);
    printf("\n");
    
    // 5. BÚSQUEDAS EN EL ÁRBOL
    printf("5. BÚSQUEDAS:\n");
    int buscar_valores[] = {25, 45, 100};
    int n_busquedas = 3;
    
    for (int i = 0; i < n_busquedas; i++) {
        NodoArbol* encontrado = buscar(raiz, buscar_valores[i]);
        printf("Buscar %d: %s\n", buscar_valores[i], 
               encontrado ? "ENCONTRADO" : "NO ENCONTRADO");
    }
    printf("\n");
    
    // 6. ELIMINACIONES
    printf("6. ELIMINACIONES:\n");
    printf("Eliminando 20 (nodo hoja)...\n");
    raiz = eliminar(raiz, 20);
    printf("Inorden después: ");
    inorden(raiz);
    printf("\n");
    
    printf("Eliminando 30 (nodo con dos hijos)...\n");
    raiz = eliminar(raiz, 30);
    printf("Inorden después: ");
    inorden(raiz);
    printf("\n\n");
    
    // 7. GRAFO CON LISTA DE ADYACENCIA
    printf("7. GRAFO CON LISTA DE ADYACENCIA:\n");
    
    Grafo* mi_grafo = crear_grafo(5);
    if (mi_grafo != NULL) {
        // Agregar aristas para crear un grafo de ejemplo
        agregar_arista(mi_grafo, 0, 1);
        agregar_arista(mi_grafo, 0, 4);
        agregar_arista(mi_grafo, 1, 2);
        agregar_arista(mi_grafo, 1, 3);
        agregar_arista(mi_grafo, 1, 4);
        agregar_arista(mi_grafo, 2, 3);
        agregar_arista(mi_grafo, 3, 4);
        
        printf("Representación del grafo:\n");
        imprimir_grafo(mi_grafo);
        
        liberar_grafo(mi_grafo);
    }
    printf("\n");
    
    // Liberar árbol
    liberar_arbol(raiz);
    
    printf("=== FIN DEL EJEMPLO ===\n");
    printf("Toda la memoria ha sido liberada correctamente.\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES SOBRE ESTRUCTURAS COMPLEJAS:
 * 
 * ÁRBOL BINARIO DE BÚSQUEDA:
 * - Propiedad: Izquierdo < Raíz < Derecho
 * - Búsqueda eficiente: O(log n) en promedio
 * - Recorridos: Inorden, Preorden, Postorden
 * - Operaciones: Insertar, Eliminar, Buscar
 * 
 * RECORRIDOS:
 * - Inorden: Izquierdo → Raíz → Derecho (da orden ascendente en BST)
 * - Preorden: Raíz → Izquierdo → Derecho (útil para copiar árbol)
 * - Postorden: Izquierdo → Derecho → Raíz (útil para liberar memoria)
 * 
 * ELIMINACIÓN EN BST:
 * 1. Nodo hoja: Simplemente eliminar
 * 2. Nodo con un hijo: Reemplazar con el hijo
 * 3. Nodo con dos hijos: Reemplazar con sucesor inorden
 * 
 * GRAFOS:
 * - Representaciones: Matriz de adyacencia, Lista de adyacencia
 * - Lista de adyacencia: Eficiente en espacio para grafos dispersos
 * - Operaciones: Agregar vértice/arista, Eliminar, Recorrer
 * 
 * COMPLEJIDADES:
 * - BST búsqueda: O(log n) promedio, O(n) peor caso
 * - BST inserción: O(log n) promedio, O(n) peor caso
 * - Grafo con lista adj: O(V + E) espacio
 * 
 * APLICACIONES:
 * - BST: Diccionarios, Índices de base de datos
 * - Grafos: Redes sociales, Mapas, Dependencias
 * - Recursión: Fundamental para navegación en estructuras
 */