#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "Empleado.h"

int main()
{
    FILE* archivoTexto=NULL;
    FILE* archivoBinario=NULL;
    LinkedList* listaEmpleados=ll_newLinkedList();
    int contAltas=1;
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        printf("1-CARGAR DATOS(modo texto)\n");
        printf("2-CARGAR DATOS(modo binario)\n");
        printf("3-ALTA\n");
        printf("4-BAJA\n");
        printf("5-MODIFICAR\n");
        printf("6-ORDENAR\n");
        printf("7-INFORMAR\n");
        printf("8-GUARDAR DATOS(modo texto)\n");
        printf("9-GUARDAR DATOS(modo binario)\n");
        printf("10-SALIR\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                empleado_cargarDatosModoTexto(archivoTexto,listaEmpleados,&contAltas);
                break;
            case 2:
                empleado_cargarDatosModoBinario(archivoBinario,listaEmpleados,&contAltas);
                break;
            case 3:
                empleado_darDeAlta(listaEmpleados,&contAltas);
                break;
            case 4:
                empleado_darDeBaja(listaEmpleados);
                break;
            case 5:
                empleado_modificarDatos(listaEmpleados);
                break;
            case 6:
                empleado_ordenarEmpleados(listaEmpleados);
                break;
            case 7:
                empleado_mostrarListaEmpleados(listaEmpleados);
                break;
            case 8:
                empleado_guardarDatosModoTexto(archivoTexto,listaEmpleados,&contAltas);
                break;
            case 9:
                empleado_guardarDatosModoBinario(archivoBinario,listaEmpleados,&contAltas);
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
