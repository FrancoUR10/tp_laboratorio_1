#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
 int id;
 char nombre[50];
 char apellido[50];
 float salario;
 int sector;
 int estaVacio;
} eEmpleado;

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

/** \brief Inicializa cada elemento del array como libre
 *
 * \param unArray[] eEmpleado El array a ser inicializado
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void inicializarId(eEmpleado unArray[],int tam);

/** \brief Busca un valor en cada elemento del array y retorna la posicion donde se encuentra
 *
 * \param unArray[] eEmpleado El array en donde realizar la busqueda
 * \param tam int La longitud del array
 * \param valor int El valor que se desea buscar
 * \param flagLugar int Para buscar solo en lugares libres [1] para ocupados [0]
 * \return int Si encontro el valor retorna el indice, si no [-1]
 *
 */
int buscarLugarLibre(eEmpleado unArray[],int tam,int valorId,int flagLugar);

/** \brief Muestra todos los elementos de un array que se encuentren ocupados
 *
 * \param unArray[] eEmpleado El array con los elementos a mostrar
 * \param tam int La longitud del array a mostrar
 * \return void No retorna nada
 *
 */
void mostrarArray(eEmpleado unArray[],int tam);

/** \brief Pide los datos generales de la estructura y los guarda en un indice
 *
 * \param unArray[] eEmpleado El array que recibe los datos
 * \param tam int La longitud del array
 * \param indice int El indice del array en donde se guardaran los datos
 * \return void No retorna nada
 *
 */
void pedirDatos(eEmpleado unArray[],int tam,int indice);

/** \brief Valida si hay un espacio libre y pide los datos para darlos de alta
 *
 * \param unArray[] eEmpleado El array en donde se daran de alta los datos
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void darDeAlta(eEmpleado unArray[],int tam);

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

/** \brief Pide el id de un empleado y lo borra de forma logica
 *
 * \param unArray[] eEmpleado El array en donde se daran de baja los datos
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void darDeBaja(eEmpleado unArray[],int tam);

/** \brief Recorre cada posicion del array buscando un lugar libre u ocupado y retorna su indice
 *
 * \param unArray[] eEmpleado El array en donde buscar un lugar libre u ocupado
 * \param tam int La longitud del array
 * \param estadoDelIndice int El estado del indice que se quiere buscar, para ocupado[0] para libre[1]
 * \return int El indice del estado buscado, si no lo encontro [-1]
 *
 */
int buscarEstadoDelArray(eEmpleado unArray[],int tam,int estadoDelIndice);

/** \brief Pide el id de un empleado y luego pide los datos a modificar
 *
 * \param unArray[] eEmpleado El array con los datos a modificar
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void modificarArray(eEmpleado unArray[],int tam);

/** \brief Saca el promedio del sueldo de cada empleado que se encuentre dado de alta
 *
 * \param unArray[] eEmpleado El array con los datos de los empleados
 * \param tam int La longitud del array
 * \return void No retorna nada
 *
 */
void mostrarPromedioDeSalarios(eEmpleado unArray[],int tam);

#endif // ARRAYEMPLOYEES_H_INCLUDED
