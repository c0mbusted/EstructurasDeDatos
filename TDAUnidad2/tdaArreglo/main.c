#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "arrtad.h"


/* función principal main */
int main () {
    int A[SIZE]; 
    int n=10; //insertamos hasta 5 elementos
    //char *resp;
    //int val;
    int busqueda;
    int eliminado;

    agregarElementos (A,n);
   //mostrar (A,n);

    int val=5;
    printf("Se busca el numero 5\n\n");
    busqueda= buscar(A,val, n);
    if(busqueda== -1) {
        printf("Elemento no existe \n\n");
        
        printf("Los valores del array son: \n");
        mostrar (A,n);
    }else {
        printf("Elemento encontrado en la posicion %d\n\n", busqueda);
    }

    eliminado = eliminar(A,val,n);
    if (eliminado==0) {
        printf("Elemento NO eliminado\n\n");
    }else {
        printf("Elemento eliminado\n\n");

    }
    mostrar (A,n);
    return 0;
    
}
