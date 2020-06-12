#include <stdio.h>

int sum(int);

int main() {
    int n,s;
    printf("enter a number\t");
    scanf("%d",&n);
    s=sum(n);
    printf("\nSum %d\n",s);
}

int sum(int n) {
    if(n==1) {
        return 1;
    } else {
        return n+sum(n-1);
    }
}

/*
4+sum(3)
3+sum(2)
2+sum(1)
base case 
4+3+2+1=10
*/