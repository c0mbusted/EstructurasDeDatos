
#include <stdlib.h>
#include <string.h>
#include "cola.c"

typedef struct data{
	char nombre;
    Queue *pacientes;
	
}Data;

Data* createData(char *nombre){
	Data* a = (Data*)malloc(sizeof(Data));
    strcpy(a->nombre,nombre);
	a->pacientes= createQueue();
	return a;
}

void freeData(Data *data){
	
	free(data);
    freeQueue(data->pacientes);
}


typedef struct node{
	Data *data;
	struct node *back, *next;
}Node;

Node* createNode(){
	Node *a = (Node*)malloc(sizeof(Node));
	a->back = NULL;
	a->next = NULL;
	a->data = NULL;
	return a;
}

void freeNode(Node *n){
	if(n->data != NULL) freeData(n->data);
	free(n);
}



typedef struct list{
	Node *first, *last;
	int size;
}List;

List* createList(){
	List* a = (List*)malloc(sizeof(List));
	a->last = NULL;
	a->first = NULL;
	a->size = 0;
	return a;
}

void add(List* l, Data *d, int index){
	Node *n = createNode();
	n->data = d;
	
	if(l->size == 0){
		l->last = n;
		l->first = n;
		n->back = l->last;
		n->next = l->first;
	}
	else if(index <= 0){
		l->first->back = n;
		n->next = l->first;
		n->back = l->last;
		l->first = n;
	}
	else if(index+1 >= l->size){
		l->last->next = n;
		n->back = l->last;
		n->next = l->first;
		l->last = n;
	}
	else{
		Node *aux = l->first;
		for(int k=0;k<=index;k++) aux = aux->next;
		Node *aux2 = aux->back;
		
		aux->back = n;
		aux2->next = n;
		n->back = aux2;
		n->next = aux;
	}

	l->size++;
}

void del(List* l, int index){
	if(l->size == 0) return;
	else if(l->size == 1){
		freeNode(l->first);
		l->first = NULL;
		l->last = NULL;
	}
	else if(index <= 0){
		Node *aux = l->first->next;
		freeNode(l->first);
		l->first = aux;
		aux->back = l->last;
	}
	else if(index+1 >= l->size){
		Node *aux = l->last->back;
		freeNode(l->last);
		l->last = aux;
		aux->next = l->first;
	}
	else{
		Node *aux = l->first;
		for(int k=0;k<index-1;k++)
			aux = aux->next;
		Node *aux2 = (aux->next)->next;
		freeNode(aux->next);
		
		aux->next = aux2;
		aux2->back = aux;
	}
	l->size--;
}

void freeList(List *l){
	if(l->size != 0){
	Node *current = l->first;
		while(l->size != 0) del(l, 0);
	}
	free(l);
}