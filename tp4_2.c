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


	int cantidadTareas;
	struct Tarea **tareas;
	char cadena1[10] = "Tarea 1";
	char cadena2[10] = "Tarea 2";
	char cadena3[10] = "Tarea 3";
	char *pCadena1;
	pCadena1 = cadena1;

	//Comentario

	printf("\n Ingrese la cantidad de tareas a cargar: ");
	scanf("%i", &cantidadTareas);

	tareas = (struct Tarea **) malloc(sizeof(struct Tarea) * cantidadTareas);
	

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

		printf("\n Nueva tarea: ");
		printf("\n ID de la tarea: %i", tareas[i]->TareaID);
		printf("\n Descripcion de la tarea: %s", tareas[i]->Descripcion);
		printf("\n Duracion de la tarea: %i", tareas[i]->Duracion);

	}
	
	

	printf("Fin del programa");

	return 0;
}