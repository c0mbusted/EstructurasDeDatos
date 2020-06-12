#include "insertion.h"

//se implementa la funcion de insertion sort
long insertionSort(int arreglo[], int largo) {
    int i, temp, j;
    long comparaciones=0;//contador de comparaciones

    for (i = 1; i < largo; i++) {
        temp = arreglo[i];
        j = i - 1;

        while (j >= 0 && arreglo[j] > temp) {
            comparaciones++;
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = temp;
    }
    return comparaciones;
}

//funcion para ordenar arreglo de mayor a menor y 
//con este arreglo se hace la prueba 2

long insertionSortDesc(int arreglo[], int largo) {
    int i, temp, j;
    long comparaciones=0;

    for (i = 1; i < largo; i++) {
        temp = arreglo[i];
        j = i - 1;

        while (j >= 0 && arreglo[j] < temp) {
            comparaciones++;
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = temp;
    }
    return comparaciones;
}