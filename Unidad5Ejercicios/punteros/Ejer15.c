#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//agregar elementos random al arreglo dinamico de notas
void agregarElementos (int *notas) {
    srand(time(NULL));
    for (int i=0; i < 50; i++){
        *notas=rand()%7;
    }
}

int main() {
    int *notas = (int*) malloc(50 * sizeof(int));
    agregarElementos(notas);
    for (int) {

    }
    printf("%d",*notas);

    int examenes;
    printf("Ingrese la cantidad de examenes rendidos: ");
    scanf("%d",examenes);

    
    
    return 0;

}