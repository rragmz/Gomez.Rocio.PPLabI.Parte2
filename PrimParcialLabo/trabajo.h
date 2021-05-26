#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fecha.h"
#include "bicicleta.h"
#include "servicio.h"


typedef struct{
    int id;
    int idBicicleta; //validar
    int idServicio; //validar
    eFecha fecha; //validar
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief Inicializa en 1 el campo isEmpty de todos los elementos del array trabajos
 *
 * \param Array de trabajos
 * \param Tamaño del array de trabajos
 * \return Devuelve 1 si logra la inicialización, 0 si no
 *
 */
int inicTrabajo(eTrabajo trabajos[], int tam);

/** \brief Busca el primer elemento libre en el array de trabajos
 *
 * \param Array de trabajos
 * \param Tamaño del array de trabajos
 * \return Si logra encontrar un elemento vacío, devuelve su índice, sino devuelve -1
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tam);

/** \brief Muestra un elemento del tipo eTrabajo
 *
 * \param Elemento del tipo a mostrar
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
  * \param Array de servicios
 * \param Tamaño del array de servicios
 * \return Devuelve 1 si logra mostrarlo, 0 si no lo hace
 *
 */
int mostrarTrabajo(eTrabajo trabajo, eBicicleta listBicis[], int tam, eServicio servicios[], int tamS);

/** \brief Muestra todos los elementos eTrabajo del array de trabajos mediante la llamada a mostrarTrabajo
 *
 * \param Array de trabajos
 * \param Tamaño del array de trabajos
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \param Array de colores
 * \param Tamaño del array de colores
 * \return Devuelve 1 si logra mostrarlos o 0 si no lo hace
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamT, eBicicleta listBicis[], int tam, eServicio servicios[], int tamS);


/** \brief Busca la existencia de una trabajo en el array a partir de su id
 *
 * \param Id a buscar
 * \param Array de trabajos
 * \param Tamaño del array de trabajos
 * \return Si logra encontrarlo, devuelve su índice, sino devuelve -1
 *
 */
int buscarTrabajo(int id, eTrabajo trabajos[], int tam);

/** \brief Si hay espacio disponible, da de alta un nuevo trabajo
 *
 * \param Array de trabajos
 * \param Tamaño del array de trabajos
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \param Array de colores
 * \param Tamaño del array de colores
 * \param Puntero al id de trabajos, el cual es autoincremental
 * \return Devuelve 1 si pudo realizar el alta o 0 si no pudo
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tam, eBicicleta listBicis[], int tamB, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL, int* pIdTrabajo);

/** \brief Modifica un campo de un elemento eTrabajo
 *
 * \param Array de trabajos
 * \param Tamaño del array de trabajos
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \param Array de colores
 * \param Tamaño del array de colores
 * \return Devuelve 1 si pudo realizar el alta o 0 si no pudo
 *
 */
int modificarTrabajo(eTrabajo trabajos[], int tamTR, eBicicleta listBicis[], int tamB, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL);

/** \brief Pide ID del trabajo al usuario y da de baja el mismo
 *
 * \param Array de trabajos
 * \param Tamaño del array de trabajos
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \param Array de colores
 * \param Tamaño del array de colores
 * \return Devuelve 1 si logra mostrarlos o 0 si no lo hace
 *
 */
int bajaTrabajo(eTrabajo trabajos[], int tamT, eBicicleta listBicis[], int tam, eServicio servicios[], int tamS);
