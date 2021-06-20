/*
 * serializer.c
 *
 *  Created on: 18 jun. 2021
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

#include "serializer.h"
#include "Employee.h"

int serializer_EmployeeToText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	int i;
	int cant;

	char auxID[BUFFER_LEN];
	char auxNombre[NAME_LEN];		//SI O SI DEBE USAR EL NAME_LEN. SI USA BUFFER_LEN NO GUARDA EL ID.
	char auxHorasTrabajadas[BUFFER_LEN];
	char auxSueldo[BUFFER_LEN];

	Employee* this;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		cant = ll_len(pArrayListEmployee);

		if(cant > 0)
		{
			fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

			for(i = 0; i < cant; i++)
			{
				this = (Employee*) ll_get(pArrayListEmployee, i);

				if(this != NULL && !employee_getIdTxt(this, auxID) && !employee_getNombre(this, auxNombre)
				&& !employee_getHorasTrabajadasTxt(this, auxHorasTrabajadas) && !employee_getSueldoTxt(this, auxSueldo))
				{
					fprintf(pFile, "%s,%s,%s,%s\n", auxID, auxNombre, auxHorasTrabajadas, auxSueldo);

				}
				else
				{
					break;
				}
			}

			if(i == cant)
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

int serializer_EmployeeToBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	int i;
	int cant;

	Employee* this;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		cant = ll_len(pArrayListEmployee);

		if(cant > 0)
		{
			for(i = 0; i < cant; i++)
			{
				this = (Employee*) ll_get(pArrayListEmployee, i);

				if(this == NULL || fwrite(this, sizeof(Employee), 1, pFile) != 1)
				{
					break;
				}
			}

			if(i == cant)
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}
