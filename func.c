/**********************************************************************
main del primer proyecto de:
Algoritmos y Programacion II
Por:
Diego Peña
Luis Enrique Salazar
***********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "lib.h"

lista crearLista(){
    lista newl;
    newl.first = newl.last = NULL;
    return newl;
}

node* xor(node* n1, node* n2){
    //uintptr_t para evitar la posibilidad de perder los punteros al castear
    return (node*)((uintptr_t)n1^(uintptr_t)n2);
}

void inicializarLista(lista *l){
    node *aux = NULL, *ant = NULL, *act = l->first;

    while(act){
        aux=act;
        act= xor(ant, act->point); //LLama xor
        ant = aux;
        free(aux);
    }
}

int esVacia(lista l){
    if(l.first)
        return 0;
    return 1;
}

int insertarPrincipio(lista *l, int val){
    node *newl=(node*)malloc(sizeof(node));
    if(!newl)
        return 0;

    newl->val = val;
    newl->point = l->first;
    l->first=newl;
    if(newl->point);
        newl->point->point = xor(newl->point->point ,l->first); //Llama xor
    return 1;
}

int insertarFinal(lista *l, int val){
    node *newl=(node*)malloc(sizeof(node));
    if(!newl)
        return 0;

    newl->val = val;
    newl->point = l->last;
    l->last=newl;
    if(newl->point);
        newl->point->point = xor(newl->point->point ,l->last); //llama xor
    return 1;
}

int insertarOrdenado(lista *l, int val){
    node *newl=(node*)malloc(sizeof(node)), *ant, *aux, *act = l->first;

    if(!newl)
        return 0;

    while(act && act->val<val){
        aux=act;
        act=xor(ant,act->point); //llama xor
        ant=aux;
    }

    newl->val = val;
    newl->point = xor(ant,act); //llaman xor
    aux = xor(ant->point, act); //actualiza nodo anterior
    ant->point = xor(aux,newl);
    aux = xor(ant, act->point); //actualiza nodo posterior
    act->point= xor(aux, newl);
    return 1;
}

int quitarInicio(lista *l){
    node *aux;
    int val = l->first->val;

    aux = l->first;
    l->first = l->first->point;
    free(aux);
    aux = xor(aux,l->first->point); //llaman xor
    l->first->point = aux;
    return val;
}

int quitarFinal(lista *l){
    node *aux;
    int val = l->last->val;

    aux = l->last;
    l->last = l->last->point;
    free(aux);
    aux = xor(aux,l->last->point); //llaman xor
    l->last->point = aux;
    return val;
}

int buscar(lista l, int val){
    node *aux, *ant, *act = l.first;
    while(act && act->val!= val){
        aux = act;
        act = xor(ant, act->point); //llaman xor
        ant = aux;
    }
     if (!act)
        return 0;
    return 1;
}

int sacarPrimeraOcurrencia(lista *l, int val){
    node *aux, *aux2, *ant, *act = l->first;

    while(act && act->val != val){
        aux = act;
        act = xor(ant, act->point); //llaman xor
        ant = aux;
    }
    if(!act)
        return 0;

    aux = act;
    act = xor(ant, aux->point);   //reasignar apuntador posterior
    aux2 = xor(aux,act->point);
    act->point = xor(ant,aux2);
    aux2 = xor(aux,ant->point);    //reasignar apuntador anterior
    ant->point = xor(act,aux2);
    free(aux);
    return 1;
}

void listarInicioFinal(lista l){
    node *aux, *ant, *act = l.first;
    while(act){
        aux = act;
        act = xor(ant, act->point); //llama xor
        ant = aux;
        printf("%d ", ant);
    }
}

void listarFinalInicio(lista l){
    node *aux, *ant, *act = l.last;
    while(act){
        aux = act;
        act = xor(ant, act->point); //llama xor
        ant = aux;
        printf("%d ", ant);
    }
}

int cantidadElementos(lista l){
    node *aux, *ant, *act = l.last;
    int elem;
    while(act){
        aux = act;
        act = xor(ant, act->point); //llama xor
        ant = aux;
        elem++;
    }
    return elem;
}
