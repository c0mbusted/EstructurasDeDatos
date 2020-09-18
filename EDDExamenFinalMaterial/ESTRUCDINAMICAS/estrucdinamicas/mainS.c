#include <stdio.h>
#include <stdlib.h>

#include "Stack.c"

int main(){
	Pila *p = crearPila();

	printf("\nSe van a apilar 3 elementos al stack\n");
	for(int k=0;k<3;k++){
		push(p, crearDatos(2*k));
		printf("Valor tope: %i\n", p->tope->datos->d);
	}
	
	printf("\nDesapilamos los elementos\n");
	
	while(p->tope != NULL){
		printf("Valor tope: %i\n", p->tope->datos->d);
		pop(p);
	}
	
	freePila(p);
	
	return 0;
}