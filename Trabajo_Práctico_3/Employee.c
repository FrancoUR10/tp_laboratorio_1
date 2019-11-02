#include "Employee.h"

int employee_setId(Employee* this,int id)
{
    int todoOk=0;
    if(this != NULL && id > 0)
    {
        this->id=id;
        todoOk=1;
    }
    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id=this->id;
        todoOk=1;
    }
    return todoOk;
}
int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk=0;
    if(this != NULL && nombre != NULL && strlen(nombre) > 2)
    {
        strcpy(this->nombre,nombre);
        todoOk=1;
    }
    return todoOk;

}
int employee_getNombre(Employee* this,char* nombre)
{

    int todoOk=0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk=1;
    }
    return todoOk;

}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {

        *horasTrabajadas=this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}
Employee* employee_new()
{
    Employee* this=(Employee*)malloc(sizeof(Employee));
    if(this != NULL)
    {
        this->id=0;
        strcpy(this->nombre," ");
        this->horasTrabajadas=0;
        this->sueldo=0;
    }
    return this;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this=employee_new();
        if(this != NULL)
        {
            if(!employee_setId(this,atoi(idStr)) || !employee_setNombre(this,nombreStr) || !employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) || !employee_setSueldo(this,atoi(sueldoStr)))
            {
                employee_delete(this);
                this=NULL;
            }
        }
    }
    return this;
}
int employee_delete(Employee* this)
{
    int seLibero=0;
    if(this!=NULL)
    {
        free(this);
        seLibero=1;
    }
    return seLibero;
}
int compararPorId(void* empleado1,void* empleado2)
{
    int comparacion=-1;
    int id1;
    int id2;
    Employee* emp1=(Employee*)empleado1;
    Employee* emp2=(Employee*)empleado2;
    employee_getId(emp1,&id1);
    employee_getId(emp2,&id2);
    if(id1 > id2)
    {
        comparacion=1;
    }
    else if(id1 == id2)
    {
        comparacion=0;
    }
    return comparacion;
}
int compararPorNombre(void* empleado1,void* empleado2)
{
    int comparacion=-1;
    char nombre1[256];
    char nombre2[256];
    Employee* emp1=(Employee*)empleado1;
    Employee* emp2=(Employee*)empleado2;
    employee_getNombre(emp1,nombre1);
    employee_getNombre(emp2,nombre2);
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
int compararPorHoras(void* empleado1,void* empleado2)
{
    int comparacion=-1;
    int hora1;
    int hora2;
    Employee* emp1=(Employee*)empleado1;
    Employee* emp2=(Employee*)empleado2;
    employee_getHorasTrabajadas(emp1,&hora1);
    employee_getHorasTrabajadas(emp2,&hora2);
    if(hora1 > hora2)
    {
        comparacion=1;
    }
    else if(hora1 == hora2)
    {
        comparacion=0;
    }
    return comparacion;
}
int compararPorSueldo(void* empleado1,void* empleado2)
{
    int comparacion=-1;
    int sueldo1;
    int sueldo2;
    Employee* emp1=(Employee*)empleado1;
    Employee* emp2=(Employee*)empleado2;
    employee_getSueldo(emp1,&sueldo1);
    employee_getSueldo(emp2,&sueldo2);
    if(sueldo1 > sueldo2)
    {
        comparacion=1;
    }
    else if(sueldo1 == sueldo2)
    {
        comparacion=0;
    }
    return comparacion;
}
int buscarEmpleadoPorId(LinkedList* listaEmpleado,int idABuscar)
{
    int retorno=-1;
    Employee* aux;
    int i;
    int len=ll_len(listaEmpleado);
    for(i=0;i<len;i++)
    {
        aux=(Employee*)ll_get(listaEmpleado,i);
        if(aux->id==idABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
