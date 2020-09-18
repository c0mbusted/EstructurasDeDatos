#include <stdlib.h>
//datos contiene informacion

typedef struct datos{
    int d;
}Datos;

Datos* crearDatos(int n){
	Datos *a = (Datos*)malloc(sizeof(Datos));
	a->d = n;
	return a;
}

void freeDatos(Datos *datos){
	free(datos);
}

/*typedef struct info{
	int valor;
}Info;*/


//nodo 

typedef struct nodo {
    Datos *datos;
    struct nodo *next;

}Nodo;


Nodo* crearNodo(){
	Nodo *a = (Nodo*)malloc(sizeof(Nodo));
	a->next =  NULL;
	a->datos = NULL;
	return a;
}

void freeNodo(Nodo *n){
	if(n->datos != NULL) freeDatos(n->datos);
	free(n);
}

//stack

typedef struct pila{
    Nodo *tope;
    //int tam;
} Pila;


Pila* crearPila(){
	Pila* a = (Pila*)malloc(sizeof(Pila));
	a-> tope = NULL;
	return a;
}

//insertar elementos al stack

void push(Pila* p, Datos *d){
	Nodo *n = crearNodo();
	n->datos = d;
	if(p->tope == NULL)
		p->tope = n;
	else{
		n->next = p->tope;
		p->tope = n;
	}
}

//desapilar 
void pop(Pila* p){
	if(p->tope == NULL) return;
	Nodo *aux = p->tope;
	p->tope = aux->next;
	freeNodo(aux);
}

//hacemo el free() de la memoria heap
void freePila(Pila *p){
	while(p->tope != NULL)
		pop(p);
	free(p);
}









