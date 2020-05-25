#include <stdio.h>
#include <stdlib.h>
#define MAX_P 10

typedef struct cola{
    int dato[Maxcola];
    int final;
    char nombre[10];
}Cola

Cola crearCola() {
    Cola c;
    c.final=0;
}

bool llena(Cola c) {
    return p.final==Maxcola;
}

bool vacia(Cola c) {
    return p.final==0;
}

Cola push(Cola c) {
    if(!llena(c) {
        c.dato[c.final++]=e;
    }
    return c;
}

Cola pop(Cola c) {
    if(vacia(c)) {
        for(int k=0;k<Maxcola-1;k++) {
            c.dato[k]=c.dato[k+1];
        p.final--;
        }
        return p;
    }
}
int main() {
    Persona personas[10];

    return 0;
}