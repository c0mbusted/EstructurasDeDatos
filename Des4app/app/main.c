#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "selection.h"
#include "bubble.h"
#include "insertion.h"
#define MAX_NUMBER 100000
#define MIN_NUMBER 0
#define MAX_SIZE 10

void test_de_ordenamiento(int algoritmo, int largo);
void printArray(int arr[], int size);
void agregarElementos (int arr[],int n);
void escribirArchivo(char filename[],int numelement,long compaleatoria,long mayormenor, long menormayor);

//main
int main()
{
    srand(time(NULL));

    int opcion = 0;

    while (1) {
        int algoritmo = 0;
        int largo = 0;
        int nuevo_ordenamiento = 0;

        while (!((algoritmo >= 1 && algoritmo <= 3) || algoritmo==9))
        {
            printf("\e[1;1H\e[2J"); // limpia la pantalla :)
            printf("\n\n******* MENU *******\n\n");
            printf("1. ordenamiento de burbuja\n");
            printf("2. ordenamiento de inserción\n");
            printf("3. ordenamiento de selección\n");
            printf("...\n");
            printf("9. Salir\n\n");
            printf("Ingrese opción: ");
            scanf("%d", &algoritmo);
        }
        if (algoritmo == 9)
            break;

        while (!((largo >= 4 && largo <= 6) || largo==9)) {
            printf("\e[1;1H\e[2J"); // limpia la pantalla :)
            printf("\n\n******* MENU *******\n\n");
            printf("4. 10.000 elementos\n");
            printf("5. 50.000 elementos\n");
            printf("6. 90.000 elementos\n");
            printf("...\n");
            printf("9. Salir\n\n");
            printf("Ingrese opción: ");
            scanf("%d", &largo);
        }
        if (largo == 9)
            break;

        int largos[] = {10000, 50000, 90000};
        test_de_ordenamiento(algoritmo, largos[largo-4]);
    }

    return 0;
}

//funcion para imprimir arreglo
void printArray(int arr[], int size)
{
    int i;
    printf("{ ");
    for (i=0; i < size; i++)
        printf("%d, ",arr[i]);
    printf("\b\b }\n");
}
//funcion para agregar elementos
void agregarElementos (int arr[],int n) {
    int i=0;
    while(i<n) {
        int element=rand()%(MAX_NUMBER+1-MIN_NUMBER);
        int repetido=0;
        for(int j=0;j<i;j++) {
            //evita elementos repetidos
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
}
//funcion para escribir archivos de salida
void escribirArchivo(char filename[],int numelement,long compaleatoria,long mayormenor, long menormayor){
    FILE *salida;
    salida=fopen(filename, "w+");
    fprintf(salida, "numElement: %d\n",numelement);
    fprintf(salida, "numCompElemAleat: %ld\n",compaleatoria);
    fprintf(salida, "numCompMenorMayor: %ld\n",mayormenor);
    fprintf(salida, "numCompMayorMenor: %ld\n",menormayor);
    fclose(salida);
}

//funcion para selecionar el tipo de ordenamiento
void test_de_ordenamiento(int algoritmo, int largo) {
    int arr[largo];
    printf("Arreglo con %d elementos\n", largo);

    printf("llenando arreglo\n");
    agregarElementos(arr, largo);
    long comparDesor;
    long comparAsc;
    long comparDesc;
    char filename[60] = "";

    // switch para elegir la opcion del algoritmo
    switch (algoritmo) {
    case 1:
        printf("ejecutando ordenamiento burbuja asc en arreglo aleatorio\n");
        comparDesor = bubbleSort(arr, largo);
        printf("ejecutando ordenamiento burbuja asc en arreglo asc\n");
        comparAsc = bubbleSort(arr, largo);
        printf("ejecutando ordenamiento burbuja desc en arreglo asc\n");
        bubbleSortDesc(arr, largo);
        printf("ejecutando ordenamiento burbuja asc en arreglo desc\n");
        comparDesc = bubbleSort(arr, largo);
        sprintf(filename, "burbuja_%d.txt", largo);
        escribirArchivo(filename, largo, comparDesor, comparAsc, comparDesc);
        break;
    case 2:
        printf("ejecutando ordenamiento insersion asc en arreglo aleatorio\n");
        comparDesor = insertionSort(arr, largo);
        printf("ejecutando ordenamiento insersion asc en arreglo asc\n");
        comparAsc = insertionSort(arr, largo);
        printf("ejecutando ordenamiento insersion desc en arreglo asc\n");
        insertionSortDesc(arr, largo);
        printf("ejecutando ordenamiento insersion asc en arreglo desc\n");
        comparDesc = insertionSort(arr, largo);
        sprintf(filename, "insercion_%d.txt", largo);
        escribirArchivo(filename, largo, comparDesor, comparAsc, comparDesc);
        break;
    case 3:
    printf("ejecutando ordenamiento seleccion asc en arreglo aleatorio\n");
        comparDesor = selectionSort(arr, largo);
        printf("ejecutando ordenamiento seleccion asc en arreglo asc\n");
        comparAsc = selectionSort(arr, largo);
        printf("ejecutando ordenamiento seleccion desc en arreglo asc\n");
        selectionSortDesc(arr, largo);
        printf("ejecutando ordenamiento seleccion asc en arreglo desc\n");
        comparDesc = selectionSort(arr, largo);
        sprintf(filename, "seleccion_%d.txt", largo);
        escribirArchivo(filename, largo, comparDesor, comparAsc, comparDesc);
        break;
    }

}
