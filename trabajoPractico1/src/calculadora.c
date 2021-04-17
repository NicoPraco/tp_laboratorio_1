/*
 * calculadora.c
 *
 *  Created on: 2 abr. 2021
 *      Author: Nicolas
 */
#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "calculadora.h"

float suma(float* pResult, float num1, float num2)
{
	int toReturn = -1;

	if(pResult != NULL)
	{
		*pResult = num1 + num2;

		toReturn = 0;
	}

	return toReturn;
}

float resta(float* pResult, float num1, float num2)
{
	int toReturn = -1;

	if(pResult != NULL)
	{
		*pResult = num1 - num2;

		toReturn = 0;
	}

	return toReturn;
}

float multiplicacion(float* pResult, float num1, float num2)
{
	int toReturn = -1;

	if(pResult != NULL)
	{
		*pResult = num1 * num2;

		toReturn = 0;
	}

	return toReturn;
}

float division(float* pResult, float num1, float num2)
{
	int toReturn = -1;

	if(pResult != NULL)
	{
		if(num2 == 0)
		{
			toReturn = 1;
		}
		else
		{
			*pResult = num1 / num2;

			toReturn = 0;
		}

	}

	return toReturn;
}

int factorial(unsigned long int* pResult, int num1)
{
	int toReturn = -1;

	int i;

	if(num1 >= 0 && pResult != NULL)
	{

		*pResult = 1;

		for(i = num1; i >= 1; i--)
		{
			*pResult = *pResult * i;
		}

		toReturn = 0;

	}

	return toReturn;
}

///////////////////////////////////////////////////////////////////////

void mostrarResultados(float ResultSum, float ResultSub, float ResultMult, float ResultDiv, unsigned long int ResultFact1, unsigned long int ResultFact2,
		float num1, float num2, int valueReturnSum, int valueReturnSub, int valueReturnMulti, int valueReturnDiv, int valueReturnFact1, int valueReturnFact2)
{

	printf("\n");

	//SUMA
	if(valueReturnSum != -1)
	{
		printf("El resultado de la suma de los numeros (%g y %g) es: %g\n", num1, num2, ResultSum);
	}
	else
	{
		printf("No se pudo realizar la suma!\n");
	}

	//RESTA
	if(valueReturnSub != -1)
	{
		printf("El resultado de la resta de los numeros (%g y %g) es: %g\n", num1, num2, ResultSub);
	}
	else
	{
		printf("No se pudo realizar la resta!\n");
	}

	//MULTIPLICACION
	if(valueReturnMulti != -1)
	{
		printf("El resultado de la multiplicacion de los numeros (%g y %g) es: %g\n", num1, num2, ResultMult);
	}
	else
	{
		printf("No se pudo realizar la multiplicacion!\n");
	}

	//DIVISION
	if(valueReturnDiv != -1)
	{
		if(valueReturnDiv != 1)
		{
			printf("El resultado de la division de los numeros (%g y %g) es: %g\n", num1, num2, ResultDiv);
		}
		else
		{
			printf("No se puede dividir por 0!!\n");
		}

	}

	//FACTORIAL 1
	if(valueReturnFact1 == 0)
	{
		printf("El resultado de la factorial del numero (%g) es: %lu\n", num1, ResultFact1);
	}
	else if(valueReturnFact1 == -1)
	{
		printf("No se puede realizar factorial de un numero negativo!\n");
	}
	else
	{
		printf("No se puede realizar el factorial de un numero con coma!\n");
	}

	//FACTORIAL 2
	if(valueReturnFact2 == 0)
	{
		printf("El resultado de la factorial del numero (%g) es: %lu\n", num2, ResultFact2);
	}
	else if(valueReturnFact2 == -1)
	{
		printf("No se puede realizar de un numero negativo!\n");
	}
	else
	{
		printf("No se puede realizar el factorial de un numero con coma!\n");
	}

	printf("\n");

}

