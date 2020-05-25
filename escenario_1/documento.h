#ifndef COLAS_IMPRESION_DOCUMENTO_H
#define COLAS_IMPRESION_DOCUMENTO_H

#define DOC_CANCELADO "cancelado"
#define DOC_ESPERA "espera"

typedef struct {
    char nombre[255];
    int num_paginas;
    int num_copias;
    char estado[30];
} Documento;

Documento crearDocumento(char nombre[255], int num_paginas, int num_copias);

#endif //COLAS_IMPRESION_DOCUMENTO_H
