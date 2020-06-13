#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "utn.h"
#include <string.h>

#define NOMLEN 128


Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

//---------------------------------------------------------------------------------------------------

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* nEmployee = NULL;
	nEmployee = employee_new();

	if(sueldoStr != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
	{

		if(employee_setId(nEmployee, atoi(idStr)) == -1 ||
		   employee_setNombre(nEmployee, nombreStr) == -1 ||
		   employee_setHorasTrabajadas(nEmployee, atoi(horasTrabajadasStr)) == -1 ||
		   employee_setSueldo(nEmployee, atoi(sueldoStr)) == -1)
		{
			employee_delete(nEmployee);
			nEmployee = NULL;
		}
		else
        {
            employee_setId(nEmployee, atoi(idStr));
            employee_setNombre(nEmployee, nombreStr);
            employee_setHorasTrabajadas(nEmployee, atoi(horasTrabajadasStr));
            employee_setSueldo(nEmployee, atoi(sueldoStr));
        }
	}

	return nEmployee;
}

//---------------------------------------------------------------------------------------------------

int employee_proxId(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int auxId;
	int ultId = 0;
	int flagId = 0;

	if(pArrayListEmployee != NULL)
	{
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee,i);
			employee_getId(pEmployee, &auxId);

			if(auxId > ultId || flagId == 0)
			{
				ultId = auxId;
				flagId = 1;
			}
		}
	}
	return ultId;
}

//---------------------------------------------------------------------------------------------------

int employee_delete(Employee* this)
{
	int exito = 1;

	if(this != NULL)
	{
		free(this);
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int employee_setId(Employee* this, int id)
{
	int exito = 1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int employee_getId(Employee* this, int* id)
{
	int exito = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int employee_setNombre(Employee* this, char* nombre)
{
	int exito = 1;

	if(this != NULL && nombre != NULL)
	{
        normalizeStr(nombre);
        strncpy(this->nombre, nombre, NOMLEN);
        exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int employee_getNombre(Employee* this, char* nombre)
{
	int exito = 1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, NOMLEN);
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int exito = 1;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int exito = 1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int employee_setSueldo(Employee* this, int sueldo)
{
	int exito = 1;

	if(this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int employee_getSueldo(Employee* this, int* sueldo)
{
	int exito = 1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		exito = 0;
	}

	return exito;
}

//---------------------------------------------------------------------------------------------------

int employee_findById(LinkedList* pArrayListEmployee, int id)
{
	int indice = -1;
	Employee* pEmployee;
	int flagId = 1;
    int auxId;

	for(int i = 0; i < ll_len(pArrayListEmployee); i++)
	{
		pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

		if(auxId == id && employee_getId(pEmployee, &auxId) == 0)
		{
			indice = i;
			flagId = 0;
		}
	}

	if(flagId == 1) //Si el flag sigue valiendo 1
    {
        printf("No registro de empleados con ese ID\n");
    }

	return indice;
}

//---------------------------------------------------------------------------------------------------

int employee_listEmployee(LinkedList* pArrayListEmployee, int indice)
{
	int auxId;
	int auxHTrab;
	int auxSueldo;
	char auxNom [NOMLEN];
	int exito = 1;

	Employee* pEmployee;
	//LinkedList* pArrayListEmployee;

	if(pArrayListEmployee != NULL && indice > 0)
	{
	    pEmployee  = ll_get(pArrayListEmployee, indice);

		employee_getId(pEmployee, &auxId);
        employee_getNombre(pEmployee, auxNom);
        employee_getHorasTrabajadas(pEmployee, &auxHTrab);
        employee_getSueldo(pEmployee, &auxSueldo);

        printf("%5d   %10s      %5d           %10d\n", auxId, auxNom, auxHTrab, auxSueldo);

        exito = 0;
	}
    else
    {
        printf("Error\n");
    }

	return exito;

}

//---------------------------------------------------------------------------------------------------
