#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /*para usar tipo de dato bool en vez de int*/
#define MAX_PILA 30 /*cantidad máxima elementos pila*/
/*Definición typedef*/
typedef struct tpila {
 int tope;
 int A[MAX_PILA];
}Pila;
/* prototipos*/

Pila crearPila();
    Pila p;
    p.tope = -1;
    return p;



/*PRINCIPAL*/
int main() {
 Pila pila=crearPila(); /*crea la pila vacía*///tope -1 indica que pila es vacia
 printf("\nSe ha creado la pila. Tope= %d ", pila.tope);
 /*pila=push (pila, 10);
 pila=push (pila, 30);
 pila=push (pila, 60);*///one way to agregar stuff a pila

 //como agrego el 10 a elementos?

 pila.A[0]=10;
 pila.tope++;
 if (/* condition */)
 {
     /* code */
 }
 

 
 return 0;
}

 /*agregar elementos a la pila*/
 



Pila crearPila(){
 Pila p;
 p.tope = -1;
 return p;
}


bool esVacia(Pila p){
    if (p.tope)
    {
        /* code */
    }
    
 return (p.tope == -1);
}
int esLlena(Pila p){
 if (p.tope == (MAX_PILA-1)) {
     printf("Pila llena");
     return 1;
 }else {
     return 0;
 }
}


Pila push(Pila p, int e){
    if (!esLlena(p)) {
        p.tope++;//es el indice que se va agregando
        p.A[p.tope]=e;
    }
    return p;  
}



Pila pop(Pila p) {
p.tope--;
 return p;
} 