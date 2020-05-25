#include <stdio.h>
#include <stdlib.h>
#define MAX_P 10

typedef struct pila() {
    int dato[MAX_P];
    int last;
}Pila;

int main() {
    Pila p=crearPila();
    p=push_p(p,1);
    p=push_p(p,2);
    p=push_p(p,3);
    p=push_p(p,4);
    for(int k=p.tope-1;k>=0;k--) {
        printf("%i\n",p.dato[k]);
    }
    return p;   
}(

Pila crearPila() {
    Pila p;
    p.tope=0;
    return p;
}
Pila push_p(Pila p, int e) {
    if(!llena_p(p)) {
        p.dato[p.tope++]=e;
    }
    return p;
}

bool llena (Pila p) {
    return p.tope==0;
}

bool vacia(Pila p) {
    return 
}
