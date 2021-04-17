/*
 * menu.c
 *
 *  Created on: 2 abr. 2021
 *      Author: Nicolas
 */
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "input.h"

int menuDeOpciones(int* value ,float numero1, float numero2)
{
	int toReturn = -1;

	if(value != NULL)
	{
		printf("Bienvenido al menu de opciones de la calculadora. Estas son las opciones disponibles: \n");
		printf("1. Ingresar primer operando.  (A = %.2f)\n", numero1);
		printf("2. Ingresar segundo operando. (B = %.2f)\n", numero2);
		printf("3. Calcular todas las operaciones. \n");
		printf("4. Informar resultados. \n");
		printf("5. Salir. \n");
		getInt(value, "Elija una de las opciones: ", "Error, ellija una de las opciones disponibles: ", 1, 5);

		toReturn = 0;
	}

	return toReturn;
}

