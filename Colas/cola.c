/* -*- Mode: C; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2; -*- */
/*
 * cola.c
 * This file is part of ED-2014-01-UNAB
 *
 * Copyright (C) 2014 - Carlos Contreras Bolton
 *
 * ED-2014-01-UNAB is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * ED-2014-01-UNAB is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ED-2014-01-UNAB. If not, see <http://www.gnu.org/licenses/>.
 */

#include "cola.h"

/**
 * Función que permite crear una nueva cola vacía.
 *
 * @return nuevo: dirección del nodo inicio de la cola creada.
 *
 */

Cola *creaCola()
{
  Cola *nueva;

  if(nueva = (Cola *) malloc(sizeof(Cola))) // Pide memoria para la Cola
    {
      nueva->tamano = 0; // Cola vacía
      nueva->inicio = nueva->fin = NULL; // Inicio y Fin apuntan a NULL
    }
  return nueva;
}

/**
 * Función que permite eliminar una Cola.
 *
 * @param c: puntero a la cola
 *
 */

void destruirCola(Cola *c)
{
  Nodo *aux;

  while(c->inicio != NULL)
    {
      aux = c->inicio;
      c->inicio = c->inicio->siguiente;
      free(aux->datos);
      free(aux);
    }
	free(c);
}

/**
 * Función que crea un nodo y lo inicializa con sus datos y la dirección del
 * siguiente nodo.
 *
 * @param dato: puntero a los datos
 * @param ptro: puntero al siguiente nodo
 * @return ptro: la dirección del nuevo nodo creado.
 *
 */

Nodo *crearNodo(Info *dato, Nodo *ptro)
{
  Nodo *nuevo;
  if(nuevo = (Nodo *) malloc(sizeof(Nodo))) // Pide memoria para el nodo
    {
      nuevo->datos = dato;
      nuevo->siguiente = ptro;
    }
  return nuevo;
}

/**
 * Función que retorna el primer nodo de la cola
 *
 * @param c: puntero a la cola
 * @return tope: dirección del primer nodo de la cola
 *
 */

Nodo *primero(Cola *c)
{
  return c->inicio;
}

/**
 * Función que retorna el último nodo de la cola
 *
 * @param c: puntero a la cola
 * @return tope: dirección del último nodo de la cola
 *
 */

Nodo *ultimo(Cola *c)
{
  return c->fin;
}

/**
 * Función que permite saber si una cola está vacía o no
 *
 * @param c: puntero a la cola
 * @return bool: true en caso de ser vacía, false caso contrario
 *
 */

bool vacia(Cola *c)
{
  return (c->inicio == NULL) ? true : false;
}

/**
 * Función que ingresa la información
 *
 * @param dato1: dato a guardar en Info
 * @param pdato: información a guardar en la cola
 *
 */

void ingresar(Info **pdato, int dato1)
{
  if(*pdato = (Info *) malloc(sizeof(Info)))
    {
      /* Se almacena la información en Info */
      (*pdato)->dato1 = dato1;
      /* pdato->dato2 = dato2; */
      /* pdato->dato3 = dato3; */
    }
  else
    {
      printf("problemas en el push\n");
      exit(0);
    }
}

/**
 * Función que inserta un nodo a cola.
 *
 * @param c: puntero a la Cola
 * @param info: información a guardar en la cola
 *
 * @return true: si la inserción tuvo éxito, false: en caso contrario.
 *
 */

bool push(Cola *c, int info)
{
  Info *pdato;
  Nodo *aux;
  ingresar(&pdato, info);
  // Se crea un nodo con datos y apunta a NULL
  if(aux = crearNodo(pdato, NULL)) //además, se almacena en aux
    {
      if(vacia(c))
        c->inicio = aux;
      else
        c->fin->siguiente = aux;
      c->fin = aux;
      c->tamano++;
      return true;
    }
  else
    return false;
}

/**
 * Función que elimina un nodo de la cola
 *
 * @param c: puntero a la cola
 * @return dato: retorna el dato de Info.
 *
 */

Info *pop(Cola *c)
{
  Nodo *aux;
  Info *dato;
  aux = c->inicio; //se guarda el nodo a eliminar (el primero) en un aux
  dato = aux->datos; //sus datos también
  c->inicio = aux->siguiente;
  c->tamano--;
  if(vacia(c))
    c->fin = NULL;
  free(aux->datos);
  free(aux);

  return dato;
}
