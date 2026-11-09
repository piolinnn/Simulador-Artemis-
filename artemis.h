#ifndef ARTEMIS_H
#define ARTEMIS_H

/*
 * Parámetros Físicos - Problema 3: Inyección Translunar (TLI)
 * -----------------------------------------------------------
 * m = 26000,0 [kg]          (Masa de Orion)
 * v = 10900,0 [m/s]         (Velocidad TLI)
 * D = 384000000,0 [m]       (Distancia media Tierra-Luna)
 * h = 192000,0 [m]          (Altitud LEO)
 * K = 1/2 m v^2             (Energía cinética)
 */

#define MASA_ORION 26000.0
#define VELOCIDAD_TLI 10900.0
#define DISTANCIA_TL 384000000.0
#define ALTITUD_LEO 192000.0

typedef struct {
    double masa;              /* [kg] */
    double velocidad;         /* [m/s] */
    double altitud;           /* [m] */
    double energia_cinetica;  /* [J] */
} NaveOrion;

void iniciar_simulacion(void);

#endif
