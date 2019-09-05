#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define MAX 1000

int main()
{
    int opcionMenu;
    char continuarMenu='s';

    eEmpleado arrayEmpleados[MAX];
    //eEmpleado auxEmpleado;


    inicializarId(arrayEmpleados,MAX);
    do
    {
        opcionMenu=pedirMenu("1-ALTAS\n2-BAJAS\n3-MODIFICAR\n4-INFORMAR\n5-SALIR\n\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                darDeAlta(arrayEmpleados,MAX);
                break;
            case 2:
                printf("\nSe ha dado de baja\n");
                break;
            case 3:
                printf("\nSe ha modificado\n");
                break;
            case 4:
                mostrarArray(arrayEmpleados,MAX);
                break;
            case 5:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');






    return 0;
}
