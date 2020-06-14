#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rta = 0,cont=0;
	int flag = 0;

	char buffer[4][2000];
	Employee* emp;
	//AGREGAR VALIDACION !=NULL
	while(!feof(pFile))
	{
    cont=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
	if(4 == cont)
	{
	    if(!flag)
        {
        flag =1 ;
        }else{
            emp = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(emp != NULL)
            {
                if(!ll_add(pArrayListEmployee,emp))
                {
                rta=1;
                }else
                    {
                    rta=0;
                    break;
                    }
            }

            }
	}

	}

    return rta;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rta = 0;
	int flag = 0;
	Employee* emp = employee_new();
	do
	{
    fread(emp,sizeof(Employee),1,pFile);
	    if(!flag)
        {
        flag = 1;
        }else{
                if(emp != NULL)
                {
                if(!ll_add(pArrayListEmployee,emp))
                {
                rta=1;
                }else
                    {
                    rta=0;
                    break;
                    }
                }
            }
	}while(!feof(pFile));
    return rta;
}
