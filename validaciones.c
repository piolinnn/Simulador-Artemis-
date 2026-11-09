#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

double leer_doble_seguro(const char *mensaje) {
    char buffer[100];
    double valor;
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%lf", &valor) == 1) {
                return valor;
            }
        }
        printf("Error: Ingrese un valor numerico valido.\n");
    }
}

int leer_entero_seguro(const char *mensaje, int min, int max) {
    char buffer[100];
    int valor;
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &valor) == 1 && valor >= min && valor <= max) {
                return valor;
            }
        }
        printf("Error: Ingrese un numero entre %d y %d.\n", min, max);
    }
}

