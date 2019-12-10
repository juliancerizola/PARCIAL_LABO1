/*
 * Entidad.c
 *
 *  Created on: 7 dic. 2019
 *      Author: tom
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entidad.h"

Entidad* entidad_new()
{
	Entidad* ent = (Entidad*)malloc( sizeof(Entidad));

	if(ent != NULL){
		ent->Id=0;
		/*strcpy(ent->nombre,"");
		ent->horasTrabajadas=0;
		ent->sueldo=0;*/

	}
	return ent;
}


Entidad* entidad_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{

	Entidad* ent = (Entidad*)malloc( sizeof(Entidad));

	if(ent != NULL){
	    ent->Id=atoi(idStr);
	    /*strcpy(emp->nombre, nombreStr);
	    emp->horasTrabajadas=atoi(horasTrabajadasStr);
	    emp->sueldo=atoi(sueldo);
	    strncpy(nombreStr,ent->nombre,20)*/

	}

	return ent;
}

//Generamos los Getter y Setter

int entidad_setId(Entidad* this,int id)
{
	int retorno = -1;
	if(this!=NULL && id!= NULL)
	{
		this->Id=id;
		retorno = 0;
	}
return retorno;

}
int entidad_getId(Entidad* this,int* id)
{

	int retorno = -1;
	if(this!=NULL && id!=NULL)
	{
		id=this->Id;
		retorno = 0;
	}
	return retorno;

}


/*int employee_setNombre(Employee* this,char nombre)
{
    int retorno = -1;
	if(this!=NULL && nombre!= NULL)
	{
       strcpy(this->nombre,nombre);

		retorno = 0;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
   int retorno = -1 ;
	if(this!=NULL && nombre!= NULL)
	{
       nombre = this->nombre;

		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
	if(this!=NULL && horasTrabajadas!= NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno = 0;
	}
    return retorno;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
	if(this!=NULL && horasTrabajadas!= NULL)
	{
		horasTrabajadas=this->horasTrabajadas;
		retorno = 0;
	}
    return retorno;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
	if(this!=NULL && sueldo!= NULL)
	{
		this->sueldo=sueldo;
		retorno = 0;
	}
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
	if(this!=NULL && sueldo!= NULL)
	{
		sueldo=this->sueldo;
		retorno = 0;
	}
    return retorno;
}*/
