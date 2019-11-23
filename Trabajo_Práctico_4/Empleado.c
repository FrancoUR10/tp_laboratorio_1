#include "Empleado.h"

eEmpleado* empleado_nuevoEmpleado()
{
    eEmpleado* unEmpleado=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(unEmpleado!=NULL)
    {
        unEmpleado->id=0;
        strcpy(unEmpleado->nombre,"VACIO");
        strcpy(unEmpleado->apellido,"VACIO");
        unEmpleado->edad=-1;
        unEmpleado->sueldo=-1;
    }
    return unEmpleado;
}
int empleado_borrarEmpleado(eEmpleado* empleado)
{
    int seLibero=0;
    if(empleado!=NULL)
    {
        free(empleado);
        seLibero=1;
    }
    return seLibero;
}
int empleado_setId(eEmpleado* empleado,int id)
{
    int retorno=0;
    if((empleado!=NULL) && (id > 0))
    {
        empleado->id=id;
        retorno=1;
    }
    return retorno;
}
int empleado_setNombre(eEmpleado* empleado,char* nombre)
{
    int retorno=0;
    if((empleado!=NULL) && (strlen(nombre) > 2))
    {
        strcpy(empleado->nombre,nombre);
        retorno=1;
    }
    return retorno;
}
int empleado_setApellido(eEmpleado* empleado,char* apellido)
{
    int retorno=0;
    if((empleado!=NULL) && (strlen(apellido) > 2))
    {
        strcpy(empleado->apellido,apellido);
        retorno=1;
    }
    return retorno;
}
int empleado_setEdad(eEmpleado* empleado,int edad)
{
    int retorno=0;
    if((empleado!=NULL) && (edad > 0))
    {
        empleado->edad=edad;
        retorno=1;
    }
    return retorno;
}
int empleado_setSueldo(eEmpleado* empleado,float sueldo)
{
    int retorno=0;
    if((empleado!=NULL) && (sueldo > 0))
    {
        empleado->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}
int empleado_getId(eEmpleado* empleado,int* id)
{
    int retorno=0;
    if(empleado!=NULL && id!=NULL)
    {
        *id=empleado->id;
        retorno=1;
    }
    return retorno;
}
int empleado_getNombre(eEmpleado* empleado,char* nombre)
{
    int retorno=0;
    if(empleado!=NULL && nombre!=NULL)
    {
        strcpy(nombre,empleado->nombre);
        retorno=1;
    }
    return retorno;
}
int empleado_getApellido(eEmpleado* empleado,char* apellido)
{
    int retorno=0;
    if(empleado!=NULL && apellido!=NULL)
    {
        strcpy(apellido,empleado->apellido);
        retorno=1;
    }
    return retorno;
}
int empleado_getEdad(eEmpleado* empleado,int* edad)
{
    int retorno=0;
    if(empleado!=NULL && edad!=NULL)
    {
        *edad=empleado->edad;
        retorno=1;
    }
    return retorno;
}
int empleado_getSueldo(eEmpleado* empleado,float* sueldo)
{
    int retorno=0;
    if(empleado!=NULL && sueldo!=NULL)
    {
        *sueldo=empleado->sueldo;
        retorno=1;
    }
    return retorno;
}
eEmpleado* empleado_nuevoEmpleadoParametros(char* id,char* nombre,char* apellido,char* edad,char* sueldo)
{
    eEmpleado* unEmpleado=NULL;
    if((id!=NULL) && (nombre!=NULL) && (apellido!=NULL) && (edad!=NULL) && (sueldo!=NULL))
    {
        unEmpleado=empleado_nuevoEmpleado();
        if(unEmpleado!=NULL)
        {
            if(!empleado_setId(unEmpleado,atoi(id)) || !empleado_setNombre(unEmpleado,nombre) || !empleado_setApellido(unEmpleado,apellido) || !empleado_setEdad(unEmpleado,atoi(edad)) || !empleado_setSueldo(unEmpleado,atof(sueldo)))
            {
                empleado_borrarEmpleado(unEmpleado);
                unEmpleado=NULL;
            }
        }
    }
    return unEmpleado;
}
int empleado_mostrarUnEmpleado(eEmpleado* unEmpleado)
{
    int seMostro=0;
    if(unEmpleado!=NULL)
    {
        printf("\n%d",unEmpleado->id);
        printf("%14s",unEmpleado->nombre);
        printf("%14s",unEmpleado->apellido);
        printf("%7d",unEmpleado->edad);
        printf("%12.2f\n",unEmpleado->sueldo);
        seMostro=1;
    }
    return seMostro;
}
void empleado_mostrarListaEmpleados(LinkedList* listaEmpleados)
{
    eEmpleado* aux;
    int i;
    int len=ll_len(listaEmpleados);
    if(listaEmpleados!=NULL)
    {
        if(listaEmpleados!=NULL && ll_isEmpty(listaEmpleados)==1)
        {
            printf("\nNo hay ningun elemento en la lista\n");
        }
        else
        {
            printf("\nID       NOMBRE      APELLIDO     EDAD   SUELDO\n");
            for(i=0;i<len;i++)
            {
                aux=(eEmpleado*)ll_get(listaEmpleados,i);
                empleado_mostrarUnEmpleado(aux);
            }
        }
    }
}
int empleado_buscarPorId(LinkedList* listaEmpleados,int idABuscar)
{
    int retorno=-1;
    eEmpleado* aux;
    int i;
    int len=ll_len(listaEmpleados);
    if(listaEmpleados!=NULL)
    {
        for(i=0;i<len;i++)
        {
            aux=(eEmpleado*)ll_get(listaEmpleados,i);
            if(aux->id==idABuscar)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int empleado_compararPorId(void* empleado1,void* empleado2)
{
    int comparacion=-1;
    int id1;
    int id2;
    eEmpleado* emp1=(eEmpleado*)empleado1;
    eEmpleado* emp2=(eEmpleado*)empleado2;
    empleado_getId(emp1,&id1);
    empleado_getId(emp2,&id2);
    if(id1 > id2)
    {
        comparacion=1;
    }
    else if(id1==id2)
    {
        comparacion=0;
    }
    return comparacion;
}
int empleado_compararPorNombre(void* empleado1,void* empleado2)
{
    int comparacion=-1;
    char nombre1[256];
    char nombre2[256];
    eEmpleado* emp1=(eEmpleado*)empleado1;
    eEmpleado* emp2=(eEmpleado*)empleado2;
    empleado_getNombre(emp1,nombre1);
    empleado_getNombre(emp2,nombre2);
    if(strcmp(nombre1,nombre2)==1)
    {
        comparacion=1;
    }
    else if(strcmp(nombre1,nombre2)==0)
    {
        comparacion=0;
    }
    return comparacion;
}
int empleado_compararPorApellido(void* empleado1,void* empleado2)
{
    int comparacion=-1;
    char apellido1[256];
    char apellido2[256];
    eEmpleado* emp1=(eEmpleado*)empleado1;
    eEmpleado* emp2=(eEmpleado*)empleado2;
    empleado_getApellido(emp1,apellido1);
    empleado_getApellido(emp2,apellido2);
    if(strcmp(apellido1,apellido2)==1)
    {
        comparacion=1;
    }
    else if(strcmp(apellido1,apellido2)==0)
    {
        comparacion=0;
    }
    return comparacion;
}
int empleado_compararPorEdad(void* empleado1,void* empleado2)
{
    int comparacion=-1;
    int edad1;
    int edad2;
    eEmpleado* emp1=(eEmpleado*)empleado1;
    eEmpleado* emp2=(eEmpleado*)empleado2;
    empleado_getEdad(emp1,&edad1);
    empleado_getEdad(emp2,&edad2);
    if(edad1 > edad2)
    {
        comparacion=1;
    }
    else if(edad1==edad2)
    {
        comparacion=0;
    }
    return comparacion;
}
int empleado_compararPorSueldo(void* empleado1,void* empleado2)
{
    int comparacion=-1;
    float sueldo1;
    float sueldo2;
    eEmpleado* emp1=(eEmpleado*)empleado1;
    eEmpleado* emp2=(eEmpleado*)empleado2;
    empleado_getSueldo(emp1,&sueldo1);
    empleado_getSueldo(emp2,&sueldo2);
    if(sueldo1 > sueldo2)
    {
        comparacion=1;
    }
    else if(sueldo1==sueldo2)
    {
        comparacion=0;
    }
    return comparacion;
}
int empleado_darDeAlta(LinkedList* listaEmpleados,int* contAltas)
{
    int sePudo=-1;
    int confirmacion;
    int auxIdInt;
    char auxNombre[256];
    char auxApellido[256];
    char auxEdadStr[256];
    char auxSueldoStr[256];
    char auxIdStr[256];
    auxIdInt=*contAltas;
    eEmpleado* auxDatos=NULL;
    int ingresoSecuencialValido=1;
    if(listaEmpleados!=NULL)
    {
        if(!getStrLetras("\nIngrese el nombre: ",auxNombre,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrLetras("\nIngrese el apellido: ",auxApellido,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumeros("\nIngrese la edad: ",auxEdadStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 18 y el 65\n",18,65,3))
        {
            ingresoSecuencialValido=0;
        }
        else if(!getStrNumerosFlotantes("\nIngrese el sueldo: ",auxSueldoStr,"\nSolo se permiten numeros y un solo punto\n","\nNumero valido entre el 1000 y el 10000\n",1000,10000,3))
        {
            ingresoSecuencialValido=0;
        }

        if(ingresoSecuencialValido==1)
        {
            confirmacion=confirmarCambios("\nEsta seguro que desea dar de alta? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
            if(confirmacion==1)
            {
                itoa(auxIdInt,auxIdStr,10);
                *contAltas=auxIdInt+1;
                auxDatos=empleado_nuevoEmpleadoParametros(auxIdStr,auxNombre,auxApellido,auxEdadStr,auxSueldoStr);
                ll_add(listaEmpleados,auxDatos);
                printf("\nSe ha dado de alta al id numero %d\n",auxIdInt);
                sePudo=1;
            }
            else if(confirmacion==0)
            {
                printf("\nAlta cancelada por el usuario\n");
                sePudo=0;
            }
        }
        if(sePudo==-1)
        {
            printf("\nAlta cancelada\n");
        }
    }
    return sePudo;
}
int empleado_darDeBaja(LinkedList* listaEmpleados)
{
    int sePudo=-1;
    int confirmacion;
    int indiceResultadoBusqueda;
    char auxIdStr[256];
    int auxIdInt;
    if(listaEmpleados!=NULL && ll_isEmpty(listaEmpleados)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        empleado_mostrarListaEmpleados(listaEmpleados);
        if(getStrNumerosSinRango("\nIngrese el id a dar de baja: ",auxIdStr,"\nSolo se permiten numeros\n",3))
        {
            auxIdInt=atoi(auxIdStr);
            indiceResultadoBusqueda=empleado_buscarPorId(listaEmpleados,auxIdInt);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                confirmacion=confirmarCambios("\nEsta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    ll_remove(listaEmpleados,indiceResultadoBusqueda);
                    printf("\nSe ha dado de baja al id numero %d\n",auxIdInt);
                    sePudo=1;
                }
                else if(confirmacion==0)
                {
                    printf("\nBaja cancelada por el usuario\n");
                    sePudo=0;
                }
            }
        }
        if(sePudo==-1)
        {
            printf("\nBaja cancelada\n");
        }
    }
    return sePudo;
}
int empleado_modificarDatos(LinkedList* listaEmpleados)
{
    int sePudo=-1;
    int indiceResultadoBusqueda;
    char auxIdStr[256];
    int auxIdInt;
    if(listaEmpleados!=NULL && ll_isEmpty(listaEmpleados)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        empleado_mostrarListaEmpleados(listaEmpleados);
        if(getStrNumerosSinRango("\nIngrese el id a modificar: ",auxIdStr,"\nSolo se permiten numeros\n",3))
        {
            auxIdInt=atoi(auxIdStr);
            indiceResultadoBusqueda=empleado_buscarPorId(listaEmpleados,auxIdInt);
            if(indiceResultadoBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                empleado_pedirDatosAModificar(listaEmpleados,indiceResultadoBusqueda);
                sePudo=1;
            }
        }
        if(sePudo==-1)
        {
            printf("\nModificacion cancelada\n");
        }
    }
    return sePudo;
}
void empleado_pedirDatosAModificar(LinkedList* listaEmpleados,int indiceEncontrado)
{
    int confirmacion;
    int flagDatoIngresado=0;
    char auxEdadStr[256];
    char auxSueldoStr[256];
    eEmpleado* datosActuales=(eEmpleado*)ll_get(listaEmpleados,indiceEncontrado);
    eEmpleado auxDatos=*datosActuales;
    eEmpleado* proximosDatos=NULL;
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        printf("\nID       NOMBRE      APELLIDO     EDAD   SUELDO\n");
        printf("\nDatos actuales seleccionados:\n");
        empleado_mostrarUnEmpleado(datosActuales);
        printf("\nDatos a modificar:\n");
        empleado_mostrarUnEmpleado(&auxDatos);

        printf("\nQue datos desea modificar?\n");
        printf("1-NOMBRE\n");
        printf("2-APELLIDO\n");
        printf("3-EDAD\n");
        printf("4-SUELDO\n");
        printf("5-CONFIRMAR CAMBIOS\n");
        printf("6-FINALIZAR MODIFICACION\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                if(getStrLetras("\nIngrese el nombre: ",auxDatos.nombre,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
                {
                    printf("\nSe ha ingresado el nombre\n");
                    flagDatoIngresado=1;
                }
                system("pause");
                break;
            case 2:
                if(getStrLetras("\nIngrese el apellido: ",auxDatos.apellido,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
                {
                    printf("\nSe ha ingresado el apellido\n");
                    flagDatoIngresado=1;
                }
                system("pause");
                break;
            case 3:
                if(getStrNumeros("\nIngrese la edad: ",auxEdadStr,"\nSolo se permiten numeros\n","\nNumero valido entre el 18 y el 65\n",18,65,3))
                {
                    auxDatos.edad=atoi(auxEdadStr);
                    printf("\nSe ha ingresado la edad\n");
                    flagDatoIngresado=1;
                }
                system("pause");
                break;
            case 4:
                if(getStrNumerosFlotantes("\nIngrese el sueldo: ",auxSueldoStr,"\nSolo se permiten numeros y un solo punto\n","\nNumero valido entre el 1000 y el 10000\n",1000,10000,3))
                {
                    auxDatos.sueldo=atof(auxSueldoStr);
                    printf("\nSe ha ingresado el sueldo\n");
                    flagDatoIngresado=1;
                }
                system("pause");
                break;
            case 5:
                if(flagDatoIngresado==1)
                {
                    confirmacion=confirmarCambios("\nDesea confirmar los cambios realizados? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                    if(confirmacion==1)
                    {
                        proximosDatos=empleado_nuevoEmpleado();
                        if(proximosDatos!=NULL)
                        {
                            *proximosDatos=auxDatos;
                            ll_set(listaEmpleados,indiceEncontrado,proximosDatos);
                            datosActuales=(eEmpleado*)ll_get(listaEmpleados,indiceEncontrado);
                            printf("\nSe han confirmado los cambios realizados\n");
                            flagDatoIngresado=0;
                        }
                    }
                }
                else
                {
                    printf("\nNo se ha realizado ningun cambio que confirmar\n");
                }
                system("pause");
                break;
            case 6:
                if(flagDatoIngresado==1)
                {
                    confirmacion=confirmarCambios("\nEsta seguro que desea salir sin confirmar cambios? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                    if(confirmacion==1)
                    {
                        printf("\nModificacion finalizada sin confirmar cambios\n");
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
void empleado_ordenarEmpleados(LinkedList* listaEmpleados)
{
    int elejirOrden;
    int opcionMenu;
    char continuarMenu='s';
    if(listaEmpleados!=NULL && ll_isEmpty(listaEmpleados)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        do
        {
            system("cls");
            printf("Desea ordenar de manera ascendente o descendente?\n");
            printf("1-ASCENDENTE\n");
            printf("2-DESCENDENTE\n");
            printf("3-CANCELAR ORDENAMIENTO\n");
            opcionMenu=getInt("\nIngrese una opcion: ");
            switch(opcionMenu)
            {
                case 1:
                    elejirOrden=1;
                    system("pause");
                    break;
                case 2:
                    elejirOrden=0;
                    system("pause");
                    break;
                case 3:
                    printf("\nOrdenamiento cancelado por el usuario\n");
                    continuarMenu='n';
                    elejirOrden=-1;
                    break;
            }
            if(elejirOrden!=-1)
            {
                system("cls");
                printf("Por cual criterio desea ordenar?\n");
                printf("1-ORDENAR POR ID\n");
                printf("2-ORDENAR POR NOMBRE\n");
                printf("3-ORDENAR POR APELLIDO\n");
                printf("4-ORDENAR POR EDAD\n");
                printf("5-ORDENAR POR SUELDO\n");
                printf("6-CANCELAR ORDENAMIENTO\n");
                opcionMenu=getInt("\nIngrese una opcion: ");
                switch(opcionMenu)
                {
                    case 1:
                        ll_sort(listaEmpleados,empleado_compararPorId,elejirOrden);
                        printf("\nSe ha ordenado por id\n");
                        continuarMenu='n';
                        break;
                    case 2:
                        ll_sort(listaEmpleados,empleado_compararPorNombre,elejirOrden);
                        printf("\nSe ha ordenado por nombre\n");
                        continuarMenu='n';
                        break;
                    case 3:
                        ll_sort(listaEmpleados,empleado_compararPorApellido,elejirOrden);
                        printf("\nSe ha ordenado por apellido\n");
                        continuarMenu='n';
                        break;
                    case 4:
                        ll_sort(listaEmpleados,empleado_compararPorEdad,elejirOrden);
                        printf("\nSe ha ordenado por edad\n");
                        continuarMenu='n';
                        break;
                    case 5:
                        ll_sort(listaEmpleados,empleado_compararPorSueldo,elejirOrden);
                        printf("\nSe ha ordenado por sueldo\n");
                        continuarMenu='n';
                        break;
                    case 6:
                        printf("\nOrdenamiento cancelado por el usuario\n");
                        continuarMenu='n';
                        break;
                    default:
                        printf("\nOpcion ingresada no valida\n");
                        system("pause");
                }
            }
        }
        while(continuarMenu=='s');
    }
}
int empleado_guardarDatosModoTexto(FILE* archivo,LinkedList* listaEmpleados,int* contAltas)
{
    char auxAltasStr[256];
    char auxIdStr[256];
    char auxNombreStr[256];
    char auxApellidoStr[256];
    char auxEdadStr[256];
    char auxSueldoStr[256];
    int sePudo=-1;
    eEmpleado* auxDatos;
    int i;
    int len=ll_len(listaEmpleados);
    if(listaEmpleados!=NULL && ll_isEmpty(listaEmpleados)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        archivo=fopen("datos_texto.csv","w");
        if(archivo!=NULL)
        {
            itoa(*contAltas,auxAltasStr,10);
            fprintf(archivo,"%s\n",auxAltasStr);
            fprintf(archivo,"ID;NOMBRE;APELLIDO;EDAD;SUELDO\n");
            for(i=0;i<len;i++)
            {
                auxDatos=(eEmpleado*)ll_get(listaEmpleados,i);
                itoa(auxDatos->id,auxIdStr,10);
                empleado_getNombre(auxDatos,auxNombreStr);
                empleado_getApellido(auxDatos,auxApellidoStr);
                itoa(auxDatos->edad,auxEdadStr,10);
                sprintf(auxSueldoStr,"%.2f",auxDatos->sueldo);
                fprintf(archivo,"%s;%s;%s;%s;%s\n",auxIdStr,auxNombreStr,auxApellidoStr,auxEdadStr,auxSueldoStr);
            }
            fclose(archivo);
            printf("\nSe han guardado los datos\n");
            sePudo=1;
        }
    }
    return sePudo;
}
int empleado_cargarDatosModoTexto(FILE* archivo,LinkedList* listaEmpleados,int* contAltas)
{
    char auxAltasStr[256];
    char auxIdStr[256];
    char auxNombreStr[256];
    char auxApellidoStr[256];
    char auxEdadStr[256];
    char auxSueldoStr[256];
    eEmpleado* auxDatos;
    int sePudo=-1;
    archivo=fopen("datos_texto.csv","r");
    if(archivo!=NULL)
    {
        ll_clear(listaEmpleados);
        fscanf(archivo,"%[^\n]\n",auxAltasStr);
        *contAltas=atoi(auxAltasStr);
        fscanf(archivo,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",auxIdStr,auxNombreStr,auxApellidoStr,auxEdadStr,auxSueldoStr);
        while(!feof(archivo))
        {
            fscanf(archivo,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",auxIdStr,auxNombreStr,auxApellidoStr,auxEdadStr,auxSueldoStr);
            auxDatos=empleado_nuevoEmpleadoParametros(auxIdStr,auxNombreStr,auxApellidoStr,auxEdadStr,auxSueldoStr);
            ll_add(listaEmpleados,auxDatos);
            if(feof(archivo))
            {
                break;
            }
        }
        fclose(archivo);
        printf("\nSe han cargado los datos\n");
        sePudo=1;
    }
    return sePudo;
}
int empleado_guardarDatosModoBinario(FILE* archivo,LinkedList* listaEmpleados,int* contAltas)
{
    int sePudo=-1;
    int i;
    int len=ll_len(listaEmpleados);
    eEmpleado* auxDatos;
    if(listaEmpleados!=NULL && ll_isEmpty(listaEmpleados)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        archivo=fopen("datos_binario","wb");
        if(archivo!=NULL)
        {
            fwrite(contAltas,sizeof(int),1,archivo);
            for(i=0;i<len;i++)
            {
                auxDatos=ll_get(listaEmpleados,i);
                fwrite(auxDatos,sizeof(eEmpleado),1,archivo);
            }
            fclose(archivo);
            printf("\nSe han guardado los datos\n");
            sePudo=1;
        }
    }
    return sePudo;
}
int empleado_cargarDatosModoBinario(FILE* archivo,LinkedList* listaEmpleados,int* contAltas)
{
    int sePudo=-1;
    eEmpleado* auxDatos;
    {
        archivo=fopen("datos_binario","rb");
        if(archivo!=NULL)
        {
            fread(contAltas,sizeof(int),1,archivo);
            ll_clear(listaEmpleados);
            while(!feof(archivo))
            {
                auxDatos=empleado_nuevoEmpleado();
                if(auxDatos!=NULL)
                {
                    fread(auxDatos,sizeof(eEmpleado),1,archivo);
                    if(feof(archivo))
                    {
                        break;
                    }
                    ll_add(listaEmpleados,auxDatos);
                }
            }
            fclose(archivo);
            printf("\nSe han cargado los datos\n");
            sePudo=1;
        }
    }
    return sePudo;
}
