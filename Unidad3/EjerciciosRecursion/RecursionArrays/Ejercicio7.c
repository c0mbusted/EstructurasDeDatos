/*Función recursiva llamada invertirArreglo
 invierta los elementos de un arreglo A.*/

#include <stdio.h>
#include <stdlib.h>

void invertir(int A[], int len, int indice);

/* función principal main */
int main () {
    int A[]={30, 28, 23, 18, 15, 7};
    int n=sizeof(A) / sizeof(A[0]);
    invertir(A, n - 1, n - 1);

    for (size_t i = 0; i < n; i++)
        printf("%d, ", A[i]);
    
    return 0;
}

void invertir(int A[], int len, int indice){
    if(indice == -1)
        printf("");
    else{
        int aux= A[len-indice];
        invertir(A, len, indice-1);
        A[indice]=aux;
    }
}

