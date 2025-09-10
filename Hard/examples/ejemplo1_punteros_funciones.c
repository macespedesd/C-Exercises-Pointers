/*
 * EJEMPLO 1: Punteros a Funciones y Callbacks
 * 
 * Este ejemplo demuestra:
 * - Declaración y uso de punteros a funciones
 * - Paso de funciones como parámetros (callbacks)
 * - Arreglos de punteros a funciones
 * - Aplicaciones prácticas de callbacks
 * 
 * Autor: Ejercicios C - Punteros
 * Nivel: Hard (Avanzado)
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funciones matemáticas básicas que usaremos como callbacks
double sumar(double a, double b) { return a + b; }
double restar(double a, double b) { return a - b; }
double multiplicar(double a, double b) { return a * b; }
double dividir(double a, double b) { return b != 0 ? a / b : 0; }

// Función que usa callback para procesar arreglo
void procesar_arreglo(double* arr, int n, double (*operacion)(double), const char* nombre_op) {
    printf("Aplicando %s al arreglo:\n", nombre_op);
    printf("Original: ");
    for (int i = 0; i < n; i++) printf("%.1f ", arr[i]);
    printf("\n");
    
    printf("Resultado: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", operacion(arr[i]));
    }
    printf("\n\n");
}

// Función que aplica operación binaria a dos arreglos
void operacion_arreglos(double* arr1, double* arr2, double* resultado, int n,
                       double (*operacion)(double, double), const char* simbolo) {
    printf("Operación %s entre arreglos:\n", simbolo);
    for (int i = 0; i < n; i++) {
        resultado[i] = operacion(arr1[i], arr2[i]);
        printf("%.1f %s %.1f = %.2f\n", arr1[i], simbolo, arr2[i], resultado[i]);
    }
    printf("\n");
}

// Simulador de calculadora con punteros a función
typedef struct {
    char simbolo;
    char nombre[20];
    double (*funcion)(double, double);
} Operacion;

void ejecutar_calculadora(Operacion* ops, int num_ops) {
    printf("=== CALCULADORA CON PUNTEROS A FUNCIÓN ===\n");
    
    for (int i = 0; i < num_ops; i++) {
        double a = 10.0, b = 3.0;
        double resultado = ops[i].funcion(a, b);
        printf("%s: %.1f %c %.1f = %.2f\n", 
               ops[i].nombre, a, ops[i].simbolo, b, resultado);
    }
    printf("\n");
}

// Sistema de eventos con callbacks
typedef void (*EventCallback)(const char* evento, void* datos);

void procesar_evento(const char* evento, void* datos, EventCallback callback) {
    printf("Procesando evento: %s\n", evento);
    if (callback != NULL) {
        callback(evento, datos);
    }
}

// Callbacks específicos para eventos
void callback_click(const char* evento, void* datos) {
    int* posicion = (int*)datos;
    printf("  -> Click detectado en posición (%d, %d)\n", posicion[0], posicion[1]);
}

void callback_teclado(const char* evento, void* datos) {
    char* tecla = (char*)datos;
    printf("  -> Tecla presionada: '%c'\n", *tecla);
}

void callback_timer(const char* evento, void* datos) {
    int* tiempo = (int*)datos;
    printf("  -> Timer activado después de %d ms\n", *tiempo);
}

int main() {
    printf("=== EJEMPLO DE PUNTEROS A FUNCIONES ===\n\n");
    
    // 1. DECLARACIÓN BÁSICA DE PUNTEROS A FUNCIÓN
    printf("1. PUNTEROS A FUNCIÓN BÁSICOS:\n");
    
    // Declarar puntero a función que toma dos doubles y retorna double
    double (*ptr_operacion)(double, double);
    
    // Asignar diferentes funciones al puntero
    ptr_operacion = sumar;
    printf("Suma: %.1f + %.1f = %.2f\n", 5.0, 3.0, ptr_operacion(5.0, 3.0));
    
    ptr_operacion = multiplicar;
    printf("Multiplicación: %.1f * %.1f = %.2f\n", 5.0, 3.0, ptr_operacion(5.0, 3.0));
    printf("\n");
    
    // 2. ARREGLO DE PUNTEROS A FUNCIÓN
    printf("2. ARREGLO DE PUNTEROS A FUNCIÓN:\n");
    
    double (*operaciones[])(double, double) = {sumar, restar, multiplicar, dividir};
    char* nombres[] = {"Suma", "Resta", "Multiplicación", "División"};
    char simbolos[] = {'+', '-', '*', '/'};
    
    double x = 12.0, y = 4.0;
    for (int i = 0; i < 4; i++) {
        double resultado = operaciones[i](x, y);
        printf("%s: %.1f %c %.1f = %.2f\n", nombres[i], x, simbolos[i], y, resultado);
    }
    printf("\n");
    
    // 3. CALLBACKS PARA PROCESAMIENTO DE ARREGLOS
    printf("3. CALLBACKS PARA PROCESAMIENTO:\n");
    
    double numeros[] = {1.0, 4.0, 9.0, 16.0, 25.0};
    int n = 5;
    
    // Aplicar diferentes funciones al arreglo
    procesar_arreglo(numeros, n, sqrt, "raíz cuadrada");
    procesar_arreglo(numeros, n, log, "logaritmo natural");
    
    // 4. OPERACIONES ENTRE ARREGLOS
    printf("4. OPERACIONES ENTRE ARREGLOS:\n");
    
    double arr1[] = {10.0, 20.0, 30.0};
    double arr2[] = {2.0, 4.0, 5.0};
    double resultado[3];
    
    operacion_arreglos(arr1, arr2, resultado, 3, sumar, "+");
    operacion_arreglos(arr1, arr2, resultado, 3, dividir, "/");
    
    // 5. CALCULADORA CON ESTRUCTURA
    printf("5. CALCULADORA AVANZADA:\n");
    
    Operacion calculadora[] = {
        {'+', "Suma", sumar},
        {'-', "Resta", restar},
        {'*', "Multiplicación", multiplicar},
        {'/', "División", dividir}
    };
    
    ejecutar_calculadora(calculadora, 4);
    
    // 6. SISTEMA DE EVENTOS CON CALLBACKS
    printf("6. SISTEMA DE EVENTOS:\n");
    
    // Simular diferentes eventos
    int posicion_click[] = {150, 200};
    char tecla_presionada = 'A';
    int tiempo_timer = 1000;
    
    procesar_evento("mouse_click", posicion_click, callback_click);
    procesar_evento("key_press", &tecla_presionada, callback_teclado);
    procesar_evento("timer_expired", &tiempo_timer, callback_timer);
    printf("\n");
    
    // 7. TABLA DE DISPATCH (AVANZADO)
    printf("7. TABLA DE DISPATCH:\n");
    
    typedef struct {
        int codigo;
        const char* nombre;
        void (*handler)(void);
    } ComandoDispatch;
    
    // Funciones para comandos
    void cmd_ayuda(void) { printf("  Mostrando ayuda del sistema\n"); }
    void cmd_salir(void) { printf("  Preparando salida del programa\n"); }
    void cmd_info(void) { printf("  Información del sistema v1.0\n"); }
    
    ComandoDispatch tabla_comandos[] = {
        {1, "help", cmd_ayuda},
        {2, "exit", cmd_salir},
        {3, "info", cmd_info}
    };
    
    printf("Ejecutando comandos:\n");
    for (int i = 0; i < 3; i++) {
        printf("Comando %d (%s):\n", tabla_comandos[i].codigo, tabla_comandos[i].nombre);
        tabla_comandos[i].handler();
    }
    
    printf("\n=== FIN DEL EJEMPLO ===\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES SOBRE PUNTEROS A FUNCIÓN:
 * 
 * DECLARACIÓN:
 * tipo_retorno (*nombre_puntero)(parámetros);
 * Ejemplo: int (*ptr_func)(int, char*);
 * 
 * ASIGNACIÓN:
 * ptr_func = nombre_funcion;  // Sin paréntesis
 * ptr_func = &nombre_funcion; // Equivalente con &
 * 
 * LLAMADA:
 * resultado = ptr_func(argumentos);
 * resultado = (*ptr_func)(argumentos); // Equivalente explícito
 * 
 * APLICACIONES PRINCIPALES:
 * 1. Callbacks para procesamiento personalizable
 * 2. Polimorfismo en C (similar a interfaces)
 * 3. Tablas de dispatch para comandos
 * 4. Sistemas de eventos
 * 5. Algoritmos genéricos (como qsort)
 * 
 * VENTAJAS:
 * - Código más flexible y reutilizable
 * - Separación de algoritmo y operación específica
 * - Implementación de patrones como Strategy
 * - Sistemas modulares y extensibles
 * 
 * ERRORES COMUNES:
 * - Llamar función con paréntesis al asignar: ptr = func() ❌
 * - No verificar NULL antes de llamar callback
 * - Confundir declaración con llamada
 * - Problemas de tipos en parámetros
 * 
 * MEJORES PRÁCTICAS:
 * - Siempre verificar NULL antes de llamar callback
 * - Usar typedef para simplificar declaraciones complejas
 * - Documentar claramente el comportamiento esperado
 * - Considerar usar void* para datos genéricos en callbacks
 */