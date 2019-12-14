
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

	if((pArchivo=fopen(path,"r+"))==NULL)
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
    char auxTipoDesc[20];
    if(ArrayEntidad!=NULL)
    {
    	for(i=0;i<ll_len(ArrayEntidad);i++)
        {
            pAux = ll_get(ArrayEntidad,i);
            strcpy(auxDesc,pAux->descripcion);
            strcpy(auxOferta,pAux->oferta);
            entidad_usarGets(pAux,&auxId,&auxDesc,&auxPrecio,&auxidTipo,&auxOferta);
            if(auxidTipo==1)
            	strcpy(auxTipoDesc,"DESKTOP");
            else
            	strcpy(auxTipoDesc,"LAPTOP");
            printf("\n%d %s %d %s %s\n",auxId,auxDesc,auxPrecio,auxTipoDesc,auxOferta);
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
	    FILE *pFile;
		Entidad *aux;
		int id;
		char descrip[100];
		int precio;
		int idTipo;
		char oferta[30];
		int retorno = -1;
		int i;

		pFile = fopen(path, "w+");
		fprintf(pFile, "ID,Descripcion,Precio,Tipo,Oferta\n");
		for (i = 0; i < ll_len(ArrayEntidad); i++) {

			aux = (Entidad*) ll_get(ArrayEntidad, i);
			strcpy(descrip,aux->descripcion);
			entidad_usarGets(aux,&id,descrip,&precio,&idTipo,oferta);
			fprintf(pFile, "%d,%s,%d,%d,%s\n", id, descrip, precio, idTipo,oferta);
			retorno = 0;
		}

		fclose(pFile);

		return retorno;
		return 1;
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
