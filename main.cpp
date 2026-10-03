// Práctica 5: El mayor de tres números
// Traduce TU receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque, con la numeración de TU receta.

// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Qué función de utilerias.h vas a usar? ¿Por qué esa y no la otra?
#include "utilerias.h"

int main() {
    int numero1 = 0;
    int numero2 = 0;
    int numero3 = 0;
    int resultado = 0;

    // Paso 1: mensaje de bienvenida
    std::cout << "Bienvenido, ingrese 3 numeros" << std::endl;

    // Paso 2: leer los tres valores
    numero1 = leerEntero("Ingresa el primer numero: ");
    numero2 = leerEntero("Ingresa el segundo numero: ");
    numero3 = leerEntero("Ingresa el tercer numero: ");

    // Paso 3: comparar y decidir cuál es el mayor
    if (numero1 >= numero2 && numero1 >= numero3) {
        resultado = numero1;
    } else if (numero2 >= numero1 && numero2 >= numero3) {
        resultado = numero2;
    } else {
        resultado = numero3;
    }

    // Paso 4: mostrar el resultado
    std::cout << "El mayor es: " << resultado << std::endl;

    return 0;
}