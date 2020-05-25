#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define bool int

#define SIZE 30

void agregarElementos (int arr[],int n);

void ordenarArreglo(int arr[], int n);

int sumaArreglo( int arr[], int index);

void imprimirArreglo(int arr[],int start, int len);

int cuentaOcurrencias(int arr [], int index, int elem);

bool esIgual(int arr[], int arr2[], int indice);

int buscarElemento(int arr[], int index, int elem);

void insertar(int A[], int indice, int numero);

void invertirArreglo(int arr[], int index, int length);

//void reverse(int arr[], int leftIndex, int rightIndex);
