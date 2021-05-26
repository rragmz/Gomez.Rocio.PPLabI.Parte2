#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

/** \brief Inicializa en 1 el campo isEmpty de todos los elementos del array clientes
 *
 * \param Array de clientes
 * \param Tamaño del array de clientes
 * \return Devuelve 1 si logra la inicialización, 0 si no
 *
 */
int inicCliente(eCliente clientes[], int tam);

/** \brief Muestra un cliente con su id, nombre y sexo
 *
 * \param Un cliente de la estructura eCliente
 * \return Devuelve 1 luego de mostrar el tipo
 *
 */
int mostrarCliente(eCliente cliente);

/** \brief Muestra todos los clientes con su id, nombre y sexo a partir de la llamada a mostrarCliente
 *
 * \param Array de clientes
 * \param Tamaño del array de clientes
 * \return Devuelve 1 si logra mostrarlos, 0 si no
 *
 */
int mostrarClientes(eCliente clientes[], int tam);


/** \brief Recorre array de clientes para buscar coincidencias y validar el primer parámetro (idCliente)
 *
 * \param Variable a ser analizada
 * \param Array de clientes
 * \param Tamaño del array de clientes
 * \return Devuelve 1 si valida el Id. Cero si no lo hace.
 *
 */
int validarCliente(int idCliente, eCliente clientes[], int tam);


/** \brief Carga el nombre del cliente en una variable de tipo string
 *
 * \param idCliente a ser cargado
 * \param Array de clientes
 * \param Tamaño del array de clientes
 * \param Variable donde se almacenará el nombre del cliente
 * \return Devuelve 1 si pudo cargar la variable con el nombre o 0 si no pudo
 *
 */
int cargarNombreCliente(int idCliente, eCliente clientes[], int tam, char nombre[]);

/** \brief Busca el primer elemento libre en el array de clientes
 *
 * \param Array de clientes
 * \param Tamaño del array de clientes
 * \return Si logra encontrar un elemento vacío, devuelve su índice, sino devuelve -1
 *
 */
int buscarLibreCliente(eCliente clientes[], int tam);

/** \brief Si hay espacio disponible, da de alta un nuevo cliente
 *
 * \param Array de clientes
 * \param Tamaño del array de clientes
 * \param Puntero al id de clientes, el cual es autoincremental
 * \return Devuelve 1 si pudo realizar el alta o 0 si no pudo
 *
 */
int altaCliente(eCliente clientes[], int tam, int* pIdCliente);
