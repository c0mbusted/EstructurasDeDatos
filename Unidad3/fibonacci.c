#include <stdlib.h>
#include <stdio.h>


//funcion que dado un numero entero positivo n calcula el numero de fibnacci asociado
int fibonacci (int n);

int main() {

    int n=10;
    int fib= fibonacci(n);
    for(int i=0;i<=n;i++) {
        fib=fibonacci(i);
        printf("\n%d\n",fib);

    }
    
    return 0;
}

int fibonacci (int n) {
    if(n<=1) { //base condition
        return(n);
    } else {
       return fibonacci(n-1)+fibonacci(n-2);
    }
}



