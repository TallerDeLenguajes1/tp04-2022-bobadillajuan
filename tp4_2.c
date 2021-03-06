#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
};

void BusquedaPorPalabra(struct Tarea **, char *clave, int cantidadTareas);
//Cambios en rama BuscarTarea
void BusquedaPorId(struct Tarea **, int id, int cantidadTareas);


int main(){


	int cantidadTareas, opcion, contador = 0, BuscarID;
	struct Tarea **tareas;
	struct Tarea **tareasRealizadas;

	char *Buff;
	Buff= (char *) malloc(100*sizeof(char));

	printf("\n Ingrese la cantidad de tareas a cargar: ");
	scanf("%i", &cantidadTareas);

	tareas = (struct Tarea **) malloc(sizeof(struct Tarea) * cantidadTareas);
	tareasRealizadas = (struct Tarea **) malloc(sizeof(struct Tarea) * cantidadTareas);
	
	printf("\n-------------------Por favor. Carge las descripciones de las tareas-------------------\n\n");
	for (int i = 0; i < cantidadTareas; i++)
	{
		tareas[i] = (struct Tarea *) malloc(sizeof(struct Tarea));
		
		//ID indexado
		tareas[i]->TareaID = i;

		//Bloque para Buff --- Ahora la carga de tareas no es indexada, sino que se hace manualmente.
		fflush(stdin);
		printf("\nIngrese la descripcion de la tarea ID[%i]: ", i);
		gets(Buff);
		tareas[i]->Descripcion = (char *) malloc((strlen(Buff)+1)*sizeof(char));
		strcpy(tareas[i]->Descripcion,Buff);
		
		//Ahora se asigna una duración aleatoria
		tareas[i]->Duracion = rand()%(90)+10;
	}

	//Bloque de busqueda
	printf("\nPor favor ingrese una palabra clave para buscar la tarea: ");
	fflush(stdin);
	gets(Buff);
	BusquedaPorPalabra(tareas, Buff, cantidadTareas);
	// Bloque de busqueda de tareas
	printf("\nPor favor ingrese el ID la tarea a buscar: ");
	scanf("%i", &BuscarID);
	BusquedaPorId(tareas, BuscarID, cantidadTareas);

	// Este bloque lo que hace es darle memoria al otro arreglo de tareas
	for (int i = 0; i < cantidadTareas; i++)
	{
		tareasRealizadas[i] = (struct Tarea *) malloc(sizeof(struct Tarea));
		tareasRealizadas[i]->Descripcion = (char *) malloc(sizeof(char) * 100); 

	}

	printf("\n--------Lista de tareas: --------");
	for (int i = 0; i < cantidadTareas; i++)
	{

		printf("\n Nueva tarea ");
		printf("\n ID de la tarea: %i", tareas[i]->TareaID);
		printf("\n Descripcion de la tarea: %s", tareas[i]->Descripcion);
		printf("\n Duracion de la tarea: %i", tareas[i]->Duracion);

		printf("\n ----- ¿Esta tarea fue realizada? ----- \n1) Si \n2)No\n\n\n");
		scanf("%i", &opcion);

		if (opcion == 1)
		{

			tareasRealizadas[contador]->TareaID = tareas[i]->TareaID;
			tareasRealizadas[contador]->Duracion = tareas[i]->Duracion;
			strcpy(tareasRealizadas[contador]->Descripcion,tareas[i]->Descripcion);
			contador++;
			tareas[i] = NULL;

		}
		


	}

	printf("Lista de tareas pendientes: ");

	for (int i = 0; i < cantidadTareas; i++)
	{

		if(tareas[i] != NULL){
		printf("\n ---------- ");
		printf("\n ID de la tarea: %i", tareas[i]->TareaID);
		printf("\n Descripcion de la tarea: %s", tareas[i]->Descripcion);
		printf("\n Duracion de la tarea: %i", tareas[i]->Duracion);
		}
	}

	printf("\n\n  Tareas realizadas: ");
	for (int i = 0; i < contador; i++)
	{

		printf("\n ---------- ");
		printf("\n ID de la tarea: %i", tareasRealizadas[i]->TareaID);
		printf("\n Descripcion de la tarea: %s", tareasRealizadas[i]->Descripcion);
		printf("\n Duracion de la tarea: %i", tareasRealizadas[i]->Duracion);

	}

	//Libero la memoria
	free(Buff);
	for (int i = 0; i < cantidadTareas; i++){
	free(tareas[i]);
	free(tareasRealizadas[i]);
	}
	
	

	printf("\nFin del programa");

	return 0;
}

void BusquedaPorPalabra(struct Tarea ** tareas, char *clave, int cantidadTareas){
	int controlador=0;
	for (int i = 0; i < cantidadTareas; i++){
		if(tareas[i] != NULL){
			if(strcmp(tareas[i]->Descripcion, clave) == 0){
				printf("\nTarea encontrada:");
				printf("\n ID de la tarea: %i", tareas[i]->TareaID);
				printf("\n Descripcion de la tarea: %s", tareas[i]->Descripcion);
				printf("\n Duracion de la tarea: %i", tareas[i]->Duracion);
				controlador++;
			}
		}
	}
	if(controlador == 0)
	printf("\nTarea no encontrada.");
}

void BusquedaPorId(struct Tarea ** tareas, int id, int cantidadTareas){
	int controlador=0;
	for (int i = 0; i < cantidadTareas; i++){
		if(tareas[i] != NULL){
			if(tareas[i]->TareaID == id){
				printf("\nTarea encontrada:");
				printf("\n ID de la tarea: %i", tareas[i]->TareaID);
				printf("\n Descripcion de la tarea: %s", tareas[i]->Descripcion);
				printf("\n Duracion de la tarea: %i", tareas[i]->Duracion);
				controlador++;
			}
		}
	}
	if(controlador == 0)
	printf("\nTarea no encontrada.");
}
