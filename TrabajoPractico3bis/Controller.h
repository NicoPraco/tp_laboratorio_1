/*
 * Controller.h
 *
 *  Created on: 5 jun. 2021
 *      Author: Nicolas
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* id);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* id);
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

#endif /* CONTROLLER_H_ */
