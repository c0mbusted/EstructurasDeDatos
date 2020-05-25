#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "preg1.h"

//Función recursiva que, dado un arreglo A, 
//tiene valores enteros positivos, indica
//la mínima cantidad de elementos consecutivos 
//al final de la lista cuya suma sea
//mayor o igual que un determinado valor C.

int main() {
    int A[SIZE];
    int n=10;
    //int C=12;
    
    agregarElementos(A,n);
    printf("\n");
    imprimirArreglo(A,0,n);
    //printf("\nIngrese un numero: del 1 al 15\n");
    //scanf("%d",&C);
    int total= funcion(A,n,0, 12);
    printf("total de numeros que sumaod superan a 12 es: %d",total);

    return 0;
}