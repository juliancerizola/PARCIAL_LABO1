/*
 * Opciones.c
 *
 *  Created on: 7 dic. 2019
 *      Author: tom
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

void opcionesMenu()
{
	printf("\n");
	printf("[1] - Opcion 1\n");
	printf("[2] - Opcion 2\n");
	printf("[3] - Opcion 3\n");
	printf("[4] - Opcion 4\n");
	printf("[5] - Opcion 5\n");
	printf("\n");
}
int seleccion(int* opcion)
{
	int retorno = -1;
	int aux;
	printf("\nSeleccione opcion: ");
	scanf("%d",&aux);
	if(aux!=NULL)
	{
		*opcion=aux;
	}

	return retorno;
}
int msg(int x){
	int retorno = -1;
	switch(x){
	case 1:
		printf("\nRealizado con Exito\n");
		retorno = 0;
		break;
	case 2:
		printf("\Ha ocurrido un error\n");
		retorno = 0;
		break;
	case 3:
		printf("\nHa salido del sistema");
		break;
	}
	return retorno;
}


