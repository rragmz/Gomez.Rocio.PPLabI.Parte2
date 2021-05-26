#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "informes.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "servicio.h"
#include "color.h"
#include "tipo.h"

/** \brief Pide al usuario el ID del color y muestra todas las bicicletas que coincidan con ese color
 *
 * \param Array bicicletas
 * \param Tamaño array bicicletas
 * \param Array tipos
 * \param Tamaño array tipos
 * \param Array colores
 * \param Tamaño array colores
 * \return Devuelve 1 si pudo mostrar, 0 si no
 *
 */
int bicisPorColor(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL);

/** \brief Pide al usuario el ID del tipo y muestra todas las bicicletas que sean de ese tipo
 *
 * \param Array bicicletas
 * \param Tamaño array bicicletas
 * \param Array tipos
 * \param Tamaño array tipos
 * \param Array colores
 * \param Tamaño array colores
 * \return Devuelve 1 si pudo mostrar, 0 si no
 *
 */
int bicisPorTipo(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL);


/** \brief Muestra la cantidad de bicicletas con el menor rodado que hay registradas en el sistema
 *
 * \param Array bicicletas
 * \param Tamaño array bicicletas
 * \param Array tipos
 * \param Tamaño array tipos
 * \param Array colores
 * \param Tamaño array colores
 * \return Devuelve 1 si pudo mostrar, 0 si no
 *
 */
int menorRodado(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL);


/** \brief Lista los tipos de bicicletas y dentro de cada tipo muestra cuáles están registradas con ese ID
 *
 * \param Array bicicletas
 * \param Tamaño array bicicletas
 * \param Array tipos
 * \param Tamaño array tipos
 * \param Array colores
 * \param Tamaño array colores
 * \return Devuelve 1 si pudo mostrar, 0 si no
 *
 */
int listadoBicisPorTipo(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL);

/** \brief Pide al usuario tipo y color y muestra ocurrencias
 *
 * \param Array bicicletas
 * \param Tamaño array bicicletas
 * \param Array tipos
 * \param Tamaño array tipos
 * \param Array colores
 * \param Tamaño array colores
 * \return Devuelve 1 si pudo mostrar, 0 si no
 *
 */
int biciTipoColor(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC);


/** \brief Lista el o los colores favoritos de los clientes
 *
 * \param Array bicicletas
 * \param Tamaño array bicicletas
 * \param Array tipos
 * \param Tamaño array tipos
 * \param Array colores
 * \param Tamaño array colores
 * \return Devuelve 1 si pudo mostrar, 0 si no
 *
 */
int coloresFavoritos(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC);


/** \brief Pide al usuario un ID bicicleta y muestra todos los trabajos que se le realizaron
 *
 * \param Array bicicletas
 * \param Tamaño array bicicletas
 * \param Array tipos
 * \param Tamaño array tipos
 * \param Array colores
 * \param Tamaño array colores
 * \param Array servicios
 * \param tamaño array servicios
 * \param Array trabajos
 * \param Tamaño array trabajos
 * \return Devuelve 1 si pudo mostrar, 0 si no
 *
 */
int trabajosBici(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTR, eCliente clientes[], int tamCL);


/** \brief Pide una bicicleta y muestra el importe total por los servicios realizados en ella
 *
 * \param Array bicicletas
 * \param Tamaño array bicicletas
 * \param Array tipos
 * \param Tamaño array tipos
 * \param Array colores
 * \param Tamaño array colores
 * \param Array servicios
 * \param tamaño array servicios
 * \param Array trabajos
 * \param Tamaño array trabajos
 * \return Devuelve 1 si pudo mostrar, 0 si no
 *
 */
int totalTrabajoBici(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTR, eCliente clientes[], int tamCL);


/** \brief Pide un servicio y muestra la/s fecha/s en que se realizó
 *
 * \param Array bicicletas
 * \param Tamaño array bicicletas
 * \param Array tipos
 * \param Tamaño array tipos
 * \param Array colores
 * \param Tamaño array colores
 * \param Array servicios
 * \param tamaño array servicios
 * \param Array trabajos
 * \param Tamaño array trabajos
 * \return Devuelve 1 si pudo mostrar, 0 si no
 *
 */
int biciServicioFecha(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTR);

/** \brief Pide una fecha y muestra todos los servicios que se realizaron en la misma
 *
 * \param Array bicicletas
 * \param Tamaño array bicicletas
 * \param Array tipos
 * \param Tamaño array tipos
 * \param Array colores
 * \param Tamaño array colores
 * \param Array servicios
 * \param tamaño array servicios
 * \param Array trabajos
 * \param Tamaño array trabajos
 * \return Devuelve 1 si pudo mostrar, 0 si no
 *
 */
int serviciosFecha(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTR);
#endif // INFORMES_H_INCLUDED
