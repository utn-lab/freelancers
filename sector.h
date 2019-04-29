/*
sector: mantiene datos de sectores.
*/

#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

#include "enums.h"
#include "etiquetas.h"
#include "pantalla.h"

namespace sector {
    const char archivo[] = "sector.bin";

    void mostrar() {
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_SECTOR,
                enums::CEN);
        pantalla::mostrar_grilla_cabecera(
                &etiquetas::SECTOR_CABECERA,
                enums::CEN);
    }
}

#endif // SECTOR_H_INCLUDED
