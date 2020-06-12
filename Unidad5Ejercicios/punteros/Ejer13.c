#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void mult_por_2(int *ptr) {
    for(int i=0; i<10;i++) {
        ptr[i]=ptr[i] *2;

    }

}
int main() {
    
    int vector[10]={1,2,3,4,4,7,8,9,5,4};
    for (int i=0; i<10;i++) {
        printf("%d- ",&vector[i]);
        printf("%d- ",vector[i]);
    }
    
    printf("llamamos la funcion multiplicar por dos: ");
    mult_por_2(vector);
    for(int j=0;j<10; j++) {

    printf("%d- ", vector[j]);


    }
    
    
    return 0;
}