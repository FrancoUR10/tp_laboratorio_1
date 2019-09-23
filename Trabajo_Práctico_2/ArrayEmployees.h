#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

/** \brief Recibe una opcion del menu y lo retorna
 *
 * \param mensaje[] char El mensaje con las opciones del menu
 * \return int La opcion ingresada
 *
 */
int pedirMenu(char mensaje[]);

/** \brief Recibe una cadena de caracteres y la guarda en un array
 *
 * \param unArray[] char Los caracteres ingresados
 * \param mensaje[] char El mensaje pidiendo un string
 * \param mensajeError[] char El mensaje en caso de error
 * \param min int El rango minimo de caracteres ingresados
 * \param max int El rango maximo de caracteres ingresados
 * \return void No retorna nada
 *
 */
void getString(char unArray[],char mensaje[],char mensajeError[],int min,int max);

/** \brief Valida si los caracteres ingresados contienen solo numeros
 *
 * \param unArray[] char Una cadena de caracteres
 * \return int Si contiene solo numeros [1] si no [0]
 *
 */
int validarSoloNumeros(char unArray[]);

/** \brief Valida si los caracteres ingresados contienen solo letras
 *
 * \param unArray[] char Una cadena de caracteres
 * \return int Si contiene solo letras [1] si no [0]
 *
 */
int validarSoloLetras(char unArray[]);

/** \brief Recibe una cadena de caracteres y valida si contiene solo numeros
 *
 * \param unArray[] char Una cadena de caracteres
 * \param mensaje[] char El mensaje pidiendo numeros
 * \param mensajeErrorRango[] char El mensaje en caso de error por rango
 * \param mensajeErrorNumeros[] char El mensaje en caso de error por caracteres no validos
 * \param min int Rango minimo del array
 * \param max int Rango maximo del array
 * \return int Si contiene solo numeros [1] si no [0]
 *
 */
int getStringNumeros(char unArray[],char mensaje[],char mensajeErrorRango[],char mensajeErrorNumeros[],int min,int max);

/** \brief Recibe una cadena de caracteres y valida si contiene solo letras
 *
 * \param unArray[] char Una cadena de caracteres
 * \param mensaje[] char El mensaje pidiendo letras
 * \param mensajeErrorRango[] char El mensaje en caso de error por rango
 * \param mensajeErrorLetras[] char El mensaje en caso de error por caracteres no validos
 * \param min int Rango minimo del array
 * \param max int Rango maximo del array
 * \return int Si contiene solo letras [1] si no [0]
 *
 */
int getStringLetras(char unArray[],char mensaje[],char mensajeErrorRango[],char mensajeErrorLetras[],int min,int max);

/** \brief Inicializa cada posicion del array como vacio
 *
 * \param list eEmployee* El puntero al array de empleados a inicializar
 * \param len int La longitud del array
 * \return int Si tiene un puntero nulo o una longitud invalida [-1] si no [0]
 *
 */
int initEmployees(eEmployee* list, int len);

/** \brief Busca el id de una posicion que se encuentre ocupada y retorna su indice
 *
 * \param list eEmployee* El puntero al array de empleados en donde realizar la busqueda
 * \param len int La longitud del array
 * \param id int El valor del id a buscar
 * \return int Si tiene un puntero nulo, una longitud invalida o no encontro al empleado [-1] si no retorna el indice
 *
 */
int findEmployeeById(eEmployee* list, int len,int id);

/** \brief Muestra el contenido del array de empleados que se encuentren ocupados
 *
 * \param list eEmployee* El puntero al array de empleados a mostrar
 * \param length int La longitud del array
 * \return int Si el puntero es nulo, la longitud es invalida o no hay un lugar ocupado a mostrar [-1] si no [0]
 *
 */
int printEmployees(eEmployee* list, int length);

/** \brief Pide los datos generales de la estructura y los guarda en un indice
 *
 * \param unArray[] eEmployee El array que recibe los datos
 * \param tam int La longitud del array
 * \param indice int El indice del array en donde se guardaran los datos
 * \return void No retorna nada
 *
 */
void pedirDatos(eEmployee unArray[],int tam,int indice);

/** \brief Valida si hay un espacio libre y pide los datos para darlos de alta
 *
 * \param unArray[] eEmployee El array en donde se daran de alta los datos
 * \param tam int La longitud del array
 * \param contDadosDeAlta int* Un contador para generar el id de forma automatica
 * \return void No retorna nada
 *
 */
