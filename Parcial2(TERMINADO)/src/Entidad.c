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

int entidad_usarGets(Entidad* aux,int* id,char descrip[],int* precio,int* idTipo,char oferta[])
{
	int retorno = 0;
	entidad_getId(aux,id);
	entidad_getDesc(aux,descrip);
	entidad_getPrecio(aux,precio);
	entidad_getidTipo(aux,idTipo);
	entidad_getOferta(aux,oferta);
	return retorno;

}



int funCritOferta(void *pElement)
{
	Entidad *arg1 = (Entidad*) pElement;
	int tipo;
	int retorno = -1;

	entidad_getidTipo(arg1,&tipo);
	if (tipo==1) {
		strcpy(arg1->oferta,"50% DESCUENTO");
		retorno = 0;
	} else
	{
		strcpy(arg1->oferta,"SIN DATOS");
		retorno = 0;
	}
	return retorno;
}


int funCritDesktop(void *pElement) {
	Entidad *arg1 = (Entidad*) pElement;
	int tipo;
	int retorno;

	entidad_getidTipo(arg1,&tipo);
	if (tipo==1) {
		retorno = 1;
	} else {
		retorno = 0;
	}
	return retorno;
}


