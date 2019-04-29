/*
horas: mantiene datos de horas.
*/

#ifndef HORAS_H_INCLUDED
#define HORAS_H_INCLUDED

#include "enums.h"
#include "etiquetas.h"
#include "pantalla.h"

namespace horas {
    const char archivo[] = "horas.bin";

    void mostrar() {
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_HORAS,
                enums::CEN);
        pantalla::mostrar_grilla_cabecera(
                &etiquetas::HORAS_CABECERA,
                enums::CEN);
    }
}

#endif // HORAS_H_INCLUDED
