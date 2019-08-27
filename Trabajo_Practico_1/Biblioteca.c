#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int getInt(char mensaje[])
{
    int auxNumero;
    printf(mensaje);
    scanf("%d",&auxNumero);
    fflush(stdin);
    return auxNumero;
}
int sacarSuma(int sumandosUno,int sumandosDos)
{
    int resultadoSuma;
    resultadoSuma=sumandosUno+sumandosDos;
    return resultadoSuma;
}
int sacarResta(int minuendo,int sustraendo)
{
    int resultadoResta;
    resultadoResta=minuendo-sustraendo;
    return resultadoResta;
}
int sacarMultiplicacion(int factorUno,int factorDos)
{
    int resultadoMultiplicacion;
    resultadoMultiplicacion=factorUno*factorDos;
    return resultadoMultiplicacion;
}
int sacarDivision(int dividendo,int divisor,float *resultadoDivision)
{
    float auxResultado;
    int retorno=0;
    if(divisor != 0)
    {
        auxResultado=(float)dividendo/divisor;
        *resultadoDivision=auxResultado;
        retorno=1;
    }
    return retorno;
}
int sacarFactorial(int operando)
{
    int resultadoFactoreo;
    if(operando < 0)
    {
        return 0;
    }
    else if(operando == 0 || operando == 1)
    {
        resultadoFactoreo=1;
    }
    else
    {
        resultadoFactoreo=operando * sacarFactorial(operando-1);
    }
    return resultadoFactoreo;
}
