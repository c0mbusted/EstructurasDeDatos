#ifndef COLAS_IMPRESION_UTILS_H
#define COLAS_IMPRESION_UTILS_H

#include "documento.h"

char * agregarNombreAleatorio();

int agregarPaginasAleatorias();

int agregarCopiasAleatorias();

void imprimir(Documento d);

int obtenerNumeroEntre(int min, int max);

#endif //COLAS_IMPRESION_UTILS_H
