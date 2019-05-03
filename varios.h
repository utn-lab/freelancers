/*
menu: muestra menu en pantalla.
ayuda: muestra ayuda.
salir: muestra pantalla anterior
a salir del programa.
*/

#ifndef VARIOS_H_INCLUDED
#define VARIOS_H_INCLUDED

#include <iostream>
#include <cstdio>

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
                etiquetas::seleccionar,
                etiquetas::MENU_PRINCIPAL.c);
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
        pantalla::mostrar_seleccione(
                etiquetas::enter,
                0);
    }
}

namespace opciones {
    estructuras::lista *opciones_a_lista() {
        char *mostrar_eliminados = new char[34];
        char *mostrar_eliminados_solamente = new char[38];
        char *salario_desde = new char[128];
        char *salario_hasta = new char[128];
        if (estado::mostrar_eliminados) {
            std::strcpy(mostrar_eliminados, "Mostrar eliminados: Activado");
        } else {
            std::strcpy(mostrar_eliminados, "Mostrar eliminados: Desactivado");
        }
        if (estado::mostrar_eliminados_solamente) {
            std::strcpy(mostrar_eliminados_solamente, "Mostrar solo eliminados: Activado");
        } else {
            std::strcpy(mostrar_eliminados_solamente, "Mostrar solo eliminados: Desactivado");
        }
        std::snprintf(
                salario_desde,
                128,
                "Listar solo desde salario: $ %.2f",
                estado::salario_desde);
        std::snprintf(
                salario_hasta,
                128,
                "Listar solo hasta salario: $ %.2f",
                estado::salario_hasta);
        estructuras::lista *opciones_lista = new estructuras::lista {
            4,
            {
                mostrar_eliminados,
                mostrar_eliminados_solamente,
                salario_desde,
                salario_hasta
            }
        };
        return opciones_lista;
    }

    void liberar_lista(
            estructuras::lista *lista) {
        for (int i = 0; i < lista->c; i++)
            delete[] lista->v[i];
        delete lista;
    }

    void mostrar() {
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_OPCIONES,
                enums::CEN);

        estructuras::lista *p;
        p = opciones_a_lista();

        pantalla::mostrar_lista_vertical(
                p,
                enums::IZQ);
        pantalla::mostrar_seleccione(
                etiquetas::seleccionar,
                p->c);
        
        liberar_lista(p);
    }

    void cambiar() {
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_OPCIONES_CAMBIAR,
                enums::CEN);

        std::cout << etiquetas::nuevo_valor << ": ";
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
                etiquetas::seleccionar,
                etiquetas::SALIR.c);
    }
}

#endif // VARIOS_H_INCLUDED
