#include <stdio.h>
#include <stdlib.h>

void conPunteros(int num1, int num2, int *resultado) {
    *resultado= num1+num2;
    
}

int sinPunteros(int num1,int num2) {
    int resultado= num1+num2;

    return resultado;

}

int main() {
    int numero1,numero2,resultadosinP,resultadoconP;
   
    printf("pon tu numerito 1\t");
    scanf("%d",&numero1);
    printf("pon tun numerito 2\t");
    scanf("%d",&numero2);


    conPunteros(numero1,numero2,&resultadoconP);
    resultadosinP= sinPunteros(numero1,numero2);
    printf("Este es con punteros %d y este es sin punteros %d: ",resultadoconP,resultadosinP);
    
    return 0;

}