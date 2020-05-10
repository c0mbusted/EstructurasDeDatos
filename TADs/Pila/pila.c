#include "pila.h"

Pila crearPila() {
    Pila p; //p es una estructura tipo Pila
    p.tope=-1;
    return p;
}

int esVacia(Pila p) {
    if (p.tope==-1) {
        printf("\nPila vacia\n");
        return 1;
    } else {
        return 0;
    }
}

int esLlena(Pila p) {
    if (p.tope== (MAX_PILA-1)) {
        printf("\nPila llena\n");
        return 1;
    } else {
        return 0;
    }
}

Pila push(Pila p, int elem) {
    if (!esLlena(p)) {
        p.tope++; //el tope es el indice que se va agregando
        p.A[p.tope] = elem;
    }  
    return p;
}

Pila pop(Pila p) {
    if (!esVacia(p)) {
        p.tope--;
    }
    return p;
}

