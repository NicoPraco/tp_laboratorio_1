/*
 * arrayEmployees.h
 *
 *  Created on: 11 may. 2021
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs/input.h"
#include "menu.h"

#define NAME_LENGHT 51
#define SURNAME_LENGTH 51

#define TRUE 1
#define FALSE 0

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
	int id;
	char name[NAME_LENGHT];
	char lastName[SURNAME_LENGTH];
	float salary;
	int sector;

	int isEmpty;

}typedef Employee;



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);

int hardcodeEmployees(Employee* list, int len, int* id);

int searchFree(Employee* list, int len, int* index);

int arrayIsEmpty(Employee* list, int len);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);

////////////////////////////////////////////////////////////////////////////////////////

int loadEmployee(Employee* list, int len, int* id);

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
*
*/
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);

////////////////////////////////////////////////////////////////////////////////////////

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);

////////////////////////////////////////////////////////////////////////////////////////
int modifyMenu(Employee* list, int len, int id);

int modifyEmployee(Employee* list, int len, int index);

////////////////////////////////////////////////////////////////////////////////////////

int sortMenu(Employee* list, int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

////////////////////////////////////////////////////////////////////////////////////////

int printOneEmployee(Employee* anEmployee);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length);

int printMenu(Employee* list, int len);

//FUNCIONES EXTRAS

int calculateAverageSalaries(Employee* list, int len);
int accumulatorOfSalaries(Employee* list, int len, float* accumulator);
int employeeCounter(Employee* list, int len, int* counter);
int getAverageSalary(Employee* list, int len, float* salaryAverage);
int employeeCounterExceedsAverageSalaries(Employee* list, int len, int* counter);

int printAverageOfSalaries(int employeeCounter, float salaryAverage, float salaryAcumulator);

#endif /* ARRAYEMPLOYEES_H_ */
