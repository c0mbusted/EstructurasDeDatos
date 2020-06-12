#include <stdio.h>
#include <stdlib.h>

void swap(float *a,float *b){
    float aux1, aux2;
    aux1=*a;
    aux2=*b;
    *b=aux1;
    *a=aux2;
}


int main () {
    float num1;
    float num2;

    printf("Ingrese un numero y luego el otro: \t");
    scanf("%f",&num1);
    scanf("%f",&num2);

    swap(&num1,&num2);
    printf("%f    %f",num1,num2);
    
    
    return 0;
}