#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "servicio_impresion.h"
#include "documento.h"
#include "utils.h"


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    ServicioDeImpresion si = crearServicioDeImpresion();

    // aqui estamos creando 3 documentos a los añadimos a la cola (servidor de imp)
    Documento d1 = crearDocumento("doc1", 40, 3);
    si = asignarDocumentoAServicioDeImpresion(si, d1);
    Documento d2 = crearDocumento("doc2", 100, 1);
    si = asignarDocumentoAServicioDeImpresion(si, d2);
    Documento d3 = crearDocumento("doc3", 250, 2);
    si = asignarDocumentoAServicioDeImpresion(si, d3);
    Documento d4 = crearDocumento("doc4", 26, 2);
    si = asignarDocumentoAServicioDeImpresion(si, d4);
    Documento d5 = crearDocumento("doc5", 100, 2);
    si = asignarDocumentoAServicioDeImpresion(si, d5);

    // de esta manera podemos cancelar una impresion
    si = cancelarImpresion(si, d4);

    // este es un siclo que simula una impresión
    while(elServicioEstaVacio(si) == 0) {
        Documento d = recuperarDocumentoDelFrente(si);
        si = desencolarServicioDeImpresion(si);
        if (strcmp(d.estado, DOC_CANCELADO) != 0) {
            imprimir(d);
        }
    }

    return 0;
}



