#include <stdio.h>
#include "pila.h"


typedef struct {
    Pila pares;
    Pila impares;
} PilaDoble;

Pila duplicarContenido(Pila p) {
    Pila pila = crearPila();

    while (!esVacia(p)) {
        pila = push(pila, obtener(p) * 2);
        p = pop(p);
    }

    printf("\n(a) Pila con contenido duplicado");

    while (!esVacia(pila)) {
        p = push(p, obtener(pila));
        pila = pop(pila);
    }

    return p;
}

Pila eliminaValor(Pila p, int v) {
    Pila pila = crearPila();
    while (!esVacia(p)) {
        int valor = obtener(p);
        if (valor != v) {
            pila = push(pila, valor);
        }
        p = pop(p);
    }
    p = pila;
    return p;
}

void mostrarDatos(Pila p) {
    printf("\n{");
    bool vacia = esVacia(p);
    while (!vacia) {
        int valor = obtener(p);
        printf("%d",  valor);
        p = pop(p);
        vacia = esVacia(p);
        if (!vacia) printf(", ");
    }
    printf("}");
}

int sumarContenido(Pila p) {
    int suma = 0;
    int i = 0;
    do {
        i++;
        suma += p.elementos[i];
    } while (i < p.tope);
    return suma;
}

int elMaximo(Pila p) {
    int maximo = 0;
    for (int i = 0; i < p.tope; ++i) {
        if (p.elementos[i] > maximo) {
            maximo = p.elementos[i];
        }
    }
    return maximo;
}

PilaDoble paresImpares(Pila p) {
    PilaDoble p2;
    p2.pares = crearPila();
    p2.impares = crearPila();
    for (int i = 0; i < p.tope; ++i) {
        if (p.elementos[i] % 2 == 0) {
            p2.pares = push(p2.pares, p.elementos[i]);
        }
        else {
            p2.impares = push(p2.impares, p.elementos[i]);
        }
    }
    return p2;
}

bool compararPilas(Pila p1, Pila p2) {

    if (esVacia(p1) && esVacia(p2)) {
        return TRUE;
    }

    if ((!esVacia(p1) && esVacia(p2)) || (esVacia(p1) && !esVacia(p2)) ) {
        return FALSE;
    }

    if (p1.tope != p2.tope) {
        return FALSE;
    }

    bool resp = TRUE;

    for (int i = 0; i < p1.tope; ++i) {
        if (p1.elementos[i] != p2.elementos[i]) {
            resp = FALSE;
            break;
        }
    }
    return resp;
}

Pila ponerLosPrimerosNElementos(Pila p, int n) {
    Pila pila1 = crearPila();
    Pila pila2 = crearPila();

    int max = p.tope;

    for (int i = 0; i < n; ++i) {
        int valor = obtener(p);
        pila1 = push(pila1, valor);
        p = pop(p);
    }

    for (int i = 0; i < max + 1 - n; ++i) {
        int valor = obtener(p);
        pila2 = push(pila2, valor);
        p = pop(p);
    }

    for (int i = 0; i < n; ++i) {
        int valor = obtener(pila1);
        p = push(p, valor);
        pila1 = pop(pila1);
    }

    for (int i = 0; i < max + 1 - n; ++i) {
        int valor = obtener(pila2);
        p = push(p, valor);
        pila2 = pop(pila2);
    }

    return p;
}

Pila clonPila(Pila p) {
    return p;
}

Pila rev(Pila p) {
    Pila pRev = crearPila();
    while (!esVacia(p)) {
        int valor = obtener(p);
        pRev = push(pRev, valor);
        p = pop(p);
    }
    return pRev;
}

Pila eliminaRepetidos(Pila pRep) {
    pRep = rev(pRep);
    Pila targ = crearPila();
    while (!esVacia(pRep)) {
        int valor = obtener(pRep);
        if (esVacia(targ)) {
            targ = push(targ, valor);
        }
        else {
            Pila aux = clonPila(targ);
            int encolarValor = TRUE;
            while (!esVacia(aux)) {
                int valorAux = obtener(aux);
                if (valor == valorAux) encolarValor = FALSE;
                aux = pop(aux);
            }
            if (encolarValor) targ = push(targ, valor);
        }
        pRep = pop(pRep);
    }
    return targ;
}

