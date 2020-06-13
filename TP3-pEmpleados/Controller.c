#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include <string.h>

#define NOMLEN 128


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int exito = 1;

	pFile = fopen(path, "r"); //Abre el archivo para leerlo de texto, si es que existe.

	if(pFile != NULL)
	{
		if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 0)
		{
		    //Si todo salio bien cambia a 0
		    exito = 0;
			printf("\nLos datos de los empleados en modo texto fueron cargados corretamente\n\n");
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
	}
	else
	{
		printf("Error\n");
	}

	fclose(pFile);

    return exito;
}

//---------------------------------------------------------------------------------------------------

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int exito = 1;

	pFile = fopen(path, "rb"); //Abre el archivo que no sea de texto para leerlo, si es que existe.

	if(pFile != NULL)
	{
		if(!(parser_EmployeeFromBinary(pFile, pArrayListEmployee)))
		{
		    //Si todo salio bien, exito pasa a valer 0
			exito = 0;
			printf("Los datos de los empleados en modo binario fueron cargados corretamente\n\n");
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
	}
	else
	{
		printf("Error\n");
	}

	fclose(pFile);

    return exito;
}

//---------------------------------------------------------------------------------------------------

int controller_addEmployee(char* path , LinkedList* pArrayListEmployee)
{
    int proxId;
	char auxNom[NOMLEN];
	int auxHTrab;
	int auxSueldo;
	//int flag = 0;
	int exito = 1;

	Employee* pEmployee = employee_new();

	if(pArrayListEmployee != NULL && pEmployee != NULL)
	{
		utn_getCadena(auxNom, NOMLEN, 2, "Ingrese nombre: ", "Error, nombre invalido. Reintente");
        utn_getEntero(&auxHTrab, 2, "Ingrese cantidad de horas trabajadas: ", "Error, antidad invalida.  Reintente\n", 0, 100000);
        utn_getEntero(&auxSueldo, 2, "Ingrese salario de 20000 a 250000: ", "Error, salario invalido. Reintente\n", 18000, 300000);

        normalizeStr(auxNom);
        proxId = employee_proxId(pArrayListEmployee) + 1;

			if(proxId >= 0)
			{
				if(!employee_setId(pEmployee, proxId) &&
				   !employee_setNombre(pEmployee, auxNom) &&
				   !employee_setHorasTrabajadas(pEmployee, auxHTrab) &&
				   !employee_setSueldo(pEmployee, auxSueldo))
				{
					ll_add(pArrayListEmployee, pEmployee);
					printf("Se realizo el alta de un nuevo empleado\n");
				}
				else
				{
					free(pEmployee);
				}
			}

		else
		{
			free(pEmployee);
		}
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int auxId;
    int ultId;
    int exito = 1;
    int indice;
    char seguir = 's';
    char confirm;
    char newName[NOMLEN];
    int newSalary;
    int newHours;

    Employee* pEmployee;

    system("cls");
    printf("***** Modificar empleado *****\n\n");


    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);

            employee_getId(pEmployee, &auxId);
            if(auxId >= ultId)
            {
                ultId = auxId;
            }
        }

        if(!utn_getEntero(&auxId, 2, "Ingrese ID de empleado a modificar: ", "Error, ID incorrecto. Reintente", 0, ultId))
        {
            indice = employee_findById(pArrayListEmployee, auxId);
            if(indice == -1)
            {
                printf("No hay registro de un empleado con ese ID\n");
            }
            else
            {
                system("cls");
                printf("\n      ID      Nombre      Horas Trabajadas   Sueldo\n\n");
                employee_listEmployee(pArrayListEmployee, indice);
                printf("\n\n");


//SUBMENU QUE PERMITE MODIFICAR CUALQUIERA DE LOS CAMPOS---------------------------------------------------

                do
                {
                    switch(menuModificar())
                    {
                    case 1:
                        printf("\nModifica Nombre? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if(confirm == 's')
                        {
                            pEmployee = ll_get(pArrayListEmployee, indice);

                            if(utn_getCadena(newName, NOMLEN, 2, "Ingrese nuevo nombre: ","Error, nombre invalido. Reintete\n") == 0)
                            {
                                normalizeStr(newName);
                                employee_setNombre(pEmployee, newName);
                                exito = 0;

                                if(exito == 0)
                                {
                                    printf("Se ha actualizado el nombre con exito\n\n");
                                    printf("\n\n");
                                    printf("\n      ID      Nombre      Horas Trabajadas   Sueldo\n\n");
                                    employee_listEmployee(pArrayListEmployee, indice);
                                }
                                else
                                {
                                    printf("Error\n\n");
                                }
                            }
                        }
                        else
                        {
                            printf("Se ha cancelado la operacion\n\n");
                        }
                        break;
                    case 2:
                        printf("\nModifica Horas trabajadas? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if(confirm == 's')
                        {
                            pEmployee = ll_get(pArrayListEmployee, indice);

                            if(utn_getEntero(&newHours, 2, "Ingrese actualizacion de horas trabajadas: ", "Error, invalido.\n", 0, 100000) == 0)
                            {
                                employee_setHorasTrabajadas(pEmployee, newHours);
                                exito = 0;

                                if(exito == 0)
                                {
                                    printf("Se han actualizado las horas trabajadas con exito\n\n");
                                    printf("\n\n");
                                    printf("\n      ID      Nombre      Horas Trabajadas   Sueldo\n\n");
                                    employee_listEmployee(pArrayListEmployee, indice);
                                }
                                else
                                {
                                    printf("Error.\n");
                                }
                            }
                        }
                        else
                        {
                            printf("Se ha cancelado la operacion\n\n");
                        }
                        break;
                    case 3:
                        printf("\nModifica Sueldo? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if(confirm == 's')
                        {
                            pEmployee = ll_get(pArrayListEmployee, indice);

                            if(utn_getEntero(&newSalary, 2, "Ingrese nuevo sueldo de 20000 a 250000: ", "Error, suedo invalido.\n", 20000, 250000) == 0)
                            {
                                employee_setHorasTrabajadas(pEmployee, newSalary);
                                exito = 0;

                                if(exito == 0)
                                {
                                    printf("Se ha actualizado el sueldo con exito\n\n");
                                    printf("\n\n");
                                    printf("\n      ID      Nombre      Horas Trabajadas   Sueldo\n\n");
                                    employee_listEmployee(pArrayListEmployee, indice);
                                }
                                else
                                {
                                    printf("Error.\n");
                                }
                            }
                        }
                        else
                        {
                            printf("Se ha cancelado la operacion\n\n");
                        }
                        break;
                    case 4:
                        printf("Confirma salida? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if(confirm == 's')
                        {
                            seguir = 'n';
                        }
                        system("pause");
                    }

                }while(seguir == 's');
            }
        }
    }

    return exito;
}

//---------------------------------------------------------------------------------------------------

int menuModificar()
{
    int option;

    printf("***** Modificar Empleados *****\n\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Horas Trabajas\n");
    printf("3. Modificar Sueldo\n");
    printf("4. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

//---------------------------------------------------------------------------------------------------

int controller_removeEmployee( LinkedList* pArrayListEmployee)
{
	int exito = 1;
	int auxId;
	int ultId = 1;
	Employee* pEmployee;
	int index;
	char confirm = 'n';

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = ll_get(pArrayListEmployee, i);

			employee_getId(pEmployee, &auxId);
			if(auxId >= ultId)
			{
				ultId = auxId;
			}
		}

		if(!utn_getEntero(&auxId, 2, "Ingrese ID de empleado a eliminar del sistema.\n", "Error, ID invalido", 0, ultId))
		{
			index = employee_findById(pArrayListEmployee, auxId);
			if(index == -1)
			{
			    printf("No hay registro de un empleado con ese ID\n\n");
			}
			else
            {
				printf("\n ID    Nombre   Horas Trabajadas   Sueldo\n\n");
				employee_listEmployee(pArrayListEmployee, index);

				printf("Confirma baja del empleado? s/n: ");
				scanf("%c", &confirm);
				if(confirm == 's')
				{
					ll_remove(pArrayListEmployee, index);
					employee_delete(pEmployee);

					printf("Baja exitosa\n");

					exito = 0;
				}
			}
		}
	}
    return exito;
}

//---------------------------------------------------------------------------------------------------

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int exito = 1;

	Employee* pEmployee;


	if(pArrayListEmployee != NULL)
	{
	    system("cls");
		printf("\n      ID       Nombre     Horas Trabajadas     Sueldo\n\n");
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = ll_get(pArrayListEmployee, i);
			if(pEmployee != NULL)
            {
                employee_listEmployee(pArrayListEmployee, i);
                exito = 0;
            }
		}
	}
	else if(exito == 1)
	{
		printf("No hay empleados cargados en la lista.\n");
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------

int sortName(void* firstName, void* secondName)
{
    int change;
    Employee* firstNameEmployee;
    Employee* secondNameEmployee;

    if(firstName != NULL && secondName != NULL)
    {
        firstNameEmployee = (Employee*) firstName;
        secondNameEmployee = (Employee*) secondName;

        change = strcmp(firstNameEmployee->nombre, secondNameEmployee->nombre);
    }

    return change;
}

//---------------------------------------------------------------------------------------------------

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int flag = 0;
    int exito = 1;

    printf("Espere por favor...\n");
    ll_sort(pArrayListEmployee, sortName, 1);
    //ll_sort(pArrayListEmployee, sortSalary, 1);
    exito = 0;

    if(exito == 0)
    {
        printf("Los empleados fueron ordenados exitosamente\n");
    }
    else
    {
        printf("Error al ordenar los empleados\n");
    }


    printf("***** Listado de Empleados *****\n");
    printf("  Id      Nombre    Apellido     Sueldo    Sector\n\n");

    for(int i=0; i < ll_len(pArrayListEmployee); i++)
    {
        if(pArrayListEmployee != NULL)
        {
            controller_ListEmployee(pArrayListEmployee);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay empleados que listar ***\n");
    }

    return exito;
}

//---------------------------------------------------------------------------------------------------

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 1;
	FILE* pFile;
	int auxId;
	char auxNom[NOMLEN];
	int auxHTrab;
	int auxSalario;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			exito = 0;
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				pEmployee = ll_get(pArrayListEmployee, i);

				employee_getId(pEmployee, &auxId);
                employee_getNombre(pEmployee, auxNom);
                employee_getHorasTrabajadas(pEmployee, &auxHTrab);
                employee_getSueldo(pEmployee, &auxSalario);

                fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNom, auxHTrab, auxSalario);
			}

			fclose(pFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(exito == 1)
        {
            printf("Error\n");
        }
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int exito = 1;
	FILE* pFile;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			if(pEmployee != NULL)
            {
                fwrite(pEmployee, sizeof(Employee), 1, pFile);
                exito = 0;
            }
		}

		if(exito == 0)
        {
            printf("Archivo guardado correctamente\n");
        }

		fclose(pFile);
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------
