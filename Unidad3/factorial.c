#include <stdio.h>

int fact(int);

int main() {
    int n,f;
    printf("enter a number\t");
    scanf("%d",&n);
    f=fact(n);
    printf("\nFactorial %d\n",f);
}

int fact(int n) {
    if(n==0) {
        return 1;
    } else {
        return n*fact(n-1);
    }
}
/*
3*fact(2);
2*fact(1);
1*fact(0);
n==0 return 1;
*/