#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int employee_proxId(LinkedList* pArrayListEmployee);
int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_findById(LinkedList* pArrayListEmployee, int id);
//int employee_listEmployee(Employee* pEmployee, int indice);
int employee_listEmployee(LinkedList* pArrayListEmployee, int indice);
//int employee_listEmployee(Employee* pEmployee, LinkedList* pArrayListEmployee);

int changeName(LinkedList* pArrayListEmployee, int index);
int changeHours(LinkedList* pArrayListEmployee, int index);
int changeSalary(LinkedList* pArrayListEmployee, int index);

#endif // employee_H_INCLUDED
