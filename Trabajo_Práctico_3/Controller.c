#include "Controller.h"

int controller_loadFromText(FILE* archivoTexto,LinkedList* pArrayListEmployee,FILE* historialAltasTexto,int* contAltas)
{
    int seCargo=0;
    Employee* aux;
    char auxIdStr[256];
    char auxNombre[256];
    char auxHorasStr[256];
    char auxSueldoStr[256];
    archivoTexto=fopen("data_modo_texto.csv","r");
    if(archivoTexto!=NULL)
    {
        ll_clear(pArrayListEmployee);
        while(!feof(archivoTexto))
        {
            if(feof(archivoTexto))
            {
                break;
            }
            fscanf(archivoTexto,"%[^,],%[^,],%[^,],%[^\n]\n",auxIdStr,auxNombre,auxHorasStr,auxSueldoStr);
            aux=employee_newParametros(auxIdStr,auxNombre,auxHorasStr,auxSueldoStr);
            ll_add(pArrayListEmployee,aux);
        }
        fclose(archivoTexto);
        historialAltasTexto=fopen("historial_altas_modo_texto.csv","r");
        if(historialAltasTexto!=NULL)
        {
            fscanf(historialAltasTexto,"%[^\n]\n",auxIdStr);
            *contAltas=atoi(auxIdStr);
            fclose(historialAltasTexto);
            printf("\nSe han cargado los datos en modo texto\n");
            seCargo=1;
        }
    }
    return seCargo;
}
int controller_loadFromBinary(FILE* archivoBinario,LinkedList* pArrayListEmployee,FILE* historialAltasBinario,int* contAltas)
{
    int seCargo=0;
    Employee* auxP=NULL;
    archivoBinario=fopen("data_modo_binario.bin","rb");
    if(archivoBinario!=NULL)
    {
        ll_clear(pArrayListEmployee);
        while(!feof(archivoBinario))
        {
            auxP=employee_new();
            fread(auxP,sizeof(Employee),1,archivoBinario);
            if(feof(archivoBinario))
            {
                break;
            }
            ll_add(pArrayListEmployee,auxP);
        }
        fclose(archivoBinario);
        historialAltasBinario=fopen("historial_altas_modo_binario.bin","rb");
        if(historialAltasBinario!=NULL)
        {
            fread(contAltas,sizeof(int),1,historialAltasBinario);
            fclose(historialAltasBinario);
            printf("\nSe han cargado los datos en modo binario\n");
            seCargo=1;
        }
    }
    return seCargo;
}
int controller_addEmployee(LinkedList* pArrayListEmployee,int* contAltas)
{
    int sePudo=-1;
    int auxIdInt=*contAltas;
    char auxHorasStr[256];
    char auxSueldoStr[256];
    char auxNombreStr[256];
    char auxIdChar[256];
    char confirmacion;
    Employee* auxDatos;
    int ingresoSecuencialValido=1;

    if(ingresoSecuencialValido==1)
    {
        if(!getStrLetras("\nIngrese el nombre: ",auxNombreStr,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumeros("\nIngrese la cant. de horas trabajadas: ",auxHorasStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1 y el 24\n",1,24,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumeros("\nIngrese el sueldo: ",auxSueldoStr,"\nSolo se permiten numeros\n","Numero valido entre el 1000 y el 10000",1000,10000,3))
        {
            ingresoSecuencialValido=0;
        }
    }
    if(ingresoSecuencialValido==1)
    {
        itoa(auxIdInt,auxIdChar,10);
        auxDatos=employee_newParametros(auxIdChar,auxNombreStr,auxHorasStr,auxSueldoStr);
        if(auxDatos!=NULL)
        {
            confirmacion=confirmarCambios("\nEsta seguro que desea dar de alta? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
            if(confirmacion==1)
            {
                ll_add(pArrayListEmployee,auxDatos);
                *contAltas=auxIdInt+1;
                sePudo=1;
                printf("\nSe ha dado de alta al id numero %d\n",auxIdInt);
            }
            else
            {
                sePudo=0;
                printf("\nAlta cancelada por el usuario\n");
            }
        }
    }
    if(ingresoSecuencialValido==0 || auxDatos==NULL)
    {
        printf("\nAlta Cancelada\n");
    }
    return sePudo;
}
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int sePudo=-1;
    int indiceResultadoBusqueda;
    char auxIdStr[256];
    int auxIdInt;
    if(ll_isEmpty(pArrayListEmployee)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        controller_ListEmployee(pArrayListEmployee);
        if(!getStrNumerosSinRango("\nIngrese el id a modificar: ",auxIdStr,"\nSolo se permiten numeros\n",3))
        {
            printf("\nModificacion cancelada\n");
        }
        else
        {
            auxIdInt=atoi(auxIdStr);
            indiceResultadoBusqueda=buscarEmpleadoPorId(pArrayListEmployee,auxIdInt);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                controller_pedirDatosAEleccion(pArrayListEmployee,indiceResultadoBusqueda);
                sePudo=1;
            }
        }
    }
    return sePudo;
}
void controller_pedirDatosAEleccion(LinkedList* pArrayListEmployee,int indice)
{
    int flagPrimerCambio=1;
    int confirmaciones;
    char auxNombreStr[256];
    char auxHorasStr[256];
    char auxSueldoStr[256];
    Employee* datosActuales;
    Employee copiaDatos;
    Employee* auxDatos;
    int opcionMenu;
    char continuarMenu='s';

    datosActuales=ll_get(pArrayListEmployee,indice);
    copiaDatos=*datosActuales;
    auxDatos=&copiaDatos;
    do
    {
        system("cls");
        printf("\nID          NOMBRE        HORAS     SUELDO\n");

        printf("\nDatos actuales seleccionados:\n");
        controller_mostrarUnEmpleado(datosActuales);

        printf("\nDatos a modificar:\n");
        controller_mostrarUnEmpleado(auxDatos);

        printf("\nQue dato desea modificar?:\n");
        printf("1-NOMBRE\n");
        printf("2-HORAS\n");
        printf("3-SUELDO\n");
        printf("4-CONFIRMAR CAMBIOS\n");
        printf("5-FINALIZAR MODIFICACION\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
        case 1:
            if(getStrLetras("\nIngrese el nombre a modificar: ",auxNombreStr,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
            {
                employee_setNombre(auxDatos,auxNombreStr);
                printf("\nSe ha ingresado correctamente el nombre\n");
                flagPrimerCambio=0;
            }
            system("pause");
            break;
        case 2:
            if(getStrNumeros("\nIngrese las horas a modificar: ",auxHorasStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1 y el 24\n",1,24,3))
            {
                employee_setHorasTrabajadas(auxDatos,atoi(auxHorasStr));
                printf("\nSe ha ingresado correctamente la hora\n");
                flagPrimerCambio=0;
            }
            system("pause");
            break;
        case 3:
            if(getStrNumeros("\nIngrese el sueldo a modificar: ",auxSueldoStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 1000 y el 10000\n",1000,10000,3))
            {
                employee_setSueldo(auxDatos,atof(auxSueldoStr));
                printf("\nSe ha ingresado correctamente el sueldo\n");
                flagPrimerCambio=0;
            }
            system("pause");
            break;
        case 4:
            if(flagPrimerCambio==1)
            {
                printf("\nNo se ha realizado ningun cambio que confirmar\n");
            }
            else
            {
                confirmaciones=confirmarCambios("\nDesea confirmar los cambios realizados? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmaciones==1)
                {
                    *datosActuales=*auxDatos;
                    printf("\nSe han confirmado los cambios realizados\n");
                    flagPrimerCambio=1;
                }
                else if(confirmaciones==0)
                {
                    printf("\nConfirmacion cancelada por el usuario\n");
                }
            }
            system("pause");
            break;
        case 5:
            if(flagPrimerCambio==0)
            {
                confirmaciones=confirmarCambios("\nEsta seguro que desea salir sin confirmar cambios? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmaciones==1)
                {
                    printf("\nModificacion finalizada\n");
                    continuarMenu='n';
                }
            }
            else
            {
                printf("\nModificacion finalizada\n");
                continuarMenu='n';
            }
            break;
        default:
            printf("\nOpcion ingresada no valida\n");
            system("pause");
        }
    }
    while(continuarMenu=='s');
}
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int sePudo=-1;
    int confirmacion;
    int indiceResultadoBusqueda;
    char auxIdStr[256];
    int auxIdInt;
    if(ll_isEmpty(pArrayListEmployee)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        controller_ListEmployee(pArrayListEmployee);
        if(!getStrNumerosSinRango("\nIngrese el id a dar de baja: ",auxIdStr,"\nSolo se permiten numeros\n",3))
        {
            printf("\nBaja cancelada\n");
        }
        else
        {
            auxIdInt=atoi(auxIdStr);
            indiceResultadoBusqueda=buscarEmpleadoPorId(pArrayListEmployee,auxIdInt);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                confirmacion=confirmarCambios("\nEsta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    ll_remove(pArrayListEmployee,indiceResultadoBusqueda);
                    sePudo=1;
                    printf("\nSe ha dado de baja al id numero %d\n",auxIdInt);
                }
                else if(confirmacion==0)
                {
                    sePudo=0;
                    printf("\nBaja cancelada por el usuario\n");
                }
            }
        }
    }
    return sePudo;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int seMostro=0;
    int i;
    int len;
    Employee* aux;
    if(ll_isEmpty(pArrayListEmployee)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        printf("\nID          NOMBRE        HORAS     SUELDO\n");
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            aux=(Employee*)ll_get(pArrayListEmployee,i);
            controller_mostrarUnEmpleado(aux);
        }
        seMostro=1;
    }
    return seMostro;
}
int controller_mostrarUnEmpleado(Employee* empleado)
{
    int seMostro=0;
    if(empleado != NULL)
    {
        seMostro=1;
        printf("\n%d\t",empleado->id);
        printf("%10s",empleado->nombre);
        printf("%10d",empleado->horasTrabajadas);
        printf("%12d\n",empleado->sueldo);
    }
    return seMostro;
}
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int seOrdeno=0;
    int opcionOrden;
    char salirMenu='s';
    if(ll_isEmpty(pArrayListEmployee)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        do
        {
            system("cls");
            printf("Por cual criterio desea ordenar?:\n");
            printf("1-ORDENAR POR ID\n");
            printf("2-ORDENAR POR NOMBRE\n");
            printf("3-ORDENAR POR HORAS\n");
            printf("4-ORDENAR POR SUELDO\n");
            printf("5-CANCELAR ORDENAMIENTO\n");
            opcionOrden=getInt("\nIngrese una opcion: ");
            switch(opcionOrden)
            {
            case 1:
                ll_sort(pArrayListEmployee,compararPorId,1);
                seOrdeno=1;
                printf("\nSe ha ordenado por id\n");
                salirMenu='n';
                break;
            case 2:
                ll_sort(pArrayListEmployee,compararPorNombre,1);
                seOrdeno=1;
                printf("\nSe ha ordenado por nombre\n");
                salirMenu='n';
                break;
            case 3:
                ll_sort(pArrayListEmployee,compararPorHoras,1);
                seOrdeno=1;
                printf("\nSe ha ordenado por las horas trabajadas\n");
                salirMenu='n';
                break;
            case 4:
                ll_sort(pArrayListEmployee,compararPorSueldo,1);
                seOrdeno=1;
                printf("\nSe ha ordenado por sueldo\n");
                salirMenu='n';
                break;
            case 5:
                printf("\nOrdenamiento cancelado\n");
                salirMenu='n';
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
                system("pause");
            }
        }
        while(salirMenu=='s');
    }
    return seOrdeno;
}
int controller_saveAsText(FILE* archivoTexto,LinkedList* pArrayListEmployee,FILE* historialAltasTexto,int* contAltas)
{
    int sePudo=0;
    int i;
    int len;
    char auxIdStr[256];
    char auxNombreStr[256];
    char auxHorasStr[256];
    char auxSueldoStr[256];
    Employee* aux;
    if(ll_isEmpty(pArrayListEmployee)==1)
    {
        printf("\nNo hay ningun elemento para guardar en la lista\n");
    }
    else
    {
        archivoTexto=fopen("data_modo_texto.csv","w");
        if(archivoTexto != NULL)
        {
            len=ll_len(pArrayListEmployee);
            for(i=0; i<len; i++)
            {
                aux=ll_get(pArrayListEmployee,i);
                itoa(aux->id,auxIdStr,10);
                employee_getNombre(aux,auxNombreStr);
                itoa(aux->horasTrabajadas,auxHorasStr,10);
                itoa(aux->sueldo,auxSueldoStr,10);
                fprintf(archivoTexto,"%s,%s,%s,%s\n",auxIdStr,auxNombreStr,auxHorasStr,auxSueldoStr);
            }
            fclose(archivoTexto);
            historialAltasTexto=fopen("historial_altas_modo_texto.csv","w");
            if(historialAltasTexto!=NULL)
            {
                itoa(*contAltas,auxIdStr,10);
                fprintf(historialAltasTexto,"%s\n",auxIdStr);
                fclose(historialAltasTexto);
                printf("\nSe han guardado los datos en modo texto\n");
                sePudo=1;
            }
        }
    }
    return sePudo;
}
int controller_saveAsBinary(FILE* archivoBinario,LinkedList* pArrayListEmployee,FILE* historialAltasBinario,int* contAltas)
{
    int sePudo=0;
    int i;
    int len;
    Employee* auxP;
    if(ll_isEmpty(pArrayListEmployee)==1)
    {
        printf("\nNo hay ningun elemento para guardar en la lista\n");
    }
    else
    {
        archivoBinario=fopen("data_modo_binario.bin","wb");
        if(archivoBinario != NULL)
        {
            len=ll_len(pArrayListEmployee);
            for(i=0; i<len; i++)
            {
               auxP = ll_get(pArrayListEmployee,i);
               fwrite(auxP,sizeof(Employee),1,archivoBinario);
            }
            fclose(archivoBinario);
            historialAltasBinario=fopen("historial_altas_modo_binario.bin","wb");
            if(historialAltasBinario!=NULL)
            {
                fwrite(contAltas,sizeof(int),1,historialAltasBinario);
                fclose(historialAltasBinario);
                printf("\nSe han guardado los datos en modo binario\n");
                sePudo=1;
            }
        }
    }
    return sePudo;
}
