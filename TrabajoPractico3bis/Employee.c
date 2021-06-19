#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "input.h"

Employee* employee_new()
{
	Employee* this;

	this = (Employee*) malloc(sizeof(Employee));

	return this;
}

Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, float sueldo)
{
	Employee* this = NULL;

	if(nombre != NULL)
	{
		this = employee_new();

		if(this != NULL)
		{
			if(employee_setId(this, id) || employee_setNombre(this, nombre) ||
				employee_setHorasTrabajadas(this, horasTrabajadas) || employee_setSueldo(this, sueldo))
			{
				employee_delete(this);
				this = NULL;
			}
		}
	}

	return this;
}

Employee* employee_newParametrosAsText(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = NULL;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		this = employee_new();

		if(this != NULL)
		{
			if(employee_setIdTxt(this, idStr) || employee_setNombre(this, nombreStr) ||
				employee_setHorasTrabajadasTxt(this, horasTrabajadasStr) || employee_setSueldoTxt(this, sueldoStr))
			{
				employee_delete(this);
				this = NULL;
			}
		}
	}

	return this;
}

int employee_delete(Employee* this)
{
	int toReturn = -1;

	if(this != NULL)
	{
		free(this);

		toReturn = 0;
	}

	return toReturn;
}

////////////////////////////////////////////////////////////////////////////////////////

// Seters & Geters de ID

int employee_setId(Employee* this, int id)
{
	int toReturn = -1;

	if(this != NULL)
	{
		if(id > 0)
		{
			this->id = id;
			toReturn = 0;
		}
	}

	return toReturn;
}

int employee_getId(Employee* this, int* id)
{
	int toReturn = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;

		toReturn = 0;
	}

	return toReturn;
}

int employee_setIdTxt(Employee* this, char* id)
{
	int toReturn = -1;

	int auxID;

	if(this != NULL && id != NULL && isNumInt(id, BUFFER_LEN) == 1)
	{
		auxID = atoi(id);

		if(auxID > 0)
		{
			this->id = auxID;

			toReturn = 0;
		}
	}

	return toReturn;
}

int employee_getIdTxt(Employee* this, char* id)
{
	int toReturn = -1;

	if(this != NULL && id != NULL)
	{
		snprintf(id, BUFFER_LEN, "%d", this->id);
		//printf("\n\n%s\n\n", id);

		toReturn = 0;
	}

	return toReturn;
}

// Seters & Geters de Nombre

int employee_setNombre(Employee* this, char* nombre)
{
	int toReturn = -1;

	if(this != NULL && nombre != NULL && isStringAlphabetical(nombre, NAME_LEN))
	{
		strncpy(this->nombre, nombre, NAME_LEN);

		toReturn = 0;
	}

	return toReturn;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int toReturn = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, NAME_LEN);

		toReturn = 0;
	}

	return toReturn;
}

//Seters & Geters de Horas Trabajadas

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int toReturn = -1;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;

		toReturn = 0;
	}

	return toReturn;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int toReturn = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;

		toReturn = 0;
	}

	return toReturn;
}

int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
	int toReturn = -1;

	int auxHorasTrabajadas;

	if(this != NULL && horasTrabajadas != NULL)
	{
		if(isNumInt(horasTrabajadas, BUFFER_LEN) == 1)
		{
			auxHorasTrabajadas = atoi(horasTrabajadas);

			if(auxHorasTrabajadas > 40)
			{
				this->horasTrabajadas = auxHorasTrabajadas;

				toReturn = 0;
			}
		}
	}

	return toReturn;
}

int employee_getHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
	int toReturn = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		snprintf(horasTrabajadas, BUFFER_LEN, "%d", this->horasTrabajadas);

		toReturn = 0;
	}

	return toReturn;
}

//Seters & Geters de Sueldo

int employee_setSueldo(Employee* this, float sueldo)
{
	int toReturn = -1;

	if(this != NULL)
	{
		if(sueldo >= 1000 && sueldo < 1000000)
		{
			this->sueldo = sueldo;

			toReturn = 0;
		}
	}

	return toReturn;
}

int employee_getSueldo(Employee* this, float* sueldo)
{
	int toReturn = -1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;

		toReturn = 0;
	}

	return toReturn;
}

