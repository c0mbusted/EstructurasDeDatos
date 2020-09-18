
#include <stdio.h>
#include <stdlib.h>

typedef struct info {
    int clave;
} Info;

typedef struct nodoArbol {
    Info *info;
    struct nodoArbol *left;
    struct nodoArbol *right;
}Nodo;

typedef struct arb {
    Nodo *raiz;
}Arbol;


/*Prototipos*/
void preorden (Nodo *aux);
void inorden (Nodo *aux);
void postorden(Nodo *aux);
void crearArbol(Arbol *a);
Info *crearInfo(int pval);
Nodo *crearNodo(int val);
Nodo *insertar(Nodo *aux, int val);
Nodo *buscar(Nodo *aux, int val);
Nodo *eliminar(Nodo *aux, int val);
Nodo *buscarSucesor(Nodo *aux);





//FUNCIONES
void preorden (Nodo *aux) {
    if(aux!=NULL) {
        printf("%d  ",aux->info->clave);
        preorden(aux->left);
        preorden(aux->right);
    }
}

void inorden (Nodo *aux) {
    if(aux!=NULL) {
        inorden(aux->left);
        printf("%d  ",aux->info->clave);
        inorden(aux->right);
    }
}

void postorden(Nodo *aux) {
    if(aux !=NULL) {
        postorden(aux->left);
        postorden(aux->right);
        printf("%d  ", aux->info->clave);
    }
}


void crearArbol(Arbol *a) {
    if(a=(Arbol*)malloc(sizeof(Arbol))) {
        a->raiz=NULL;
    }else {
        printf("MEMORIA ARBOL NO ASIGNADA"); 
    }
}



Info *crearInfo(int pval){
  Info *newInfo;
  if (newInfo=(Info*) malloc(sizeof(Info))){
    newInfo->clave = pval;
  }else{
    printf("MEMORIA INFO NO ASIGNADA");
  }
  return newInfo;
}


Nodo *crearNodo(int val) {
    Info *pinfo;
    pinfo=crearInfo(val);
    Nodo *nod;
    if (nod=(Nodo *) malloc(sizeof(Nodo))) {
        nod->info=pinfo;
        nod->left=nod->right=NULL;
    }else {
        printf("MEMORIA DEL NODO NO ASIGNADA");
    }
    return nod;
}

Nodo *insertar(Nodo *aux, int val) {
    if(aux==NULL)
        return crearNodo(val);
    else
        if (val<aux->info->clave)
        aux->left=insertar(aux->left,val);
    else
        if(val>aux->info->clave)
        aux->right=insertar(aux->right,val);
    return aux;        
}

Nodo *buscar(Nodo *aux, int val) {
    if (aux==NULL)
        return NULL;
    else
        if(val <aux->info->clave)
            return buscar(aux->left,val);
        else
            if(val>aux->info->clave)
                return buscar(aux->right,val);
            else
                return aux;  
}

Nodo *eliminar(Nodo *aux, int val) {
    if(aux==NULL)
        printf("Elemento no encontrado\n");
    else
        if(val< aux->info->clave)
            aux->left=eliminar (aux->left,val);
        else
            if(val> aux->info->clave)
                aux ->right = eliminar(aux->right,val);
            else {
                Nodo *temp;
                if(aux->right !=NULL && aux->left !=NULL) {
                    temp=buscarSucesor(aux->right);
                    aux->info->clave=temp->info->clave;
                    aux->right=eliminar(aux->right,temp->info->clave);
               
                }else {
                    temp=aux;
                    if(aux->left==NULL)
                        aux=aux->right;
                    else
                        if(aux->right==NULL)
                            aux=aux->left;
                    free(temp);
                }
            }
    return aux;
}

Nodo *buscarSucesor(Nodo *aux) {
    if(aux==NULL)
        return NULL;
    if(aux->left==NULL)
        return aux;
    else
        return buscarSucesor(aux->left);
}
