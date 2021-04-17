/*
 * calculadora.h
 *
 *  Created on: 2 abr. 2021
 *      Author: Nicolas
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/**
* \brief Funcion que realiza la operacion de la suma
* \param pResult Puntero. Sera donde se guarde el resultado obtenido.
* \param num1. Flotante. Primer operando.
* \param num2. Flotante. Segundo operando.
* \return Devuelve -1 si error, 0 si OK.
*
*/
float suma(float* pResult, float num1, float num2);

/**
* \brief Funcion que realiza la operacion de la resta
* \param pResult Puntero. Sera donde se guarde el resultado obtenido.
* \param num1. Flotante. Primer operando.
* \param num2. Flotante. Segundo operando.
* \return Devuelve -1 si error, 0 si OK.
*
*/
float resta(float* pResult, float num1, float num2);

/**
* \brief Funcion que realiza la operacion de la multiplicacion.
* \param pResult Puntero. Sera donde se guarde el resultado obtenido.
* \param num1. Flotante. Primer operando.
* \param num2. Flotante. Segundo operando.
* \return Devuelve -1 si error, 0 si OK.
*
*/
float multiplicacion(float* pResult, float num1, float num2);

/**
* \brief Funcion que realiza la operacion de la division.
* \param pResult Puntero. Sera donde se guarde el resultado obtenido.
* \param num1. Flotante. Primer operando.
* \param num2. Flotante. Segundo operando.
* \return Devuelve -1 si error, 0 si OK, 1 si segundo operando es igual a 0.
*
*/
float division(float* pResult, float num1, float num2);

/**
* \brief Funcion que realiza la operacion del factorial
* \param pResult Puntero. Sera donde se guarde el resultado obtenido.
* \param num1. Flotante. Primer operando.
* \return Devuelve -1 si error, 0 si OK.
*
*/
int factorial(unsigned long int* pResult, int num1);

//////////////////////////////////////////////////////////////////////////////

/**
* \brief Funcion que muestra los resultados obtenidos.
* \param ResultSum Flotante. Almacena el resultado de la suma.
* \param ResultSub Flotante. Almacena el resultado de la resta.
* \param ResultMult Flotante. Almacena el resultado de la multiplicacion.
* \param ResultDiv Flotante. Almacena el resultado de la division.
* \param ResultFact1 Unsigned Long Int. Almacena el resultado del factorial del primer numero.
* \param ResultFact2 Unsigned Long Int. Almacena el resultado del factorial del segundo numero.
* \param num1 Flotante. El primer operando.
* \param num2 Flotante. El segundo operando.
* \param valueReturnSum Entero. el valor de retorno de la funcion suma. Funciona como un flag.
* \param valueReturnSub Entero. el valor de retorno de la funcion resta. Funciona como un flag.
* \param valueReturnMulti Entero. el valor de retorno de la funcion multiplicacion. Funciona como un flag.
* \param valueReturnDiv Entero. el valor de retorno de la funcion division. Funciona como un flag.
* \param valueReturnFact1 Entero. el valor de retorno de la funcion del factorial del primer operando. Funciona como un flag.
* \param valueReturnFact2 Entero. el valor de retorno de la funcion del factorial del segundo operando. Funciona como un flag.
*
*/
void mostrarResultados(float ResultSum, float ResultSub, float ResultMult, float ResultDiv, unsigned long int ResultFact1, unsigned long int ResultFact2,
		float num1, float num2, int valueReturnSum, int valueReturnSub, int valueReturnMulti, int valueReturnDiv, int valueReturnFact1, int valueReturnFact2);

#endif /* CALCULADORA_H_ */
