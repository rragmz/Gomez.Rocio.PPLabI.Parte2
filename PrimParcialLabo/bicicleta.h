#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "tipo.h"
#include "color.h"
#include "marca.h"
#include "cliente.h"


typedef struct{
    int id;
    int idMarca;
    int idTipo; //validar;
    int idColor; //validar
    int idCliente;
    float rodado; //20, 26, 27.5 y 29
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

/** \brief Inicializa en 1 el campo isEmpty de todos los elementos del array listBicis
 *
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \return Devuelve 1 si logra la inicialización, 0 si no
 *
 */
int inicBicis(eBicicleta listBicis[], int tam);

/** \brief Busca el primer elemento libre en el array de bicicletas
 *
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \return Si logra encontrar un elemento vacío, devuelve su índice, sino devuelve -1
 *
 */
int buscarLibre(eBicicleta listBicis[], int tam);

/** \brief Busca la existencia de una bicicleta en el array a partir de su id
 *
 * \param Id a buscar
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \return Si logra encontrarlo, devuelve su índice, sino devuelve -1
 *
 */
int validarBici(int id, eBicicleta listBicis[], int tam);

/** \brief Muestra un elemento del tipo eBicicleta
 *
 * \param Elemento a mostrar
 * \param Array de tipos
 * \param Tamaño del array de tipos
 * \param Array de colores
 * \param Tamaño del array de colores
 * \return Devuelve 1 si logra mostrarlo o 0 si no lo hace
 *
 */
int mostrarBicicleta(eBicicleta bicicleta, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL);

/** \brief Muestra todos los elementos eBicicleta del array de bicicletas mediante la llamada a mostrarBicicleta
 *
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \param Array de tipos
 * \param Tamaño del array de tipos
 * \param Array de colores
 * \param Tamaño del array de colores
 * \return Devuelve 1 si logra mostrarlo o 0 si no lo hace
 *
 */
int mostrarBicicletas(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL);

/** \brief Da de alta una nueva bicicleta si hay espacio
 *
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \param Array de tipos
 * \param Tamaño del array de tipos
 * \param Array de colores
 * \param Tamaño del array de colores
 * \param Puntero al id de bicicletas, el cual es autoincremental
 * \return Devuelve 1 si pudo realizar el alta o 0 si no pudo
 *
 */
int altaBicicleta(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL, int* pIdBici);

/** \brief Modifica el tipo o el rodado de un elemento eBicicleta
 *
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \param Array de tipos
 * \param Tamaño del array de tipos
 * \param Array de colores
 * \param Tamaño del array de colores
 * \return Devuelve 1 si pudo realizar la modificación o 0 si no pudo
 *
 */
int modificarBicicleta(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL);

/** \brief Da la baja a una bicicleta
 *
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \param Array de tipos
 * \param Tamaño del array de tipos
 * \param Array de colores
 * \param Tamaño del array de colores
 * \return Devuelve 1 si pudo realizar la modificación o 0 si no pudo
 *
 */
int bajaBicicleta(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCL);

/** \brief Ordena el array de bicicletas por tipo y rodado (ascendente)
 *
 * \param Array de bicicletas
 * \param Tamaño del array de bicicletas
 * \param Array de tipos
 * \param Tamaño del array de tipos
 * \param Array de colores
 * \param Tamaño del array de colores
 * \return Devuelve 1 si pudo realizar el ordenamiento o 0 si no pudo
 *
 */
int ordenarBicicleta(eBicicleta listBicis[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eColor colores[], int tamC);
