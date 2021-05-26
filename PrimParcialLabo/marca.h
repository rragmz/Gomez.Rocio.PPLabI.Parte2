#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
}eMarca;

#endif // MARCA_H_INCLUDED

/** \brief Muestra una marca con su id y nombre
 *
 * \param Un tipo de la estructura eMarca
 * \return Devuelve 1 luego de mostrar la marca
 *
 */
int mostrarMarca(eMarca marca);

/** \brief Muestra todas las marcas con su id y nombre a partir de la llamada a mostrarMarca
 *
 * \param Array de marcas
 * \param Tamaño del array de marcas
 * \return Devuelve 1 si logra mostrarlas, 0 si no
 *
 */
int mostrarMarcas(eMarca marcas[], int tam);


/** \brief Recorre array de marcas para buscar coincidencias y validar el primer parámetro (idMarca)
 *
 * \param Variable a ser analizada
 * \param Array de marcas
 * \param Tamaño del array de marcas
 * \return Devuelve 1 si valida el Id. Cero si no lo hace.
 *
 */
int validarMarca(int idMarca, eMarca marcas[], int tam);


/** \brief Carga el nombre de la marca en una variable de tipo string
 *
 * \param Id de la marca a ser cargada
 * \param Array de marcas
 * \param Tamaño del array de marcas
 * \param Variable donde se almacenará el nombre de la marca
 * \return Devuelve 1 si pudo cargar la variable con el nombre o 0 si no pudo
 *
 */
int cargarNombreMarca(int idMarca, eMarca marcas[], int tam, char nombre[]);

/** \brief Busca la existencia de una marca en el array a partir de su id
 *
 * \param Id a ser buscado
 * \param Array de marcas
 * \param Tamaño del array
 * \return Devuelve 1 si lo encuentra, 0 si no lo hace.
 *
 */
int buscarMarca(int id, eMarca marcas[], int tam);
