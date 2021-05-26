#include "trabajo.h"
#include "fecha.h"

int inicTrabajo(eTrabajo trabajos[], int tam){
    int todoOk = 0;
        if(trabajos != NULL && tam > 0){
            for(int i = 0; i < tam; i++){
                    trabajos[i].isEmpty = 1;
                    todoOk = 1;
                }
            }
    return todoOk;
}
int buscarLibreTrabajo(eTrabajo trabajos[], int tam){
    int indice = -1;

    if(trabajos != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            //Analizo si está vacío
            if(trabajos[i].isEmpty){
                //De estarlo, devuelvo el índice
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int buscarTrabajo(int id, eTrabajo trabajos[], int tam){
    int indice = -1;
    if(trabajos != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(trabajos[i].id == id){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int mostrarTrabajo(eTrabajo trabajo, eBicicleta listBicis[], int tam, eServicio servicios[], int tamS){
char servicio[20];
int todoOk = 0;
    if(listBicis != NULL && tam > 0 && servicios != NULL && tamS > 0){
        if(cargarDescServicio(trabajo.idServicio, servicios, tamS, servicio)){
            printf("    %d \t    %d \t %10s \t %d/%d/%d\n",
                   trabajo.id,
                   trabajo.idBicicleta,
                   servicio,
                   trabajo.fecha.dia,
                   trabajo.fecha.mes,
                   trabajo.fecha.anio
                    );
            todoOk = 1;
        }
    }
    return todoOk;
}

int mostrarTrabajos(eTrabajo trabajos[], int tamT, eBicicleta listBicis[], int tam, eServicio servicios[], int tamS){
int flag = 0;
    printf("          TRABAJOS \n\n");
    printf("    Id        Id Bicicleta         Servicio        Fecha\n");
    if(trabajos != NULL && tamT > 0 && listBicis != NULL && tam > 0 && servicios != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(!trabajos[i].isEmpty){
                mostrarTrabajo(trabajos[i], listBicis, tam, servicios, tamS);
                flag = 1;
            }
        }
        printf("\n");
        if(!flag){
            printf("No se pueden mostrar datos.");
        }
        printf("\n");
        printf("\n");
    }

    return flag;
}



int altaTrabajo(eTrabajo trabajos[], int tam, eBicicleta listBicis[], int tamB, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL, int* pIdTrabajo){
int todoOk = 0;

    eTrabajo nuevoTrabajo;
    int indice;

    system("cls");
    printf("          ALTA TRABAJO\n\n");

    printf("Id: %d\n", *pIdTrabajo);

        //Hago las validaciones generales
        if(trabajos != NULL && tam > 0 && listBicis != NULL && tamB > 0 && servicios != NULL && tamS > 0 && marcas != NULL && tamM > 0          && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && clientes != NULL && tamCL > 0 && pIdTrabajo != NULL){
            //Llamo a la funcion buscar libre para pedirle el primer índice vacío disponible
            indice = buscarLibreTrabajo(trabajos, tam);

            //Si el índice es -1, es porque no hay lugar.
            if(indice == -1){
                printf("No hay lugar en el sistema\n");
            }
            //Sino, es porque sí hay lugar, procedemos a la carga de datos
            else{
                mostrarBicicletas(listBicis, tamB, marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
                printf("Ingrese ID de la bicicleta: ");
                scanf("%d", &nuevoTrabajo.idBicicleta);

                mostrarServicios(servicios, tamS);
                printf("Ingrese ID servicio: ");
                scanf("%d", &nuevoTrabajo.idServicio);
                while(!validarServicio(nuevoTrabajo.idServicio, servicios, tamS)){
                    printf("Error. Ingrese ID servicio: ");
                    scanf("%d", &nuevoTrabajo.idServicio);
                }

                printf("Ingrese fecha (dd/mm/aaaa): ");
                fflush(stdin);
                scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
                while(!validarFecha(nuevoTrabajo.fecha)){
                    printf("Error. Reingrese fecha (dd/mm/aaaa): ");
                    fflush(stdin);
                    scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
                }

                nuevoTrabajo.id = *pIdTrabajo;
                //Informo que ya no está vacío
                nuevoTrabajo.isEmpty = 0;
                //Incremento el valor del id, para próximas cargas
                (*pIdTrabajo)++;

                //Ahora tenemos que copiar lo que está en la variable auxiliar a la posición[indice] de nuestro array
                trabajos[indice] = nuevoTrabajo;
                todoOk = 1;


                }//Cierro el else
        }
    return todoOk;
}


int modificarTrabajo(eTrabajo trabajos[], int tamTR, eBicicleta listBicis[], int tamB, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL){

eTrabajo auxTrabajo;
    int indice;
    int id;
    int todoOk = 0;
    int opcion;
    char seguir;

    mostrarTrabajos(trabajos, tamT, listBicis, tamB, servicios, tamS);

    printf("Ingrese ID a modificar: ");
    scanf("%d", &id);

    indice = buscarTrabajo(id, trabajos, tamT);

    if(indice == -1){
        printf("No hay trabajos con ese id\n");
    }
    else{
        auxTrabajo = trabajos[indice];
        mostrarTrabajo(auxTrabajo, listBicis, tamB, servicios, tamS);
        printf("1. ID bicicleta\n");
        printf("2. ID servicio\n");
        printf("3. Fecha");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            system("cls");
            mostrarBicicletas(listBicis, tamB, marcas, tamM, tipos, tamT, colores, tamC, clientes, tamCL);
            printf("Ingrese ID bicicleta: ");
            fflush(stdin);
            scanf("%d", &auxTrabajo.idBicicleta);
            while(!validarBici(auxTrabajo.idBicicleta, listBicis, tamB)){
                printf("Error. Ingrese ID bicicleta: ");
                fflush(stdin);
                scanf("%d", &auxTrabajo.idBicicleta);
            }
            break;
        case 2:
            system("cls");
            mostrarServicios(servicios, tamS);
            printf("Ingrese rodado ID servicio: ");
            fflush(stdin);
            scanf("%d", &auxTrabajo.idServicio);
            while(!validarServicio(auxTrabajo.idServicio, servicios, tamS)){
                printf("Error. Reingrese rodado ID servicio: ");
                fflush(stdin);
                scanf("%d", &auxTrabajo.idServicio);
            }
            break;
         case 3:
            system("cls");
            printf("Ingrese fecha: ");
            fflush(stdin);
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
            while(!validarFecha(auxTrabajo.fecha)){
                 printf("Error. Reingrese fecha: ");
                fflush(stdin);
                scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);;
            }
            break;
        default:
            printf("Opcion invalida\n");
        }
        mostrarTrabajo(auxTrabajo, listBicis, tamB, servicios, tamS);
        printf("Confirma cambios? s/n: ");
        fflush(stdin);
        scanf("%c",&seguir);
        if(opcion == 's'){
            trabajos[indice] = auxTrabajo;
            todoOk = 1;
        }
        else{
            printf("Modificación cancelada por el usuario. \n");
        }
    }
 return todoOk;
}

int bajaTrabajo(eTrabajo trabajos[], int tamT, eBicicleta listBicis[], int tam, eServicio servicios[], int tamS){
    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    system("cls");
    printf("       Baja Trabajo\n\n");

    if(trabajos != NULL && tamT > 0 && listBicis != NULL && tam > 0 && servicios != NULL && tam > 0){
        mostrarTrabajos(trabajos, tamT, listBicis, tam, servicios, tamS);
        printf("\nIngrese ID: ");
        scanf("%d", &id);

        indice = buscarTrabajo(id, trabajos, tamT);

        if(indice == -1){
            printf("No hay ningún trabajo registrado con el ID %d \n", id);
        }
        else{
            printf("\n");
            mostrarTrabajo(trabajos[indice], listBicis, tam, servicios, tamS);
            printf("\nConfirma baja? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's'){
                trabajos[indice].isEmpty = 1;
                todoOk = 1;
            }
            else{
                printf("Baja cancelada por el usuario \n");
            }
        }
    }

    return todoOk;
}
