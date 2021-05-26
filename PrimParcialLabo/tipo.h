#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
 int id; //comienza en 1000
 char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief Muestra un tipo con su id y descripcion
 *
 * \param Un tipo de la estructura eTipo
 * \return Devuelve 1 luego de mostrar el tipo
 *
 */
int mostrarTipo(eTipo tipo);

/** \brief Muestra todos los tipos con su id y descripción a partir de la llamada a mostrarTipo
 *
 * \param Array de tipos
 * \param Tamaño del array de tipos
 * \return Devuelve 1 si logra mostrarlos, 0 si no
 *
 */
int mostrarTipos(eTipo tipos[], int tam);


/** \brief Recorre array de tipos para buscar coincidencias y validar el primer parámetro (idTipo)
 *
 * \param Variable a ser analizada
 * \param Array de tipos
 * \param Tamaño del array de tipos
 * \return Devuelve 1 si valida el Id. Cero si no lo hace.
 *
 */
int validarTipo(int idTipo, eTipo tipos[], int tam);


/** \brief Carga el nombre del tipo en una variable de tipo string
 *
 * \param Id del tipo a ser cargado
 * \param Array de tipos
 * \param Tamaño del array de tipos
 * \param Variable donde se almacenará el nombre del tipo
 * \return Devuelve 1 si pudo cargar la variable con el nombre o 0 si no pudo
 *
 */
int cargarDescripcionTipos(int idTipo, eTipo tipos[], int tam, char desc[]);

/** \brief Busca la existencia de un tipo en el array a partir de su id
 *
 * \param Id a ser buscado
 * \param Array de tipos
 * \param Tamaño del array
 * \return Devuelve 1 si lo encuentra, 0 si no lo hace.
 *
 */
int buscarTipo(int id, eTipo tipos[], int tam);
