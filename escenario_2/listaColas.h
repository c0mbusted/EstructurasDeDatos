#ifndef COLAS_IMPRESION_LISTACOLAS_H
#define COLAS_IMPRESION_LISTACOLAS_H

#include "cola.h"
#include "documento.h"

#define MAX_COLAS_POR_LISTA 3
#define FALSO 0
#define VERDADERO 1

typedef struct {
    int frente;
    int final;
    Cola colas[MAX_COLAS_POR_LISTA];
} ListaDeColas;

ListaDeColas crearListaDeColas();

ListaDeColas llenarListaDeColas(ListaDeColas lq);

ListaDeColas agregarColaALista(ListaDeColas lq, Cola q);

int obtenerIndiceMejorCola(ListaDeColas lq);

ListaDeColas asignarDocumentoAServidorImpresion(ListaDeColas lq, Documento d);

int sumadeDocumentos(Cola cola);

ListaDeColas cancelarImpresion(ListaDeColas lq, Documento d);

ListaDeColas redistribuir(ListaDeColas lq);

#endif //COLAS_IMPRESION_LISTACOLAS_H
