#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int main(){
    lista l = crearLista();
    int op, elm;
    while(op){
        printf("Elija una opcion: \n 1: Resetear lista \n 2: Comprobar si esta vacia \n 3: Insertar elemento al principio \n 4: Insertar elemento al final \n 5: Insertar ordenado \n 6: Comprobar si un elemento esta en la lista \n 7: Sacar primero \n 8: Sacar final \n 9: Sacar primera ocurrencia \n 10: listar inicio a final \n 11: Listar final a inicio \n 12: Cantidad de elementos \n 0: Salir");
        scanf("%d", op);
        switch(op){
            case 1:
                inicializarLista(&l);
            case 2:
                if (esVacia(l))
                    printf("Esta vacia");
                else
                    printf("No esta vacia");
            case 3:
                printf("Ingrese el elemento");
                scanf("%d", elm);
                if (!insertarPrincipio(&l, elm))
                    printf("Error en malloc");
            case 4:
                printf("Ingrese el elemento");
                scanf("%d", elm);
                if (!insertarFinal(&l, elm))
                    printf("Error en malloc");
            case 5:
                printf("Ingrese el elemento");
                scanf("%d", elm);
                if (!insertarOrdenado(&l, elm))
                    printf("Error en malloc");
            case 6:
                printf("Ingrese el elemento");
                scanf("%d", elm);
                if (buscar(l, elm))
                    printf("El elemento esta en la lista");
                else
                    printf("El elemento NO esta en la lista");
            case 7:
                if(esVacia(l)) //Comprobar si la lista tiene elementos
                    printf("Lista vacia");
                else
                    printf("El elemento es %d",quitarInicio(&l));
            case 8:
                if(esVacia(l)) //Comprobar si la lista tiene elementos
                    printf("Lista vacia");
                else
                    printf("El elemento es %d",quitarFinal(&l));
            case 9:
                printf("Ingrese el elemento");
                scanf("%d",elm);

                if(!sacarPrimeraOcurrencia(&l))
                    printf("No se encontro el elemento");
                else
                    printf("Se saco la primera ocurrencia");
            case 10:
                listarInicioFinal(l);
            case 11:
                listarFinalInicio(l);
            case 12:;
                printf("La cantidad de elementos es de %d", cantidadElementos(l));
        }
    }
}
