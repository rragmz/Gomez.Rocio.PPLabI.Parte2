#include "fecha.h"

int validarFecha(eFecha unaFecha){
    int todoOk = 0;

    if(unaFecha.anio >= 1950 && unaFecha.anio <= 2021){
        if(unaFecha.mes >= 1 && unaFecha.mes <= 12){
            if(unaFecha.mes == 1 ||
               unaFecha.mes == 3 ||
               unaFecha.mes == 5 ||
               unaFecha.mes == 7 ||
               unaFecha.mes == 8 ||
               unaFecha.mes == 10 ||
               unaFecha.mes == 12){
                if(unaFecha.dia >= 1 && unaFecha.dia <= 31){
                    todoOk = 1;
                }
            }
        }
        else if(unaFecha.mes == 2){
            if(unaFecha.dia >= 1 && unaFecha.dia <= 29){
                todoOk = 1;
            }
        }
        else{
            if(unaFecha.mes == 4 ||
           unaFecha.mes == 6 ||
           unaFecha.mes == 9 ||
           unaFecha.mes == 11){
            if(unaFecha.dia >= 1 && unaFecha.dia <= 30){
                todoOk = 1;
             }
           }
        }
    }
    return todoOk;
}
