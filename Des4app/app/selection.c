#include "selection.h"

//se implementa la funcion de selections sort
long selectionSort(int arreglo[], int largo) {
    long comparaciones = 0;//contador de comparaciones
    int i, j, primer_elem;
    for (i = 0; i < largo-1; i++) {
        primer_elem = i;
        for (j = i+1; j < largo; j++) {
            comparaciones++;
            if (arreglo[j] < arreglo[primer_elem])
                primer_elem = j;
        }
        // Intercambiar el elemento minimo con el primer elemento
        int temp = arreglo[primer_elem];
        arreglo[primer_elem] = arreglo[i];
        arreglo[i] = temp;
    }
    return comparaciones;
}

//funcion para ordenar arreglo de mayor a menor y
//con este arreglo se hace la prueba 2
long selectionSortDesc(int arreglo[], int largo) {
    long comparaciones = 0;
    int i, j, primer_elem;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < largo-1; i++) {
        // Find the minimum element in unsorted array
        primer_elem = i;
        for (j = i+1; j < largo; j++) {
            comparaciones++;
            if (arreglo[j] > arreglo[primer_elem])
                primer_elem = j;
        }
        // Swap the found minimum element with the first element
        int temp = arreglo[primer_elem];
        arreglo[primer_elem] = arreglo[i];
        arreglo[i] = temp;
    }
    return comparaciones;
}
