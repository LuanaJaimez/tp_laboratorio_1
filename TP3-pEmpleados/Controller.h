
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Da de alta a un nuevo empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_addEmployee(char* path , LinkedList* pArrayListEmployee);


/** \brief Modifica los datos de un empleado elegido por ID
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Muestra las opciones para elegir la modificacion del empleado
 *
 * \return opcion elegida
 *
 */
int menuModificar();


/** \brief Da de baja a un empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Lista a los empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordena los empleados por nombre
 *
 * \param firstName void*
 * \param secondName void*
 * \return int change
 *
 */
int sortName(void* firstName, void* secondName);


/** \brief Ordena los empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);




