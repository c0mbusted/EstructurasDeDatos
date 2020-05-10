#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX_COLA 5

typedef struct cola {
    int frente, final;
    int queue[MAX_COLA];
} Cola;

Cola crearCola();

Cola encolar(Cola q, int e);

Cola desencolar(Cola q);

int recuperarFrente(Cola q);

bool esVacia(Cola q);

bool esLlena(Cola q);