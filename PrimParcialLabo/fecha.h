#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;


#endif // FECHA_H_INCLUDED

/** \brief Valido el día, el mes y el año de una fecha pasada por parámetro
 *
 * \param La fecha a validar
 * \return 1 si valida, 0 si no.
 *
 */
int validarFecha(eFecha unaFecha);
