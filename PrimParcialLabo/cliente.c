#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

int inicCliente(eCliente clientes[], int tam){
int todoOk = 0;
    if(clientes != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
                clientes[i].isEmpty = 1;
                todoOk = 1;
            }
        }
return todoOk;
}

int mostrarCliente(eCliente cliente){
    int todoOk = 1;
    printf("    %d     %10s      %c\n", cliente.id, cliente.nombre, cliente.sexo);
    return todoOk;
}

int mostrarClientes(eCliente clientes[], int tam){
    int todoOk = 0;
    printf("         CLIENTES \n\n");
    printf("     ID          Nombre         Sexo\n\n");
    if(clientes != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(!clientes[i].isEmpty){
                mostrarCliente(clientes[i]);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int validarCliente(int idCliente, eCliente clientes[], int tam){
    int todoOk = 0;

    if(clientes != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(clientes[i].id == idCliente){
                todoOk = 1;
                break;
            }
        }
    }
return todoOk;
}

int cargarNombreCliente(int idCliente, eCliente clientes[], int tam, char nombre[]){
    int todoOk = 0;

    if(clientes != NULL && tam > 0 && nombre != NULL){
        for(int i = 0; i < tam; i++){
            if(clientes[i].id == idCliente){
                strcpy(nombre, clientes[i].nombre);
                todoOk = 1;
                break;
            }
        }
    }
return todoOk;
}

int buscarLibreCliente(eCliente clientes[], int tam){
    int indice = -1;

    if(clientes != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            //Analizo si está vacío
            if(clientes[i].isEmpty){
                //De estarlo, devuelvo el índice
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaCliente(eCliente clientes[], int tam, int* pIdCliente){
    int todoOk = 0;
    eCliente nuevoCliente;
    int indice;

    system("cls");
    printf("          ALTA CLIENTE\n\n");

    printf("Id: %d\n", *pIdCliente);
    if(clientes != NULL && tam > 0){
        indice = buscarLibreCliente(clientes, tam);

            //Si el índice es -1, es porque no hay lugar.
            if(indice == -1){
                printf("No hay lugar en el sistema\n");
            }
            //Sino, es porque sí hay lugar, procedemos a la carga de datos
            else{
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nuevoCliente.nombre);
                while(!esSoloLetras(nuevoCliente.nombre) || strlen(nuevoCliente.nombre) > 20){
                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    gets(nuevoCliente.nombre);
                }

                printf("Ingrese sexo: ");
                fflush(stdin);
                scanf("%c", &nuevoCliente.sexo);
                nuevoCliente.sexo = tolower(nuevoCliente.sexo);
                while(nuevoCliente.sexo != 'f' && nuevoCliente.sexo != 'm'){
                    printf("Ingrese sexo: ");
                    fflush(stdin);
                    scanf("%c", &nuevoCliente.sexo);
                    nuevoCliente.sexo = tolower(nuevoCliente.sexo);
                }

                nuevoCliente.id = *pIdCliente;
                //Informo que ya no está vacío
                nuevoCliente.isEmpty = 0;
                //Incremento el valor del id, para próximas cargas
                (*pIdCliente)++;

                //Ahora tenemos que copiar lo que está en la variable auxiliar a la posición[indice] de nuestro array
                clientes[indice] = nuevoCliente;
                todoOk = 1;
                }//Cierro el else
        }
    return todoOk;
}


