/*
 * arrayEmployees.c
 *
 *  Created on: 11 may. 2021
 *      Author: Nicolas
 */

#include "arrayEmployees.h"

int initEmployees(Employee* list, int len)
{
	int toReturn = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}

		toReturn = 0;
	}

	return toReturn;
}

int hardcodeEmployees(Employee* list, int len, int* id)
{
	int toReturn = -1;

	int i = 0;
	int index;
	int quantity;

	int flag = FALSE;

    Employee auxEmployee[] =
    {
    		{1, "Martin", 	 "Fernandez", 	45000, 5, FALSE},
			{2, "Jorge", 	 "Menendez", 	50000, 1, FALSE},
			{3, "Julio", 	 "Lopez", 		60000, 3, FALSE},
			{4, "Valentina", "Alvarez", 	60000, 1, FALSE},
			{5, "Martin", 	 "Lopez", 		80000, 2, FALSE},
			{6, "Miguel", 	 "DiLuca", 		30000, 4, FALSE}
    };

    if(list != NULL && len > 0 && id != NULL)
    {
    	quantity = sizeof(auxEmployee) / sizeof(Employee);

    	if(quantity <= len)
    	{
			while(i < quantity && !searchFree(list, len, &index))
			{

				if(index > -1)
				{
					if(auxEmployee[i].id > *id)
					{
						*id = auxEmployee[i].id;
					}

					list[index] = auxEmployee[i];

					flag = TRUE;
				}
				else
				{
					break;
				}

				i++;

			}

			if(flag)
			{
				toReturn = 0;
			}
    	}
    }
	return toReturn;

}

int searchFree(Employee* list, int len, int* index)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && index != NULL && *index < len)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				*index = i;
				toReturn = 0;
				break;
			}
		}
	}

	return toReturn;
}

int arrayIsEmpty(Employee* list, int len)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len  > 0)
	{
		toReturn = 1;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				toReturn = 0;
				break;
			}
		}
	}

	return toReturn;
}

int findEmployeeById(Employee* list, int len, int id)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				toReturn = i;
				break;
			}
		}
	}

	return toReturn;
}

/////////////////////////////////////////////////////////////////////////////////

int loadEmployee(Employee* list, int len, int* id)
{
	int toReturn = -1;

	Employee auxEmployee;

	if(list != NULL && len > 0 && id != NULL)
	{
		if(!getString(auxEmployee.name, "Ingrese el nombre del empleado: ",
				"Error, vuelva a intentarlo: ", 3, NAME_LENGHT))
		{
			if(!getString(auxEmployee.lastName, "Ingrese el apellido del empleado: ",
					"Error, vuelva a intentarlo: ", 3, SURNAME_LENGTH))
			{
				if(!getFloat(&auxEmployee.salary, "Ingrese el salario del empleado: ",
						"Error, vuelva a intentarlo: ", 1000, 100000))
				{
					printf("\nLos sectores disponibles son: \n");
					printf("1. Sector de Recursos Humanos.\n");
					printf("2. Sector de Relaciones con el Cliente.\n");
					printf("3. Sector Administrativo.\n");
					printf("4. Sector de Ventas.\n");
					printf("5. Sector de Finanzas.\n");

					if(!getInt(&auxEmployee.sector, "Ingrese el sector del empleado (1 a 5): ",
							"Error, vuelva a intentarlo: ", 1, 5))
					{
						if(!addEmployee(list, len, *id + 1, auxEmployee.name, auxEmployee.lastName,
								auxEmployee.salary, auxEmployee.sector))
						{
							(*id)++;

							toReturn = 0;
						}
					}
				}
			}
		}
	}

	return toReturn;
}

int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
	int toReturn = -1;

	int index;

	if(list != NULL && len > 0 && id > -1 && name != NULL && lastName != NULL && salary > 1000 && sector > 0)
	{
		searchFree(list, len, &index);

		if(index > -1)
		{
			list[index].id = id;

			strncpy(list[index].name, name, NAME_LENGHT);
			strncpy(list[index].lastName, lastName, NAME_LENGHT);

			list[index].salary = salary;
			list[index].sector = sector;

			list[index].isEmpty = FALSE;

			toReturn = 0;
		}
	}


	return toReturn;
}

int removeEmployee(Employee* list, int len, int id)
{
	int toReturn = -1;

	int index;
	int answer;

	if(list != NULL && len > 0)
	{
		index = findEmployeeById(list, len, id);

		if(index > -1)
		{
			printf("\n\n");

			printf("\tBAJA DE EMPLEADO\n\n");

			printf("ID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR\n\n");
			printOneEmployee(&list[index]);

			getInt(&answer, "Esta seguro de borrar a este empleado? (0 = NO/1 = SI): ", "Error, vuelva a intentarlo: ", 0, 1);

			if(answer == 1)
			{
				list[index].isEmpty = TRUE;

				toReturn = 0;
			}
			else
			{
				//USUARIO CANCELO EL BORRAR
				toReturn = 1;
			}
		}
	}

	return toReturn;
}

