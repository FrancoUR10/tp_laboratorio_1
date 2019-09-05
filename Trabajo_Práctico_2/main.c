#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define MAX 1000

int main()
{
    int opcionMenu;
    char continuarMenu='s';

    eEmpleado arrayEmpleados[MAX];

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
                darDeBaja(arrayEmpleados,MAX);
                break;
            case 3:
                modificarArray(arrayEmpleados,MAX);
                break;
            case 4:
                mostrarArray(arrayEmpleados,MAX);
                break;
            case 5:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\a\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');






    return 0;
}
