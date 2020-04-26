#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define TAM 50 //max amount of elements

/* prototipos */
void agregarElementos(int A[], int n);

void mostrar(int A[], int n);

int buscarElemento(int A[], int bus, int n); //array n what u r gonn look for
int eliminarElemento(int A[], int elim ,int n);

int main() {
    int A[TAM]; //crea una rreglo de 30
    int n=10; /* vamos agregar n elementos del los TAM que tiene el arreglo */
    agregarElementos(A,n);
    mostrar(A,n);
    int b=5;
    int encontrado = buscarElemento(A,b,n);
    if (encontrado==-1) {
        printf("Elemento no existe");
    } else
    {
        printf("Eemento encontrado en la posicion %d",encontrado);
        //return 0;

    int b=5;
    int eliminado =eliminarElemento(A,b,n);
    if(eliminado==0) {
        printf("Elemento no ELIMINADO");//cunado no lo encuentra
    } else {
        printf("Elemento eliminado");
    }
    mostrar(A,n);
    return 0;
    }
    
   // eliminarElemento();
}


/* OPERACIONES o FUNCIONES del TAD */
/*void agregarElementos(int A[],int n) { //le decimos que es un vestor con el []
    for (int i=0; i < n; i++){
    printf("Ingrese elemento %d:",i+1);
    scanf (" %d", &A[i]);
    printf("\n");
    }
}*/

void agregarElementos(int A[],int n) {
    srand(time(NULL));
    for (int i=0; i < n; i++){
        A[i]=rand()%(10)+1;
    }
}


void mostrar(int A[],int n) {
    for (int i=0; i < n; i++){
    printf("Elemento numero %d = %d", i+1, A[i]);
    printf("\n");
    }
} 

//buscar
int buscarElemento(int A[], int bus, int n) {
    int i =0;
    int pos=-1;
    for (i=0;i < n; i++)
    {
        if (A[i]==bus) {
            pos =i;
            break;
        } 
        
    }
    return pos;

   
}

int eliminarElemento(int A[], int elim, int n) {

    int encontrado=buscarElemento(A, elim,n);//en esta var esta la posicion del array
    if(encontrado==-1) {
        return 0;
    } else {
        A[encontrado]=0;
        return 1;

    }
}