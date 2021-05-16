/*
 ============================================================================
 Name        : trabajoPractico2bis.c
 Author      : Praconovo, Nicolas Javier
 Version     :
 Copyright   : -
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "arrayEmployee.h"

int main(void)
{
	setbuf(stdout,NULL);

    int option;

    //VERIFICADORES
    int value;

    int valueRemove;
    int valueModify;
    int valueSort;
    int valuePrint;

    int ID;

    sEmployee employeeList[ELEMENTS];

    initEmployees(employeeList, ELEMENTS);
    hardcodeEmployee(employeeList, ELEMENTS);

    do
    {
        value = optionsMenu(&option);


        if(value == 0)
        {
            printf("OPTIONS WORKS!\n");
        }
        else
        {
            printf("\a\aOPTIONS DO NOT WORKS!\n");
        }


        switch(option)
        {
            case 1:
                value = new_Employee(employeeList, ELEMENTS);

                if(value == 0)
                {
                    printf("NEW EMPLOYEE WORKS!\n");
                }
                else
                {
                    printf("\a\aNEWEMPLOYEES DO NOT WORKS!\n");
                }

            break;

            case 2:
                getInt(&ID, "Enter the ID to be searched: ", "Error, invalid ID. Please, try again: ", 1, 1000);

                valueRemove = removeEmployee(employeeList, ELEMENTS, ID);

                switch(valueRemove)
                {
                    case -1:
                        printf("The ID entered does not exist.\n");
                        break;

                    case 0:
                        printf("The employee has been removed successfully.\n");
                        break;

                    case 1:
                        printf("Remove Canceled.\n");
                        break;

                }
            break;

            case 3:
                getInt(&ID, "Enter the ID to be searched: ", "Error, invalid ID. Please, try again: ", 1, 1000);

                valueModify = modifyEmployee(employeeList, ELEMENTS, ID);

                switch(valueModify)
                {
                    case -1:
                        printf("The ID entered does not exist.\n");
                        break;

                    case 0:
                        printf("The employee has been modified successfully.\n");
                        break;

                    case 1:
                        printf("Modification Cancelled.\n");
                        break;

                }
            break;

            case 4:
                valueSort = chooseOrderOfSort(employeeList, ELEMENTS);

                switch(valueSort)
                {
                    case -1:
                        printf("\a\aAn error has occurred.\n");
                        break;

                    case 0:
                        printf("Employees has been sort successfully.\n");
                        break;
                }
            break;

            case 5:
                printMenu(&valuePrint);

                switch(valuePrint)
                {
                    case 1:
                    printf("\n ID   SURNAME       NAME         SALARY      SECTOR\n");
                    printEmployees(employeeList, ELEMENTS);
                    break;

                    case 2:
                    calculateAverageOfSalaries(employeeList, ELEMENTS);
                    break;

                    default:
                        if(valuePrint == 3)
                        {
                            printf("Leaving...\n");
                        }
                        else
                        {
                            printf("\a\aInvalid option. Please, enter a valid option.\n");
                        }
                }

            break;

            default:
                if(option == 6)
                {
                    printf("Leaving...\n");
                    break;
                }
                else
                {
                    printf("Invalid option. Please, enter a valid optiom.\n");
                    break;
                }
        }

        system("pause");
        system("cls");

    }while(option != 6);

	return EXIT_SUCCESS;
}
