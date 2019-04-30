/*
pantalla: funciones que imprimen informacion en la pantalla.
*/

#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

#include <cstring>
#include <iostream>

#include "enums.h"
#include "estado.h"
#include "etiquetas.h"
#include "estructuras.h"

namespace pantalla {
#ifdef _WIN32
    int pantalla_ancho = 120;
    int pantalla_alto = 30;
#else
    int pantalla_ancho = 80;
    int pantalla_alto = 24;
#endif
    int grilla_buffer = pantalla_alto - 8;

    void cambiar_tamano(int ancho, int alto) {
        if (ancho)
            pantalla_ancho = ancho;
        if (alto)
            pantalla_alto = alto;
        grilla_buffer = pantalla_alto - 8;
    }

    const char separador_h = '-';
    const char separador_v = '|';
    const int separador_h_longitud = 1;
    const int separador_v_longitud = 1;

    int encontrar_mayor_longitud(
            estructuras::lista *lista) {
        int mayor = 0;
        int longitud_item_actual;
        for (int i = 0; i < lista->c; i++) {
            longitud_item_actual = std::strlen(lista->v[i]);
            if (longitud_item_actual >= mayor)
                mayor = longitud_item_actual;
        }
        return mayor;
    }

    void mostrar_espacio(int cantidad) {
        for (int i = 0; i < cantidad; i++)
            std::cout << ' ';
    }

    void mostrar_separadores_h(int cantidad) {
        for (int i = 0; i < cantidad; i++)
            std::cout << separador_h;
    }

    void mostrar_nueva_linea(int cantidad) {
        for (int i = 0; i < cantidad; i++) {
            std::cout << std::endl;
            estado::lineas_ocupadas++;
        }
    }

    void mostrar_campo(
            const char *texto,
            int ancho_caracteres,
            enums::alineacion alineacion) {
        int longitud = std::strlen(texto);
        if (longitud > ancho_caracteres) {
            for (int i = 0; i < ancho_caracteres - 3; i++)
                std::cout << texto[i];
            std::cout << "...";
        } else {
            int espacio = ancho_caracteres - longitud;
            if (alineacion == enums::CEN) {
                espacio /= 2;
                mostrar_espacio(espacio);
            } else if (alineacion == enums::DER)
                mostrar_espacio(espacio);
            std::cout << texto;
            if (alineacion == enums::CEN) {
                espacio = ancho_caracteres - longitud - espacio;
                mostrar_espacio(espacio);
            } else if (alineacion == enums::IZQ) {
                mostrar_espacio(espacio);
            }
        }
    }

    void mostrar_lista_vertical(
            estructuras::lista *lista,
            enums::alineacion alineacion) {
        // Encontrar mayor longitud de item
        int mayor = encontrar_mayor_longitud(lista);
        // Calcular espacio entre borde izquierdo y menu
        int margen_izquierdo =
            (pantalla_ancho - mayor - separador_v_longitud) / 2 - 1;
        // Reservar espacio entre separadores
        mayor += 2;
        // Imprimir marco
        mostrar_espacio(margen_izquierdo);
        mostrar_separadores_h(mayor + 2);
        mostrar_nueva_linea(1);
        // Imprimir opciones
        for (int linea = 0; linea < lista->c; linea++) {
            mostrar_espacio(margen_izquierdo);
            std::cout << separador_v;
            mostrar_campo(lista->v[linea], mayor, alineacion);
            std::cout << separador_v;
            mostrar_nueva_linea(1);
        }
        mostrar_espacio(margen_izquierdo);
        mostrar_separadores_h(mayor + 2);
        mostrar_nueva_linea(1);
    }

    void mostrar_grilla_renglon(
            estructuras::lista *renglon,
            enums::alineacion *alineaciones) {
        int campo_ancho = (pantalla_ancho - 2) / renglon->c;
        for (int columna = 0; columna < renglon->c; columna++) {
            mostrar_campo(
                    renglon->v[columna],
                    campo_ancho,
                    alineaciones[columna]);
            if (renglon->c - columna != 1)
                std::cout << separador_v;
        }
        mostrar_nueva_linea(1);
    }

    void mostrar_grilla_cabecera(
            estructuras::lista *cabecera,
            enums::alineacion alineacion) {
        enums::alineacion alineaciones[cabecera->c];
        for (int columna = 0; columna < cabecera->c; columna++) {
            alineaciones[columna] = alineacion;
        }

        mostrar_separadores_h(pantalla_ancho);
        mostrar_nueva_linea(1);
        mostrar_grilla_renglon(cabecera, alineaciones);
        mostrar_separadores_h(pantalla_ancho);
        mostrar_nueva_linea(1);
    }

    void mostrar_enter() {
        mostrar_nueva_linea(
                pantalla_alto - estado::lineas_ocupadas - 1);
        std::cout << etiquetas::enter << ": ";
    }

    void mostrar_seleccione(
            const char *etiqueta,
            int ocurrencias) {
        mostrar_nueva_linea(
                pantalla_alto - estado::lineas_ocupadas - 1);
        std::cout << etiqueta << " (1-" << ocurrencias << "): ";
    }
}

#endif // PANTALLA_H_INCLUDED
