#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

lista crearLista(){
    lista newl;
    newl.first = newl.last = NULL;
    return newl;
}

void inicializarLista(lista *l){
    node *aux = NULL, *ant = NULL, *act = l->first;

    while(act){
        aux=act;
        //act= moverDerecha(ant, act->point);
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
    //    newl->point->point = newl->point->point ^l->first;
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
    //    newl->point->point = newl->point->point ^l->last;
    return 1;
}

int insertarOrdenado(lista *l, int val){
    node *newl=(node*)malloc(sizeof(node)), *ant, *aux, *act = l->first;

    if(!newl)
        return 0;

    while(act && act->val<val){
        aux=act;
        //act=moveDerecha(ant,act->point)
        ant=aux;
    }

    newl->val = val;
    //newl->point = ant^act;
    //aux = ant->point ^ act; //actualiza nodo anterior
    //ant->point = aux^newl;
    //aux = ant ^ act->point;
    //act->point= aux ^ newl;
    return 1;
}

int quitarInicio(lista *l){
    node *aux;
    int val = l->first->val;

    aux = l->first;
    l->first = l->first->point;
    free(aux);
    //aux = aux^l->first->point;
    l->first->point = aux;
    return val;
}

int quitarFinal(lista *l){
    node *aux;
    int val = l->last->val;

    aux = l->last;
    l->last = l->last->point;
    free(aux);
    //aux = aux^l->last->point;
    l->last->point = aux;
    return val;
}

int buscar(lista l, int val){
    node *aux, *ant, *act = l.first;
    while(act && act->val!= val){
        aux = act;
        //act = movDerecha(ant, act.point);
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
        //act = moveder(ant, act->point);
        ant = aux;
    }
    if(!act)
        return 0;

    aux = act;
    //act = ant ^ aux->point;   //reasignar apuntador posterior
    //aux2 = aux^act->point;
    //act->point = ant^aux2;
    //aux2 = aux^ant->point;    //reasignar apuntador anterior
    //ant->point = act^aux2;
    free(aux);
    return 1;
}

void listarInicioFinal(lista l){
    node *aux, *ant, *act = l.first;
    while(act){
        aux = act;
        //act = movDer(ant, act.point);
        ant = aux;
        printf("%d ", ant);
    }
}

void listarFinalInicio(lista l){
    node *aux, *ant, *act = l.last;
    while(act){
        aux = act;
        //act = movizq(ant, act.point);
        ant = aux;
        printf("%d ", ant);
    }
}

int cantidadElementos(lista l){
    node *aux, *ant, *act = l.last;
    int elem;
    while(act){
        aux = act;
        //act = movizq(ant, act.point);
        ant = aux;
        elem++;
    }
    return elem;
}
