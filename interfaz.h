#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include "enums.h"
#include "etiquetas.h"
#include "pantalla.h"
#include "sistema.h"
#include "datos.h"
#include "empleado.h"

namespace interfaz {
    // Usada desde ayuda y salir
    enums::pantalla pantalla_actual;
    // Respuesta de usuario
    int int_buffer;
    char respuesta[100];

    void recibir_respuesta() {
        std::cin.getline(respuesta, 100);
    }

    int respuesta_es_numero() {
        int i = 0;
        while (respuesta[i] != '\0') {
            i++;
        }
        return 0;
    }

    void mostrar_menu() {
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

    void mostrar_horas() {
    }

    void mostrar_salario() {
    }

    void mostrar_ayuda() {
        pantalla::mostrar_lista_vertical(
                &etiquetas::TITULO_AYUDA,
                enums::CEN);
        pantalla::mostrar_lista_vertical(
                &etiquetas::AYUDA,
                enums::IZQ);
        pantalla::mostrar_enter();
    }

    void mostrar_salir() {
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

    void ir_a(enums::pantalla pantalla) {
        if (pantalla != enums::AYUDA
                and pantalla != enums::SALIR)
            pantalla_actual = pantalla;
        sistema::clear();
        respuesta[0] = '\0';
        switch (pantalla) {
            case enums::MENU:
                mostrar_menu();
                recibir_respuesta();
                switch (respuesta[0]) {
                    case '1':
                    case 'e':
                        ir_a(enums::EMPLEADO);
                        break;
                    case '2':
                    case 'p':
                        ir_a(enums::HORAS);
                        break;
                    case '3':
                    case 'v':
                        ir_a(enums::SALARIO);
                        break;
                    case '5':
                    case 'q':
                        ir_a(enums::SALIR);
                        break;
                    default:
                        ir_a(enums::AYUDA);
                        break;
                }
                break;

            case enums::EMPLEADO:
                empleado::cargar();
                empleado::mostrar();
                recibir_respuesta();
                if (empleado::empleados_c == 0) {
                    // TODO: menu agregar empleado
                } else if (std::strlen(respuesta) >= 2) {
                    // TODO: buscar en empleado::empleados
                } else {
                    // Opciones
                    switch (respuesta[0]) {
                        case 'q':
                            ir_a(enums::MENU);
                            break;
                        default:
                            ir_a(enums::AYUDA);
                            break;
                    }
                }
                break;

            case enums::HORAS:
                mostrar_horas();
                recibir_respuesta();
                switch (respuesta[0]) {
                    default:
                        break;
                }
                break;

            case enums::SALARIO:
                mostrar_salario();
                recibir_respuesta();
                switch (respuesta[0]) {
                    default:
                        break;
                }
                break;

            case enums::AYUDA:
                mostrar_ayuda();
                recibir_respuesta();
                switch (respuesta[0]) {
                    case 'q':
                        ir_a(enums::SALIR);
                        break;
                    default:
                        ir_a(pantalla_actual);
                        break;
                }
                break;

            case enums::SALIR:
                mostrar_salir();
                recibir_respuesta();
                switch (respuesta[0]) {
                    case '\0':
                    case 'q':
                    case 'y':
                        sistema::clear();
                        break;
                    default:
                        ir_a(pantalla_actual);
                        break;
                }
                break;

            default:
                ir_a(enums::AYUDA);
                break;
        }
    }
}

#endif // INTERFAZ_H_INCLUDED
