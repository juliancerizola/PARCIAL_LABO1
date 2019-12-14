/*
 * Entidad.h
 *
 *  Created on: 7 dic. 2019
 *      Author: tom
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_

typedef struct
{
	int Id;
	char descripcion[128];
	int precio;
	int idTipo;
	char oferta[30];

}Entidad;

Entidad* entidad_new();
Entidad* entidad_newParametros(char* idStr,char* descStr,char* precioStr, char* idTipStr);
void entidad_delete();

int entidad_setId(Entidad* this,int id);
int entidad_getId(Entidad* this,int* id);

int entidad_setDesc(Entidad* this,char descrip);
int entidad_getDesc(Entidad* this,char* descrip);

int entidad_setPrecio(Entidad* this,int precio);
int entidad_getPrecio(Entidad* this,int* precio);

int entidad_setidTipo(Entidad* this,int idTipo);
int entidad_getidTipo(Entidad* this,int* idTipo);

int entidad_getOferta(Entidad* this,char* oferta);
int entidad_setOferta(Entidad* this,char oferta);

int entidad_usarGets(Entidad* aux,int* id,char descrip[],int* precio,int* idTipo,char oferta[]);

int funCritTipo(void *argumento1, void *argumento2);
int funCritOferta(void* pElement);
int funCritDesktop(void *pElement);




#endif /* ENTIDAD_H_ */
