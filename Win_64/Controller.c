#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Employee.h"
#include "Egil.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int rta=0, cargado = ll_isEmpty(pArrayListEmployee);
	system("cls");
        FILE* f = fopen(path,"r");
        if(cargado)
        {
            if (f!=NULL&&path!=NULL)
            {
            if(parser_EmployeeFromText(f,pArrayListEmployee))
            {
    		rta=1;
            }
            fclose(f);
            }
        }else{
            printf("Hay datos cargados en la lista.\nPara volver a usar esta opcion debe guardar los cambios con la opcion 8 o 9.\n\n");
            rta = -1;
            }
    return rta;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	int rta=0, cargado = ll_isEmpty(pArrayListEmployee);
		system("cls");
    FILE* f = fopen(path,"rb");
	if(cargado)
    {
        if (f!=NULL&&path!=NULL)
        {
    	if(parser_EmployeeFromBinary(f,pArrayListEmployee))
    	{
    		rta=1;
    	}
    	fclose(f);
    	}
    }else
        {
        printf("Hay datos cargados en la lista.\nPara volver a usar esta opcion debe guardar los cambios con la opcion 8 o 9.\n\n");
        rta=-1;
        }
    return rta;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int rta = 0;
    char buffer[4][20];
    Employee* emp;

        printf("****Alta Empleado****\n\n");
    	lastId(pArrayListEmployee,buffer[0]);
        printf("Ingrese Nombre.\nMaximo de caracteres 20: ");
        fflush(stdin);
        scanf("%s",buffer[1]);
        printf("Ingrese cantidad de horas trabajadas.\nDeben ser mayores a 0: ");
        fflush(stdin);
        scanf("%s",buffer[2]);
        printf("Ingrese sueldo.\nDebe ser mayor a 10.000: ");
        fflush(stdin);
        scanf("%s",buffer[3]);

        emp = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
        if(emp!=NULL)
        {
            if(!ll_add(pArrayListEmployee,emp))
            {
            rta =1;
            }
        }

return rta;

}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int rta =0,id=0,horas,sueldo;
    char nombre[20],salir='n',confirmar = 'n';
    Employee* auxEmp;
    system("cls");
		do
		{
		    system("cls");
		    switch(menuModificar())
		    {
		    	case 1:
		    		controller_ListEmployees(pArrayListEmployee);
		    		system("pause");
		    		break;
		    	case 2:
                system("cls");
		    	if(getInt(&id,1,1,2000,"Ingrese numero de Id ",""))
		    	{
		    	    system("cls");
		    		if((auxEmp=ll_get(pArrayListEmployee,id-1))!=NULL)
		    		{
                    printf("Id     Nombre    Horas Trabajadas    Sueldo\n\n");
                    controller_ListEmployee(auxEmp);
                        getChar(&confirmar,1,1,'s','n',"\nDesea seguir? S/N","");
                        if(confirmar=='s')
                        {
                        system("cls");
                        printf("Ingrese nuevo Nombre: ");
                        fflush(stdin);
                        scanf("%s",nombre);
                            if(employee_setNombre(auxEmp,nombre))
                            printf("Modificacion exitosa.\n");
                            else
                            printf("Error en la carga de nombre.");
                        }
                    }else
		    			printf("El Id ingresado es incorrecto.\n");
		    	}else
                    {
                    printf("El Id ingresado es incorrecto.\n");
		  			system("pause");
                    }
		    		break;
		    	case 3:
                system("cls");
		    	if(getInt(&id,1,1,2000,"Ingrese numero de Id ",""))
		    	{
		    	    system("cls");
		    		if((auxEmp=ll_get(pArrayListEmployee,id-1))!=NULL)
		    		{
                    printf("Id     Nombre    Horas Trabajadas    Sueldo\n\n");
                    controller_ListEmployee(auxEmp);
                        getChar(&confirmar,1,1,'s','n',"\nDesea seguir? S/N","");
                        if(confirmar=='s')
                        {
                        system("cls");
                        printf("Ingrese hora trabajadas: ");
                        fflush(stdin);
                        scanf("%d",&horas);
                            if(employee_setHorasTrabajadas(auxEmp,horas))
                            printf("Modificacion exitosa.\n");
                            else
                            printf("Error en la carga de nombre.");
                        }
                    }else
		    			printf("El Id ingresado es incorrecto.\n");
		    	}else
                    {
                    printf("El Id ingresado es incorrecto.\n");
		  			system("pause");
                    }

		    		break;
		    	case 4:
                system("cls");
		    	if(getInt(&id,1,1,2000,"Ingrese numero de Id ",""))
		    	{
		    	    system("cls");
		    		if((auxEmp=ll_get(pArrayListEmployee,id-1))!=NULL)
		    		{
                    printf("Id     Nombre    Horas Trabajadas    Sueldo\n\n");
                    controller_ListEmployee(auxEmp);
                    getChar(&confirmar,1,1,'s','n',"\nDesea seguir? S/N","");
                        if(confirmar=='s')
                        {
                        system("cls");
                        printf("Ingrese sueldo: ");
                        fflush(stdin);
                        scanf("%d",&sueldo);
                            if(employee_setSueldo(auxEmp,sueldo))
                            printf("Modificacion exitosa.\n");
                            else
                            printf("Error en la carga de nombre.");
                        }
                    }else
		    			printf("El Id ingresado es incorrecto.\n");
		    	}else
                    {
                    printf("El Id ingresado es incorrecto.\n");
		  			system("pause");
                    }
		  			break;
                case 5:
                getChar(&salir,1,1,'s','n',"Desea salir? s/n: ","");
                    break;
		    	default:
		    	printf("la opcion ingresada es invalida, vuelva a intentarlo.\n");
		    		break;
		    	}
        }while(salir!='s');
