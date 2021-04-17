/*
 ============================================================================
 Name        : trabajoPractico1.c
 Author      : Praconovo, Nicolas Javier
 Version     : Eclipse
 Copyright   : -
 Description : Trabajo Practico Nº1.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "calculadora.h"
#include "menu.h"
#include "input.h"

int main(void)
{
	setbuf(stdout,NULL);

	int option;
	int counter1 = 0;
	int counter2 = 0;

	float num1 = 0;
	float num2 = 0;

	//RESULTS:
	float resultSum;	//SUMA
	float resultSub; 	//SUBTRACTION
	float resultMulti; 	//MULTIPLICATION
	float resultDiv;  	//DIVISION
	unsigned long int resultFact1;	//FACTORIAL
	unsigned long int resultFact2;    //FACTORIAL.

	//RETURNS VALUES:
	int valueReturnGetNum1 = -1;
	int valueReturnGetNum2 = -1;
	int valueReturnCalculations = -1;

	int valueReturnSum = -1;
	int valueReturnSub = -1;
	int valueReturnMulti = -1;
	int valueReturnDiv = -1;
	int valueReturnFact1 = -1;
	int valueReturnFact2 = -1;

	int auxValueReturnFact1;
	int auxValueReturnFact2;

	do
	{
		menuDeOpciones(&option, num1, num2);
		printf("\n");

		switch(option)
		{
			case 1:
				counter1 = getFloatNoVal(&num1, "Ingrese el primer operando: ");

				if(counter1 == 0)
				{
					valueReturnGetNum1 = 0;
				}

				break;

			case 2:
				counter2 = getFloatNoVal(&num2, "Ingrese el segundo operando: ");

				if(counter2 == 0)
				{
					valueReturnGetNum2 = 0;
				}

				break;

			case 3:
				if(valueReturnGetNum1 != 0 || valueReturnGetNum2 != 0)
				{
					printf("\n\a\aNo ha ingresado uno o ambos operandos, por favor ingrese el operando faltante.\n");
				}
				else
				{
					 valueReturnSum = suma(&resultSum, num1, num2);
					 valueReturnSub = resta(&resultSub, num1, num2);
					 valueReturnMulti = multiplicacion(&resultMulti, num1, num2);
					 valueReturnDiv = division(&resultDiv, num1,  num2);

					 auxValueReturnFact1 = isNumInt(num1);
					 auxValueReturnFact2 = isNumInt(num2);

					 if(auxValueReturnFact1 != 0)
					 {
						 valueReturnFact1 = factorial(&resultFact1, (int)num1);
					 }
					 else
					 {
						 valueReturnFact1 = -2;
					 }

					 if(auxValueReturnFact2 != 0)
					 {
						 valueReturnFact2 = factorial(&resultFact2, (int)num2);
					 }
					 else
					 {
						 valueReturnFact2 = -2;
					 }

					 valueReturnCalculations = 0;

					 if(valueReturnCalculations == 0)
					 {
						 printf("Se han realizado las siguientes operaciones con exito.\n");
						 printf("A. SUMA (A + B)\n");
						 printf("B. RESTA (A - B)\n");
						 printf("C. SUMA (A * B)\n");
						 printf("D. SUMA (A / B)\n");
						 printf("E. SUMA (A!)\n");
						 printf("F. SUMA (B!)\n");
					 }
				}

				break;

			case 4:
				if(valueReturnGetNum1 != 0 || valueReturnGetNum2 != 0)
				{
					printf("\n\a\aNo ha ingresado uno o ambos operandos, por favor ingrese el operando faltante.\n");
				}
				else if(valueReturnCalculations == 0)
					{

						mostrarResultados(resultSum, resultSub, resultMulti, resultDiv, resultFact1, resultFact2,
						num1, num2, valueReturnSum, valueReturnSub, valueReturnMulti, valueReturnDiv, valueReturnFact1, valueReturnFact2);
					}
				else
				{
					printf("No se han realizado ningun calculo!!\n");
				}

				break;

			case 5:
				printf("Gracias por usar la calculadora. Nos vemos!!\n");
				break;

			default:
				printf("\a\aError. Ha ingresado en valor invalido!!\n");
				break;
		}

		printf("\n");
		system("pause");
		system("cls");

		//FUNCION PARA MOVER EL CODIGO
		//clearScreen();

	}while(option != 5);

	return EXIT_SUCCESS;
}
