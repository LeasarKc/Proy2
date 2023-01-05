/**********************************************************************
main del primer proyecto de:
Algoritmos y Programacion II
Por:
Diego Peña
Luis Enrique Salazar
***********************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include "lib.h"

int main(){
    lista l = crearLista();
    int op, elm;

    while(1){
        printf("Elija una opcion: \n 1: Resetear lista \n 2: Comprobar si esta vacia \n 3: Insertar elemento al principio \n 4: Insertar elemento al final \n 5: Insertar ordenado \n 6: Comprobar si un elemento esta en la lista \n 7: Sacar primero \n 8: Sacar final \n 9: Sacar primera ocurrencia \n 10: listar inicio a final \n 11: Listar final a inicio \n 12: Cantidad de elementos \n 0: Salir \n");
        scanf("%d", &op);
        printf("\n");

        switch(op){
            case 1:
                inicializarLista(&l);
                break;
            case 2:
                if (esVacia(l))
                    printf("Esta vacia\n");
                else
                    printf("No esta vacia\n");
                break;
            case 3:
                printf("Ingrese el elemento\n");
                scanf("%d", &elm);
                if (!insertarPrincipio(&l, elm))
                    printf("Error en malloc\n");
                break;
            case 4:
                printf("Ingrese el elemento\n");
                scanf("%d", &elm);
                if (!insertarFinal(&l, elm))
                    printf("Error en malloc\n");
                break;
            case 5:
                printf("Ingrese el elemento\n");
                scanf("%d", &elm);
                if (!insertarOrdenado(&l, elm))
                    printf("Error en malloc\n");
                break;
            case 6:
                printf("Ingrese el elemento\n");
                scanf("%d", &elm);
                if (buscar(l, elm))
                    printf("El elemento esta en la lista\n");
                else
                    printf("El elemento NO esta en la lista\n");
                break;
            case 7:
                if(esVacia(l)) //Comprobar si la lista tiene elementos
                    printf("Lista vacia\n");
                else
                    printf("El elemento es %d \n",quitarInicio(&l));
                break;
            case 8:
                if(esVacia(l)) //Comprobar si la lista tiene elementos
                    printf("Lista vacia\n");
                else
                  printf("El elemento es %d \n",quitarFinal(&l));
                break;
            case 9:
                if (esVacia(l))
                    printf("Lista Vacia\n");
                else{
                    printf("Ingrese el elemento\n");
                    scanf("%d",&elm);

                    elm = sacarPrimeraOcurrencia(&l, elm);
                    if(!elm)
                        printf("No se encontro el elemento\n");
                    else
                        printf("Se saco la primera ocurrencia\n");
                }
                break;
            case 10:
                listarInicioFinal(l);
                printf("\n");
                break;
            case 11:
                listarFinalInicio(l);
                printf("\n");
                break;
            case 12:
                elm = cantidadElementos(l);
                printf("La cantidad de elementos es de %d\n", elm);
                break;
            case 0:
                return 1;
        }

        printf("\n");
    }
}
