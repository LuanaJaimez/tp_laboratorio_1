#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "ArrayEmployees.h"
#include "utn.h"



void inicializarEmpleados(Employee list[], int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }
}

//---------------------------------------------------------------------------------------------------

int buscarLibre(Employee list[], int len)
{
    int indice = -1;
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

int buscarEmpleado(Employee list[], int len, int id)
{
    int indice = -1;
    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

int altaEmpleado(Employee list[], int len, int idx)
{
    int todoOk = 0;
    int indice = buscarLibre(list, len);
    //int id;
    //int existe;
    Employee auxEmpleado;

    system("cls");

    printf("***** Alta empleado *****\n\n");

    if(indice == -1) //hay lugar?
    {
        printf("Sistema completo\n\n");
    }
    else
    {
            auxEmpleado.id = idx;

            /*printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmpleado.nombre);*/
            utn_getCadena(auxEmpleado.name, 51, 2, "Ingrese nombre: ", "\nError. Reingrese nombre\n");

            /*printf("Ingrese apellido: ");
            fflush(stdin);
            gets(auxEmpleado.apellido);*/
            utn_getCadena(auxEmpleado.lastname, 51, 2, "Ingrese apellido: ", "\nError. Reingrese apellido\n");

            /*printf("Ingrese sueldo: ");
            scanf("%f", &auxEmpleado.sueldo);*/
            utn_getFlotante(&auxEmpleado.salary, 2, "Ingrese sueldo (1000-100000): ", "\nError. Reingrese sueldo\n", 1000, 100000);

            /*mostrarSectores(sectores, tamSec);
            printf("\nIngrese id del sector");
            scanf("%d", &auxEmpleado.idSector);*/
            utn_getEntero(&auxEmpleado.sector, 2, "Ingrese sector: ", "\nError. Reingrese sector (solo numeros)\n", 1, 1000);

            auxEmpleado.isEmpty = 0;


            list[indice] = auxEmpleado; //copio al vector el empleado nuevo
            todoOk = 1;

    }//else exterior

    return todoOk;

}//fin de la funcion

//---------------------------------------------------------------------------------------------------

void bajaEmpleado(Employee list[], int len)
{
    int id;
    int indice;
    char confirm;

    system("cls");
    printf("***** Baja empleado *****\n\n");

    printf("Ingrese Id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(list, len, id);

    if(indice == -1)
    {
        printf("No hay registro de un empleado con el Id: %d\n", id);
    }
    else
    {
        mostrarEmpleado(list[indice]);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirm);
        if(confirm == 's')
        {
            list[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

}

//---------------------------------------------------------------------------------------------------

void modificarEmpleado(Employee list[], int len)
{
    int id;
    int indice;
    char seguir = 's';
    char confirm;
    char newName[51];
    char newLastname[51];
    float newSalary;
    int newSector;

    system("cls");
    printf("***** Modificar empleado *****\n\n");

    printf("Ingrese Id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(list, len, id);

    if(indice == -1)
    {
        printf("No hay registro de un empleado con el Id: %d\n", id);
    }
    else
    {
        printf("ID   Nombre    Apellido    Sueldo    Sector\n");
        mostrarEmpleado(list[indice]);

//SUBMENU QUE PERMITA MODIFICAR CUALQUIERA DE LOS CAMPOS---------------------------------------------------

    do{
        switch(menuModificar())
        {
        case 1:
            printf("\nModifica Nombre?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                printf("Ingrese nuevo nombre: ");
                scanf("%s", newName);

                strcpy(list[indice].name, newName);
                printf("Se ha actualizado el nombre con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 2:
            printf("\nModifica Apellido?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                printf("Ingrese nuevo apellido: ");
                scanf("%s", newLastname);

                strcpy(list[indice].lastname, newLastname);
                printf("Se ha actualizado el apellido con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 3:
            printf("\nModifica Sueldo?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                printf("Ingrese nuevo sueldo: ");
                scanf("%f", &newSalary);

                list[indice].salary = newSalary;
                printf("Se ha actualizado el sueldo con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 4:
            printf("\nModifica Sector?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                printf("Ingrese nuevo sector: ");
                scanf("%d", &newSector);

                list[indice].sector = newSector;
                printf("Se ha actualizado el sector con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 5:
            printf("Confirme salida: ");
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

//---------------------------------------------------------------------------------------------------

int menuModificar()
{
    int opcion;

    printf("***** Modificar Empleados *****\n\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Apellido\n");
    printf("3. Modificar Sueldo\n");
    printf("4. Modificar Sector\n");
    printf("5. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//---------------------------------------------------------------------------------------------------

void mostrarEmpleado(Employee x)
{
    printf("%d  %10s    %10s     %6.2f      %d\n", x.id, x.name, x.lastname, x.salary, x.sector);
}


