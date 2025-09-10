/*
 * EJERCICIO 5: Sistema de Callbacks y Eventos
 * 
 * OBJETIVO: Implementar un sistema completo de eventos usando
 * punteros a función para crear un patrón Observer.
 * 
 * NIVEL: Hard (Avanzado)
 * TIEMPO ESTIMADO: 55-65 minutos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de tipos para el sistema de eventos
typedef enum {
    EVENTO_CLICK,
    EVENTO_TECLADO,
    EVENTO_TIMER,
    EVENTO_PERSONALIZADO
} TipoEvento;

typedef struct {
    TipoEvento tipo;
    void* datos;
    char* mensaje;
} Evento;

typedef void (*CallbackEvento)(const Evento* evento, void* contexto);

typedef struct nodo_callback {
    CallbackEvento callback;
    void* contexto;
    struct nodo_callback* siguiente;
} NodoCallback;

typedef struct {
    NodoCallback* callbacks[4]; // Un arreglo por cada tipo de evento
    int activo;
} SistemaEventos;

// TODO: Implementa el sistema de eventos
SistemaEventos* crear_sistema_eventos() {
    // TU CÓDIGO AQUÍ: Inicializar sistema de eventos
    return NULL;
}

void registrar_callback(SistemaEventos* sistema, TipoEvento tipo, 
                       CallbackEvento callback, void* contexto) {
    // TU CÓDIGO AQUÍ: Registrar callback para tipo de evento
}

void desregistrar_callback(SistemaEventos* sistema, TipoEvento tipo, 
                          CallbackEvento callback) {
    // TU CÓDIGO AQUÍ: Remover callback específico
}

void disparar_evento(SistemaEventos* sistema, const Evento* evento) {
    // TU CÓDIGO AQUÍ: Ejecutar todos los callbacks del tipo de evento
}

void limpiar_callbacks(SistemaEventos* sistema, TipoEvento tipo) {
    // TU CÓDIGO AQUÍ: Limpiar todos los callbacks de un tipo
}

void destruir_sistema_eventos(SistemaEventos* sistema) {
    // TU CÓDIGO AQUÍ: Liberar toda la memoria del sistema
}

// Callbacks de ejemplo
void callback_click(const Evento* evento, void* contexto) {
    // TU CÓDIGO AQUÍ: Manejar evento de click
}

void callback_teclado(const Evento* evento, void* contexto) {
    // TU CÓDIGO AQUÍ: Manejar evento de teclado
}

void callback_timer(const Evento* evento, void* contexto) {
    // TU CÓDIGO AQUÍ: Manejar evento de timer
}

void callback_logger(const Evento* evento, void* contexto) {
    // TU CÓDIGO AQUÍ: Logger universal para todos los eventos
}

// Sistema de comandos usando punteros a función
typedef struct {
    char* nombre;
    void (*ejecutar)(const char* argumentos);
    char* descripcion;
} Comando;

// TODO: Implementa sistema de comandos
void cmd_ayuda(const char* args) {
    // TU CÓDIGO AQUÍ: Mostrar ayuda
}

void cmd_eco(const char* args) {
    // TU CÓDIGO AQUÍ: Repetir argumentos
}

void cmd_calc(const char* args) {
    // TU CÓDIGO AQUÍ: Calculadora simple
}

void procesar_comando(const char* linea, Comando* comandos, int num_comandos) {
    // TU CÓDIGO AQUÍ: Parsear y ejecutar comando
}

// Sistema de filtros en cadena
typedef int (*Filtro)(int valor, void* params);

typedef struct nodo_filtro {
    Filtro filtro;
    void* parametros;
    struct nodo_filtro* siguiente;
} NodoFiltro;

// TODO: Implementa cadena de filtros
void agregar_filtro(NodoFiltro** cabeza, Filtro filtro, void* params) {
    // TU CÓDIGO AQUÍ: Agregar filtro a la cadena
}

int aplicar_filtros(NodoFiltro* cabeza, int valor) {
    // TU CÓDIGO AQUÍ: Aplicar todos los filtros en secuencia
    return valor;
}

void liberar_filtros(NodoFiltro* cabeza) {
    // TU CÓDIGO AQUÍ: Liberar cadena de filtros
}

// Filtros de ejemplo
int filtro_par(int valor, void* params) { return valor % 2 == 0; }
int filtro_rango(int valor, void* params) {
    int* rango = (int*)params;
    return valor >= rango[0] && valor <= rango[1];
}

int main() {
    printf("=== EJERCICIO 5: CALLBACKS Y EVENTOS ===\n");
    
    // TODO: Implementa un programa que demuestre:
    // 1. Sistema de eventos completo con múltiples callbacks
    // 2. Registro y desregistro dinámico de callbacks
    // 3. Sistema de comandos usando punteros a función
    // 4. Cadena de filtros configurable
    // 5. Manejo de contexto en callbacks
    // 6. Cleanup completo de memoria
    
    return 0;
}

/*
 * SISTEMA DE EVENTOS:
 * - Patrón Observer: Observadores se registran para eventos
 * - Desacoplamiento: Emisor no conoce a los receptores
 * - Flexibilidad: Agregar/quitar handlers dinámicamente
 * 
 * PUNTEROS A FUNCIÓN:
 * - Polimorfismo en C
 * - Tablas de dispatch
 * - Callbacks asíncronos
 * - Sistemas modulares
 * 
 * APLICACIONES:
 * - GUIs (eventos de usuario)
 * - Sistemas embebidos (interrupciones)
 * - Pipelines de procesamiento
 * - Plugins y extensiones
 */