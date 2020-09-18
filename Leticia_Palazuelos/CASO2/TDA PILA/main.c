#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "pila.h"
#define MAX_PILA 11

//PILA DOBLE ESTATICA

int main() {
    Pila pila= crearPila(); //la var p de pila.c viene aqui
    printf("\n Se ha creado la pila. Tope Izquierda= %d\t Tope Derecha= %d\n", pila.topeizq, pila.topeder);
	
    printf("Esta vacia la pila?: \n");
    while (esVacia(pila)) {
    	
    	pila=push(pila,10);
    	pila=push(pila,20);
    	pila=push(pila,30);
    	pila=push(pila,40);
    	pila=push(pila,50);
    	pila=push(pila,60);
    	pila=push(pila,70);
    	pila=push(pila,80);
    	pila=push(pila,90);
    	pila=push(pila,100);
    	printf("\nSe ha insertado la pila. Tope Izquierda= %d \t Tope Derecha: %d\n\n", pila.topeizq, pila.topeder);
    
    
    }
    printf("\nPila llena.\n\n");
    printf("\nPila quedó con tope izq =%d y tope der =%d ", pila.topeizq, pila.topeder);//pila.A[pila.topeizq]
    
 

return 0;
}
