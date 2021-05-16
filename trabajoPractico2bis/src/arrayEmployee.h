/*
 * arrayEmployee.h
 *
 *  Created on: 15 may. 2021
 *      Author: Nicolas
 */

#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "inputs/input.h"

#define ELEMENTS 1000

#define FALSE 0 //FALSE  0
#define TRUE 1 //TRUE   1

typedef struct
{
    int id;

    char name[51];
    char lastName[51];

    float salary;

    int sector;

    int isEmpty;

}sEmployee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(sEmployee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/
int addEmployee(sEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(sEmployee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(sEmployee* list, int len, int id);


/** \brief Modify an existing Employee by Id.
 *
 * \param list Employee*
 * \param length int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int modifyEmployee(sEmployee* list, int length, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(sEmployee* list, int len, int order);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(sEmployee* list, int length);


//----------------------------------------------------------------------------------
//Funciones Extras:

//Menus de opciones:
int optionsMenu(int* option);
int printMenu(int* option);
int sortMenu(int* option);
int modifyMenu(int* option);

//Hardcodeo Employee
int hardcodeEmployee(sEmployee* list, int len);

//NEW EMPLOYEE
int new_Employee(sEmployee* list, int length);

//BUSCAR LIBRE!
int searchFree(sEmployee* list, int len);

//ID AUTOMATICO
int ID_AutoIncremental(sEmployee* list ,int length);

//Mostrar un empleado
void printOneEmployee(sEmployee anEmployee);

//ELEGIR ORDENAMIENTO
int chooseOrderOfSort(sEmployee* list, int len);

//CALCULA SALARIOS MAYORES AL PROMEDIO
int calculateAverageOfSalaries(sEmployee* list, int len);
int employeeCounter(sEmployee* list, int len, float salaryAverage);

//Mostrar salarios
void printAverageOfSalaries(int employeeCounter, float salaryAverage, float salaryAcumulator);

//Mostrar empleado por ID
void printEmployeeByID(sEmployee* list, int len, int ID);

#endif /* ARRAYEMPLOYEE_H_ */
