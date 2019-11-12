#include "LinkedList.h"

/** \brief  Obtiene un nodo de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* lista=(LinkedList*)malloc(sizeof(LinkedList));
    if(lista!=NULL)
    {
        lista->pFirstNode=NULL;
        lista->size=0;
    }
    return lista;
}
int ll_len(LinkedList* lista)
{
    int returnAux=-1;
    if(lista!=NULL)
    {
        returnAux=lista->size;
    }
    return returnAux;
}
static Node* getNode(LinkedList* lista, int nodeIndex)
{
    Node* pNode=NULL;
    int i=0;
    int len=ll_len(lista);
    if(lista!=NULL && nodeIndex > -1 && nodeIndex < len)
    {
        pNode=lista->pFirstNode;
        while(pNode!=NULL && i != nodeIndex)
        {
            pNode=pNode->pNextNode;
            i++;
        }
    }
    return pNode;
}
static int addNode(LinkedList* lista, int nodeIndex,void* pElement)
{
    Node* pNuevoNodo=NULL;
    Node* pAuxNodo=NULL;
    int returnAux=-1;
    int len=ll_len(lista);
    if(lista!=NULL && nodeIndex > -1 && nodeIndex <= len)
    {
        pNuevoNodo=(Node*)malloc(sizeof(Node));
        if(pNuevoNodo!=NULL)
        {
            pNuevoNodo->pElement=pElement;
            if(nodeIndex==0)
            {
                pNuevoNodo->pNextNode=lista->pFirstNode;
                lista->pFirstNode=pNuevoNodo;
            }
            else
            {
                pAuxNodo=getNode(lista,nodeIndex-1);
                pNuevoNodo->pNextNode=pAuxNodo->pNextNode;
                pAuxNodo->pNextNode=pNuevoNodo;
            }
            lista->size++;
            returnAux=0;
        }
    }
    return returnAux;
}
int ll_add(LinkedList* lista, void* pElement)
{
    int returnAux=-1;
    int len=ll_len(lista);
    if(lista!=NULL)
    {
        returnAux=addNode(lista,len,pElement);
    }
    return returnAux;
}
void* ll_get(LinkedList* lista, int index)
{
    void* returnAux=NULL;
    Node* pNode=NULL;
    if(lista!=NULL)
    {
        pNode=getNode(lista,index);
        if(pNode!=NULL)
        {
            returnAux=pNode->pElement;
        }
    }
    return returnAux;
}
int ll_set(LinkedList* lista, int index,void* pElement)
{
    int returnAux=-1;
    Node* pNode;
    if(lista!=NULL)
    {
        pNode=getNode(lista,index);
        if(pNode!=NULL)
        {
            pNode->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}
int ll_remove(LinkedList* lista,int index)
{
    Node* pNode=NULL;
    Node* pAuxNode=NULL;
    int returnAux=-1;
    int len=ll_len(lista);
    if(lista!=NULL && index > -1 && index < len)
    {
        pNode=getNode(lista,index);
        if(index==0)
        {
            lista->pFirstNode=pNode->pNextNode;
        }
        else
        {
            pAuxNode=getNode(lista,index-1);
            pAuxNode->pNextNode=pNode->pNextNode;
        }
        free(pNode);
        pNode=NULL;
        lista->size--;
        returnAux=0;
    }
    return returnAux;
}
int ll_clear(LinkedList* lista)
{
    int returnAux=-1;
    Node* pNode;
    int i=0;
    int len=ll_len(lista);
    if(lista!=NULL)
    {
        while(lista!=NULL && i > -1 && i < len)
        {
            pNode=getNode(lista,i);
            free(pNode);
            pNode=NULL;
            i++;
        }
        lista->pFirstNode=NULL;
        lista->size=0;
        returnAux=0;
    }
    return returnAux;
}
int ll_deleteLinkedList(LinkedList* lista)
{
    int returnAux=-1;
    if(lista!=NULL)
    {
        ll_clear(lista);
        free(lista);
        lista=NULL;
        returnAux=0;
    }
    return returnAux;
}
int ll_indexOf(LinkedList* lista, void* pElement)
{
    int returnAux=-1;
    Node* pNode=NULL;
    int i;
    int len=ll_len(lista);
    if(lista!=NULL)
    {
        for(i=0;i<len;i++)
        {
            pNode=getNode(lista,i);
            if(pNode!=NULL && pNode->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}
int ll_isEmpty(LinkedList* lista)
{
    int returnAux=-1;
    if(lista!=NULL)
    {
        if(lista->size==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}
int ll_push(LinkedList* lista, int index, void* pElement)
{
    int returnAux=-1;
    if(lista!=NULL)
    {
        returnAux=addNode(lista,index,pElement);
    }
    return returnAux;
}
void* ll_pop(LinkedList* lista,int index)
{
    void* returnAux=NULL;
    void* auxElement=NULL;
    if(lista!=NULL)
    {
        auxElement=ll_get(lista,index);
        if(ll_remove(lista,index)==0)
        {
            returnAux=auxElement;
        }
    }
    return returnAux;
}
int ll_contains(LinkedList* lista, void* pElement)
{
    int returnAux=-1;
    if(lista!=NULL)
    {
        returnAux=ll_indexOf(lista,pElement);
        if(returnAux==-1)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
    }
    return returnAux;
}
int ll_containsAll(LinkedList* lista,LinkedList* lista2)
{
    int returnAux=-1;
    void* auxElement;
    int i=0;
    int len=ll_len(lista2);
    if(lista!=NULL && lista2!=NULL)
    {
        returnAux=1;
        while(returnAux!=0 && i > -1 && i < len)
        {
            auxElement=ll_get(lista2,i);
            returnAux=ll_contains(lista,auxElement);
            i++;
        }
    }
    return returnAux;
}
LinkedList* ll_subList(LinkedList* lista,int from,int to)
{
    LinkedList* cloneArray=NULL;
    void* auxElement=NULL;
    int i;
    int len=ll_len(lista);
    if(lista!=NULL && (from > -1 && from <= len) && (to > from && to <= len))
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(i=from;i<to;i++)
            {
                auxElement=ll_get(lista,i);
                ll_add(cloneArray,auxElement);
            }
        }
    }
    return cloneArray;
}
LinkedList* ll_clone(LinkedList* lista)
{
    LinkedList* cloneArray=NULL;
    void* auxElement=NULL;
    int i;
    int len=ll_len(lista);
    if(lista!=NULL)
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(i=0;i<len;i++)
            {
                auxElement=ll_get(lista,i);
                ll_add(cloneArray,auxElement);
            }
        }
    }
    return cloneArray;
}
int ll_sort(LinkedList* lista, int (*pFunc)(void* ,void*), int order)
{
    int returnAux=-1;
    int comparacion=1;
    int i;
    int j;
    Node* pNodeI;
    Node* pNodeJ;
    void* elementI;
    void* elementJ;
    int len=ll_len(lista);
	if(lista!=NULL && pFunc != NULL && (order==1 || order==0))
    {
        returnAux=0;
        if(order!=1)
        {
            comparacion=-1;
        }
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                elementI=ll_get(lista,i);
                elementJ=ll_get(lista,j);
                if(pFunc(elementI,elementJ)==comparacion)
                {
                    pNodeI=getNode(lista,i);
                    pNodeJ=getNode(lista,j);

                    pNodeI->pElement=elementJ;
                    pNodeJ->pElement=elementI;
                }
            }
        }
    }
    return returnAux;
}

