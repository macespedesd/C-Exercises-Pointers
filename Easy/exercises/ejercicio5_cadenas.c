/*
 * EJERCICIO 5: Manipulación Básica de Cadenas
 * 
 * OBJETIVO:
 * Aprender a trabajar con cadenas de caracteres usando punteros.
 * Las cadenas en C son arreglos de caracteres terminados en '\0'.
 * 
 * INSTRUCCIONES:
 * 1. Implementa funciones básicas de cadenas usando punteros
 * 2. Practica el recorrido de cadenas hasta encontrar '\0'
 * 3. Implementa operaciones como longitud, copia, comparación
 * 4. Aprende la diferencia entre cadenas literales y arreglos de caracteres
 * 
 * NIVEL: Easy (Básico)
 * TIEMPO ESTIMADO: 40-45 minutos
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>

// TODO: PARTE 1 - Función para calcular longitud de cadena
// Calcula la longitud de una cadena SIN usar strlen()
int mi_strlen(char *cadena) {
    // TU CÓDIGO AQUÍ:
    // Recorre la cadena con un puntero hasta encontrar '\0'
    // Cuenta cuántos caracteres hay antes del '\0'
    
    int longitud = 0;
    
    
    
    
    return longitud;
}

// TODO: PARTE 2 - Función para copiar cadena
// Copia una cadena a otra SIN usar strcpy()
void mi_strcpy(char *destino, char *origen) {
    // TU CÓDIGO AQUÍ:
    // Copia caracter por caracter desde origen hasta destino
    // No olvides copiar también el '\0' al final
    
    
    
    
}

// TODO: PARTE 3 - Función para comparar cadenas
// Compara dos cadenas SIN usar strcmp()
// Retorna: 0 si son iguales, >0 si cadena1 > cadena2, <0 si cadena1 < cadena2
int mi_strcmp(char *cadena1, char *cadena2) {
    // TU CÓDIGO AQUÍ:
    // Compara caracter por caracter
    // Si encuentras diferencia, retorna la diferencia
    // Si son iguales hasta el final, retorna 0
    
    
    
    
    
    
    return 0;
}

// TODO: PARTE 4 - Función para contar vocales
// Cuenta cuántas vocales (a, e, i, o, u) hay en la cadena
int contar_vocales(char *cadena) {
    // TU CÓDIGO AQUÍ:
    // Recorre la cadena y cuenta vocales (mayúsculas y minúsculas)
    
    int contador = 0;
    
    
    
    
    
    
    return contador;
}

// TODO: PARTE 5 - Función para convertir a mayúsculas
// Convierte todos los caracteres de la cadena a mayúsculas
void a_mayusculas(char *cadena) {
    // TU CÓDIGO AQUÍ:
    // Recorre la cadena y convierte minúsculas a mayúsculas
    // Usa la diferencia ASCII: 'a' - 'A' = 32
    
    
    
    
    
    
}

// TODO: PARTE 6 - Función para invertir cadena
// Invierte el orden de los caracteres en la cadena
void invertir_cadena(char *cadena) {
    // TU CÓDIGO AQUÍ:
    // Usa dos punteros: uno al inicio, otro al final
    // Intercambia caracteres y mueve punteros hacia el centro
    
    
    
    
    
    
    
    
    
}

// TODO: PARTE 7 - Función para buscar caracter
// Busca un caracter en la cadena y retorna su posición (o -1 si no existe)
int buscar_caracter(char *cadena, char caracter) {
    // TU CÓDIGO AQUÍ:
    // Recorre la cadena buscando el caracter
    // Retorna la posición si lo encuentra, -1 si no
    
    
    
    
    
    
    return -1; // No encontrado
}

// TODO: PARTE 8 - Función para concatenar cadenas
// Añade la cadena2 al final de cadena1
void mi_strcat(char *cadena1, char *cadena2) {
    // TU CÓDIGO AQUÍ:
    // 1. Encuentra el final de cadena1 (el '\0')
    // 2. Copia cadena2 a partir de esa posición
    // 3. Asegúrate de que quede bien terminada con '\0'
    
    
    
    
    
    
}

int main() {
    printf("=== EJERCICIO 5: MANIPULACIÓN BÁSICA DE CADENAS ===\n\n");
    
    // Declaración de cadenas para las pruebas
    char texto1[100] = "Hola Mundo";
    char texto2[100] = "Universidad";
    char texto3[100]; // Para copias
    char texto4[200] = "Programacion "; // Para concatenación
    
    // TODO: PARTE 9 - Probar cálculo de longitud
    printf("PRUEBA 1: Calcular Longitud\n");
    printf("Cadena: \"%s\"\n", texto1);
    // TU CÓDIGO AQUÍ: Usa mi_strlen para calcular la longitud
    
    
    printf("\n");
    
    // TODO: PARTE 10 - Probar copia de cadena
    printf("PRUEBA 2: Copiar Cadena\n");
    printf("Original: \"%s\"\n", texto2);
    
    // TU CÓDIGO AQUÍ: Usa mi_strcpy para copiar texto2 a texto3
    
    
    printf("Copia: \"%s\"\n\n", texto3);
    
    // TODO: PARTE 11 - Probar comparación de cadenas
    printf("PRUEBA 3: Comparar Cadenas\n");
    char cadena_a[] = "ABC";
    char cadena_b[] = "ABC";
    char cadena_c[] = "XYZ";
    
    // TU CÓDIGO AQUÍ: Compara las cadenas usando mi_strcmp
    
    
    
    
    printf("\n");
    
    // TODO: PARTE 12 - Probar conteo de vocales
    printf("PRUEBA 4: Contar Vocales\n");
    char frase[] = "La programacion es divertida";
    printf("Frase: \"%s\"\n", frase);
    
    // TU CÓDIGO AQUÍ: Cuenta las vocales usando contar_vocales
    
    
    printf("\n");
    
    // TODO: PARTE 13 - Probar conversión a mayúsculas
    printf("PRUEBA 5: Convertir a Mayúsculas\n");
    char minusculas[] = "texto en minusculas";
    printf("Antes: \"%s\"\n", minusculas);
    
    // TU CÓDIGO AQUÍ: Convierte a mayúsculas usando a_mayusculas
    
    
    printf("Después: \"%s\"\n\n", minusculas);
    
    // TODO: PARTE 14 - Probar inversión de cadena
    printf("PRUEBA 6: Invertir Cadena\n");
    char palabra[] = "PUNTEROS";
    printf("Antes: \"%s\"\n", palabra);
    
    // TU CÓDIGO AQUÍ: Invierte la cadena usando invertir_cadena
    
    
    printf("Después: \"%s\"\n\n", palabra);
    
    // TODO: PARTE 15 - Probar búsqueda de caracter
    printf("PRUEBA 7: Buscar Caracter\n");
    char busqueda[] = "Estructura de Datos";
    char buscar1 = 'E', buscar2 = 'z';
    
    // TU CÓDIGO AQUÍ: Busca los caracteres usando buscar_caracter
    
    
    
    printf("\n");
    
    // TODO: PARTE 16 - Probar concatenación
    printf("PRUEBA 8: Concatenar Cadenas\n");
    printf("Cadena base: \"%s\"\n", texto4);
    char agregar[] = "en C";
    
    // TU CÓDIGO AQUÍ: Concatena usando mi_strcat
    
    
    printf("Después de concatenar: \"%s\"\n\n", texto4);
    
    // TODO: PARTE 17 - Experimento con punteros a cadenas literales
    printf("EXPERIMENTO: Punteros a Cadenas Literales\n");
    char *ptr_literal = "Cadena Literal";
    char arreglo_chars[] = "Arreglo de Chars";
    
    printf("Cadena literal: %s (dirección: %p)\n", ptr_literal, (void*)ptr_literal);
    printf("Arreglo de chars: %s (dirección: %p)\n", arreglo_chars, (void*)arreglo_chars);
    
    // TU CÓDIGO AQUÍ: Imprime caracter por caracter usando punteros
    printf("Caracter por caracter de la literal: ");
    
    
    
    printf("\n");
    
    printf("\n=== FIN DEL EJERCICIO ===\n");
    
    return 0;
}

/*
 * CONCEPTOS IMPORTANTES SOBRE CADENAS EN C:
 * 
 * REPRESENTACIÓN:
 * - Las cadenas son arreglos de caracteres terminados en '\0'
 * - "Hola" se almacena como: {'H', 'o', 'l', 'a', '\0'}
 * - El '\0' marca el final de la cadena
 * 
 * DECLARACIÓN:
 * - char cadena[] = "texto";        // Arreglo modificable
 * - char *ptr = "texto";            // Puntero a literal (solo lectura)
 * - char cadena[50] = "texto";      // Arreglo con tamaño fijo
 * 
 * PISTAS PARA RESOLVER:
 * 1. Para recorrer hasta '\0': while(*ptr != '\0') { ... ptr++; }
 * 2. Para mayúsculas: if(c >= 'a' && c <= 'z') c = c - 'a' + 'A';
 * 3. Para vocales: if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') contador++;
 * 4. Para invertir: usa dos punteros y intercambia caracteres
 * 
 * ERRORES COMUNES:
 * - Olvidar el '\0' al final de la cadena
 * - Modificar cadenas literales (comportamiento indefinido)
 * - No verificar límites de arreglos
 * - Confundir punteros a char con arreglos de char
 * 
 * DIFERENCIAS IMPORTANTES:
 * - char arr[] = "hola";   // Copia la cadena al arreglo (modificable)
 * - char *ptr = "hola";    // Apunta a cadena literal (no modificable)
 * 
 * FUNCIONES ESTÁNDAR EQUIVALENTES:
 * - mi_strlen() ≡ strlen()
 * - mi_strcpy() ≡ strcpy()
 * - mi_strcmp() ≡ strcmp()
 * - mi_strcat() ≡ strcat()
 */