#include <stdlib.h>
#include <stdio.h>


//funcion que dado un numero entero positivo n calcula el numero de fibnacci asociado
int potencia(int num,int exp);

int main() {

    int n=5;
    int e=5;
    int total= potencia(n,e);
    printf("potencia: %d",total);
    /*for(int i=0;i<=n;i++) {
        fib=fibonacci(i);
        printf("\n%d\n",fib);

    }*/
    
    return 0;
}

int potencia (int num, int exp) {
    if(exp<=0) { //base condition
        return(1);
    } else {
       return num*potencia(num,exp-1);
    }
}

/*5*potencia(5,4)
625*potencia(5,3)
125*potencia(5,2)
25*potencia(5,1)
5*potencia(5,0)
1*/
