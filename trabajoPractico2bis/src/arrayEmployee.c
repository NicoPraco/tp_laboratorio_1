/*
 * arrayEmployee.c
 *
 *  Created on: 15 may. 2021
 *      Author: Nicolas
 */

#include "arrayEmployee.h"
#include "inputs/input.h"

int optionsMenu(int* option)
{
    int toReturn = -1;

    printf("Welcome, these are the available options: \n");
    printf("1. Add an Employee.\n");
    printf("2. Remove an Employee.\n");
    printf("3. Modify an Employee.\n");
    printf("4. Sort Employees\n");
    printf("5. Show Employees.\n");
    printf("6. Exit.\n");
    getInt(option, "Choose an option: ", "Error, option entered not valid. Please try again: ", 1, 6);

    toReturn = 0;

    return toReturn;
}

int printMenu(int* option)
{
    int toReturn = -1;

    printf("1. Print employees.\n");
    printf("2. Print employees witch are above average of salaries\n");
    printf("3. Exit.\n");
    getInt(option, "Choose an option: ", "Error, invalid option. Please trt again: ", 1, 3);

    return toReturn;
}

int sortMenu(int* option)
{
    int toReturn = -1;

    printf("1. Ascending order for the sort.\n");
    printf("2. Descending order for the sort.\n");
    printf("3. Exit.\n");
    getInt(option, "Choose an option; ", "Error, invalid option. Please try again: ", 1, 3);

    toReturn = 0;

    return toReturn;
}

int modifyMenu(int* option)
{
    int toReturn = -1;

    printf("1. Name.\n");
    printf("2. Surname.\n");
    printf("3. Salary.\n");
    printf("4. Sector.\n");
    printf("5. Exit.\n");
    getInt(option, "Choose an option to modify from the employee.", "Error, invalid option. Please try again: ", 1, 5);

    return toReturn;
}

int ID_AutoIncremental(sEmployee* list, int length)
{
    int id = 0;
    int i;

    if(list != NULL && length > 0)
    {
        for(i = 0; i < length; i++)
        {
            if(list[i].isEmpty == FALSE && list[i].id > id)
            {
                id = list[i].id;
            }
        }

        id++;
    }

    return id;
}

int hardcodeEmployee(sEmployee* list, int len)
{
    int i;
    int toReturn = -1;

    int id[5] = {1, 2, 3, 4, 5};
    int sector[5] = {1, 2, 1, 3, 5};

    float salary[5] = {10000, 25000, 15000, 50000, 50000};

    char name[5][51] = {"Nicolas", "Ramiro", "Santiago", "Daniela", "Maria"};
    char lastName[5][51] = {"Praconovo", "Quintana", "Leonardi", "Ibasca", "Perez"};

    if(len > 0 && list != NULL)
    {
        toReturn = 0;

        for(i = 0; i < len; i++)
        {
            list[i].id = id[i];
            list[i].sector = sector[i];

            list[i].salary = salary[i];

            strcpy(list[i].name, name[i]);
            strcpy(list[i].lastName, lastName[i]);

            list[i].isEmpty = TRUE;

            if(i == 4)
            {
                break;
            }
        }
    }

    return toReturn;

}

//------------------------------------------------------------------------------------------------------------

int initEmployees(sEmployee* list, int len)
{
    int toReturn = -1;
    int i;

    if(len > 0 && list != NULL)
    {
        for(i = 0; i < len; i++)
        {
            list[i].isEmpty = FALSE;

            toReturn = 0;
        }
    }

    return toReturn;
}

int addEmployee(sEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int toReturn = -1;
    int index;
    int i;

    if(len > 0 && list != NULL)
    {
        for(i = 0; i < len; i++)
        {
            index = searchFree(list, len);

            if(index != -1)
            {
               list[index].id = id;
               strcpy(list[index].name, name);
               strcpy(list[index].lastName, lastName);
               list[index].salary = salary;
               list[index].sector = sector;

               list[index].isEmpty = TRUE;

               toReturn = 0;

                break;
            }
        }
    }

    return toReturn;
}

int findEmployeeById(sEmployee* list, int len, int id)
{
    int toReturn = -1;
    int i;

    if(len > 0 && list != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == TRUE && list[i].id == id)
            {
                toReturn = i;
                break;
            }
        }
    }

    return toReturn;
}

