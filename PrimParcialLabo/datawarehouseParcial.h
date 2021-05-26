#ifndef DATAWAREHOUSEPARCIAL_H_INCLUDED
#define DATAWAREHOUSEPARCIAL_H_INCLUDED
#include <string.h>
#include "bicicleta.h"
#include "trabajo.h"

/** \brief Pongo valores en los distintos campos de los elementos eBicicleta
 *
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \param Cantidad a hardcodear
 * \param Próximo id a utilizar
 * \return La cantidad hardcodeada
 *
 */
int hardcodearBicicletas(eBicicleta listBicis[], int tam, int cant, int* pIdBici);

/** \brief Pongo valores en los distintos campos de los elementos eTrabajo
 *
 * \param Array de trabajos
 * \param Tamaño del array de trabajos
 * \param Cantidad a hardcodear
 * \param Próximo id a utilizar
 * \return La cantidad hardcodeada
 *
 */
int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pIdTrabajo);

/** \brief Pongo valores en los distintos campos de los elementos eCliente
 *
 * \param Array de clientes
 * \param Tamaño del array de clientes
 * \param Cantidad a hardcodear
 * \param Próximo id a utilizar
 * \return La cantidad hardcodeada
 *
 */
int hardcodearClientes(eCliente clientes[], int tam, int cant, int* pIdCliente);

#endif // DATAWAREHOUSEPARCIAL_H_INCLUDED

