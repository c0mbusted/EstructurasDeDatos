#include <stdio.h>
#include <stdlib.h>

typedef struct info{
	int dato;
}Info;

typedef struct node{
	struct node* next;
	Info* data;
}Node;

typedef struct list{
	int size;
	Node *first;
}List;

Info *createInfo(int n){
	Info *i = (Info*)malloc(sizeof(Info));
	i->dato = n;
	return i;
}

Node *createNode(){
	Node *n = (Node*)malloc(sizeof(Node));
	n->next = NULL;
	n->data = NULL;
	return n;
}

List *createList(){
	List *l = (List*)malloc(sizeof(List));
	l->size = 0;
	l->first = NULL;
	return l;
}

void append(List* l, int i){ 
Info *inf = createInfo(i); 
Node *n = createNode(); 
n->data = inf; 
	if(l->size == 0) 
		l->first = n; 
	else{ 
		Node *aux = l->first; 
		for(int k=0;k<l->size-1;k++) 
			aux = aux->next; 
		 
		aux->next = n; 
	}
l->size++; 
}

void imprimir(List *l){
	Node *actual = l->first;
	for(int k=0;k<l->size;k++){
		printf("Valor: %i\n", actual->data->dato);
		actual = actual->next;
	}
}

void limpiarLista(List *l){
	if(l->size == 0) 
		free(l);
	else{ 
		Node *actual = l->first;
		while(actual->next != NULL){ 
			Node *del = actual; 
			actual = actual->next; 
			free(del->data); 
			free(del); 
		}
		free(actual); 
	}
}

//funcion de CONTAR NODOS
int cuentaNodos(List *l) {
	if (l->size == NULL) {
		return 0;
	} else {
		return (1+cuentaNodos(l->first));
	}
}
//funcion SUMA SUB LISTA
int sumaSubLista(int arr[], int n, int total) { 
    int suma, i, j; 

    for (i = 0; i < n; i++) { 
        suma = arr[i]; 
        for (j = i + 1; j <= n; j++) { 
            if (suma == total) { 
                printf( 
                    "La sublista esta entre el indice  %d y %d", 
                    i, j - 1); 
                return 1; 
            } 
            if (suma > total || j == n) 
                break; 
            suma = suma + arr[j]; 
        } 
    } 
  
    printf("No se encontro una sublista"); 
    return 0; 
} 
