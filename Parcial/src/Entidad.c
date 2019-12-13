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
		strcpy(ent->descripcion,"");
		ent->precio = 0;
		ent->idTipo = 0;
		strcpy(ent->oferta,"");
		/*strcpy(ent->nombre,"");
		ent->horasTrabajadas=0;
		ent->sueldo=0;*/

	}
	return ent;
}


Entidad* entidad_newParametros(char* idStr,char* descStr,char* precioStr, char* idTipStr)
{

	Entidad* ent = (Entidad*)malloc( sizeof(Entidad));

	if(ent != NULL){
	    ent->Id=atoi(idStr);
	    strcpy(ent->descripcion,descStr);
	    ent->precio = atoi(precioStr);
	    ent->idTipo = atoi(idTipStr);
	    /*strcpy(emp->nombre, nombreStr);
	    emp->horasTrabajadas=atoi(horasTrabajadasStr);
	    emp->sueldo=atoi(sueldo);
	    strncpy(nombreStr,ent->nombre,20)*/

	    //printf("\n%d %s %d %d",ent->Id,ent->descripcion,ent->precio,ent->idTipo);
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
		*id=this->Id;
		retorno = 0;
	}
	return retorno;

}

int entidad_setDesc(Entidad* this,char descrip)
{
    int retorno = -1;
	if(this!=NULL && descrip!= NULL)
	{
       strcpy(this->descripcion,descrip);

		retorno = 0;
	}
	return retorno;

}

int entidad_getDesc(Entidad* this,char* descrip)
{
	   int retorno = -1 ;
		if(this!=NULL && descrip!= NULL)
		{
			descrip = this->descripcion;

			retorno = 0;
		}
		return retorno;
}

int entidad_setPrecio(Entidad* this,int precio)
{
	int retorno = -1;
	if(this!=NULL && precio!=NULL)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int entidad_getPrecio(Entidad* this,int* precio)
{
	int retorno = -1;
	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		retorno = 0;
	}
	return retorno;
}

int entidad_setidTipo(Entidad* this,int idTipo)
{

	int retorno = -1;
	if(this!=NULL && idTipo!=NULL)
	{
		this->idTipo=idTipo;
		retorno = 0;
	}
	return retorno;
}
int entidad_getidTipo(Entidad* this,int* idTipo)
{
	int retorno = -1;
	if(this!=NULL && idTipo!=NULL)
	{
		*idTipo=this->idTipo;
		retorno = 0;
	}
	return retorno;
}


int funCritTipo(void *argumento1, void *argumento2) {
	Entidad *arg1 = (Entidad*) argumento1;
	Entidad *arg2 = (Entidad*) argumento2;
	int valor1, valor2;
	int retorno;

	entidad_getidTipo(arg1,&valor1);
	entidad_getidTipo(arg2,&valor2);
	//employee_getHorasTrabajadas(arg1, &valor1);
	//employee_getHorasTrabajadas(arg2, &horas2);

	if (valor1 < valor2) {
		retorno = -1;
	} else if (valor1 > valor2) {
		retorno = 1;

	} else {
		retorno = 0;
	}
	return retorno;
}
int entidad_setOferta(Entidad* this,char oferta)
{
	int retorno = -1;
	if(this!=NULL && oferta!=NULL)
	{
		strcpy(this->oferta,oferta);
		retorno = 0;
	}
	return retorno;
}
int entidad_getOferta(Entidad* this,char* oferta)
{
	int retorno = -1;
	if(this!=NULL && oferta!=NULL)
	{
		oferta=this->oferta;
		retorno = 0;
	}
	return 0;
}


int funCritOferta(void *pElement)
{
	Entidad* aux;
	char oferta1[] = {"SIN DATOS"};
	char oferta2[] = {"50% DESCUENTO"};
	//aux=(Entidad*)pElement;

	int retorno;

	if (aux->idTipo==1){
		entidad_setOferta(aux,oferta2);
		//strcpy(aux->oferta,oferta2);
		retorno = 1;
	} else if(aux->idTipo==2){
		entidad_setOferta(aux,oferta1);
		//strcpy(aux->oferta,oferta1);
		retorno = 1;
	}
	return retorno;
}


int funCritDesktop(void *pElement) {
	Entidad *arg1 = (Entidad*) pElement;

	int valor;
	int retorno;

	entidad_getidTipo(arg1, &valor);

	if (valor==1) {
		retorno = 1;
	} else {
		retorno = 0;
	}
	return retorno;
}


