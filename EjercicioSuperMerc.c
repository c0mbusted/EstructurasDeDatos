# include <stdio.h>
# include <stdlib.h>
#include<math.h>


typedef struct compra {
    char rutcli [9];
    int valorCompra;
    int cantProd;
    float puntos;
} Compra;


Compra ingresarCompra();
void generarTicket(Compra compI);


void main() {

    Compra c= ingresarCompra();
    generarTicket(c);
}


///funciones

Compra ingresarCompra() {
    Compra compr = {"",0,0,0.0};

    printf("Rut cliente: ");
    scanf("%s",compr.rutcli);

   
    int i=0, pre=0,cant=0;
    do{
        i++;
        printf("\n Precio producto %d",+i);
        scanf("%d",&pre);
        printf("Cantidad comprada producto %d", +i);
        scanf("%d", &cant);
        compr.valorCompra = compr.valorCompra + pre*cant;

    } while (pre>0 && cant>0);

compr.cantProd = i-1;

compr.puntos= round((float)compr.valorCompra/10);

return compr;
    
}


void generarTicket(Compra compI) {
    printf("\n\n**SUPERMERCADO SUPERAHORRO**");
    printf("\n\nRut cliente: %s", compI.rutcli);
    printf("\n\nValor total de la compra : %d",compI.valorCompra);
    printf("\n\nCantidad total de productos en su compra %d",compI.cantProd);
    printf("\n\nPuntos obtenidos: %0.lf",compI.puntos);
    printf("\n\n**gracias por su visita*");


}

