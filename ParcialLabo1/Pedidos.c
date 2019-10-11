#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"
#include "Pedidos.h"

int InicializaPedido(Pedido array[], int size)
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

int buscaPedido(Pedido array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
                continue;
            else if(array[i].PedID==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}



int buscaLugar(Pedido array[], int size, int* posicion)
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

int crearPedido(Pedido array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
   // int id;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        //id = *contadorID;
        if(buscaLugar(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {

            array[posicion].PedID=*contadorID;                                                       //campo ID
            array[posicion].IsEmpty=0;
            printf("\nIngrese el ID del Cliente:  ");
            //fgets(array[posicion].Nombre);
            scanf("%d",&array[posicion].CliID);

            printf("\nIngrese la cantidad del pedido: ");
            //fgets(array[posicion].cuit);
            scanf("%d",&array[posicion].cantidad);
            strcpy(array[posicion].Pedsts,"PENDIENTE");

            (*contadorID)++;
            retorno=0;
        }
    }
    printf("\nSe dio de alta correctamente!");
    return retorno;
}

int listaPedidos(Pedido array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        printf("\n \tPed.NRO        CliID        Estado del PEDIDO       Cantidad ");

        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
                continue;
            else
                printf("\n\t   %d       %d       %s       %d",
                       array[i].PedID,array[i].CliID,array[i].Pedsts,array[i].cantidad);
        }
        retorno=0;
    }
    return retorno;
}




int procesarPedido(Pedido array[],int size,int* contadorID)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
       // if(buscaIsEmpty(array,size,&posicion)==-1)
       // {
       //     printf("\nNo hay lugares vacios");
       // }
        //else
        //{
        id = *contadorID;
        if(buscaPedido(array,size,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            printf("\nTipo de plastico HDPE, cantidad:  ");
            //fgets(&array[posicion].Nombre);
            scanf("%d",&array[posicion].HDPE);

             printf("\nTipo de plastico LDPE, cantidad:  ");
            //fgets(array[posicion].cuit);
            scanf("%d",&array[posicion].LDPE);

            printf("\nTipo de plastico PP, cantidad:  ");
            scanf("%d",&array[posicion].PP);

            strcpy(array[posicion].Pedsts,"PROCESADO");


            retorno=0;

        }



    }
    printf("\nSe proceso correctamente!");
    return retorno;
}



int listarPedidosClientes(Pedido array[],Cliente arraycli[],int size)
{
    int retorno=-1;
    int i;
    int j;
    int cantidadped = 0;
    char pedido[] = {"PENDIENTE"};
    if(array!=NULL && arraycli!=NULL && size>=0)
    {
       // printf("\n Ped.NRO    CliID    Estado del PEDIDO   Cantidad ");
        printf("\n  \tPedido    ID Cliente       Nombre      cuit    Direccion     Localidad      Estado del PEDIDO  cantidad pedidos");
        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
                continue;
            else
            {
                if(strcmp(array[i].Pedsts,pedido)==0)
                {
                       cantidadped = cantidadped + 1;
                        for(j=0;j<size;j++)
                        {
                             if(array[j].IsEmpty==1)
                                continue;
                            else
                            {
                                printf("\n    \t%d        %d         %s         %d        %s          %s          %s",
                                   array[i].PedID,arraycli[j].CliID,arraycli[j].Nombre,arraycli[j].cuit,arraycli[j].Direccion,arraycli[j].Localidad,array[i].Pedsts,cantidadped);
                            }

                        }


                    }

                }
            }

        }
        retorno=0;

    return retorno;
}
//////////////////////////////////
int listarPedidosClientesPendientes(Pedido array[],Cliente arraycli[],int size)
{
    int retorno=-1;
    int i;
    int j;
    char pedido[] = {"PENDIENTE"};
    if(array!=NULL && arraycli!=NULL && size>=0)
    {
       // printf("\n Ped.NRO    CliID    Estado del PEDIDO   Cantidad ");
        printf("\n  \tPedido    ID Cliente    cuit     Direccion       cantidad a recolectar        Estado del PEDIDO");
        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
                continue;
            else
            {
                if(strcmp(array[i].Pedsts,pedido)==0)
                {

                        for(j=0;j<size;j++)
                        {
                             if(array[j].IsEmpty==1)
                                continue;
                            else
                            {
                                printf("\n    \t%d         %d           %d          %s         %d                %s",
                                   array[i].PedID,arraycli[j].CliID,arraycli[j].cuit,arraycli[j].Direccion,array[i].cantidad,array[i].Pedsts);
                            }

                        }


                    }

                }
            }

        }
        retorno=0;

    return retorno;
}

int listarPedidosClientesProcesados(Pedido array[],Cliente arraycli[],int size)
{
    int retorno=-1;
    int i;
    int j;
    char pedido[] = {"PROCESADO"};
    if(array!=NULL && arraycli!=NULL && size>=0)
    {
       // printf("\n Ped.NRO    CliID    Estado del PEDIDO   Cantidad ");
        printf("\n  ID Cliente    cuit      cantidad de HDPE        cantidad de LDPE     cantidad de PP      Estado del PEDIDO");
        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
                continue;
            else
            {
                if(strcmp(array[i].Pedsts,pedido)==0)
                {

                        for(j=0;j<size;j++)
                        {
                             if(array[j].IsEmpty==1)
                                continue;
                            else
                            {
                                printf("\n    \t%d         %d          %d           %d         %d         %s",
                                   arraycli[j].CliID,arraycli[j].cuit,array[i].HDPE,array[i].LDPE,array[i].PP,array[i].Pedsts);
                            }

                        }


                    }

                }
            }

        }
        retorno=0;

    return retorno;
}