int modifyMenu(Employee* list, int len, int id)
{
	int toReturn = -1;

	int index;
	int answer;

	if(list != NULL && len > 0)
	{
		index = searchFree(list, len, &index);

		if(index > -1)
		{
			printf("\n\n");

			printf("\tMODIFICACION DE EMPLEADO\n\n");
			printOneEmployee(&list[index]);

			getInt(&answer, "Esta seguro de borrar a este empleado? (0 = NO/1 = SI): ", "Error, vuelva a intentarlo: ", 0, 1);

			if(answer == 1)
			{
				if(!modifyEmployee(list, len, index))
				{
					toReturn = 0;
				}
			}
			else
			{
				//EL USUARIO CANCELO EL MODIFICAR
				toReturn = 1;
			}
		}
	}

	return toReturn;
}

int modifyEmployee(Employee* list, int len, int index)
{
	int toReturn = -1;

	int option;

	int flag = FALSE;

	Employee auxEmployee;

	if(list != NULL && len > 0)
	{
		do
		{
			EmployeeModMenu(&option);

			switch(option)
			{
				case 1:
					if(!getString(auxEmployee.name, "Ingrese el nuevo nombre: ",
								"Error, vuelva a intentarlo: ", 3, NAME_LENGHT))
					{
						strncpy(list[index].name, auxEmployee.name, NAME_LENGHT);

						flag = TRUE;
					}
					break;

				case 2:
					if(!getString(auxEmployee.lastName, "Ingrese en nuevo apellido: ",
								"Error, vuelva a intentarlo: ", 3, SURNAME_LENGTH))
					{
						strncpy(list[index].lastName, auxEmployee.lastName, SURNAME_LENGTH);

						flag = TRUE;
					}
					break;

				case 3:
					if(!getFloat(&auxEmployee.salary, "Ingrese el nuevo salario: ",
								"Error, vuelva a intentarlo: ", 1000, 100000))
					{
						list[index].salary = auxEmployee.salary;

						flag = TRUE;
					}
					break;

				case 4:
					if(!getInt(&auxEmployee.sector, "Ingrese el nuevo sector entre 1 y 5: ",
							"Error, vuelva a intentarlo: ", 1, 5))
					{
						list[index].sector = auxEmployee.sector;

						flag = TRUE;
					}
					break;

				case 5:
					printf("Saliendo...\n");
					break;

				default:
					printf("Error, ha ingresado un valor invalido.\n");
					break;
			}

			printf("\n");
			system("pause");
			system("cls()");

		}while(option != 5);

		if(flag)
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int sortMenu(Employee* list, int len)
{
	int toReturn = -1;

	int option;
	int order;

	if(list != NULL && len > 0)
	{
		do
		{
			EmployeeSortMenu(&option);

			switch(option)
			{
				case 1:
					order = 1;
					break;

				case 2:
					order = 0;
					break;

				default:
					printf("Error, ha ingresado un valor invalido.\n");
			}

		}while(option != 1 && option != 2);

		if(!sortEmployees(list, len, order))
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int sortEmployees(Employee* list, int len, int order)
{
	int toReturn = -1;

	int i;
	int flagSwap;
	int auxCmp;

	Employee auxEmployee;

	if(list != NULL && len > 0)
	{
		do
		{
			flagSwap = FALSE;

			for(i = 0; i < len - 1; i++)
			{
				if(list[i].isEmpty == FALSE && list[i + 1].isEmpty == FALSE)
				{
					auxCmp = strncmp(list[i].lastName, list[i + 1].lastName, SURNAME_LENGTH);

					if( ((auxCmp > 0 || (auxCmp == 0 && list[i].sector > list[i + 1].sector)) && order == 1)
							||
					((auxCmp < 0 || (auxCmp == 0 && list[i].sector < list[i + 1].sector)) && order == 0) )
					{
						auxEmployee = list[i];
						list[i] = list[i + 1];
						list[i + 1] = auxEmployee;

						flagSwap = TRUE;
					}
				}
			}
			len--;

		}while(flagSwap);

		toReturn = 0;
	}

	return toReturn;
}

int printOneEmployee(Employee* anEmployee)
{
	int toReturn = -1;

	if(anEmployee != NULL)
	{
		printf("%d\t %7s\t %8s\t %7g\t %d\n", (*anEmployee).id, (*anEmployee).name, (*anEmployee).lastName, (*anEmployee).salary, (*anEmployee).sector);

		toReturn = 0;
	}

	return toReturn;
}

int printEmployees(Employee* list, int length)
{
	int toReturn = -1;

	int i;

	if(list != NULL && length > 0)
	{
		printf("\n\n");
		system("pause");

		printf("\tLISTA DE EMPLEADOS.\n\n");
		printf("ID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR\n\n");

		for(i = 0; i < length; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				if(printOneEmployee(&list[i]))
				{
					break;
				}
			}
		}

		if(i == length)
		{
			toReturn = 0;
		}
	}

	return toReturn;
}

int printMenu(Employee* list, int len)
{
	int toReturn = -1;

	int option;

	if(list != NULL && len > 0)
	{
		do
		{
			EmployeePrintMenu(&option);

			switch(option)
			{
				case 1:
					//LISTAR ORDENADA
					if(!sortMenu(list, len))
					{
						if(!printEmployees(list, len))
						{
							printf("Lista de empleados mostrada correctamente.\n");
						}
						else
						{
							printf("Error al mostrar la lista de empleados.\n");
						}
					}
					else
					{
						printf("Error al mostrar el menu de ordenamiento.\n");
					}
					break;

				case 2:
					//PROMEDIO DE SALARIOS
					if(!calculateAverageSalaries(list, len))
					{
						printf("Reporte de salarios mostrado con exito.\n");
					}
					else
					{
						printf("Error al mostrar el reporte de salarios.\n");
					}
					break;

				case 3:
					printf("Saliendo...\n");
					break;

				default:
					printf("Error, ha ingresado un valor invalido.\n");
			}

			printf("\n");
			system("pause");
			system("cls()");

		}while(option != 3);
	}

	return toReturn;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

//								CALCULAR SALARIOS											  //

/////////////////////////////////////////////////////////////////////////////////////////////////

int calculateAverageSalaries(Employee* list, int len)
{
	int toReturn = -1;

	int employeeNumerator;

	float salaryAcumulator;
	float salaryAverage;

	if(list != NULL && len > 0)
	{
		if(!accumulatorOfSalaries(list, len, &salaryAcumulator) && !employeeCounter(list, len, &employeeNumerator) &&
		   !getAverageSalary(list, len, &salaryAverage) && !employeeCounterExceedsAverageSalaries(list, len, &employeeNumerator))
		{
			printAverageOfSalaries(employeeNumerator, salaryAverage, salaryAcumulator);

			toReturn = 0;
		}
	}

	return toReturn;
}

int accumulatorOfSalaries(Employee* list, int len, float* accumulator)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && accumulator != NULL)
	{
		*accumulator = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)

			*accumulator = *accumulator + list[i].salary;
		}

		toReturn = 0;
	}

	return toReturn;
}

