#include <stdlib.h>
#include <string.h>

typedef struct dataq{
	char *n;
}Dataq;

typedef struct nodeq{
	struct nodeq* next;
	Dataq *dato;
}Nodeq;

typedef struct queue{
	Nodeq *first, *last;
	int size;
}Queue;


Dataq* createDataq(char *a){
	Dataq* d = (Dataq*)malloc(sizeof(Dataq));
	strcpy(d->n,a);
	return d;
}

void freeDataq(Dataq *d){	
	free(d);
}

Nodeq *createNodeq(){
	Nodeq* n = (Nodeq*)malloc(sizeof(Nodeq));
	n->next = NULL;
	n->dato = NULL;
	return n;
}

void freeNodeq(Nodeq *n){
	if(n->dato != NULL) freeData(n->dato);
	free(n);
}

//cola
Queue *createQueue(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->first = NULL;
	q->last = NULL;
	q->size = 0;
	return q;
}

void push(Queue *q, Dataq *d){
	Nodeq *n = createNodeq();
	n->dato = d;
	if(q->first == NULL){
		q->first = n;
		q->last = n;
	}
	else{
		(q->last)->next = n;
		q->last = n;
	}
	q->size++;
}

void pop(Queue *q){
	if(q->size == 0) return;

	if(q->size == 1){
		freeNodeq(q->first);
		q->first = NULL;
		q->last = NULL;
	}
	else{
		Nodeq *aux = (q->first)->next;
		freeNodeq(q->first);
		q->first = aux;
	}
	q->size--;
}

int isEmpty (Queue *q) {
    return q->size==0;
}


void freeQueue(Queue *q){
	while(q->size != 0)
		pop(q);
	free(q);
}