#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Guarda un id en el campo de una estructura
 *
 * \param this Employee* El puntero a Employee
 * \param id int El id a guardar
 * \return int Si es nulo o el id no es valido [0] si se guardo el id [1]
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Obtiene el id guardado en una estructura por referencia
 *
 * \param this Employee* El puntero a Employee
 * \param id int* Un puntero al id a obtener
 * \return int Si alguno de los punteros es nulo [0] si se obtuvo el id [1]
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Guarda un nombre en el campo de una estructura
 *
 * \param this Employee* El puntero a Employee
 * \param nombre char* El nombre a guardar
 * \return int Si es nulo o el nombre no es valido [0] si se guardo el nombre [1]
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Obtiene el nombre guardado en una estructura por referencia
 *
 * \param this Employee* El puntero a Employee
 * \param nombre char* Un puntero al nombre a obtener
 * \return int Si alguno de los punteros es nulo [0] si se obtuvo el nombre [1]
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Guarda una hora en el campo de una estructura
 *
 * \param this Employee* El puntero a Employee
 * \param horasTrabajadas int La hora a guardar
 * \return int Si es nulo o la hora no es valida [0] si se guardo la hora [1]
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Obtiene la hora guardada en una estructura por referencia
 *
 * \param this Employee* El puntero a Employee
 * \param horasTrabajadas int* Un puntero a la hora a obtener
 * \return int Si alguno de los punteros es nulo [0] si se obtuvo la hora [1]
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Guarda un sueldo en el campo de una estructura
 *
 * \param this Employee* El puntero a Employee
 * \param sueldo int El sueldo a guardar
 * \return int Si es nulo o el sueldo no es valido [0] si se guardo el sueldo [1]
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene el sueldo guardado en una estructura por referencia
 *
 * \param this Employee* El puntero a Employee
 * \param sueldo int* Un puntero al sueldo a obtener
 * \return int Si alguno de los punteros es nulo [0] si se obtuvo el sueldo [1]
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Reserva un espacio de memoria inicializando todos sus campos y devuelve su posicion
 *
 * \return Employee* La direccion de memoria asignada o nulo si no pudo asignarla
 *
 */
Employee* employee_new();

/** \brief Reserva un espacio de memoria guardando en los campos cada dato enviado como string
 *
 * \param idStr char* El id en dato string
 * \param nombreStr char* El nombre
 * \param horasTrabajadasStr char* Las horas trabajadas en dato string
 * \param sueldoStr char* El sueldo en dato string
 * \return Employee* La direccion de memoria asignada o nulo si no pudo asignarla
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Recibe un puntero y libera el espacio en memoria al que apunta
 *
 * \param this Employee* El puntero a Employee
 * \return int Si se libero el espacio en memoria [1] si el puntero recibido es nulo [0]
 *
 */
int employee_delete(Employee* this);

/** \brief Muestra los datos de un solo empleado
 *
 * \param empleado Employee* El puntero a Employee
 * \return void No retorna nada
 *
 */
void mostrarUnEmpleado(Employee* empleado);

/** \brief Muestra a cada empleado de la lista dinamica
 *
 * \param listaEmpleado LinkedList* La lista dinamica
 * \return void No retorna nada
 *
 */
void mostrarListaEmpleado(LinkedList* listaEmpleado);

/** \brief Recibe dos empleados como parametros y los compara por id
 *
 * \param empleado1 void* El primer puntero a Employee
 * \param empleado2 void* El segundo puntero a Employee
 * \return int Si el primero es mayor que el segundo [1] si es menor [-1] si son iguales [0]
 *
 */
int compararPorId(void* empleado1,void* empleado2);

/** \brief Recibe dos empleados como parametros y los compara por nombre
 *
 * \param empleado1 void* El primer puntero a Employee
 * \param empleado2 void* El segundo puntero a Employee
 * \return int Si el primero es mayor que el segundo [1] si es menor [-1] si son iguales [0]
 *
 */
int compararPorNombre(void* empleado1,void* empleado2);

/** \brief Recibe dos empleados como parametros y los compara por horas
 *
 * \param empleado1 void* El primer puntero a Employee
 * \param empleado2 void* El segundo puntero a Employee
 * \return int Si el primero es mayor que el segundo [1] si es menor [-1] si son iguales [0]
 *
 */
int compararPorHoras(void* empleado1,void* empleado2);

/** \brief Recibe dos empleados como parametros y los compara por sueldo
 *
 * \param empleado1 void* El primer puntero a Employee
 * \param empleado2 void* El segundo puntero a Employee
 * \return int Si el primero es mayor que el segundo [1] si es menor [-1] si son iguales [0]
 *
 */
int compararPorSueldo(void* empleado1,void* empleado2);

/** \brief Busca un empleado por id y retorna su indice
 *
 * \param listaEmpleado LinkedList* La lista dinamica
 * \param idABuscar int El id a buscar
 * \return int Si encontro el id retorna su indice, si no lo encontro [-1]
 *
 */
int buscarEmpleadoPorId(LinkedList* listaEmpleado,int idABuscar);

#endif // employee_H_INCLUDED
