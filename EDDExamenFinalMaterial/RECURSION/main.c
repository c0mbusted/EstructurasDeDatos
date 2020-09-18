#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "recarr.h"


/* función principal main */
int main () {
    int A[SIZE]; 
    int B[SIZE]; 
    int n=10; 
    int suma,numero,wanted,numinsert;
    
    agregarElementos (A,n);
    agregarElementos (B,n);

    imprimirArreglo(A,0,n);

    suma =sumaArreglo(A,n);
    printf("\nLa SUMA de los elementos en el arreglo es: %d\n",suma);
    
    //printf("\nSe ordenaran los elementos de arreglo...\n");
    
    printf("\nElementos Ordenados\n");
    ordenarArreglo(A,n);
    imprimirArreglo(A,0,n);
    printf("\nIngrese un numero para ver cuantas veces se repite:\n ");
    scanf("%d",&numero);
    
    int repetido= cuentaOcurrencias(A,n,numero);
    printf("\nElemento se repite %d veces\n",repetido);

    printf("\nIngresar el numero a buscar:\n");
    scanf("%d",&wanted);
    int buscado= buscarElemento(A,n,wanted);
    printf("\n0 False y 1 True\t Fue encontrado?  %d\n",buscado);
    
    printf("\nSon iguales A y B?\n");
    imprimirArreglo(A,0,n);
    printf("\n");
    imprimirArreglo(B,0,n);

    int resultado = esIgual(A,B,n);
    printf("\n0 False y 1 True\t Son iguales? %d\n",resultado); 

    




    return 0;
    
}