#include "cola.h"


/**
 * Función Principal
 *
 */
int main(int argc, char *argv[])
{
  Cola *C;
  C = creaCola();
  push(C, 1);
  push(C, 2);
  push(C, 3);
  push(C, 4);
  printf("inicio: % d - fin: % d\n",
         primero(C)->datos->dato1, ultimo(C)->datos->dato1);
  pop(C);
  printf("inicio: % d - fin: % d\n",
         primero(C)->datos->dato1, ultimo(C)->datos->dato1);
  push(C, 5);
  push(C, 6);
  printf("inicio: % d - fin: % d\n",
         primero(C)->datos->dato1, ultimo(C)->datos->dato1);
  destruirCola(C);
	C = creaCola();
  push(C, 7);
  push(C, 8);
  printf("inicio: % d - fin: % d\n",
         primero(C)->datos->dato1, ultimo(C)->datos->dato1);
  return 0;
}
