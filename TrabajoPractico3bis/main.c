#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
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

int main()
{
	setbuf(stdout,NULL);

	LinkedList* listaEmpleados = ll_newLinkedList();

	int ID = 0;
    int input;

    if(listaEmpleados != NULL)
    {
    	do
    	{
    		if(!optionsMenu(&input))
    		{
    			switch(input)
    			{
    				case 1:
    					//CARGAR DATOS DE DATA.CSV EN COMO TEXTO
    					if(ll_isEmpty(listaEmpleados))
    					{
    						if(!controller_loadFromText("data.csv", listaEmpleados, &ID))
    						{
    							printf("\nEl archivo 'data.csv' como texto ha sido cargado con exito.\n");
    						}
    						else
    						{
    							printf("\nError en la carga del archivo como texto.\n");
    						}
    					}
    					else
    					{
    						printf("\nLa lista ya ha sido cargada.\n");
    					}
    					break;

    				case 2:
    					//CARGA DE DATOS DE DATA2.CSV EN MODO BINARIO
    					if(ll_isEmpty(listaEmpleados))
    					{
    						if(!controller_loadFromBinary("data2.csv", listaEmpleados, &ID))
    						{
    							printf("\nEl archivo 'data2.csv' como binario a sido cargado con exito.\n");
    						}
    						else
    						{
    							printf("\nError en la carga del archivo como binario.\n");
    						}
    					}
    					else
    					{
    						printf("\nLa lista ya ha sido cargada.\n");
    					}
    					break;

    				case 3:
    					//ALTA DE EMPLEADOS
    					if(!ll_isEmpty(listaEmpleados))
    					{
    						if(!controller_addEmployee(listaEmpleados, &ID))
    						{
    							printf("\nEmpleado cargado con exito.\n");
    						}
    						else
    						{
    							printf("\nError en la carga de un empleado.\n");
    						}
    					}
    					else
    					{
    						printf("\nError. Carge la lista para poder agregar un empleado.\n");
    					}
    					break;

    				case 4:
    					//MODIFICAR EMPLEADO
    					if(!ll_isEmpty(listaEmpleados))
    					{
    						if(!controller_editEmployee(listaEmpleados))
    						{
    							printf("\nEmpleado modificado con exito.\n");
    						}
    						else
    						{
    							printf("\nError en la modificacion de un empleado.\n");
    						}
    					}
    					else
    					{
    						printf("\nError. Carge la lista para poder modificar empleados.\n");
    					}
    					break;

    				case 5:
    					//BAJA EMPLEADO
    					if(!ll_isEmpty(listaEmpleados))
    					{
    						if(!controller_removeEmployee(listaEmpleados))
    						{
    							printf("\nEmpleado eliminado con exito.\n");
    						}
    						else
    						{
    							printf("\nError en la eliminacion del empleado.\n");
    						}
    					}
    					else
    					{
    						printf("\nError. Carge la lista para poder eliminar empleados.\n");
    					}
    					break;

    				case 6:
    					//LISTAR EMPLEADO
    					if(!ll_isEmpty(listaEmpleados))
    					{
    						if(!controller_ListEmployee(listaEmpleados))
    						{
    							printf("\nLista de empleados mostrada con exito.\n");
    						}
    						else
    						{
    							printf("\nHa ocurrido un error al mostrar la lista de emplados.\n");
    						}
    					}
    					else
    					{
    						printf("\nError. Carge la lista de empleados para poder mostrar la lista.\n");
    					}
    					break;

    				case 7:
    					//ORDENAR EMPLEADO
    					if(!ll_isEmpty(listaEmpleados))
    					{
    						if(!controller_sortEmployee(listaEmpleados))
    						{
    							printf("\nOrdenamiento de empleados realizado con exito.\n");
    						}
    						else
    						{
    							printf("\nHa ourrrido un error al ordenar los empleados.\n");
    						}
    					}
    					else
    					{
    						printf("\nError. Carge la lista para poder ordenar a los empleados.\n");
    					}
    					break;

    				case 8:
    					//GUARDAR LOS DATOS EN DATA.CSV COMO TEXTO
    					if(!ll_isEmpty(listaEmpleados))
    					{
    						if(!controller_saveAsText("data.csv", listaEmpleados))
    						{
    							printf("\nLos datos han sido guardado en el archivo 'data.csv' como texto con exito.\n");
    						}
    						else
    						{
    							printf("\nHa ocurrido un error al guardar los datos como texto en el archivo 'data.csv'.\n");
    						}
    					}
    					else
    					{
    						printf("\nError. Carge la lista para poder guardar cualquier cambio como texto.\n");
    					}
    					break;

    				case 9:
    					//GUARDAR LOS DATOS EN DATA2.CSV COMO BINARIO
    					if(!ll_isEmpty(listaEmpleados))
    					{
    						if(!controller_saveAsBinary("data2.csv", listaEmpleados))
    						{
    							printf("\nLos datos han sido guardado en el archivo 'data2.csv' como binario con exito.\n");
    						}
    						else
    						{
    							printf("\nHa occurrido un error al guardar los datos como binario en el archivo 'data2.csv'.\n");
    						}
    					}
    					else
    					{
    						printf("\nError. Carge la lista para poder guardar cualquier cambio como binario.\n");
    					}
    					break;

    				case 10:
    					//SALIR DEL MENU DE OPCIONES
    					printf("\nSaliendo del menu de opciones...\n");
    					break;

    				default:
    					//ERROR. VALOR INVALIDO INGRESADO.
    					printf("\nError. Ha ingresado un valor invalido.\n");
    					break;

    			}
    		}

    		printf("\n");
    		//clearScreen();

    		system("pause");
    		system("cls");

    	}while(input != 10);
    }
    else
    {
    	printf("Ha ocurrido un error al crear una LinkedList.\n");
    }

    return 0;
}
