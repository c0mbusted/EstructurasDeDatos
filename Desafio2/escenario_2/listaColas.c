#include <string.h>
#include "cola.h"
#include "documento.h"
#include "listaColas.h"

ListaDeColas crearListaDeColas() {
    ListaDeColas lq;
    lq.final = -1;
    lq.frente = 0;
    return lq;
}

ListaDeColas llenarListaDeColas(ListaDeColas lq) {
    for (int i = 0; i < MAX_COLAS_POR_LISTA; ++i) {
        lq = agregarColaALista(lq, crearCola());
    }
    return lq;
}

ListaDeColas agregarColaALista(ListaDeColas lq, Cola cola) {
    lq.final++;
    lq.colas[lq.final] = cola;
    return lq;
}

int sumadeDocumentos(Cola q) {
    int totalDeHojas = 0;
    for (int i = q.frente; i <= q.final; ++i) {
        Documento d = recuperarDocumento(q, i);
        totalDeHojas += d.num_paginas * d.num_copias;
    }
    return totalDeHojas;
};

int obtenerIndiceMejorCola(ListaDeColas lq) {
    int mejorCola = 0;
    int totalDeHojasDeMejorCola = 0;
    for (int i = lq.frente; i <= lq.final; ++i) {
        Cola q = lq.colas[i];
        int totalDeHojas = sumadeDocumentos(q);
        if (totalDeHojas == 0) {
            return i;
        }
        else if (totalDeHojas < totalDeHojasDeMejorCola || totalDeHojasDeMejorCola == 0) {
            totalDeHojasDeMejorCola = totalDeHojas;
            mejorCola = i;
        }
    }
    return mejorCola;
}

ListaDeColas asignarDocumentoAServidorImpresion(ListaDeColas lq, Documento d) {
    int i = obtenerIndiceMejorCola(lq);
    lq.colas[i] = encolar(lq.colas[i], d);
    return lq;
}

ListaDeColas cancelarImpresion(ListaDeColas lq, Documento d) {
    for (int i = 0; i < 3; ++i) {
        for (int j = lq.colas[i].frente; j <= lq.colas[i].final; ++j) {
            if (strcmp(lq.colas[i].documentos[j].nombre, d.nombre) == 0) {
                stpcpy(lq.colas[i].documentos[j].estado, DOC_CANCELADO);
            }
        }
    }
    lq = redistribuir(lq);
    return lq;
}

ListaDeColas redistribuir(ListaDeColas lq) {
    ListaDeColas lq2 = crearListaDeColas();
    lq2 = agregarColaALista(lq2, crearCola());
    lq2 = agregarColaALista(lq2, crearCola());
    lq2 = agregarColaALista(lq2, crearCola());
    for (int i = 0; i < 3; ++i) {
        for (int j = lq.colas[i].frente; j <= lq.colas[i].final; ++j) {
            Documento d = lq.colas[i].documentos[j];
            if (strcmp(d.estado, DOC_ESPERA) == 0) {
                lq2 = asignarDocumentoAServidorImpresion(lq2, d);
            }
        }
    }
    return lq2;
}
