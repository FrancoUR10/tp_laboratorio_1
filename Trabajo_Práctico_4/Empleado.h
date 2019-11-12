#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    int edad;
    float sueldo;
}eEmpleado;

/** \brief Recerba espacio en memoria e inicializa un empleado
 *
 * \return eEmpleado* [NULL] si no encontro espacio o la posicion de memoria del empleado si encontro espacio
 *
 */
eEmpleado* empleado_nuevoEmpleado();

/** \brief Libera el espacio en memoria de un empleado
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \return int Si libero al empleado [1] si no [0]
 *
 */
int empleado_borrarEmpleado(eEmpleado* empleado);

/** \brief Setea el id a un empleado
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \param id int El id a setear
 * \return int Si seteo el id [1] si no [0]
 *
 */
int empleado_setId(eEmpleado* empleado,int id);

/** \brief Setea el nombre a un empleado
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \param nombre char* El nombre a setear
 * \return int Si seteo el nombre [1] si no [0]
 *
 */
int empleado_setNombre(eEmpleado* empleado,char* nombre);

/** \brief Setea el apellido a un empleado
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \param apellido char* El apellido a setear
 * \return int Si seteo el apellido [1] si no [0]
 *
 */
int empleado_setApellido(eEmpleado* empleado,char* apellido);

/** \brief Setea la edad a un empleado
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \param edad int La edad a setear
 * \return int Si seteo la edad [1] si no [0]
 *
 */
int empleado_setEdad(eEmpleado* empleado,int edad);

/** \brief Setea el sueldo a un empleado
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \param sueldo float El elSueldo a setear
 * \return int Si seteo el sueldo [1] si no [0]
 *
 */
int empleado_setSueldo(eEmpleado* empleado,float sueldo);

/** \brief Obtiene el id de un empleado por parametros
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \param id int* El id a obtener
 * \return int Si se obtuvo el id [1] si no [0]
 *
 */
int empleado_getId(eEmpleado* empleado,int* id);

/** \brief Obtiene el nombre de un empleado por parametros
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \param nombre char* El nombre a obtener
 * \return int Si se obtuvo el nombre [1] si no [0]
 *
 */
int empleado_getNombre(eEmpleado* empleado,char* nombre);

/** \brief Obtiene el apellido de un empleado por parametros
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \param apellido char* El apellido a obtener
 * \return int Si se obtuvo el apellido [1] si no [0]
 *
 */
int empleado_getApellido(eEmpleado* empleado,char* apellido);

/** \brief Obtiene la edad de un empleado por parametros
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \param edad int* La edad a obtener
 * \return int Si se obtuvo la edad [1] si no [0]
 *
 */
int empleado_getEdad(eEmpleado* empleado,int* edad);

/** \brief Obtiene el sueldo de un empleado por parametros
 *
 * \param empleado eEmpleado* El puntero a un empleado
 * \param sueldo float* El sueldo a obtener
 * \return int Si se obtuvo el sueldo [1] si no [0]
 *
 */
int empleado_getSueldo(eEmpleado* empleado,float* sueldo);

/** \brief Recerba espacio en memoria para un empleado y setea todos sus campos pasados por parametros
 *
 * \param id char* El id tipo string a setear
 * \param nombre char* El nombre a setear
 * \param apellido char* El apellido a setear
 * \param edad char* La edad tipo string a setear
 * \param sueldo char* El sueldo tipo string a setear
 * \return eEmpleado* [NULL] si no encontro espacio o la direccion de memoria si encontro espacio
 *
 */
eEmpleado* empleado_nuevoEmpleadoParametros(char* id,char* nombre,char* apellido,char* edad,char* sueldo);

/** \brief Recibe dos empleados y compara el id de ambos
 *
 * \param empleado1 void* El puntero del primer empleado
 * \param empleado2 void* El puntero del segundo empleado
 * \return int Si el primer empleado es mayor al segundo [1], si es menor [-1] si son iguales [0]
 *
 */
int empleado_compararPorId(void* empleado1,void* empleado2);

/** \brief Recibe dos empleados y compara el nombre de ambos
 *
 * \param empleado1 void* El puntero del primer empleado
 * \param empleado2 void* El puntero del segundo empleado
 * \return int Si el primer empleado es mayor al segundo [1], si es menor [-1] si son iguales [0]
 *
 */
int empleado_compararPorNombre(void* empleado1,void* empleado2);

