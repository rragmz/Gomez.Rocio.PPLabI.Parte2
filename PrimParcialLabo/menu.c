#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"



char menu(){
    char opcion;

    printf("-----BICICLETERIA-----\n");
        printf("A. Alta bicicleta \n");
        printf("B. Modificar bicicleta \n");
        printf("C. Baja bicicleta \n");
        printf("D. Listar bicicletas \n");
        printf("E. Listar marcas \n");
        printf("F. Listar tipos \n");
        printf("G. Listar colores \n");
        printf("H. Listar servicios \n");
        printf("I. Alta trabajo\n");
        printf("J. Listar trabajos\n");
        printf("K. Alta cliente\n");
        printf("L. Informes\n");
        printf("M. Salir\n");

        printf("Ingrese la opción: ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = toupper(opcion);

    return opcion;
}

int menuInformes(){
  int opcion;

  printf("         INFORMES\n\n");
  printf("1. Listar bicicletas por color\n");
  printf("2. Listar bicicletas por tipo\n");
  printf("3. Listar bicicleta/s del menor rodado\n");
  printf("4. Listar bicicletas separadas por tipo\n");
  printf("5. Listar bicicletas de un tipo y color\n");
  printf("6. El color favorito de los clientes\n");
  printf("7. Listar trabajos de una bicicleta\n");
  printf("8. Total a pagar por bicicleta\n");
  printf("9. Listar bicicletas por servicio\n");
  printf("10. Listar servicios por fecha\n\n");
  utn_getNumero(&opcion, "Ingrese opcion: ", "Error. Reingrese una opcion correcta", 1, 10, 3);

  return opcion;
}
