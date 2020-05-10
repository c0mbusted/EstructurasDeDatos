#include "cola.h"

Cola crearCola (){
    Cola q;
    q.final = -1;
    q.frente = -1;
    return q;
}

Cola encolar (Cola q, int e){
    if (q.final == q.frente-1){// esta condición es cuando Se ha vaciado la cola
        q.frente = -1;
        q.final = -1;
    }
    if (esLlena(q)) {
        printf("\nCola Llena");
    }else{
     if (esVacia(q)){
        q.frente++;
     }
        q.final++;
        q.queue[q.final] = e;
    }
    return q;
}

Cola desencolar (Cola q){
    if (esVacia(q)) {
        printf("\nCola Vacía");
    } else {
        q.frente++;
    }
    return q;
}


int recuperarFrente (Cola q) {
    return q.queue[q.frente];
    
}


bool esVacia(Cola q){
    return(q.frente==-1);
}

bool esLlena (Cola q){
    return (q.final== (MAX_COLA-1));
}
