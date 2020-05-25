
#include "recarr.h"

/* OPERACIONES RECURSIVAS*/
//agregar elementos no recursiva
void agregarElementos (int arr[],int n) {
    srand(time(NULL));
    for (int i=0; i < n; i++){
        arr[i]=rand()%10+1;
    }
}

//imprimir el arreglo
void imprimirArreglo(int arr[],int start, int len) {
    if(start>=len) { 
        return;
    } else {
    printf("%d ",arr[start]);
    imprimirArreglo(arr,start+1,len);
    }
}

//sumaArreglo
int sumaArreglo( int arr[], int index) {
    if(index<=0) { //if it is -1 then return 0; <=0
        return 0;
    }else {
        return (sumaArreglo(arr,index-1)+arr[index-1]);
    }
}

//ordenarArreglo
void ordenarArreglo(int arr[], int n) {
    if(n<=1) {
        return;
    }else {
        ordenarArreglo(arr, n-1);
    }
    int last = arr[n-1]; 
    int j = n-2; 
    while (j >= 0 && arr[j] > last) { 
        arr[j+1] = arr[j]; 
        j--; 
    } 
    arr[j+1] = last; 
}

//cuenta ocurrencias
int cuentaOcurrencias(int arr [], int index, int elem) {
    if(index==-1) {
        return 0;
    }	
    else if (arr[index]==elem){
        return  (1+cuentaOcurrencias(arr, index-1, elem));
    }   
    else return (cuentaOcurrencias(arr, index-1,elem));
}

//buscar elemento
//caso base de buscar es si lo encontro o si el indice es -1
bool buscarElemento(int arr[], int index, int elem) {
    if (arr[index]==elem) {
        return 1;
    } else{
        if(index==-1) {
            return 0;
        }else{
            return buscarElemento(arr,index-1, elem);
        }
    }
}

//sonIguales
//true si son iguales recorrer todo
//false si no son iguales es que un elemento es distinto
bool esIgual(int arr[], int arr2[], int indice) {
    if(indice==-1) {
        return 1;    
    }else {
        if (arr[indice]!= arr2[indice]) {
            return 0;
        } else {
         return esIgual( arr,  arr2, indice-1);
        }
    }     
}


7:56 PM
int A[] = {1,4,6,7,8,9,0};
	int B[] = {1,4,6,7,8,9,0};

//invertir el arreglo
void reverse(int arr, int index)  
{  
    if(arr<= 0) 
    { 
        return; 
    } 
    reverse(arr[index]==arr[index-1]); */
//}  
  
//eliminar

///////////////////////////////////////////////

