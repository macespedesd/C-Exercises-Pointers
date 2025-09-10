# Nivel Medium - Punteros Intermedios

## 🎯 Objetivos de Aprendizaje

En este nivel aprenderás:
- Punteros dobles (punteros a punteros)
- Asignación dinámica de memoria (malloc, free)
- Estructuras de datos dinámicas básicas
- Punteros a estructuras
- Manejo de memoria y prevención de memory leaks

## 📁 Contenido

### Examples (Ejemplos)
1. **ejemplo1_punteros_dobles.c** - Punteros a punteros y sus aplicaciones
2. **ejemplo2_memoria_dinamica.c** - malloc, realloc, free y manejo de memoria

### Exercises (Ejercicios)
1. **ejercicio1_matriz_dinamica.c** - Crear y manipular matrices dinámicas
2. **ejercicio2_lista_enlazada.c** - Implementar una lista enlazada simple
3. **ejercicio3_pila_dinamica.c** - Implementar una pila usando memoria dinámica
4. **ejercicio4_ordenamiento.c** - Algoritmos de ordenamiento con punteros
5. **ejercicio5_busqueda.c** - Algoritmos de búsqueda y manipulación de datos

## 📚 Conceptos Clave

- **Puntero Doble**: Puntero que apunta a otro puntero (`int **ptr`)
- **malloc()**: Asigna memoria dinámicamente en el heap
- **free()**: Libera memoria previamente asignada
- **realloc()**: Redimensiona un bloque de memoria
- **Memory Leak**: Fuga de memoria por no liberar memoria asignada
- **Segmentation Fault**: Error por acceso a memoria no válida

## 🚨 Reglas Importantes

1. **Siempre libera la memoria**: Por cada `malloc()` debe haber un `free()`
2. **Verifica punteros NULL**: Siempre verifica que `malloc()` no retorne NULL
3. **No uses memoria liberada**: Después de `free()`, no accedas al puntero
4. **Inicializa punteros**: Los punteros no inicializados pueden causar errores

## 🚀 Cómo Empezar

1. Asegúrate de dominar el nivel Easy primero
2. Lee los ejemplos para entender los conceptos nuevos
3. Practica con los ejercicios gradualmente
4. Siempre compila con `-Wall` para detectar warnings
5. Usa herramientas como `valgrind` para detectar memory leaks

¡La memoria dinámica es poderosa pero requiere responsabilidad!