#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
	LinkedList *this = (LinkedList*) malloc(sizeof(LinkedList));
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this) {
	int returnAux = -1;
	//LinkedList* aux;
	if (this != NULL) {

		returnAux = this->size;
	}
	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex) {
	Node *aux = NULL;
	int i;
	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) {
		aux = this->pFirstNode;
		if (nodeIndex > 0) {
			for (i = 0; i < nodeIndex; i++) {
				aux = aux->pNextNode;
			}
		}

	}

	return aux;

}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {
	return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	Node *new = (Node*) malloc(sizeof(Node));
	new->pElement = pElement;
	Node *aux;
	int returnAux = -1;
	//int i;

	if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {
		if (nodeIndex == 0) {
			if (this->pFirstNode == NULL) {
				this->pFirstNode = new;
				this->size++;
				returnAux = 0;
			} else {

				new->pNextNode = this->pFirstNode;
				this->pFirstNode = new;
				this->size++;
				returnAux = 0;

			}
		}
		if (this != NULL && nodeIndex > 0 && nodeIndex <= ll_len(this)) {
			aux = getNode(this, (nodeIndex - 1));
			new->pNextNode = aux->pNextNode;
			aux->pNextNode = new;
			this->size++;
			returnAux = 0;
		}

	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) {
	int returnAux = -1;
	if (this != NULL) {
		addNode(this, ll_len(this), pElement);
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *paux;

	if (this != NULL && index >= 0 && index < ll_len(this)) {
		paux = getNode(this, index);
		returnAux = paux->pElement;
	}

	return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *paux;

	if (this != NULL && index >= 0 && index < ll_len(this)) {
		paux = getNode(this, index);
		paux->pElement = pElement;
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {

	int returnAux = -1;
	Node *pauxRemove;
	Node *pauxBefore;
	if (this != NULL && index > 0 && index < ll_len(this)) {
		pauxRemove = getNode(this, index);
		pauxBefore = getNode(this, (index - 1));

		pauxBefore->pNextNode = pauxRemove->pNextNode;
		free(pauxRemove);
		this->size--;

		returnAux = 0;
	}
	if (this != NULL && index == 0) {
		pauxRemove = getNode(this, index);
		this->pFirstNode = pauxRemove->pNextNode;
		free(pauxRemove);
		this->size--;
		returnAux = 0;
	}
	if (this != NULL && this->size == 0) {
		this->pFirstNode = NULL;
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {

	int returnAux = -1;
	int i;
	if (this != NULL) {
		for (i = 0; i < ll_len(this); i++) {
			ll_remove(this, 0);
		}
		returnAux = 0;

	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this) {

	int returnAux = -1;

	if (this != NULL) {
		ll_clear(this);
		free(this);
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int i;
	Node *paux;
	int ok = 0;

	if (this != NULL) {
		//paux=this->pFirstNode;
		for (i = 0; i < ll_len(this); i++) {
			paux = getNode(this, i);
			if (paux->pElement == pElement) {
				ok = 1;
				break;
			}
		}
		if (ok == 1) {
			returnAux = i;
		}

	}

	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		if (this->size == NULL) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;

	if (this != NULL && index >= 0 && index <= ll_len(this)) {
		addNode(this, index, pElement);
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *paux;

	if (this != NULL && index >= 0 && index < ll_len(this)) {

		paux = getNode(this, index);
		returnAux = paux->pElement;
		ll_remove(this, index);

	}

	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int ok = -1;

	if (this != NULL) {
		ok = ll_indexOf(this, pElement);
		if (ok != -1) {
			returnAux = 1;
		} else {
			returnAux = 0;
		}

	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList* this,LinkedList* this2) // DUDA
{
    int returnAux = -1;
    int i;
    Node* pNode;

    if(this!=NULL && this2!=NULL)
    {
        returnAux = 1;

        for(i=0;i<ll_len(this2);i++)
        {
          pNode = ll_get(this2,i);

            if(ll_contains(this,pNode)==0 || ll_contains(this,pNode)==1 )
            {
                returnAux = 0;
            }
            else{
            	returnAux = 1;
            }

        }
    }


    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	int i;

	if(this!=NULL&&from>=0&&from<=ll_len(this)&&to>from&&to<=ll_len(this))
	{
		cloneArray = ll_newLinkedList();
		for(i=from;i<=to;i++)
		{
			ll_add(cloneArray,ll_get(this,i));

		}


	}

	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;
	int i;

	if(this!=NULL)
	{
		cloneArray=ll_newLinkedList();
		for(i=0;i<=ll_len(this);i++)
		{
			ll_add(cloneArray,ll_get(this,i));
		}
	}

	return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    void* p1 = NULL;
    void* p2 = NULL;
    void* aux = NULL;

    int i , j;

if(this!=NULL && pFunc !=NULL &&  (order == 0 || order == 1) )

    {


        for(i=0 ; i < ll_len(this)-1;i++)
           {
              p1 = ll_get(this,i);


              for(j=i+1; j < ll_len(this);j++)
              {
                  p2 = ll_get(this,j);


                  if(order == 1)
                  {
                      if((*pFunc)(p1,p2)== 1)
                      {
                          aux = p1;
                          p1 = p2;
                          p2 = aux;
                      }
                  }

                  else if(order==0)
                  {
                      if( (*pFunc)(p1,p2)== -1)
                     {
                       aux = p2;
                       p2 = p1;
                       p1 = aux;
                     }
                  }

                  ll_set(this,i,p1);
                  ll_set(this,j,p2);
              }

              returnAux = 0;

           }


    }




    return returnAux;

}
LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void *element)) {
	void *pElement;
	LinkedList *aux;
	aux = ll_newLinkedList();
	int i;
	for (i = 0; i < ll_len(this); i++) {
		pElement = ll_get(this, i);
		if (pFunc(pElement) == 1) {

			ll_add(aux, pElement);
		}

	}
	return aux;
}