void darDeAlta(eEmployee unArray[],int tam,int* contDadosDeAlta);

/** \brief valida si el caracter ingresado contiene solo numeros y menos de dos puntos, ademas del rango establecido
 *
 * \param unArray[] char El array donde se ingresan los caracteres
 * \return int Si solo contiene numeros flotantes [1] si no [0]
 *
 */
int validarSoloNumerosFloat(char unArray[]);

/** \brief Pide una cadena de caracteres y valida si contiene solo numeros flotantes y si se encuentra en el rango establecido
 *
 * \param unArray[] char El array donde se ingresan los caracteres
 * \param mensaje[] char El mensaje pidiendo un numero tipo float
 * \param mensajeErrorRango[] char El mensaje en caso de error por rango
 * \param mensajeErrorNumeros[] char El mensaje en caso de error por no contener solo numeros o mas de un solo punto
 * \param min int El rango minimo del array
 * \param max int El rango maximo del array
 * \return int Si contiene solo un numero tipo float [1] si no [0]
 *
 */
int getStringNumerosFloat(char unArray[],char mensaje[],char mensajeErrorRango[],char mensajeErrorNumeros[],int min,int max);

/** \brief Pide el id de un empleado y lo borra de manera logica
 *
 * \param list eEmployee* El puntero al array del empleado a borrar
 * \param len int La longitud del array
 * \return int Si el puntero es nulo, la longitud es invalida o si no encontro al empleado [-1] si lo encontro [0]
 *
 */
int removeEmployee(eEmployee* list, int len);

/** \brief Recorre cada posicion del array buscando un lugar libre u ocupado y retorna su indice
 *
 * \param unArray[] eEmployee El array en donde buscar un lugar libre u ocupado
 * \param tam int La longitud del array
 * \param estadoDelIndice int El estado del indice que se quiere buscar, para ocupado[0] para libre[1]
 * \return int El indice del estado buscado, si no lo encontro [-1]
 *
 */
int buscarEstadoDelArray(eEmployee unArray[],int tam,int estadoDelIndice);

/** \brief Pide el id de un empleado y luego permite modificar un dato seleccionado
 *
 * \param unArray[] eEmployee El array con los datos a modificar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void modificarArray(eEmployee unArray[],int tam);

/** \brief Saca el promedio del sueldo de cada empleado que se encuentre dado de alta
 *
 * \param unArray[] eEmployee El array con los datos de los empleados
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarPromedioDeSalarios(eEmployee unArray[],int tam);

/** \brief Ordena los elementos de un array por sector y apellido de menor a mayor
 *
 * \param unArray[] eEmployee El array con los elementos a ordenar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void ordenarArrayAscendiente(eEmployee unArray[],int tam);

/** \brief Ordena los elementos de un array por sector y apellido de mayor a menor
 *
 * \param unArray[] eEmployee El array con los elementos a ordenar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void ordenarArrayDescendiente(eEmployee unArray[],int tam);

/** \brief Ordena los elementos por sector y por apellido
 *
 * \param list eEmployee* El puntero al array de empleados a ordenar
 * \param len int La longitud del array
 * \param order int El tipo de orden: Para ordenar ascendiente [1] Para descendiente [0]
 * \return int Si el puntero es nulo o la longitud es invalida [-1] si se ordeno [0]
 *
 */
int sortEmployees(eEmployee* list, int len, int order);

/** \brief Pregunta por un solo dato a modificar y realiza la modificacion del mismo
 *
 * \param unArray[] eEmployee El array con un dato a modificar
 * \param tam int La longitud del array
 * \param indice int La posicion del array en donde se modificara un dato
 * \return void No retorna nada
 *
 */
void menuModificarDatos(eEmployee unArray[],int tam,int indice);

/** \brief Harcodea los datos ingresados como parametros en una posicion libre, generando un id automaticamente
 *
 * \param list eEmployee* El puntero al array de empleados a harcodear
 * \param len int La longitud del array
 * \param contId int* El contador para generar un id de forma automatica
 * \param name[] char El nombre a harcodear
 * \param lastName[] char El apellido a harcodear
 * \param salary float El salario a harcodear
 * \param sector int El sector a harcodear
 * \return int Si el puntero es nulo, la longitud es invalida o no se encontro un lugar libre [-1] si no [0]
 *
 */
int addEmployee(eEmployee* list, int len, int* contId, char name[],char lastName[],float salary,int sector);

#endif // ARRAYEMPLOYEES_H_INCLUDED
