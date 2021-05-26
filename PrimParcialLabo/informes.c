#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "servicio.h"
#include "color.h"
#include "tipo.h"
#include "fecha.h"

int bicisPorColor(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL){
    int todoOk = 0;
    int flag = 1;
    int idColor;

    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCL > 0){
        mostrarColores(colores, tamC);
        printf("\nIngrese ID del color: ");
        //Limpio el búfer por si se intenta romper el programa ingresando caracteres alfanuméricos
        fflush(stdin);
        scanf("%d", &idColor);
        while(!validarColor(idColor, colores, tamC)){
            printf("Error. Reingrese ID del color: ");
            fflush(stdin);
            scanf("%d", &idColor);
        }
        printf("\n");
        printf("      Id          Dueño        Marca             Tipo            Color      Rodado\n\n");
        //Recorro el array de bicicletas
        for(int i = 0; i < tam; i++){
            //Cuando el elemento no esté vacío y su color sea el mismo que el solicitado por el usuario, muestro la bicicleta
            if(!listBicis[i].isEmpty && (listBicis[i].idColor == idColor)){
                mostrarBicicleta(listBicis[i], marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
                flag = 0;
            }
        }
        printf("\n");
        //Si la bandera no cambió su estado, lo informo
        if(flag){
            printf("No hay bicicletas registradas con ese color\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int bicisPorTipo(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL){
    int todoOk = 0;
    int flag = 1;
    int idTipo;

    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCL > 0){
        mostrarTipos(tipos, tamT);
        printf("\nIngrese Id del tipo: ");
        fflush(stdin);
        scanf("%d", &idTipo);
        while(!validarTipo(idTipo, tipos, tamT)){
            printf("Error. Reingrese ID del tipo: ");
            fflush(stdin);
            scanf("%d", &idTipo);
        }
        printf("\n");
        printf("      Id               Dueño         Marca             Tipo            Color      Rodado\n\n");
        for(int i = 0; i < tam; i++){
            if(!listBicis[i].isEmpty && (listBicis[i].idTipo == idTipo)){
                mostrarBicicleta(listBicis[i], marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
                flag = 0;
            }
        }
        if(flag){
            printf("No hay bicicletas registradas de ese tipo\n\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int menorRodado(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL){
    float menor;
    int flag = 1;
    int todoOk = 0;

    printf("      Id               Dueño         Marca             Tipo            Color      Rodado\n\n");
    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0){
        //Hago un for inicial para averiguar cuál es el menor rodado registrado
        for(int i = 0; i < tam-1; i++){
            if(flag || listBicis[i].rodado < menor){
                    menor = listBicis[i].rodado;
                }
            }
        //Hago un segundo for para mostrar las ocurrencias de bicicletas con ese rodado
        for(int i = 0; i < tam; i++){
            if(listBicis[i].rodado == menor){
                mostrarBicicleta(listBicis[i], marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
            }
        }
    }
    return todoOk;
}

int listadoBicisPorTipo(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL){
int todoOk = 0;
int flag;
char desc[20];

    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCL > 0){
            //Recorro el array de tipos
        for(int i = 0; i < tamT; i++){
            //Cargo la variable desc con el nombre del tipo que estoy actualmente recorriendo
            cargarDescripcionTipos(tipos[i].id, tipos, tamT, desc);
            printf("TIPO: %s\n\n", desc);
            printf("      Id               Dueño         Marca             Tipo            Color      Rodado\n\n");
            //Inicializo flag en 1 para poder chequear si hubo o no ocurrencias
            flag = 1;
            //Recorro el array de bicicletas
            for(int j = 0; j < tam; j++){
                //Si el idTipo de una bicicleta del array es igual al tipo que estoy recorriendo, muestro la bicicleta y cambio el estado de flag
                if(!listBicis[j].isEmpty && (listBicis[j].idTipo == tipos[i].id)){
                    mostrarBicicleta(listBicis[j], marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
                    flag = 0;
                }
            }
            //Si no se encontraron ocurrencias de tipo, imprimo mensaje
            if(flag){
                printf("No hay bicicletas registradas de ese tipo\n");
            }
            printf("\n-----------------------------------------------------------------------\n\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int biciTipoColor(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC){
    int todoOk = 0;
    int idColor;
    char nombreColor[20];
    int idTipo;
    char descTipo[20];
    int cont = 0;

    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0){
        //Le pido al usuario ingrese id del color a buscar
        mostrarColores(colores, tamC);
        printf("Ingrese ID del color: ");
        fflush(stdin);
        scanf("%d", &idColor);
        while(!validarColor(idColor, colores, tamC)){
            printf("Error. Reingrese ID del color: ");
            fflush(stdin);
            scanf("%d", &idColor);
        }
        cargarNombreColores(idColor, colores, tamC, nombreColor);
        //Le pido al usuario ingrese id del tipo a buscar
        mostrarTipos(tipos, tamT);
        printf("Ingrese ID del tipo: ");
        fflush(stdin);
        scanf("%d", &idTipo);
        while(!validarTipo(idTipo, tipos, tamT)){
            printf("Ingrese ID del tipo: ");
            fflush(stdin);
            scanf("%d", &idTipo);
        }
        cargarDescripcionTipos(idTipo, tipos, tamT, descTipo);
        //Recorro el array de bicicletas
        for(int i = 0; i < tam; i++){
                //Cuando el elemento no esté vacío y encuentre ocurrencias tanto en el color como en el tipo, actualizo el contador
                if(!listBicis[i].isEmpty && (listBicis[i].idColor == idColor && listBicis[i].idTipo == idTipo)){
                    cont++;
                }
        }
        //Si el contador no cambió su estado lo informo
        if(cont == 0){
            printf("No hay registro de bicicletas que cumplan con la condición\n");
        }
        else{
            //Si el contador sí cambió su estado, informo cuántas bicicletas cumplen con la condición
            printf("La cantidad de bicicletas del tipo %s y de color %s es: %d",descTipo, nombreColor, cont);
        }
        todoOk = 1;
    }
    return todoOk;
}

int coloresFavoritos(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC){
    int todoOk = 0;
    int mayorColor;
    int totalColor = 0;
    int totalesColor[tamC];
    int flag = 1;
    system("cls");
    printf("\n        COLORES FAVORITOS DE LOS CLIENTES\n\n");
    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0){
        //Recorro el array de colores
        for(int c = 0; c < tamC; c++){
            //Inicializo en 0 la variable totalColor en cada vuelta del for
            totalColor = 0;
            //Recorro el array de bicicletas
            for(int b = 0; b < tam; b++){
                    //Cuando el elemento no esté vacío y su idColor sea igual al id actual del for de colores, sumo el contador totalColor
                    if(!listBicis[b].isEmpty && listBicis[b].idColor == colores[c].id){
                        totalColor ++;
                    }
                }
                //Asigno el total de este color a su posición en el array de totalesColor
                totalesColor[c] = totalColor;
            }
            //Recorro el array de colores y analizo cuál es el cuantitativamente mayor. Guardo su total en mayorColor
            for(int i = 0; i < tamC; i++){
                if(flag || totalesColor[i] > mayorColor){
                    mayorColor = totalesColor[i];
                    flag = 0;
                }
            }
            printf("El color o los colores favoritos de los clientes son: \n");
            //Recorro nuevamente el array de colores para mostrar cuál/es son los más elegidos por los usuarios
            for(int i = 0; i < tamC; i++){
                if(mayorColor == totalesColor[i]){
                    printf("%s\n",colores[i].nombreColor);
                }
            }
            todoOk = 1;
    }
    return todoOk;
}

int trabajosBici(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTR, eCliente clientes[], int tamCL){
    int todoOk = 0;
    int flag = 1;
    int idBici;

    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0&& tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && servicios != NULL && tamS > 0 && trabajos != NULL && tamTR > 0 && clientes != NULL &&tamCL > 0){
        mostrarBicicletas(listBicis, tam, marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
        printf("Ingrese ID: ");
        fflush(stdin);
        scanf("%d", &idBici);
        while(validarBici(idBici, listBicis, tam) == -1){
            printf("Error. Reingrese ID: ");
            fflush(stdin);
            scanf("%d", &idBici);
        }
        printf("       TRABAJOS EN LA BICICLETA ID: %d\n\n", idBici);
        //Recorro el array de bicicletas
        for(int i = 0; i < tam; i++){
            //Cuando el elemento no esté vacío y su id sea el mismo que el que busca el usuario
            if(!listBicis[i].isEmpty && listBicis[i].id == idBici){
                //Recorro el array de trabajos
                for(int t = 0; t < tamTR; t++){
                    //Cuando el trabajo pertenezca al id de la bicicleta que se busca, muestro el trabajo
                    if(trabajos[t].idBicicleta == listBicis[i].id){
                        mostrarTrabajo(trabajos[t], listBicis, tam, servicios, tamS);
                        //Cambio el estado de la bandera
                        flag = 0;
                    }
                }
            }
        }
        todoOk = 1;
    }
    //Si la bandera no cambió su estado, lo informo
    if(flag){
        printf("En esta bicicleta no se realizó ningún trabajo\n");
    }
    return todoOk;
}

int totalTrabajoBici(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTR, eCliente clientes[], int tamCL){
    int todoOk = 0;
    int flag = 1;
    int idBici;
    float total = 0;

    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0&& tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && servicios != NULL && tamS > 0 && trabajos != NULL && tamTR > 0 && clientes != NULL &&tamCL > 0){
        mostrarBicicletas(listBicis, tam, marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
        printf("Ingrese ID: ");
        fflush(stdin);
        scanf("%d", &idBici);
        while(validarBici(idBici, listBicis, tam) == -1){
            printf("Error. Reingrese ID: ");
            fflush(stdin);
            scanf("%d", &idBici);
        }
        printf("       IMPORTE TOTAL DE TRABAJOS EN LA BICICLETA ID: %d\n\n", idBici);
        //Recorro el array de bicicletas
        for(int i = 0; i < tam; i++){
            //Cuando el elemento no esté vacío y su id sea el mismo que el que busca el usuario
            if(!listBicis[i].isEmpty && listBicis[i].id == idBici){
                //Recorro el array de trabajos
                for(int t = 0; t < tamTR; t++){
                    //Cuando el trabajo pertenezca al id de la bicicleta que se busca, muestro el trabajo
                    if(trabajos[t].idBicicleta == listBicis[i].id){
                        mostrarTrabajo(trabajos[t], listBicis, tam, servicios, tamS);
                        //Recorro el array de servicios
                        for(int s = 0; s < tamS; s++){
                            //Cuando el servicio del trabajo sea igual al id del servicio actual, sumo su importe al total
                            if(trabajos[t].idServicio == servicios[s].id){
                                total += servicios[s].precio;
                            }
                        }
                        //Cambio el estado de la bandera
                        flag = 0;
                    }
                }
            }
        }
        todoOk = 1;
    }
    //Si la bandera no cambió su estado, lo informo
    if(flag){
        printf("En esta bicicleta no se realizó ningún trabajo\n");
    }
    //Si cambió el estado, informo el total a pagar
    else{
        printf("El total a pagar es: %.2f", total);
    }
    return todoOk;
}

int biciServicioFecha(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTR){
    int todoOk = 0;
    int flag;
    int idServicio;

    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0&& tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && servicios != NULL && tamS > 0 && trabajos != NULL && tamTR > 0){
        mostrarServicios(servicios, tamS);
        //Pido al usuario un ID y valido. Limpio el búfer de entrada por si se intenta romper el programa ingresando letras
        printf("\nIngrese ID servicio: ");
        fflush(stdin);
        scanf("%d", &idServicio);
        while(!validarServicio(idServicio, servicios, tamS)){
            printf("Error. Reingrese ID servicio: ");
            fflush(stdin);
            scanf("%d", &idServicio);
        }
        printf("\n    Id        Id Bicicleta         Servicio        Fecha\n");
        //Recorro el array de trabajos. Cuando un elemento tenga su idServicio (fk) igual al idServicio que pide el usuario, muestro el trabajo
        for(int i = 0; i < tamTR; i++){
            if(trabajos[i].idServicio == idServicio){
                mostrarTrabajo(trabajos[i], listBicis, tam, servicios, tamS);
                //Cambio el estado de la bandera
                flag = 0;
            }
        }
        //Si la bandera no cambió su estado, lo informo
        if(flag){
            printf("No hay bicicletas con ese servicio\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int serviciosFecha(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTR){
    int flag = 1;
    int todoOk = 0;
    eFecha unaFecha;

    if(listBicis != NULL && tam > 0 && marcas != NULL && tamM > 0&& tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && servicios != NULL && tamS > 0 && trabajos != NULL && tamTR > 0){
        //Le pido al usuario una fecha y la valido
        printf("Ingrese fecha (dd/mm/aaaa): ");
        fflush(stdin);
        scanf("%d/%d/%d", &unaFecha.dia, &unaFecha.mes, &unaFecha.anio);
        while(!validarFecha(unaFecha)){
            printf("Error. Reingrese fecha (dd/mm/aaaa): ");
            fflush(stdin);
            scanf("%d/%d/%d", &unaFecha.dia, &unaFecha.mes, &unaFecha.anio);
        }
        printf("\n    Id        Id Bicicleta         Servicio        Fecha\n");
        //Recorro el array de trabajos. Cuando un elemento tenga su campo fecha exactamente igual al pedido por el usuario, lo muestro
        for(int i = 0; i < tamT; i++){
            if(trabajos[i].fecha.dia == unaFecha.dia && trabajos[i].fecha.mes == unaFecha.mes && trabajos[i].fecha.anio){
                mostrarTrabajo(trabajos[i], listBicis, tam, servicios, tamS);
                flag = 0;
            }
        }
        //Si la bandera no cambió de estado, lo informo
        if(flag){
            printf("No hay servicios realizados en esa fecha\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
