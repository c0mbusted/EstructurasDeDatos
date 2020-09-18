#include <stdlib.h>

typedef struct data{
	int n;
}Data;

typedef struct node{
	struct node* next;
	Data *dato;
}Node;

typedef struct queue{
	Node *first, *last;
	int size;
}Queue;

Data* createData(int a){
	Data* d = (Data*)malloc(sizeof(Data));
	d->n = a;
	return d;
}

void freeData(Data *d){
	/*
	Si mi data tiene heap agrega free a tus attrs. con heap
	*/	
	free(d);
}

Node *createNode(){
	Node* n = (Node*)malloc(sizeof(Node));
	n->next = NULL;
	n->dato = NULL;
	return n;
}

void freeNode(Node *n){
	if(n->dato != NULL) freeData(n->dato);
	free(n);
}

Queue *createQueue(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->first = NULL;
	q->last = NULL;
	q->size = 0;
	return q;
}

void push(Queue *q, Data *d){
	Node *n = createNode();
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
		freeNode(q->first);
		q->first = NULL;
		q->last = NULL;
	}
	else{
		Node *aux = (q->first)->next;
		freeNode(q->first);
		q->first = aux;
	}
	q->size--;
}


void freeQueue(Queue *q){
	while(q->size != 0)
		pop(q);
	free(q);
}