int main(int argc, char const *argv[])
{
    printf("(a) El contenido de la");

    Pila pila = crearPila();

    printf("\nSe ha creado la pila. Tope= %d ", pila.tope);

    /*agregar elementos a la pila*/
    int i=0;

    do {
        i++;
        if (esVacia(pila)) {
            printf("\nPila vacia.");
        }
        pila = push(pila, i*10);

    } while (i < MAX_PILA);

    if (esLlena(pila)) {
        printf("\nPila llena.");
    }

    printf("\nPila quedó con tope=%d con valor=%d", pila.tope, pila.elementos[pila.tope]);

    pila = duplicarContenido(pila);

    pila.elementos[0] = 30;

    printf("\n(b) Valor en el fondo de la pila: %d", pila.elementos[0]);
    printf("\n(c) El numero de elementos en la pila es: %d", pila.tope + 1);
    printf("\n(d) Elimina de una pila todas las ocurrencias de un elemento dado.");
    pila = eliminaValor(pila, 80);
    printf("\n(e) Intercambia los valor es del tope y el fondo de una pila: ");
    printf("[f: %d, t: %d]", pila.elementos[0], pila.elementos[pila.tope]);
    int aux = pila.elementos[0];
    pila.elementos[0] = pila.elementos[pila.tope];
    pila.elementos[pila.tope] = aux;
    printf(" => [f: %d, t: %d]", pila.elementos[0], pila.elementos[pila.tope]);
    printf("\n(f) Calcula la suma de una pila de enteros sin modificar su contenido: %d", sumarContenido(pila));
    printf("\n(g) Busca el máximo de una pila de números enteros: %d", elMaximo(pila));
    printf("\n(h) Escribe una función reciba una pila de enteros y retorne "
           "dos pila suna con los números pares y otra con los impares.");
    PilaDoble p2 = paresImpares(pila);
    printf("\n(i) Escribe una función: compararPilas(pila1, pila2) la cual devuelve verdadero "
           "si las pilas pila1 y pila2 son iguales, en caso contrario retorna falso");
    Pila p3 = crearPila();
    p3 = pila;
    if (compararPilas(p3, pila)) {
        printf("\nSon iguales");
    }
    else{
        printf("\nSon distintos");
    }
    p3.elementos[10] = 30;
    if (compararPilas(p3, pila)) {
        printf("\nSon iguales");
    }
    else{
        printf("\nSon distintos");
    }
    printf("\n(J) Escribe una función que reciba una Pila y un número entero n. Esta función debe poner los primeros n "
           "elementos de la Pila al final de la misma y retornar esta misma pila con los elementos modificados. "
           "Por ejemplo, si la Pila P es P = {6, 5, 3, 4, 2, 0} y n es 2, debe retornar P= {3, 4, 2, 0, 6, 5}.");
    Pila pila4 = crearPila();
    pila4 = push(pila4, 0);
    pila4 = push(pila4, 2);
    pila4 = push(pila4, 4);
    pila4 = push(pila4, 3);
    pila4 = push(pila4, 5);
    pila4 = push(pila4, 6);
    mostrarDatos(pila4);
    pila4 = ponerLosPrimerosNElementos(pila4, 2);
    mostrarDatos(pila4);

    printf("\n(i)");
    Pila pRep = crearPila();
    pRep = push(pRep, 3);
    pRep = push(pRep, 4);
    pRep = push(pRep, 3);
    pRep = push(pRep, 4);
    pRep = push(pRep, 5);
    pRep = push(pRep, 6);
    pRep = push(pRep, 3);
    mostrarDatos(pRep);
    pRep = eliminaRepetidos(pRep);
    mostrarDatos(pRep);


    printf("\n");
    return 0;
}

