#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "selection.h"
#include "bubble.h"
#include "insertion.h"
#define MAX_NUMBER 100000
#define MIN_NUMBER 0
#define MAX_SIZE 90000


void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++) 
        printf("%d ",arr[i]);   
} 

long agregarElementos (int arr[],int n) {
    int i=0;
    long cont=0;
    while(i<n) {
        int element=rand()%(MAX_NUMBER+1-MIN_NUMBER);
        int repetido=0;
        for(int j=0;j<i;j++) {
            cont++;
            if(arr[j]==element){
                repetido=1;
                break;
            }
        }
        if(repetido==0) {
            arr[i]=element;
            i++;
        }  
    }
    return cont;
}

void escribirArchivo(char filename[],int numelement,long compaleatoria,long mayormenor, long menormayor){
    FILE *salida;
    salida=fopen(filename, "w+");
    fprintf(salida, "numElement: %d\n",numelement);
    fprintf(salida, "numCompElemAleat: %ld\n",compaleatoria);
    fprintf(salida, "numCompMenorMayor: %ld\n",mayormenor);
    fprintf(salida, "numCompMayorMenor: %ld\n",menormayor);
    fclose(salida);
}


int main()  
{  
    srand(time(NULL));
    int n= MAX_SIZE;
    
 
    //Insertion
    int arr[n]; 
    int arrI[n];
    long compAleatoria= agregarElementos(arr,n);
    long compAleatoriaI= agregarElementos(arrI,n);
    long compMenorMayor= insertionSort(arr,n,0); 
    long compMayorMenor= insertionSort(arrI,n,1);
    escribirArchivo("insertion.txt",n,compAleatoria,compMenorMayor,compMayorMenor);

    //Selection
    int arr1[n];
    int arrS[n];
    long compAleatoria1= agregarElementos(arr1,n);
    long compAleatoriaS= agregarElementos(arrS,n);
    long compMenorMayor1= selectionSort(arr1,n,0); 
    long compMayorMenor1= selectionSort(arrS,n,1);
    escribirArchivo("selection.txt",n,compAleatoria1,compMenorMayor1,compMayorMenor1);

    //bubble 
    int arr2[n];
    int arrB[n];
    long compAleatoria2= agregarElementos(arr2,n);
    long compAleatoriaB= agregarElementos(arrB,n);
    long compMenorMayor2= bubbleSort(arr2,n,0); 
    long compMayorMenor2= bubbleSort(arrB,n,1); 
    escribirArchivo("bubble.txt",n,compAleatoria2,compMenorMayor2,compMayorMenor2);

    //int n=sizeof(arr)/sizeof(arr[0]); 
    //selectionSort(arr,n); 
    //bubbleSort(arr, n);
    
   // printf("Sorted Array: \n");
   // printArray(arr,n);
    
    
    
  
    return 0;  
}  
