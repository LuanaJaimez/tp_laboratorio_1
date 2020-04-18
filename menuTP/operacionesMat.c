#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacionesMat.h"

/** \brief calcula el factorial de un numero
 *
 * \param numero sobre el que se realizara la operacion
 * \return factorial del numero ingresado
 *
 */
int factorial(int a);

/** \brief mensaje que pide al usuario el ingreso del primer operando */
void operando1();

/** \brief mensaje que pide al usuario el ingreso del segundo operando */
void operando2();

/** \brief realiza las operaciones matematicas de suma, resta, multiplicacion, division y factorial
 *
 * \param sitio de donde se toman y colocan los datos
 * \return todas las operaciones matematicas calculadas
 *
 */
int operaciones(int menuOpciones);

/** \brief muestra los resultados de las operaciones realizadas
 *
 * \param sitio donde se toman y colocan los datos
 * \return valores de la suma, resta, multiplicacion, division y factorial de A y B
 *
 */
int resultados(int menuOpciones);




//Declaracion de variables
int numeroA = 0;
int numeroB = 0;
int suma;
int resta;
int mult;
float division;
int fac;
int fac2;
int sumaR;
int restaR;
int multR;
float divisionR;
int facR;
int fac2R;


int menuOpciones()
{
    int opcion;

    system("cls");
    printf("   *****************************************  \n");
    printf("   **** Calculadora de numeros enteros *****  \n");
    printf("   *********** Maximo 6 digitos ************  \n");
    printf("   *****************************************  \n\n");
    printf("1- Ingresar primer operando (A=%d)\n", numeroA);
    printf("2- Ingresar segundo operando (B=%d)\n", numeroB);
    printf("3- Calcular todas las operaciones\n");
    printf("  a) Calcular la suma(%d+%d)\n", numeroA, numeroB);
    printf("  b) Calcular la resta(%d-%d)\n", numeroA, numeroB);
    printf("  c) Calcular la division(%d/%d)\n", numeroA, numeroB);
    printf("  d) Calcular la multiplicacion(%d*%d)\n", numeroA, numeroB);
    printf("  e) Calcular el factorial (%d!)\n", numeroA);
    printf("4- Informar resultados\n");
    printf("  a) El resultado de A+B es: %d\n", sumaR);
    printf("  b) El resultado de A-B es: %d\n", restaR);
    printf("  c) El resultado de A/B es: %.2f\n", divisionR);
    printf("  d) El resultado de A*B es: %d\n", multR);
    printf("  e) El factorial de A es: %d y el factorial de B es: %d\n\n", facR, fac2R);
    printf("5- Salir\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);


    return opcion;
}




////////////////////
void operando1()
{
//Se pide el operando A
    printf("Ingrese 1er operando: ");
    scanf("%d", &numeroA);
}


////////////////////
void operando2()
{
//Se pide el operando B
    printf("Ingrese 2do operando: ");
    scanf("%d", &numeroB);
}


////////////////////
int operaciones(int menuOpciones)
{
//Se realizan las operaciones matematicas
    if(numeroA == 0 && numeroB == 0)
    {
        printf("ERROR. Ingrese 1er y 2do operando para continuar\n\n");
    }
    else
    {
        //a) Suma
        suma = numeroA + numeroB;
        //b) Resta
        resta = numeroA - numeroB;
        //c) Division
        if(numeroB == 0)
        {
            printf("ERROR. Igrese 2do operando distinto de 0\n");
        }
        else
        {
            division = (float) numeroA / numeroB;
        }
        //d) Multiplicacion
        mult = numeroA * numeroB;
        //e) Factorial
        if(numeroA < 0)
        {
            printf("ERROR. La operacion Factorial no se puede realizar porque el numero es negativo\n");
        }
        else
        {
            fac = ( factorial(numeroA));
        }
        if(numeroB < 0)
        {
            printf("ERROR. La operacion Factorial no se puede realizar porque el numero es negativo\n");
        }
        else
        {
            fac2 = ( factorial(numeroB));
        }

    }

//Se informa que las operaciones fueron calculadas.
    if(numeroB != 0)
    {
        printf("Calculando operaciones...\n\n");
    }

    return menuOpciones;

}


////////////////////
int resultados(int menuOpciones)
{
//Se imprimen los resultados
    if(numeroA == 0 && numeroB == 0)
    {
        printf("ERROR. Ingrese 1er y 2do operando para continuar\n\n");
    }
    else
    {
        sumaR = suma;
        restaR = resta;
        divisionR = division;
        multR = mult;
        facR = fac;
        fac2R = fac2;
    }


    return menuOpciones;
}


//Desarrollo de la funcion factorial

////////////////////
int factorial(int a)
{
    int fact =0;

    if(a >= 0)
    {
        if(a == 1 || a == 0)
        {
            fact = 1;
        }
        else
        {
            fact = a * factorial(a-1);
        }
    }

    return fact;
}
