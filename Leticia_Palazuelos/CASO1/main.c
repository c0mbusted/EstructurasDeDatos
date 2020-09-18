#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    int S=13;
	List *l = createList();
	append(l, 1);
	append(l, 2);
	append(l, 6);
	append(l, 5);
	append(l, 8);
	append(l, 3);
    append(l, 4);
    append(l, 6);
	imprimir(l);
    int resultado = cuentaNodos(l);
    printf("%d", resultado);

    //para la suma sublista
    int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int sum = 23; 
    sumaSubLista(arr, n, sum); 
    return 0;



	limpiarLista(l);
	return 0;
}