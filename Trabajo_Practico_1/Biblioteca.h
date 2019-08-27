#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

/** \brief Pide un numero de tipo int al usuario
 *
 * \param El mensaje pidiendo un numero entero
 * \return El dato enviado por el usuario
 *
 */
int getInt(char mensaje[]);

/** \brief Realiza una suma de dos numeros
 *
 * \param Un numero de tipo int
 * \param Otro numero de tipo int
 * \return El resultado de la suma
 *
 */
int sacarSuma(int sumandosUno,int sumandosDos);

/** \brief Realiza una resta de dos numeros
 *
 * \param El numero minuendo
 * \param El numero sustraendo
 * \return El resultado de la resta
 *
 */
int sacarResta(int minuendo,int sustraendo);

/** \brief Realiza una multiplicacion de dos numeros
 *
 * \param Un numero factor
 * \param Otro numero factor
 * \return El producto de la multiplicacion
 *
 */
int sacarMultiplicacion(int factorUno,int factorDos);

/** \brief Compara que el numero divisor sea distinto de cero y realiza una division de dos numeros
 *
 * \param El numero dividendo
 * \param El numero divisor
 * \param El resultado de la division por medio de un puntero
 * \return 1 si la division es valida y 0 si la division no es valida
 *
 */
int sacarDivision(int dividendo,int divisor,float *resultadoDivision);

/** \brief Compara que el numero no sea negativo y realiza el factorial
 *
 * \param Un numero de tipo int
 * \return El resultado del factorial
 *
 */
int sacarFactorial(int operando);

#endif // BIBLIOTECA_H_INCLUDED
