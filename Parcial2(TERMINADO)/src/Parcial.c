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
#include "Entidad.h"

int main(void)
{
	printf("Parcial Laboratorio\n");
	/*********************************/
	int opciones = 0;
	int insert = 0;
	int insertA = 0;
	char nombreArch[30];
	LinkedList* ArrayEntidad = ll_newLinkedList();
	LinkedList* DeskTop;
	do
	{
		opcionesMenu();
		seleccion(&opciones);
		switch(opciones)
		{
			case 1:
					printf("\nIngrese nombre del archivo: ");
					scanf("%s",nombreArch);
					if(nombreArch!=NULL)
					{
						insertA = 1;
					}
				break;

			case 2:
				if(insertA==1)
				{
					if(controller_loadFromText("datos_Fin.csv",ArrayEntidad)==0)
					{
						msg(1);
						insert = 1;
					}
					else
						msg(2);
				}
				else
					msg(4);
				break;
			case 3:

				if(insert ==1 && insertA==1)
				{
					if(controller_sortEmployee(ArrayEntidad)==0)
						msg(1);
					else
						msg(2);
				}
				else
					msg(4);
				break;
			case 4:
				if(insert==1 && insertA==1)
				{
					if(controller_ListEmployee(ArrayEntidad)==0)
						msg(1);
					else
						msg(2);
				}
				else
					msg(4);
				break;
			case 5:
				if(insert==1 && insertA==1)
				{
					ll_map(ArrayEntidad,funCritOferta);
					msg(1);
				}
				else
					msg(4);
				break;
			case 6:
				if(insert==1 && insertA==1)
				{
					DeskTop = ll_newLinkedList();
					DeskTop = ll_filter(ArrayEntidad, funCritDesktop);
					controller_saveAsText("filtado.csv",DeskTop);
					printf("\nGuardado!\n");
				}
				else
					msg(4);
				break;
			case 7:
				controller_ListEmployee(DeskTop);
				break;
		}
	}while(opciones!=10);
	if(opciones==10)
	{
		msg(3);
	}




	return 0;
}
