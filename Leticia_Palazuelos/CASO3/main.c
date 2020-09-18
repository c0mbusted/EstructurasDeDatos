#include "arbolTDA.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 


int main() {
  Arbol *arbol;
  crearArbol(arbol);
  int datos[] = {30,21,33,32,41,43};  
  int n=7;
  int root =30;
  int clave=0;
 
  for (int i=0; i<n; i++) {
    arbol->raiz = insertar(arbol->raiz, datos[i]);
  }

  printf("\nRECORRIDO PREORDEN\t: ");
  preorden(arbol->raiz);
  printf("\nRECORRIDO INOORDEN\t: ");
  inorden(arbol->raiz);
  printf("\nRECORRIDO POSTORDEN\t: ");
  postorden(arbol->raiz);
  printf("\n");

  // CANTIDAD DE NODOS ARBOL
  int numNodos = contarNodos(arbol->raiz);
  printf("\nNumero de nodos en el arbol: %d", numNodos);

  // VERIFICA QUE VALOR ESTE EN HOJA O NO
  int resp = esHoja(arbol->raiz);
  printf("\nEl nodo es hoja: %d", resp);

  //ES BINARIO O NO
  int resultado = esABB(arbol->raiz);
  printf("\nEl arbol es binario? %d", resultado);

  //suma elementos
  sumaElementos(root, clave);
  return 0;
}