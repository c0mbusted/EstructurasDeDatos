#include <stdio.h>
#include <stdlib.h>
#define alength 100

int main() {
    int i;
    int arrintegers[100];
    /*for(i =0; i<alength;i++) {
        arrintegers[i]=i;
        printf("%d\n",arrintegers[i]);
    }*/

//orden descendente
    for(i =alength; i>=1;i--) {
        arrintegers[i]=i;
        printf("%d\n",arrintegers[i]);
    }
    

    return 0;
}