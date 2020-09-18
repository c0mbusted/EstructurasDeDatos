#include "pila.h"

Pila crearPila() {
    Pila p;
    p.tope = -1;
    return p;
}

bool esVacia(Pila p) {
    return (p.tope == -1);
}

bool esLlena(Pila p) {
    return (p.tope == (MAX_PILA-1));
}

Pila push(Pila p, int elem) {
    ++p.tope;
    p.elementos[p.tope] = elem;
    return p;
}

Pila pop(Pila p) {
    p.tope--;
    return p;
}

int obtener(Pila p) {
    return p.elementos[p.tope];
}
