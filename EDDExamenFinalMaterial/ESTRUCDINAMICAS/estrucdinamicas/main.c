#include <stdio.h>

#include "Queue.c" //Incluir librería

int main(){
	Queue *q = createQueue(); //Crear cola
	
	push(q, createData(432)); //Agrego...
	push(q, createData(412)); //Agrego...
	push(q, createData(13)); //Agrego...
	push(q, createData(54)); //Agrego...
	push(q, createData(52)); //Agrego...
	
	Node *curr = q->first;  //Nodo actual
	for(int k=0; k<q->size; k++){  //Recorro mi cola...
		printf("%i\n", curr->dato->n); //Imprimo el dato actual
		curr = curr->next; //Paso al siguiente elemento
	}
	
	freeQueue(q); //No olvidar memoleak
	return 0;
}