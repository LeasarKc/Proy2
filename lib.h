

typedef struct node{
    int val;
    struct node *point;
}node;

typedef struct lista {
    node *first;
    node *last;
}lista;

lista crearLista();

void inicializarLista(lista*);

int esVacia(lista l);

int insertarPrincipio(lista *l,int val);

int insertarFinal(lista *l, int val);

int insertarOrdenado(lista *l, int val);

int quitarInicio(lista *l);

int quitarFinal(lista *l);

void listarInicioFinal(lista);

void listarFinalInicio(lista);

int buscar(lista l, int val);
