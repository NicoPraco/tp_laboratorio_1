#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

void clearScreen()
{
	int i;
    for (i = 0; i < 1; i++)
    {
    	printf( "\n\n\n\n\n" );
    }
}

////////////////////////////////////////////////////////////////////////////////////

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int retorno = -1;
    int indice;
    int flagWhile = 0;

    char temp;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit < hiLimit)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }
            else
            {
                printf("%s \a\a", eMessage);
            }
            indice = scanf("%d%c", input, &temp);
            fflush(stdin);

        }while((indice != 2 || temp != '\n') || (*input < lowLimit || *input > hiLimit));

        retorno = 0;
    }

    return retorno;

}

////////////////////////////////////////////////////////////////////////////////////

int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int retorno = -1;
    int indice;
    int flagWhile = 0;

    char temp;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit < hiLimit)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }
            else
            {
                printf("%s \a\a", eMessage);
            }

            indice = scanf("%f%c", input, &temp);
            fflush(stdin);

        }while((indice != 2 || temp != '\n') || (*input < lowLimit || *input > hiLimit));

        retorno = 0;
    }

    return retorno;
}

////////////////////////////////////////////////////////////////////////////////////

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int retorno = -1;
    int flagWhile = 0;

    char temp;

    if(input != NULL && message != NULL && eMessage != NULL && lowLimit < hiLimit)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }
            else
            {
                printf("%s \a\a", eMessage);
            }
            scanf("%c%c", input, &temp);
            fflush(stdin);

        }while( (temp != '\n') || (*input < lowLimit || *input > hiLimit) );

        retorno = 0;
    }

    return retorno;
}

////////////////////////////////////////////////////////////////////////////////////

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
     int retorno = -1;
     int length;
     int flagWhile = 0;

     if(input != NULL && message != NULL && eMessage != NULL && lowLimit < hiLimit)
     {
         do
         {
             if(flagWhile == 0)
             {
                 printf("%s", message);

                 flagWhile = 1;
             }
             else
             {
                 printf("%s \a\a", eMessage);
             }
             fgets(input, hiLimit, stdin);
             length = strlen(input);

             if(input[length - 1] == '\n')
             {
                 input[length - 1] = '\0';
             }

             length = strlen(input);

         }while(length < lowLimit || length > hiLimit);

         retorno = 0;
     }

    return retorno;
}

////////////////////////////////////////////////////////////////////////////////////

int getIntNoVal(int* input, char message[])
{
	int toReturn = -1;
    int indice;
    int flagWhile = 0;

    char temp;

    if(input != NULL && message != NULL)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }

            indice = scanf("%d%c", input, &temp);
            fflush(stdin);

        }while((indice != 2 || temp != '\n'));

        toReturn = 0;
    }

	return toReturn;
}

////////////////////////////////////////////////////////////////////////////////////

int getFloatNoVal(float* input,char message[])
{
    int toReturn = -1;
    int indice;
    int flagWhile = 0;

    char temp;

    if(input != NULL && message != NULL)
    {
        do
        {
            if(flagWhile == 0)
            {
                printf("%s", message);

                flagWhile = 1;
            }

            indice = scanf("%f%c", input, &temp);
            fflush(stdin);

        }while((indice != 2 || temp != '\n'));

        toReturn = 0;
    }

    return toReturn;
}

////////////////////////////////////////////////////////////////////////////////////

int isNumFloat(char input[])
{
	int toReturn = -1;
	int i;

	int length;

	length = strlen(input);

	for(i = 0; i < length; i++)
	{
		if(input[i] == ',' || input[i] == '.')
		{
				//NUMERO CON COMA
				toReturn = 1;

		}
	}

	return toReturn;
}
