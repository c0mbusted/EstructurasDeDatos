/* -*- Mode: C; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2; -*- */
/*
 * cola.h
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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _COLA_H_
#define _COLA_H_

/**
 * Estructura que guarda la información.
 *
 */
typedef struct info {
  int dato1;
  /* int dato2; */
}Info;

/**
 * Estructura que guarda el nodo, un puntero que apunta a la Info,
 * y otro que apunta al nodo siguiente
 *
 */
typedef struct nodo {
  Info *datos;
  struct nodo *siguiente;
}Nodo;

/**
 * Estructura que guarda la Cola, con un puntero que apunta al inicio
 * y al fin de ésta. Además, almacena el tamaño de la Cola.
 *
 */
typedef struct cola {
  Nodo *inicio;
  Nodo *fin;
  int tamano;
}Cola;

/* Funciones de las operaciones básicas */
Cola *creaCola();
void destruirCola(Cola *c);
Nodo *crearNodo(Info *dato, Nodo *ptro);
Nodo *primero(Cola *c);
Nodo *ultimo(Cola *c);
bool vacia(Cola *c);
void ingresar(Info **pdato, int dato1);
bool push(Cola *c, int info);
Info *pop(Cola *c);

#endif /* _COLA_H_ */
