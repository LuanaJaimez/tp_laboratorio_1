#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "informes.h"


//----------------------------INFORMES---------------------------------------------------------------

void informar(Employee list[], int len)
{
    char seguir = 's';
    char confirm;

    do{
        switch(menuInformes())
        {
        case 1:
            sortEmployees(list, len, 1);
            break;
        case 2:
            informarTotalSueldos(list, len);
            break;
        case 3:
            printf("Confirme salida: ");
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

}

//---------------------------------------------------------------------------------------------------

int menuInformes()
{
    int opcion;

    system("cls");
    printf("***** Informes empleados *****\n\n");
    printf("1. Listar empleados ordenador alfabeticamente\n");
    printf("2. Mostrar total y promedio de los sueldos\n");
    printf("3. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//---------------------------------------------------------------------------------------------------

void informarTotalSueldos(Employee list[], int len)
{
    system("cls");
    float total = 0;
    int empleados = 0;
    float promedio = 0;
    int empleadosMasPromedio = 0;
    int flag = 0;

    printf("***** Informes sueldos *****\n\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            total += list[i].salary;
            empleados++;
        }
    }

    promedio = total / empleados;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            if(list[i].salary > promedio)
            {
                empleadosMasPromedio++;
            }
            flag = 1;
        }
    }


    if(flag == 0)
    {
        printf("*** No hay sueldos que listar ***\n\n");
    }
    else
    {
        printf("  Total         Promedio       \n");
        printf("  $%.2f      $%.2f          \n\n ", total, promedio);
        printf("--------------------------------\n");
        printf("La cantidad de empleados que superan el sueldo promedio es: %d\n\n", empleadosMasPromedio);
    }

}

//---------------------------------------------------------------------------------------------------

void sortEmployees(Employee list[], int len, int order)
{
    system("cls");
    int flag = 0;
    Employee auxEmpleado;

    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(list[i].sector > list[j].sector)
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
            else if(list[i].sector == list[j].sector && strcmp(list[i].lastname, list[j].lastname) > 0)
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
        }
    }

    printf("***** Listado de Empleados *****\n");
    printf("  Id      Nombre    Apellido     Sueldo    Sector\n\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            mostrarEmpleado(list[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay empleados que listar ***\n");
    }

}
