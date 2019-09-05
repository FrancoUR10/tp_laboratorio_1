#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int pedirMenu(char mensaje[])
{
    int auxOpcion;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxOpcion);
    return auxOpcion;
}
void getString(char unArray[],char mensaje[],char mensajeError[],int min,int max)
{
    int longitud;
    char auxString[256];
    printf("%s",mensaje);
    fflush(stdin);
    gets(auxString);
    longitud=strlen(auxString);
    while(longitud < min || longitud > max)
    {
        printf("%s",mensajeError);
        system("pause");
        system("cls");
        printf("%s",mensaje);
        fflush(stdin);
        gets(auxString);
        longitud=strlen(auxString);
    }
    strcpy(unArray,auxString);
}
int validarSoloNumeros(char unArray[])
{
    int retorno=1;
    int i=0;
    while(unArray[i] != '\0')
    {
        if(unArray[i] < '0' || unArray[i] > '9')
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
int validarSoloLetras(char unArray[])
{
    int retorno=1;
    int i=0;
    while(unArray[i] != '\0')
    {
        if((unArray[i] != ' ') && (unArray[i] < 'a' || unArray[i] > 'z') && (unArray[i] < 'A' || unArray[i] > 'Z'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
int getStringNumeros(char unArray[],char mensaje[],char mensajeErrorRango[],char mensajeErrorNumeros[],int min,int max)
{
    int retorno=0;
    char auxString[256];
    getString(auxString,mensaje,mensajeErrorRango,min,max);
    while(!validarSoloNumeros(auxString))
    {
        printf("%s",mensajeErrorNumeros);
        system("pause");
        system("cls");
        getString(auxString,mensaje,mensajeErrorRango,min,max);
    }
    strcpy(unArray,auxString);
    retorno=1;
    return retorno;
}
int getStringLetras(char unArray[],char mensaje[],char mensajeErrorRango[],char mensajeErrorLetras[],int min,int max)
{
    int retorno=0;
    char auxString[256];
    getString(auxString,mensaje,mensajeErrorRango,min,max);
    while(!validarSoloLetras(auxString))
    {
        printf("%s",mensajeErrorLetras);
        system("pause");
        system("cls");
        getString(auxString,mensaje,mensajeErrorRango,min,max);
    }
    strcpy(unArray,auxString);
    retorno=1;
    return retorno;
}
void inicializarId(eEmpleado unArray[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        unArray[i].id=-1;
        strcpy(unArray[i].nombre,"VACIO");
        strcpy(unArray[i].apellido,"VACIO");
        unArray[i].salario=0;
        unArray[i].sector=-1;
        unArray[i].estaVacio=1;
    }
}
int buscarLugarLibre(eEmpleado unArray[],int tam,int valorId,int flagLugar)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estaVacio==flagLugar)
        {
            if(unArray[i].id==valorId)
            {
                retorno=i;
            }
        }
    }
    return retorno;
}
void mostrarArray(eEmpleado unArray[],int tam)
{
    int indiceLibre;
    int i;
    indiceLibre=buscarEstadoDelArray(unArray,tam,0);
    if(indiceLibre == -1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        for(i=0;i<tam;i++)
        {
            if(unArray[i].estaVacio == 0)
            {
                printf("\nNombre: %s--Apellido: %s--Salario: %.2f--Sector: %d--Id: %d\n",unArray[i].nombre,unArray[i].apellido,unArray[i].salario,unArray[i].sector,unArray[i].id);
            }
        }
    }
}
void darDeAlta(eEmpleado unArray[],int tam)
{
    char auxIdStr[256];
    int auxIdInt;
    int indiceLibre;
    indiceLibre=buscarLugarLibre(unArray,tam,-1,1);
    if(indiceLibre == -1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        getStringNumeros(auxIdStr,"\nIngrese el id del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten numeros\n",1,20);
        auxIdInt=atoi(auxIdStr);
        while(buscarLugarLibre(unArray,tam,auxIdInt,0) != -1)
        {
            printf("\nEl id ingresado ya existe\n");
            getStringNumeros(auxIdStr,"\nIngrese el id del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten numeros\n",1,20);
            auxIdInt=atoi(auxIdStr);
        }
        pedirDatos(unArray,tam,indiceLibre);
        unArray[indiceLibre].id=auxIdInt;
        unArray[indiceLibre].estaVacio=0;
        printf("\nSe ha dado de alta al id: %d\n",auxIdInt);
    }

}
void pedirDatos(eEmpleado unArray[],int tam,int indice)
{
    char auxNombreStr[256];
    char auxApellidoStr[256];
    char auxSalarioStr[256];
    char auxSectorStr[256];

    float auxSalarioFloat;
    int auxSectorInt;

    /*
    getStringNumeros(auxIdStr,"\nIngrese el id del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten numeros\n",1,20);
    auxIdInt=atoi(auxIdStr);
    while(buscarLugarLibre(unArray,tam,auxIdInt) != -1)
    {
        printf("\nEl legajo ingresado ya existe\n");
        getStringNumeros(auxIdStr,"\nIngrese el id del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten numeros\n",1,20);
        auxIdInt=atoi(auxIdStr);
    }
    */
    getStringLetras(auxNombreStr,"\nIngrese el nombre del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten letras\n",1,20);
    getStringLetras(auxApellidoStr,"\nIngrese el apellido del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten letras\n",1,20);
    getStringNumerosFloat(auxSalarioStr,"\nIngrese el salario del empleado: ","\nRango valido entre 1 y 8\n","\nSolo se permiten numeros\n",1,8);
    auxSalarioFloat=atof(auxSalarioStr);
    getStringNumeros(auxSectorStr,"\nIngrese el sector del empleado: ","\nRango valido entre 1 y 10\n","\nSolo se permiten numeros\n",1,10);
    auxSectorInt=atoi(auxSectorStr);

    strcpy(unArray[indice].nombre,auxNombreStr);
    strcpy(unArray[indice].apellido,auxApellidoStr);
    unArray[indice].salario=auxSalarioFloat;
    unArray[indice].sector=auxSectorInt;
}
int validarSoloNumerosFloat(char unArray[])
{
    int contadorPuntos=0;
    int retorno=1;
    int i=0;
    while(unArray[i] != '\0')
    {
        if((unArray[i] !='.') && (unArray[i] < '0' || unArray[i] > '9'))
        {
            retorno=0;
        }
        if(unArray[i] == '.')
        {
            contadorPuntos++;
        }
        i++;
    }
    if(retorno==1)
    {
        if(contadorPuntos > 1)
        {
            retorno=0;
        }
    }
    return retorno;
}
int getStringNumerosFloat(char unArray[],char mensaje[],char mensajeErrorRango[],char mensajeErrorNumeros[],int min,int max)
{
    int retorno=0;
    char auxString[256];
    getString(auxString,mensaje,mensajeErrorRango,min,max);
    while(!validarSoloNumerosFloat(auxString))
    {
        printf("%s",mensajeErrorNumeros);
        system("pause");
        system("cls");
        getString(auxString,mensaje,mensajeErrorRango,min,max);
    }
    strcpy(unArray,auxString);
    retorno=1;
    return retorno;
}
void darDeBaja(eEmpleado unArray[],int tam)
{
    char auxIdStr[256];
    int auxIdInt;
    int indiceLibre;
    int indiceResultadoDeBusqueda;

    indiceLibre=buscarEstadoDelArray(unArray,tam,0);
    if(indiceLibre == -1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        getStringNumeros(auxIdStr,"\nIngrese el id del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten numeros\n",1,20);
        auxIdInt=atoi(auxIdStr);
        indiceResultadoDeBusqueda=buscarLugarLibre(unArray,tam,auxIdInt,0);
        if(indiceResultadoDeBusqueda == -1)
        {
            printf("\nNo existe el id ingresado\n");
        }
        else
        {
            unArray[indiceResultadoDeBusqueda].estaVacio=-1;
            printf("\nSe ha dado de baja al id %d\n",auxIdInt);
        }
    }

}
int buscarEstadoDelArray(eEmpleado unArray[],int tam,int estadoDelIndice)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estaVacio==estadoDelIndice)
        {
            retorno=i;
        }
    }
    return retorno;
}
void modificarArray(eEmpleado unArray[],int tam)
{
    char auxIdStr[256];
    int auxIdInt;
    int indiceLibre;
    int indiceResultadoDeBusqueda;

    indiceLibre=buscarEstadoDelArray(unArray,tam,0);
    if(indiceLibre == -1)
    {
        printf("\nTodos los lugares se encuentran libres\n");
    }
    else
    {
        getStringNumeros(auxIdStr,"\nIngrese el id del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten numeros\n",1,20);
        auxIdInt=atoi(auxIdStr);
        indiceResultadoDeBusqueda=buscarLugarLibre(unArray,tam,auxIdInt,0);
        if(indiceResultadoDeBusqueda == -1)
        {
            printf("\nNo existe el id ingresado\n");
        }
        else
        {
            pedirDatos(unArray,tam,indiceResultadoDeBusqueda);
            printf("\nSe ha modificado el id %d\n",auxIdInt);
        }
    }
}
