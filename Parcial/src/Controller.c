
#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Entidad.h"
#include "parser.h"
#include "Opciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* ArrayEntidad)
{

	FILE *pArchivo;
	int retorno=0;

	if((pArchivo=fopen(path,"r"))==NULL)
	{
		printf("El archivo no puede ser abierto");
		retorno=-1;
	}
	//parser_EmployeeFromText(pArchivo,Entidad);
	parser_EmployeeFromText(pArchivo,ArrayEntidad);
    fclose(pArchivo);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* ArrayEntidad)
{

	/*FILE *pArchivo;
	int retorno=0;
	//int cantidadLeida,longitudTexto;

	if((pArchivo=fopen(path,"r+b"))==NULL)
	{
		printf("El archivo no puede ser abierto");
		retorno=-1;
	}
	parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    fclose(pArchivo);*/

    return 0;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* ArrayEntidad)
{
    /*int retorno = -1;
    if(pideDatosAlta(pArrayListEmployee)==0)
    {
        retorno = 0;
    }*/
    return 0;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* ArrayEntidad)
{
    int retorno = -1;
   /* if(pArrayListEmployee!=NULL)
    {
        if(pideDatosModifica(pArrayListEmployee)==0)
        {
            retorno = 0;
        }
    }*/
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* ArrayEntidad)
{
    int retorno=-1;
   /* if(pArrayListEmployee!=NULL)
    {
        if(pideDatosBaja(pArrayListEmployee)==0)
        {
            retorno = 0;
        }
    }*/
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* ArrayEntidad)
{
    Entidad* pAux;
    int retorno=-1;
    int i;
    int auxId;
    char auxDesc[128];
    int auxPrecio;
    int auxidTipo;
    char auxOferta[30];
    if(ArrayEntidad!=NULL)
    {
         for(i=0;i<ll_len(ArrayEntidad);i++)
        {

            pAux = ll_get(ArrayEntidad,i);
            auxId = pAux->Id;
            strcpy(auxDesc,pAux->descripcion);
            auxPrecio = pAux->precio;
            auxidTipo = pAux->idTipo;
            strcpy(auxOferta,pAux->oferta);

            if(entidad_getId(pAux,&auxId)==0)
            	printf("%d",auxId);
            if(entidad_getDesc(pAux,&auxDesc)==0)
            	printf(" %s",auxDesc);
            if(entidad_getPrecio(pAux,&auxPrecio)==0)
            	printf(" %d",auxPrecio);
            if(entidad_getidTipo(pAux,&auxidTipo)==0)
            {
            	if(auxidTipo == 1)
            		printf(" DESKTOP ");
            	else
            		printf(" LAPTOP ");
            }
            if(entidad_getOferta(pAux,&auxOferta)==0)
            	printf(" %s\n",auxOferta);

            /*if(employee_getId(pAux,&auxId)==0)
                printf("%d",auxId);
            if(employee_getNombre(pAux,&auxNom)==0)
                printf(" %s",auxNom);

            if(employee_getHorasTrabajadas(pAux,&auxHs)==0)
                printf(" %d",auxHs);
            if(employee_getSueldo(pAux,&auxSueldo)==0)
                printf(" %d\n",auxSueldo);*/

            retorno = 0;
        }

    }
    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* ArrayEntidad)
{
    int retorno = -1;
    if(ArrayEntidad!=NULL)
    {
        ll_sort(ArrayEntidad,funCritTipo,1);
        retorno = 0;
    }
    return retorno;
}

int controller_Map(LinkedList* ArrayEntidad)
{
    int retorno = -1;
    if(ArrayEntidad!=NULL)
    {
        //ll_sort(ArrayEntidad,funCritTipo,1);
    	ll_map(ArrayEntidad,funCritOferta);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* ArrayEntidad)
{
    int retorno=-1;

    if(ArrayEntidad!=NULL && path!=NULL)
    {
        FILE* pFile;
        Entidad* auxEnt;

        int auxId;
        int auxPrecio;
        int auxidTipo;
        char auxDesc[120];
        char archivo[30];

        pFile=fopen(path,"w+");
        fprintf(pFile,"id,Descripcion,Precio,idTipo\n");

        for(int i=0;i<ll_len(ArrayEntidad);i++)
        {
            auxEnt=(Entidad*)ll_get(ArrayEntidad,i);
        	//auxEnt=ll_get(ArrayEntidad,i);
            auxId = auxEnt->Id;
            strcpy(auxDesc,auxEnt->descripcion);
            auxPrecio = auxEnt->precio;
            auxidTipo = auxEnt->idTipo;

            entidad_getId(auxEnt,&auxId);
            entidad_getDesc(auxEnt,auxDesc);
            entidad_getPrecio(auxEnt,&auxPrecio);
            entidad_getidTipo(auxEnt,&auxidTipo);

           // printf("%d,%s,%d,%d\n",auxId,auxDesc,auxPrecio,auxidTipo);


            /* employee_getId(auxEmp,&auxId);
            employee_getNombre(auxEmp,auxNombre);
            employee_getHorasTrabajadas(auxEmp,&auxHoras);
            employee_getSueldo(auxEmp,&auxSueldo);*/

            fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxDesc,auxPrecio,auxidTipo);
            retorno=0;
        }
        printf("\nArchivo guardado en modo texto correctamente!\n");
        fclose(pFile);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* ArrayEntidad)
{
    /*FILE *pArchivo;
    Employee* pAux;
    int retorno = -1;
    int cant;
    int i;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        if((pArchivo=fopen(path,"w+b"))==NULL)
        {
            printf("El archivo no puede ser abierto");
            retorno=-1;
        }
        else
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pAux=ll_get(pArrayListEmployee,i);
                cant=fwrite(pAux,sizeof(Employee),1,pArchivo);
            }
            retorno = 0;
            fclose(pArchivo);
            printf("\nSe guardo el Archivo en modo BIN correctamente\n");


        }
    }*/
    return 0;
}
