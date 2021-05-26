#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "marca.h"

int mostrarMarca(eMarca marca){
    int todoOk = 1;
    printf("    %d     %10s\n", marca.id, marca.nombre);

    return todoOk;
}

int mostrarMarcas(eMarca marcas[], int tam){
int todoOk = 0;
    printf("        MARCAS \n\n");
    printf("     Id          Marca\n\n");
    if(marcas != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            mostrarMarca(marcas[i]);
            todoOk = 1;
        }
    }
}

int validarMarca(int idMarca, eMarca marcas[], int tam){
    int todoOk = 0;

    if(marcas != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(marcas[i].id == idMarca){
                todoOk = 1;
                break;
            }
        }
    }
return todoOk;
}

int cargarNombreMarca(int idMarca, eMarca marcas[], int tam, char nombre[]){
int todoOk = 0;

    if(idMarca >= 3000 && idMarca <= 3004 && marcas != NULL && tam > 0 && nombre != NULL){
        for(int i = 0; i < tam; i++){
            if(marcas[i].id == idMarca){
                fflush(stdin);
                strcpy(nombre, marcas[i].nombre);
                todoOk = 1;
                break;
            }
        }
    }
return todoOk;
}

int buscarMarca(int id, eMarca marcas[], int tam){
    int indice = -1;
    if(marcas != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(marcas[i].id == id){
                indice = i;
                break;
            }
        }
    }
    return indice;
}
