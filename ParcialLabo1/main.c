#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"
#include "Pedidos.h"
#include "Informes.h"
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
            printf("\n--------------------------------");
            printf("\n\nINFORMES:");
            printf("\n\n10- CLIENTE CON MAS PEDIDOS PENDIENTES");
            printf("\n11- CLIENTE CON MAS PEDIDOS COMPLETADOS");
            printf("\n12- CLIENTE CON MAS PEDIDOS");
            printf("\n13- CLIENTE QUE RECICLO MAS KILOS");
            printf("\n14- CLIENTE QUE RECICLO MENOS KILOS");
            printf("\n15- CANTIDAD DE CLIENTES QUE RECICLARON MAS DE 1000 KG");
            printf("\n16- CANTIDAD DE CLIENTES QUE RECICLARON MENOS DE 100 KG");
            printf("\n17- IMPRIMIR PEDIDOS COMPLETADOS");
            printf("\n18- IMPRIMIR LOCALIDAD CON CANTIDAD DE PEDIDOS PENDIENTES");
            printf("\n19- IMPRIMIR PROMEDIO");
            printf("\n20- IMPRIMIR TOTALES DE LOS TOPOS DE PLASTICO");
            printf("\n21- SALIR ");
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
                            opcion = 21;
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
	                 if(insert==1)
                    {

                       clienteMaxPedidosPendientes(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;


                case 11:
	                 if(insert==1)
                    {

                       clienteMaxPedidosCompletados(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;




                case 13:
	                 if(insert==1)
                    {

                       clienteMaxKilos(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;

	            case 14:
	                 if(insert==1)
                    {

                       clienteMinKilos(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;

                 case 15:
	                 if(insert==1)
                    {

                       clienteMaxReciclo(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;
                case 16:
	                 if(insert==1)
                    {

                       clienteMinReciclo(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;
                 case 17:
	                 if(insert==1)
                    {

                       pedidosProcesados(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;
                case 18:
	                 if(insert==1)
                    {

                       localidadPedidos(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;
                 case 19:
	                 if(insert==1)
                    {

                       totalClientes(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;

                case 20:
	                 if(insert==1)
                    {

                       cantidadKilosTotales(arrayPedido,arrayCliente,cantidad);
                    }
                     else
                     {
                        msgError();
                      }
	                break;
                case 21:
	                printf("\nFin del Programa");
	        }
	    }while(opcion!=21);
	    return 0;

}
