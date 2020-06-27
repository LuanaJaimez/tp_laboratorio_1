#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombreCompleto[128];
    char nombreUsuario[128];
    char pais[21];
    int puntos;
}eJugador;


/** \brief Guarda espacio en memoria para el nuevo jugador
 *
 * \return Puntero al espacio guardado
 *
 */
eJugador* new_Jugador();


/** \brief Carga los nuevos parametros de jugadores
 *
 * \param idStr char*
 * \param nombreCompletoStr char*
 * \param nombreUsuarioStr char*
 * \param paisStr char*
 * \param puntosStr char*
 * \return nuevo jugador
 *
 */
eJugador* jugadoresParametros(char* idStr, char* nombreCompletoStr, char* nombreUsuarioStr, char* paisStr, char* puntosStr);


/** \brief Muestra el proximo ID
 *
 * \param pArrayListEmployee LinkedList*
 * \return int ultId
 *
 */
//int employee_proxId(LinkedList* pArrayListEmployee);



/** \brief Borra un jugador de la lista
 *
 * \param this Employee*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int delete_jugador(eJugador* this);


/** \brief Carga el id
 *
 * \param this Employee*
 * \param id int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int jugador_setId(eJugador* this, int id);

int jugador_setNombreCompleto(eJugador* this, char* nombreCompleto);

int jugador_setNombreUsuario(eJugador* this, char* nombreUsuario);

int jugador_setPais(eJugador* this, char* pais);

int jugador_setPuntos(eJugador* this, int puntos);

int jugador_getId(eJugador* this, int* id);

int jugador_getNombreCompleto(eJugador* this, char* nombreCompleto);

int jugador_getNombreUsuario(eJugador* this, char* nombreUsuario);

int jugador_getPais(eJugador* this, char* pais);

int jugador_getPuntos(eJugador* this, int* puntos);

int mostrarJugador(LinkedList* pLista, int indice);

int buscarJugadorPorId(LinkedList* pLista, int id);

int sortJugadorxNombreCompleto(void* x, void* y);

int sortJugadorxPuntos(void* x, void* y);

#endif // JUGADOR_H_INCLUDED
