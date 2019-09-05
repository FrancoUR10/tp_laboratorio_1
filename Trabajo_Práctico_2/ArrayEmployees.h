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
void mostrarArray(eEmpleado unArray[],int tam);
void pedirDatos(eEmpleado unArray[],int tam,int indice);
void darDeAlta(eEmpleado unArray[],int tam);

#endif // ARRAYEMPLOYEES_H_INCLUDED
