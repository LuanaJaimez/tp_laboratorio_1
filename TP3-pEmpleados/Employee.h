#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/** \brief Guarda espacio en memoria para el nuevo empleado
 *
 * \return Puntero al espacio guardado
 *
 */
Employee* employee_new();


/** \brief Carga los nuevos parametros de empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return nuevo empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


/** \brief Muestra el proximo ID
 *
 * \param pArrayListEmployee LinkedList*
 * \return int ultId
 *
 */
int employee_proxId(LinkedList* pArrayListEmployee);


/** \brief Borra un empleado elegido de la lista
 *
 * \param this Employee*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int employee_delete(Employee* this);


/** \brief Carga el id
 *
 * \param this Employee*
 * \param id int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int employee_setId(Employee* this,int id);


/** \brief Asigna el id a un empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int employee_getId(Employee* this, int* id);


/** \brief Carga el nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int employee_setNombre(Employee* this, char* nombre);


/** \brief Asigna el nombre a un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int employee_getNombre(Employee* this, char* nombre);


/** \brief Carga las horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);


/** \brief Asigna las horas trabajadas a un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);


/** \brief Carga el sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int employee_setSueldo(Employee* this, int sueldo);


/** \brief Asigna el sueldo a un empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int employee_getSueldo(Employee* this, int* sueldo);


/** \brief Recorre la lista de empleados buscando uno por ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int indice [-1] si hubo error, [i: posicion del empleado] si no hubo error
 *
 */
int employee_findById(LinkedList* pArrayListEmployee, int id);


/** \brief Muestra un empledo si la lista no está vacia
 *
 * \param pArrayListEmployee LinkedList*
 * \param indice int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int employee_listEmployee(LinkedList* pArrayListEmployee, int indice);


#endif // employee_H_INCLUDED
