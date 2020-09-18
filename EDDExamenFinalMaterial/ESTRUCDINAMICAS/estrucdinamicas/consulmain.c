#include <stdio.h>
#include "listacons.c"

#define bool  int
#define false 0
#define true 1


//funciones del consultorio

bool nuevoMedico(List *ListDocs,char *nombre) {
    add(ListDocs,createData(nombre),0);
    return true;

}

bool pideConsulta(List *ListDocs, char *nombre, char *nompac){
    if(ListDocs->size==0) {
        return false;

    } else {
        Node *aux= ListDocs->first;
        for(int i=0; i<ListDocs->size;i++) {
            if(strcmp(aux->data->nombre,nombre)==0) { //comparamos nombre del doc
                push(aux->data->pacientes,createDataq(nompac));
                return true;
            }
            aux=aux->next;
        }
    }
return false;
}

char *siguientePaciente(List *ListDocs, char *nomdoc){
    if(ListDocs->size==0) {
        return NULL;

    } else {
        Node *aux= ListDocs->first;
        for(int i=0; i<ListDocs->size;i++) {
            if(strcmp(aux->data->nombre,nomdoc)==0) { 
               return aux->data->pacientes->first->dato->n;
            }
            aux=aux->next;
        }
    }
return NULL;
}


bool atiendeConsulta(List *ListDocs, char *nomdoc){
    if(ListDocs->size==0) {
        return false;

    } else {
        Node *aux= ListDocs->first;
        for(int i=0; i<ListDocs->size;i++) {
            if(strcmp(aux->data->nombre,nomdoc)==0) { 
                pop(aux->data->pacientes);
                return true;
            }
            aux=aux->next;
        }
    }
return false;
}

bool tienePacientes(List *ListDocs, char *nomdoc){
    if(ListDocs->size==0) {
        return false;

    } else {
        Node *aux= ListDocs->first;
        for(int i=0; i<ListDocs->size;i++) {
            if(strcmp(aux->data->nombre,nomdoc)==0) { 
                return  !isEmpty(aux->data->pacientes);
            }
            aux=aux->next;
        }
    }
return false;

}


int main() {

    List *ListDocs=createList();
    
	printf("Se agregan doctores a la cola: \n");
	nuevoMedico(ListDocs,"Dr. Lopez");
    nuevoMedico(ListDocs,"Dra. Polo");
    nuevoMedico(ListDocs,"Dra. Gutierrez");
	
    printList(ListDocs);
    //se valida funciond e pedir consulta
    if (pideConsulta(ListDocs,"Dr. Queso","Leticia")) {
        printf("paciente agregado");

    } else {
        printf("Este doctor no esta en la lista.");
    }

    if (pideConsulta(ListDocs,"Dr. Lopez","Anita")) {
        printf("paciente agregado");

    } else {
        printf("Este doctor no esta en la lista.");
    }

    if(tienePacientes(ListDocs,"Dr. Lopez")){
        printf("tiene pacientes\n");
        printf("El primer paciente de la cola es:", siguientePaciente(ListDocs,"Dr. Lopez"));
        printf("El primer paciente fue atendido.", atiendeConsulta(ListDocs,"Dr. Lopez"));
    }else {
        print("no tiene pacientes");
    }
    
	
	
	freeList(ListDocs);


    return 0;
}

