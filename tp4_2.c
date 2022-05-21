#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
};

typedef struct nodo{
    struct Tarea Tarea;
    struct nodo *Siguiente;
}nodo;

typedef nodo *Lista;

void listaVacia(Lista *);
void escribirTarea(struct Tarea tareas);
nodo *crearNodo(int i);
void insertarNodo(Lista *,nodo *);
void mostrarListaDeTareas(Lista);
void BusquedaPorPalabra(Lista , char *clave);
void BusquedaPorId(Lista, int id);
void ordenarTareas(Lista *,Lista *);
void eliminarNodo(Lista *);
void eliminarLista(Lista *);



int main(){


	int cantidadTareas, opcion, contador = 0, BuscarID;
	nodo *nodoAux;
	Lista tareasRealizadas,tareas;

	listaVacia(&tareasRealizadas);
	listaVacia(&tareas);

	char *Buff;
	Buff= (char *) malloc(100*sizeof(char));

	printf("\n Ingrese la cantidad de tareas a cargar: ");
	scanf("%i", &cantidadTareas);

	printf("\n-------------------Por favor. Carge las descripciones de las tareas-------------------\n\n");
	for (int i = 0; i < cantidadTareas; i++)
	{
		nodoAux=crearNodo(i);
        insertarNodo(&tareas,nodoAux);
	}

	printf("\n----- Lista de tareas cargadas -----");
	mostrarListaDeTareas(tareas);

	//Bloque de busqueda
	printf("\nPor favor ingrese una palabra clave para buscar la tarea: ");
	fflush(stdin);
	gets(Buff);
	BusquedaPorPalabra(tareas, Buff);

	printf("\nPor favor ingrese el ID la tarea a buscar: ");
	scanf("%i", &BuscarID);
	BusquedaPorId(tareas, BuscarID);

    //Bloque para separar las pendientes de las realizadas.
	ordenarTareas(&tareas,&tareasRealizadas);
    printf("\nLista de tareas realizadas:\n");
    mostrarListaDeTareas(tareasRealizadas);
    printf("\nLista de tareas pendientes:\n");
    mostrarListaDeTareas(tareas);
	


    
	printf("\nFin del programa");
    free(Buff);
    eliminarLista(&tareas);
    eliminarLista(&tareasRealizadas);


	return 0;
}

void BusquedaPorPalabra(Lista lista, char *clave){
	while(lista && strcmp(lista->Tarea.Descripcion, clave)!=0)
    {
        lista=lista->Siguiente;
    }
    if (lista)
    {
        printf("\nTarea encontrada:");

        
		printf("\nTarea ID: %i", lista->Tarea.TareaID);
		printf("\nTarea Descripcion: %s", lista->Tarea.Descripcion);
		printf("\nTarea Duracion: %i", lista->Tarea.Duracion);
    }else{
		printf("\nTarea no encontrada.");
	}

}

void BusquedaPorId(Lista lista, int id){
	while(lista && lista->Tarea.TareaID!=id)
    {
        lista=lista->Siguiente;
    }
    if (lista)
    {
         printf("\nTarea encontrada:");
        escribirTarea(lista->Tarea);
    }else{
		printf("\nTarea no encontrada.");
	}
}

void listaVacia(Lista *lista){
    *lista=NULL;
}

struct Tarea cargarTarea(int i){

    char *buff=malloc(100*sizeof(char));
    struct Tarea nuevaTarea;
    printf("\n\nIngrese la descripcion de la tarea ID[%i]: ", i);
    fflush(stdin);
    gets(buff);
    nuevaTarea.Descripcion=(char *)malloc((strlen(buff)+1)*sizeof(char));
    strcpy(nuevaTarea.Descripcion,buff);
    nuevaTarea.Duracion=rand()%90 + 10;
    nuevaTarea.TareaID=i;
	printf("\nTarea cargada con éxito!\n");

    free (buff);

    return nuevaTarea;
}

nodo *crearNodo(int id){
    nodo *nuevoNodo=(nodo *)malloc(sizeof(nodo));
    nuevoNodo->Tarea=cargarTarea(id);
    nuevoNodo->Siguiente=NULL;
}

void eliminarNodo(Lista *lista){
    nodo *eliminado=*lista;
    *lista=(*lista)->Siguiente;
    free(eliminado);
}

void eliminarLista(Lista *listaABorrar){
    while (*listaABorrar)
    {
        eliminarNodo(listaABorrar);   
    }
}

void insertarNodo(Lista *head, nodo *nodoAInsertar){
    nodoAInsertar->Siguiente=*head;
    *head=nodoAInsertar;
}

void mostrarListaDeTareas(Lista listaAMostrar){
    while (listaAMostrar)
    {
        escribirTarea(listaAMostrar->Tarea);
        listaAMostrar=listaAMostrar->Siguiente;
    }
}

void escribirTarea(struct Tarea tareas){

	printf("\n ID de la tarea: %i", tareas.TareaID);
	printf("\n Descripcion de la tarea: %s", tareas.Descripcion);
	printf("\n Duracion de la tarea: %i", tareas.Duracion);

}


void ordenarTareas(Lista *tareasPendientes, Lista *tareasRealizadas){
    int completada;
    Lista listaAuxiliar=*tareasPendientes;
    nodo *nodoAuxiliar,*nodoAnterior=listaAuxiliar;
    printf("\n----- Por favor indique si las tareas fueron realizadas -----\n\n");
    while (listaAuxiliar)
    {
        escribirTarea(listaAuxiliar->Tarea);
        fflush(stdin);
        printf("\n¿Fue realizada la tarea? 1) Si. --- 2) No. \n");
        scanf("%d",&completada);
        if (completada==1)
        {
            nodoAuxiliar=listaAuxiliar;
            if (nodoAnterior==listaAuxiliar)//es el primer elemento de la lista
            {
                (*tareasPendientes)=(*tareasPendientes)->Siguiente;
                listaAuxiliar=*tareasPendientes;
            }else{
                    (*nodoAnterior).Siguiente=listaAuxiliar->Siguiente;
                    listaAuxiliar=listaAuxiliar->Siguiente;
            }
            (*nodoAuxiliar).Siguiente=*tareasRealizadas;
            *tareasRealizadas=nodoAuxiliar;
        }else{
            listaAuxiliar=listaAuxiliar->Siguiente;
            nodoAnterior=*tareasPendientes;
        }
    }
}




