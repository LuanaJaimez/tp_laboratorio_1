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
    printf("**** Calculadora ****\n\n");
    printf("1- Ingresar primer operando (A=x)\n");
    printf("2- Ingresar segundo operando (B=y)\n");
    printf("3- Calcular todas las operaciones\n");
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
    if(op == 'a'){
        printf("a) El resultado de A+B es: %d\n\n", suma);
    }
    else if(op == 'b'){
        printf("b) El resultado de A-B es: %d\n", resta);
    }
    else if(op == 'c'){
        printf("c) El resultado de A/B es: %d\n", division);
    }
    else if(op == 'd'){
        printf("d) El resultado de A*B es: %d\n", mult);
    }
    else if(op == 'e'){
        printf("e) El factorial de A es: %d y el factorial de B es: %d\n\n", fac, fac2);
    }
    else{
        printf("Operacion invalida\n\n");
    }

    return menuOpciones;
}
