#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Egil.h"

Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
Employee* auxEmp = employee_new();
	if(auxEmp!=NULL)
	{
	 if(employee_setId(auxEmp,atoi(idStr))
		&&employee_setNombre(auxEmp,nombreStr)
		&&employee_setHorasTrabajadas(auxEmp,atoi(horasTrabajadasStr))
		&&employee_setSueldo(auxEmp,atoi(sueldo))
	   )
		{
		}else
			{
		 	printf("Error en la carga de empleados.\n");
			}
	}
return auxEmp;
}

int employee_setId(Employee* this,int id)
{
	int rta = 0;
	if(id>0)
	{
	this->id=id;
	rta = 1;
	}
	return rta;
}

int employee_setNombre(Employee* this,char* nombre)
{
int rta = 0;
int tam = strlen(nombre);
	if( tam < 20  && tam > 1)
	{
	strcpy(this->nombre,nombre);
	rta = 1;
	}
return rta;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
int rta = 0;
	if(horasTrabajadas>0)
	{
	this->horasTrabajadas = horasTrabajadas;
	rta = 1;
	}
return rta;
}


int employee_setSueldo(Employee* this,int sueldo)
{
int rta = 0;

	if(sueldo>=10000)
	{
		this->sueldo=sueldo;
		rta=1;
	}

return rta;
}

int employee_getId(Employee* this,int* id)
{
	int rta = 0;

if (this!=NULL&& id!=NULL)
{
	*id=this->id;
	rta = 1;
}
return rta;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int rta=0;
if (this!=NULL && nombre!=NULL)
{
	strcpy(nombre,this->nombre);
	rta = 1;
}
	return rta;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int rta=0;
if (this!=NULL && horasTrabajadas!=NULL)
{
	*horasTrabajadas = this->horasTrabajadas;
	rta = 1;
}
	return rta;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int rta=0;
	{
	*sueldo=this->sueldo;
	rta = 1;
	}

	return rta;
}



void lastId(LinkedList* lista,char* id)
{
	int aux,flag=0;
	int tam = ll_len(lista);
	Employee* emp;

	for (int i = 0; i < tam; ++i)
	{
	    emp = (Employee*) ll_get (lista,i);
		if(aux < emp->id || flag==0)
		{
		aux=emp->id;
		flag=1;
		}
	}
	aux++;
	sprintf(id,"%d",aux);
}


