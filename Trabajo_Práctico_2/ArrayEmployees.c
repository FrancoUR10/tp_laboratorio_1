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
int initEmployees(eEmployee* list, int len)
{
    int retorno=-1;
    int i;
    if((list != NULL) && (len > 0))
    {
        for(i=0;i<len;i++)
        {
            list[i].id=-1;
            strcpy(list[i].name,"VACIO");
            strcpy(list[i].lastName,"VACIO");
            list[i].salary=0;
            list[i].sector=-1;
            list[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}
int findEmployeeById(eEmployee* list, int len,int id)
{
    int retorno=-1;
    int i;
    if((list != NULL) && (len > 0))
    {
        for(i=0;i<len;i++)
        {
            if((list[i].isEmpty==0) && (list[i].id==id))
            {
                retorno=i;
            }
        }
    }
    return retorno;
}
int printEmployees(eEmployee* list, int length)
{
    int indiceLibre;
    int i;
    int retorno=-1;
    if((list != NULL) && (length > 0))
    {
        indiceLibre=buscarEstadoDelArray(list,length,0);
        if(indiceLibre == -1)
        {
            printf("\nTodos los lugares se encuentran libres\n");
        }
        else
        {
            for(i=0;i<length;i++)
            {
                if(list[i].isEmpty == 0)
                {
                    printf("\nNombre: %s  Apellido: %s  Salario: %.2f  Sector: %d  Id: %d\n",list[i].name,list[i].lastName,list[i].salary,list[i].sector,list[i].id);
                }
            }
            mostrarPromedioDeSalarios(list,length);
            retorno=0;
        }
    }
    return retorno;
}
void mostrarArray(eEmployee unArray[],int tam)
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
            if(unArray[i].isEmpty == 0)
            {
                printf("\nNombre: %s  Apellido: %s  Salario: %.2f  Sector: %d  Id: %d\n",unArray[i].name,unArray[i].lastName,unArray[i].salary,unArray[i].sector,unArray[i].id);
            }
        }
        mostrarPromedioDeSalarios(unArray,tam);
    }
}
void darDeAlta(eEmployee unArray[],int tam,int* contDadosDeAlta)
{
    int auxIdInt;
    int indiceLibre;
    indiceLibre=buscarEstadoDelArray(unArray,tam,1);
    if(indiceLibre == -1)
    {
        printf("\nNo quedan lugares libres\n");
    }
    else
    {
        auxIdInt=*contDadosDeAlta;

        pedirDatos(unArray,tam,indiceLibre);
        unArray[indiceLibre].id=auxIdInt;
        unArray[indiceLibre].isEmpty=0;
        printf("\nSe ha dado de alta al id: %d\n",auxIdInt);
        *contDadosDeAlta=auxIdInt+1;
    }

}
void pedirDatos(eEmployee unArray[],int tam,int indice)
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

    strcpy(unArray[indice].name,auxNombreStr);
    strcpy(unArray[indice].lastName,auxApellidoStr);
    unArray[indice].salary=auxSalarioFloat;
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
int removeEmployee(eEmployee* list, int len)
{
    char auxIdStr[256];
    int auxIdInt;
    int indiceLibre;
    int indiceResultadoDeBusqueda;
    int retorno=-1;
    if((list != NULL) && (len > 0))
    {
        indiceLibre=buscarEstadoDelArray(list,len,0);
        if(indiceLibre == -1)
        {
            printf("\nTodos los lugares se encuentran libres\n");
        }
        else
        {
            getStringNumeros(auxIdStr,"\nIngrese el id del empleado: ","\nRango valido entre 1 y 20\a\n","\nSolo se permiten numeros\a\n",1,20);
            auxIdInt=atoi(auxIdStr);
            indiceResultadoDeBusqueda=findEmployeeById(list,len,auxIdInt);
            if(indiceResultadoDeBusqueda == -1)
            {
                printf("\nNo existe el id ingresado\n");
            }
            else
            {
                list[indiceResultadoDeBusqueda].isEmpty=1;
                printf("\nSe ha dado de baja al id %d\n",auxIdInt);
                retorno=0;
            }
        }
    }
    return retorno;
}
int buscarEstadoDelArray(eEmployee unArray[],int tam,int estadoDelIndice)
{
    int retorno=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].isEmpty==estadoDelIndice)
        {
            retorno=i;
        }
    }
    return retorno;
}
void modificarArray(eEmployee unArray[],int tam)
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
        indiceResultadoDeBusqueda=findEmployeeById(unArray,tam,auxIdInt);
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
void mostrarPromedioDeSalarios(eEmployee unArray[],int tam)
{
    int contadorSuperanElPromedio=0;
    float acumuladorDeSalarios=0;
    int contadorDeAltas=0;
    float promedioDeSalarios=0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].isEmpty==0)
        {
            contadorDeAltas++;
            acumuladorDeSalarios+=unArray[i].salary;
        }
    }
    promedioDeSalarios=(float)acumuladorDeSalarios/contadorDeAltas;
    for(i=0;i<tam;i++)
    {
        if(unArray[i].isEmpty==0)
        {
            if(unArray[i].salary>promedioDeSalarios)
            {
                contadorSuperanElPromedio++;
            }
        }
    }
    printf("\nSuma total de salarios: %.2f\nPromedio de salarios: %.2f\nCantidad de empleados que superan el salario promedio: %d\n",acumuladorDeSalarios,promedioDeSalarios,contadorSuperanElPromedio);
}
void ordenarArrayAscendiente(eEmployee unArray[],int tam)
{
    int i;
    int j;
    eEmployee auxArray;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(unArray[i].isEmpty==0)
            {
                if(unArray[i].sector>unArray[j].sector)
                {
                    auxArray=unArray[i];
                    unArray[i]=unArray[j];
                    unArray[j]=auxArray;
                }
                else if(unArray[i].sector==unArray[j].sector)
                {
                    if(strcmp(unArray[i].lastName,unArray[j].lastName)==1)
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
void ordenarArrayDescendiente(eEmployee unArray[],int tam)
{
    int i;
    int j;
    eEmployee auxArray;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(unArray[i].isEmpty==0)
            {
                if(unArray[i].sector<unArray[j].sector)
                {
                    auxArray=unArray[i];
                    unArray[i]=unArray[j];
                    unArray[j]=auxArray;
                }
                else if(unArray[i].sector==unArray[j].sector)
                {
                    if(strcmp(unArray[i].lastName,unArray[j].lastName)==-1)
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
int sortEmployees(eEmployee* list, int len, int order)
{
    int retorno=-1;
    if((list != NULL) && (len > 0))
    {
        if(order==1)
        {
            ordenarArrayAscendiente(list,len);
            retorno=0;
        }
        else if(order==0)
        {
            ordenarArrayDescendiente(list,len);
            retorno=0;
        }
    }
    return retorno;
}
void menuModificarDatos(eEmployee unArray[],int tam,int indice)
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
                strcpy(unArray[indice].name,auxNombreStr);
                printf("\nSe ha modificado el nombre\n");
                continuarOpcion='n';
                break;
            case 2:
                getStringLetras(auxApellidoStr,"\nIngrese el apellido del empleado: ","\nRango valido entre 1 y 20\n","\nSolo se permiten letras\n",1,20);
                strcpy(unArray[indice].lastName,auxApellidoStr);
                printf("\nSe ha modificado el apellido\n");
                continuarOpcion='n';
                break;
            case 3:
                getStringNumerosFloat(auxSalarioStr,"\nIngrese el salario del empleado: ","\nRango valido entre 1 y 8\n","\nSolo se permiten numeros\n",1,8);
                auxSalarioFloat=atof(auxSalarioStr);
                unArray[indice].salary=auxSalarioFloat;
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
int addEmployee(eEmployee* list, int len, int* contId, char name[],char lastName[],float salary,int sector)
{
    int retorno=-1;
    int auxId;
    int indiceLibre;
    if((list != NULL) && (len > 0))
    {
        indiceLibre=buscarEstadoDelArray(list,len,1);
        if(indiceLibre==-1)
        {
            printf("\nNo quedan lugares libres\n");
        }
        else
        {
            auxId=*contId;
            list[indiceLibre].id=auxId;
            strcpy(list[indiceLibre].name,name);
            strcpy(list[indiceLibre].lastName,lastName);
            list[indiceLibre].salary=salary;
            list[indiceLibre].sector=sector;
            list[indiceLibre].isEmpty=0;
            *contId=auxId+1;
            retorno=0;
        }
    }
    return retorno;
}
