#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "documento.h"
#include "listaColas.h"

int main()//int argc, char const *argv[]
{
    /* asi se inicializa la lista de colas (lista de colas => adiministrador de impresion) */
    ListaDeColas lq = crearListaDeColas();
    lq = llenarListaDeColas(lq);

    /* asi creamos nuevos documentos y los agrgamos al servicio */
    Documento d1 = crearDocumento("doc1", 130, 4);
    lq = asignarDocumentoAServidorImpresion(lq, d1);
    Documento d2 = crearDocumento("doc2", 1200, 2);
    lq = asignarDocumentoAServidorImpresion(lq, d2);
    Documento d3 = crearDocumento("doc3", 99, 15);
    lq = asignarDocumentoAServidorImpresion(lq, d3);
    Documento d4 = crearDocumento("doc4", 255, 4);
    lq = asignarDocumentoAServidorImpresion(lq, d4);
    Documento d5 = crearDocumento("doc5", 340, 1);
    lq = asignarDocumentoAServidorImpresion(lq, d5);
    Documento d6 = crearDocumento("doc6", 340, 1);
    lq = asignarDocumentoAServidorImpresion(lq, d6);
    Documento d7 = crearDocumento("doc7", 340, 1);
    lq = asignarDocumentoAServidorImpresion(lq, d7);
    Documento d8 = crearDocumento("doc8", 340, 1);
    lq = asignarDocumentoAServidorImpresion(lq, d8);

    /* asi posdemos eliminar el documento */
    lq = cancelarImpresion(lq, d2);
    lq = cancelarImpresion(lq, d4);
    //lq = cancelarImpresion(lq, d1);

    /* de esta forma simulamos las impresiones */
    for (int i = 0; i < MAX_COLAS_POR_LISTA; i++) {
        printf("************ DOCTOS COLA %d ************\n\n", i);
        while(colaEstaVacia(lq.colas[i]) == FALSO) {
            Documento d = recuperarDocumentoDelFrente(lq.colas[i]);
            lq.colas[i] = desEncolar(lq.colas[i]);
            imprimir(d);
        }
    }

    return 0;
}
