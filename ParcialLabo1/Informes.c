#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"
#include "Pedidos.h"
#include "Informes.h"




int cantPedPendientes(Pedido array[],Cliente arraycli[],int size,int Cliente,int *max)
{

	int retorno = -1;
	int i;
	int contar = 0;

	char pedidosts[] = {"PENDIENTE"};

	if(array!= NULL && arraycli != NULL && size>0)
	{
		for(i=0;i<size;i++)
		{
			if(strcmp(array[i].Pedsts,pedidosts)==0 && array[i].CliID==Cliente)
			{
			   contar += 1;
			}
		}
		*max=contar;
		retorno=0;
		//break;
	}
	return retorno;
}

int cantPedCompletados(Pedido array[],Cliente arraycli[],int size,int Cliente,int *max)
{

	int retorno = -1;
	int i;
	int contar = 0;

	char pedidosts[] = {"PROCESADO"};

	if(array!= NULL && arraycli != NULL && size>0)
	{
		for(i=0;i<size;i++)
		{
			if(strcmp(array[i].Pedsts,pedidosts)==0 && array[i].CliID==Cliente)
			{
			   contar += 1;
			}
		}
		*max=contar;
		retorno=0;
		//break;
	}
	return retorno;
}




int clienteMaxPedidos(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    int i,j;
    int auxCliID;
    int contMax = 0;
    int mayor = 0;
    int idMax = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            auxCliID = arraycli[i].CliID;
            for(j=0;j<size;j++)
            {
                if(array[j].CliID == auxCliID)
                {
                    contMax = contMax + 1;
                }

            }
            if(contMax>mayor)
            {
                mayor = contMax;
                idMax = auxCliID;
            }

        }
        retorno = 0;
        printf("\nEl ID con mas pedidos pendientes es: %d",idMax);


    }

      //retorno=0;
    return retorno;
}





int clienteMaxPedidosPendientes(Pedido array[],Cliente arraycli[],int size)
{
   	int retorno = -1;
    int i,j;
    int auxCliID;
	int maxResult = 0;
	int mayor=0;
	int CliId;



    	if(array!=NULL && arraycli!=NULL && size>=0)
    	{
        	for(i=0;i<size;i++)
        	{
            		auxCliID = arraycli[i].CliID;
			cantPedPendientes(array,arraycli,size,arraycli[i].CliID,&maxResult);
			if(maxResult>mayor)
			{
				mayor = maxResult;
				CliId = arraycli[i].CliID;
				retorno = 0;
			}
	        }
	}
	if(retorno == 0 && CliId != NULL)
	{
		printf("\nEl cliente con mas pedidos PENDIENTES es: %d",CliId);
	}

     	    return retorno;
}



int clienteMaxPedidosCompletados(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    int i,j;
    int auxCliID;
	int maxResult = 0;
	int mayor=0;
	int CliId;

    if(array!=NULL && arraycli!=NULL && size>=0)
    	{
        	for(i=0;i<size;i++)
        	{
            auxCliID = arraycli[i].CliID;
			cantPedPendientes(array,arraycli,size,arraycli[i].CliID,&maxResult);
			if(maxResult>mayor)
			{
				mayor = maxResult;
				CliId = arraycli[i].CliID;
				retorno = 0;
			}
	        }
	}
	if(retorno == 0 && CliId != NULL)
	{
		printf("\nEl cliente con mas pedidos PENDIENTES es: %d",CliId);
	}

      //retorno=0;
    return retorno;
}




int clienteMaxKilos(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    int i;
    char pedido[] = {"PROCESADO"};
    int auxCli;
    int maxKilos = 0;
    int sumaCantidad = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
                continue;
          else if(strcmp(array[i].Pedsts,pedido)==0)
            {
                sumaCantidad += array[i].HDPE + array[i].LDPE + array[i].PP;
                if(sumaCantidad > maxKilos)
                {
                    maxKilos = sumaCantidad;
                    auxCli = array[i].CliID;
                }
            }

        }
        printf("\nEl cliente con mas kilos es: %d y la cantidad mayor fue: %d",auxCli,maxKilos);
        sumaCantidad = 0;
        retorno=0;
    }
      //retorno=0;
    return retorno;
}

