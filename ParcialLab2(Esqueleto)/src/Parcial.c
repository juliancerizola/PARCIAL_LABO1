/*
 ============================================================================
 Name        : Parcial.c
 Author      : Tomas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Opciones.h"
#include "LinkedList.h"
#include "Controller.h"

int main(void)
{
	printf("Parcial Laboratorio\n");
	/*********************************/
	int opciones = 0;
	LinkedList* ArrayEntidad = ll_newLinkedList();
	//LinkedList* Extra = ll_newLinkedList();
	//LinkedList* Extra2 = ll_newLinkedList();
	do
	{
		opcionesMenu();
		seleccion(&opciones);
		printf("\nOpcion Elegida: %d\n ",opciones);
		switch(opciones)
		{
			case 1:
				/*if(controller_loadFromText("data.csv",ArrayEntidad)==0)
					msg(1);
				else
					msg(2);*/
				break;
			case 2:
				printf("\nOpcion 2\n");
				break;
			case 3:
				printf("\nOpcion 3\n");
				break;
			case 4:
				/*if (flag == 1) {
					Extra = ll_newLinkedList();
					Extra = ll_filter(ArrayEntidad, funCritDias);
					controller_saveAsText("Extras.csv",Extra);
				} else {
					msg(2);
				}*/
				printf("\nOpcion 4\n");
				break;
			case 5:
				printf("\nOpcion 5\n");
				break;
		}
	}while(opciones!=10);
	if(opciones==10)
	{
		msg(3);
	}




	return 0;
}
