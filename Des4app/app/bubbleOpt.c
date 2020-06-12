#include <stdbool.h>

long bubbleOpt(int arreglo[], int largo_arreglo);

long bubbleopt(int arreglo[], int largo_arreglo){
	int aux;
	char bandera = 'f';
	int i=0;
	int comparaciones=0;
	while(bandera=='f' && i<n){
		bandera='v';
		for (int k=0; k<n-i; k++){
			comparaciones++;
			if(arreglo[k]>arreglo[k+1]){
				aux=arreglo[k];
				arreglo[k]=arreglo[k+1];
				arreglo[k+1]=aux;
				bandera='f';
			}
		}
		i=i+1;
	}
	return comparaciones;
}