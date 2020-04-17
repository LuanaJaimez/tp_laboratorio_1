#include <stdio.h>
#include <stdlib.h>
#include "operacionesMat.h"

int main()
{
    char seguir = 's';
    do{
            switch(menuOpciones ()){

        case 1:
            operando1();
            break;
        case 2:
            operando2();
            break;
        case 3:
            operaciones();
            break;
        case 4:
            resultados();
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("No es una opcion valida\n");
            }

    system("pause");
    }while(seguir == 's');


    return 0;
}


