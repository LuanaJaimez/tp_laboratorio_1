#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Analiza y parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return exito [1] si hubo error, [0] si no hubo error
 *
 */
int parser_JugadorATexto(FILE* pFile , LinkedList* pLista);


/** \brief Analiza y parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return exito [1] si hubo error, [0] si no hubo error
 *
 */
int parser_JugadorABinario(FILE* pFile , LinkedList* pLista);


#endif // PARSER_H_INCLUDED