int employeeCounter(Employee* list, int len, int* counter)
{
	int toReturn = -1;

	int i;

	if(list != NULL && len > 0 && counter != NULL)
	{
		*counter = 0;

		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				(*counter)++;
			}
		}

		toReturn = 0;
	}

	return toReturn;
}

int getAverageSalary(Employee* list, int len, float* salaryAverage)
{
	int toReturn = -1;

	int counter;
	float accumulator;

	if(list != NULL && len > 0 && salaryAverage != NULL)
	{
		if(!accumulatorOfSalaries(list, len, &accumulator) && !employeeCounter(list, len, &counter) && counter > 0)
		{
			*salaryAverage = accumulator / counter;

			toReturn = 0;
		}
	}

	return toReturn;
}

int employeeCounterExceedsAverageSalaries(Employee* list, int len, int* counter)
{
	int toReturn = -1;

	int i;
	float average;

	if(list != NULL && len > 0 && counter != NULL)
	{
		*counter = 0;

		if(!getAverageSalary(list, len, &average))
		{
			for(i = 0; i < len; i++)
			{
				if(list[i].isEmpty == FALSE && list[i].salary > average)
				{
					(*counter)++;
				}
			}
			toReturn = 0;
		}
	}

	return toReturn;
}

int printAverageOfSalaries(int employeeCounter, float salaryAverage, float salaryAcumulator)
{
	int toReturn = -1;

	if(employeeCounter > 0 && salaryAverage > 0 && salaryAcumulator > 0)
	{
		printf("\tREPORTE DE SALARIOS\n\n");

		printf("Suma total de salarios: %g. \n", salaryAcumulator);
		printf("Promedio de salarios: %g. \n", salaryAverage);
		printf("Cantidad de empleados que superar el primedio: %d.\n\n", employeeCounter);

		toReturn = 0;
	}

	return toReturn;
}

