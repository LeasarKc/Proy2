/**********************************************************************
main del primer proyecto de:
Algoritmos y Programacion II
Por:
Diego Peña
Luis Enrique Salazar
***********************************************************************/

typedef struct node{
    int val;
    struct node *point;
}node;

typedef struct lista {
    node *first;
    node *last;
}lista;

lista crearLista(); //Crea una lista nueva

node* xor(node*, node*); //Funcion para hacer xor entre dos nodos

void inicializarLista(lista*); //Borra todos los elementos de la lista

int esVacia(lista l); //Indica si la lista esta vacia o no

int insertarPrincipio(lista *l,int val); //Inserta un elemento al principio

int insertarFinal(lista *l, int val); //Inserta un elemento al final

int insertarOrdenado(lista *l, int val); //Inserta un elemento ordenadamente

int quitarInicio(lista *l); //Quita el primer elemento

int quitarFinal(lista *l); //Quita el ultimo elemento

int sacarPrimeraOcurrencia(lista*, int); //Saca la primera ocurrencia del elemento

void listarInicioFinal(lista); //Imprime los elementos de principio a fin

void listarFinalInicio(lista); //Imprime los elementos de fin a principio

int buscar(lista l, int val); //Indica si un elemento esta en la lista o no

int cantidadElementos(lista); //Cuenta la cantidad de elementos de
