#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastname[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED


/** \brief le asigna un lugar al empleado
 *
 * \param list Employee[]
 * \param len int
 *
 */
void inicializarEmpleados(Employee list[], int len);


/** \brief busca lugar libre de empleados
 *
 * \param list Employee[]
 * \param len int
 * \return indice [-1] si hubo error, si no la posicion libre
 *
 */
int buscarLibre(Employee list[], int len);


/** \brief busca un empleado por el ingreso de id
 *
 * \param list Employee[]
 * \param len int
 * \param id int
 * \return indice [-1] si hubo error, si no la posicion del empledo
 *
 */
int buscarEmpleado(Employee list[], int len, int id);


/** \brief pide y guarda los datos ingresado por el usuario de un nuevo empleado
 *
 * \param list Employee[]
 * \param len int
 * \param idx int
 * \return todoOk [0] si hubo error, [1] si no hubo error
 *
 */
int altaEmpleado(Employee list[], int len, int idx);


/** \brief elimina un empleado elegido ingresando el id del mismo del sistema
 *
 * \param list Employee[]
 * \param len int
 *
 */
void bajaEmpleado(Employee list[], int len);


/** \brief permite modificar los datos del empleado
 *
 * \param list Employee[]
 * \param len int
 *
 */
void modificarEmpleado(Employee list[], int len);


/** \brief muestra las opciones para elegir la modificacion del empleado
 *
 * \return opcion elegida
 *
 */
int menuModificar();


/** \brief imprime en pantalla los datos del empleado
 *
 * \param x Employee
 *
 */
void mostrarEmpleado(Employee x);
