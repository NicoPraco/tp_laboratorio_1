/*
 * menu.c
 *
 *  Created on: 11 may. 2021
 *      Author: Nicolas
 */

#include "menu.h"
#include "inputs/input.h"

int EmployeeOptionsMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\n\tMENU DE EMPLEADOS:\n\n");

		printf("1. Alta Empleado.\n");
		printf("2. Baja Empleado.\n");
		printf("3. Modificar Empleado.\n");
		printf("4. Informar Empleados.\n");
		printf("5. Salir.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, vuelva a intentarlo:", 1, 5))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int EmployeeModMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\n\tMENU DE MODIFICACION:\n\n");

		printf("1. Modificar Nombre.\n");
		printf("2. Modificar Apellido.\n");
		printf("3. Modificar Salario.\n");
		printf("4. Modificar Sector.\n");
		printf("5. Salir.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, vuelva a intenarlo:", 1, 5))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int EmployeeSortMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\n\tMENU DE SELECCION DE ORDEN:\n\n");

		printf("1. Orden Ascendente.\n");
		printf("2. Order Descendente.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, vuelva a intentarlo: ", 1, 2))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int EmployeePrintMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\n\tMENU DE INFORMES\n\n");

		printf("1. Mostrar Lista Ordenada de empleados.\n");
		printf("2. Mostrar Promedio de Salarios.\n");
		printf("3. Salir.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, vuelva a intentarlo: ", 1, 3))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}
