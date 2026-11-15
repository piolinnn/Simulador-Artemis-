# Trabajo Final de C

## 1. Integrantes 
(Grupo: "Punto y Coma")

- Caceres Efrain - 31435
- Amarilla Leonardo - 31296
- Carina Beatriz Burger - 26664
- Carlos Nicolás Augusto Richter - 26785
- Lautaro de Jesús González - 28829

## 2. Comisión y repositorio

- **Comisión: D (k1.4)** 
- **Repositorio GitHub/GitLab: https://github.com/piolinnn/Simulador-Artemis-.git** 

## 3. Descripción del juego

### Escenario Artemis asignado
**Problema 3: Inyección Translunar — TLI e Inercia en Trayectoria Libre**
El sistema simula la misión de la nave Orion durante la maniobra de Inyección Translunar (TLI), realizada desde una órbita baja terrestre (LEO).
En esta etapa, la etapa superior ICPS impulsa a la nave Orion hasta una velocidad de inyección de:

* Velocidad inicial: 10.900,0 m/s
* Masa de Orion: 26.000,0 kg
* Distancia media Tierra-Luna: 384.000.000,0 m
* Altitud de la órbita baja: 192.000,0 m

Luego de la maniobra TLI, la etapa ICPS se desacopla y los motores principales de Orion se apagan. La nave continúa su trayectoria hacia la Luna bajo la acción de las fuerzas gravitatorias.

### Reglas del juego
Una vez finalizado el impulso de la etapa ICPS:
1. La nave Orion continúa su movimiento debido a su estado de movimiento inicial.
2. Los motores principales permanecen apagados.
3. La nave se encuentra en una trayectoria de retorno libre (Free Return Trajectory) hacia la Luna.
4. El programa debe utilizar los datos físicos proporcionados para realizar los cálculos correspondientes.
5. Los valores ingresados por el usuario deben ser validados para evitar datos incorrectos o comportamientos inesperados.
5. El sistema debe mostrar al usuario los resultados de los cálculos de manera clara.

### Objetivo
El objetivo del programa es simular y analizar la situación física correspondiente a la Inyección Translunar de la nave Orion, aplicando conceptos de:
* Primera Ley de Newton o Ley de Inercia.
* Movimiento de la nave luego del apagado de los motores.
* Energía cinética.
* Conservación de la energía mecánica.
* Energía potencial gravitatoria.
* Trabajo y energía.

## 4. Funcionamiento
El programa es un simulador por consola. Al iniciar, crea la nave Orion (una variable de tipo `struct NaveOrion`) con los datos por defecto del problema (masa de 26.000 kg y velocidad de 10.900 m/s) y muestra un menú que se repite hasta que el usuario decide salir. Los cálculos se hacen sobre el estado actual de la nave, que se pasa por puntero a las funciones de cálculo.
Todos los datos se leen con `fgets` + `sscanf` desde el módulo de validaciones, por lo que si el usuario escribe letras, deja el dato vacío o ingresa un valor fuera de rango, el programa muestra un mensaje de error y vuelve a pedir el dato, sin cerrarse.

**Estructura del proyecto:**
| Archivo | Responsabilidad |
|---------|-----------------|
| `main.c` | Punto de entrada: llama a `iniciar_simulacion()`. |
| `artemis.h` | Constantes (`#define`), `struct NaveOrion` y prototipos. |
| `artemis.c` | Menú, ciclo de simulación y cálculos físicos. |
| `validaciones.h` / `validaciones.c` | Lectura segura de enteros y reales. |
| `Makefile` | Compilación del proyecto. |

### Menú principal
El menú muestra el estado actual de la nave (masa y velocidad) y ofrece estas opciones:

1. **Calcular Energía Cinética Inicial (Inciso b):** calcula y muestra `K_i = 1/2 · m · v²` con la masa y velocidad actuales, en Joules y notación científica.
2. **Modificar parámetros de la nave:** permite ingresar una nueva masa (debe ser `> 0`) y una nueva velocidad (debe ser `>= 0`).
3. **Salir:** finaliza el programa.

La opción del menú debe ser un entero entre 1 y 3.

### Mecánica del juego
1. El usuario inicia el programa y ve el menú con los datos por defecto de Orion.
2. Puede calcular la energía cinética con esos datos. Con `m = 26.000 kg` y `v = 10.900 m/s` el resultado es `K_i ≈ 1,54453 × 10¹² J`.
3. Si quiere analizar otros casos, elige la opción 2 y modifica masa y velocidad. Los valores se validan antes de aceptarse.
4. Vuelve a calcular con los nuevos valores y compara los resultados.
5. Repite el ciclo las veces que quiera y sale con la opción 3.

### Condiciones de victoria / derrota
Al ser un simulador de cálculo físico y no un juego competitivo, no hay victoria ni derrota ni puntaje.
El programa se considera exitoso cuando el usuario ingresa datos válidos y obtiene los resultados correctos del escenario.
Termina únicamente cuando el usuario elige "Salir" o cuando se detecta el fin de la entrada (EOF), en cuyo caso se cierra de forma ordenada.

## 5. Compilación y ejecución

### Requisitos
* Compilador de C compatible con el estándar C11 (`clang` o `gcc`).
* `make` (opcional, se puede compilar a mano).
* Una terminal o consola de comandos.

### Compilación
Con Makefile (usa `clang` por defecto):

```bash
make
```

Si solo tenés `gcc` instalado:

```bash
make CC=gcc
```

Sin Makefile:

```bash
gcc -Wall -Wextra -std=c11 -o simulador main.c artemis.c validaciones.c
```

### Ejecución

```bash
./simulador
```

En Windows:

```bash
simulador.exe
```

Para borrar el ejecutable generado:

```bash
make clean
```
