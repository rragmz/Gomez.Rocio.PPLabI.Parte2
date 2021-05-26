#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "utn.h"
#include "cliente.h"

int inicBicis(eBicicleta listBicis[], int tam){
int todoOk = 0;
    if(listBicis != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
                listBicis[i].isEmpty = 1;
                todoOk = 1;
            }
        }
return todoOk;
}

int buscarLibre(eBicicleta listBicis[], int tam){
int indice = -1;

    if(listBicis != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            //Analizo si está vacío
            if(listBicis[i].isEmpty){
                //De estarlo, devuelvo el índice
                indice = i;
                //Rompemos para que nos muestre el PRIMER lugar libre
                break;
            }
        }
    }
    return indice;
}

int validarBici(int id, eBicicleta listBicis[], int tam){
int indice = -1;
    if(listBicis != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(listBicis[i].id == id){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int mostrarBicicleta(eBicicleta bicicleta, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL){
int todoOk = 0;
char marca[20];
char descTipo[20];
char color[20];
char nombre[20];
cargarNombreMarca(bicicleta.idMarca, marcas, tamM, marca);
cargarDescripcionTipos(bicicleta.idTipo, tipos, tamT, descTipo);
cargarNombreColores(bicicleta.idColor, colores, tamC, color);
cargarNombreCliente(bicicleta.idCliente, clientes, tamCL, nombre);

    if(marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCL > 0){
        printf("     %d\t %10s \t%10s  \t  %10s   \t  %10s  \t  %.2f\n", bicicleta.id, nombre, marca, descTipo, color, bicicleta.rodado);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarBicicletas(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL){
int todoOk = 0;
printf("       BICICLETAS \n\n");
    printf("      Id         Dueño           Marca             Tipo            Color      Rodado\n\n");
    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCL > 0){
        for(int i = 0; i < tam; i++){
            if(!listBicis[i].isEmpty){
                mostrarBicicleta(listBicis[i], marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
                todoOk = 1;
            }
        }
    }
    return todoOk;
}



int altaBicicleta(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL, int* pIdBici){
    int todoOk = 0;

    eBicicleta nuevaBici;
    //Es la que voy a utilizar para pedir la información, una vez que haya validado
    int indice;

    system("cls");
    printf("          Alta Bicicleta\n");

        //Hago las validaciones generales
        if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCL > 0 && pIdBici != NULL){
            //Le mostramos al usuario cuál sería el id de bici que le corresponde de realizarse correctamente el alta
            printf("Id: %d\n", *pIdBici);
            //Llamo a la funcion buscar libre para pedirle el primer índice vacío disponible
            indice = buscarLibre(listBicis, tam);

            //Si el índice es -1, es porque no hay lugar. Printeamos.
            if(indice == -1){
                printf("No hay lugar en el sistema\n");
            }
            //Sino, es porque sí hay lugar, procedemos a la carga de datos
            else{
                mostrarClientes(clientes, tamCL);
                printf("Ingrese ID cliente: ");
                scanf("%d", &nuevaBici.idCliente);
                while(!validarCliente(nuevaBici.idCliente, clientes, tamCL)){
                    printf("Ingrese ID cliente: ");
                    scanf("%d", &nuevaBici.idCliente);
                }
                mostrarMarcas(marcas, tamM);
                printf("\nIngrese ID marca: ");
                fflush(stdin);
                scanf("%d", &nuevaBici.idMarca);
                while(!validarMarca(nuevaBici.idMarca, marcas, tamM)){
                    printf("\nError. Reingrese ID marca: ");
                    fflush(stdin);
                    scanf("%d", &nuevaBici.idMarca);
                }

                mostrarTipos(tipos, tamT);
                printf("\nIngrese ID tipo: ");
                scanf("%d", &nuevaBici.idTipo);
                while(!validarTipo(nuevaBici.idTipo, tipos, tamT)){
                    printf("Error. Ingrese ID tipo: ");
                    scanf("%d", &nuevaBici.idTipo);
                }
                printf("\n");

                mostrarColores(colores, tamC);
                printf("\nIngrese ID color: ");
                scanf("%d", &nuevaBici.idColor);
                while(!validarColor(nuevaBici.idColor, colores, tamC)){
                    printf("Error. Ingrese ID color: ");
                    scanf("%d", &nuevaBici.idColor);
                }

                printf("\nIngrese rodado (20/26/27.5/29): ");
                scanf("%f", &nuevaBici.rodado);
                while(nuevaBici.rodado != 20 && nuevaBici.rodado != 26 && nuevaBici.rodado != 27.5 && nuevaBici.rodado != 29){
                    printf("Ingrese rodado: ");
                    scanf("%f", &nuevaBici.rodado);
                }

                nuevaBici.id = *pIdBici; //Accedo al valor que tengo en el puntero, y se lo asigno a esta nueva bici luego de las validaciones.
                //Informo que ya no está vacío
                nuevaBici.isEmpty = 0;
                //Incremento el valor del id, para próximas cargas
                (*pIdBici)++;

                //Ahora tenemos que copiar lo que está en la variable auxiliar a la posición[indice] de nuestro array
                listBicis[indice] = nuevaBici;
                todoOk = 1;


                }//Cierro el else
        }
    return todoOk;
}

int modificarBicicleta(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL){

eBicicleta auxBici;
    int indice;
    int id;
    int todoOk = 0;
    int opcion;
    char seguir;

    mostrarBicicletas(listBicis, tam, marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);

    printf("Ingrese ID a modificar: ");
    scanf("%d", &id);

    indice = validarBici(id,listBicis, tam);

    if(indice == -1){
        printf("No hay bicicletas con ese id\n");
    }
    else{
        auxBici = listBicis[indice];
        mostrarBicicleta(auxBici, marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
        printf("1. Tipo\n");
        printf("2. Rodado\n");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            system("cls");
            mostrarTipos(tipos, tamT);
                printf("Ingrese ID tipo: ");
                scanf("%d", &auxBici.idTipo);
                while(!validarTipo(auxBici.idTipo, tipos, tamT)){
                    printf("Error. Ingrese ID tipo: ");
                    scanf("%d", &auxBici.idTipo);
                }
            break;
        case 2:
            system("cls");
            printf("Ingrese rodado (20/26/27.5/29): ");
                scanf("%f", &auxBici.rodado);
                while(auxBici.rodado != 20 && auxBici.rodado != 26 && auxBici.rodado != 27.5 && auxBici.rodado != 29){
                    printf("Ingrese rodado: ");
                    scanf("%f", &auxBici.rodado);
                }
            break;
        default:
            printf("Opcion invalida\n");
        }
        mostrarBicicleta(auxBici, marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
        printf("Confirma cambios? s/n: ");
        fflush(stdin);
        scanf("%c",&seguir);
        if(seguir == 's'){
            listBicis[indice] = auxBici;
            todoOk = 1;
        }
        else{
            printf("Modificación cancelada por el usuario. \n");
        }
    }
 return todoOk;
}

int bajaBicicleta(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL){
    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("       Baja Bicicleta\n\n");

    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCL > 0){
        mostrarBicicletas(listBicis, tam, marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
        printf("\nIngrese ID: ");
        scanf("%d", &id);

        indice = validarBici(id, listBicis, tam);

        if(indice == -1){
            printf("No hay ninguna bicicleta registrada con el ID %d \n", id);
        }
        else{
            printf("\n");
            mostrarBicicleta(listBicis[indice], marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
            printf("\nConfirma baja? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's'){
                listBicis[indice].isEmpty = 1;
                todoOk = 1;
            }
            else{
                printf("Baja cancelada por el usuario \n");
            }
        }
    }

    return todoOk;
}

int ordenarBicicleta(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC){
    int todoOk = 0;
    eBicicleta auxBicicleta;

    for(int i = 0; i < tam-1; i++){
        for(int j = i+1; j < tam; j++){
                if(listBicis[i].idTipo > listBicis[j].idTipo || (listBicis[i].idTipo == listBicis[j].idTipo &&
                   listBicis[i].rodado > listBicis[j].rodado)){
                    auxBicicleta = listBicis[i];
                    listBicis[i] = listBicis[j];
                    listBicis[j] = auxBicicleta;
                    todoOk = 1;
                }
            }
    }
    return todoOk;
}
