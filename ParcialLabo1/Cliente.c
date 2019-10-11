#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array Cliente Array of Cliente
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int InicializaCliente(Cliente array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].IsEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array Cliente Array de Cliente
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int buscaIsEmpty(Cliente array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Entidad Array de Entidad
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int buscaID(Cliente array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
                continue;
            else if(array[i].CliID==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Entidad Array de Entidad
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int altaCliente(Cliente array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(buscaIsEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {

            array[posicion].CliID=*contadorID;                                                       //campo ID
            array[posicion].IsEmpty=0;
            printf("\n\nIngrese un nombre: ");
            //fgets(array[posicion].Nombre);
            scanf("%s",&array[posicion].Nombre);

            printf("\nIngrese el CUIT: ");
            //fgets(array[posicion].cuit);
            scanf("%d",&array[posicion].cuit);

            printf("\nIngrese una Direccion: ");
            //fgets(array[posicion].Direccion)
            scanf("%s",&array[posicion].Direccion);

            printf("\nIngrese una localidad: ");
            //fgets(array[posicion].Localidad);
            scanf("%s",&array[posicion].Localidad);

            (*contadorID)++;
            retorno=0;
        }
    }
    printf("\nSe dio de alta correctamente!");
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Entidad Array de Entidad
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int BajaCliente(Cliente array[], int sizeArray)
{
    int retorno=-1;
    int opcion;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        printf("\nIngrese el ID para dar de baja: ");
        scanf("%d",&id);
        //utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(buscaID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
           printf("\nDesea dar de baja este cliente?: 1->SI 0-> NO");
           scanf("%d",&opcion);
           if(opcion==1)
           {
            array[posicion].IsEmpty=1;
            array[posicion].CliID=0;
            array[posicion].cuit=0;                                                                    //cambiar campo id                                                            //cambiar campo varFloat
            strcpy(array[posicion].Nombre,"");                                                   //cambiar campo varString

            strcpy(array[posicion].Direccion,"");
            strcpy(array[posicion].Localidad,"");                                               //cambiar campo varLongString
            retorno=0;
           }

        }
    }
    printf("\nSe dio de baja correctamente!");
    return retorno;
}


//****************************Entidad*************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Entidad Array de Entidad
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int modificaCliente(Cliente array[], int sizeArray)
{
    int retorno=-1;
    int opcion;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
   // char opcion;
    if(array!=NULL && sizeArray>0)
    {
        printf("\nIngrese el ID para dar de baja: ");
        scanf("%d",&id);
        //utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(buscaID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {    printf("\n Posicion: %d\n ID: %d\n 1 - Nombre: %s\n 2 - cuit: %d\n 3 - Direccion: %s\n 4 - Localidad: %s \n 5 - Salir",
                       posicion, array[posicion].CliID,array[posicion].Nombre,array[posicion].cuit,array[posicion].Direccion,array[posicion].Localidad);
                printf("\n\nElija la opcion a modificar: ");
                scanf("%d",&opcion);
                switch(opcion)
                {
                    case 1:
                         utn_getName("\nIngrese Nombre nuevo: ","\nError",1,30,1,array[posicion].Nombre);
                        break;
                    case 2:
                        utn_getCUIT("\nIngrese CUIT nuevo: ","\nError",3,array[posicion].cuit);
                        break;
                    case 3:
                        utn_getName("\nIngrese Direccion nuevo: ","\nError",1,30,1,array[posicion].Direccion);
                        break;
                    case 4:
                        utn_getName("\nIngrese Localidad nuevo: ","\nError",1,30,1,array[posicion].Localidad);
                        break;
                    case 5:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!= 5);
            retorno=0;
        }
    }
    return retorno;
}


//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Entidad Array de Entidad
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int listaCliente(Cliente array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
                continue;
            else
                printf("\n ID: %d\n Nombre: %s\n CUIT: %d\n Direccion: %s \n Localidad: %s",
                       array[i].CliID,array[i].Nombre,array[i].cuit,array[i].Direccion,array[i].Localidad);
        }
        retorno=0;
    }
    return retorno;
}
