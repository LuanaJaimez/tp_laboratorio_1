#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "informes.h"
#define TAM 1000
#include "utn.h"


int menu();

int main()
{
    char seguir = 's';
    char confirm;

    int proximoId = 1000;
    Employee list[TAM];

    inicializarEmpleados(list, TAM);

    do{
        switch(menu())
        {
        case 1:
            if(altaEmpleado(list, TAM, proximoId) == 1)
            {
                proximoId++;
            }
            break;
        case 2:
            modificarEmpleado(list, TAM);
            break;
        case 3:
            bajaEmpleado(list, TAM);
            break;
        case 4:
            informar(list, TAM);
            break;
        case 5:
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

    return 0;
}

//---------------------------------------------------------------------------------------------------

int menu()
{
    int opcion;

    system("cls");
    printf("***** Sistema de Empleados ******\n\n");
    printf("1. Alta Empleado\n");
    printf("2. Modificar Empleado\n");
    printf("3. Baja Empleados\n");
    printf("4. Informar\n");
    printf("5. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//---------------------------------------------------------------------------------------------------

