/*
sector: mantiene datos de sectores.
*/

#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

#include <cstdio>

#include "enums.h"
#include "etiquetas.h"
#include "estructuras.h"
#include "pantalla.h"

namespace sector {
    const char archivo[] = "sector.bin";
    float valor_hora[3];
    const int sector_c = 3;

    estructuras::lista *sector_a_lista(
            enums::sector sector) {
        char *valor_char = new char[64];
        std::snprintf(valor_char, 64, "$ %.2f", valor_hora[sector]);
        estructuras::lista *sector_lista = new estructuras::lista {
            2,
            {
                etiquetas::EMPLEADO_TIPOS.v[sector],
                valor_char
            }
        };
        return sector_lista;
    }

    void liberar_lista(
            estructuras::lista *sector_lista) {
        delete[] sector_lista->v[1];
        delete sector_lista;
    }

    void cargar() {
        FILE *fp;
        fp = std::fopen(archivo, "rb");

        if (!fp) {
            valor_hora[enums::DISENO] = 300.0;
            valor_hora[enums::DESARROLLO] = 350.0;
            valor_hora[enums::ANALISIS] = 400.0;
            return;
        }

        std::fread(
                &valor_hora,
                sizeof(float),
                sector_c,
                fp);

        std::fclose(fp);
    }

    void guardar() {
        FILE *fp;
        fp = std::fopen(archivo, "wb");
        std::fwrite(
                &valor_hora,
                sizeof(float),
                sector_c,
                fp);
        std::fclose(fp);
    }

    void cambiar_valor(enums::sector sector) {
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_SECTOR_CAMBIAR,
                enums::CEN);
        pantalla::mostrar_grilla_cabecera(
                &etiquetas::SECTOR_CABECERA,
                enums::CEN);

        enums::alineacion alineaciones[] = {
            enums::IZQ,
            enums::DER
        };

        estructuras::lista *p;
        p = sector_a_lista(sector);
        pantalla::mostrar_grilla_renglon(
                p,
                alineaciones);
        liberar_lista(p);

        pantalla::mostrar_separadores_h(
                pantalla::pantalla_ancho);
        pantalla::mostrar_seleccione(
                etiquetas::nuevo_valor,
                0);
        std::cin >> valor_hora[sector];
        std::cin.ignore();
    }

    void mostrar() {
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_SECTOR,
                enums::CEN);
        pantalla::mostrar_grilla_cabecera(
                &etiquetas::SECTOR_CABECERA,
                enums::CEN);

        // Elegir alineaciones
        enums::alineacion alineaciones[] = {
            enums::IZQ,
            enums::DER
        };

        estructuras::lista *p;
        for (int i = 0; i < sector_c; i++) {
            p = sector_a_lista((enums::sector)i);
            pantalla::mostrar_grilla_renglon(
                    p,
                    alineaciones);
            liberar_lista(p);
        }

        pantalla::mostrar_separadores_h(
                pantalla::pantalla_ancho);
        pantalla::mostrar_seleccione(
                etiquetas::seleccionar,
                sector_c);
    }
}

#endif // SECTOR_H_INCLUDED