return rta;

}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
int rta = 0,op=0,id;
char salir='n',confirmar='n';
Employee* auxEmp;
system("cls");

    printf("****Baja Empleado****\n\n");

    do{
        system("cls");
        printf("****Ingrese la Opcion deseada****\n\n");
        getInt(&op,1,1,3,"1)Lista de empleados.\n2)Baja.\n3)Salir.\n\n","Error.\n1)Lista de empleados.\n2)Baja.\n3)Salir.\n\n");
        switch(op)
        {
        case 1:
            system("cls");
            printf("Id     Nombre    Horas Trabajadas    Sueldo\n\n");
            controller_ListEmployees(pArrayListEmployee);
            system("pause");
            break;
        case 2:
            system("cls");
             if(getInt(&id,1,1,2000,"Ingrese numero de Id ",""))
		    	{
		    	    system("cls");
		    		if((auxEmp=ll_get(pArrayListEmployee,id-1))!=NULL)
		    		{
                    printf("Id     Nombre    Horas Trabajadas    Sueldo\n\n");
                    controller_ListEmployee(auxEmp);
                        getChar(&confirmar,1,1,'s','n',"\nDesea realizar la baja S/N","");
                        if(confirmar=='s')
                        {
                        system("cls");
                        ll_remove(pArrayListEmployee,id-1);
                        printf("Baja exitosa.\n");
                        }else
                            if(confirmar=='n')
                            printf("Baja cancelada.");
                    }else
		    			printf("El Id ingresado es incorrecto.\n");
		    	}else
                    {
                    printf("El Id ingresado es incorrecto.\n");
		  			system("pause");
                    }
            break;
        case 3:
            getChar(&salir,1,1,'s','n',"Desea salir? s/n: ","");
            break;
        default:
            printf("La opcion ingresada es invalida.\n");
            break;
        }
    }while(salir!='s');


    return rta;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployees(LinkedList* pArrayListEmployee)
{
int rta=0,tam = ll_len(pArrayListEmployee), flag=0;
Employee* auxEmp;

if (pArrayListEmployee!=NULL)
{
	rta = 1;
	for (int i = 0; i < tam; ++i)
	{
	    auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
		if (auxEmp!=NULL)
		{
			if (!flag)
			{
				printf("Id                Nombre     Horas Trabajadas      Sueldo\n");
				flag=1;
			}
            if(!controller_ListEmployee(auxEmp))
                printf("Hubo un error al intentar cargar los datos del empleado.\n");
		}
	}
}
return rta;

}

