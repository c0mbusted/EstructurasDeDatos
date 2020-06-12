#include <stdlib.h>
#include <stdio.h>


//funcion que dado un numero entero positivo n calcula el numero de fibnacci asociado
int sumofdigits(int num);

int main() {

    int n=543;
    //int result;
    int result= sumofdigits(n);
    printf("suma de digitos de 543: %d",result);
    /*for(int i=0;i<=n;i++) {
        fib=fibonacci(i);
        printf("\n%d\n",fib);

    }*/
    
    return 0;
}

int sumofdigits(int num) {
    if(num==0) { //base condition
        return(0);
    } else {
       return ((num%10)+sumofdigits(num/10));
    }
}