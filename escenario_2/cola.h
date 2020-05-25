#ifndef COLAS_IMPRESION_COLA_H
#define COLAS_IMPRESION_COLA_H
#include "documento.h"

#define MAX_COLA 100
#define FALSO 0
#define VERDADERO 1

typedef struct {
    int frente;
    int final;
    Documento documentos[MAX_COLA];
} Cola;

Cola crearCola();

Cola encolar(Cola q, Documento d);

int colaEstaVacia(Cola q);

Cola desEncolar(Cola q);

Documento recuperarDocumentoDelFrente(Cola q);

Documento recuperarDocumento(Cola q, int indice);

#endif //COLAS_IMPRESION_COLA_H
