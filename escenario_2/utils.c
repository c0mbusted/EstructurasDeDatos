#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "documento.h"

#define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

char * agregarNombreAleatorio() {
    char nombre[10];
    for (int i = 0; i < 9; ++i) {
        int num = randnum(1, 25);
        nombre[i] = 'A' + num;
    }
    return strdup(nombre);
}

int agregarPaginasAleatorias() {
    int num = randnum(1, 1000);
    return num;
}

int agregarCopiasAleatorias() {
    int num = randnum(1, 4);
    return num;
}

void imprimir(Documento d) {
    printf("=============== INICIO IMPRESION ===============\n");
    printf("Nombre del documento: %s \n", d.nombre);
    printf("Se imprimen %d paginas \n", d.num_copias * d.num_paginas);
    printf("================ FIN IMPRESION =================\n\n");
}

int obtenerNumeroEntre(int min, int max) {
    return randnum(min, max);
}
