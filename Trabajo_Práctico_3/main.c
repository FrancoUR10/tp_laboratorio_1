#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    FILE* archivoEmpleadosTexto=NULL;
    FILE* archivoHistorialAltasTexto=NULL;
    //FILE* archivoEmpleadosBinario=NULL;
    //FILE* archivoHistorialAltasBinario=NULL;
    LinkedList* listaEmpleados=ll_newLinkedList();
    int contAltas=1;
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        printf("1-CARGAR DATOS (modo texto)\n");
        printf("2-CARGAR DATOS (modo binario)\n");
        printf("3-ALTA\n");
        printf("4-MODIFICAR\n");
        printf("5-BAJA\n");
        printf("6-LISTAR\n");
        printf("7-ORDENAR EMPLEADOS\n");
        printf("8-GUARDAR DATOS (modo texto)\n");
        printf("9-GUARDAR DATOS (modo binario)\n");
        printf("10-SALIR\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                controller_loadFromText(archivoEmpleadosTexto,listaEmpleados,archivoHistorialAltasTexto,&contAltas);
                break;
            case 2:
                //controller_loadFromBinary(archivoEmpleadosBinario,listaEmpleados,archivoHistorialAltasBinario,&contAltas);
                break;
            case 3:
                controller_addEmployee(listaEmpleados,&contAltas);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText(archivoEmpleadosTexto,listaEmpleados,archivoHistorialAltasTexto,&contAltas);
                break;
            case 9:
                //controller_saveAsBinary(archivoEmpleadosBinario,listaEmpleados,archivoHistorialAltasBinario,&contAltas);
                break;
            case 10:
                continuarMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
        }
        system("pause");
        system("cls");
    }
    while(continuarMenu=='s');
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
