#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "cola.h"
#define MAX_COLA 5

int main () {
    Cola cola=crearCola();
    printf("\nSe ha creado la cola. Frente= %d y Final= %d\n\n", cola.frente, cola.final);

    cola=encolar(cola, 10);
    cola=encolar(cola, 20);
    cola=encolar(cola, 30);
    cola=encolar(cola, 40);

    printf("Se han ingresado 4 elementos. Frente: %d\n", cola.queue[cola.frente]);

    printf("El ultimo elemento en la cola es : %d\n", cola.queue[cola.final]);

    printf("\n\nSe elimina un elemento \n\n");
    
    cola=desencolar(cola);
    printf("El elemento del frente ahora es\n %d", cola.queue[cola.frente]);

    printf("\n\nSe elimina otro elemento \n\n");

    cola=desencolar(cola);
    printf("El elemento del frente ahora es %d\n", cola.queue[cola.frente]);


    return 0;

}