#include "arr.h"

/* OPERACIONES o FUNCIONES del TAD */
void agregarElementos (int arr[],int n) {
    srand(time(NULL));
    for (int i=0; i < n; i++){
        arr[i]=rand()%10+1;
    }
}

void mostrar (int arr[],int n) {
    for (int i=0; i < n; i++){
    printf("Elemento numero %d = %d", i+1, arr[i]);
    printf("\n");
    }
}

int buscar(int arr[], int value, int n) {
    int pos=-1;
    for(int i=0;i<n;i++) {
        if (arr[i]==value) {
            pos=i;
            break;
        }

    }
    return pos;
}

int eliminar(int arr[],int elim,int n) {
    int found = buscar(arr,elim, n);
    if (found==-1) {
        return 0;
    }else {
        arr[found]=0;
        return 1;
    }
}