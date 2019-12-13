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
	printf("[1] - Ingresar Nombre de Archivo\n");
	printf("[2] - Leer Archivo\n");
	printf("[3] - Ordenar Archivo por IdTipo\n");
	printf("[4] - Imprimir\n");
	printf("[5] - Ejecutar Funcion ll_map\n");
	printf("[6] - Crear Archivo y Guardar\n");
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
	case 4:
		printf("\nDebe cargar el Archivo o Ponerle un Nombre\n");
		break;
	}
	return retorno;
}

/*int pideDatosAlta(LinkedList* pArrayListEmployee)
{

    Employee* pAux;
    int retorno = -1;
    char AuxId[10];
    char Auxnombre[128]="";
    char AuxhorasTrabajadas[10];
    char Auxsueldo[10];
    int parse = 0;
    int pContador = 0;
    char parsechar[10];
    int ok;

   cuentaArray(pArrayListEmployee,&pContador);
   printf("\nHay %d valores\n",pContador);
  // parse = atoi(AuxId);
   parse = pContador+1;
   printf("\nID nuevo: %d\n",parse);
   utn_getTexto("\nIngrese nombre: ","\nError",1,128,1,&Auxnombre);
  // printf("\nIngrese nombre: ");
  // scanf("%s",Auxnombre);
   printf("\nIngrese horas: ");
   scanf("%s",AuxhorasTrabajadas);
   printf("\nIngrese Sueldo: ");
   scanf("%s",Auxsueldo);

    if(/*AuxId!=NULL*///Auxnombre!=NULL && AuxhorasTrabajadas!=NULL && Auxsueldo!=NULL)
    /*{
        itoa(parse,parsechar,10);
        pAux=employee_newParametros(parsechar,Auxnombre,AuxhorasTrabajadas,Auxsueldo);
		 if(pAux!=NULL)
		 {
			 ll_add(pArrayListEmployee,pAux);
			 retorno = 0;
		 }

    }

    return retorno;
}
int pideDatosModifica(LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    int retorno = -1;
    int i;
    int j;
    int ParseID=0;
    int auxId;
    int Auxopcion;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    controller_ListEmployee(pArrayListEmployee);
    printf("\nIngrese un ID de Cliente: ");
    scanf("%d",&auxId);
   // ParseID = atoi(auxId);

//    *(lista + i)->
    //if(auxId!=NULL)
    //{
        pAux=ll_get(pArrayListEmployee,auxId-1);
        printf("\nID encontrado: %d",auxId);
        printf("\n1.- Nombre: %s \n2.- Horas Trabajadas: %d \n3.-Sueldo: %d \n4.-Salir",pAux->nombre,pAux->horasTrabajadas,pAux->sueldo);
        //%s %d %d ",auxId,pAux->nombre,pAux->horasTrabajadas,pAux->sueldo);
         printf("\n¿Que desea modificar?: ");
        scanf("%d",&Auxopcion);

        switch(Auxopcion)
        {
                case 1:if(utn_getTexto("\n\nIngrese un nombre nuevo: ","\nError",1,128,3,&auxNombre)==0)
                            if(employee_setNombre(pAux,&auxNombre)==0)
                                printf("\nModificado!\n");
                    break;
                case 2:
                       printf("\nIngrese Horas Nuevas: ");
                       scanf("%d",&auxHoras);
                       if(employee_setHorasTrabajadas(pAux,auxHoras)==0)
                                printf("\nModificado!\n");
                    break;
                case 3:printf("\nIngrese Sueldo nuevo: ");
                       scanf("%d",&auxSueldo);
                       if(employee_setSueldo(pAux,auxSueldo)==0)
                            printf("\nModificado!\n");
                    break;

                case 4:printf("\nExit");
                    break;

        }

    return retorno;

}
int pideDatosBaja(LinkedList* pArrayListEmployee)
{
    Employee* pAux;
    int retorno = -1;
    int auxId;
    int ok;

    controller_ListEmployee(pArrayListEmployee);

    printf("\nIngrese un ID de Cliente para la BAJA: ");
    scanf("%d",&auxId);
    pAux=ll_get(pArrayListEmployee,auxId-1);

    printf("\n1.- Nombre: %s \n2.- Horas Trabajadas: %d \n3.-Sueldo: %d",pAux->nombre,pAux->horasTrabajadas,pAux->sueldo);

    printf("\nDesea realizar la baja?(S = 1/N= 0): ");
    scanf("%d",&ok);
    if(ok!=1)
    {
        printf("\nError");
    }
    else
    {
        ll_remove(pArrayListEmployee,auxId-1);
        printf("\nBaja realizada!");
        retorno = 0;

    }



    return retorno;
}*/


/*int cuentaArray(LinkedList* pArrayListEmployee,int* contar)
{
    int retorno = -1;
    int contador=0;
    int i;

    if(pArrayListEmployee!=NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            contador +=1;
        }
        *contar = contador;
        retorno = 0;
    }

    return retorno;
}*/