int removeEmployee(sEmployee* list, int len, int id)
{
    int toReturn = -1;
    int index;

    int value;

    if(len > 0 && list != NULL)
    {
        index = findEmployeeById(list, ELEMENTS, id);

        printEmployeeByID(list, len, id);

        if(index != -1)
        {
            getInt(&value, "Are you sure that you want to remove this employee (YES (1) /NO (0)): ", "Error, invalid answer. Please try again: ", 0, 1);

            if(value == 1)
            {
                list[index].isEmpty = FALSE;

                toReturn = 0;
            }
            else
            {
                toReturn = 1;
            }
        }
    }

    return toReturn;
}

int sortEmployees(sEmployee* list, int len, int order)
{
    int toReturn = -1;
    int i;

    int flag;
    int value;

    sEmployee auxEmployee;

    if(len > 0 && list != NULL)
    {
        do
        {
            flag = 0;

            for(i = 0; i < len - 1; i++)
            {
                value = strncmp(list[i].lastName, list[i + 1].lastName, 51);

                if( (!list[i].isEmpty && order == 1 && (value > 0 || (value == 0 && list[i].sector > list[i + 1].sector))) ||
                    (!list[i + 1].isEmpty && order == 0 && (value < 0 || (value == 0 && list[i].sector < list[i + 1].sector))) )
                {
                    flag = 1;

                    auxEmployee = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = auxEmployee;
                }
            }

            len--;

        }while(flag);

        toReturn = 0;
    }

    return toReturn;
}

int modifyEmployee(sEmployee* list, int length, int id)
{
    int election;
    int toReturn = -1;
    int index;

    int value;

    if(length > 0 && list != NULL)
    {
        index = findEmployeeById(list, ELEMENTS, id);

        printEmployeeByID(list, length, id);

        if(index != -1)
        {
            modifyMenu(&election);

            switch(election)
            {
                case 1:
                    getInt(&value, "Are you sure you want to modify the name (YES (1)/ NO (0)): ", "Error invalid option. Please try again: ", 0, 1);

                    if(value == 1)
                    {
                        getString(list[index].name, "ºnEnter the new name: ", "\nError, the name entered is invalid. Please try again: ", 3, 50);
                        toReturn = 0;
                        break;
                    }
                    else
                    {
                        toReturn = 1;
                        break;
                    }

                case 2:
                    getInt(&value, "Are you sure you want to modify the surname (YES (1)/ NO (0)): ", "ºnError invalid option. Please try again: ", 0, 1);

                    if(value == 1)
                    {
                        getString(list[index].lastName, "\nEnter the new surname: ", "ºnError, the surname entered is invalid. Please try again: ", 3, 50);
                        toReturn = 0;
                        break;
                    }
                    else
                    {
                        toReturn = 1;
                        break;
                    }

                case 3:
                    getInt(&value, "Are you sure you want to modify the salary (YES (1)/ NO (0)): ", "Error invalid option. Please try again: ", 0, 1);

                    if(value == 1)
                    {
                        getFloat(&list[index].salary, "\nEnter the new salary: ", "\nError, the salary entered is invalid. Please try again: ", 1, 100000);
                        toReturn = 0;
                        break;
                    }
                    else
                    {
                        toReturn = 1;
                        break;
                    }

                case 4:
                    getInt(&value, "Are you sure you want to modify the sector (YES (1)/ NO (0)): ", "Error invalid option. Please try again: ", 0, 1);

                    if(value == 1)
                    {
                        printf("\nThe sectors are: \n");
                        printf("\n1. Human Resources Sector.");
                        printf("\n2. Customer Relationship Management.");
                        printf("\n3. Business Intelligence.");
                        printf("\n4. Supply Chain Management.");
                        printf("\n5. Inventory Management.");
                        printf("\n6. Financial Management");

                        getInt(&list[index].sector, "Enter the new sector: ", "Error, invalid sector. Please try again: ", 1, 6);
                        toReturn = 0;
                        break;
                    }
                    else
                    {
                        toReturn = 1;
                        break;
                    }

                default:
                    if(election == 5)
                    {
                        printf("Leaving...\n");
                    }
                    else
                    {
                        printf("\a\aThe option entered is not valid. Please enter a valid option.\n");
                    }
            }
        }
    }

    return toReturn;
}

