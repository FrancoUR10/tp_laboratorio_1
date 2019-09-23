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
                printf("\nNombre: %s  Apellido: %s  Salario: %.2f  Sector: %d  Id: %d\n",unArray[i].nombre,unArray[i].apellido,unArray[i].salario,unArray[i].sector,unArray[i].id);
            }
        }
        mostrarPromedioDeSalarios(unArray,tam);
    }
}
void darDeAlta(eEmpleado unArray[],int tam,int* contDadosDeAlta)
{
    int auxIdInt;
    int indiceLibre;
    indiceLibre=buscarLugarLibre(unArray,tam,-1,1);
    if(indiceLibre == -1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        auxIdInt=*contDadosDeAlta;

        pedirDatos(unArray,tam,indiceLibre);
        unArray[indiceLibre].id=auxIdInt;
        unArray[indiceLibre].estaVacio=0;
        printf("\nSe ha dado de alta al id: %d\n",auxIdInt);
        *contDadosDeAlta=auxIdInt+1;
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

    getStringLetras(auxNombreStr,"\nIngrese el nombre del empleado: ","\nRango valido entre 1 y 20\a\n","\nSolo se permiten letras\a\n",1,20);
    getStringLetras(auxApellidoStr,"\nIngrese el apellido del empleado: ","\nRango valido entre 1 y 20\a\n","\nSolo se permiten letras\a\n",1,20);
    getStringNumerosFloat(auxSalarioStr,"\nIngrese el salario del empleado: ","\nRango valido entre 1 y 8\a\n","\nSolo se permiten numeros\a\n",1,8);
    auxSalarioFloat=atof(auxSalarioStr);
    getStringNumeros(auxSectorStr,"\nIngrese el sector del empleado: ","\nRango valido entre 1 y 10\a\n","\nSolo se permiten numeros\a\n",1,10);
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
        getStringNumeros(auxIdStr,"\nIngrese el id del empleado: ","\nRango valido entre 1 y 20\a\n","\nSolo se permiten numeros\a\n",1,20);
        auxIdInt=atoi(auxIdStr);
        indiceResultadoDeBusqueda=buscarLugarLibre(unArray,tam,auxIdInt,0);
        if(indiceResultadoDeBusqueda == -1)
        {
            printf("\nNo existe el id ingresado\n");
        }
        else
        {
            unArray[indiceResultadoDeBusqueda].estaVacio=1;
            unArray[indiceResultadoDeBusqueda].id=-1;
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
        getStringNumeros(auxIdStr,"\nIngrese el id del empleado: ","\nRango valido entre 1 y 20\a\n","\nSolo se permiten numeros\a\n",1,20);
        auxIdInt=atoi(auxIdStr);
        indiceResultadoDeBusqueda=buscarLugarLibre(unArray,tam,auxIdInt,0);
        if(indiceResultadoDeBusqueda == -1)
        {
            printf("\nNo existe el id ingresado\n");
        }
        else
        {
            menuModificarDatos(unArray,tam,indiceResultadoDeBusqueda);
        }
    }
}
void mostrarPromedioDeSalarios(eEmpleado unArray[],int tam)
{
    int contadorSuperanElPromedio=0;
    float acumuladorDeSalarios=0;
    int contadorDeAltas=0;
    float promedioDeSalarios=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estaVacio==0)
        {
            contadorDeAltas++;
            acumuladorDeSalarios+=unArray[i].salario;
        }
    }
    promedioDeSalarios=(float)acumuladorDeSalarios/contadorDeAltas;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].estaVacio==0)
        {
            if(unArray[i].salario>promedioDeSalarios)
            {
                contadorSuperanElPromedio++;
            }
        }
    }
    printf("\nSuma total de salarios: %.2f\nPromedio de salarios: %.2f\nCantidad de empleados que superan el salario promedio: %d\n",acumuladorDeSalarios,promedioDeSalarios,contadorSuperanElPromedio);
}
void ordenarArrayAscendiente(eEmpleado unArray[],int tam)
{
    int i;
    int j;
    eEmpleado auxArray;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(unArray[i].estaVacio==0)
            {
                if(unArray[i].sector>unArray[j].sector)
                {
                    auxArray=unArray[i];
                    unArray[i]=unArray[j];
                    unArray[j]=auxArray;
                }
                else if(unArray[i].sector==unArray[j].sector)
                {
                    if(strcmp(unArray[i].apellido,unArray[j].apellido)==1)
                    {
                        auxArray=unArray[i];
                        unArray[i]=unArray[j];
                        unArray[j]=auxArray;
                    }
                }
            }
        }
    }
}
void ordenarArrayDescendiente(eEmpleado unArray[],int tam)
{
    int i;
    int j;
    eEmpleado auxArray;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(unArray[i].estaVacio==0)
            {
                if(unArray[i].sector<unArray[j].sector)
                {
                    auxArray=unArray[i];
                    unArray[i]=unArray[j];
                    unArray[j]=auxArray;
                }
                else if(unArray[i].sector==unArray[j].sector)
                {
                    if(strcmp(unArray[i].apellido,unArray[j].apellido)==-1)
                    {
                        auxArray=unArray[i];
                        unArray[i]=unArray[j];
                        unArray[j]=auxArray;
                    }
                }
            }
        }
    }
}
void ordenarListaDeEmpleados(eEmpleado unArray[],int tam,int opcionTipoDeOrden)
{
    if(opcionTipoDeOrden==1)
    {
        ordenarArrayAscendiente(unArray,tam);
    }
    else if(opcionTipoDeOrden==0)
    {
        ordenarArrayDescendiente(unArray,tam);
    }
}
void menuModificarDatos(eEmpleado unArray[],int tam,int indice)
{
    char auxNombreStr[256];
    char auxApellidoStr[256];
    char auxSalarioStr[256];
    char auxSectorStr[256];

    float auxSalarioFloat;
    int auxSectorInt;

    int opcionAModificar;
    char continuarOpcion='s';

    system("cls");
    do
    {
        opcionAModificar=pedirMenu("Que dato del empleado desea modificar?: \n1-NOMBRE\n2-APELLIDO\n3-SALARIO\n4-SECTOR\n5-CANCELAR MODIFICACION\n\nIngrese una opcion: ");
        switch(opcionAModificar)
        {
            case 1:
                getStringLetras(auxNombreStr,"\nIngrese el nombre del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten letras\n",1,20);
                strcpy(unArray[indice].nombre,auxNombreStr);
                printf("\nSe ha modificado el nombre\n");
                continuarOpcion='n';
                break;
            case 2:
                getStringLetras(auxApellidoStr,"\nIngrese el apellido del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten letras\n",1,20);
                strcpy(unArray[indice].apellido,auxApellidoStr);
                printf("\nSe ha modificado el apellido\n");
                continuarOpcion='n';
                break;
            case 3:
                getStringNumerosFloat(auxSalarioStr,"\nIngrese el salario del empleado: ","\nRango valido entre 1 y 8\n","\nSolo se permiten numeros\n",1,8);
                auxSalarioFloat=atof(auxSalarioStr);
                unArray[indice].salario=auxSalarioFloat;
                printf("\nSe ha modificado el salario\n");
                continuarOpcion='n';
                break;
            case 4:
                getStringNumeros(auxSectorStr,"\nIngrese el sector del empleado: ","\nRango valido entre 1 y 10\n","\nSolo se permiten numeros\n",1,10);
                auxSectorInt=atoi(auxSectorStr);
                unArray[indice].sector=auxSectorInt;
                printf("\nSe ha modificado el sector\n");
                continuarOpcion='n';
                break;
            case 5:
                printf("\nModificacion cancelada\n");
                continuarOpcion='n';
                break;
            default:
                printf("\nOpcion Ingresada no valida\a\n");
                system("pause");
                system("cls");
                break;
        }
    }
    while(continuarOpcion=='s');
}
void harcodearPrimerPosicionLibre(eEmpleado unArray[],int tam,int parametroId,char parametroNombre[],char parametroApellido[],float parametroSalario,int parametroSector)
{
    int indiceLibre;
    indiceLibre=buscarLugarLibre(unArray,tam,-1,1);
    if(indiceLibre==-1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        unArray[indiceLibre].id=parametroId;
        strcpy(unArray[indiceLibre].nombre,parametroNombre);
        strcpy(unArray[indiceLibre].apellido,parametroApellido);
        unArray[indiceLibre].salario=parametroSalario;
        unArray[indiceLibre].sector=parametroSector;
        unArray[indiceLibre].estaVacio=0;
    }
}