int employee_setSueldoTxt(Employee* this, char* sueldo)
{
	int toReturn = -1;

	float auxSueldo;

	if(this != NULL && sueldo != NULL)
	{
		if(isNumFloat(sueldo, BUFFER_LEN) == 1)
		{
			auxSueldo = atof(sueldo);

			if(auxSueldo >= 1000 && *sueldo < 1000000)
			{
				this->sueldo = auxSueldo;
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

int employee_getSueldoTxt(Employee* this, char* sueldo)
{
	int toReturn = -1;

	if(this != NULL && sueldo != NULL)
	{
		snprintf(sueldo, BUFFER_LEN, "%.2f", this->sueldo);

		toReturn = 0;
	}

	return toReturn;
}

////////////////////////////////////////////////////////////////////////////////////////

int findEmployeeByID(LinkedList* pArrayListEmployee, int ID, int* index)
{
	int toReturn = -1;

	int i;
	int len;
	int auxID;

	Employee* this;

	if(pArrayListEmployee != NULL && index != NULL)
	{
		len = ll_len(pArrayListEmployee);

		if(len > 0)
		{
			for(i = 0; i < len; i++)
			{
				this = (Employee*) ll_get(pArrayListEmployee, i);

				if(this != NULL && !employee_getId(this, &auxID))
				{
					if(auxID == ID)
					{
						*index = i;

						toReturn = 0;
						break;
					}
				}
			}
		}
	}

	return toReturn;
}

int employee_compareByID(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	int auxID1;
	int auxID2;

	Employee* pEmployee1;
	Employee* pEmployee2;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pEmployee1 = (Employee*) pElement1;
		pEmployee2 = (Employee*) pElement2;

		if(!employee_getId(pEmployee1, &auxID1) && !employee_getId(pEmployee2, &auxID2))
		{
			if(auxID1 > auxID2)
			{
				//El Primer ID es mayor al segundo ID.
				toReturn = 1;
			}
			else if(auxID1 == auxID2)
			{
				//LOS IDs son iguales.
				toReturn = 0;
			}
			else
			{
				//El primer ID es menor al segundo ID.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int employee_compareByName(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	char auxName1[NAME_LEN];
	char auxName2[NAME_LEN];

	int auxComp;

	Employee* pEmployee1;
	Employee* pEmployee2;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pEmployee1 = (Employee*) pElement1;
		pEmployee2 = (Employee*) pElement2;

		if(!employee_getNombre(pEmployee1, auxName1) && !employee_getNombre(pEmployee2, auxName2))
		{
			auxComp = strncmp(auxName1, auxName2, NAME_LEN);

			if(auxComp > 0)
			{
				//El primer  nombre es mayor al segundo nombre.
				toReturn = 1;
			}
			else if(auxComp == 0)
			{
				//Los nombres son iguales.
				toReturn = 0;
			}
			else
			{
				//El primer nombre es menos al segundo
				toReturn = -1;
			}

		}
	}

	return toReturn;
}

int employee_compareByHorasTrabajadas(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	int auxHorasTrabajadas1;
	int auxHorasTrabajadas2;

	Employee* pEmployee1;
	Employee* pEmployee2;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pEmployee1 = (Employee*) pElement1;
		pEmployee2 = (Employee*) pElement2;

		if(!employee_getHorasTrabajadas(pEmployee1, &auxHorasTrabajadas1) && !employee_getHorasTrabajadas(pEmployee2, &auxHorasTrabajadas2))
		{
			if(auxHorasTrabajadas1 > auxHorasTrabajadas2)
			{
				//Las horas trabajadas del primer empleado son mayores al segundo.
				toReturn = 1;
			}
			else if(auxHorasTrabajadas1 == auxHorasTrabajadas2)
			{
				//Las horas trabajadas son iguales.
				toReturn = 0;
			}
			else
			{
				//Las horas trabajadas por el primer empleado son menor al segundo.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

int employee_compareBySueldo(void* pElement1, void* pElement2)
{
	int toReturn = -2;

	float auxSueldo1;
	float auxSueldo2;

	Employee* pEmployee1;
	Employee* pEmployee2;

	if(pElement1 != NULL && pElement2 != NULL)
	{
		pEmployee1 = (Employee*) pElement1;
		pEmployee2 = (Employee*) pElement2;

		if(!employee_getSueldo(pEmployee1, &auxSueldo1) && !employee_getSueldo(pEmployee2, &auxSueldo2))
		{
			if(auxSueldo1 > auxSueldo2)
			{
				//El sueldo del primer empleado es mayor al segundo.
				toReturn = 1;
			}
			else if(auxSueldo1 == auxSueldo2)
			{
				//Los sueldos son iguales.
				toReturn = 0;
			}
			else
			{
				//El sueldo del primer empleado es menor al sueldo del segundo.
				toReturn = -1;
			}
		}
	}

	return toReturn;
}

////////////////////////////////////////////////////////////////////////////////////////

int showModMenu(LinkedList* pArrayListEmployee, Employee* this)
{
	int toReturn = -1;

	char auxNombre[NAME_LEN];
	int auxHorasTrabajadas;
	float auxSueldo;

	int option;

	int flag1 = 0;

	if(pArrayListEmployee != NULL && this != NULL)
	{
		do
		{
			modMenu(&option);

			switch(option)
			{
				case 1:
					//MODIFICAR EL NOMBRE.
					if(!getString(auxNombre, "Ingrese el nuevo nombre del empleado: ", "Error, vuelva a intenarlo: ", 3, NAME_LEN)
					&& !employee_setNombre(this, auxNombre))
					{
						flag1 = 1;
					}
					break;

				case 2:
					//MODIFICAR LAS HORAS TRABAJADAS.
					if(!getInt(&auxHorasTrabajadas, "Ingrese las nuevas horas trabajadas del empleado entre 40 y 400: ",
					   "Error, solo entre 40 y 400. Vuelva a intentarlo: ", 40, 400) && !employee_setHorasTrabajadas(this, auxHorasTrabajadas))
					{
						flag1 = 1;
					}
					break;

				case 3:
					//MODIFICAR EL SUELDO.
					if(!getFloat(&auxSueldo, "Ingrese el nuevo sueldo del empleado entre 1000 y 1 000 000: ", "Error, solo entre 1000 y 1 000 000", 1000, 1000000)
					&& !employee_setSueldo(this, auxSueldo))
					{
						flag1 = 1;
					}
					break;

				case 4:
					printf("\nSaliendo del menu de opciones...\n");
					break;

				default:
					printf("Error, ha ingresado un valor invalido.");
					break;
			}

		}while(option != 4);

		if(flag1 == 1)
		{
			//MODIFICACION REALIZADA CON EXITO
			toReturn = 0;
		}

	}

	return toReturn;
}

int showSortMenu(LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	int option;
	int orderOption;
	int order;

	int (*pFunc)(void*, void*);

	if(pArrayListEmployee != NULL)
	{
		do
		{
			sortMenu(&option);

			switch(option)
			{
				case 1:
					//COMPARAR POR ID
					pFunc = employee_compareByID;
					break;

				case 2:
					//COMPARAR POR NOMBRE
					pFunc = employee_compareByName;
					break;

				case 3:
					//COMPARAR POR HORAS TRABAJADAS
					pFunc = employee_compareByHorasTrabajadas;
					break;

				case 4:
					//COMPARAR POR SUELDO
					pFunc = employee_compareBySueldo;
					break;

				default:
					printf("Error, ha ingresado un valor invalido.\n");
					break;
			}

		}while(option < 1 || option > 5);

		do
		{
			sortOrderMenu(&orderOption);

			switch(orderOption)
			{
				case 1:
					order = 0;
					break;

				case 2:
					order = 1;
					break;

				default:
					printf("Error, ha ingresado un valor invalido.\n");
					break;
			}

			}while(orderOption != 1 && orderOption != 2);

			ll_sort(pArrayListEmployee, pFunc, order);

			toReturn = 0;
	}

	return toReturn;
}



////////////////////////////////////////////////////////////////////////////////////////

int employee_add(LinkedList* pArrayListEmployee, int* ID)
{
	int toReturn = -1;

	char auxNombre[NAME_LEN];
	int auxHorasTrabajadas;
	float auxSueldo;

	Employee* this;

	if(pArrayListEmployee != NULL && ID != NULL)
	{
		printf("\n");

		if(!getString(auxNombre, "Ingrese el nombre: ", "Error, vuelva a intentarlo: ", 3, NAME_LEN))
		{
			if(!getInt(&auxHorasTrabajadas, "Ingrese las horas trabajadas entre 40 y 400: ", "Error, solo entre 40 y 400. Vuelva a intentarlo: ", 40, 400))
			{
				if(!getFloat(&auxSueldo, "Ingrese el sueldo entre 1000 y 1 000 000: ", "Error, solo entre 1000 y 1 000 000. Vuelva a intentarlo: ", 1000, 1000000))
				{
					this = employee_newParametros(*ID + 1, auxNombre, auxHorasTrabajadas, auxSueldo);

					if(this != NULL)
					{
						(*ID)++;

						ll_add(pArrayListEmployee, this);

						toReturn = 0;

					}
				}
			}
		}
	}

	return toReturn;
}

int employee_edit(LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	int auxID;
	int answer;
	int index;

	Employee* this;


	if(pArrayListEmployee != NULL)
	{
		if(!controller_ListEmployee(pArrayListEmployee))
		{
			if(!getInt(&auxID, "\nIngrese la ID del empleado a modificar entre 1 y 2000: ", "Error, solo entre 1 y 2000", 1, 2000))
			{
				if(!findEmployeeByID(pArrayListEmployee, auxID, &index))
				{
					this = (Employee*) ll_get(pArrayListEmployee, index);

					if(this != NULL)
					{
						printf("\nID\tNombre\t\t\tHoras Trabajadas\tSueldo\n\n");
						employee_printAnEmployee(this);

						if(!getInt(&answer, "\nEsta seguro que desea modificar este empleado (1: Si/2: No): ", "Error, solo 1 (Si) o 2 (No):", 1, 2))
						{
							if(!showModMenu(pArrayListEmployee, this))
							{
								toReturn = 0;
							}
						}
					}
				}
			}
		}
	}

	return toReturn;
}

int employee_remove(LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	int auxID;
	int answer;
	int index;

	Employee* this;

	if(pArrayListEmployee != NULL)
	{
		if(!controller_ListEmployee(pArrayListEmployee))
		{
			if(!getInt(&auxID, "\nIngrese el ID del empleado a elimianr entre 1 y 2000: ", "Error, solo entre 1 y 2000. Vuelva a intentarlo: ", 1, 2000))
			{
				if(!findEmployeeByID(pArrayListEmployee, auxID, &index))
				{
					this = (Employee*) ll_get(pArrayListEmployee, index);

					if(this != NULL)
					{
						printf("\nID\tNombre\t\t\tHoras Trabajadas\tSueldo\n\n");
						employee_printAnEmployee(this);

						if(!getInt(&answer, "\nEsta seguro de eliminar a este empleado (1: Si/2: NO): ", "Error, solo 1 (Si) o 2 (No): ", 1, 2))
						{
							employee_delete(this);
							ll_remove(pArrayListEmployee, index);

							toReturn = 0;
						}
					}
				}
			}
		}
	}

	return toReturn;
}

int employee_sort(LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	//FALTA FUNCION MOSTRAR MENU DE ORDENAMIENTO

	return toReturn;
}

int employee_clear(LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	int i;
	int len;

	Employee* this;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		if(len > 0)
		{
			for(i = 0; i < len; i++)
			{
				this = (Employee*) ll_get(pArrayListEmployee, i);

				if(this != NULL)
				{
					employee_delete(this);
				}
				else
				{
					break;
				}
			}

			if(i == len)
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}

int employee_printAnEmployee(Employee* this)
{
	int toReturn = -1;

	int auxID;
	char auxNombre[NAME_LEN];
	int auxHorasTrabajadas;
	float auxSueldo;

	if(this != NULL)
	{
		if(!employee_getId(this, &auxID))
		{
			if(!employee_getNombre(this, auxNombre))
			{
				if(!employee_getHorasTrabajadas(this, &auxHorasTrabajadas))
				{
					if(!employee_getSueldo(this, &auxSueldo))
					{
						printf("%d\t%-8s\t\t%-d\t\t\t%.2f\n", auxID, auxNombre, auxHorasTrabajadas, auxSueldo);

						toReturn = 0;
					}
				}
			}
		}
	}

	return toReturn;
}

int employee_list(LinkedList* pArrayListEmployee)
{
	int toReturn = -1;

	int i;
	int len;

	Employee* this;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		if(len > 0)
		{
			printf("\n");
			printf("Listado de Empleados\n\n");
			printf("ID\tNombre\t\t\tHoras Trabajadas\tSueldo\n\n");

			for(i = 0; i < len; i++)
			{
				this = (Employee*) ll_get(pArrayListEmployee, i);

				if(employee_printAnEmployee(this))
				{
					break;
				}
			}

			if(i == len)
			{
				toReturn = 0;
			}
		}
	}

	return toReturn;
}


