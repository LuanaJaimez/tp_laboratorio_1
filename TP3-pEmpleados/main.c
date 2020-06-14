#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int menu();

int main()
{
    char confirm;
    char seguir = 's';
    int flagATexto = 0;
    int flagABinario = 0;


    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(menu())
        {
            case 1:
            	if(flagABinario != 1)//No existe
            	{
            		if(!controller_loadFromText("data.csv", listaEmpleados))
					{
						flagATexto = 1;
					}
            	}
            	else
				{
					printf("Archivo ya cargado como binario\n\n");
				}
                break;
            case 2:
            	if(flagATexto != 1)//No existe
            	{
            		if(!controller_loadFromBinary("data.bin", listaEmpleados))
            		{
            			flagABinario = 1;
            		}
            	}
            	else
            	{
            		printf("Archivo ya cargado como texto\n\n");
            	}
            	break;
            case 3:
            	//validar que no entre si no entro al primer case (ahi ya leeria el archivo)
            	if(flagATexto == 1 || flagABinario == 1)
            	{
            		controller_addEmployee("data.csv", listaEmpleados);
            	}
            	else
            	{
            		printf("Error. No hay archivos registrados.\n");
            	}
            	break;
            case 4:
                if(flagATexto == 1 || flagABinario == 1)
				{
            		controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. No hay archivos registrados.\n");
				}
            	break;
            case 5:
            	if(flagATexto == 1 || flagABinario == 1)
				{
            		controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. No hay archivos registrados.\n");
				}
            	break;
            case 6:
            	if(flagATexto == 1 || flagABinario == 1)
				{
            		controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. No hay archivos registrados.\n");
				}
            	break;
            case 7:
                if(flagATexto == 1 || flagABinario == 1)
				{
            		controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("Error. No hay archivos registrados.\n");
				}
            	break;
            case 8:
            	controller_saveAsText("data.csv", listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary("data.bin", listaEmpleados);
            	break;
            case 10:
            	printf("Confirma salida? s/n: ");
            	fflush(stdin);
            	scanf("%c", &confirm);
            	if(confirm == 's')
            	{
            		seguir = 'n';
            	}
            	break;
        }

        system("pause");

    }while(seguir == 's');

    return 0;
}


//---------------------------------------------------------------------------------------------------

int menu()
{
    int option;

    system("cls");
    printf("***** Sistema de Empleados ******\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

//---------------------------------------------------------------------------------------------------


