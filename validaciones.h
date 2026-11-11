#ifndef VALIDACIONES_H
#define VALIDACIONES_H

double leer_doble_seguro(const char *mensaje);
double leer_doble_positivo(const char *mensaje);
double leer_doble_no_negativo(const char *mensaje);
int leer_entero_seguro(const char *mensaje, int min, int max);

#endif
