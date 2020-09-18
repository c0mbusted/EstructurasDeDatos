
#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main () {
    Arbol *arbol;
    crearArbol(arbol);
    int datos[]={31,43,23,29,50,20,35,39,37,40};
    int n=10;
    for(int i=0; i<n; i++) {
        arbol->raiz=insertar(arbol->raiz,datos[i]);
    }
    printf("\n ARBOL CREADO\n");
   

    printf("\n RECORRIDO PREORDEN\n");
    preorden(arbol->raiz);

    printf("\n\n RECORRIDO INORDEN\n");
    inorden(arbol->raiz);

    printf("\n\n RECORRIDO POSTORDEN\n");
    postorden(arbol->raiz);
   
    Nodo *temp;
    temp = buscarSucesor(arbol->raiz->right);
    printf("\n\nValor del sucesor de la raiz %d es %d", arbol->raiz->info->clave,temp->info->clave);
   

    int valElim=35;
   
    arbol->raiz =eliminar(arbol->raiz,valElim);
    printf("\n\nNODO CON 1 HIJO ELIMINADO %d\n\n ",valElim);
    //imprimirArbol(arbol->raiz,0);
   
    printf("\n RECORRIDO PREORDEN PARA PROBAR ELIMINACION\n");
    preorden(arbol->raiz);

    valElim=31;
    arbol->raiz=eliminar(arbol->raiz,valElim);
    printf("\nNODO CON 2 HIJOS ELIMINADOS %d",valElim);
    printf("REEMPLAZADO CON SU SUCESOR");


    printf("\n RECORRIDO PREORDEN PARA PROBAR ELIMINACION\n");
    preorden(arbol->raiz);

    printf("\n\n");
    //imprimirArbol(arbol->raiz,0);
     
    return 0;

}
