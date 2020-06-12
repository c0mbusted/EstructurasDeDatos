#ifndef COLA_IMPRESIO_SERVICIO_IMPRESION_H
#define COLA_IMPRESIO_SERVICIO_IMPRESION_H

#include "documento.h"

#define MAX_COLA 100

typedef struct {
    int frente;
    int final;
    Documento documentos[MAX_COLA];
} ServicioDeImpresion;

ServicioDeImpresion crearServicioDeImpresion();

ServicioDeImpresion asignarDocumentoAServicioDeImpresion(ServicioDeImpresion si, Documento d);

ServicioDeImpresion cancelarImpresion(ServicioDeImpresion si, Documento d);

Documento recuperarDocumentoDelFrente(ServicioDeImpresion si);

ServicioDeImpresion desencolarServicioDeImpresion(ServicioDeImpresion si);

int elServicioEstaVacio(ServicioDeImpresion si);

#endif //COLA_IMPRESIO_SERVICIO_IMPRESION_H
