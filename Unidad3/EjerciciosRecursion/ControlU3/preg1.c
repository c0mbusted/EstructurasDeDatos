
#include "preg1.h"

void agregarElementos (int arr[],int n) {
    srand(time(NULL));
    for (int i=0; i < n; i++){
        arr[i]=rand()%10+1;
    }
}

void imprimirArreglo(int arr[],int start, int len) {
    if(start>=len) { 
        return;
    } else {
    printf("%d ",arr[start]);
    imprimirArreglo(arr,start+1,len);
    }
}
//Si A = {1, 2, 3, 4, 5, 6, 7} y C = 8, 
//entonces, el resultado es 2 porque (6+7=13 > 8).

//sumaArreglo
int sumaArreglo( int arr[], int index) {
    if(index<=0) { //if it is -1 then return 0; <=0
        return 0;
    }else {
        return (sumaArreglo(arr,index-1)+arr[index-1]);
    }
}
//funcion
int funcion( int arr[], int index, int cont, int numero) {
    if(sumaArreglo(arr,index)>numero){ //if it is -1 then return 0; <=0
        return 0;
    }else if (sumaArreglo(arr,index-1)+arr[index-1]<numero){
        cont++;
        return cont;        
    } else {
        return (sumaArreglo(arr,index-1)+arr[index-1]);
    }
}



/*int resultado(int arr, int h,int contador, int numero) {
    int index;
    if(arr[9]+arr[index-2]>numero) {


    }

}*/
//1 2 3 4 5 6 7


/*int cuentaOcurrencias(int arr [], int index, int numero) {
    if(index==-1) {
        return 0;
    }	
    else if (sumaArreglo(arr,index)>numero){
        return  (1+cuentaOcurrencias(arr, index-1,numero));
    }   
    else return (cuentaOcurrencias(arr, index-1,numero));
}

int minimaCantidad(int arr[], int index, int numero) {
    if(sumaArreglo(arr,index)>numero) {
        return;
    }else if (sumaArreglo(arr,index)<numero){
        return (sumaArreglo(arr,index-1)+arr[index-1]);   
    } else {
        return minimaCantidad(arr,index,numero);
    }

}*/

