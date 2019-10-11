#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct
{
    int CliID;
    int IsEmpty;
    //-----------------
    char Nombre[40];
    int cuit;
    char Direccion[80];
    char Localidad[80];

}Cliente;

#endif // CLIENTE_H_INCLUDED


int InicializaCliente(Cliente array[], int size);
int buscaIsEmpty(Cliente array[], int size, int* posicion);
int buscaID(Cliente array[], int size, int valorBuscado, int* posicion);
//int Entidad_buscarInt(Cliente array[], int size, int valorBuscado, int* posicion);
//int Entidad_buscarString(Cliente array[], int size, char* valorBuscado, int* indice);
int altaCliente(Cliente array[], int size, int* contadorID);
int BajaCliente(Cliente array[], int sizeArray);
//int Entidad_bajaValorRepetidoInt(Cliente array[], int sizeArray, int valorBuscado);
int modificaCliente(Cliente array[], int sizeArray);
//int Entidad_ordenarPorString(Cliente array[],int size);
int listaCliente(Cliente array[], int size);



