#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
};



int main(){


	int cantidadTareas, opcion, contador = 0;
	struct Tarea **tareas;
	struct Tarea **tareasNoRealizadas;

	//Esto lo tengo que arreglar
	char cadena1[10] = "Tarea 1";
	char cadena2[10] = "Tarea 2";
	char cadena3[10] = "Tarea 3";
	char *pCadena1;
	pCadena1 = cadena1;


	printf("\n Ingrese la cantidad de tareas a cargar: ");
	scanf("%i", &cantidadTareas);

	tareas = (struct Tarea **) malloc(sizeof(struct Tarea) * cantidadTareas);
	tareasNoRealizadas = (struct Tarea **) malloc(sizeof(struct Tarea) * cantidadTareas);

	//Por ahora tan solo cargo 3
	for (int i = 0; i < cantidadTareas; i++)
	{
		tareas[i] = (struct Tarea *) malloc(sizeof(struct Tarea));
		tareas[i]->Descripcion = (char *) malloc(sizeof(char) * 10); 
		

		tareas[i]->TareaID = i;
		//Tambien hace falta la descripcion
		strcpy(tareas[i]->Descripcion,pCadena1);
		//Hace falta cambiar para que esto sea un numero random
		tareas[i]->Duracion = 5;
		

	}

	for (int i = 0; i < cantidadTareas; i++)
	{
		tareasNoRealizadas[i] = (struct Tarea *) malloc(sizeof(struct Tarea));
		tareasNoRealizadas[i]->Descripcion = (char *) malloc(sizeof(char) * 10); 

	}

	printf("\nLista de tareas:");
	for (int i = 0; i < cantidadTareas; i++)
	{

		printf("\n Nueva tarea: ");
		printf("\n ID de la tarea: %i", tareas[i]->TareaID);
		printf("\n Descripcion de la tarea: %s", tareas[i]->Descripcion);
		printf("\n Duracion de la tarea: %i", tareas[i]->Duracion);

		printf("\n ----- ¿Esta tarea fue realizada? ----- \n1) Si \n2)No\n\n\n");
		scanf("%i", &opcion);

		if (opcion == 1)
		{
			contador++;
			tareasNoRealizadas[contador]->TareaID = tareas[i]->TareaID;
			tareasNoRealizadas[contador]->Duracion = tareas[contador]->Duracion;
			strcpy(tareasNoRealizadas[contador]->Descripcion,tareas[i]->Descripcion);

			//Todavia nos falta hacer que apunte al NULL (debo hacer un free a la liberada)



		}
		


	}

	printf("Lista de tareas pendientes: ");

	for (int i = 0; i < cantidadTareas; i++)
	{

		printf("\n Nueva tarea: ");
		printf("\n ID de la tarea: %i", tareas[i]->TareaID);
		printf("\n Descripcion de la tarea: %s", tareas[i]->Descripcion);
		printf("\n Duracion de la tarea: %i", tareas[i]->Duracion);

	}

	printf("\n\n  Tareas sin realizar: ");
	for (int i = 0; i < contador; i++)
	{

		//Aqui hay problemas con el bucle, ya que leera todas las Norealizadas anteriores al indice del contador
		printf("\n Nueva tarea: ");
		printf("\n ID de la tarea: %i", tareasNoRealizadas[i]->TareaID);
		printf("\n Descripcion de la tarea: %s", tareasNoRealizadas[i]->Descripcion);
		printf("\n Duracion de la tarea: %i", tareasNoRealizadas[i]->Duracion);

	}

	//Falta liberar toda la memoria
	
	

	printf("Fin del programa");

	return 0;
}