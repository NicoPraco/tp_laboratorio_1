/*
 ============================================================================
 Name        : trabajoPractico2.c
 Author      : Praconovo, Nicolas Javier
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "arrayEmployees.h"

#define MAX_EMPLOYEE 1000

int main(void)
{
	setbuf(stdout,NULL);

	Employee arrayEmployees[MAX_EMPLOYEE];

	int option;
	int auxID;

	int valueReturnRemove;
	int valueReturnMod;

	int id = 0;

	if(!initEmployees(arrayEmployees, MAX_EMPLOYEE))
	{
		hardcodeEmployees(arrayEmployees, MAX_EMPLOYEE, &id);

		do
		{
			if(!EmployeeOptionsMenu(&option))
			{
				switch(option)
				{
					case 1:
						//ALTA EMPLEADO
						if(!loadEmployee(arrayEmployees, MAX_EMPLOYEE, &id))
						{
							printf("\nEmpleado cargado con exito.\n");
						}
						else
						{
							printf("Error, en la carga de datos.\n");
						}
						break;

					case 2:
						//BAJA EMPLEADO
						if(!arrayIsEmpty(arrayEmployees, MAX_EMPLOYEE))
						{
							printEmployees(arrayEmployees, MAX_EMPLOYEE);

							getInt(&auxID, "Ingrese la id del empleado a borrar: ", "Error, vuelva a intentarlo: ", 1, 1000);

							valueReturnRemove = removeEmployee(arrayEmployees, MAX_EMPLOYEE, auxID);

							if(valueReturnRemove == 0)
							{
								printf("Empleado borrado con exito.\n");
							}
							else if(valueReturnRemove == 1)
							{
								printf("El usuario ha cancelado el borrado.\n");
							}
							else
							{
								printf("Error en el borrado del empleado.\n");
							}
						}
						else
						{
							printf("No hay empleados que borrar.\n");
						}
						break;

					case 3:
						//MOD EMPLEADO
						if(!arrayIsEmpty(arrayEmployees, MAX_EMPLOYEE))
						{
							printEmployees(arrayEmployees, MAX_EMPLOYEE);

							getInt(&auxID, "Ingrese la id del empleado a modificar: ", "Error, vuelva a intentarlo: ", 1, 1000);

							valueReturnMod = modifyMenu(arrayEmployees, MAX_EMPLOYEE, auxID);

							if(valueReturnMod == 0)
							{
								printf("Empleado modificado con exito.\n");
							}
							else if(valueReturnMod == 1)
							{
								printf("El usuario cancelo la modificacion.\n");
							}
							else
							{
								printf("Error al modificar al empleado.\n");
							}

						}
						else
						{
							printf("No hay empleados para modificar.\n");
						}
						break;

					case 4:
						//LISTAR EMPLEADO
						if(!arrayIsEmpty(arrayEmployees, MAX_EMPLOYEE))
						{
							if(printMenu(arrayEmployees, MAX_EMPLOYEE))
							{
								printf("Informes mostrados con exitos.\n");
							}
							else
							{
								printf("Error, al mostrar los infomres.\n");
							}
						}
						else
						{
							printf("No hay empleados para mostrar.\n");
						}
						break;

					case 5:
						printf("Saliendo del menu de empleados.\n");
						//SALIR
						break;

					default:
						printf("Error, ha ingresado un valor invalido.\n");
				}
			}

		}while(option != 5);
	}
	else
	{
		printf("Error al inicializar el array.\n");
	}

	return EXIT_SUCCESS;
}
