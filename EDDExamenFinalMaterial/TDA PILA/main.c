 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "pila.h"
#define MAX_PILA 10


int main() {
    Pila pila=crearPila(); //la var p de pila.c viene aqui
    printf("\n Se ha creado la pila. Tope= %d\n\n", pila.tope);

    pila=push(pila,10);
    pila=push(pila,20);
    pila=push(pila,30);
    pila=push(pila,40);
    

    printf("\n Se ha insertado la pila. Tope= %d\n\n", pila.tope);
    printf("\n El ultimo de la pila es = %d\n\n", pila.A[pila.tope]);

    printf("\nSe elimina un elemento de la pila....\n\n");
    pila=pop(pila);//le paso la pila, no elindice porque solo se va el ultmo elem
    printf("\n El ultimo de la pila es = %d\n\n", pila.A[pila.tope]);
    printf("\n Se ha eliminado elemento la pila. Tope= %d\n\n", pila.tope);
    

//agregar elementos a la pila
   /* int i =0;
    do {
        i++;
        if(esVacia(pila)) {
            printf("\nPila vacia.\n\n");
            pila = push(pila, i*10);
        
    } while (i < MAX_PILA);
        if (esLlena(pila)) {
            printf("\nPila llena.\n\n");
            printf("\nPila quedó con tope=%d con valor=%d ", pila.tope, pila.A[pila.tope]);
        }
    } do {
        pila = pop(pila);
    } while (pila.tope >=0);//mientras tenga elementos
printf("\nSe ha vaciado la pila. Tope quedó con :%d ",pila.tope );*/
return 0;
}