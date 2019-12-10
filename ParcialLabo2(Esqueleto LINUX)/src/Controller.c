
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
int controller_loadFromText(char* path , LinkedList* Entidad)
{

	FILE *pArchivo;
	int retorno=0;

	if((pArchivo=fopen(path,"r"))==NULL)
	{
		printf("El archivo no puede ser abierto");
		retorno=-1;
	}
	//parser_EmployeeFromText(pArchivo,Entidad);
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
int controller_loadFromBinary(char* path , LinkedList* Entidad)
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
int controller_addEmployee(LinkedList* Entidad)
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
int controller_editEmployee(LinkedList* Entidad)
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
int controller_removeEmployee(LinkedList* Entidad)
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
int controller_ListEmployee(LinkedList* Entidad)
{
    /*Employee* pAux;
    int retorno=-1;
    int i;
    int auxId;
    char auxNom[128];
    int auxHs;
    int auxSueldo;
    if(pArrayListEmployee!=NULL)
    {
         for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pAux = ll_get(pArrayListEmployee,i);
            auxId = pAux->id;
            strcpy(auxNom,pAux->nombre);
            auxHs = pAux->horasTrabajadas;
            auxSueldo = pAux->sueldo;

            if(employee_getId(pAux,&auxId)==0)
                printf("%d",auxId);
            if(employee_getNombre(pAux,&auxNom)==0)
                printf(" %s",auxNom);

            if(employee_getHorasTrabajadas(pAux,&auxHs)==0)
                printf(" %d",auxHs);
            if(employee_getSueldo(pAux,&auxSueldo)==0)
                printf(" %d\n",auxSueldo);

            retorno = 0;
        }

    }*/
    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* Entidad)
{
    int retorno = -1;
    /*if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,funcioncriterio,1);
        retorno = 0;
    }*/
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* Entidad)
{
    int retorno=-1;

   /* if(pArrayListEmployee!=NULL && path!=NULL)
    {
        FILE* pFile;
        Employee* auxEmp;

        int auxId;
        int auxHoras;
        int auxSueldo;
        char auxNombre[120];

        pFile=fopen(path,"w");
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmp=(Employee*)ll_get(pArrayListEmployee,i);

            employee_getId(auxEmp,&auxId);
            employee_getNombre(auxEmp,auxNombre);
            employee_getHorasTrabajadas(auxEmp,&auxHoras);
            employee_getSueldo(auxEmp,&auxSueldo);

            fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
        }
        printf("\nArchivo guardado en modo texto correctamente!\n");
        retorno=0;
        fclose(pFile);
    }*/
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* Entidad)
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
