#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main()
{
    int primerOperandoA=0;
    int segundoOperandoB=0;
    int resultadoSuma=0;
    int resultadoResta=0;
    int resultadoMultiplicacion=0;
    float resultadoDivision;
    int validarDivision=0;
    int continuar=1;
    int opcionIngresada;
    int factorialPrimerOperando=1;
    int factorialSegundoOperando=1;

    while(continuar==1)
    {
        printf("Valor actual del operando A: %d\nValor actual del operando B: %d\n\n",primerOperandoA,segundoOperandoB);
        switch(opcionIngresada=getInt("1. Ingresar 1er operando\n2. Ingresar 2do operando\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\nSeleccione una opcion: "))
        {
            case 1 :
                primerOperandoA=getInt("Ingrese el primer operando: ");
                break;
            case 2 :
                segundoOperandoB=getInt("Ingrese el segundo operando: ");
                break;
            case 3 :
                resultadoSuma=sacarSuma(primerOperandoA,segundoOperandoB);
                resultadoResta=sacarResta(primerOperandoA,segundoOperandoB);
                validarDivision=sacarDivision(primerOperandoA,segundoOperandoB,&resultadoDivision);
                resultadoMultiplicacion=sacarMultiplicacion(primerOperandoA,segundoOperandoB);
                factorialPrimerOperando=sacarFactorial(primerOperandoA);
                factorialSegundoOperando=sacarFactorial(segundoOperandoB);
                break;
            case 4 :
                printf("\nEl resultado de A + B es: %d\n",resultadoSuma);
                printf("\nEl resultado de A - B es: %d\n",resultadoResta);
                if(validarDivision==1)
                {
                    printf("\nEl resultado de A / B es: %.2f\n",resultadoDivision);
                }
                else
                {
                    printf("\nNo es posible dividir por cero\n");
                }
                printf("\nEl resultado de A * B es: %d\n",resultadoMultiplicacion);

                if(sacarFactorial(primerOperandoA)==0)
                {
                    printf("\nEl factorial de A no existe\n");
                }
                else
                {
                    printf("\nEl factorial de A es: %d\n",factorialPrimerOperando);
                }

                if(sacarFactorial(segundoOperandoB)==0)
                {
                    printf("\nEl factorial de B no existe\n");
                }
                else
                {
                    printf("\nEl factorial de B es: %d\n",factorialSegundoOperando);
                }
                break;
            case 5 :
                continuar=0;
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
        }
        system("pause");
        system("cls");
    }

























    return 0;
}
