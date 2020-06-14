#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Egil.h"

int menu (void);

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
    char salir ='n';
    int error;
    LinkedList* listaEmpleados = ll_newLinkedList();
            if(listaEmpleados!=NULL)
            {
    do{
        switch(menu())
        {
            case 1:
                error=controller_loadFromText("data.csv",listaEmpleados);
                if(error==1)
                {
                printf("Los empleados fueron cargados con exito.\n");
                }else if(error == 0)
                    {
                    printf("Hubo un error en la carga de datos.\n");
                    }else
                        printf("Se ha cancelado la carga de datos.\n");
            break;
            case 2:
                error=controller_loadFromBinary("data.csv",listaEmpleados);
                if(error==1)
                {
                printf("Los empleados fueron cargados con exito.\n");
                }else if(error==0)
                    {
                    printf("Hubo un error en la carga de datos.\n");
                    }else
                        printf("Se ha cancelado la carga de datos.\n");
                break;
            case 3:
                if(!ll_isEmpty(listaEmpleados))
                {
                    if (controller_addEmployee(listaEmpleados))
                    {
                    printf("Empleado cargado con exito.\n");
                    }
                    else
                        printf("Hubo un error al intentar cargar el nuevo empleado.\nVerifique los datos ingresados e intentelo denuevo.\n");
                }else
                    printf("Debe ingresar a la Opcion uno antes de realizar cualquier de las demas tareas.");
                break;
            case 4:
                if(!ll_isEmpty(listaEmpleados))
                {
                controller_editEmployee(listaEmpleados);
                }else
                   printf("Debe ingresar a la Opcion uno antes de realizar cualquier de las demas tareas.");
                break;
            case 5:
                if(!ll_isEmpty(listaEmpleados))
                {
                controller_removeEmployee(listaEmpleados);
                }else
                    printf("Debe ingresar a la Opcion uno antes de realizar cualquier de las demas tareas.");

                break;
            case 6:
                if(!ll_isEmpty(listaEmpleados))
                {
                controller_ListEmployees(listaEmpleados);
                }else
                    printf("Debe ingresar a la Opcion uno antes de realizar cualquier de las demas tareas.");
                break;
            case 7:
                if(!ll_isEmpty(listaEmpleados))
                {
                if(controller_sortEmployee(listaEmpleados))
                printf("El ordenamiento por sueldo se realizo con exito.\n");
                    else
                    printf("Hubo una falla al intentar ordenar la lista\n");
                }else
                    printf("Debe ingresar a la Opcion uno antes de realizar cualquier de las demas tareas.");

                break;
            case 8:
                if(!ll_isEmpty(listaEmpleados))
                {
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                printf("Empleados Guardados con exito.\n");
                }else
                    printf("No se realizo el guardado de los empleados.\n");
                }else
                    printf("Debe ingresar a la Opcion uno antes de realizar cualquier de las demas tareas.");
                break;
            case 9:

                break;
            case 10:
                printf("Desea Salir?\nS/N");
                getChar(&salir,1,1,'s','n',"Desea salir? s\n: ","");
                if(salir=='s')
                    ll_deleteLinkedList(listaEmpleados);
                break;
        }
        printf("\n\n");
    system("pause");
    system("cls");
    }while(salir!='s');
            }
    return 0;
}

int menu(void)
{
    int op=0;

    printf("-----Menu-----\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf(" 3. Alta de empleado\n");
    printf(" 4. Modificar datos de empleado\n");
    printf(" 5. Baja de empleado\n");
    printf(" 6. Listar empleados\n");
    printf(" 7. Ordenar empleados\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");

   getInt(&op,1,1,10,"Ingrese la opcion deseada.","");

    return op;
}
