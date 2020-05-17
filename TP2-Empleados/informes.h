#include "ArrayEmployees.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief permite elegir el informe del empleado
 *
 * \param list Employee[]
 * \param len int
 *
 */
void informar(Employee list[], int len);


/** \brief muestra las opciones para elegir el informe del empleado
 *
 *  \return opcion elegida
 *
 */
int menuInformes();


/** \brief acumula los sueldos de todos los empleado, realiza el promedio y la cantidad de empleados que lo superan
 *
 * \param list Employee[]
 * \param len int
 *
 */
void informarTotalSueldos(Employee list[], int len);


/** \brief ordena los empleados por apellido alfabeticamente y por sector
 *
 * \param list Employee[]
 * \param len int
 * \param order int [1] indica ascendente - [0] indica descendente
 *
 */
void sortEmployees(Employee list[], int len, int order);
