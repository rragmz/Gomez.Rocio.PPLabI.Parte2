#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "fecha.h"
#include "tipo.h"
#include "marca.h"
#include "color.h"
#include "bicicleta.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"
#include "datawarehouseParcial.h"
#include "informes.h"

#define TAMT 4
#define TAMC 5
#define TAMM 5
#define TAMS 4
#define TAMB 11
#define TAMTR 11
#define TAMCL 11
int main()
{
    char salir;
    int flag = 0;

    int nextIdBici = 200;
    int nextIdTrabajo = 300;
    int nextIdCliente = 100;

    eTipo tipos[TAMT] = {
    {1000, "Rutera"},
    {1001, "Carrera"},
    {1002, "Mountain"},
    {1003, "BMX"},
    };

    eMarca marcas[TAMM] = {
    {3000, "Trek"},
    {3001, "Merida"},
    {3002, "Specialized"},
    {3003, "Felt"},
    {3004, "Giant"},
    };

    eColor colores[TAMC] = {
    {5000, "Gris"},
    {5001, "Negro"},
    {5002, "Blanco"},
    {5003, "Azul"},
    {5004, "Rojo"},
    };

    eServicio servicios[TAMS] = {
        {20000, "Limpieza", 250},
        {20001, "Parche", 300},
        {20002, "Centrado", 400},
        {20003, "Cadena", 350},
    };

    eBicicleta listabicis[TAMB];
    inicBicis(listabicis, TAMB);
    hardcodearBicicletas(listabicis, TAMB, 10, &nextIdBici);

    eTrabajo trabajos[TAMTR];
    inicTrabajo(trabajos, TAMTR);
    hardcodearTrabajos(trabajos, TAMTR, 10, &nextIdTrabajo);

    eCliente clientes[TAMCL];
    inicCliente(clientes, TAMCL);
    hardcodearClientes(clientes, TAMCL, 10, &nextIdCliente);

    do{
    switch(menu()){
        case 'A':
            system("cls");
            if(altaBicicleta(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, clientes, TAMCL, &nextIdBici)){
                printf("\nSe realizo correctamente el alta!!\n");
                flag = 1;
            }
            else{
                printf("No se pudo realizar el alta \n");
            }
            break;
        case 'B':
            system("cls");
            if(flag){
                if(modificarBicicleta(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, clientes, TAMCL)){
                    printf("\nSe realizo correctamente la modificacion!!\n");
                }
                else{
                    printf("No se pudo realizar la modificacion \n");
                }
            }
            else{
                printf("Primero haga un alta\n");
            }
            break;
        case 'C':
            system("cls");
            if(flag){
                if(bajaBicicleta(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, clientes, TAMCL)){
                    printf("\nSe realizo correctamente la baja!!\n");
                }
                else{
                    printf("No se pudo realizar la baja \n");
                }
            }
            else{
                printf("Primero haga un alta\n");
            }
            break;
        case 'D':
            system("cls");
            ordenarBicicleta(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC);
            mostrarBicicletas(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, clientes, TAMCL);
            break;
        case 'E':
            system("cls");
            mostrarMarcas(marcas, TAMM);
            break;
        case 'F':
            system("cls");
            mostrarTipos(tipos, TAMT);
            break;
        case 'G':
            system("cls");
            mostrarColores(colores, TAMC);
            break;
        case 'H':
            system("cls");
            mostrarServicios(servicios, TAMS);
            break;
        case 'I':
            system("cls");
            if(altaTrabajo(trabajos, TAMTR, listabicis, TAMB, servicios, TAMS, marcas, TAMM, tipos, TAMT, colores, TAMC, clientes, TAMCL, &nextIdTrabajo)){
                printf("Se realizó el alta correctamente!\n");
            }
            else{
                printf("Alta cancelada por el usuario\n");
            }
            break;
        case 'J':
            system("cls");
            mostrarTrabajos(trabajos, TAMTR, listabicis, TAMB, servicios, TAMS);
            break;
        case 'K':
            system("cls");
            if(altaCliente(clientes, TAMCL, &nextIdCliente)){
                printf("Se realizó el alta correctamente!\n");
            }
            else{
                printf("No se pudo realizar el alta\n");
            }
            break;
        case 'L':
            system("cls");
            switch(menuInformes()){
                case 1:
                    system("cls");
                    bicisPorColor(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, clientes, TAMCL);
                    break;
                case 2:
                    system("cls");
                    bicisPorTipo(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, clientes, TAMCL);
                    break;
                case 3:
                    system("cls");
                    menorRodado(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, clientes, TAMCL);
                    break;
                case 4:
                    system("cls");
                    listadoBicisPorTipo(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, clientes, TAMCL);
                    break;
                case 5:
                    system("cls");
                    biciTipoColor(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC);
                    break;
                case 6:
                    system("cls");
                    coloresFavoritos(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC);
                    break;
                case 7:
                    system("cls");
                    trabajosBici(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, servicios, TAMS, trabajos, TAMTR, clientes, TAMCL);
                    break;
                case 8:
                    system("cls");
                    totalTrabajoBici(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, servicios, TAMS, trabajos, TAMTR, clientes, TAMCL);
                    break;
                case 9:
                    system("cls");
                    biciServicioFecha(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, servicios, TAMS, trabajos, TAMTR);
                    break;
                case 10:
                    system("cls");
                    serviciosFecha(listabicis, TAMB, marcas, TAMM, tipos, TAMT, colores, TAMC, servicios, TAMS, trabajos, TAMTR);
                    break;
            }
            break;
        case 'M':
            system("cls");
            printf("Confirma salida? s/n: ");
            scanf("%c", &salir);
            salir = tolower(salir);
            break;
        default:
            printf("Esta no es una opcion\n");
            break;
        }
        printf("\n");
        system("pause");
    }while(salir != 's');
}
