#include <string.h>
#include "documento.h"

Documento crearDocumento(char nombre[255], int num_paginas, int num_copias) {
    Documento d;
    strcpy(d.nombre, nombre);
    strcpy(d.estado, DOC_ESPERA);
    d.num_paginas = num_paginas;
    d.num_copias = num_copias;
    return d;
};
