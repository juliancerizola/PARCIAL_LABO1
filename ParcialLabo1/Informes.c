#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"
#include "Pedidos.h"
#include "Informes.h"


/*int clienteMaxPedidosPendientes(Pedido array[],Cliente arraycli[],int size)
{
    int retorno=-1;
    int i;
    int j;
    int cantidadped = 0;
    char pedido[] = {"PENDIENTE"};
    if(array!=NULL && arraycli!=NULL && size>=0)
    {
       // printf("\n Ped.NRO    CliID    Estado del PEDIDO   Cantidad ");
       // printf("\n  \tPedido    ID Cliente       Nombre      cuit    Direccion     Localidad      Estado del PEDIDO  cantidad pedidos");
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
}*/

int calculaCantPedCli(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    int id;
    int i;
    int posicion;
    char pedido[] = {"PENDIENTE"};
    int auxCli = 0;
    int auxPed = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {
       printf("\nIngrese el ID del Cliente: ");
       scanf("%d",&id);
       if(buscaID(arraycli,size,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            for(i=0;i<size;i++)
            {
                if(array[i].CliID == id && strcmp(array[i].Pedsts,pedido)==0)
                {
                  //auxCli = array[i].CliID;
                  auxPed = auxPed + 1;

                }

                //if(strcmp(array[i].Pedsts,pedido)==0 )

            }
        }

            printf("\nEl cliente tiene : %d",auxPed);

            retorno=0;

    }
      //retorno=0;
    return retorno;
}

int clienteMaxPedidosPendientes(Pedido array[],Cliente arraycli[],int size)

{
    int retorno = -1;
    int cantidadpedidos = 0;
    int id;
    int i;
    int posicion;
    char pedido[] = {"PENDIENTE"};
    int auxCli = 0;
    int auxCantidad = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
           if(strcmp(array[i].Pedsts,pedido)==0)
           {
               auxCantidad = auxCantidad + 1;
           }



        }
        printf("\nHay %d",auxCantidad);
        retorno=0;
    }
      //retorno=0;
    return retorno;
}

int clienteMaxKilos(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    int cantidadpedidos = 0;
    int id;
    int i;
    int posicion;
    char pedido[] = {"PENDIENTE"};
    int auxCli;
    int maxKilos = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].cantidad > maxKilos)
            {
                maxKilos = array[i].cantidad;
                auxCli = array[i].CliID;
            }

        }
        printf("\nEl cliente con mas kilos es: %d y la cantidad mayor fue: %d",auxCli,maxKilos);
        retorno=0;



    }
      //retorno=0;
    return retorno;
}

int clienteMinKilos(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    int cantidadpedidos = 0;

    int i;

    int auxCli;
    int minKilos = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            minKilos = array[i].cantidad;
            if(array[i].cantidad < minKilos)
            {
                minKilos = array[i].cantidad;
                auxCli = array[i].CliID;
            }

        }
          printf("\nEl cliente con menos kilos es: %d y la cantidad menor fue: %d",auxCli,minKilos);
        retorno=0;



    }
      //retorno=0;
    return retorno;
}

int clienteMaxReciclo(Pedido array[],Cliente arraycli[],int size)
{

     int retorno = -1;
    int cantidadpedidos = 0;
    int i;
    int maxReciclo = 1000;
    int contar = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {


        for(i=0;i<size;i++)
        {
                if(array[i].cantidad > maxReciclo)
            {
                contar = contar + 1;
            }
        }
        printf("\nLa cantidad de clientes mayores a 1000 son: %d",contar);
        retorno=0;


    }
      //retorno=0;
    return retorno;



}

int clienteMinReciclo(Pedido array[],Cliente arraycli[],int size)
{

    int retorno = -1;
    int cantidadpedidos = 0;
    int i;
    int minReciclo = 100;
    int contar = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {


        for(i=0;i<size;i++)
        {
                if(array[i].cantidad < minReciclo)
            {
                contar = contar + 1;
            }
        }
        printf("\nLa cantidad de clientes menores a 100 son: %d",contar);
        retorno=0;


    }
      //retorno=0;
    return retorno;

}

int pedidosProcesados(Pedido array[],Cliente arraycli[],int size)
{
    int retorno=-1;
    int i;
    int j;
    char pedido[] = {"PROCESADO"};
    if(array!=NULL && arraycli!=NULL && size>=0)
    {
       // printf("\n Ped.NRO    CliID    Estado del PEDIDO   Cantidad ");
        printf("\nID PEDIDO\t CUIT\t CANTIDADTOTAL\t");
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
                                printf("\n%d\t %d\t %d",
                                   array[i].PedID,arraycli[j].cuit,array[i].cantidad);
                            }

                        }


                    }

                }
            }

        }
        retorno=0;

    return retorno;
}

int localidadPedidos(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    char localidadaux[30];
    int i;
    int j;
    char pedido[] = {"PENDIENTE"};
    int contarpedidos = 0;


    if(array!=NULL && arraycli!=NULL && size>=0)
    {
       printf("\nIngrese una localidad: ");
       scanf("%s",localidadaux);

            for(i=0;i<size;i++)
            {
                if(strcmp(arraycli[i].Localidad,localidadaux)==0)
                {
                    for(j=0;j<size;j++)
                    {
                        if(strcmp(array[j].Pedsts,pedido)==0)
                        {
                            contarpedidos = contarpedidos + 1;
                        }

                    }

                }

            }
        }

            printf("\nLa localidad tiene %d pedidos en estado PENDIENTE",contarpedidos);

            retorno=0;
            return retorno;

    }

    int localidadPedidos(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    //char localidadaux[30];
    int i;
    if(array!=NULL && arraycli!=NULL && size>=0)
    {





    }

           // printf("\nLa localidad tiene %d pedidos en estado PENDIENTE",contarpedidos);

            retorno=0;
            return retorno;

    }





