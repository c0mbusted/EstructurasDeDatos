#include <stdio.h>
#include <stdlib.h>

void modificar(int *old, int nuevo) {
    *old=nuevo;
    
}
int main() {
    int numero;
    int numero2;
    printf("pon tun numerito");
    scanf("%d\n",&numero);

    modificar(numero2, numero);
    printf("\n%d",numero2);
    return 0;

}