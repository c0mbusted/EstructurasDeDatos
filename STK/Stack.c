#include <stdlib.h>

typedef struct data{
	int d;
	/*
	atr1
	atr2 
	...
	*/
}Data;

Data* createData(int n /*, param1, param2, param3*/){
	Data *a = (Data*)malloc(sizeof(Data));
	a->d = n;
	/*
	a->attr1 = param1;
	a->attr2 = param2;
	a->attr3 = param3;
	*/
	return a;
}

void freeData(Data *data){
	/*
	If Data data has heap memory attributes, free here...
	HERE....
	*/
	
	//This at end
	free(data);
}

/*########################################
##                                      ##
##  NO CAMBIAR NADA DE AQUÍ PARA ABAJO  ##
##                                      ##
########################################*/

typedef struct node{
	Data *data;
	struct node *next;
}Node;

Node* createNode(){
	Node *a = (Node*)malloc(sizeof(Node));
	a->next = NULL;
	a->data = NULL;
	return a;
}

void freeNode(Node *n){
	if(n->data != NULL) freeData(n->data);
	free(n);
}

//LIST STUFF

typedef struct stack{
	Node *top;
}Stack;

Stack* createStack(){
	Stack* a = (Stack*)malloc(sizeof(Stack));
	a->top = NULL;
	return a;
}

void push(Stack* s, Data *d){
	Node *n = createNode();
	n->data = d;
	if(s->top == NULL)
		s->top = n;
	else{
		n->next = s->top;
		s->top = n;
	}
}

void pop(Stack* s){
	if(s->top == NULL) return;
	Node *aux = s->top;
	s->top = aux->next;
	freeNode(aux);
}

void freeStack(Stack *s){
	while(s->top != NULL)
		pop(s);
	free(s);
}