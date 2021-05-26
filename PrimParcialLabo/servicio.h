#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id; //Comienza en 20000
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief Muestra id, descripción y precio de un elemento del tipo eServicio
 *
 * \param Elemento a mostrar
 * \return Devuelve 1 luego de mostrarlo
 *
 */
int mostrarServicio(eServicio servicio);


/** \brief Muestra los elementos del array servicios a partir de la llamada a mostrarServicio
 *
 * \param Array de servicios
 * \param Tamaño del array
 * \return Devuelve 1 si pudo mostrarlos, 0 si no
 *
 */
int mostrarServicios(eServicio servicios[], int tam);

/** \brief Recorre el array de servicios y valida el primer parámetro si encuentra ocurrencia
 *
 * \param Variable a ser analizada
 * \param Array de servicios
 * \param Tamaño del array de servicios
 * \return Devuelve 1 si valida el Id, 0 si no lo hace
 *
 */
int validarServicio(int idServicio, eServicio servicios[], int tam);

/** \brief Carga el nombre del servicio en una variable de tipo string
 *
 * \param Id del servicio a ser cargado
 * \param Array de servicios
 * \param Tamaño del array de servicios
 * \param Variable donde se almacenará la descripción del servicio
 * \return Devuelve 1 si pudo cargar la variable con la descripción o 0 si no pudo
 *
 */
int cargarDescServicio(int idServicio, eServicio servicios[], int tam, char desc[]);

/** \brief Busca la existencia de un servicio en el array a partir de su id
 *
 * \param Id a ser buscado
 * \param Array de servicios
 * \param Tamaño del array
 * \return Devuelve 1 si lo encuentra, 0 si no lo hace.
 *
 */
int buscarServicio(int id, eServicio servicios[], int tam);
