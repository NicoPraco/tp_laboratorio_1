


#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#define BUFFER_LEN 100
#define NAME_LEN 128

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[NAME_LEN]; //SI O SI DEBE USAR EL NAME_LEN. SI USA BUFFER_LEN NO GUARDA EL ID.
    int horasTrabajadas;
    float sueldo;

}Employee;

Employee* employee_new();
Employee* employee_newParametros(int id, char* nombre, int horasTrabajadas, float sueldo);
Employee* employee_newParametrosAsText(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
int employee_delete(Employee* this);

//////////////////////////////////////////////////////////////////////////////

//Geters y Seters de ID
int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);
int employee_setIdTxt(Employee* this, char* id);
int employee_getIdTxt(Employee* this, char* id);

//Geters y Seters de Nombre
int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);

//Geters y Seters de HorasTrabajadas
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);
int employee_getHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);

//Geters y Seters de Sueldo
int employee_setSueldo(Employee* this, float sueldo);
int employee_getSueldo(Employee* this, float* sueldo);
int employee_setSueldoTxt(Employee* this, char* sueldo);
int employee_getSueldoTxt(Employee* this, char* sueldo);

//////////////////////////////////////////////////////////////////////////////

int findEmployeeByID(LinkedList* pArrayListEmployee, int ID, int* index);

int employee_compareByID(void* pElement1, void* pElement2);
int employee_compareByName(void* pElement1, void* pElement2);
int employee_compareByHorasTrabajadas(void* pElement1, void* pElement2);
int employee_compareBySueldo(void* pElement1, void* pElement2);

//////////////////////////////////////////////////////////////////////////////

int showModMenu(LinkedList* pArrayListEmployee, Employee* this);
int showSortMenu(LinkedList* pArrayListEmployee);

//////////////////////////////////////////////////////////////////////////////

int employee_add(LinkedList* pArrayListEmployee, int* ID);
int employee_edit(LinkedList* pArrayListEmployee);
int employee_remove(LinkedList* pArrayListEmployee);
int employee_sort(LinkedList* pArrayListEmployee);
int employee_clear(LinkedList* pArrayListEmployee);
int employee_printAnEmployee(Employee* this);
int employee_list(LinkedList* pArrayListEmployee);

//////////////////////////////////////////////////////////////////////////////

#endif // EMPLOYEE_H_INCLUDED
