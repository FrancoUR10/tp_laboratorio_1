#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "Empleado.h"

int main()
{
    FILE* archivoEmpleados=NULL;
    LinkedList* listaEmpleados=ll_newLinkedList();
    int contAltas=1;
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        printf("1-CARGAR DATOS\n");
        printf("2-ALTA\n");
        printf("3-BAJA\n");
        printf("4-MODIFICAR\n");
        printf("5-ORDENAR\n");
        printf("6-INFORMAR\n");
        printf("7-SALIR\n");
        printf("8-GUARDAR DATOS\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                empleado_cargarDatos(archivoEmpleados,listaEmpleados,&contAltas);
                break;
            case 2:
                empleado_darDeAlta(listaEmpleados,&contAltas);
                break;
            case 3:
                empleado_darDeBaja(listaEmpleados);
                break;
            case 4:
                empleado_modificarDatos(listaEmpleados);
                break;
            case 5:
                empleado_ordenarEmpleados(listaEmpleados);
                break;
            case 6:
                empleado_mostrarListaEmpleados(listaEmpleados);
                break;
            case 7:
                continuarMenu='n';
                break;
            case 8:
                empleado_guardarDatos(archivoEmpleados,listaEmpleados,&contAltas);
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
