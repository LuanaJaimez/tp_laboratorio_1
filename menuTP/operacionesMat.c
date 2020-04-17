#include <stdio.h>
#include <stdlib.h>
#include "operacionesMat.h"

int a = 0;
int b = 0;
int suma;
int resta;
int mult;
int division;
int fac;
int fac2;
char op;

int factorial(int a);
int operaciones();

int menuOpciones(){
    int opcion;

    system("cls");
    printf("   *****************************************  \n");
    printf("   **** Calculadora de numeros enteros *****  \n");
    printf("   **** Selecciones opciones del 1 al 5 ****  \n");
    printf("   *****************************************  \n\n");
    printf("1- Ingresar primer operando (A=%d)\n", a);
    printf("2- Ingresar segundo operando (B=%d)\n", b);
    printf("3- Calcular todas las operaciones\n");
    printf("  a) Calcular la suma(%d+%d)\n", a, b);
    printf("  b) Calcular la resta(%d-%d)\n", a, b);
    printf("  c) Calcular la division(%d/%d)\n", a, b);
    printf("  d) Calcular la multiplicacion(%d*%d)\n", a, b);
    printf("  e) Calcular el factorial (%d!)\n", a);
    printf("4- Informar resultados\n");
    printf("5- Salir\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void operando1(){
    //int x;
    printf("Ingrese 1er operando: ");
    scanf("%d", &a);
}
void operando2(){
    //int y;
    printf("Ingrese 2do operando: ");
    scanf("%d", &b);
}


int operaciones(int menuOpciones) {
    printf("Ingrese operacion: ");
    fflush(stdin);
    scanf("%c", &op);

    switch (op) {
        case 'a':
            suma = a + b;
            break;
        case 'b':
            resta = a - b;
            break;
        case 'c':
            if(b == 0){
                printf("Error. El operando B es 0 \n");
            }
            else{
               division = a / b;
            }
            break;
        case 'd':
            mult = a * b;
            break;
        case 'e':
            fac = ( factorial(a));
            fac2 = ( factorial(b));
            break;
    }


        return menuOpciones;

}

int factorial(int a)
{

    int fact =0;

    if(a >= 0)
    {
        if(a == 1 || a == 0){
            fact = 1;
        }
        else{
            fact = a * factorial(a-1);
        }
    }

    return fact;
}

int resultados(int menuOpciones){
    if(op != 'a' && op != 'b' && op != 'c' && op != 'd' && op != 'e'){
            printf("Operacion invalida\n\n");
        }
    else{
        printf("a) El resultado de A+B es: %d\n", suma);
        printf("b) El resultado de A-B es: %d\n", resta);
        printf("c) El resultado de A/B es: %d\n", division);
        printf("d) El resultado de A*B es: %d\n", mult);
        printf("e) El factorial de A es: %d y el factorial de B es: %d\n\n", fac, fac2);
    }


    return menuOpciones;
}
