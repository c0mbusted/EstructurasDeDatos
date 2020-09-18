#ifndef APP_PILA_H
#define APP_PILA_H

#define MAX_PILA 20

typedef enum { FALSE = 0, TRUE } bool;

typedef struct {
    int tope;
    int elementos[MAX_PILA];
} Pila;

Pila crearPila();

bool esVacia(Pila p);

bool esLlena(Pila p);

Pila push(Pila p, int elem);

int obtener(Pila p);

Pila pop(Pila p);

#endif
