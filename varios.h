#ifndef VARIOS_H_INCLUDED
#define VARIOS_H_INCLUDED

#include "enums.h"
#include "etiquetas.h"
#include "pantalla.h"
#include "sistema.h"

namespace menu {
    void mostrar() {
        sistema::imprimir_archivo("logo.txt");
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_MENU_PRINCIPAL,
                enums::CEN);
        pantalla::mostrar_lista_vertical(
                &etiquetas::MENU_PRINCIPAL,
                enums::CEN);
        pantalla::mostrar_seleccione(
                etiquetas::por_favor,
                &etiquetas::MENU_PRINCIPAL);
    }
}

namespace ayuda {
    void mostrar() {
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_AYUDA,
                enums::CEN);
        pantalla::mostrar_lista_vertical(
                &etiquetas::AYUDA,
                enums::IZQ);
        pantalla::mostrar_enter();
    }
}

namespace salir {
    void mostrar() {
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_SALIR,
                enums::CEN);
        pantalla::mostrar_lista_vertical(
                &etiquetas::SALIR,
                enums::CEN);
        pantalla::mostrar_seleccione(
                etiquetas::por_favor,
                &etiquetas::SALIR);
    }
}

#endif // VARIOS_H_INCLUDED
