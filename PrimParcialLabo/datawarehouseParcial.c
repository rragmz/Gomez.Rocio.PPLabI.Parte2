#include "datawarehouseParcial.h"
#include "fecha.h"

//Para el hardcodeo de las bicicletas
int idMarcas[10] = {3000,3002,3003,3000,3004,3001,3003,3001,3004,3000};
int idTipos[10] = {1000, 1002, 1001, 1000, 1000, 1001, 1002, 1000, 1001, 1001};
int idColores[10] = {5001, 5002, 5000, 5003, 5001, 5002, 5001, 5000, 5003, 5000};
float rodados[10] = {27.5, 29, 26, 26, 29, 29, 27.5, 26, 29, 27.5};

//Para el hardcodeo de los trabajos
int idBicicletas[20] = {200,201,202,203,204,205,206,207,208,200};
int idServicios[20] = {20003,20001,20000,20001,20001,20000,20003,20003,20001,20000};

eFecha fechas[] = {{1,1,2021},
    {1,5,2021},
    {1,5,2021},
    {1,5,2021},
    {1,5,2021},
    {1,5,2021},
    {2,5,2021},
    {2,5,2021},
    {2,5,2021},
    {2,5,2021},
    {2,5,2021},
    {2,5,2021},
    {3,5,2021},
    {3,5,2021},
    {3,5,2021},
    {3,5,2021},
    {3,5,2021},
    {3,5,2021},
    {4,5,2021},
    {4,5,2021},
    {4,5,2021},
    {4,5,2021},
    {4,5,2021},
    {4,5,2021},
};

int idClientes[10] = {200,201,202,203,204,205,206,207,208,209};

char nombres[10][20] = {
    "Jose",
    "Mariana",
    "Martin",
    "Agustina",
    "Federico",
    "Gonzalo",
    "Manuela",
    "Josefina",
    "Andres",
    "Agustin"
};

char sexos[10]={'m', 'f', 'm', 'f', 'm', 'm', 'f', 'f', 'm', 'm'};

int hardcodearBicicletas(eBicicleta listBicis[], int tam, int cant, int* pIdBici){
    //No puede cargar bicicletas:
    int cantidad = 0;

    if(listBicis != NULL && tam > 0 && cant >= 0 && cant <= tam && pIdBici != NULL){
    //Menor a cant porque es la cantidad de bicicletas que quiero cargar
        for(int i = 0; i < cant; i++){
            listBicis[i].id = *pIdBici;
            (*pIdBici)++;
            //Copio la marca
            listBicis[i].idMarca = idMarcas[i];
            listBicis[i].idCliente = idClientes[i];
            //El idTipo
            listBicis[i].idTipo = idTipos[i];
            //El idColor
            listBicis[i].idColor = idColores[i];
            //Los rodados
            listBicis[i].rodado = rodados[i];
            //Ocupo el índice
            listBicis[i].isEmpty = 0;
            cantidad++;
        }
    }
    return cantidad;
}

int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pIdTrabajo){
    int cantidad = 0;

    if(trabajos != NULL && tam > 0 && cant >= 0 && cant <= tam && pIdTrabajo != NULL){
        for(int i = 0; i < cant; i++){
            trabajos[i].id = *pIdTrabajo;
            (*pIdTrabajo)++;

            trabajos[i].idBicicleta = idBicicletas[i];
            trabajos[i].idServicio = idServicios[i];
            trabajos[i].fecha = fechas[i];
            trabajos[i].isEmpty = 0;
            cantidad++;
        }
    }
    return cantidad;
}

int hardcodearClientes(eCliente clientes[], int tam, int cant, int* pIdCliente){
    int cantidad = 0;

    if(clientes != NULL && tam > 0 && cant >= 0 && cant <= tam && pIdCliente != NULL){
        for(int i = 0; i < cant; i++){
            clientes[i].id = *pIdCliente;
            (*pIdCliente)++;
            clientes[i].id = idClientes[i];
            strcpy(clientes[i].nombre, nombres[i]);
            clientes[i].sexo = sexos[i];
            clientes[i].isEmpty = 0;
            cantidad++;
        }
    }
    return cantidad;

}
