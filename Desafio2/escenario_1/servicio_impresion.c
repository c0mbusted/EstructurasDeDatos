#include <string.h>
#include "servicio_impresion.h"

ServicioDeImpresion crearServicioDeImpresion() {
    ServicioDeImpresion si;
    si.final = -1;
    si.frente = 0;
    return si;
}

ServicioDeImpresion asignarDocumentoAServicioDeImpresion(ServicioDeImpresion si, Documento d) {
    si.final++;
    si.documentos[si.final] = d;
    return si;
}

ServicioDeImpresion cancelarImpresion(ServicioDeImpresion si, Documento d) {
    for (int i = si.frente; i <= si.final; ++i) {
        if (strcmp(si.documentos[i].nombre, d.nombre) == 0) {
            stpcpy(si.documentos[i].estado, DOC_CANCELADO);
        }
    }
    return si;
}

int elServicioEstaVacio(ServicioDeImpresion si) {
    if (si.final < si.frente) {
        return 1;
    }
    return 0;
}

ServicioDeImpresion desencolarServicioDeImpresion(ServicioDeImpresion si) {
    si.frente++;
    return si;
}

Documento recuperarDocumentoDelFrente(ServicioDeImpresion si) {
    Documento d = si.documentos[si.frente];
    return d;
}