/** \brief Recibe dos empleados y compara el apellido de ambos
 *
 * \param empleado1 void* El puntero del primer empleado
 * \param empleado2 void* El puntero del segundo empleado
 * \return int Si el primer empleado es mayor al segundo [1], si es menor [-1] si son iguales [0]
 *
 */
int empleado_compararPorApellido(void* empleado1,void* empleado2);

/** \brief Recibe dos empleados y compara la edad de ambos
 *
 * \param empleado1 void* El puntero del primer empleado
 * \param empleado2 void* El puntero del segundo empleado
 * \return int Si el primer empleado es mayor al segundo [1], si es menor [-1] si son iguales [0]
 *
 */
int empleado_compararPorEdad(void* empleado1,void* empleado2);

/** \brief Recibe dos empleados y compara el sueldo de ambos
 *
 * \param empleado1 void* El puntero del primer empleado
 * \param empleado2 void* El puntero del segundo empleado
 * \return int Si el primer empleado es mayor al segundo [1], si es menor [-1] si son iguales [0]
 *
 */
int empleado_compararPorSueldo(void* empleado1,void* empleado2);

/** \brief Muestra los datos de un solo empleado
 *
 * \param unEmpleado eEmpleado* El puntero a un empleado
 * \return int Si el puntero es nulo [0] si se mostraron los datos [1]
 *
 */
int empleado_mostrarUnEmpleado(eEmpleado* unEmpleado);

/** \brief Muestra la lista con todos los empleados
 *
 * \param listaEmpleados LinkedList* La lista de empleados
 * \return void No retorna nada
 *
 */
void empleado_mostrarListaEmpleados(LinkedList* listaEmpleados);

/** \brief Busca el indice de un empleado por su id
 *
 * \param listaEmpleados LinkedList* La lista de empleados
 * \param idABuscar int El id a buscar en la lista
 * \return int Si lo encontro retorna el indice, si no lo encontro [-1]
 *
 */
int empleado_buscarPorId(LinkedList* listaEmpleados,int idABuscar);

/** \brief Da de alta a un nuevo empleado en la lista
 *
 * \param listaEmpleados LinkedList* La lista de empleados
 * \param contAltas int* El contador para generar un nuevo id automaticamente
 * \return int Si se dio de alta [1] si cancelo el usuario [0] si no se logro el alta [-1]
 *
 */
int empleado_darDeAlta(LinkedList* listaEmpleados,int* contAltas);

/** \brief Da de baja a un empleado en la lista
 *
 * \param listaEmpleados LinkedList* La lista de empleados
 * \return int Si se dio de baja [1] si cancelo el usuario [0] si no se logro la baja [-1]
 *
 */
int empleado_darDeBaja(LinkedList* listaEmpleados);

/** \brief Modifica a un empleado en la lista
 *
 * \param listaEmpleados LinkedList* La lista de empleados
 * \return int Si se accedio al menu de modificaciones [1] si no se logro obtener al empleado [-1]
 *
 */
int empleado_modificarDatos(LinkedList* listaEmpleados);

/** \brief Recibe el indice de un empleado y pregunta por los datos a modificar
 *
 * \param listaEmpleados LinkedList* La lista de empleados
 * \param indiceEncontrado int El indice del empleado a modificar
 * \return void No retorna nada
 *
 */
void menuPedirDatosAModificar(LinkedList* listaEmpleados,int indiceEncontrado);

/** \brief Guarda los datos de los empleados en modo binario
 *
 * \param archivo FILE* El archivo en donde guardar los datos
 * \param listaEmpleados LinkedList* La lista de empleados
 * \param contAltas int* El contador de altas a guardar en la primer posicion del archivo
 * \return int Si se pudo guardar los datos [1] si no [-1]
 *
 */
int empleado_guardarDatos(FILE* archivo,LinkedList* listaEmpleados,int* contAltas);

/** \brief Carga los datos de los empleados que fueron guardados en modo binario
 *
 * \param archivo FILE* El archivo en donde se guardaron los datos
 * \param listaEmpleados LinkedList* La lista de empleados
 * \param contAltas int* El contador de altas a obtener desde la primer posicion del archivo
 * \return int Si se pudo cargar los datos [1] si no [-1]
 *
 */
int empleado_cargarDatos(FILE* archivo,LinkedList* listaEmpleados,int* contAltas);

/** \brief Pregunta en un menu de opciones de que forma se desean ordenar los datos
 *
 * \param listaEmpleados LinkedList* La lista de empleados
 * \return void No retorna nada
 *
 */
void empleado_ordenarEmpleados(LinkedList* listaEmpleados);
#endif // EMPLEADO_H_INCLUDED