int controller_ListEmployee(Employee* empleado)
{
int rta=0,auxId,auxHoras,auxSueldo;
char AuxNombre[20];


if(empleado!= NULL)
{
	if (employee_getId(empleado,&auxId)
        &&employee_getNombre(empleado,AuxNombre)
        &&employee_getHorasTrabajadas(empleado,&auxHoras)
        &&employee_getSueldo(empleado,&auxSueldo)
		)
	{
	printf("%4d     %15s     %7d     %15d\n",auxId,AuxNombre,auxHoras,auxSueldo);
    rta = 1;
	}
}

return rta;

}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
int rta = 0;

if(ll_sort(pArrayListEmployee,compararEmpleado,1)!=-1)
	rta = 1;

return rta;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int rta=0,tam=ll_len(pArrayListEmployee),auxId,auxHoras,auxSueldo;
    char AuxNombre[20];
    Employee* empleado;
    FILE* f = fopen(path,"w");
    if (f!=NULL&&path!=NULL)
    {
    fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
    for(int i =0;i<tam;i++)
    {
    empleado = (Employee*) ll_get(pArrayListEmployee,i);
    {
    if (employee_getId(empleado,&auxId)
        &&employee_getNombre(empleado,AuxNombre)
        &&employee_getHorasTrabajadas(empleado,&auxHoras)
        &&employee_getSueldo(empleado,&auxSueldo)
		)
		{
        fprintf(f,"%d,%s,%d,%d\n",auxId,AuxNombre,auxHoras,auxSueldo);
        rta=1;
		}else
            {
            rta = 0;
            break;
            }
    }

    }
    fclose(f);
    if(rta)
    {
    ll_deleteLinkedList(pArrayListEmployee);
    }
    }
    return rta;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */



//     	if (employee_getId(empleado,&auxId)
//        &&employee_getNombre(empleado,AuxNombre)
//        &&employee_getHorasTrabajadas(empleado,&auxHoras)
//        &&employee_getSueldo(empleado,&auxSueldo)
//		)
int controller_saveAsBinary(char* path ,LinkedList* pArrayListEmployee)
{
    int rta=0,tam=ll_len(pArrayListEmployee);
    char encabezado[35];
    Employee* empleado=NULL;
    FILE* f = fopen(path,"wb");
    if(f!=NULL&&path!=NULL)
    {
    for(int i = 0; i<tam ;i++)
    {
    empleado = (Employee*) ll_get(pArrayListEmployee,i);
    fwrite(empleado,sizeof(Employee),1,f);
        rta=1;
    }
    if(rta)
    {
    ll_deleteLinkedList(pArrayListEmployee);
    }
    fclose(f);
    }
    return rta;
}

int compararEmpleado(void* emp1,void* emp2)
{
	int rta;

	Employee* a = (Employee*)emp1;
	Employee* b = (Employee*)emp2;


	if (a->sueldo==b->sueldo)
	{
		rta = 0;
	}else
		if (a->sueldo>b->sueldo)
		{
			rta = 1;
		}else
			rta = -1;

	return rta;
}


int menuModificar(void)
{
    int op=0;
    printf("****Modificar Empleado*****\n");
    	printf("1)Lista De Empleados\n");
    	printf("2)Nombre\n");
    	printf("3)Horas Trabajadas\n");
    	printf("4)Sueldo\n");
    	printf("5)Salir\n");
    	getInt(&op,2,1,5,"Ingrese la Opcion deseada: ","Opcion, invalida\nIngrese la Opcion deseada: ");
    return op;

}
