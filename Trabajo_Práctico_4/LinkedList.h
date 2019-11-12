#ifndef __LINKEDLIST
#define __LINKEDLIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    void* pElement;                         //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;                 //puntero al prox nodo
}typedef Node;

typedef struct
{
    Node* pFirstNode;
    int size;                               //cada vez que agrego o elimino un elemento size++/--
}LinkedList;

//Publicas

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void);

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* lista);                                       //devuelve el valor del campo int size
/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* lista, void* pElement);

/** \brief Obtiene un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* lista, int index);

/** \brief Modifica un elemento de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* lista, int index,void* pElement);

/** \brief Elimina un elemento de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* lista,int index);

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* lista);

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* lista);

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param lista LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* lista, void* pElement);

/** \brief Indica si la lista esta o no vacia
 *
 * \param lista LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* lista);

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* lista, int index, void* pElement);

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* lista,int index);                           //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param lista LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* lista, void* pElement);

/** \brief  Determina si todos los elementos de la lista (lista2)
            estan contenidos en la lista (lista)
 *
 * \param lista LinkedList* Puntero a la lista
 * \param lista2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (lista2) estan contenidos en la lista (lista)
                        ( 0) si los elementos de (lista2) NO estan contenidos en la lista (lista)
*/
int ll_containsAll(LinkedList* lista,LinkedList* lista2);

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param lista LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* lista,int from,int to);

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* lista);

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param lista LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* lista, int (*pFunc)(void* ,void*), int order);
#endif
