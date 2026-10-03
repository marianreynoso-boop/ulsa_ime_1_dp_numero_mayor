# Práctica 5: El mayor de tres números

> **En esta práctica todo es tuyo:** el análisis, la receta, el código y las pruebas. Llena cada sección en la fase que se indica.

## 1. Descripción del problema (Fase 1)
<!-- Explica con tus palabras qué hace tu programa y para qué serviría en la vida real. Máximo 4 líneas. -->

Este programa pide tres números y determina cuál es el mayor entre ellos. Sirve para comparar tres mediciones, como la temperatura de tres sensores o la lectura más alta de tres entradas de un sistema.

## 2. Entradas y salidas (Fase 1)
<!-- Define cada entrada y cada salida, con su tipo de dato y su objetivo. -->

**Entradas:**
1. `numero1` de tipo `int`, que representa el primer valor ingresado.
2. `numero2` de tipo `int`, que representa el segundo valor ingresado.
3. `numero3` de tipo `int`, que representa el tercer valor ingresado.

**Salida:**
1. `resultado` de tipo `int`, que muestra el valor mayor de los tres.

**¿Muestro el valor del mayor o cuál de los tres fue (primero, segundo o tercero)? ¿Por qué?**
Muestro el valor del mayor porque el problema pide identificar el número más grande, no la posición. Eso es más útil y directo para comparar resultados.

**¿Qué función de `utilerias.h` uso para leer los números? ¿Por qué esa y no la otra?**
Uso `leerEntero`, porque el problema pide comparar números enteros y la función valida entradas numéricas correctas sin permitir decimales ni texto. `leerDecimal` no sería adecuada porque acepta decimales y no es necesario para este caso.

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):
- Deben leerse exactamente tres números.
- El programa debe mostrar siempre un valor válido como resultado.

**¿Hace falta validar el rango de los números (por ejemplo, rechazar el 0 o los negativos)? ¿Por qué?**
No hace falta rechazar el 0 ni los negativos, porque el problema no dice que sean positivos. Un valor negativo puede ser el mayor en un conjunto de números negativos, así que debe aceptarse.

**¿Qué hace mi programa cuando dos números son iguales y son los mayores? ¿Y cuando los tres son iguales?**
Si dos números son iguales y son el mayor, el programa muestra ese valor porque la comparación usa `>=`. Si los tres son iguales, también muestra ese valor sin error.

**¿Quién detecta cada error?** (¿qué revisa la función de `utilerias.h` y qué reviso yo?)
La función de `utilerias.h` revisa que la entrada sea un entero válido. Yo reviso la lógica de la comparación y la forma en que se toman decisiones con `if` y `else if`.

**Invariante** (justo antes de mostrar el resultado, ¿qué es seguro sobre el valor que voy a mostrar?):
El valor que voy a mostrar es mayor o igual que cada uno de los otros dos números, por lo que cumple con la condición de ser el máximo del conjunto.

## 4. Casos resueltos a mano (Fase 1)

| Caso | Número 1 | Número 2 | Número 3 | Mayor calculado a mano |
|---|---|---|---|---|
| 1 (el mayor en primera posición) | 9 | 4 | 2 | 9 |
| 2 (el mayor en segunda posición) | 4 | 9 | 2 | 9 |
| 3 (el mayor en tercera posición) | 2 | 4 | 9 | 9 |
| 4 (con un empate) | 7 | 7 | 3 | 7 |
| 5 (con negativos) | -4 | -1 | -9 | -1 |

