/*
 * parser.c
 *
 *  Created on: 5 jun. 2021
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param id int*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee, int* id)
{
	int toReturn = -1;

	int auxID;

	char IDstr[BUFFER_LEN];
	char auxNombre[BUFFER_LEN];
	char auxHorasTrabajadas[BUFFER_LEN];
	char auxSueldo[BUFFER_LEN];

	Employee* this;

	if(pFile != NULL && pArrayListEmployee != NULL && id != NULL)
	{
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", IDstr, auxNombre, auxHorasTrabajadas, auxSueldo) == 4)
			{
				this = employee_newParametrosAsText(IDstr, auxNombre, auxHorasTrabajadas, auxSueldo);

				if(this != NULL)
				{
					auxID = atoi(IDstr);

					if(auxID > *id)
					{
						*id = auxID;
					}

					ll_add(pArrayListEmployee, this);
				}
			}
		}

		toReturn = 0;
	}

    return toReturn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee, int* id)
{
	int toReturn = -1;

	int auxID;

	Employee* this;

	if(pFile != NULL && pArrayListEmployee != NULL && id != NULL)
	{
		while(!feof(pFile))
		{
			this = employee_new();

			if(this != NULL && fread(this, sizeof(Employee), 1, pFile) == 1)
			{
				if(!employee_getId(this, &auxID) && auxID > *id)
				{
					*id = auxID;
				}

				ll_add(pArrayListEmployee, this);
			}
		}

		toReturn = 0;
	}

	return toReturn;
}
