#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"
#include "Pedidos.h"
//#include "Entidad.h"

#define cantidad 3

int main(void)
{
	int opcion;
	int IDcontador = 1;
	int IDpedido = 1;
	int insert=0;
	int opciondos;

	Cliente arrayCliente[cantidad];
	InicializaCliente(arrayCliente,cantidad);

	Pedido arrayPedido[cantidad];
	InicializaPedido(arrayPedido,cantidad);

	printf("****BIENVENIDO AL SISTEMA*****");
	//printf("\n\n****** ABM DE  *****");
	do
	    {
            printf("\n");
	        printf("\n\n1- ALTA DE CLIENTE");
            printf("\n2- BAJA DE CLIENTE ");
            printf("\n3- MODIFICAR CLIENTE ");
            printf("\n5- CREAR PEDIDO ");
            printf("\n6- PROCESAR PEDIDO ");
            printf("\n7- IMPRIMIR CLIENTES ");
            printf("\n8- IMPRIMIR PEDIDOS PENDIENTES ");
            printf("\n9- IMPRIMIR PEDIDOS PROCESADOS ");
            printf("\n10- SALIR ");
	        printf("\n\nIngrese una opcion: ");
            scanf("%d",&opcion);
	        switch(opcion)
	        {
	            case 1:
                    insert = 1;
	            	altaCliente(arrayCliente,cantidad,&IDcontador);
	                break;
                case 2:
                    if(insert==1)
                    {
                     BajaCliente(arrayCliente,cantidad);
                    }
                    else{
                        msgError();
                        }
	                break;
                case 3:
                     if(insert==1)
                    {
                      modificaCliente(arrayCliente,cantidad);
                    }
                   else{
                       msgError();
                        }
	                break;
                case 4:
                    if(insert==1)
                    {
                     listaCliente(arrayCliente,cantidad);
                    }
                    else{
                        msgError();
                        }
	                break;

                case 5:
                     if(insert==1)
                    {

                      crearPedido(arrayPedido,cantidad,&IDpedido);
                    }
                     else
                     {
                        msgError();
                      }
	                break;
	            case 6:
	                 if(insert==1)
                    {
                        listaPedidos(arrayPedido,cantidad);
                        printf("\nElija un ID de Pedido: ");
                        scanf("%d",&opciondos);
                        if(opciondos!= NULL)
                        {
                            procesarPedido(arrayPedido,cantidad,&opciondos);
                            break;
                        }
                        else
                        {
                            opcion = 10;
                        }

                    }
                     else
                     {
                        msgError();
                        break;
                      }

                case 7:
	                 if(insert==1)
                    {

                      listarPedidosClientes(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;

	             case 8:
	                 if(insert==1)
                    {

                      listarPedidosClientesPendientes(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;


                case 9:
	                 if(insert==1)
                    {

                      listarPedidosClientesProcesados(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;

                case 10:
	                printf("\nFin del Programa");
	        }
	    }while(opcion!=10);
	    return 0;

}
