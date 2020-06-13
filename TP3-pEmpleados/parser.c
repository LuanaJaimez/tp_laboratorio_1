#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int exito = 1;
	Employee* pEmployee;
	char id[200];
	char nombre[200];
	char horasTrabajadas[200];
	char sueldo[200];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
	    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == 4)
			{
				pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(pEmployee != NULL)//osea si pudo cargar
				{
					ll_add(pArrayListEmployee, pEmployee);
					exito = 0;
				}
			}
			else
			{
				break;
			}

		}while(feof(pFile) == 0);
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int exito = 1;
	Employee* pEmployee;

	if(pFile != NULL)
	{
		do
		{
			pEmployee = employee_new();
			if(fread(pEmployee, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, pEmployee);
				printf("Aniadido con exito\n");
				exito = 0;
			}
		}while(!feof(pFile));
	}

    return exito;
}
