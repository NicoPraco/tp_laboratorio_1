/*
 * menu.c
 *
 *  Created on: 6 jun. 2021
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int optionsMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("Menu De Opciones:\n\n");
		printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
		printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
		printf("3. Alta de empleado.\n");
		printf("4. Modificar datos de empleado.\n");
		printf("5. Baja de empleado.\n");
		printf("6. Listar empleados.\n");
		printf("7. Ordenar empleados.\n");
		printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
		printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
		printf("10. Salir del programa.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, elija una opcion valida:", 1, 10))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int modMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\nMenu de Opciones. Modificacion de Empleado.\n\n");
		printf("1. Nombre del empleado.\n");
		printf("2. Horas Trabajadas del empleado.\n");
		printf("3. Sueldo del empleado.\n");
		printf("4. Salir del menu de opciones.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, elija una opcion valida. Vuelva a intentarlo: ", 1, 4))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int sortMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\nMenu de Opciones. Ordenamiento de Empleado.\n\n");
		printf("1. Ordenar por ID.\n");
		printf("2. Ordenar por nombre.\n");
		printf("3. Ordenar por horas trabajadas.\n");
		printf("4. Ordenar por sueldo.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, elija una opcion valida. Vuelva a intentarlo", 1, 4))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int sortOrderMenu(int* input)
{
	int toReturn = -1;

	if(input != NULL)
	{
		printf("\nMenu de Opciones. Sentido del Ordenamiento.\n\n");
		printf("1. Sentido Ascendente.\n");
		printf("2. Sentido Descendente.\n\n");

		if(!getInt(input, "Elija una opcion: ", "Error, solo entre 1 y 2. Vuelva a intentarlo: ", 1, 2))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}



