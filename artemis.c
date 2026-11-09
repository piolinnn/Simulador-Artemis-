#include <stdio.h>
#include "artemis.h"
#include "validaciones.h"

void calcular_energia_cinetica(NaveOrion *nave) {
    nave->energia_cinetica = 0.5 * nave->masa * (nave->velocidad * nave->velocidad);

    printf("\n-----------------------------------------\n");
    printf(" INCISO B: ENERGIA CINETICA INICIAL\n");
    printf("-----------------------------------------\n");
    printf(" Formula : K_i = 1/2 m v^2\n");
    printf(" m       = %.1f [kg]\n", nave->masa);
    printf(" v       = %.1f [m/s]\n", nave->velocidad);
    printf(" K_i     = %.5e [J]\n", nave->energia_cinetica);
    printf("-----------------------------------------\n");
}

void iniciar_simulacion(void) {
    NaveOrion orion = {MASA_ORION, VELOCIDAD_TLI, ALTITUD_LEO, 0.0};
    int opcion;

    do {
        printf("\n=========================================\n");
        printf(" SIMULADOR ARTEMIS - INYECCION TRANSLUNAR\n");
        printf("=========================================\n");
        printf(" Estado Actual de la Nave Orion:\n");
        printf(" m = %.1f [kg] | v = %.1f [m/s]\n", orion.masa, orion.velocidad);
        printf("=========================================\n");
        printf(" 1. Calcular Energia Cinetica Inicial (Inciso b)\n");
        printf(" 2. Modificar parametros de la nave\n");
        printf(" 3. Salir\n");
        printf("=========================================\n");

        opcion = leer_entero_seguro("Seleccione una opcion: ", 1, 3);

        switch (opcion) {
            case 1:
                calcular_energia_cinetica(&orion);
                break;
            case 2:
                printf("\n--- MODIFICACION DE PARAMETROS ---\n");
                orion.masa = leer_doble_seguro("Ingrese nueva masa [kg]: ");
                orion.velocidad = leer_doble_seguro("Ingrese nueva velocidad [m/s]: ");
                break;
            case 3:
                printf("\nSaliendo del simulador...\n");
                break;
        }
    } while (opcion != 3);
}

