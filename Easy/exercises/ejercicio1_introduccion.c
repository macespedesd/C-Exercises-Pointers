/*
 * EJERCICIO 1: Introducción a Punteros
 * 
 * OBJETIVO:
 * Familiarizarse con la declaración, inicialización y uso básico de punteros.
 * Este es tu primer contacto práctico con punteros.
 * 
 * INSTRUCCIONES:
 * 1. Declara variables de diferentes tipos (int, float, char)
 * 2. Declara punteros para cada tipo
 * 3. Asigna las direcciones de las variables a los punteros
 * 4. Imprime los valores usando tanto las variables como los punteros
 * 5. Modifica los valores usando los punteros
 * 
 * NIVEL: Easy (Básico)
 * TIEMPO ESTIMADO: 15-20 minutos
 * Para: Estudiantes de 3er semestre
 */

#include <stdio.h>

int main() {
    printf("=== EJERCICIO 1: INTRODUCCIÓN A PUNTEROS ===\n\n");
    
    // TODO: PARTE 1 - Declarar variables de diferentes tipos
    // Declara las siguientes variables:
    // - Un entero llamado 'edad' con valor 20
    // - Un flotante llamado 'altura' con valor 1.75
    // - Un caracter llamado 'inicial' con valor 'J'
    
    // TU CÓDIGO AQUÍ:
    
    
    
    
    // TODO: PARTE 2 - Declarar punteros
    // Declara punteros para cada una de las variables anteriores:
    // - Un puntero a entero llamado 'ptr_edad'
    // - Un puntero a flotante llamado 'ptr_altura'  
    // - Un puntero a caracter llamado 'ptr_inicial'
    
    // TU CÓDIGO AQUÍ:
    
    
    
    
    // TODO: PARTE 3 - Asignar direcciones a los punteros
    // Asigna la dirección de cada variable a su puntero correspondiente
    // Usa el operador & para obtener la dirección
    
    // TU CÓDIGO AQUÍ:
    
    
    
    
    // TODO: PARTE 4 - Imprimir valores originales
    // Imprime los valores de las variables originales y sus direcciones
    printf("VALORES ORIGINALES:\n");
    
    // TU CÓDIGO AQUÍ - Ejemplo:
    // printf("edad = %d, dirección: %p\n", edad, (void*)&edad);
    
    
    
    
    printf("\n");
    
    // TODO: PARTE 5 - Imprimir usando punteros
    // Imprime los mismos valores pero usando los punteros
    printf("VALORES USANDO PUNTEROS:\n");
    
    // TU CÓDIGO AQUÍ - Ejemplo:
    // printf("*ptr_edad = %d, dirección del puntero: %p\n", *ptr_edad, (void*)ptr_edad);
    
    
    
    
    printf("\n");
    
    // TODO: PARTE 6 - Modificar valores usando punteros
    // Cambia los valores de las variables usando únicamente los punteros:
    // - edad a 25
    // - altura a 1.80
    // - inicial a 'M'
    printf("MODIFICANDO VALORES CON PUNTEROS...\n");
    
    // TU CÓDIGO AQUÍ:
    
    
    
    
    // TODO: PARTE 7 - Verificar cambios
    // Imprime los nuevos valores usando las variables originales
    // para comprobar que los cambios se efectuaron
    printf("\nVALORES DESPUÉS DE MODIFICAR:\n");
    
    // TU CÓDIGO AQUÍ:
    
    
    
    
    // TODO: PARTE 8 - Experimentar con punteros nulos
    // Declara un puntero nulo y muestra su valor
    printf("\nEXPERIMENTANDO CON PUNTEROS NULOS:\n");
    
    // TU CÓDIGO AQUÍ:
    
    
    
    printf("\n=== FIN DEL EJERCICIO ===\n");
    
    return 0;
}

/*
 * PISTAS PARA RESOLVER EL EJERCICIO:
 * 
 * 1. Para declarar un puntero: tipo *nombre_puntero;
 * 2. Para asignar dirección: puntero = &variable;
 * 3. Para acceder al valor: *puntero
 * 4. Para imprimir direcciones usa %p y convierte a (void*)
 * 5. NULL es el valor para punteros que no apuntan a nada
 * 
 * RESULTADO ESPERADO:
 * Deberías ver que:
 * - Los punteros contienen las mismas direcciones que las variables
 * - Los valores accedidos por punteros son idénticos a los originales
 * - Modificar con punteros cambia las variables originales
 * - Un puntero NULL muestra 0x0 o (nil)
 * 
 * PREGUNTAS PARA REFLEXIONAR:
 * 1. ¿Por qué cambiar *ptr_edad también cambia el valor de edad?
 * 2. ¿Qué pasa si intentas usar un puntero sin inicializar?
 * 3. ¿Por qué necesitamos convertir a (void*) para imprimir direcciones?
 */