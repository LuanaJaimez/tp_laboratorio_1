#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int loadFromText(char* path , LinkedList* pLista);

int loadFromBinary(char* path , LinkedList* pLista);

int obetenerId(int* id);

int actualizarId(int id);

int addJugador(char* path , LinkedList* pLista);

int editJugador(LinkedList* pLista);

int menuModificar();

int removeJugador(LinkedList* pLista);

int mostrarJugadores(LinkedList* pLista);

int sortJugador(LinkedList* pLista);

int menuSortJugador();

int saveAsText(char* path , LinkedList* pLista);

int saveAsBinary(char* path , LinkedList* pLista);

#endif // CONTROLLER_H_INCLUDED
