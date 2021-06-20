/*
 * Controller.c
 *
 *  Created on: 5 jun. 2021
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "serializer.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* id)
{
	int toReturn = -1;

	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL && id != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL)
		{
			if(!parser_EmployeeFromText(pFile, pArrayListEmployee, id))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

    return toReturn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* id)
{
	int toReturn = -1;

	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL && id != NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee, id))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

	return toReturn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
	int toReturn = -1;

	if(pArrayListEmployee != NULL && id != NULL)
	{
		if(!employee_add(pArrayListEmployee, id))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	if(pArrayListEmployee != NULL)
	{
		if(!employee_edit(pArrayListEmployee))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	if(pArrayListEmployee != NULL)
	{
		if(!employee_remove(pArrayListEmployee))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	if(pArrayListEmployee != NULL)
	{
		if(!employee_list(pArrayListEmployee))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	if(pArrayListEmployee != NULL)
	{
		if(!showSortMenu(pArrayListEmployee))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			if(!serializer_EmployeeToText(pFile, pArrayListEmployee))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

	return toReturn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");

		if(pFile != NULL)
		{
			if(!serializer_EmployeeToBinary(pFile, pArrayListEmployee))
			{
				toReturn = 0;
			}
			fclose(pFile);
		}
	}

	return toReturn;
}
