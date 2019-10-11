#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

typedef struct
{
    int PedID;
    int IsEmpty;
    //-----------------
    int CliID;
    char Pedsts[20];
    int HDPE;
    int LDPE;
    int PP;
    int cantidad;
}Pedido;

#endif // PEDIDOS_H_INCLUDED

int InicializaPedido(Pedido array[], int size);
int buscaLugar(Pedido array[], int size, int* posicion);
//int buscaID(Cliente array[], int size, int valorBuscado, int* posicion);
//int Entidad_buscarInt(Cliente array[], int size, int valorBuscado, int* posicion);
//int Entidad_buscarString(Cliente array[], int size, char* valorBuscado, int* indice);
int crearPedido(Pedido array[], int size, int* contadorID);
int procesarPedido(Pedido array[],int size,int* contadorID);
int buscaPedido(Pedido array[], int size, int valorBuscado, int* posicion);

//int BajaCliente(Cliente array[], int sizeArray);
//int Entidad_bajaValorRepetidoInt(Cliente array[], int sizeArray, int valorBuscado);
//int modificaCliente(Cliente array[], int sizeArray);
//int Entidad_ordenarPorString(Cliente array[],int size);
int listaPedidos(Pedido array[], int size);
int listarPedidosClientes(Pedido array[],Cliente arraycli[],int size);
int listarPedidosClientesPendientes(Pedido array[],Cliente arraycli[],int size);
int listarPedidosClientesProcesados(Pedido array[],Cliente arraycli[],int size);
