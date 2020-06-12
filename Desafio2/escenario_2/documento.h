#ifndef COLAS_IMPRESION_DOCUMENTO_H
#define COLAS_IMPRESION_DOCUMENTO_H

#define DOC_ESPERA "espera"
#define DOC_CANCELADO "cancelado"

typedef struct {
    char nombre[255];
    int num_paginas;
    int num_copias;
    char estado[30];
} Documento;

Documento crearDocumento(char nombre[255], int num_paginas, int num_copias);

#endif //COLAS_IMPRESION_DOCUMENTO_H
