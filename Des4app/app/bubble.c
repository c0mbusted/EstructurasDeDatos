#include "bubble.h"

//se implementa funcion bubble sort
long bubbleSort(int arreglo[], int largo_arreglo) {
    long comparaciones=0;//contador de comparaciones
    for (int i=0; i < largo_arreglo; i++) {
        for(int j=0; j < largo_arreglo; j++){
            comparaciones++;
            if(arreglo[i] < arreglo[j]) {
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
    return comparaciones;
}

//funcion para ordenar arreglo de mayor a menor y 
//con este arreglo se hace la prueba 2
long bubbleSortDesc(int arreglo[], int largo_arreglo) {
    long comparaciones=0;
    for (int i=0; i < largo_arreglo; i++) {
        for(int j=0; j < largo_arreglo; j++){
            comparaciones++;
            if(arreglo[i] > arreglo[j]) {
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
    }
    return comparaciones;
}
