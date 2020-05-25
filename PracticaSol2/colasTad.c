#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /*para usar tipo de dato bool en vez de int*/
#define MAX_COLA 30

/*Definición typedef*/
typedef struct tcola {
    int frente, final;
    int elementos[MAX_COLA];
}Cola;


/* prototipos*/
Cola crearCola();
Cola encolar(Cola q, int e);
Cola desencolar(Cola q);
int recuperarFrente(Cola q);
bool esVacia(Cola q); /*puede ser también tipo int en vez de bool*/
bool esLlena(Cola q); /*puede ser también tipo int en vez de bool*/



/*FUNCIONES*/
Cola crearCola(){
Cola q;
q.frente = -1;
q.final = -1;
return q;
}
bool esVacia(Cola q){
 return (q.frente == -1);
} 
24
bool esLlena(Cola q){
 return (q.final == (MAX_COLA-1));
}
Cola encolar(Cola q, int elem){
 if (q.final == q.frente-1){// esta condición es cuando Se ha vaciado la cola
q.frente = -1;
q.final = -1;
 }
 if (esLlena(q))
printf("\nCola Llena");
 else{
 if (esVacia(q))
q.frente++;
q.final++;
q.elementos[q.final] = elem;
 }
 return q;
}
Cola desencolar(Cola q) {
if (esVacia(q))
printf("\nCola Vacía");
else
q.frente++;
return q;
}
int recuperarFrente(Cola q){
return q.elementos[q.frente];
}