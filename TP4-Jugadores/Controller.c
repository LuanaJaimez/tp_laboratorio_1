#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Parser.h"
#include "utn.h"
#include "Controller.h"
#include <string.h>


int loadFromText(char* path , LinkedList* pLista)
{
	FILE* pFile;
	int exito = 1;

	pFile = fopen(path, "r"); //Abre el archivo para leerlo de texto, si es que existe.

	if(pFile != NULL)
	{
		if(parser_JugadorATexto(pFile, pLista) == 0)
		{
		    //Si todo salio bien cambia a 0
		    exito = 0;
			printf("\nLos datos de los jugadores en modo texto fueron cargados corretamente\n\n");
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

int loadFromBinary(char* path , LinkedList* pLista)
{
	FILE* pFile;
	int exito = 1;

	pFile = fopen(path, "rb"); //Abre el archivo que no sea de texto para leerlo, si es que existe.

	if(pFile != NULL)
	{
		if(!(parser_JugadorABinario(pFile, pLista)))
		{
		    //Si todo salio bien, exito pasa a valer 0
			exito = 0;
			printf("Los datos de los jugadores en modo binario fueron cargados corretamente\n\n");
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

int obetenerId(int* id)
{
    int error = 1;
    *id = 51;

    FILE* f;
    f = fopen("proximoId.bin", "rb");
    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);

        fclose(f);
        error = 0;
    }

    return error;
}

//---------------------------------------------------------------------------------------------------

int actualizarId(int id)
{
    int error = 1;
    id++;

    FILE* f = fopen("proximoId.bin", "wb");
    if(f != NULL)
    {
        fwrite(&id, sizeof(int), 1, f);

        fclose(f);
        error = 0;
    }

    return error;
}

//---------------------------------------------------------------------------------------------------

int addJugador(char* path , LinkedList* pLista)
{
    int proxId;
    int ultimoIndice = ll_len(pLista) - 1;
	eJugador* auxId = new_Jugador();
	char auxNom[128];
	char auxNomU[128];
	char auxPais[21];
	int auxPuntos;
	//int flag = 0;
	int exito = 1;

	eJugador* pJugador = new_Jugador();

	if(pLista != NULL && pJugador != NULL)
	{
		utn_getCadena(auxNom, 128, 2, "Ingrese nombre completo: ", "Error, nombre invalido. Reintente");
		printf("Ingrese nombre de usuario: ");
		scanf("%s", auxNomU);
		utn_getCadena(auxPais, 21, 2, "Ingrese pais: ", "Error, pais invalido. Reintente");
        utn_getEntero(&auxPuntos, 2, "Ingrese cantidad de puntos (max. 5 cifras): ", "Error, cantidad invalida.  Reintente\n", 0, 99999);

        //normalizeStr(auxNom);
        //proxId = employee_proxId(pArrayListEmployee) + 1;
        //obetenerId(&proxId);
        //printf("ID= %d\n", proxId);
        //actualizarId(proxId);

        auxId = (eJugador*) ll_get(pLista, ultimoIndice);
        jugador_getId(auxId, &proxId);

        pJugador->id = proxId + 1;

			if(proxId >= 0)
			{
				if(!jugador_setId(pJugador, proxId) &&
				   !jugador_setNombreCompleto(pJugador, auxNom) &&
				   !jugador_setNombreUsuario(pJugador, auxNomU) &&
				   !jugador_setPais(pJugador, auxPais) &&
				   !jugador_setPuntos(pJugador, auxPuntos))
				{
					ll_add(pLista, pJugador);
					printf("Se realizo el alta de un nuevo jugador\n");
				}
				else
				{
					free(pJugador);
				}
			}

		else
		{
			free(pJugador);
		}
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------

int editJugador(LinkedList* pLista)
{
    int auxId;
    int ultId;
    int exito = 1;
    int indice;
    char seguir = 's';
    char confirm;
    char auxNom[128];
	char auxNomU[128];
	char auxPais[21];
	int auxPuntos;

    eJugador* pJugador;

    system("cls");
    printf("***** Modificar jugador *****\n\n");


    if(pLista != NULL)
    {
        mostrarJugadores(pLista);

        for(int i = 0; i < ll_len(pLista); i++)
        {
            pJugador = ll_get(pLista, i);

            jugador_getId(pJugador, &auxId);
            if(auxId >= ultId)
            {
                ultId = auxId;
            }
        }

        if(!utn_getEntero(&auxId, 2, "Ingrese ID de jugador a modificar: ", "Error, ID incorrecto. Reintente", 0, ultId))
        {
            indice = buscarJugadorPorId(pLista, auxId);
            if(indice == -1)
            {
                printf("No hay registro de un jugador con ese ID\n");
            }
            else
            {
                system("cls");
                printf("\n ID \tNombre Completo \t       Nombre de Usuario \tPais \t                Puntos\n\n");
                mostrarJugador(pLista, indice);
                printf("\n\n");


//SUBMENU QUE PERMITE MODIFICAR CUALQUIERA DE LOS CAMPOS---------------------------------------------------

                do
                {
                    switch(menuModificar())
                    {
                    case 1:
                        printf("\nModifica Nombre Completo? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if(confirm == 's')
                        {
                            pJugador = ll_get(pLista, indice);

                            if(utn_getCadena(auxNom, 128, 2, "Ingrese nuevo nombre: ","Error, nombre invalido. Reintete\n") == 0)
                            {
                                jugador_setNombreCompleto(pJugador, auxNom);
                                exito = 0;

                                if(exito == 0)
                                {
                                    printf("Se ha actualizado el nombre con exito\n\n");
                                    printf("\n\n");
                                    printf("\n ID \tNombre Completo \t       Nombre de Usuario \tPais \t                Puntos\n\n");
                                    mostrarJugador(pLista, indice);
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
                        printf("\nModifica Nombre de Usurio? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if(confirm == 's')
                        {
                            pJugador = ll_get(pLista, indice);

                            printf("Ingrese nombre de usuario: ");
                            scanf("%s", auxNomU);

                            jugador_setNombreUsuario(pJugador, auxNomU);
                            exito = 0;

                            if(exito == 0)
                            {
                                printf("Se ha actualizado el nombre de usuario con exito\n\n");
                                printf("\n\n");
                                printf("\n ID \tNombre Completo \t       Nombre de Usuario \tPais \t                Puntos\n\n");
                                mostrarJugador(pLista, indice);
                            }
                            else
                            {
                                printf("Error.\n");
                            }
                        }
                        else
                        {
                            printf("Se ha cancelado la operacion\n\n");
                        }
                        break;
                    case 3:
                        printf("\nModifica Pais? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if(confirm == 's')
                        {
                            pJugador = ll_get(pLista, indice);

                            if(utn_getCadena(auxPais, 21, 2, "Ingrese nuevo pais: ","Error. Reintete\n") == 0)
                            {
                                jugador_setPais(pJugador, auxPais);
                                exito = 0;

                                if(exito == 0)
                                {
                                    printf("Se ha actualizado el pais con exito\n\n");
                                    printf("\n\n");
                                    printf("\n ID \tNombre Completo \t       Nombre de Usuario \tPais \t                Puntos\n\n");
                                    mostrarJugador(pLista, indice);
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
                    case 4:
                        printf("\nModifica Puntos? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if(confirm == 's')
                        {
                            pJugador = ll_get(pLista, indice);

                            if(utn_getEntero(&auxPuntos, 2, "Ingrese cantidad de puntos (max. 5 cifras): ", "Error, cantidad invalida.  Reintente\n", 0, 99999) == 0)
                            {
                                jugador_setPuntos(pJugador, auxPuntos);
                                exito = 0;

                                if(exito == 0)
                                {
                                    printf("Se han actualizado los puntos con exito\n\n");
                                    printf("\n\n");
                                    printf("\n ID \tNombre Completo \t       Nombre de Usuario \tPais \t                Puntos\n\n");
                                    mostrarJugador(pLista, indice);
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
                    case 5:
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

    printf("***** Modificar Jugadores *****\n\n");
    printf("1. Modificar Nombre Completo\n");
    printf("2. Modificar Nombre de Usuario\n");
    printf("3. Modificar Pais\n");
    printf("4. Modificar Puntos\n");
    printf("5. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

//---------------------------------------------------------------------------------------------------

int removeJugador(LinkedList* pLista)
{
	int exito = 1;
	int auxId;
	int ultId = 1;
	eJugador* pJugador;
	int index;
	char confirm = 'n';

	if(pLista != NULL)
	{
		mostrarJugadores(pLista);

		for(int i = 0; i < ll_len(pLista); i++)
		{
			pJugador = ll_get(pLista, i);

			jugador_getId(pJugador, &auxId);
			if(auxId >= ultId)
			{
				ultId = auxId;
			}
		}

		if(!utn_getEntero(&auxId, 2, "Ingrese ID de jugador a modificar: ", "Error, ID incorrecto. Reintente", 0, ultId))
		{
			index = buscarJugadorPorId(pLista, auxId);
			if(index == -1)
			{
			    printf("No hay registro de un jugador con ese ID\n\n");
			}
			else
            {
				printf("\n ID \tNombre Completo \t       Nombre de Usuario \tPais \t                Puntos\n\n");
                mostrarJugador(pLista, index);

				printf("Confirma baja del jugador? s/n: ");
				scanf("%c", &confirm);
				if(confirm == 's')
				{
					ll_remove(pLista, index);
					delete_jugador(pJugador);

					printf("Baja exitosa\n");

					exito = 0;
				}
			}
		}
	}
    return exito;
}

//---------------------------------------------------------------------------------------------------

int mostrarJugadores(LinkedList* pLista)
{
	int exito = 1;

    eJugador* pJugador;


	if(pLista != NULL)
	{
	    system("cls");
		printf("\n ID \tNombre Completo \t       Nombre de Usuario \tPais \t                Puntos\n\n");
		for(int i = 0; i < ll_len(pLista); i++)
		{
			pJugador = ll_get(pLista, i);
			if(pJugador != NULL)
            {
                mostrarJugador(pLista, i);
                exito = 0;
            }
		}
	}
	else if(exito == 1)
	{
		printf("No hay Jugadores cargados en la lista.\n");
	}

    return exito;
}

//---------------------------------------------------------------------------------------------------

/*
int sortJugador(LinkedList* pLista)
{
    int flag = 0;
    int exito = 1;

    printf("Espere por favor...\n");
    ll_sort(pLista, sortName, 1);
    exito = 0;

    if(exito == 0)
    {
        printf("Los jugadores fueron ordenados exitosamente\n");
    }
    else
    {
        printf("Error al ordenar los jugadores\n");
    }


    printf("***** Listado de jugadores *****\n");
    printf("\n ID \tNombre Completo \t       Nombre de Usuario \tPais \t                Puntos\n\n");

    for(int i=0; i < ll_len(pLista); i++)
    {
        if(pLista != NULL)
        {
            mostrarJugadores(pLista);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay jugadores que listar ***\n");
    }

    return exito;
}
*/


int sortJugador(LinkedList* pLista)
{

    system("cls");
	int exito = 1;
	int orden;
	//int opcion;
	LinkedList* pCopiaLista = ll_newLinkedList();


	if((pCopiaLista = ll_clone(pLista)) != NULL)  //crea una copia de la lista para mostrar, ya que sino, la opcion 5 se veria afectada.
    {
        switch(menuSortJugador())
        {
            case 1:  //alfabeticamente
                system("cls");
                utn_getEntero(&orden, 2, "Ingrese el orden en el que quiere que se \nacomoden los nombres.Recuerde que este proceso\ntarda unos segundos. (1 ascendente o 0 descendente): ", "Error. Ingrese un numero valido\n", 0, 1);

                ll_sort(pCopiaLista, sortJugadorxNombreCompleto, orden);

                //se ordenan por nombre
                break;
            case 2:  //puntos
                system("cls");
                utn_getEntero(&orden, 2, "Ingrese el orden en el que quiere que se \nacomoden los Puntos.Recuerde que este proceso\ntarda unos segundos. (1 ascendente o 0 descendente): ", "Error. Ingrese un numero valido\n", 0, 1);

                ll_sort(pCopiaLista, sortJugadorxPuntos, orden);

                //se ordenan por puntos
                break;

            }


		}

        printf("***** Listado de jugadores *****\n");
        printf("\n ID \tNombre Completo \t       Nombre de Usuario \tPais \t                Puntos\n\n");
		mostrarJugadores(pCopiaLista);

        ll_deleteLinkedList(pCopiaLista);


    return exito;
}

//---------------------------------------------------------------------------------------------------

int menuSortJugador()
{
    int option;

    printf("***** Ordenar Jugadores *****\n\n");
    printf("1. Ordenar alfabeticamente nombre completo\n");
    printf("2. Ordenar por cantidad de puntos\n");
    printf("3. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}
//---------------------------------------------------------------------------------------------------

int crearCopiaSubList(LinkedList* pLista)
{
    system("cls");
    int exito = 1;
    int desde;
    int hasta;
    LinkedList* sublista;



    if(!(utn_getEntero(&desde, 2 , "Ingrese desde que Id donde desea crear la sublista: ", "Error. Ingrese un numero positivo o mas chico.\n\n", 0, ll_len(pLista))))
       {

           if(!(utn_getEntero(&hasta, 2 , "Ingrese hasta que Id desea crear la sublista: ", "Error. Ingrese un numero positivo o mas chico.\n\n", 0, ll_len(pLista))))
              {

                   // desde--;
                   sublista = ll_subList(pLista,desde,hasta);



                    mostrarJugadores(sublista);

                    exito = 0;

              }
                ll_deleteLinkedList(sublista);

       }
       return exito;
}

//---------------------------------------------------------------------------------------------------

int saveAsText(char* path , LinkedList* pLista)
{
	int auxId;
	char auxNombreC[128];
	char auxNombreU[128];
	char auxPais[21];
	int auxPuntos;
	FILE* pFile;
	int exito = 1;
	eJugador* pJugador;

	if(pLista != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			exito = 0;
			for(int i = 0; i < ll_len(pLista); i++)
			{
				pJugador = ll_get(pLista, i);

                jugador_getId(pJugador, &auxId);
                jugador_getNombreCompleto(pJugador, auxNombreC);
                jugador_getNombreUsuario(pJugador, auxNombreU);
                jugador_getPais(pJugador, auxPais);
                jugador_getPuntos(pJugador, &auxPuntos);

                fprintf(pFile, "%d,%s,%s,%s,%d\n", auxId, auxNombreC, auxNombreU, auxPais, auxPuntos);
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

int saveAsBinary(char* path , LinkedList* pLista)
{
	int exito = 1;
	FILE* pFile;
	eJugador* pJugador;

	if(pLista != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 0; i < ll_len(pLista); i++)
		{
			pJugador = (eJugador*) ll_get(pLista, i);
			if(pJugador != NULL)
            {
                fwrite(pJugador, sizeof(eJugador), 1, pFile);
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

/*
int filtrarxPuntos(void* unJugador)
{
    int auxReturn = 0;
    eJugador* x;

    if(unJugador != NULL)
    {
        x = (eJugador*) unJugador;
        if(x->puntos >= 1000)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}
*/

/*
int filtrarxPais(void* unJugador)
{
    int auxReturn = 0;
    eJugador* x;

    if(unJugador != NULL)
    {
        x = (eJugador*) unJugador;
        if(strcmp(x->pais, "China") == 0)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}
*/
