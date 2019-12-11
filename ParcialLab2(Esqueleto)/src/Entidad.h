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
	//char string[20];
	//char string[20];
	//char character;
	//int entero;
}Entidad;

Entidad* entidad_new();
Entidad* entidad_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void entidad_delete();

int entidad_setId(Entidad* this,int id);
int entidad_getId(Entidad* this,int* id);

/*int entidad_setNombre(Entidad* this,char nombre);
int entidad_getNombre(Entidad* this,char* nombre);

int entidad_setHorasTrabajadas(Entidad* this,int horasTrabajadas);
int entidad_getHorasTrabajadas(Entidad* this,int* horasTrabajadas);

int entidad_setSueldo(Entidad* this,int sueldo);
int entidad_getSueldo(Entidad* this,int* sueldo);*/

/*int funCritDias(void* pElement);
int funCritMacho(void* pElement);
int funCritRaza(void* pElement);*/



#endif /* ENTIDAD_H_ */
