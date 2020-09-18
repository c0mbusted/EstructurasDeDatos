#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_PILA 10

typedef struct pila {
    int tope;
    int A[MAX_PILA];
}Pila;

Pila crearPila();

int esVacia(Pila p);

int esLlena(Pila p); 

Pila push(Pila p, int elem);

Pila pop(Pila p);