## 5. Receta en pseudocódigo (Fase 2)
<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 5 casos?** Sí
**¿Tuve que corregirla? ¿Qué cambié?** Sí, cambié la comparación para usar `>=` para que también funcione con empates.
**¿Cuántas versiones de mi receta escribí hasta la final?** 2 versiones.
**¿Se me ocurrió otra forma de resolver el problema? ¿Cuál? ¿Por qué elegí la que usé?**
Sí, otra opción era comparar cada número contra los otros dos por separado. Elegí la versión con `if / else if` porque es más clara, más corta y fácil de mantener.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o numero_mayor
./numero_mayor
```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con un caso de empate (por ejemplo 7, 7 y 3). -->

```text
Bienvenido, ingrese 3 numeros
Ingresa el primer numero: 7
Ingresa el segundo numero: 7
Ingresa el tercer numero: 3
El mayor es: 7
```

## 8. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | `std::cout << "Bienvenido, ingrese 3 numeros" << std::endl;` |
| 2. Leer el primer número | `numero1 = leerEntero("Ingresa el primer numero: ");` |
| 3. Leer el segundo número | `numero2 = leerEntero("Ingresa el segundo numero: ");` |
| 4. Leer el tercer número | `numero3 = leerEntero("Ingresa el tercer numero: ");` |
| 5. Comparar y elegir el mayor | `if (numero1 >= numero2 && numero1 >= numero3) { ... } else if ...` |
| 6. Mostrar resultado | `std::cout << "El mayor es: " << resultado << std::endl;` |

**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
Sí, la parte de los empates fue la más delicada, porque hay que decidir si se usa `>` o `>=`. Elegí `>=` para que el valor mayor también funcione cuando dos o tres números coinciden.

## 9. Experimentos (Fase 3)

**Experimento A: ¿qué te dijo el compilador con `if (a > b > c)`? ¿Qué mostró el programa con 3, 2 y 1? ¿Por qué?**
El compilador advierte que la expresión no tiene la lógica correcta, porque `a > b` da un valor booleano (`true` o `false`) y luego ese resultado se compara contra `c`. Con 3, 2 y 1, el programa no compara como en matemáticas y da un resultado incorrecto, porque primero evalúa `3 > 2` y luego compara `true > 1`.

**Experimento B: al cambiar `>=` por `>` (o al revés), ¿qué mostró el programa con 7, 7, 3 y con 5, 5, 5? ¿Por qué?**
Con `>`, los empates desaparecen y el programa no reconoce correctamente el máximo cuando dos o tres números son iguales. Con `>=`, sí reconoce que el valor repetido sigue siendo el mayor. Por eso `>=` es la opción correcta para esta práctica.

**Experimento C (opcional): con `if (a = b)`, ¿qué te dijo el compilador? ¿Qué le pasó al valor de `a`?**
El compilador da una advertencia porque `=` asigna, no compara. Esto hace que `a` tome el valor de `b`, y la condición se evalúa con el valor asignado, no con una comparación real.

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Mayor primero | 9, 4, 2 | 9 | 9 | Sí |
| Mayor en medio | 4, 9, 2 | 9 | 9 | Sí |
| Mayor al final | 2, 4, 9 | 9 | 9 | Sí |
| Empate arriba (1.º y 2.º) | 7, 7, 3 | 7 | 7 | Sí |
| Empate arriba (1.º y 3.º) | 7, 3, 7 | 7 | 7 | Sí |
| Empate abajo | 8, 3, 3 | 8 | 8 | Sí |
| Los tres iguales | 5, 5, 5 | 5 | 5 | Sí |
| Todos negativos | -4, -1, -9 | -1 | -1 | Sí |
| Con cero | -2, 0, -5 | 0 | 0 | Sí |
| Decimales cercanos | 2.5, 2.7, 2.6 | 2.7 | 2.7 | Sí |
| Texto | `abc` (luego 3), 1, 2 | vuelve a pedir el dato; 3 | 3 | Sí |
| Caso propio 1 | 12, 8, 15 | 15 | 15 | Sí |
| Caso propio 2 | -7, -2, -9 | -2 | -2 | Sí |

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | La primera versión usaba nombres de variables inconsistentes y no compilaba. | Reemplacé `valor1`, `valor2`, `valor3` por `numero1`, `numero2`, `numero3` y dejé la lógica consistente. | Sí |
| 2 | Quise asegurar que los empates también fueran válidos. | Cambié las comparaciones a `>=` para considerar igualdad como caso ganador. | Sí |

**Reto elegido (opcional):** Asegurar que el programa maneje bien empates y no solo números distintos.

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| ¿Se puede mostrar también cuál de los tres fue el mayor? | Ya entendí que, para esta práctica, lo importante es el valor máximo, no la posición. |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
Aprendí a plantear la lógica antes de programar, a cuidar los empates y a usar correctamente las comparaciones en C++.

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Escribiría primero la receta y los casos de prueba antes de tocar el código, para evitar errores de lógica y nombres de variables.

**¿Qué fue lo más difícil y cómo lo resolví?**
Lo más difícil fue considerar los empates y la comparación correcta con `>=`. Lo resolví probando varios casos y corrigiendo la condición.

**¿Qué pregunta me quedó sin responder?**
Ninguna por el momento, porque la lógica quedó clara y la práctica quedó resuelta.

**¿Qué fue más fácil para mí: la Práctica 3 (receta propia con un paso de ejemplo), la 4 (receta ajena) o esta (todo desde cero)? ¿Por qué?**
La Práctica 4 fue más fácil porque ya tenía una guía clara. Esta práctica me obligó a pensar más y a diseñar la solución por mi cuenta.

**¿Pensé en los empates antes de programar o los descubrí al probar?**
Los descubrí al probar, pero también los pensé después al revisar la lógica para que quedaran cubiertos.

## 14. Lista de verificación antes de entregar (Fase 5)

- [x] Llené las secciones 1 a 13
- [x] Escribí mi receta completa en `RECETA.md` antes de programar
- [x] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [x] Mi programa compila sin advertencias
- [x] Probé todos los casos de la tabla, incluidos los empates
- [x] Hice los Experimentos A y B y dejé el código correcto al terminar
- [x] No modifiqué `utilerias.h`
- [x] Hice al menos 3 commits con mensajes claros
- [x] Hice `git push` y verifiqué mi fork en GitHub
- [x] Mi fork se llama `ulsa_ime_1_dp_numero_mayor` y el código está en `main.cpp`
- [x] Entregué el enlace de mi fork en Classroom