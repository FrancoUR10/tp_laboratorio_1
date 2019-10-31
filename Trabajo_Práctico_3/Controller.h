#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Da de alta a un empleado en la lista
 *
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \param contAltas int* El contador para generar un id automaticamente
 * \return int Si los datos no se ingresaron correctamente [-1] si se dio de alta [1] si cancelo el usuario [0]
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* contAltas);

/** \brief Modifica los datos de un empleado en la lista
 *
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Si se encontro el elemento a modificar [1] si no se encontro [-1]
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Permite elejir los datos a modificar a por medio de un menu
 *
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \param indice int El indice del empleado en la lista
 * \return void No retorna nada
 *
 */
void controller_pedirDatosAEleccion(LinkedList* pArrayListEmployee,int indice);

/** \brief Da de baja a un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Si no se pudo dar de baja [-1] si se dio de baja [1] si cancelo el usuario [0]
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Muestra la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Si la lista esta libre [0] si mostro la lista [1]
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Muestra un solo empleado
 *
 * \param empleado Employee* El puntero a Employee
 * \return int Si el puntero es nulo [0] si pudo mostrar al empleado [1]
 *
 */
int controller_mostrarUnEmpleado(Employee* empleado);

/** \brief Ordena los elementos de la lista dinamica a eleccion del criterio
 *
 * \param pArrayListEmployee LinkedList* La lista dinamica
 * \return int Si alguna vez se ordeno [1] si nunca se ordeno [0]
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