int clienteMinKilos(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    char pedido[] = {"PROCESADO"};
    int i;
    int auxCli;
    int minKilos;
    int minCantidad;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
                continue;
          else if(strcmp(array[i].Pedsts,pedido)==0)
            {
                minCantidad += array[i].HDPE + array[i].LDPE + array[i].PP;
                if(minCantidad < minKilos)
                {
                    minKilos = minCantidad;
                    auxCli = array[i].CliID;
                }
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
    char pedido[] = {"PROCESADO"};
    int i;
    int maxReciclo = 1000;
    int contar = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {

        for(i=0;i<size;i++)
        {
            if(array[i].IsEmpty==1)
                continue;
           else if(strcmp(array[i].Pedsts,pedido)==0)
            {
                if(array[i].cantidad > maxReciclo)
                {
                    contar = contar + 1;
                }
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
    int i;
    int minReciclo = 100;
    int contar = 0;
    char pedido[] = {"PROCESADO"};


    if(array!=NULL && arraycli!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
             if(array[i].IsEmpty==1)
                continue;
           else if(strcmp(array[i].Pedsts,pedido)==0)
            {
                if(array[i].cantidad > minReciclo)
                {
                    contar = contar + 1;

                }
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
                             if(arraycli[j].IsEmpty==1)
                                continue;
                            else
                            {
                                printf("\nNum.Pedido: %d\nCUIT del Cliente: %d\nCantidad Total: %d",
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
                else{
                    printf("\nNo existe esa localidad!");

                }

            }
        }

            printf("\nLa localidad tiene %d pedidos en estado PENDIENTE",contarpedidos);

            retorno=0;
            return retorno;

    }

int totalClientes(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    //char localidadaux[30];
    int i;
    int sumCantidad = 0;
    int cantidadClientes = 0;
    int total = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {

            if(array[i].IsEmpty==1)
                continue;
            else
            {
                 sumCantidad+=array[i].cantidad;
                 cantidadClientes = cantidadClientes + 1;

            }

        }

        total = sumCantidad/cantidadClientes;

    }

           printf("\nPromedio total: %d",total);
            retorno=0;
            return retorno;

}

int cantidadKilosTotales(Pedido array[],Cliente arraycli[],int size)
{
    int retorno = -1;
    int cuitingresado = 0;
    int i;
    int j;    //int tipoplastico;
    int idCliente;
    int totalKilos = 0;

    if(array!=NULL && arraycli!=NULL && size>=0)
    {
       //printf("\n1-Tipo de plastico HDPE");
       //printf("\n2-Tipo de plastico LDPE");
       //printf("\n3-Tipo de plastico PP");
       //printf("\n4-Elija un tipo de Plastico: ");
       //scanf("%d",&tipoplastico);
        printf("\nIngrese un CUIT: ");
        scanf("%d",&cuitingresado);

            for(i=0;i<size;i++)
            {
                if(arraycli[i].IsEmpty==1)
                    continue;
               else if(arraycli[i].cuit==cuitingresado)
                {
                     idCliente = arraycli[i].CliID;
                    for(j=0;j<size;j++)
                    {
                        if(array[j].CliID == idCliente)
                        {
                            //contarpedidos = contarpedidos + 1;
                            totalKilos += array[j].HDPE + array[j].LDPE + array[j].PP;
                            retorno=0;

                        }

                    }

                }
                else
                {
                    printf("\nEste cuit no existe!");
                    retorno = -1;

                }

            }
        }

         if(retorno == 0)
            {
                printf("\nEl total de kilos ingresados por el CUIT son: %d",totalKilos);

            }
        return retorno;

 }








