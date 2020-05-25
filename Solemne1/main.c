///CASO 1 ////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "bday.h"
#define MAX_ARRAY 1000

typedef struct amigo {
    char telefono[9];
    char nombre[20];
    Fecha fecha;
    int Amigos[MAX_ARRAY];
} Amigo;

typedef struct fecha {
	int dd;
    int mm;
    int yy;
    //int fecha[30];
    //char mes[12];
}Fecha;

void ingresarAmigo(char tel, char nom, int dd, int mm, int yy, int arr[]);
void validarFecha(int dd, int mm, int yy);
void mostrarcuantoscumplen(int arr[], int dd, int mm );
void MesconNombre(int d, int m);
int mostrarCantidad(int arr[], int dd, int mm );

int main () {
    int Amigos[MAX_ARRAY]; 
    int dd,mm,yy;
    char telf;
    int fecha[30];
    char nom;


    ingresarAmigo(telf,nom,dd, mm, yy, fecha);

    //printf();

    return 0;
    
}


/////////FUNCIONES///////////
void ingresarAmigo(char tel, char nom, int dd, int mm, int yy, int arr[]) {
    printf("Ingrese el telefono del amigo:");
    scanf("%d",tel);
    printf("Ingrese el nombre del amigo:");
    scanf("%d",nom);

    printf("Ingrese la fecha de cumpleaños en el formato: (DD/MM/YYYY) ");
    scanf("%d/%d/%d",dd,mm,yy);

    printf("La fecha es %d/%d/%d", dd,mm,yy);
}
//================================================
void validarFecha(int dd, int mm, int yy) {
    if(yy>=1900 && yy<=9999)
    { 
        if(mm>=1 && mm<=12)
        {
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                printf("Fecha es valida.\n");
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                printf("Fecha es valida.\n");
            else if((dd>=1 && dd<=28) && (mm==2))
                printf("Fecha es valida.\n");
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                printf("Fecha es valida.\n");
            else
                printf("Fecha no valida!.\n");
        }
        else
        {
            printf("Mes no valido!.\n");
        }
    }
    else
    {
        printf("Año no valido!.\n");
    }
}
//==============================================================
void MesconNombre(int d, int m) {
    printf("Ingrese el dia de la fecha de cumpleaños:\t");
    scanf("%d", d);
    printf("Ingrese el mes de la fecha de cumpleaños:\t");
    scanf("%d", m);
     if (m==1) {
        printf("Cumple en el %d de Enero.", d);
     } else if (m==2){
         printf("Cumple en el %d de Febrero.", d);
     } else if (m==3){
         printf("Cumple en el %d de Marzo.", d);
     }
     else if (m==4){
         printf("Cumple en el %d de Abril.", d);
     }
     else if (m==5) {
         printf("Cumple en el %d de Mayo.", d);
     }
     else if (m==6){
         printf("Cumple en el %d de Junio.", d);
     }
     else if (m==7){
        printf("Cumple en el %d de Julio.", d);

     }
     else if (m==8){
        printf("Cumple en el %d de Agosto.", d);
     }
     else if (m==9){
        printf("Cumple en el %d de Septiembre.", d);
     }
     else if (m==10){
        printf("Cumple en el %d de Octubre.", d);
     }
     else if (m==11){
        printf("Cumple en el %d de Noviembre.", d);
     }else{
        printf("Cumple en el %d de Diciembre.", d);

     }

}
//==========================================================
int mostrarCantidad(int arr[], int dd, int mm ) {
    int cont=0;
     for(int i=0;i<MAX_ARRAY;i++) {
        if (arr[i]==dd && arr[i]==mm) {
            cont= cont+1;
            printf("Hay %d amigos que cumplen en el dia y mes ingresados",cont);
        }
    }
    return cont;
}
//==============================================================

////////////////////////////////////////////////////////////
