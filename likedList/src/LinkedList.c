#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}


int ll_len(LinkedList* this)
{
    int toReturn = -1;

    if(this != NULL)
    {
    	toReturn = this->size;
    }

    return toReturn;
}



static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;

	int i;
	int len;

	if(this != NULL && nodeIndex >= 0)
	{
		len = ll_len(this);

		if(nodeIndex < len)
		{
			pNode = this->pFirstNode;

			for(i = 0; i < nodeIndex; i++)
			{
				pNode = pNode->pNextNode;
			}
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}



static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int toReturn = -1;

    int len;

    Node* pNewNode;
    Node* pLastNode;

    if(this != NULL && nodeIndex >= 0)
    {
    	len = ll_len(this);

    	if(nodeIndex <= len)
    	{
    		pNewNode = (Node*) malloc(sizeof(Node));

    		if(pNewNode != NULL)
    		{
    			pNewNode->pElement = pElement;

    			if(nodeIndex == 0)
    			{
    				pNewNode->pNextNode = this->pFirstNode;
    				this->pFirstNode = pNewNode;
    			}
    			else
    			{
    				pLastNode = getNode(this, nodeIndex - 1);

    				if(pLastNode != NULL)
    				{
    					pNewNode->pNextNode = pLastNode->pNextNode;
    					pLastNode->pNextNode = pNewNode;
    				}
    			}
    			this->size++;

    			toReturn = 0;
    		}
    	}
    }


    return toReturn;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    int toReturn = -1;

    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	toReturn = addNode(this, len, pElement);

    }

    return toReturn;
}

void* ll_get(LinkedList* this, int index)
{
    void* toReturn = NULL;

    int len;

    Node* pNode;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(len > 0 && index < len)
    	{
    		pNode = getNode(this, index);

    		if(pNode != NULL)
    		{
    			toReturn = pNode->pElement;
    		}
    	}
    }

    return toReturn;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int toReturn = -1;

    int len;

    Node* pNode;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(len > 0 && index < len)
    	{
    		pNode = getNode(this, index);

    		if(pNode != NULL)
    		{
    			pNode->pElement = pElement;

    			toReturn = 0;
    		}
    	}
    }

    return toReturn;
}

int ll_remove(LinkedList* this,int index)
{
    int toReturn = -1;

    int len;

    Node* pNode;
    Node* pAuxNode;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(len > 0 && index < len)
    	{
    		pNode = getNode(this, index);

    		if(pNode != NULL)
    		{
    			if(index == 0)
    			{
    				this->pFirstNode = pNode->pNextNode;
    			}
    			else
    			{
    				pAuxNode = getNode(this, index - 1);

    				pAuxNode->pNextNode = pNode->pNextNode;
    			}

    			free(pNode);
    			this->size--;

    			toReturn = 0;
    		}
    	}
    }


    return toReturn;
}

int ll_clear(LinkedList* this)
{
    int toReturn = -1;

    int i;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len > 0)
    	{
    		for(i = len - 1; i >= 0; i--)
			{
				if(ll_remove(this, i))
				{
					break;
				}
			}

			if(i == -1)
			{
				this->pFirstNode = NULL;
				this->size = 0;

				toReturn = 0;
			}
    	}
    }

    return toReturn;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int toReturn = -1;

    if(this != NULL && !ll_clear(this))
    {
    	free(this);

    	toReturn = 0;
    }

    return toReturn;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int toReturn = -1;

    int i;
    int len;

    void* pAux;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len > 0)
    	{
    		for(i = 0; i < len; i++)
			{
				pAux = ll_get(this, i);

				if(pAux == pElement)
				{
					toReturn = i;
					break;
				}
			}
    	}
    }

    return toReturn;
}


int ll_isEmpty(LinkedList* this)
{
    int toReturn = -1;

    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	if(len == 0)
    	{
    		toReturn = 1;
    	}
    	else
    	{
    		toReturn = 0;
    	}
    }

    return toReturn;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int toReturn = -1;

    int len;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(index <= len)
    	{
    		toReturn = addNode(this, index, pElement);
    	}
    }

    return toReturn;
}

void* ll_pop(LinkedList* this,int index)
{
    void* toReturn = NULL;

    int len;

    if(this != NULL && index >= 0)
    {
    	len = ll_len(this);

    	if(len > 0 && index < len)
    	{
    		toReturn = ll_get(this, index);

    		if(toReturn != NULL && ll_remove(this, index))
    		{
    			toReturn = NULL;
    		}
    	}
    }

    return toReturn;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int toReturn = -1;

    int index;

    if(this != NULL)
    {
    	index = ll_indexOf(this, pElement);

    	if(index > -1)
    	{
    		toReturn = 1;
    	}
    	else
    	{
    		toReturn = 0;
    	}
    }

    return toReturn;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int toReturn = -1;

    int i;
    int len;

    void* pElement;

    if (this != NULL && this2 != NULL)
    {
		toReturn = 1;

		len = ll_len(this2);

		for(i = 0; i < len; i++)
		{
			pElement = ll_get(this2, i);

			if(!ll_contains(this, pElement))
			{
				toReturn = 0;
				break;
			}
		}
	}

    return toReturn;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    int i;
    int len;

    void* pElement;

    if(this != NULL && from >= 0 && from < to)
    {
    	len = ll_len(this);

    	if(from <= len && to <= len)
    	{
    		cloneArray = ll_newLinkedList();

    		if(cloneArray != NULL)
    		{
    			for(i = from; i < to; i++)
    			{
    				pElement = ll_get(this, i);

    				if(ll_add(cloneArray, pElement))
    				{
    					free(cloneArray);
    					cloneArray = NULL;
    					break;
    				}
    			}
    		}
    	}
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	cloneArray = ll_subList(this, 0, len);
    }

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int toReturn = -1;

    int i;
    int len;
    int flagSwap;
    int pFuncReturn;

    void* pElement1;
    void* pElement2;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
    	len = ll_len(this);

    	do
    	{
    		flagSwap = 0;

    		for(i = 0; i < len - 1; i++)
    		{
    			pElement1 = ll_get(this, i);
    			pElement2 = ll_get(this, i + 1);

    			pFuncReturn = pFunc(pElement1, pElement2);

    			if((order == 1 && pFuncReturn == 1) || (order == 0 && pFuncReturn == -1))
    			{
    				flagSwap = 1;

    				ll_set(this, i, pElement2);
    				ll_set(this, i + 1, pElement1);

    			}
    		}
    		len--;


    	}while(flagSwap);

    	toReturn = 0;
    }

    return toReturn;

}

