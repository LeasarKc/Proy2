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

    while(act){ //Recorrido
        aux=act;
        act= xor(ant, act->point); //LLama xor
        ant = aux;
        free(aux);
    }
    l->first= l->last = NULL;
}

int esVacia(lista l){
    if(l.first)
        return 0;
    return 1;
}

int insertarPrincipio(lista *l, int val){
    node *newnd=(node*)malloc(sizeof(node));
    if(!newnd)
        return 0;

    newnd->val = val;
    newnd->point = l->first;
    l->first=newnd;
    if(newnd->point) //Si no es el primer elemento insertado
        newnd->point->point = xor(newnd->point->point ,l->first); //Llama xor
    else //Sino, hay que actuaizar last
        l->last = newnd;
    return 1;
}

int insertarFinal(lista *l, int val){
    node *newnd=(node*)malloc(sizeof(node));
    if(!newnd)
        return 0;

    newnd->val = val;
    newnd->point = l->last;
    l->last=newnd;

    if(newnd->point) //Si no es el primero insertado
        newnd->point->point = xor(newnd->point->point ,l->last); //llama xor
    else //Sino hay que actualizar first
        l->first = newnd;
    return 1;
}

int insertarOrdenado(lista *l, int val){
    node *newnd=(node*)malloc(sizeof(node)), *ant = NULL, *aux, *act = l->first;

    if(!newnd)
        return 0;

    newnd->val = val;

    if(!l->first){ //Si es el primero en insetarse podemos omitir la mayoria del procedimiento
        l->first = l->last = newnd;
        newnd->point = NULL;
    }
    else{
        while(act && act->val<val){ //Recorrido
            aux=act;
            act=xor(ant,act->point); //llama xor
            ant=aux;
        }

        if(!act){ //Si es el ultio de la lista
            newnd->point = ant; //Apunta directamente al anterior
            ant->point = xor(ant->point, newnd); //Actualiza el anterior
            l->last = newnd; //Actualiza last

        }
        else if (!ant){ //Si es el primero de la lista
            newnd->point = act; //Apunta directamente al siguente
            act->point = xor(act->point,newnd); //Actualiza el siguiente
            l->first = newnd; //Actualiza first

        }else{  //Si esta entre dos nodos
            newnd->point = xor(ant,act); //Nuevo nodo guarda xor del anterior y posterior
            aux = xor(ant->point, act); //actualiza nodo anterior
            ant->point = xor(aux,newnd);
            aux = xor(ant, act->point); //actualiza nodo posterior
            act->point= xor(aux, newnd);
        }
    }
    return 1;
}

int quitarInicio(lista *l){
    node *aux;
    int val = l->first->val;

    if(l->first == l->last){ //Si es el unico elemento de la lista
        free(l->first);
        l->first = l->last = NULL;

    }else{
        aux = l->first;
        l->first = l->first->point;
        free(aux);
        aux = xor(aux,l->first->point); //llama xor
        l->first->point = aux;
    }
    return val;
}

int quitarFinal(lista *l){
    node *aux;
    int val = l->last->val;

    if(l->first == l->last){ //Si es el unico elemento de la lista
        free(l->last);
        l->last = l->first = NULL;

    }else{
        aux = l->last;
        l->last = l->last->point;
        free(aux);
        aux = xor(aux,l->last->point); //llaman xor
        l->last->point = aux;
    }
    return val;
}

int buscar(lista l, int val){
    node *aux, *ant = NULL, *act = l.first;
    while(act && act->val!= val){ //Recorrido
        aux = act;
        act = xor(ant, act->point); //llaman xor
        ant = aux;
    }
     if (!act)
        return 0;
    return 1;
}

int sacarPrimeraOcurrencia(lista *l, int val){
    node *aux, *aux2, *ant = NULL, *act = l->first;

    if(l->first->val == val){
        l->first->point->point = xor(l->first,l->first->point->point); //Actualiza el siguiente
        aux = l->first;;
        l->first = l->first->point;
        free(aux);

    }else{
        while(act && act->val != val){ //Recorrido
            aux = act;
            act = xor(ant, act->point); //llaman xor
            ant = aux;
        }
        if(!act)
            return 0;

        if(act == l->last){ //Si es el ultimo
            l->last->point->point = xor(l->last, l->last->point->point);
            aux = l->last;
            l->last = l->last->point;
            free(aux);

        }else{ //Si esta entre dos nodos
            aux = act;
            act = xor(ant, aux->point);   //reasignar apuntador posterior
            aux2 = xor(aux,act->point);
            act->point = xor(ant,aux2);
            aux2 = xor(aux,ant->point);    //reasignar apuntador anterior
            ant->point = xor(act,aux2);
            free(aux);
        }
    }
    return 1;
}

void listarInicioFinal(lista l){
    node *aux, *ant = NULL, *act = l.first;
    while(act){ //Recorrido
        aux = act;
        act = xor(ant, act->point); //llama xor
        ant = aux;
        printf("%d ", ant->val);
    }
}

void listarFinalInicio(lista l){
    node *aux, *ant = NULL, *act = l.last;
    while(act){ //Recorrido
        aux = act;
        act = xor(ant, act->point); //llama xor
        ant = aux;
        printf("%d ", ant->val);
    }
}

int cantidadElementos(lista l){
    node *aux, *ant = NULL, *act = l.first;
    int elem = 0;
    while(act){ //Recorrido
        aux = act;
        act = xor(ant, act->point); //llama xor
        ant = aux;
        elem++;
    }
    return elem;
}
