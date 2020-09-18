/*Función recursiva llamada insertar que inserte un elemento en un arreglo que está
ordenado de menor a mayor*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
# define SIZE 30



void insertar(int A[], int indice, int numero);

/* función principal main */
int main () {
    int A[]={2,5,6,8,10,0};
    int n=(sizeof(A)/sizeof(A[0]))-1;
    int numero =3;
    /*srand(time(NULL));
    for (int i=0; i < n; i++){
        A[i]=rand()%10+1;
    }*/

    insertar(A,n,numero);
    for (size_t i = 0; i < n + 1; i++)
        printf("%d, ", A[i]);
    return 0;
    //int suma,numero,wanted,numinsert;
}




void insertar(int A[], int indice, int numero){
    if(indice == -1){
        A[indice+1] = numero; //cuando llega al final y debe insertarlo (primer caso base)
        return;
    }else{
         A[indice] = A[indice - 1];
        if(numero >A[indice]){
          A[indice] = numero; //cuando inserta el número SALE (segundo caso base)
          return;
        }else {
            //A[indice+1] = A[indice];//Corre los elementos mientras pilla donde insertar
            insertar(A, indice-1, numero);
        }
    }
}