int printEmployees(sEmployee* list, int length)
{
    int i;
    int toReturn = -1;

    if(length > 0 && list != NULL)
    {
        for(i = 0; i < length; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                printOneEmployee(list[i]);

                toReturn = 0;
            }
        }
    }

    return toReturn;
}

//------------------------------------------------------------------------------------------------------------

int searchFree(sEmployee* list, int len)
{
    int i;
    int toReturn = -1;

    if(len > 0 && list != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty != TRUE)
            {
                toReturn = i;
            }
        }
    }

    return toReturn;
}

int new_Employee(sEmployee* list, int length)
{
    sEmployee anEmployee;

    int toReturn = -1;

    anEmployee.id = ID_AutoIncremental(list, length);

    //Get Name
    getString(anEmployee.name, "Enter the employee's name: ", "Error, invalid name, please try again: ", 3, 50);

    //Get Surname
    getString(anEmployee.lastName, "Enter the employee's surname: ", "Error, invalid surname, please try again: ", 5, 50);

    //Get Salary
    getFloat(&anEmployee.salary, "Enter the employee's salary: ", "Error, invalid salary, please try again: ", 1000, 100000);

    //Get Sector
    printf("\nThe sectors are: \n");
    printf("\n1. Human Resources Sector.");
    printf("\n2. Customer Relationship Management.");
    printf("\n3. Business Intelligence.");
    printf("\n4. Supply Chain Management.");
    printf("\n5. Inventory Management.");
    printf("\n6. Financial Management");

    getInt(&anEmployee.sector, "\n\nEnter the employee's sector: ", "Error, invalid sector, please try again: ", 1, 6);

    addEmployee(list, length, anEmployee.id, anEmployee.name, anEmployee.lastName, anEmployee.salary, anEmployee.sector);

    toReturn = 0;

    return toReturn;
}

void printOneEmployee(sEmployee anEmployee)
{
    printf("%2d %10s, %10s %14.2f %8d\n", anEmployee.id, anEmployee.lastName, anEmployee.name, anEmployee.salary, anEmployee.sector);
}

int chooseOrderOfSort(sEmployee* list, int len)
{
    int toReturn = -1;
    int orderOption;
    int value;

    if(len > 0 && list != NULL)
    {
        value = sortMenu(&orderOption);

        if(value == 0)
        {
            switch(orderOption)
            {
                case 1:
                    sortEmployees(list, len, 1);

                    toReturn = 0;
                    break;

                case 2:
                    sortEmployees(list, len, 0);

                    toReturn = 0;
                    break;

                default:
                    if(orderOption == 3)
                    {
                        printf("Leaving...\n");
                    }
                    else
                    {
                        printf("\a\a\nInvalid option. Please try again.\n");
                    }
            }
        }
        else
        {
            printf("\a\a\nAn error has occurred. Please, try again. \n");
        }

    }


    return toReturn;
}

int calculateAverageOfSalaries(sEmployee* list, int len)
{
    int i;
    int toReturn = -1;
    int salaryCounter = 0;
    int employeeNumerator = 0;

    float salaryAcumulator = 0;
    float salaryAverage;

    if(len > 0 && list != NULL)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                salaryAcumulator = salaryAcumulator + list[i].salary;
                salaryCounter++;

                toReturn = 0;
            }
        }

        salaryAverage = (float)salaryAcumulator / salaryCounter;

        employeeNumerator = employeeCounter(list, len, salaryAverage);

        printAverageOfSalaries(employeeNumerator, salaryAverage, salaryAcumulator);

    }

    return toReturn;
}

int employeeCounter(sEmployee* list, int len, float salaryAverage)
{
    int i;
    int employeeNumerator = 0;

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == TRUE && list[i].salary > salaryAverage)
        {
            employeeNumerator++;
        }
    }

    return employeeNumerator;
}

void printAverageOfSalaries(int employeeCounter, float salaryAverage, float salaryAcumulator)
{
    printf("Total: %.2f \t Average: %.2f \t Employee with more than average: %d\n", salaryAcumulator, salaryAverage, employeeCounter);
}

void printEmployeeByID(sEmployee* list, int len, int ID)
{
    int i;

    if(len > 0 && list != NULL)
    {
        printf("\n ID   SURNAME       NAME         SALARY      SECTOR\n");

        for(i = 0; i < len; i++)
        {
            if(list[i].id == ID)
            {
                printf("%2d %10s, %10s %14.2f %8d\n\n", list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector);
                break;
            }
        }
    }
}
