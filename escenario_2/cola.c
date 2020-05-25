#include "cola.h"
#include "documento.h"


Cola crearCola() {
    Cola q;
    q.final = -1;
    q.frente = 0;
    return q;
}

Cola encolar(Cola q, Documento d) {
    q.final++;
    q.documentos[q.final] = d;
    return q;
}

Cola desEncolar(Cola q) {
    q.frente++;
    return q;
}

int colaEstaVacia(Cola q) {
    if (q.final < q.frente) {
        return VERDADERO;
    }
    return FALSO;
}

Documento recuperarDocumentoDelFrente(Cola q) {
    Documento d = q.documentos[q.frente];
    return d;
}

Documento recuperarDocumento(Cola q, int indice) {
    return q.documentos[indice];
}
