# Lista Simplemente Enlazada en C

Este proyecto implementa una **lista simplemente enlazada** en C, demostrando operaciones básicas como creación de nodos, recorrido e impresión de la lista.

## Estructura del Proyecto

```
lista_simple/
├── Listas/
│   └── lista.c
├── README.md
```

- `Listas/lista.c`: Código fuente principal con la implementación de la lista.
- `README.md`: Este archivo de documentación.

## Cómo Compilar

Desde la raíz del proyecto, ejecuta:

```sh
gcc Listas/lista.c -o lista_simple
```

## Cómo Ejecutar

Después de compilar, ejecuta:

```sh
./lista_simple
```

## Estructura del Código

- **struct Node**: Define el nodo de la lista.
- **createNode(int data)**: Reserva memoria y crea un nodo.
- **printList(struct Node* head)**: Imprime la lista.
- **main()**: Crea 1000 nodos, imprime la lista y libera la memoria.

## Complejidad Algorítmica

- **Creación de nodos**: O(n), donde n es el número de nodos.
- **Impresión de la lista**: O(n).
- **Liberación de memoria**: O(n).

## Pruebas

Puedes modificar el valor de `n` en el bucle de `main()` para probar con diferentes tamaños de lista.  
Para pruebas automatizadas, se recomienda crear scripts adicionales o integrar un framework de pruebas en C.

---

**Autor:**  
MARTIN CESPEDES
2025