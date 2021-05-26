#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id; //comienza en 5000
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

/** \brief Muestra un color con su id y nombre
 *
 * \param Una variable de la estructura eColor
 * \return Devuelve 1 luego de mostrarlo
 *
 */
int mostrarColor(eColor color);

/** \brief Muestra todos los colores existentes a partir de la llamada a mostrarColor
 *
 * \param Array de colores
 * \param Tamaño del array de colores
 * \return Devuelve 1 si pudo mostrarlos, 0 si no
 *
 */

int mostrarColores(eColor colores[], int tam);

/** \brief Busca coincidencia entre el id pasado por parámetro y los id del array de colores
 *
 * \param Id a buscar
 * \param Array de colores
 * \param Tamaño del array
 * \return Devuelve 1 si existe coincidencia, 0 si no
 *
 */
int validarColor(int idColor, eColor colores[], int tam);


/** \brief Carga el nombre del color en una variable de tipo string
 *
 * \param Id del color a ser cargado
 * \param Array de colores
 * \param Tamaño del array de colores
 * \param Variable donde se almacenará el nombre del color
 * \return Devuelve 1 si lo encuentra, 0 si no lo hace
 *
 */
int cargarNombreColores(int idColor, eColor colores[], int tam, char nombre[]);

/** \brief Busca la existencia de un color en el array a partir de su id
 *
 * \param Id a ser buscado
 * \param Array de colores
 * \param Tamaño del array de colores
 * \return Devuelve 1 si lo encuentra, 0 si no lo hace
 *
 */
int buscarColor(int id, eColor colores[], int tam);
