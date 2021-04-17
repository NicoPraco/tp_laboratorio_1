/*
 * menu.h
 *
 *  Created on: 2 abr. 2021
 *      Author: Nicolas
 */

#ifndef MENU_H_
#define MENU_H_

/**
* \brief Es el menu con el que el usuario interactua.
* \param value Puntero donde se carga el numero ingresado en el menu.
* \param message Es el mensaje a ser mostrado
* \return Devuelve -1 si error, 0 si OK.
*
*/
int menuDeOpciones(int* value, float numero1, float numero2);

#endif /* MENU_H_ */
